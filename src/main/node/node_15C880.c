/*
 * main/node: range (2 files, 0015C880-0015C9A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vector_resize.h"
#pragma pop

/* merge_units: begin func_0015C880 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V_C88 { float x, y, z, w; } __attribute__((aligned(16)));
struct M_C88 {
    V_C88 r[4];
    M_C88() {}
    M_C88(const M_C88& o) { const M_C88* s = &o; M_C88* d = this; __int128 qa, qb; asm volatile { lq qa, 0x0(s); lq qb, 0x10(s); sq qa, 0x0(d); lq qa, 0x20(s); sq qb, 0x10(d); lq qb, 0x30(s); sq qa, 0x20(d); sq qb, 0x30(d) } }
};
struct Rel_C88 { int a, b, c; unsigned char d; };
struct Node_C88 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void SetMatrix(M_C88* m, int f);
    char pad4[0x29];
    unsigned char x2D;
    char pad2E[0x36];
    int x64;
    Rel_C88 x68;
    int x78;
    int x7C;
};
extern "C" {
extern void* const cNode_vtable[];
extern char D_004EA770[];
extern M_C88 g_IdentityMatrix;
void cGOBJ_ctor(Node_C88* self, int* id, int n, char* name);
void std_vector_tNodeLink_ctor(Rel_C88* r);
Node_C88* cNode_ctor_int_float_float_float_etc(Node_C88* self, int a, int b, int c, float x, float y, float z);
}
typedef void (*SetM_C88)(Node_C88*, M_C88*, int);
Node_C88* cNode_ctor_int_float_float_float_etc(Node_C88* self, int a, int b, int c, float x, float y, float z)
{
    int id = -1;
    cGOBJ_ctor(self, &id, 10, D_004EA770);
    *(void**)self = (void*)cNode_vtable;
    { Rel_C88* r = &self->x68; std_vector_tNodeLink_ctor(r); r->d = 1; }
    {
        M_C88 m = g_IdentityMatrix;
        self->x64 = a;
        m.r[3].x = x;
        m.r[3].y = y;
        m.r[3].z = z;
        m.r[3].w = 1.0f;
        self->SetMatrix(&m, 0);
    }
    self->x78 = c;
    self->x7C = b;
    self->x2D = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015C880(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015C880 */

/* merge_units: begin func_0015C9A0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_RESIZE_ELEMENT(Elem8, 8)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(std_vector_imp_tNodeLink_resize, Elem8, std_vector_imp_tNodeLink_insert, std_vector_imp_tNodeLink_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_0015C9A0 */
