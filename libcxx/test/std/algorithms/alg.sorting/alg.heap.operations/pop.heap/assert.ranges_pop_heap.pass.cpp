//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// REQUIRES: has-unix-headers
// UNSUPPORTED: c++03, c++11, c++14, c++17
// UNSUPPORTED: !libcpp-has-hardened-mode && !libcpp-has-debug-mode
// XFAIL: availability-verbose_abort-missing

// <algorithm>

// Calling `ranges::pop_heap` on an empty range is invalid.

#include <algorithm>

#include <array>
#include "check_assertion.h"

int main(int, char**) {
  std::array<int, 0> a;

  TEST_LIBCPP_ASSERT_FAILURE(std::ranges::pop_heap(a.begin(), a.end()), "The heap given to pop_heap must be non-empty");
  TEST_LIBCPP_ASSERT_FAILURE(std::ranges::pop_heap(a), "The heap given to pop_heap must be non-empty");

  return 0;
}
