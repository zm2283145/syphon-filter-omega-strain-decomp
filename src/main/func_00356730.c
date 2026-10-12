#pragma cplusplus on
#include "types.h"
struct H356730 { int v; };
struct P356730 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H356730 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
};
extern "C" void func_0036E5D0(void* m);
/* constructor: reset two members, ids, mask, handle (copied through a stack temp) */
#pragma push
#pragma opt_propagation off
extern "C" P356730* func_00356730(P356730* p)
{
    *(int*)((char*)p + 0x24) = -2;
    *(int*)((char*)p + 0x20) = 0;
    func_0036E5D0(p->memberA);
    func_0036E5D0(p->memberB);
    p->id = -1;
    p->mask = -1;
    p->w20 = 0;
    { H356730 h; H356730* hp = &h; h.v = -1; p->h24 = *hp; }
    p->w30 = 0;
    p->w34 = 0;
    p->w38 = 0;
    p->h184 = -1;
    p->w180 = 0;
    p->b186 = 0;
    return p;
}
#pragma pop
