#pragma once
#include "stdint.h"

/**
 * https://www.reddit.com/r/C_Programming/comments/gqpuef/comment/fru7tmu/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button
 */
inline int RoundIntDiv(uint64_t a, uint64_t b)
{
  return ((a + (b/2)) / 2);
}