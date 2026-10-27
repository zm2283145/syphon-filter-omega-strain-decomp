/*
 * Libs/SFOLib/Source/shadows: 3 files, 003D35D0-003D3700
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D35D0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char unused; } Alloc;
typedef struct { Alloc alloc; int value; } TaggedInt;
extern void std_list_imp_int_remove_if(void* self, TaggedInt arg);
/* Forwards value, paired with an empty allocator tag, to std_list_imp_int_remove_if. */
void cLList_int_Remove(void* self, int value)
{
    Alloc alloc;
    TaggedInt arg;
    arg.alloc = alloc;
    arg.value = value;
    std_list_imp_int_remove_if(self, arg);
}
static inline void merge_flush_func_003D35D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D35D0 */

/* merge_units: begin func_003D3600 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

/* Returns the address 8 bytes into the object pointed to by the second word. */
char* cLList_int_Back(char** self) {
    return self[1] + 8;
}

void XLib_SetAspectRatio(Unk3D3670* self, float value) {
    self->unkF94 = value;
}

/* Fills an entry: position, a tag byte, and marks it in use. */
void cXViewport_SetWindow(L4Entry110* entry, Vec4* pos, int tag) {
    entry->unk00.x = pos->x;
    entry->unk00.y = pos->y;
    entry->unk00.z = pos->z;
    entry->unk00.w = pos->w;
    entry->unk105 = tag;
    entry->unk106 = 1;
}

Vec4* tRECT_ctor(Vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    return v;
}

/* Returns the current entry. */
L4Entry110* XLib_EditViewport(Unk3D3670* self) {
    return &self->entries[self->cur];
}

/* Advances to the next entry and marks it in use. */
void XLib_PushViewport(int a0) {
    int tmp0;
    int tmp1;

    /* entries[++cur].unk106 = 1; the struct form swaps an addu operand order */
    tmp0 = *(int*)((char*)a0 + 2672);
    *(int*)((char*)a0 + 2672) = (tmp0 + 1);
    tmp1 = *(int*)((char*)a0 + 2672);
    *(char*)((char*)(a0 + (tmp1 * 272)) + 758) = 1;
}

/* Assumed to act on the same object as its neighbours. */
void XLib_SetDepthTest(Unk3D3670* self, int unused, int value) {
    self->unkF4 = value & 255;
}

unsigned char cUserFrameEnv_HasZBuffer(Unk3D36D0* self) {
    return self->unk10;
}

int cUserFrameEnv_GetZPSM(Unk3D36D0* self) {
    return self->unk0C;
}

int cUserFrameEnv_GetPSM(Unk3D36D0* self) {
    return self->unk08;
}
static inline void merge_flush_func_003D3600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D3600 */

/* merge_units: begin func_003D3700 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
static inline void Q3700(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ Q3700(this, &o); }
} __attribute__((aligned(16)));
struct M {
    V r[4];
    void Apply(V* v) const { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(this) : "memory"); }
    V Applied(V v) const { V* p = &v; Apply(p); return *p; }
};
struct Renderer { char pad0[0x180]; float f180; char pad184[0xC]; float f190; char pad194[0xF00 - 0x194]; M view; };
extern "C" void XLib_UpdateCompMat(Renderer* r);
static inline float MaxF(float a, float b) { return a > b ? a : b; }
static inline float MinF(float a, float b) { return a < b ? a : b; }
extern "C" float XLib_GetFogVal(Renderer* r, const V* p)
{
    XLib_UpdateCompMat(r);
    const M* m = &r->view;
    V v = m->Applied(*p);
    float f = r->f180 + r->f190 / v.w;
    return MinF(MaxF(f, 0.0f), 255.0f);
}
static inline void merge_flush_func_003D3700(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D3700 */
