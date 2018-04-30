#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void _err_msg(char *filename, int line, int errnum, char *sysc)
{
  fprintf(stderr, "%s:%d: %s: %s\n", filename, line, sysc, strerror(errnum));
}

void _log_msg(char *filename, int line, char *fmt, ...)
{
  va_list vargs;
  fprintf(stderr, "%s:%d: ", filename, line);
  va_start(vargs, fmt);
  vfprintf(stderr, fmt, vargs);
  va_end(vargs);
  fprintf(stderr, "\n"); /* flush */
}

void _log_msg_r(char *filename, int line, char *fmt, ...)
{
  static char msg[255];
  static bool firstcall = true;
  char tmp[255];
  va_list vargs;

  if (firstcall) {
    firstcall = false;
    strcat(msg, filename);
    sprintf(tmp, ":%d: ", line);
    strncat(msg, tmp, strlen(tmp));
  }

  va_start(vargs, fmt);
  vsprintf(tmp, fmt, vargs);
  va_end(vargs);
  strncat(msg, tmp, strlen(tmp));

  if (strstr(fmt, "\n")) {
    fprintf(stderr, "%s", msg);
    firstcall = true;
    strncpy(msg, "\0", 1);
  }

}
