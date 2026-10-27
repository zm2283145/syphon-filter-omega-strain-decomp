#include "types.h"
typedef struct { char pad[0x48]; } Tmp;
typedef struct { char pad[4]; char name[0x50]; int count1; int count2; } Def;
typedef struct { char pad[0x24]; Def* def; char p2[0x50]; char list1[0x10]; char list2[0x18]; char sub[1]; } S;
typedef struct { int a, b; } Pair;
extern void cSkaAnimAnchorList_Reset(void*, void*);
extern void cSplinedMotion_Scalar0To1_ctor(Tmp*);
extern void cSkaSliderValue_opAssign(Tmp*, float);
extern void std_vector_imp_cSkaSliderValue_resize(void*, int, Tmp*);
extern void cSplinedMotion_Scalar0To1_dtor(Tmp*, int);
extern void std_vector_imp_cSkaSwitchValue_resize(void*, int, Pair*);
/* Binds a definition: copies its name and fills both lists with default entries. */
void Model_Attach_3634D0(S* s, Def* def)
{
    Tmp tmp;
    Pair p;
    s->def = def;
    cSkaAnimAnchorList_Reset(s->sub, def->name);
    cSplinedMotion_Scalar0To1_ctor(&tmp);
    cSkaSliderValue_opAssign(&tmp, 0.0f);
    std_vector_imp_cSkaSliderValue_resize(s->list1, def->count1, &tmp);
    cSplinedMotion_Scalar0To1_dtor(&tmp, -1);
    p.a = 0;
    p.b = 0;
    std_vector_imp_cSkaSwitchValue_resize(s->list2, def->count2, &p);
}
