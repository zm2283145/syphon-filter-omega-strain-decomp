#pragma cplusplus on
#include "types.h"
struct H1C9F80 { int v; };
struct P1C9F80 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H1C9F80 h24;
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
extern "C" char* func_001C9F80(char* self)
{
    P1C9F80* p;
    *(int*)(self + 0x44) = -2;
    *(int*)(self + 0x40) = 0;
    p = (P1C9F80*)(self + 0x20);
    func_0036E5D0(p->memberA);
    func_0036E5D0(p->memberB);
    p->id = -1;
    p->mask = -1;
    p->w20 = 0;
    { H1C9F80 h; H1C9F80* hp = &h; h.v = -1; p->h24 = *hp; }
    p->w30 = 0;
    p->w34 = 0;
    p->w38 = 0;
    p->h184 = -1;
    p->w180 = 0;
    p->b186 = 0;
    return self;
}
#pragma pop
