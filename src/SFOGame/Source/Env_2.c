/*
 * SFOGame/Source/Env: 5 files, 00174FF0-00175330
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00174FF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_5(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
static inline void merge_flush_func_00174FF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00174FF0 */

/* merge_units: begin func_00175030 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tstr_types.h"

struct KV { unsigned int cap; unsigned int count; int* data; };
extern "C" {
extern char D_0049CAA0[];
extern char D_0049CAD8[];
extern char D_0049CAC8[];
#if 0 /* merge_units */
void std_swap_vectordeleterR_vectordeleterR_5(KV* a, KV* b);
#endif /* merge_units */
#define std_swap_vectordeleterR_vectordeleterR_5(a0, a1) (std_swap_vectordeleterR_vectordeleterR_5((PtrVec *)(a0), (PtrVec *)(a1))) /* merge_units */

}

extern "C" void std_vector_imp_cObjectId_reserve(KV* v, unsigned int n)
{
    if (v->cap < n) {
        if (n > 0x1800000) {
            Libc_Fprintf(D_00489738->stream, D_0049CAA0);
            Libc_Abort();
        }
        KV tmp;
        tmp.cap = 0;
        tmp.count = 0;
        tmp.data = 0;
        tmp.data = (int*)TStr_Alloc(n * 4, D_0049CAD8, 0x5C);
        tmp.cap = n;
        int* d;
        int* s;
        int* e;
        s = v->data;
        e = s + v->count;
        d = tmp.data;
        while (s < e) {
            if (d)
                *d = *s;
            s++;
            d++;
            tmp.count++;
        }
        std_swap_vectordeleterR_vectordeleterR_5(&tmp, v);
        tmp.count = 0;
        int* fp = tmp.data;
        if (fp) {
            if (fp)
                TStr_Free((char*)fp, D_0049CAC8, 0x64);
        }
    }
}
#undef std_swap_vectordeleterR_vectordeleterR_5 /* merge_units */
static inline void merge_flush_func_00175030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00175030 */

/* merge_units: begin func_00175230 */
#pragma push /* merge_units */
/* clear(): count = 0. */
void std_vector_deleter_cObjectId_clear(PtrVec* v) {
    v->count = 0;
}
static inline void merge_flush_func_00175230(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00175230 */

/* merge_units: begin player_175240 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "clear_buffer_dtor.h"

/* Clear and free a vector, optionally delete. */
DEFINE_CLEAR_BUFFER_DTOR(std_vector_deleter_cObjectId_dtor, D_0049CAC8)
static inline void merge_flush_player_175240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end player_175240 */

/* merge_units: begin func_00175330 */
#pragma push /* merge_units */
int Player_IsPlayer(void) {
    return 1;
}
static inline void merge_flush_func_00175330(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00175330 */
