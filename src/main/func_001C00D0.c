#include "types.h"
typedef struct { int w[3]; } String;
extern void func_0013BCB0(String* dst, String* src);
extern void func_001C4300(String* s, int arg);
extern void String_Dtor(String* s, int flags);
/* Copies src, transforms the copy with arg, and assigns it to dst. */
int func_001C00D0(String* dst, String* src, int arg)
{
    String tmp;
    func_0013BCB0(&tmp, src);
    func_001C4300(&tmp, arg);
    func_0013BCB0(dst, &tmp);
    String_Dtor(&tmp, 0);
    return 0;
}
