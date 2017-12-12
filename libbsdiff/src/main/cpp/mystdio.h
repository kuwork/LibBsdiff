#include <stdio.h>
#include "logutils.h"

/* ========
   Android Porting
   ======== */
#ifdef __ANDROID__

#include <android/log.h>

static int my_fprintf(FILE *stream, const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    __android_log_vprint(ANDROID_LOG_DEBUG, TAG, format, ap);
    va_end(ap);
    return 0;
}

#ifdef fprintf
#undef fprintf
#endif
#define fprintf(fp, ...) my_fprintf(fp, __VA_ARGS__)

#endif /*__ANDROID__*/