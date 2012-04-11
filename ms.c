
//
// ms.c
//
// Copyright (c) 2012 TJ Holowaychuk <tj@vision-media.ca>
//

#include <stdlib.h>
#include <string.h>
#include "ms.h"

/*
 * Convert the given `str` representation to microseconds,
 * for example "10ms", "5s", "2m", "1h" etc.
 */

long long
string_to_microseconds(const char *str) {
  size_t len = strlen(str);
  long long val = strtoll(str, NULL, 10);
  if (!val) return -1;
  switch (str[len - 1]) {
    case 's': return  'm' == str[len - 2] ? val * 1000 : val * 1000000;
    case 'm': return val * 60000000;
    case 'h': return val * 3600000000;
    case 'd': return val * 86400000000;
    default:  return val;
  }
}

/*
 * Convert the given `str` representation to milliseconds,
 * for example "10ms", "5s", "2m", "1h" etc.
 */

long long
string_to_milliseconds(const char *str) {
  size_t len = strlen(str);
  long long val = strtoll(str, NULL, 10);
  if (!val) return -1;
  switch (str[len - 1]) {
    case 's': return  'm' == str[len - 2] ? val : val * 1000;
    case 'm': return val * 60 * 1000;
    case 'h': return val * 60 * 60 * 1000;
    case 'd': return val * 24 * 60 * 60 * 1000;
    default:  return val;
  }
}

// tests

#ifdef TEST_MS

#include <assert.h>
#include <stdio.h>

void
test_string_to_microseconds() {
  assert(string_to_microseconds("") == -1);
  assert(string_to_microseconds("s") == -1);
  assert(string_to_microseconds("hey") == -1);
  assert(string_to_microseconds("5000") == 5000);
  assert(string_to_microseconds("1ms") == 1000);
  assert(string_to_microseconds("5ms") == 5000);
  assert(string_to_microseconds("1s") == 1000000);
  assert(string_to_microseconds("5s") == 5000000);
  assert(string_to_microseconds("1m") == 60000000);
  assert(string_to_microseconds("1h") == 3600000000);
  assert(string_to_microseconds("2d") == 2 * 24 * 3600000000);
  assert(strtous("1ms") == 1000);
}

void
test_string_to_milliseconds() {
  assert(string_to_milliseconds("") == -1);
  assert(string_to_milliseconds("s") == -1);
  assert(string_to_milliseconds("hey") == -1);
  assert(string_to_milliseconds("5000") == 5000);
  assert(string_to_milliseconds("1ms") == 1);
  assert(string_to_milliseconds("5ms") == 5);
  assert(string_to_milliseconds("1s") == 1000);
  assert(string_to_milliseconds("5s") == 5000);
  assert(string_to_milliseconds("1m") == 60 * 1000);
  assert(string_to_milliseconds("1h") == 60 * 60 * 1000);
  assert(string_to_milliseconds("1d") == 24 * 60 * 60 * 1000);
  assert(strtoms("50s") == 50000);
}

int
main(){
  test_string_to_microseconds();
  test_string_to_milliseconds();
  printf("\n  \e[32m\u2713 \e[90mok\e[0m\n\n");
  return 0;
}

#endif