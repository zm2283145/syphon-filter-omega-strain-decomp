/* MotionSlider_RegisterNode: clone a motion node by kind (clip / timed clip / slider / blend),
 * register it under its name and drop it again if the name was already taken. */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct VC_003B49A0 { virtual int v0(...); };
struct Node_3B49A0 {
    void* vt;
    unsigned char kind;
    char pad5[0x20 - 5];
    int x20;
    char c24[0x34 - 0x24];
    unsigned char b34, b35;
    char pad36[0x50 - 0x36];
    int x50;
    float f54, f58;
    char pad5C[4];
    __int128 q60;
};
struct V4_3B49A0 {
    float x, y, z, w;
    V4_3B49A0() {}
    /* dead xx: retail computes the destination address twice */
    V4_3B49A0(const V4_3B49A0& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(&o), "r"(this) : "memory"); void* xx = this; }
} __attribute__((aligned(16)));

static inline V4_3B49A0 ZeroV_3B49A0() { V4_3B49A0 r; { V4_3B49A0* p = &r; __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(p) : "memory"); } return r; }
struct Owner_3B49A0 { char pad[0x54]; int n54; int n58; };
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
void ModelNames_Insert(int* out, Owner_3B49A0* self, void* name, Node_3B49A0* value);
Node_3B49A0* cSkaAnim_ctor_cSkaAnimR_eModifier(Node_3B49A0* self, Node_3B49A0* o, unsigned char mode);
Node_3B49A0* MotionNode_BaseCopy(Node_3B49A0* self, Node_3B49A0* src, V4_3B49A0* offset);
void MotionSlider_CopyChildren(void* d, void* s);
void cArray_cSkaSwitchItem_ctor_cArrayR(void* d, void* s);
extern int D_004BCD60;
extern char D_004BCD70[];
extern char D_004DFC10[];
extern char D_004DFBF0[];
extern char D_004DFBB0[];
void MotionSlider_RegisterNode(int* out, Owner_3B49A0* owner, void* name, Node_3B49A0* src);
}

static inline void* AllocL_3B49A0(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004BCD70, line);
}
static inline int Max_3B49A0(int a, int b) { return a < b ? b : a; }

extern "C" void MotionSlider_RegisterNode(int* out, Owner_3B49A0* owner, void* name, Node_3B49A0* src)
{
    int res;
    Node_3B49A0* n = 0;
    switch (src->kind) {
    case 0:
        {
            Node_3B49A0* p = (Node_3B49A0*)AllocL_3B49A0(0x50, 0x22C);
            if (p) p = cSkaAnim_ctor_cSkaAnimR_eModifier(p, src, 0);
            n = p;
        }
        break;
    case 1:
        n = (Node_3B49A0*)AllocL_3B49A0(0x70, 0x231);
        if (n) {
            cSkaAnim_ctor_cSkaAnimR_eModifier(n, src, 0);
            n->vt = D_004DFC10;
            n->x50 = src->x50;
            n->f54 = src->f54;
            n->f58 = src->f58;
            { __int128* d = &n->q60; const __int128* q = &src->q60; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(q) : "memory"); }
        }
        owner->n54 = Max_3B49A0(n->x50 + 1, owner->n54);
        break;
    case 2:
        n = (Node_3B49A0*)AllocL_3B49A0(0x40, 0x23B);
        if (n) {
            V4_3B49A0 c(ZeroV_3B49A0());
            MotionNode_BaseCopy(n, src, &c);
            n->vt = D_004DFBF0;
            n->x20 = src->x20;
            MotionSlider_CopyChildren(n->c24, src->c24);
            n->b34 = src->b34;
            n->b35 = src->b35;
        }
        owner->n54 = Max_3B49A0(n->x20 + 1, owner->n54);
        break;
    case 3:
        n = (Node_3B49A0*)AllocL_3B49A0(0x40, 0x245);
        if (n) {
            V4_3B49A0 c(ZeroV_3B49A0());
            MotionNode_BaseCopy(n, src, &c);
            n->vt = D_004DFBB0;
            n->x20 = src->x20;
            cArray_cSkaSwitchItem_ctor_cArrayR(n->c24, src->c24);
        }
        owner->n58 = Max_3B49A0(n->x20 + 1, owner->n58);
        break;
    }
    ModelNames_Insert(&res, owner, name, n);
    if (res == D_004BCD60 && n) {
        AllocGuard g;
        ((VC_003B49A0*)n)->v0(-1);
        Mem_Free(0, n, D_004BCD70, 0x258);
    }
    *out = res;
}
