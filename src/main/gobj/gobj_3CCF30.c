/*
 * main/gobj: range (5 files, 003CCF30-003CD1C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CCF30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { void Mem_Free(int pool, void* p, char* file, int line); extern char D_004BD228[]; }
class C3CCF30 { public: virtual void Destroy(int flags); };
struct O3CCF30 { char pad[0x58]; C3CCF30* m; };
extern "C" void Node_ReleaseComponent58(O3CCF30* self)
{
    C3CCF30* m = self->m;
    if (m) {
        {
            AllocGuard g;
            m->Destroy(-1);
            Mem_Free(0, m, D_004BD228, 0x291);
        }
        self->m = 0;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003CCF30 */

/* merge_units: begin func_003CCFF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "node_world_q4.h"
extern "C" MtxQ4 g_IdentityMatrix;
extern "C" MtxQ4 GObj_GetWorldMatrix(OwnerQ4* o)
{
    NODE_WORLD_Q4_BODY(o, g_IdentityMatrix)
}
#pragma pop /* merge_units */
/* merge_units: end func_003CCFF0 */

/* merge_units: begin func_003CD090 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#include "v4_asm_copy.h"
struct N_3CD420 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char pad4[0x40 - 4];
    V4 pos;
    unsigned char dirty;
};
struct X_3CD420 { char pad[0x50]; N_3CD420* n; };
#pragma push
#pragma opt_common_subs off
extern "C" void func_003CD090(V4* out, X_3CD420* x) {
    N_3CD420* n = x->n;
    if (n) {
        if (n->dirty) n->Update();
        V4Copy(out, &n->pos);
        return;
    }
    V4 r;
    V4StoreVF0(&r);
    V4Copy(out, &r);
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003CD090 */

/* merge_units: begin func_003CD110 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" MtxQ4 func_003CD110(OwnerQ4* o, int* flag)
{
    *flag = 0;
    NODE_WORLD_Q4_BODY(o, g_IdentityMatrix)
}
#pragma pop /* merge_units */
/* merge_units: end func_003CD110 */

/* merge_units: begin func_003CD1C0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" MtxQ4 Node_GetComponentMatrix(OwnerQ4* o)
{
    NODE_WORLD_Q4_BODY(o, g_IdentityMatrix)
}
#pragma pop /* merge_units */
/* merge_units: end func_003CD1C0 */
