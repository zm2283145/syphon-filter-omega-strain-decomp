#pragma opt_propagation off
#include "types.h"
extern long long func_003698B0(void);
extern int D_0048C368;
extern int D_0051EF98;
extern char* func_002CCA30(void);
extern int sprintf(char* buf, const char* fmt, ...);
extern void func_002C8840(char* s);
void func_002C7C40(int a, int b)
{
    char buf[0x100];
    char* fmt;
    int t = func_003698B0();
    D_0048C368 = b;
    D_0051EF98 = t;
    fmt = "gamedata\\frontend\\lang\\%s\\%s.tdx";
    sprintf(buf, fmt, func_002CCA30(), a);
    func_002C8840(buf);
}