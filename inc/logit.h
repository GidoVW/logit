#ifndef LOGIT_H
#define LOGIT_H

#include <errno.h>

extern char *logit_version();

#define _log(...)   _log_msg(__FILE__, __LINE__, __VA_ARGS__)
#define _log_r(...) _log_msg_r(__FILE__, __LINE__, __VA_ARGS__)
#define _err(sysc_s)  _err_msg(__FILE__, __LINE__, errno, sysc_s)

extern void _log_msg(char *filename, int line, char *fmt, ...);
extern void _log_msg_r(char *filename, int line, char *fmt, ...);
extern void _err_msg(char *filename, int line, int errnum, char *sysc);

#endif /* LOGIT_H */
