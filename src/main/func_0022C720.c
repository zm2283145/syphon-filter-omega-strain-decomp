#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"

struct Tgt { char p[0xC]; int id; };
static inline int IdOf(Tgt* a) { int none; return *(a ? &a->id : (none = -1, &none)); }
struct HndT {
    Tgt* p; int id;
    HndT(Tgt* a) { id = -1; p = a; id = IdOf(a); }
};
struct Eq {};
struct Pred { Eq op; HndT* value; Pred(const Eq& o, const HndT& v) : op(o) { value = (HndT*)&v; } };
struct RList { int count; void* head; };

struct Pair { char p[8]; int a; int b; };
struct PNode { PNode* prev; PNode* next; Pair v; };
struct PIt { PNode* n; };
struct PList { int size; PNode* sprev; PNode* first; };
struct NEq {};
struct NPred { NEq op; Pair* value; NPred(const NEq& o, Pair& v) : op(o) { value = &v; } };

struct Cell { int a; int b; char p8[5]; unsigned char flag; char pE[2];
    void Clear() { b = 0; a = 0; flag = 0; } };

struct TVis {
    char p0[0x20];
    Cell* rows[30];
    int slots[30];
    PList pairs;
    RList recent;
};

extern "C" {
int TargetVis_GetSlotIndex(TVis* s, Tgt* t);
void TargetVis_LeaveRecent(RList* l, Pred p);
PIt* std_list_deleter_LosReqElem_generic_iterator_ctor(PIt* it, PNode* n);
PNode* std_list_deleter_LosReqElem_tail(PList* l);
PNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_5(void* n);
void std_list_imp_LosReqElem_remove_if(PList* l, NPred p);
}

static inline PNode* PBegin(PList* l) { return details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_5(&l->sprev)->next; }
static inline PNode* PEnd(PList* l) { PIt t; std_list_deleter_LosReqElem_generic_iterator_ctor(&t, std_list_deleter_LosReqElem_tail(l)); return t.n; }

extern "C" int TargetVis_Unregister(TVis* self, Tgt* t)
{
    int slot = TargetVis_GetSlotIndex(self, t);
    if (slot >= 0) {
    {
        int n = 0x1D - slot;
        Cell* c = self->rows[slot];
        for (int j = 0; j < n; j++) { c->Clear(); c++; }
    }
    for (int i = 0; i < slot; i++) self->rows[i][slot - i - 1].Clear();
    self->slots[slot] = 0;
    { Eq eq; HndT h(t); TargetVis_LeaveRecent(&self->recent, Pred(eq, h)); }
    for (PNode* it = PBegin(&self->pairs); it != PEnd(&self->pairs); it = it->next) {
        if (slot == it->v.a || slot == it->v.b) {
            { NEq eq; std_list_imp_LosReqElem_remove_if(&self->pairs, NPred(eq, it->v)); }
            break;
        }
    }
    return 1;
    }
    return 0;
}

