/*
 * SFOGame/Source/npc: 2 files, 0014F1C0-0014F240
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0014F1C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

void std_vector_int_end_void(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* cArray_int_ConstIterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_int_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

/* End pointer of a vector of 8-byte elements. */
int* std_vector_imp_tNodeLink_end_void(PtrVec* v) {
    return v->data + (v->count << 1);
}

void std_vector_tNodeLink_pointer2iterator_tNodeLinkPR(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* std_vector_imp_tNodeLink_begin_void(PtrVec* v) {
    return v->data;
}
static inline void merge_flush_func_0014F1C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014F1C0 */

/* merge_units: begin func_0014F240 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0xC]; int id; } Who_F240;
typedef struct { Who_F240* who; int id; float val; int z; unsigned char b; } Ev_F240;
typedef struct { char pad[0x160]; int limit; char pad164[2]; unsigned char flag; char pad167[0x1B8 - 0x167]; char* list; } S_F240;
void std_list_deleter_cLookAtListItem_insert(void* out, void* list, void* pos, Ev_F240* e);
void cNPC_AddLookAt(S_F240* self, Who_F240* who, int t, float val)
{
    if (t >= self->limit) {
        int m1;
        char out[4];
        void* pos;
        Ev_F240 e;
        int* p;
        char* list;
        *(&e.id) = -2;
        e.who = who;
        if (who) p = &who->id; else { m1 = -1; p = &m1; }
        e.id = *p;
        e.val = val;
        e.b = 0;
        e.z = 0;
        list = self->list;
        if (list) {
            pos = list + 4;
            std_list_deleter_cLookAtListItem_insert(out, list, &pos, &e);
        }
        self->flag = 1;
    }
}
static inline void merge_flush_func_0014F240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014F240 */
