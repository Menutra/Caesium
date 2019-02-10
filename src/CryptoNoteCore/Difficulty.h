// Copyright (c) 2018, The TurtleCoin Developers
// Copyright (c) 2019, The Lithe Project
// 
// Please see the included LICENSE file for more information.

#include <stdint.h>
#include <vector>

uint64_t nextDifficulty(std::vector<uint64_t> timestamps, std::vector<uint64_t> cumulativeDifficulties);

/* TODO: This has been added in the stdlib in c++17 */
template <typename T>
T clamp(const T& n, const T& lower, const T& upper)
{
    return std::max(lower, std::min(n, upper));
}
