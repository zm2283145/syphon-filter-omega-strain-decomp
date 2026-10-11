#include "types.h"
typedef struct { char pad[0x14]; unsigned short a14; } W342F00;
typedef struct { char pad[0x78]; W342F00* a78; char pad7C[0xDC]; unsigned char a158; } S342F00;
typedef struct { char pad[0x2F]; unsigned char a2F; } G342F00;
typedef struct { char pad[0x68]; unsigned int a68; } M342F00;
typedef struct { char pad[0xB68]; unsigned char aB68; char padB69[9]; unsigned char aB72; } A342F00;
extern G342F00* D_004FFC04;
extern char D_004FFB50[];
extern void func_0041EFA0(S342F00* o);
extern void func_0041E0F0(void* self, void* w, int a, int b, int c);
extern M342F00* func_004147A0(void);
extern A342F00* Agent_GetSelected(void* list, int idx);
void func_00342F00(S342F00* o)
{
    M342F00* m;
    A342F00* ag;
    D_004FFC04->a2F = 1;
    func_0041EFA0(o);
    if (o->a78) func_0041E0F0(o, o->a78, 10, 0, 0);
    if (o->a78) o->a78->a14 &= ~2;
    m = func_004147A0();
    m->a68 |= 0xC;
    ag = Agent_GetSelected(D_004FFB50, -1);
    ag->aB68 = 0;
    ag->aB72 = 1;
    o->a158 = 0;
}