
//
// ms.h
//
// Copyright (c) 2012 TJ Holowaychuk <tj@vision-media.ca>
//

#ifndef MS
#define MS

#define strtous string_to_microseconds
#define strtoms string_to_milliseconds

long long
string_to_microseconds(const char *str);

long long
string_to_milliseconds(const char *str);

#endif