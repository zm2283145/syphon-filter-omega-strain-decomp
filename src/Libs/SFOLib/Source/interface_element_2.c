/*
 * Libs/SFOLib/Source/interface_element: 4 files, 003E87D0-003E8DE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E87D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * interface_element.cc
 */

#include "types.h"

/* Declared as char[] and accessed through casts: typed scalars let the
 * compiler sink the counter load below the flag store, which breaks the match. */
extern char D_00538C64[];   /* int counter */
extern char D_00538C68[];   /* char flag */

/* Decrement the global counter and set the companion flag. */
void cInterfaceElement_UnsetupView(void) {
    int count;

    count = *(int*)D_00538C64;
    *(char*)D_00538C68 = 1;
    *(int*)D_00538C64 = count - 1;
}
static inline void merge_flush_func_003E87D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E87D0 */

/* merge_units: begin func_003E8800 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { __int128 q[4]; } M4_E88;
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_E88;
typedef struct { char pad[0xA80]; M4_E88 m[1]; } MStack_E88;
typedef struct { char pad[0x62]; unsigned char b62; } Info_E88;
typedef struct { char pad[0x20]; V4_E88 v20; float m30[16]; Info_E88* p70; } Elem_E88;
extern "C" {
extern MStack_E88 g_Video;
#if 0 /* merge_units */
extern int D_00538C64;
#endif /* merge_units */
#define D_00538C64 (*(int*)&D_00538C64) /* merge_units */

#if 0 /* merge_units */
extern char D_00538C68;
#endif /* merge_units */
#define D_00538C68 (*(char*)&D_00538C68) /* merge_units */

}
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void GV(void* d, void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline void M4Mul(void* o, void* a, void* b) {
    asm {
        lqc2 vf4, 0x0(a)
        lqc2 vf5, 0x10(a)
        lqc2 vf6, 0x20(a)
        lqc2 vf7, 0x30(a)
        lqc2 vf8, 0x0(b)
        lqc2 vf9, 0x10(b)
        lqc2 vf10, 0x20(b)
        lqc2 vf11, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddaz.xyzw ACC, vf6, vf9z
        vmaddw.xyzw vf13, vf7, vf9w
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddaz.xyzw ACC, vf6, vf10z
        vmaddw.xyzw vf14, vf7, vf10w
        vmulax.xyzw ACC, vf4, vf11x
        vmadday.xyzw ACC, vf5, vf11y
        vmaddaz.xyzw ACC, vf6, vf11z
        vmaddw.xyzw vf15, vf7, vf11w
        sqc2 vf12, 0x0(o)
        sqc2 vf13, 0x10(o)
        sqc2 vf14, 0x20(o)
        sqc2 vf15, 0x30(o)
    }
}
static inline bool IsIdent(float* m) {
    return m[0] == 1.0f && m[1] == 0.0f && m[2] == 0.0f && m[3] == 0.0f &&
           m[4] == 0.0f && m[5] == 1.0f && m[6] == 0.0f && m[7] == 0.0f &&
           m[8] == 0.0f && m[9] == 0.0f && m[10] == 1.0f && m[11] == 0.0f &&
           m[12] == 0.0f && m[13] == 0.0f && m[14] == 0.0f && m[15] == 1.0f;
}

extern "C" void cInterfaceElement_SetupView(Elem_E88* e)
{
    M4_E88 a;
    M4_E88 r;
    M4_E88 t;
    {
        GQR(&g_Video.m[D_00538C64 + 1], &g_Video.m[D_00538C64]);
        void* x0 = &a; /* dead on purpose */
        D_00538C64++;
    }
    UM(&a);
    {
        void* x1 = &a.q[3]; /* dead on purpose */
        GV(&a.q[3], &e->v20);
    }
    if (e->p70->b62) {
        M4Mul(&t, &a, &g_Video.m[D_00538C64]);
        {
            M4_E88* pr = &r;
            void* x2 = &r; /* dead on purpose */
            GQR(&r, &t);
            GQR(&g_Video.m[D_00538C64], pr);
        }
        D_00538C68 = 1;
    } else {
        M4_E88* c = &g_Video.m[D_00538C64];
        M4Mul(c, c, &a);
        D_00538C68 = 1;
    }
    if (!IsIdent(e->m30)) {
        M4_E88* c = &g_Video.m[D_00538C64];
        M4Mul(c, c, e->m30);
        D_00538C68 = 1;
    }
}
#undef D_00538C64 /* merge_units */
#undef D_00538C68 /* merge_units */
static inline void merge_flush_func_003E8800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E8800 */

/* merge_units: begin func_003E8DC0 */
#pragma push /* merge_units */
#include "interface_element_types.h"

extern int cInterfaceModel_RenderInstance(int owner, IfElement* elem, int a2);

/* Forward (elem, a1) to cInterfaceModel_RenderInstance on the element's owner. */
int cInterfaceElement_Render(IfElement* elem, int a1) {
    return cInterfaceModel_RenderInstance(elem->owner, elem, a1);
}
static inline void merge_flush_func_003E8DC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E8DC0 */

/* merge_units: begin func_003E8DE0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Eq_8DE0 {};
struct Pred_8DE0 { Eq_8DE0 op; int* ref; Pred_8DE0(Eq_8DE0 o, int* r) : op(o), ref(r) {} };
extern "C" {
void std_list_imp_voidPtr_remove_if(void* list, Pred_8DE0 p);
char* GetTextSystem(unsigned char);
void cLList_cTextAreaPtr_PushBackActual(void*, int*);
}
struct O_8DE0 { char pad[0x18]; unsigned char on; char pad2[0x74 - 0x19]; int id; };
extern "C" void cInterfaceElement_Activate(O_8DE0* o, int on) {
    unsigned char cur = o->on;
    if ((unsigned char)on != cur) {
        if (cur) {
            if (o->id) {
                int id = o->id;
                Eq_8DE0 e;
                char* x = GetTextSystem(cur);
                std_list_imp_voidPtr_remove_if(x + 0x10, Pred_8DE0(e, &id));
            }
            o->on = 0;
        } else {
            if (o->id) {
                int id = o->id;
                cLList_cTextAreaPtr_PushBackActual(GetTextSystem(cur) + 0x10, &id);
            }
            o->on = 1;
        }
    }
}
static inline void merge_flush_func_003E8DE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E8DE0 */
