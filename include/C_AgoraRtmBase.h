#ifndef C_AGORA_RTM_BASE_H
#define C_AGORA_RTM_BASE_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#pragma region agora

#pragma region agora::rtm

#define C_DEFAULT_LOG_SIZE_IN_KB 1024

/**
 * Rtm link state.
 */
typedef enum _C_RTM_LINK_STATE {
  /**
   * The initial state.
   */
  C_RTM_LINK_STATE_IDLE = 0,
  /**
   * The SDK is connecting to the server.
   */
  C_RTM_LINK_STATE_CONNECTING = 1,
  /**
   * The SDK has connected to the server.
   */
  C_RTM_LINK_STATE_CONNECTED = 2,
  /**
   * The SDK is disconnected from the server.
   */
  C_RTM_LINK_STATE_DISCONNECTED = 3,
  /**
   * The SDK link is suspended.
   */
  C_RTM_LINK_STATE_SUSPENDED = 4,
  /**
   * The SDK is failed to connect to the server.
   */
  C_RTM_LINK_STATE_FAILED = 5,
} C_RTM_LINK_STATE;

/**
 * Rtm link operation.
 */
typedef enum _C_RTM_LINK_OPERATION {
  /**
   * Login.
   */
  C_RTM_LINK_OPERATION_LOGIN = 0,
  /**
   * Logout.
   */
  C_RTM_LINK_OPERATION_LOGOUT = 1,
  /**
   * Join
   */
  C_RTM_LINK_OPERATION_JOIN = 2,
  /**
   * Leave.
   */
  C_RTM_LINK_OPERATION_LEAVE = 3,
  /**
   * Server reject
   */
  C_RTM_LINK_OPERATION_SERVER_REJECT = 4,
  /**
   * Auto reconnect
   */
  C_RTM_LINK_OPERATION_AUTO_RECONNECT = 5,
  /**
   * Reconnected
   */
  C_RTM_LINK_OPERATION_RECONNECTED = 6,
  /**
   * Heartbeat lost
   */
  C_RTM_LINK_OPERATION_HEARTBEAT_LOST = 7,
  /**
   * Server timeout
   */
  C_RTM_LINK_OPERATION_SERVER_TIMEOUT = 8,
  /**
   * Network change
   */
  C_RTM_LINK_OPERATION_NETWORK_CHANGE = 9,
} C_RTM_LINK_OPERATION;

/**
 * Rtm link state change reason.
 */
typedef enum _C_RTM_LINK_STATE_CHANGE_REASON {
  /**
   * Unknown reason.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_UNKNOWN = 0,
  /**
   * Login.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_LOGIN = 1,
  /**
   * Login success.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_LOGIN_SUCCESS = 2,
  /**
   * Login timeout.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_LOGIN_TIMEOUT = 3,
  /**
   * Login not authorized.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_LOGIN_NOT_AUTHORIZED = 4,
  /**
   * Login rejected.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_LOGIN_REJECTED = 5,
  /**
   * Re-login.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_RELOGIN = 6,
  /**
   * Logout.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_LOGOUT = 7,
  /**
   * Auto reconnect.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_AUTO_RECONNECT = 8,
  /**
   * Reconnect timeout.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_RECONNECT_TIMEOUT = 9,
  /**
   * Reconnect success.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_RECONNECT_SUCCESS = 10,
  /**
   * Join.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_JOIN = 11,
  /**
   * Join success.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_JOIN_SUCCESS = 12,
  /**
   * Join failed.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_JOIN_FAILED = 13,
  /**
   * Rejoin.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_REJOIN = 14,
  /**
   * Leave.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_LEAVE = 15,
  /**
   * Invalid token.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_INVALID_TOKEN = 16,
  /**
   * Token expired.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_TOKEN_EXPIRED = 17,
  /**
   * Inconsistent app ID.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_INCONSISTENT_APP_ID = 18,
  /**
   * Invalid channel name.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_INVALID_CHANNEL_NAME = 19,
  /**
   * Invalid user ID.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_INVALID_USER_ID = 20,
  /**
   * Not initialized.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_NOT_INITIALIZED = 21,
  /**
   * Rtm service not connected.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_RTM_SERVICE_NOT_CONNECTED = 22,
  /**
   * Channel instance exceed limitation.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_CHANNEL_INSTANCE_EXCEED_LIMITATION = 23,
  /**
   * Operation rate exceed limitation.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_OPERATION_RATE_EXCEED_LIMITATION = 24,
  /**
   * Channel in error state.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_CHANNEL_IN_ERROR_STATE = 25,
  /**
   * Presence not connected.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_PRESENCE_NOT_CONNECTED = 26,
  /**
   * Same UID login.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_SAME_UID_LOGIN = 27,
  /**
   * Kicked out by server.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_KICKED_OUT_BY_SERVER = 28,
  /**
   * Keep alive timeout.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_KEEP_ALIVE_TIMEOUT = 29,
  /**
   * Connection error.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_CONNECTION_ERROR = 30,
  /**
   * Presence not ready.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_PRESENCE_NOT_READY = 31,
  /**
   * Network change.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_NETWORK_CHANGE = 32,
  /**
   * Service not supported.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_SERVICE_NOT_SUPPORTED = 33,
  /**
   * Stream channel not available.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_STREAM_CHANNEL_NOT_AVAILABLE = 34,
  /**
   * storage not available.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_STORAGE_NOT_AVAILABLE = 35,
  /**
   * Lock not available.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_LOCK_NOT_AVAILABLE = 36,
  /**
   * Login too frequent.
   */
  C_RTM_LINK_STATE_CHANGE_REASON_LOGIN_TOO_FREQUENT = 37,
} C_RTM_LINK_STATE_CHANGE_REASON;

/**
 * Rtm protocol type for underlying connection.
 */
typedef enum _C_RTM_PROTOCOL_TYPE {
    /**
     * TCP and UDP (default).
     */
    C_RTM_PROTOCOL_TYPE_TCP_UDP = 0,
    /**
     * Use TCP only.
     */
    C_RTM_PROTOCOL_TYPE_TCP_ONLY = 1,
} C_RTM_PROTOCOL_TYPE;

/**
 * Rtm service type.
 */
typedef enum _C_RTM_SERVICE_TYPE {
    /**
     * The type of rtm service not specified.
     */
    C_RTM_SERVICE_TYPE_NONE = 0x00000000,
    /**
     * The basic functionality of rtm service.
     */
    C_RTM_SERVICE_TYPE_MESSAGE = 0x00000001,
    /**
     * The advanced functionality of rtm service.
     */
    C_RTM_SERVICE_TYPE_STREAM = 0x00000002,
} C_RTM_SERVICE_TYPE;

/**
 * IP areas.
 */
typedef enum _C_RTM_AREA_CODE {
  /**
   * Mainland China.
   */
  C_RTM_AREA_CODE_CN = 0x00000001,
  /**
   * North America.
   */
  C_RTM_AREA_CODE_NA = 0x00000002,
  /**
   * Europe.
   */
  C_RTM_AREA_CODE_EU = 0x00000004,
  /**
   * Asia, excluding Mainland China.
   */
  C_RTM_AREA_CODE_AS = 0x00000008,
  /**
   * Japan.
   */
  C_RTM_AREA_CODE_JP = 0x00000010,
  /**
   * India.
   */
  C_RTM_AREA_CODE_IN = 0x00000020,
  /**
   * (Default) Global.
   */
  C_RTM_AREA_CODE_GLOB = (0xFFFFFFFF)
} C_RTM_AREA_CODE;

/**
 * @brief Log level for C API.
 */
typedef enum _C_RTM_LOG_LEVEL {
  /**
   * 0x0000: No logging.
   */
  C_RTM_LOG_LEVEL_NONE = 0x0000,
  /**
   * 0x0001: Informational messages.
   */
  C_RTM_LOG_LEVEL_INFO = 0x0001,
  /**
   * 0x0002: Warnings.
   */
  C_RTM_LOG_LEVEL_WARN = 0x0002,
  /**
   * 0x0004: Errors.
   */
  C_RTM_LOG_LEVEL_ERROR = 0x0004,
  /**
   * 0x0008: Critical errors that may lead to program termination.
   */
  C_RTM_LOG_LEVEL_FATAL = 0x0008,
} C_RTM_LOG_LEVEL;

/**
 * The encryption mode.
 */
typedef enum _C_RTM_ENCRYPTION_MODE {
  /**
   * Disable message encryption.
   */
  C_RTM_ENCRYPTION_MODE_NONE = 0,
  /**
   * 128-bit AES encryption, GCM mode.
   */
  C_RTM_ENCRYPTION_MODE_AES_128_GCM = 1,
  /**
   * 256-bit AES encryption, GCM mode.
   */
  C_RTM_ENCRYPTION_MODE_AES_256_GCM = 2,
} C_RTM_ENCRYPTION_MODE;

/**
 * The error codes of rtm client.
 */
typedef enum _C_RTM_ERROR_CODE {
  /**
   * 0: No error occurs.
   */
  C_RTM_ERROR_OK = 0,

  /**
   * -10001 ~ -11000 : reserved for generic error.
   * -10001: The SDK is not initialized.
   */
  C_RTM_ERROR_NOT_INITIALIZED = -10001,
  /**
   * -10002: The user didn't login the RTM system.
   */
  C_RTM_ERROR_NOT_LOGIN = -10002,
  /**
   * -10003: The app ID is invalid.
   */
  C_RTM_ERROR_INVALID_APP_ID = -10003,
  /**
   * -10004: The event handler is invalid.
   */
  C_RTM_ERROR_INVALID_EVENT_HANDLER = -10004,
  /**
   * -10005: The token is invalid.
   */
  C_RTM_ERROR_INVALID_TOKEN = -10005,
  /**
   * -10006: The user ID is invalid.
   */
  C_RTM_ERROR_INVALID_USER_ID = -10006,
  /**
   * -10007: The service is not initialized.
   */
  C_RTM_ERROR_INIT_SERVICE_FAILED = -10007,
  /**
   * -10008: The channel name is invalid.
   */
  C_RTM_ERROR_INVALID_CHANNEL_NAME = -10008,
  /**
   * -10009: The token has expired.
   */
  C_RTM_ERROR_TOKEN_EXPIRED = -10009,
  /**
   * -10010: There is no server resources now.
   */
  C_RTM_ERROR_LOGIN_NO_SERVER_RESOURCES = -10010,
  /**
   * -10011: The login timeout.
   */
  C_RTM_ERROR_LOGIN_TIMEOUT = -10011,
  /**
   * -10012: The login is rejected by server.
   */
  C_RTM_ERROR_LOGIN_REJECTED = -10012,
  /**
   * -10013: The login is aborted due to unrecoverable error.
   */
  C_RTM_ERROR_LOGIN_ABORTED = -10013,
  /**
   * -10014: The parameter is invalid.
   */
  C_RTM_ERROR_INVALID_PARAMETER = -10014,
  /**
   * -10015: The login is not authorized. Happens user login the RTM system without granted from console.
   */
  C_RTM_ERROR_LOGIN_NOT_AUTHORIZED = -10015,
  /**
   * -10016: Try to login or join with inconsistent app ID.
   */
  C_RTM_ERROR_INCONSISTENT_APPID = -10016,
  /**
   * -10017: Already call same request.
   */
  C_RTM_ERROR_DUPLICATE_OPERATION = -10017,
  /**
   * -10018: Already call destroy or release, this instance is forbidden to call any api, please create new instance.
   */
  C_RTM_ERROR_INSTANCE_ALREADY_RELEASED = -10018,
  /**
   * -10019: The channel type is invalid.
   */
  C_RTM_ERROR_INVALID_CHANNEL_TYPE = -10019,
  /**
   * -10020: The encryption parameter is invalid.
   */
  C_RTM_ERROR_INVALID_ENCRYPTION_PARAMETER = -10020,
  /**
   * -10021: The operation is too frequent.
   */
  C_RTM_ERROR_OPERATION_RATE_EXCEED_LIMITATION = -10021,

  /**
   * -11001 ~ -12000 : reserved for channel error.
   * -11001: The user has not joined the channel.
   */
  C_RTM_ERROR_CHANNEL_NOT_JOINED = -11001,
  /**
   * -11002: The user has not subscribed the channel.
   */
  C_RTM_ERROR_CHANNEL_NOT_SUBSCRIBED = -11002,
  /**
   * -11003: The topic member count exceeds the limit.
   */
  C_RTM_ERROR_CHANNEL_EXCEED_TOPIC_USER_LIMITATION = -11003,
  /**
   * -11004: The channel is reused in RTC.
   */
  C_RTM_ERROR_CHANNEL_IN_REUSE = -11004,
  /**
   * -11005: The channel instance count exceeds the limit.
   */
  C_RTM_ERROR_CHANNEL_INSTANCE_EXCEED_LIMITATION = -11005,
  /**
   * -11006: The channel is in error state.
   */
  C_RTM_ERROR_CHANNEL_IN_ERROR_STATE = -11006,
  /**
   * -11007: The channel join failed.
   */
  C_RTM_ERROR_CHANNEL_JOIN_FAILED = -11007,
  /**
   * -11008: The topic name is invalid.
   */
  C_RTM_ERROR_CHANNEL_INVALID_TOPIC_NAME = -11008,
  /**
   * -11009: The message is invalid.
   */
  C_RTM_ERROR_CHANNEL_INVALID_MESSAGE = -11009,
  /**
   * -11010: The message length exceeds the limit.
   */
  C_RTM_ERROR_CHANNEL_MESSAGE_LENGTH_EXCEED_LIMITATION = -11010,
  /**
   * -11011: The user list is invalid.
   */
  C_RTM_ERROR_CHANNEL_INVALID_USER_LIST = -11011,
  /**
   * -11012: The stream channel is not available.
   */
  C_RTM_ERROR_CHANNEL_NOT_AVAILABLE = -11012,
  /**
   * -11013: The topic is not subscribed.
   */
  C_RTM_ERROR_CHANNEL_TOPIC_NOT_SUBSCRIBED = -11013,
  /**
   * -11014: The topic count exceeds the limit.
   */
  C_RTM_ERROR_CHANNEL_EXCEED_TOPIC_LIMITATION = -11014,
  /**
   * -11015: Join topic failed.
   */
  C_RTM_ERROR_CHANNEL_JOIN_TOPIC_FAILED = -11015,
  /**
   * -11016: The topic is not joined.
   */
  C_RTM_ERROR_CHANNEL_TOPIC_NOT_JOINED = -11016,
  /**
   * -11017: The topic does not exist.
   */
  C_RTM_ERROR_CHANNEL_TOPIC_NOT_EXIST = -11017,
  /**
   * -11018: The topic meta is invalid.
   */
  C_RTM_ERROR_CHANNEL_INVALID_TOPIC_META = -11018,
  /**
   * -11019: Subscribe channel timeout.
   */
  C_RTM_ERROR_CHANNEL_SUBSCRIBE_TIMEOUT = -11019,
  /**
   * -11020: Subscribe channel too frequent.
   */
  C_RTM_ERROR_CHANNEL_SUBSCRIBE_TOO_FREQUENT = -11020,
  /**
   * -11021: Subscribe channel failed.
   */
  C_RTM_ERROR_CHANNEL_SUBSCRIBE_FAILED = -11021,
  /**
   * -11022: Unsubscribe channel failed.
   */
  C_RTM_ERROR_CHANNEL_UNSUBSCRIBE_FAILED = -11022,
  /**
   * -11023: Encrypt message failed.
   */
  C_RTM_ERROR_CHANNEL_ENCRYPT_MESSAGE_FAILED = -11023,
  /**
   * -11024: Publish message failed.
   */
  C_RTM_ERROR_CHANNEL_PUBLISH_MESSAGE_FAILED = -11024,
  /**
   * -11025: Publish message too frequent.
   */
  C_RTM_ERROR_CHANNEL_PUBLISH_MESSAGE_TOO_FREQUENT = -11025,
  /**
   * -11026: Publish message timeout.
   */
  C_RTM_ERROR_CHANNEL_PUBLISH_MESSAGE_TIMEOUT = -11026,
  /**
   * -11027: The connection state is invalid.
   */
  C_RTM_ERROR_CHANNEL_NOT_CONNECTED = -11027,
  /**
   * -11028: Leave channel failed.
   */
  C_RTM_ERROR_CHANNEL_LEAVE_FAILED = -11028,
  /**
   * -11029: The custom type length exceeds the limit.
   */
  C_RTM_ERROR_CHANNEL_CUSTOM_TYPE_LENGTH_OVERFLOW = -11029,
  /**
   * -11030: The custom type is invalid.
   */
  C_RTM_ERROR_CHANNEL_INVALID_CUSTOM_TYPE = -11030,
  /**
   * -11031: unsupported message type (in MacOS/iOS platform，message only support NSString and NSData)
   */
  C_RTM_ERROR_CHANNEL_UNSUPPORTED_MESSAGE_TYPE = -11031,
  /**
   * -11032: The channel presence is not ready.
   */
  C_RTM_ERROR_CHANNEL_PRESENCE_NOT_READY = -11032,
  /**
   * -11033: The destination user of publish message is offline.
   */
  C_RTM_ERROR_CHANNEL_RECEIVER_OFFLINE = -11033,

  /**
   * -12001 ~ -13000 : reserved for storage error.
   * -12001: The storage operation failed.
   */
  C_RTM_ERROR_STORAGE_OPERATION_FAILED = -12001,
  /**
   * -12002: The metadata item count exceeds the limit.
   */
  C_RTM_ERROR_STORAGE_METADATA_ITEM_EXCEED_LIMITATION = -12002,
  /**
   * -12003: The metadata item is invalid.
   */
  C_RTM_ERROR_STORAGE_INVALID_METADATA_ITEM = -12003,
  /**
   * -12004: The argument in storage operation is invalid.
   */
  C_RTM_ERROR_STORAGE_INVALID_ARGUMENT = -12004,
  /**
   * -12005: The revision in storage operation is invalid.
   */
  C_RTM_ERROR_STORAGE_INVALID_REVISION = -12005,
  /**
   * -12006: The metadata length exceeds the limit.
   */
  C_RTM_ERROR_STORAGE_METADATA_LENGTH_OVERFLOW = -12006,
  /**
   * -12007: The lock name in storage operation is invalid.
   */
  C_RTM_ERROR_STORAGE_INVALID_LOCK_NAME = -12007,
  /**
   * -12008: The lock in storage operation is not acquired.
   */
  C_RTM_ERROR_STORAGE_LOCK_NOT_ACQUIRED = -12008,
  /**
   * -12009: The metadata key is invalid.
   */
  C_RTM_ERROR_STORAGE_INVALID_KEY = -12009,
  /**
   * -12010: The metadata value is invalid.
   */
  C_RTM_ERROR_STORAGE_INVALID_VALUE = -12010,
  /**
   * -12011: The metadata key length exceeds the limit.
   */
  C_RTM_ERROR_STORAGE_KEY_LENGTH_OVERFLOW = -12011,
  /**
   * -12012: The metadata value length exceeds the limit.
   */
  C_RTM_ERROR_STORAGE_VALUE_LENGTH_OVERFLOW = -12012,
  /**
   * -12013: The metadata key already exists.
   */
  C_RTM_ERROR_STORAGE_DUPLICATE_KEY = -12013,
  /**
   * -12014: The revision in storage operation is outdated.
   */
  C_RTM_ERROR_STORAGE_OUTDATED_REVISION = -12014,
  /**
   * -12015: The storage operation performed without subscribing.
   */
  C_RTM_ERROR_STORAGE_NOT_SUBSCRIBE = -12015,
  /**
   * -12016: The metadata item is invalid.
   */
  C_RTM_ERROR_STORAGE_INVALID_METADATA_INSTANCE = -12016,
  /**
   * -12017: The user count exceeds the limit when try to subscribe.
   */
  C_RTM_ERROR_STORAGE_SUBSCRIBE_USER_EXCEED_LIMITATION = -12017,
  /**
   * -12018: The storage operation timeout.
   */
  C_RTM_ERROR_STORAGE_OPERATION_TIMEOUT = -12018,
  /**
   * -12019: The storage service not available.
   */
  C_RTM_ERROR_STORAGE_NOT_AVAILABLE = -12019,

  /**
   * -13001 ~ -14000 : reserved for presence error.
   * -13001: The user is not connected.
   */
  C_RTM_ERROR_PRESENCE_NOT_CONNECTED = -13001,
  /**
   * -13002: The presence is not writable.
   */
  C_RTM_ERROR_PRESENCE_NOT_WRITABLE = -13002,
  /**
   * -13003: The argument in presence operation is invalid.
   */
  C_RTM_ERROR_PRESENCE_INVALID_ARGUMENT = -13003,
  /**
   * -13004: The cached presence state count exceeds the limit.
   */
  C_RTM_ERROR_PRESENCE_CACHED_TOO_MANY_STATES = -13004,
  /**
   * -13005: The state count exceeds the limit.
   */
  C_RTM_ERROR_PRESENCE_STATE_COUNT_OVERFLOW = -13005,
  /**
   * -13006: The state key is invalid.
   */
  C_RTM_ERROR_PRESENCE_INVALID_STATE_KEY = -13006,
  /**
   * -13007: The state value is invalid.
   */
  C_RTM_ERROR_PRESENCE_INVALID_STATE_VALUE = -13007,
  /**
   * -13008: The state key length exceeds the limit.
   */
  C_RTM_ERROR_PRESENCE_STATE_KEY_SIZE_OVERFLOW = -13008,
  /**
   * -13009: The state value length exceeds the limit.
   */
  C_RTM_ERROR_PRESENCE_STATE_VALUE_SIZE_OVERFLOW = -13009,
  /**
   * -13010: The state key already exists.
   */
  C_RTM_ERROR_PRESENCE_STATE_DUPLICATE_KEY = -13010,
  /**
   * -13011: The user is not exist.
   */
  C_RTM_ERROR_PRESENCE_USER_NOT_EXIST = -13011,
  /**
   * -13012: The presence operation timeout.
   */
  C_RTM_ERROR_PRESENCE_OPERATION_TIMEOUT = -13012,
  /**
   * -13013: The presence operation failed.
   */
  C_RTM_ERROR_PRESENCE_OPERATION_FAILED = -13013,

  /**
   * -14001 ~ -15000 : reserved for lock error.
   * -14001: The lock operation failed.
   */
  C_RTM_ERROR_LOCK_OPERATION_FAILED = -14001,
  /**
   * -14002: The lock operation timeout.
   */
  C_RTM_ERROR_LOCK_OPERATION_TIMEOUT = -14002,
  /**
   * -14003: The lock operation is performing.
   */
  C_RTM_ERROR_LOCK_OPERATION_PERFORMING = -14003,
  /**
   * -14004: The lock already exists.
   */
  C_RTM_ERROR_LOCK_ALREADY_EXIST = -14004,
  /**
   * -14005: The lock name is invalid.
   */
  C_RTM_ERROR_LOCK_INVALID_NAME = -14005,
  /**
   * -14006: The lock is not acquired.
   */
  C_RTM_ERROR_LOCK_NOT_ACQUIRED = -14006,
  /**
   * -14007: Acquire lock failed.
   */
  C_RTM_ERROR_LOCK_ACQUIRE_FAILED = -14007,
  /**
   * -14008: The lock is not exist.
   */
  C_RTM_ERROR_LOCK_NOT_EXIST = -14008,
  /**
   * -14009: The lock service is not available.
   */
  C_RTM_ERROR_LOCK_NOT_AVAILABLE = -14009,
} C_RTM_ERROR_CODE;

/**
 * Connection states between rtm sdk and agora server.
 */
typedef enum _C_RTM_CONNECTION_STATE {
  /**
   * 1: The SDK is disconnected with server.
   */
  C_RTM_CONNECTION_STATE_DISCONNECTED = 1,
  /**
   * 2: The SDK is connecting to the server.
   */
  C_RTM_CONNECTION_STATE_CONNECTING = 2,
  /**
   * 3: The SDK is connected to the server and has joined a channel. You can now publish or subscribe to
   * a track in the channel.
   */
  C_RTM_CONNECTION_STATE_CONNECTED = 3,
  /**
   * 4: The SDK keeps rejoining the channel after being disconnected from the channel, probably because of
   * network issues.
   */
  C_RTM_CONNECTION_STATE_RECONNECTING = 4,
  /**
   * 5: The SDK fails to connect to the server or join the channel.
   */
  C_RTM_CONNECTION_STATE_FAILED = 5,
} C_RTM_CONNECTION_STATE;

/**
 * Reasons for connection state change.
 */
typedef enum _C_RTM_CONNECTION_CHANGE_REASON {
  /**
   * 0: The SDK is connecting to the server.
   */
  C_RTM_CONNECTION_CHANGED_CONNECTING = 0,
  /**
   * 1: The SDK has joined the channel successfully.
   */
  C_RTM_CONNECTION_CHANGED_JOIN_SUCCESS = 1,
  /**
   * 2: The connection between the SDK and the server is interrupted.
   */
  C_RTM_CONNECTION_CHANGED_INTERRUPTED = 2,
  /**
   * 3: The connection between the SDK and the server is banned by the server.
   */
  C_RTM_CONNECTION_CHANGED_BANNED_BY_SERVER = 3,
  /**
   * 4: The SDK fails to join the channel for more than 20 minutes and stops reconnecting to the channel.
   */
  C_RTM_CONNECTION_CHANGED_JOIN_FAILED = 4,
  /**
   * 5: The SDK has left the channel.
   */
  C_RTM_CONNECTION_CHANGED_LEAVE_CHANNEL = 5,
  /**
   * 6: The connection fails because the App ID is not valid.
   */
  C_RTM_CONNECTION_CHANGED_INVALID_APP_ID = 6,
  /**
   * 7: The connection fails because the channel name is not valid.
   */
  C_RTM_CONNECTION_CHANGED_INVALID_CHANNEL_NAME = 7,
  /**
   * 8: The connection fails because the token is not valid.
   */
  C_RTM_CONNECTION_CHANGED_INVALID_TOKEN = 8,
  /**
   * 9: The connection fails because the token has expired.
   */
  C_RTM_CONNECTION_CHANGED_TOKEN_EXPIRED = 9,
  /**
   * 10: The connection is rejected by the server.
   */
  C_RTM_CONNECTION_CHANGED_REJECTED_BY_SERVER = 10,
  /**
   * 11: The connection changes to reconnecting because the SDK has set a proxy server.
   */
  C_RTM_CONNECTION_CHANGED_SETTING_PROXY_SERVER = 11,
  /**
   * 12: When the connection state changes because the app has renewed the token.
   */
  C_RTM_CONNECTION_CHANGED_RENEW_TOKEN = 12,
  /**
   * 13: The IP Address of the app has changed. A change in the network type or IP/Port changes the IP
   * address of the app.
   */
  C_RTM_CONNECTION_CHANGED_CLIENT_IP_ADDRESS_CHANGED = 13,
  /**
   * 14: A timeout occurs for the keep-alive of the connection between the SDK and the server.
   */
  C_RTM_CONNECTION_CHANGED_KEEP_ALIVE_TIMEOUT = 14,
  /**
   * 15: The SDK has rejoined the channel successfully.
   */
  C_RTM_CONNECTION_CHANGED_REJOIN_SUCCESS = 15,
  /**
   * 16: The connection between the SDK and the server is lost.
   */
  C_RTM_CONNECTION_CHANGED_LOST = 16,
  /**
   * 17: The change of connection state is caused by echo test.
   */
  C_RTM_CONNECTION_CHANGED_ECHO_TEST = 17,
  /**
   * 18: The local IP Address is changed by user.
   */
  C_RTM_CONNECTION_CHANGED_CLIENT_IP_ADDRESS_CHANGED_BY_USER = 18,
  /**
   * 19: The connection is failed due to join the same channel on another device with the same uid.
   */
  C_RTM_CONNECTION_CHANGED_SAME_UID_LOGIN = 19,
  /**
   * 20: The connection is failed due to too many broadcasters in the channel.
   */
  C_RTM_CONNECTION_CHANGED_TOO_MANY_BROADCASTERS = 20,
  /**
   * 21: The connection is failed due to license validation failure.
   */
  C_RTM_CONNECTION_CHANGED_LICENSE_VALIDATION_FAILURE = 21,
  /**
   * 22: The connection is failed due to user vid not support stream channel.
   */
  C_RTM_CONNECTION_CHANGED_STREAM_CHANNEL_NOT_AVAILABLE = 22,
  /**
   * 23: The connection is failed due to token and appid inconsistent.
   */
  C_RTM_CONNECTION_CHANGED_INCONSISTENT_APPID = 23,
  /**
   * 10001: The connection of rtm edge service has been successfully established.
   */
  C_RTM_CONNECTION_CHANGED_LOGIN_SUCCESS = 10001,
  /**
   * 10002: User log out Agora RTM system.
   */
  C_RTM_CONNECTION_CHANGED_LOGOUT = 10002,
  /**
   * 10003: User log out Agora RTM system.
   */
  C_RTM_CONNECTION_CHANGED_PRESENCE_NOT_READY = 10003,
} C_RTM_CONNECTION_CHANGE_REASON;

/**
 * RTM channel type.
 */
typedef enum _C_RTM_CHANNEL_TYPE {
  /**
   * 0: Unknown channel type.
   */
  C_RTM_CHANNEL_TYPE_NONE = 0,
  /**
   * 1: Message channel.
   */
  C_RTM_CHANNEL_TYPE_MESSAGE = 1,
  /**
   * 2: Stream channel.
   */
  C_RTM_CHANNEL_TYPE_STREAM = 2,
  /**
   * 3: User.
   */
  C_RTM_CHANNEL_TYPE_USER = 3,
} C_RTM_CHANNEL_TYPE;

/**
  @brief Message type when user publish message to channel or topic
  */
typedef enum _C_RTM_MESSAGE_TYPE {
  /**
    0: The binary message.
    */
  C_RTM_MESSAGE_TYPE_BINARY = 0,
  /**
    1: The ascii message.
    */
  C_RTM_MESSAGE_TYPE_STRING = 1,
} C_RTM_MESSAGE_TYPE;

/**
  @brief Storage type indicate the storage event was triggered by user or channel
  */
typedef enum _C_RTM_STORAGE_TYPE {
  /**
    0: Unknown type.
    */
  C_RTM_STORAGE_TYPE_NONE = 0,
  /**
    1: The user storage event.
    */
  C_RTM_STORAGE_TYPE_USER = 1,
  /**
    2: The channel storage event.
    */
  C_RTM_STORAGE_TYPE_CHANNEL = 2,
} C_RTM_STORAGE_TYPE;

/**
 * The storage event type, indicate storage operation
 */
typedef enum _C_RTM_STORAGE_EVENT_TYPE {
  /**
    0: Unknown event type.
    */
  C_RTM_STORAGE_EVENT_TYPE_NONE = 0,
  /**
    1: Triggered when user subscribe user metadata state or join channel with options.withMetadata = true
    */
  C_RTM_STORAGE_EVENT_TYPE_SNAPSHOT = 1,
  /**
    2: Triggered when a remote user set metadata
    */
  C_RTM_STORAGE_EVENT_TYPE_SET = 2,
  /**
    3: Triggered when a remote user update metadata
    */
  C_RTM_STORAGE_EVENT_TYPE_UPDATE = 3,
  /**
    4: Triggered when a remote user remove metadata
    */
  C_RTM_STORAGE_EVENT_TYPE_REMOVE = 4,
} C_RTM_STORAGE_EVENT_TYPE;

/**
 * The lock event type, indicate lock operation
 */
typedef enum _C_RTM_LOCK_EVENT_TYPE {
  /**
   * 0: Unknown event type
   */
  C_RTM_LOCK_EVENT_TYPE_NONE = 0,
  /**
   * 1: Triggered when user subscribe lock state
   */
  C_RTM_LOCK_EVENT_TYPE_SNAPSHOT = 1,
  /**
   * 2: Triggered when a remote user set lock
   */
  C_RTM_LOCK_EVENT_TYPE_LOCK_SET = 2,
  /**
   * 3: Triggered when a remote user remove lock
   */
  C_RTM_LOCK_EVENT_TYPE_LOCK_REMOVED = 3,
  /**
   * 4: Triggered when a remote user acquired lock
   */
  C_RTM_LOCK_EVENT_TYPE_LOCK_ACQUIRED = 4,
  /**
   * 5: Triggered when a remote user released lock
   */
  C_RTM_LOCK_EVENT_TYPE_LOCK_RELEASED = 5,
  /**
   * 6: Triggered when user reconnect to rtm service,
   * detect the lock has been acquired and released by others.
   */
  C_RTM_LOCK_EVENT_TYPE_LOCK_EXPIRED = 6,
} C_RTM_LOCK_EVENT_TYPE;

/**
 * The proxy type
 */
typedef enum _C_RTM_PROXY_TYPE {
  /**
   * 0: Link without proxy
   */
  C_RTM_PROXY_TYPE_NONE = 0,
  /**
   * 1: Link with http proxy
   */
  C_RTM_PROXY_TYPE_HTTP = 1,
  /**
   * 2: Link with tcp cloud proxy
   */
  C_RTM_PROXY_TYPE_CLOUD_TCP = 2,
} C_RTM_PROXY_TYPE;

/**
  @brief Topic event type
  */
typedef enum _C_RTM_TOPIC_EVENT_TYPE {
  /**
   * 0: Unknown event type
   */
  C_RTM_TOPIC_EVENT_TYPE_NONE = 0,
  /**
   * 1: The topic snapshot of this channel
   */
  C_RTM_TOPIC_EVENT_TYPE_SNAPSHOT = 1,
  /**
   * 2: Triggered when remote user join a topic
   */
  C_RTM_TOPIC_EVENT_TYPE_REMOTE_JOIN_TOPIC = 2,
  /**
   * 3: Triggered when remote user leave a topic
   */
  C_RTM_TOPIC_EVENT_TYPE_REMOTE_LEAVE_TOPIC = 3,
} C_RTM_TOPIC_EVENT_TYPE;

/**
  @brief Presence event type
  */
typedef enum _C_RTM_PRESENCE_EVENT_TYPE {
  /**
   * 0: Unknown event type
   */
  C_RTM_PRESENCE_EVENT_TYPE_NONE = 0,
  /**
   * 1: The presence snapshot of this channel
   */
  C_RTM_PRESENCE_EVENT_TYPE_SNAPSHOT = 1,
  /**
   * 2: The presence event triggered in interval mode
   */
  C_RTM_PRESENCE_EVENT_TYPE_INTERVAL = 2,
  /**
   * 3: Triggered when remote user join channel
   */
  C_RTM_PRESENCE_EVENT_TYPE_REMOTE_JOIN_CHANNEL = 3,
  /**
   * 4: Triggered when remote user leave channel
   */
  C_RTM_PRESENCE_EVENT_TYPE_REMOTE_LEAVE_CHANNEL = 4,
  /**
   * 5: Triggered when remote user's connection timeout
   */
  C_RTM_PRESENCE_EVENT_TYPE_REMOTE_TIMEOUT = 5,
  /**
   * 6: Triggered when user changed state
   */
  C_RTM_PRESENCE_EVENT_TYPE_REMOTE_STATE_CHANGED = 6,
  /**
   * 7: Triggered when user joined channel without presence service
   */
  C_RTM_PRESENCE_EVENT_TYPE_ERROR_OUT_OF_SERVICE = 7,
} C_RTM_PRESENCE_EVENT_TYPE;

/**
 * @brief Log configuration structure for C API.
 */
typedef struct _rtm_log_config
{
  /**
   * The log file path, default is NULL for default log path
   */
  const char *filePath;
  /**
   * The log file size, KB , set 1024KB to use default log size
   */
  uint32_t fileSizeInKB;
  /**
   *  The log level, set C_RTM_LOG_LEVEL_INFO to use default log level
   */
  C_RTM_LOG_LEVEL level;
} rtm_log_config;
rtm_log_config *rtm_log_config_create();
void rtm_log_config_delete(rtm_log_config *this_);

/**
 * User list.
 */
typedef struct _user_list
{
  /**
   * The list of users.
   */
  const char **users;
  /**
   * The number of users.
   */
  size_t userCount;
} user_list;
user_list *user_list_create();
void user_list_delete(user_list *this_);

/**
  @brief Topic publisher information
  */
typedef struct _publisher_info
{
  /**
   * The publisher user ID
   */
  const char *publisherUserId;
  /**
   * The metadata of the publisher
   */
  const char *publisherMeta;
} publisher_info;
publisher_info *publisher_info_create();
void publisher_info_delete(publisher_info *this_);

/**
  @brief Topic information
  */
typedef struct _topic_info
{
  /**
   * The name of the topic
   */
  const char *topic;
  /**
   * The publisher array
   */
  publisher_info *publishers;
  /**
   * The count of publisher in current topic
   */
  size_t publisherCount;
} topic_info;
topic_info *topic_info_create();
void topic_info_delete(topic_info *this_);

/**
  @brief User state property
  */
typedef struct _state_item
{
  /**
   * The key of the state item.
   */
  const char *key;
  /**
   * The value of the state item.
   */
  const char *value;
} state_item;
state_item *state_item_create();
void state_item_delete(state_item *this_);

/**
 *  The information of a Lock.
 */
typedef struct _lock_detail
{
  /**
   * The name of the lock.
   */
  const char *lockName;
  /**
   * The owner of the lock. Only valid when user getLocks or receive LockEvent with RTM_LOCK_EVENT_TYPE_SNAPSHOT
   */
  const char *owner;
  /**
   * The ttl of the lock.
   */
  uint32_t ttl;
} lock_detail;
lock_detail *lock_detail_create();
void lock_detail_delete(lock_detail *this_);

/**
 *  The states of user.
 */
typedef struct _user_state
{
  /**
   * The user id.
   */
  const char *userId;
  /**
   * The user states.
   */
  const state_item *states;
  /**
   * The count of user states.
   */
  size_t statesCount;
} user_state;
user_state *user_state_create();
void user_state_delete(user_state *this_);

/**
 *  The subscribe option.
 */
typedef struct _subscribe_options
{
  /**
   * Whether to subscribe channel with message
   */
  bool withMessage;
  /**
   * Whether to subscribe channel with metadata
   */
  bool withMetadata;
  /**
   * Whether to subscribe channel with user presence
   */
  bool withPresence;
  /**
   * Whether to subscribe channel with lock
   */
  bool withLock;
} subscribe_options;
subscribe_options *subscribe_options_create();
void subscribe_options_delete(subscribe_options *this_);

/**
 *  The channel information.
 */
typedef struct _channel_info
{
  /**
   * The channel which the message was published
   */
  const char *channelName;
  /**
   * Which channel type, C_RTM_CHANNEL_TYPE_STREAM or C_RTM_CHANNEL_TYPE_MESSAGE
   */
  C_RTM_CHANNEL_TYPE channelType;
} channel_info;
channel_info *channel_info_create();
void channel_info_delete(channel_info *this_);

/**
 *  The option to query user presence.
 */
typedef struct _presence_options
{
  /**
   * Whether to display user id in query result
   */
  bool includeUserId;
  /**
   * Whether to display user state in query result
   */
  bool includeState;
  /**
   * The paging object used for pagination.
   */
  const char *page;
} presence_options;
presence_options *presence_options_create();
void presence_options_delete(presence_options *this_);

/**
 *  The option to query user presence.
 */
typedef struct _get_online_users_options
{
  /**
   * Whether to display user id in query result
   */
  bool includeUserId;
  /**
   * Whether to display user state in query result
   */
  bool includeState;
  /**
   * The paging object used for pagination.
   */
  const char *page;
} get_online_users_options;
get_online_users_options *get_online_users_options_create();
void get_online_users_options_delete(get_online_users_options *this_);

/**
  @brief Publish message option
  */
typedef struct _publish_options
{
 /*
  The channel type.
 */
 C_RTM_CHANNEL_TYPE channelType;
 /**
   The message type.
   */
  C_RTM_MESSAGE_TYPE messageType;
  /**
    The custom type of the message, up to 32 bytes for customize
    */
  const char *customType;
} publish_options;
publish_options *publish_options_create();
void publish_options_delete(publish_options *this_);

/**
  @brief topic message option
  */
typedef struct _topic_message_options
{
  /**
    The message type.
    */
  C_RTM_MESSAGE_TYPE messageType;
  /**
    The time to calibrate data with media,
    only valid when user join topic with syncWithMedia in stream channel
    */
  uint64_t sendTs;
  /**
    The custom type of the message, up to 32 bytes for customize
    */
  const char *customType;
} topic_message_options;
topic_message_options *topic_message_options_create();
void topic_message_options_delete(topic_message_options *this_);

/**
  @brief Proxy configuration
  */
typedef struct _rtm_proxy_config
{
  /**
    The Proxy type.
    */
  C_RTM_PROXY_TYPE proxyType;
  /**
    The Proxy server address.
    */
  const char *server;
  /**
    The Proxy server port.
    */
  uint16_t port;
  /**
    The Proxy user account.
    */
  const char *account;
  /**
    The Proxy password.
    */
  const char *password;
} rtm_proxy_config;
rtm_proxy_config *rtm_proxy_config_create();
void rtm_proxy_config_delete(rtm_proxy_config *this_);

/**
  @brief encryption configuration
  */
typedef struct _rtm_encryption_config
{
  /**
   * The encryption mode.
   */
  C_RTM_ENCRYPTION_MODE encryptionMode;

  /**
   * The encryption key in the string format.
   */
  const char *encryptionKey;

  /**
   * The encryption salt.
   */
  uint8_t encryptionSalt[32];
} rtm_encryption_config;
rtm_encryption_config *rtm_encryption_config_create();
void rtm_encryption_config_delete(rtm_encryption_config *this_);

/**
 * @brief Private configuration
 */
typedef struct _rtm_private_config {
    /**
     * Rtm service type.
     */
    C_RTM_SERVICE_TYPE serviceType;
    /**
     * Local access point hosts list.
     */
    const char** accessPointHosts;
    /**
     * The count of access point hosts list.
     */
    size_t accessPointHostsCount;
} rtm_private_config;
rtm_private_config *rtm_private_config_create();
void rtm_private_config_delete(rtm_private_config *this_);

typedef struct _history_message {
  /**
   * Message type
   */
  C_RTM_MESSAGE_TYPE messageType;
  /**
   * The publisher
   */
  const char* publisher;
  /**
   * The payload
   */
  const char* message;
  /**
   * The payload length
   */
  size_t messageLength;
  /**
   * The custom type of the message
   */
  const char* customType;
  /**
   * Timestamp of the message received by rtm server
   */
  uint64_t timestamp;
} history_message;
history_message *history_message_create();
void history_message_delete(history_message *this_);

#pragma endregion agora::rtm

#pragma endregion agora

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_AGORA_RTM_BASE_H
