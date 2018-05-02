# logit -- C logging library

## Usage

```
git clone https://github.com/gidovw/logit
make          # This will create the static library
make install  # This will create the library and cp it in /usr/lib
```

Include the `inc/logit.h` header file in the source code and link against the `liblogit.a` object.

```
gcc [...] -l:liblogit.a
``` 
