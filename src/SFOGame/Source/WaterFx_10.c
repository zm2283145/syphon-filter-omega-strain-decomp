/*
 * SFOGame/Source/WaterFx: 5 files, 002B4710-002B4AA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B4710 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma inline_depth(10)
#pragma opt_rebuildconditionals off
#include "types.h"

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& s) { V4* d = this; const V4* p = &s; __asm__ volatile("lq %0, 0x0(%0); sq %0, 0x0(%1)" : "+r"(p) : "r"(d) : "memory"); }
} __attribute__((aligned(16)));
typedef struct Splash {
    float t;
    char pad4[0xC];
    V4 pos;
    float r20;
    float r24;
    int tex;
} Splash;
struct V4c {
    float x, y, z, w;
    V4c(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct M44 { __int128 r[4]; };
extern "C" {
void SfxParticleEffect_eEffectName_cMatrixR(int id, M44* m);
}
static inline void UnitMtx(void* m) { int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void CP2(V4* d0, const V4* s) { V4* d = d0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=&r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void CP(V4* d, const V4* s) { __asm__ volatile("lq %0, 0x0(%0); sq %0, 0x0(%1)" : "+r"(s) : "r"(d) : "memory"); }

extern "C" void WaterFx_InitSplash(Splash* s, const V4* p, float size, float z)
{
    s->t = 5.0f;
    CP2(&s->pos, p);
    s->pos.z = z;
    float k = 2.5f * size;
    s->r20 = 0.15f * size;
    s->r24 = k - s->r20;
    M44 m;
    UnitMtx(&m);
    V4c v(s->pos.x, s->pos.y, s->pos.z - 0.25f * size, 1.0f);
    CP2((V4*)&m.r[3], (V4*)&v);
    if (size >= 2.0f) SfxParticleEffect_eEffectName_cMatrixR(0x11, &m);
    else SfxParticleEffect_eEffectName_cMatrixR(0x12, &m);
}
static inline void merge_flush_func_002B4710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B4710 */

/* merge_units: begin func_002B4810 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "object_list_erase_range.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "object_list_erase_file.h"
#pragma pop

#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cSplash_dtor)
static inline void merge_flush_func_002B4810(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B4810 */

/* merge_units: begin func_002B4860 */
#pragma push /* merge_units */
#pragma cplusplus on
#define D_0049AE80 D_004ABFD0
extern "C" {
char D_004ABFD0[] = "allocator.hh";
}

DEFINE_OBJECT_LIST_ERASE_RANGE(std_list_deleter_tNode_erase_listdeleter_listdeleter)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002B4860(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002B4860 */

/* merge_units: begin func_002B49A0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_OBJECT_LIST_ERASE_ONE_FILE(std_list_deleter_tNode_erase_listdeleter, D_004ABFD0)
static inline void merge_flush_func_002B49A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B49A0 */

/* merge_units: begin func_002B4AA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

extern "C" {
extern char D_004ABFC0[];
extern char D_004ABFD0[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
}
inline void* operator new(unsigned int, void* p) { return p; }
struct Q_B4AA0 {
    float x, y, z, w;
    Q_B4AA0(const Q_B4AA0& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
} __attribute__((aligned(16)));
struct Val_B4AA0 { Q_B4AA0 q0, q1, q2, q3, q4; float f50; float f54; int f58; int f5C; };
struct Node_B4AA0 { Node_B4AA0* prev; Node_B4AA0* next; Val_B4AA0 value; };
struct List_B4AA0 { int count; int alloc; };
struct Flag_B4AA0 {
    char c;
    Flag_B4AA0() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Flag_B4AA0() {}
};
struct E_B4AA0 {};
struct Ptr_B4AA0 : E_B4AA0 { Node_B4AA0* p; Ptr_B4AA0(const E_B4AA0& e, Node_B4AA0* n) : E_B4AA0(e), p(n) {} };
struct Holder_B4AA0;
extern "C" void details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_7(Holder_B4AA0* h);
struct Holder_B4AA0 {
    int* alloc;
    Node_B4AA0* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Holder_B4AA0()
    {
        if (node) {
            details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_7(this);
            Node_B4AA0* p = node;
            if (p) {
                AllocGuard guard;
                cMemMan_Deallocate(0, p, D_004ABFD0, 0x64);
            }
        }
    }
};

static inline Node_B4AA0* NewNode() { AllocGuard guard; return (Node_B4AA0*)cMemMan_Allocate(0, 0x70, D_004ABFC0, 0x5C); }
#pragma push
#pragma opt_propagation off
extern "C" int std_list_deleter_tNode_insert(Node_B4AA0** result, List_B4AA0* list, Node_B4AA0** pos, const Val_B4AA0* value)
{
    Node_B4AA0* n;
    int* alloc = &list->alloc;
    Flag_B4AA0 flag;
    E_B4AA0 f1 = *(E_B4AA0*)&flag;
    n = NewNode();
    {
    Holder_B4AA0 h;
    Ptr_B4AA0 t(f1, n);
    h.node = t.p;
    h.alloc = alloc;
    Val_B4AA0* v = &h.node->value;
    new (v) Val_B4AA0(*value);
    Node_B4AA0* m = h.node;
    Node_B4AA0* p;
    h.node = 0;
    p = *pos;
    p->prev->next = m;
    m->prev = p->prev;
    p->prev = m;
    m->next = p;
    list->count++;
    *result = m;
    }
    return 0;
}
#pragma pop
static inline void merge_flush_func_002B4AA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B4AA0 */
