#include "types.h"
typedef struct { signed char b0; signed char b1; char pad2[2]; int x4; int x8; int xC; int x10; char x14[0x1C]; unsigned char x30; } Src_B000;
typedef struct { signed char b0; char pad1[3]; char x4[0x10]; char x14[0x1C]; unsigned char x30; unsigned char x31; unsigned char x32; char pad33[0xD]; char x40[0x60]; char xA0[0x10]; char xB0[0x10]; char xC0[0x10]; char xD0[0x10]; int xE0; int xE4; char padE8[8]; } Col_B000;
typedef struct { int n; int pad[3]; Col_B000 items[9]; } List_B000;
void cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_cMasks_ctor(void* d, int* a, int* b, int* c, int* e);
void HumanColPreset_Copy(void* d, void* s);
void cCollisionEdge_ctor(void*);
void HumanColMask_Ctor(void*, int);
void Ptr_Identity(void*);
void cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_opAssign(Col_B000* d, Col_B000* s);
static inline void Tail_B000(Col_B000* cp, unsigned char v)
{
    cp->x30 = v;
    cp->x31 = 0;
    cp->x32 = 0;
    cCollisionEdge_ctor(cp->x40);
    HumanColMask_Ctor(cp->xA0, 0);
    Ptr_Identity(cp->xB0);
    Ptr_Identity(cp->xC0);
    Ptr_Identity(cp->xD0);
    cp->xE0 = 0xFF7FFFFF;
    cp->xE4 = 0;
}
#pragma push
#pragma opt_propagation off
List_B000* HumanCol_AppendPreset(List_B000* l, Src_B000* s)
{
    Col_B000 c;
Col_B000* cp = &c;
unsigned char v = s->x30;
    c.b0 = s->b1;
    cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_cMasks_ctor(c.x4, &s->x4, &s->x8, &s->xC, &s->x10);
    HumanColPreset_Copy(c.x14, s->x14);
    Tail_B000(cp, v);
    if ((unsigned int)l->n < 9) {
        cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_opAssign(&l->items[l->n], &c);
        l->n++;
    }
    return l;
}
#pragma pop
