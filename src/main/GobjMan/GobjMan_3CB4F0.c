/*
 * main/GobjMan: 4 files, 003CB4F0-003CB5C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CB4F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int nGobjManager_DeleteNow(L4Tagged*);   /* first function of GobjMan.cc */

/* Calls nGobjManager_DeleteNow on the record at +0xC if its tag is 0xBEBAAFDE. */
void cDeleteCallback_Call(Unk3CB4F0* self) {
    unsigned int magic = 0xBEBAAFDE;
    L4Tagged* rec = self->unk0C;

    if (rec->tag == magic) {
        nGobjManager_DeleteNow(rec);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003CB4F0 */

/* merge_units: begin func_003CB530 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vt8_chain_dtor.h"
DEFINE_VT8_CHAIN_DTOR(cDeleteCallback_dtor, D_004DFE20, D_004D9DE0)
#pragma pop /* merge_units */
/* merge_units: end func_003CB530 */

/* merge_units: begin func_003CB590 */
#pragma push /* merge_units */
int cDeleteCallback_IsReferencing(Unk3CB590* self, int value) {
    return value == self->unk0C;
}

Map* std_tree_pair_cSystemPtr_value_compare_ctor(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CB590 */

/* merge_units: begin func_003CB5C0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } TB5C0;
extern void std_tree_pair_cSystemPtr_value_compare_destroy(TB5C0* t, void* n);
extern void operator_delete(void* p);
TB5C0* cAssocArray_cSystemPtr_int_dtor(TB5C0* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    std_tree_pair_cSystemPtr_value_compare_destroy(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CB5C0 */
