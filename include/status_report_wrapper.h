#ifndef STATUS_REPORT_WRAPPER_H
#define STATUS_REPORT_WRAPPER_H
/* GCC library wrappers: forward the arguments to an inner call and,
   when it returns 0, report through sceMc2Sync2(0, 0, &result). */
extern void sceMc2Sync2(int a, int b, int* result);
#define DEFINE_STATUS_REPORT_WRAPPER(name, inner)                   \
    extern int inner(int a, int b, int c, int d);                   \
    int name(int a, int b, int c, int d)                            \
    {                                                               \
        int r = inner(a, b, c, d);                                  \
        if (r != 0)                                                 \
            return r;                                               \
        sceMc2Sync2(0, 0, &r);                                    \
        return r;                                                   \
    }
#endif