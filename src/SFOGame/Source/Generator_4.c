/*
 * SFOGame/Source/Generator: 3 files, 0021D240-0021D350
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021D240 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { char pad[0x10]; void* val; } Node21D240;
typedef struct { void* vt; char p4[0x20]; int f24; signed char f28; char p29[3]; } Evt21D240;
typedef struct { int kind; int id; signed char b8; char p9[3]; int fC; } Arg21D240;
extern "C" {
extern void cMessage_ctor_cMessageNameR(Evt21D240* e, void* type);
extern void QueueMessage_cMessageR_cSystemP_int_int(Evt21D240* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt21D240* e, int f);
extern char D_0055C7A0[];
extern void std_tree_pair_int_value_compare_find_intR(Node21D240** out, void* map, int* key);
#if 0 /* merge_units */
extern void std_map_int_netSystemField_end(void* out, void* map);
#endif /* merge_units */
void std_map_int_netSystemField_end(Iter* out, Tree* t); /* merge_units */
#define std_map_int_netSystemField_end(a0, a1) (std_map_int_netSystemField_end((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cAssocArray_int_netSystemField_Iterator_ctor(Node21D240** out, void* in);
#endif /* merge_units */
Word* cAssocArray_int_netSystemField_Iterator_ctor(Word* dst, Word* src); /* merge_units */
#define cAssocArray_int_netSystemField_Iterator_ctor(a0, a1) ((void)cAssocArray_int_netSystemField_Iterator_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

extern char D_004DB5E0[];
extern char D_004A4A78[];
extern unsigned char D_005721D0;
}
static inline int Eq21D240(Node21D240* a, Node21D240* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int cGeneratorDataMessage_GeneratorDataMessageCallback(int a0, int a1, int a2, Arg21D240* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        int k[1];
        Node21D240* end[1];
        Node21D240* it[1];
        int tmp[1];
        Arg21D240* a = arg;
Node21D240* n;

        k[0] = a->id;
        std_tree_pair_int_value_compare_find_intR(it, D_0055C7A0, k);
        n = it[0];
        std_map_int_netSystemField_end(tmp, D_0055C7A0);
        cAssocArray_int_netSystemField_Iterator_ctor(end, tmp);
        if (Eq21D240(n, end[0]) ^ 1) {
            Evt21D240 e;
            cMessage_ctor_cMessageNameR(&e, D_004A4A78);
            e.vt = D_004DB5E0;
            e.f28 = a->b8;
            e.f24 = a->fC;
            QueueMessage_cMessageR_cSystemP_int_int(&e, n->val, 0, 0);
            e.vt = D_004DB5E0;
            cMessage_dtor(&e, 0);
        }
    }
    return 0x10;
}
#pragma pop
#undef std_map_int_netSystemField_end /* merge_units */
#undef cAssocArray_int_netSystemField_Iterator_ctor /* merge_units */
static inline void merge_flush_func_0021D240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D240 */

/* merge_units: begin func_0021D350 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Word* cAssocArray_int_netSystemField_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_int_netSystemField_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
static inline void merge_flush_func_0021D350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D350 */

/* merge_units: begin func_0021D370 */
#pragma push /* merge_units */
#include "message_pack.h"

#define BASE_BODY(e, b) MP_I(b, 0xC) = MP_I(MP_P(e, 0x24), 0xC); MP_S(b, 8) = 0;
DEFINE_MESSAGE_PACK_INLINE(GeneratorMessageBase_Pack, 0x14, D_004F56C8, BASE_BODY)

#define PACK_TAIL(e, b) MP_H(b, 0x10) = MP_U(e, 0x28); MP_S(b, 8) = 3;
DEFINE_MESSAGE_PACK_DERIVED(cGeneratorMessage_Pack, 0x14, GeneratorMessageBase_Pack, PACK_TAIL)
static inline void merge_flush_func_0021D370(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D370 */
