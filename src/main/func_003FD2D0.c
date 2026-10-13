#include "types.h"
typedef struct { int w[4]; } SD2D0;
extern unsigned char D_0055D450;
extern void String_CtorCStr_13B480(SD2D0* s, const char* c);
extern int func_003FD740(SD2D0* s);
extern void func_00138B70(SD2D0* s, int del);
extern const char* String_CStr(SD2D0* s);
extern void String_Copy(char* d, const char* s);
int func_003FD2D0(char* buf)
{
    SD2D0 s;
    if (!D_0055D450)
        return 0;
    if (!buf || !*buf)
        return 1;
    String_CtorCStr_13B480(&s, buf);
    if (!func_003FD740(&s)) {
        func_00138B70(&s, 0);
        return 0;
    }
    String_Copy(buf, String_CStr(&s));
    func_00138B70(&s, 0);
    return 1;
}