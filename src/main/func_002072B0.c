#include "types.h"

typedef struct { int words[4]; } Value16;
extern void func_00207310(Value16* dst, void* src);
extern void func_00209620(Value16* v, void* arg);
extern void func_00138350(Value16* v, int flags);

/* Builds a temporary from src, applies arg to it, copies it into dst, then destroys it; returns 0. */
int func_002072B0(void* dst, void* src, void* arg)
{
    Value16 tmp;
    func_00207310(&tmp, src);
    func_00209620(&tmp, arg);
    func_00207310(dst, &tmp);
    func_00138350(&tmp, -1);
    return 0;
}
