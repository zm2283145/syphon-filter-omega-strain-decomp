
#include "types.h"
/* Skel_Bind */
typedef struct { void* skel; int p50; int pad[2]; float a, b, c, d, e; } Pt2_MCInit;
typedef struct { char pad0[0x50]; int x50; char pad54[0xC]; char app[0x70]; char xD0[0x2B94]; void* p2C64; char pad2C68[0x1E8]; char ctx[0x10]; } Pt2_SkelActor;
extern char D_0053BB70[];
extern void Appearance_Setup(void*, int, int, int);
extern void* Skel_Find(void*, void*);
extern void ModelCtx_Init(void*, Pt2_MCInit*);
extern void Skel_ApplyScalePreset(void*, int);

void Skel_Bind(Pt2_SkelActor* a, int* desc) {
    Pt2_MCInit init;
    void* s;
    Appearance_Setup(a->app, desc[0], desc[1], desc[2]);
    a->p2C64 = a->ctx;
    s = Skel_Find(D_0053BB70, a->xD0);
    {
        int p = a->x50;
        float c = 0.2f;
        float o = 1.0f;
        float h = 0.5f;
        init.skel = s;
        init.p50 = p;
        init.a = o;
        init.b = h;
        init.c = c;
        init.d = c;
        init.e = c;
    }
    ModelCtx_Init(a->ctx, &init);
    Skel_ApplyScalePreset(a->app, -1);
}