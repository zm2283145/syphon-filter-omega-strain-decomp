#ifndef STATUS_REPORT_WRAPPER_H
#define STATUS_REPORT_WRAPPER_H
/* GCC library wrappers: forward the arguments to an inner call and,
   when it returns 0, report through func_002B5EA8(0, 0, &result). */
extern void func_002B5EA8(int a, int b, int* result);
#define DEFINE_STATUS_REPORT_WRAPPER(name, inner)                   \
    extern int inner(int a, int b, int c, int d);                   \
    int name(int a, int b, int c, int d)                            \
    {                                                               \
        int r = inner(a, b, c, d);                                  \
        if (r != 0)                                                 \
            return r;                                               \
        func_002B5EA8(0, 0, &r);                                    \
        return r;                                                   \
    }
#endif