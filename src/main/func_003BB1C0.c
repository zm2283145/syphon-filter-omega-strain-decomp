#include "types.h"
typedef struct F1RT3BB { int color; int depth; int colorFmt; int depthFmt; unsigned char hasDepth; } F1RT3BB;
extern void* D_00539248;
extern char D_004BD010[];
extern void String_Copy(char* dst, char* src);
extern void func_00128F58(char* dst, char* src);
extern int func_00380DB0(void* mgr, char* name, int w, int h, int fmt);
void func_003BB1C0(F1RT3BB* rt, char* name, int w, int h, int fmt, int depth)
{
    char cname[0x40];
    char dname[0x40];
    String_Copy(cname, name);
    String_Copy(dname, name);
    func_00128F58(dname, D_004BD010);
    rt->colorFmt = fmt == 16 ? 2 : fmt == 24;
    rt->depthFmt = depth == 16 ? 0x3A : depth == 24 ? 0x31 : 0x30;
    rt->hasDepth = depth > 0;
    rt->color = -1;
    rt->depth = -1;
    rt->color = func_00380DB0(D_00539248, cname, w, h, fmt);
    if (depth) rt->depth = func_00380DB0(D_00539248, dname, w, h, depth);
}