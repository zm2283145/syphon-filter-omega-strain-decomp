/*
 * SFOGame/Source/NetMsgThrottle: 4 files, 00471C20-00471F30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00471C20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)

inline void* operator new(unsigned int, void* p) { return p; }
struct V4_471C20 { float x, y, z, w; V4_471C20(const V4_471C20& o) { float a = o.x, b = o.y, c = o.z, d = o.w; x = a; y = b; z = c; w = d; } };
struct V3_471C20 { float x, y, z; V3_471C20(const V3_471C20& o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
struct E_471C20 { V4_471C20 a; V4_471C20 b; V3_471C20 c; };
struct Vec_471C20 { unsigned int cap; unsigned int count; E_471C20* data; };
typedef struct { char pad[0xC]; void* stream; } Err_471C20;
extern "C" {
extern Err_471C20* D_00489738;
extern char D_004C33E0[];
extern char D_004C33F0[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void Libc_Abort(void);
void Libc_Fprintf(void* s, char* msg);
void std_swap_vectordeleterR_vectordeleterR_54(Vec_471C20* a, Vec_471C20* b);
}

static inline E_471C20* Alloc_471C20(unsigned int n) { AllocGuard g; return (E_471C20*)cMemMan_Allocate(0, n * sizeof(E_471C20), D_004C33F0, 0x5C); }
#pragma push
#pragma peephole off
#pragma opt_propagation off
extern "C" void std_vector_imp_tRecord_reserve(Vec_471C20* v0, unsigned int n0)
{
    Vec_471C20* v = v0;
    unsigned int n = n0;
    if (v0->cap < n) {
        if (n > 0x22E8BA) {
            Libc_Fprintf(D_00489738->stream, "vector::reserve length error\n");
            Libc_Abort();
        }
        {
            E_471C20* d; E_471C20* s; E_471C20* e; Vec_471C20 tmp;
            tmp.cap = 0;
            tmp.count = 0;
            tmp.data = 0;
            tmp.data = Alloc_471C20(n);
            tmp.cap = n;
            s = v->data;
            e = s + v->count;
            d = tmp.data;
            for (; s < e; s++, d++) {
                new (d) E_471C20(*s);
                tmp.count++;
            }
            std_swap_vectordeleterR_vectordeleterR_54(&tmp, v);
            tmp.count = 0;
            {
                E_471C20* p = tmp.data;
                if (p) { if (p) { AllocGuard g; cMemMan_Deallocate(0, p, D_004C33E0, 0x64); } }
            }
        }
    }
}
#pragma pop
static inline void merge_flush_func_00471C20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00471C20 */

/* merge_units: begin NetMsgThrottle_471E90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after inventory.cc (ends 0x004719B0),
 * before NetMsgThrottle.cc (starts 0x00472050).
 */


Word* func_00471E90(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00471EA0(Iter* out, Tree* t) {
    out->p = &t->header;
}
static inline void merge_flush_NetMsgThrottle_471E90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end NetMsgThrottle_471E90 */

/* merge_units: begin func_00471EB0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_sMsgInfoPtr_dtor)
static inline void merge_flush_func_00471EB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00471EB0 */

/* merge_units: begin func_00471F30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cLList_sMsgInfoPtr_dtor, func_00135C90)
static inline void merge_flush_func_00471F30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00471F30 */
