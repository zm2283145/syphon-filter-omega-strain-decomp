#include "types.h"
#include "v4_asm_copy.h"
typedef struct { __int128 q; } V_F160;
typedef struct { int p; } It_F160;
typedef struct { char pad[0x50]; unsigned char a50; char pad51[0x3F]; V_F160 v90; char padA0[4]; int lA4[3]; } S_F160;
extern void cArray_cXformNodePtr_Begin(It_F160* it, void* c);
extern void cArray_cXformNodePtr_End(It_F160* it, void* c);
extern int cArray_cXformNodePtr_ConstIterator_opNe(It_F160* a, It_F160* b);
extern void** cArray_cXformNodePtr_ConstIterator_opMul(It_F160* it);
extern void cXformNode_SetNeedsUpdate(void* p);
extern void cArray_cXformNodePtr_ConstIterator_opInc(It_F160* it);
#pragma opt_rotateloops off
void cXformNode_SetTranslation_ParentRelative(S_F160* o, V_F160* src)
{
    It_F160 b;
    It_F160 e;
    V4Copy(&o->v90, src);
    if (!o->a50) {
        It_F160* pe;
        o->a50 = 1;
        cArray_cXformNodePtr_Begin(&b, o->lA4);
        cArray_cXformNodePtr_End(&e, o->lA4);
        pe = &e;
        while (cArray_cXformNodePtr_ConstIterator_opNe(&b, pe)) {
            cXformNode_SetNeedsUpdate(*cArray_cXformNodePtr_ConstIterator_opMul(&b));
            cArray_cXformNodePtr_ConstIterator_opInc(&b);
        }
    }
}
#pragma opt_rotateloops reset
#pragma peephole reset