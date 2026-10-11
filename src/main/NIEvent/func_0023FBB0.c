#pragma cplusplus on
#include "types.h"
#pragma inline_depth(10)
struct VBase_23FBB0 { int x; };

struct VObj_23FBB0 : VBase_23FBB0 { virtual void Destroy(int f); };
typedef struct {
    void* vt;
    char pad04[0x98];
    char m9C[0x10];
    char mAC[0x18];
    char mC4[0xAC];
    char m170[0x20];
    char m190[0x4];
    char m194[0x1C];
} Light_23FBB0;
typedef struct { char pad[0x140]; VObj_23FBB0* obj; } LightP_23FBB0;
extern "C" {
extern char D_004DBED0[];
extern char D_004DC190[];
extern void func_002402A0(void* p, int f);
extern void func_0023F3F0(void* p, int f);
extern void func_0023F460(void* p, int f);
extern void func_0023F4D0(void* p, int f);
extern void cGOBJ_dtor(void* p, int f);
extern void operator_delete(void* p);
}
static inline void L4_23FBB0(void* p) { if (p) func_002402A0(p, 0); }
static inline void L3_23FBB0(void* p) { if (p) L4_23FBB0(p); }
static inline void L2_23FBB0(void* p) { if (p) L3_23FBB0(p); }
static inline void L2b_23FBB0(void* p) { if (p) L2_23FBB0(p); }
static inline void L1_23FBB0(char* p) { if (p) L2_23FBB0(p + 4); }
static inline void Del_23FBB0(VObj_23FBB0* p) { if (p) p->Destroy(1); }
static inline void Base_23FBB0(Light_23FBB0* l)
{
    if (l) {
        l->vt = D_004DC190;
        func_0023F3F0(l->mC4, -1);
        func_0023F460(l->mAC, -1);
        func_0023F4D0(l->m9C, -1);
        cGOBJ_dtor(l, 0);
    }
}
extern "C" Light_23FBB0* cNIEventLight_dtor(Light_23FBB0* l, short flag)
{
    if (l) {
        VObj_23FBB0* o;
        l->vt = D_004DBED0;
        o = ((LightP_23FBB0*)l)->obj;
        if (o)
            Del_23FBB0(o);
        L1_23FBB0(l->m190);
        L1_23FBB0(l->m170);
        Base_23FBB0(l);
        if (flag > 0)
            operator_delete(l);
    }
    return l;
}