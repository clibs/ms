
# ms

  Convert strings like "15s" to seconds, milliseconds, or microseconds,
  and convert milliseconds to strings ("300ms", "5ms") or long strings ("5 seconds", "1 month").

## Installation

  Install with [clib](https://github.com/clibs/clib):

```
$ clib install clibs/ms
```

## API

```c
long long
string_to_microseconds(const char *str);

long long
string_to_milliseconds(const char *str);

long long
string_to_seconds(const char *str);

char *
milliseconds_to_string(long long ms);

char *
milliseconds_to_long_string(long long ms);
```

For usage view the [tests](https://github.com/clibs/ms/blob/master/ms.c#L52)