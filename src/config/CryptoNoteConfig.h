// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero Project
// Copyright (c) 2018, The TurtleCoin Developers
// Copyright (c) 2019, The Lithe Project
//
// Please see the included LICENSE file for more information.

#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <limits>
#include <initializer_list>
#include <boost/uuid/uuid.hpp>

namespace CryptoNote {
namespace parameters {

const uint64_t DIFFICULTY_TARGET                             = 60; // seconds

const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0xe6dc4e2;
const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 120;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 3 * DIFFICULTY_TARGET;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 11;

// MONEY_SUPPLY - total number coins to be generated
const uint64_t MONEY_SUPPLY                                  = UINT64_C(2500000000000000);

const unsigned EMISSION_SPEED_FACTOR                         = 29;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

/* Premine amount */
const uint64_t GENESIS_BLOCK_REWARD                          = UINT64_C(0);

const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff000188f3b501029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd088071210142694232c5b04151d9e4c27d31ec7a68ea568b19488cfcb422659a07a0e44dd5";
static_assert(sizeof(GENESIS_COINBASE_TX_HEX)/sizeof(*GENESIS_COINBASE_TX_HEX) != 1, "GENESIS_COINBASE_TX_HEX must not be empty.");

/* This is the unix timestamp of the first "mined" block (technically block 2, not the genesis block)
   You can get this value by doing "print_block 2" in Lithedd. It is used to know what timestamp
   to import from when the block height cannot be found in the node or the node is offline. */
const uint64_t GENESIS_BLOCK_TIMESTAMP                       = 1512800692;

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 100000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 20000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 10000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;

const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 5;

const uint64_t MINIMUM_FEE                                   = UINT64_C(10);

/* This section defines our minimum and maximum mixin counts required for transactions */
const uint64_t MINIMUM_MIXIN                                 = 0;
const uint64_t MAXIMUM_MIXIN                                 = 100;
const uint64_t DEFAULT_MIXIN                                 = 2;

const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(0);

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;

const size_t   DIFFICULTY_WINDOW                             = 60;
const uint64_t DIFFICULTY_BLOCKS_COUNT                       = DIFFICULTY_WINDOW + 1;

const size_t   MAX_BLOCK_SIZE_INITIAL                        = 100000;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;
const uint64_t MAX_EXTRA_SIZE                                = 140000;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t UPGRADE_HEIGHT_V2                             = 1; // Upgrade height for CN-Turtle Variant 2 switch.
const uint32_t UPGRADE_HEIGHT_V3                             = 2;
const uint32_t UPGRADE_HEIGHT_CURRENT                        = UPGRADE_HEIGHT_V3;

const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

/* Block heights we are going to have hard forks at */
const uint64_t FORK_HEIGHTS[] =
{
    1,  // 0
    2,  // 1
    3,  // 2
    4  // 3
};

/* MAKE SURE TO UPDATE THIS VALUE WITH EVERY MAJOR RELEASE BEFORE A FORK */
const uint64_t SOFTWARE_SUPPORTED_FORK_INDEX                 = 3;

const uint64_t FORK_HEIGHTS_SIZE = sizeof(FORK_HEIGHTS) / sizeof(*FORK_HEIGHTS);

/* The index in the FORK_HEIGHTS array that this version of the software will
   support. For example, if CURRENT_FORK_INDEX is 3, this version of the
   software will support the fork at 600,000 blocks.

   This will default to zero if the FORK_HEIGHTS array is empty, so you don't
   need to change it manually. */
const uint8_t CURRENT_FORK_INDEX = FORK_HEIGHTS_SIZE == 0 ? 0 : SOFTWARE_SUPPORTED_FORK_INDEX;

static_assert(CURRENT_FORK_INDEX >= 0, "CURRENT FORK INDEX must be >= 0");
/* Make sure CURRENT_FORK_INDEX is a valid index, unless FORK_HEIGHTS is empty */
static_assert(FORK_HEIGHTS_SIZE == 0 || CURRENT_FORK_INDEX < FORK_HEIGHTS_SIZE, "CURRENT_FORK_INDEX out of range of FORK_HEIGHTS!");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.bin";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.bin";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "Lithe";

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  CURRENT_TRANSACTION_VERSION                   =  TRANSACTION_VERSION_1;

const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;

const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  100;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              =  25500;
const int      RPC_DEFAULT_PORT                              =  25501;
const int      SERVICE_DEFAULT_PORT                          =  25502;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

// P2P Network Configuration Section - This defines our current P2P network version
// and the minimum version for communication between nodes
const uint8_t  P2P_CURRENT_VERSION                           = 0;
const uint8_t  P2P_MINIMUM_VERSION                           = 0;

// This defines the minimum P2P version required for lite blocks propogation
const uint8_t P2P_LITE_BLOCKS_PROPOGATION_VERSION            = 0;

// This defines the number of versions ahead we must see peers before we start displaying
// warning messages that we need to upgrade our software.
const uint8_t  P2P_UPGRADE_WINDOW                            = 2;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 32 * 1024 * 1024; // 32 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "";

const uint64_t DATABASE_WRITE_BUFFER_MB_DEFAULT_SIZE         = 256;
const uint64_t DATABASE_READ_BUFFER_MB_DEFAULT_SIZE          = 10;
const uint32_t DATABASE_DEFAULT_MAX_OPEN_FILES               = 100;
const uint16_t DATABASE_DEFAULT_BACKGROUND_THREADS_COUNT     = 2;

const char     LATEST_VERSION_URL[]                          = "http://github.com/lithe-project/lithe/";
const std::string LICENSE_URL                                = "https://github.com/lithe-project/lithe/blob/master/LICENSE";
const static   boost::uuids::uuid CRYPTONOTE_NETWORK         =
{
    {  0x6c, 0x69, 0x74, 0x68, 0x65, 0x20, 0x70, 0x72, 0x6f, 0x6a, 0x65, 0x63, 0x74  }
};

const char* const SEED_NODES[] = {
  "127.0.0.1:25501", /* local seed::temp */
  "67.176.94.193:25501"
};
} // CryptoNote
