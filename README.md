# logit -- C logging library

Current logit version: 1.0.1

## Install & Linking

```
git clone https://github.com/gidovw/logit
make          # This will create the static library
make install  # This will create the library and cp it in /usr/lib
```

Include the `inc/logit.h` header file in the source code and link against the `liblogit.a` object.

```
gcc [...] -l:liblogit.a
``` 

## Usage

There are three main interfaces that you can use to log messages.

### logit()

`logit()` is the most basic logging interface -- just pass the string you want to log! Example:

```
logit("This is my string");
```

This will print the following output:

```
[file]:[line]: This is my string
```

### logit_r()

`logit_r()` is a more complicated version of `logit()` that you can call several times: it will build up a string for you at each call, and only print the whole string if you add a new line character (`\n`). Example: 

```
logit_r("I want this");
logit_r("to be printed");
logit_r("on one line.\n");
```

This will produce the following output:

```
[file]:[line]: I want this to be printed on one line.
```

### syserr()
