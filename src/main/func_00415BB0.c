#pragma opt_rebuildconditionals off
#pragma cplusplus on

#include "types.h"

typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct M4 { float m[16]; } __attribute__((aligned(16))) M4;
typedef struct Slot { char pad0[0xF0]; float fF0; float fF4; float fF8; char padFC[0x104 - 0xFC]; char b104; char b105; char b106; char pad107[0x110 - 0x107]; } Slot;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;

struct LNode { LNode* prev; LNode* next; struct W* value; };
struct LIt { LNode* node; };
struct Draw {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); 
    virtual void Paint();
};
struct W { char pad0[0x14]; unsigned short flags; char pad16[0x44 - 0x16]; Draw* d; };
struct Self { char pad0[0x14]; unsigned short flags; char pad16[0x28 - 0x16]; char children[0xC]; };

extern "C" {
extern char D_005381F0[];
extern int D_00538318;
extern long long D_004BC1B0;
extern long long D_005392D8;
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern int D_005392D0;
void List_Begin(LIt* out, void* list);
void func_0028C0B0(LIt* out, LIt* in);
void func_0028C0A0(LIt* out, void* list);
void func_0028C090(LIt* out, LIt* in);
void func_0037A1E0(char* r);
}

#define SlotAt(i) ((Slot*)(D_005381F0 + 0x1F0 + (i) * 0x110))
static inline Mtx* MtxAt(int i) { return &((Render*)D_005381F0)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline void MM(void* d, void* a, void* b)
{
    __asm__ volatile("lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf11, 0x30(%2); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}

extern "C" void GuiFrontendCanvas_Draw(Self* self)
{
    if (self->flags & 4) {
        M4 m;
        LIt it;
        LIt last;
        LIt first;
        LIt beginTmp;
        LIt endTmp;
        int save;
        D_00538318 = 0;
        { long long t = D_004BC1B0; int i = D_00538C64; D_005392D8 = t; GQR(MtxAt(i + 1), MtxAt(i)); }
        D_00538C64++;
        UM(MtxAt(D_00538C64));
        D_00538C68 = 1;
        save = D_005392D0;
        {
            Slot* s = SlotAt(D_00538C60);
            s->fF0 = 0.0f;
            s->fF8 = 1000.0f;
            s->b106 = 1;
            s->b104 = 1;
        }
        m.m[0] = 1.0f; m.m[1] = 0.0f; m.m[2] = 0.0f; m.m[3] = 0.0f;
        m.m[4] = 0.0f; m.m[5] = 0.0f; m.m[6] = 1.0f; m.m[7] = 0.0f;
        m.m[8] = 0.0f; m.m[9] = 1.0f; m.m[10] = 0.0f; m.m[11] = 0.0f;
        m.m[12] = 0.0f; m.m[13] = 0.0f; m.m[14] = 1.0f; m.m[15] = 1.0f;
        { Mtx* c = MtxAt(D_00538C64); MM(c, c, &m); }
        D_00538C68 = 1;
        D_005392D0 = save | 4;
        List_Begin(&beginTmp, self->children);
        func_0028C0B0(&first, &beginTmp);
        for (it = first; func_0028C0A0(&endTmp, self->children), func_0028C090(&last, &endTmp), it.node != last.node; it.node = it.node->next) {
            if (it.node->value->flags & 2) {
                func_0037A1E0(D_005381F0);
                it.node->value->d->Paint();
            }
        }
        D_005392D0 = save;
        D_00538C68 = 1;
        D_00538C64--;
    }
}



