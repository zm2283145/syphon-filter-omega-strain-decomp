#include "types.h"
typedef struct { char pad[0x30]; char* obj; char pad2[0x1A8 - 0x34]; float maxv; } S1765B0;
extern int D_004FFC2C;
extern char D_0049CAF8[];
extern char* Loc_LookupText(char* key);
extern void func_00242FA0(int a, char* b, char* c, int d, int e, int f, float g, float h);
void cPlayer_v26(S1765B0* p, int a1, int a2, int flag, float v)
{
    if (v > p->maxv) {
        p->maxv = v;
    }
    if (flag == 0 && v > 0.5f) {
        char* s;
        int d;
        d = D_004FFC2C;
        s = p->obj + 0xC;
        func_00242FA0(d, s, Loc_LookupText(D_0049CAF8), 0, 0, 0, 0.1f, 1.0f);
    }
}