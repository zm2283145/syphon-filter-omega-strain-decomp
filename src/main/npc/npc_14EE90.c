/*
 * main/npc: range (2 files, 0014EE90-0014EF80)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0014EE90 */
#pragma push /* merge_units */
typedef struct { int pad[3]; int key; } Tgt_EE90;
typedef struct { Tgt_EE90* node; int key; } H_EE90;
typedef struct { H_EE90 h; int pad8; int prio; } Dat_EE90;
typedef struct N_EE90 { struct N_EE90* prev; struct N_EE90* next; Dat_EE90 d; } N_EE90;
typedef struct { N_EE90* prev; N_EE90* next; } L_EE90;
typedef struct { char pad[0x1B8]; void* list; } NPC_EE90;
extern L_EE90* std_list_deleter_cLookAtListItem_tail(void* list);
extern void std_list_deleter_cLookAtListItem_generic_iterator_ctor_nodeP(N_EE90** it, N_EE90* n);
extern void std_list_deleter_cLookAtListItem_generic_iterator_ctor_nodebaseP(N_EE90** it, L_EE90* l);
static inline Tgt_EE90* H_Get(H_EE90* o)
{
    Tgt_EE90* n = o->node;
    unsigned char ok = 1;
    int z = (n != 0) ^ 1;
    if (!z && n->key != o->key) ok = 0;
    return ok ? n : 0;
}
Tgt_EE90* cNPC_GetMostDenseLookAtGobj(NPC_EE90* self)
{
    N_EE90* it;
    N_EE90* end;
    Tgt_EE90* best = 0;
    int bestPrio = 0;
    N_EE90* n;
    std_list_deleter_cLookAtListItem_generic_iterator_ctor_nodeP(&it, std_list_deleter_cLookAtListItem_tail(self->list)->next);
    n = it;
    std_list_deleter_cLookAtListItem_generic_iterator_ctor_nodebaseP(&end, std_list_deleter_cLookAtListItem_tail(self->list));
    while (n != end) {
        
        Dat_EE90* d = &n->d;
        if (bestPrio < d->prio) {
            bestPrio = d->prio;
            best = H_Get(&d->h);
        }
        n = n->next;
        std_list_deleter_cLookAtListItem_generic_iterator_ctor_nodebaseP(&end, std_list_deleter_cLookAtListItem_tail(self->list));
    }
    return best;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014EE90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014EE90 */

/* merge_units: begin func_0014EF80 */
#pragma push /* merge_units */
typedef struct It8 { int* p; } It8;
typedef struct It4 { int* p; } It4;
typedef struct Raw4 { int* p; } Raw4;
typedef struct PNode { char pad[0x7C]; int kind; } PNode;
typedef struct Self14 { char pad[0x160]; int f160; } Self14;
typedef struct Grp { char pad[0x8]; char* arr; } Grp;
extern char* cAIPathData_GetNode(int id);
extern int* std_vector_imp_tNodeLink_begin_void(void* c);
extern int* std_vector_imp_tNodeLink_end_void(void* c);
extern void std_vector_tNodeLink_pointer2iterator_tNodeLinkPR(It8* out, void* c, int** raw);
extern void std_vector_int_begin(Raw4* out, void* c);
extern void std_vector_int_end_void(Raw4* out, void* c);
extern void cArray_int_ConstIterator_ctor(It4* out, Raw4* raw);
extern void cNPC_AddLookAt(Self14* self, PNode* n, int x, float f);
extern Grp* D_004FFBE8;
static inline unsigned char ne8(It8 a, It8 b) { return !(a.p == b.p); }
static inline unsigned char ne4(It4 a, It4 b) { return !(a.p == b.p); }
void cNPC_AddLinkedNodesToLookAt(Self14* self, int kind, int path, int skip, float f) {
    It8 it1;
    It4 it2;
    It8 t84;
    It4 t80;
    It4 end2;
    It8 b78;
    It8 end1;
    int* raw70;
    int* raw6C;
    Raw4 raw68;
    Raw4 raw64;
    if (path >= 0) {
        void* c = cAIPathData_GetNode(path) + 0x68;
        raw70 = std_vector_imp_tNodeLink_begin_void(c);
        std_vector_tNodeLink_pointer2iterator_tNodeLinkPR(&b78, c, &raw70);
        t84.p = b78.p;
        it1 = t84;
        while ((raw6C = std_vector_imp_tNodeLink_end_void(c), std_vector_tNodeLink_pointer2iterator_tNodeLinkPR(&end1, c, &raw6C), !(it1.p == end1.p))) {
            int id = *it1.p;
            if (id != skip) {
                PNode* n = (PNode*)cAIPathData_GetNode(id);
                if (kind < 0 || kind == n->kind) cNPC_AddLookAt(self, n, self->f160, f);
            }
            it1.p += 2;
        }
    } else if (kind >= 0) {
        void* c = D_004FFBE8->arr + kind * 16;
        std_vector_int_begin(&raw68, c);
        cArray_int_ConstIterator_ctor(&t80, &raw68);
        it2 = t80;
        while ((std_vector_int_end_void(&raw64, c), cArray_int_ConstIterator_ctor(&end2, &raw64), !(it2.p == end2.p))) {
            cNPC_AddLookAt(self, (PNode*)cAIPathData_GetNode(*it2.p), self->f160, f);
            it2.p += 1;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014EF80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014EF80 */
