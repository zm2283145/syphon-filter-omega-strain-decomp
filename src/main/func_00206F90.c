#include "types.h"
typedef struct { char d[0x8]; } B8;
typedef struct { int w[3]; } W12;
typedef struct { char d[0x20]; } B20;
typedef struct { char d[0x30]; } B30;
extern int BuildAnimationNode_ForRotatingANonTranslatingAnimation(void*, void*, void*, void*, void*, void*, void*, float, float, void*);
extern void cString_ctor_charP(void*, void*);
extern int opAdd_cStringR_cStringR(void*, void*, void*);
extern void* cSkaPlaybackGroupId_ctor_int(void*, void*);
extern void cSkaAnimationBlend_ctor(void*, void*, void*, void*);
extern void* cString16N_2_ctor_cStringR(void*, void*);
extern void cSkaAnimationSet_CreateAnimationBlend(void*, void*, void*);
extern void cSkaAnimationBlend_dtor(void*, int);
extern void String_Dtor_138350(void*, int);
/* Builds the "blend" selector node over the graph made by BuildAnimationNode_ForRotatingANonTranslatingAnimation and registers it. */
#pragma optimization_level 1
int BuildAnimationBlend_ForRotatingANonTranslatingAnimation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, float f0, float f1, void* p7)
{
    W12 vF0;
    W12 vE0;
    B8 vD8;
    W12 vC8;
    W12 vB8;
    W12 vA8;
    B30 v70;
    B20 v50;
    BuildAnimationNode_ForRotatingANonTranslatingAnimation(&v70, p1, p2, p3, p4, p5, p6, f0, f1, p7);
    cString_ctor_charP(&vF0, "blend");
    opAdd_cStringR_cStringR(&vE0, &vF0, p2);
    cSkaAnimationBlend_ctor(&vC8, &v70, p1, cSkaPlaybackGroupId_ctor_int(&vD8, p7));
    cSkaAnimationSet_CreateAnimationBlend(p1, cString16N_2_ctor_cStringR(&v50, &vE0), &vC8);
    cSkaAnimationBlend_dtor(&vC8, -1);
    String_Dtor_138350(&vE0, -1);
    String_Dtor_138350(&vF0, -1);
    cString_ctor_charP(&vB8, "blend");
    opAdd_cStringR_cStringR(&vA8, &vB8, p2);
    cString16N_2_ctor_cStringR(p0, &vA8);
    String_Dtor_138350(&vA8, -1);
    String_Dtor_138350(&vB8, -1);
    return 0;
}
#pragma optimization_level reset
