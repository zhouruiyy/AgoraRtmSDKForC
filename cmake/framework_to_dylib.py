import os
import subprocess
import shutil

def convert_xcframework_to_dylib(xcframework_path, lib_name, output_path):
  # Create the output directory if it doesn't exist
  if not os.path.exists(output_path):
    os.makedirs(output_path, mode=0o755)

  lib_path = os.path.join(xcframework_path, "macos-arm64_x86_64", lib_name + ".framework", lib_name)
  out_lib_name = "lib" + lib_name + ".dylib"
  out_lib_path = os.path.join(output_path, out_lib_name)
  # Construct the command to convert xcframework to dylib
  command = "cp \"{0}\" \"{1}\"".format(lib_path, out_lib_path)
  print("copy: " + command)
  subprocess.call(command, shell=True)
  command = "install_name_tool -id @rpath/{0} {1}".format(out_lib_name, out_lib_path)
  subprocess.call(command, shell=True)

  # otool -L lib_path
  rpaths_output = subprocess.check_output(["otool", "-L", out_lib_path])
  rpaths = rpaths_output.decode("utf-8").split("\n")
  for rpath in rpaths:
    rpath_stripped = rpath.strip()
    if rpath_stripped.startswith("@rpath") and not rpath_stripped.endswith(".dylib"):
      # @rpath/Agoraffmpeg.framework/Versions/A/Agoraffmpeg (compatibility version 0.0.0, current version 0.0.0)
      rpath_stripped = rpath_stripped.split(" ")[0]
      dep_lib = rpath_stripped.split("/")[-1]
      command = "install_name_tool -change {0} @rpath/lib{1}.dylib {2}".format(rpath_stripped, dep_lib, out_lib_path)
      subprocess.call(command, shell=True)

def copy_headers(xcframework_path, lib_name, headers_path):
  # Create headers directory if it doesn't exist
  if not os.path.exists(headers_path):
    os.makedirs(headers_path, mode=0o755)

  # Copy headers from framework
  framework_headers = os.path.join(xcframework_path, "macos-arm64_x86_64", lib_name + ".framework", "Headers")
  if os.path.exists(framework_headers):
    # 使用copytree递归复制整个目录
    for item in os.listdir(framework_headers):
      src = os.path.join(framework_headers, item)
      dst = os.path.join(headers_path, item)
      if os.path.isdir(src):
        if os.path.exists(dst):
          shutil.rmtree(dst)
        shutil.copytree(src, dst)
      else:
        shutil.copy2(src, dst)
    print(f"Copied headers from {framework_headers} to {headers_path}")

def cleanup_xcframework(xcframework_path):
  # Remove .xcframework files
  for item in os.listdir(xcframework_path):
    if item.endswith(".xcframework"):
      xcf_path = os.path.join(xcframework_path, item)
      shutil.rmtree(xcf_path)
      print(f"Removed {xcf_path}")

# Path to the agora_sdk_mac folder
xcframework_path = "../build/agora_rtm_sdk_download-prefix/src/agora_rtm_sdk_download/libs"

# Path to the output folder for dylib libraries
output_path = "../build/agora_rtm_sdk_download-prefix/src/agora_rtm_sdk_download/libs"
headers_path = os.path.join(os.path.dirname(xcframework_path), "headers")

# Read the contents of the directory
for file_name in os.listdir(xcframework_path):
  # Check if the item is a file
  if not file_name.endswith(".xcframework") or os.path.isfile(os.path.join(xcframework_path, file_name)):
    continue
  lib_name = file_name.split(".")[0]
  convert_xcframework_to_dylib(os.path.join(xcframework_path, file_name), lib_name, output_path)
  copy_headers(os.path.join(xcframework_path, file_name), lib_name, headers_path)

# Clean up xcframework files after processing
cleanup_xcframework(xcframework_path)
