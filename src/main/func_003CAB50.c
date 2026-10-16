#pragma cplusplus on
#pragma opt_common_subs off
#include "types.h"
typedef struct { char pad[8]; int* key; } Svc_ab50;
typedef struct SvcNode_ab50 { struct SvcNode_ab50* prev; struct SvcNode_ab50* next; Svc_ab50* svc; } SvcNode_ab50;
typedef struct { SvcNode_ab50* p; } SvcIt_ab50;
typedef struct { char pad[0x20]; int list; } SvcMgr_ab50;
struct Empty_ab50 { char c; };
struct Pred_ab50 {
    Empty_ab50 e;
    Svc_ab50** svc;
    Pred_ab50(const Empty_ab50& c, Svc_ab50** s) : e(c), svc(s) {}
};
extern "C" {
void func_0013B160(SvcIt_ab50* out, void* list);
SvcIt_ab50* func_003CAB40(SvcIt_ab50* dst, SvcIt_ab50* src);
void func_003CAB30(SvcIt_ab50* out, void* list);
SvcIt_ab50* func_003CAB20(SvcIt_ab50* dst, SvcIt_ab50* src);
void ActiveList_EraseMatching(void* v, Pred_ab50 p);
}
struct KeyPred_ab50 { int* k; KeyPred_ab50(int* kk) : k(kk) {} bool operator()(Svc_ab50* s) const { return *s->key == *k; } };
inline Svc_ab50* Erase_ab50(SvcMgr_ab50* self, Svc_ab50*& svc, SvcIt_ab50 it, SvcNode_ab50* last, Empty_ab50& e) {
    for (; it.p != last; it.p = it.p->next) {
        if (KeyPred_ab50(svc->key)(it.p->svc)) {
            ActiveList_EraseMatching(&self->list, Pred_ab50(e, &svc));
            return svc;
        }
    }
    return 0;
}
struct ItW_ab50 { SvcIt_ab50 i; };
extern "C" Svc_ab50* func_003CAB50(SvcMgr_ab50* self, Svc_ab50* svc) {
    ItW_ab50 uit;
    SvcIt_ab50 beg;
    SvcIt_ab50 end;
    Empty_ab50 e;
    SvcIt_ab50 e0;
    SvcIt_ab50 b0;
    SvcNode_ab50* last;
    func_0013B160(&e0, &self->list);
    func_003CAB40(&end, &e0);
    last = end.p;
    func_003CAB30(&b0, &self->list);
    func_003CAB20(&beg, &b0);
    for (uit = *(ItW_ab50*)&beg; uit.i.p != last; uit.i.p = uit.i.p->next) {
        if (KeyPred_ab50(svc->key)(uit.i.p->svc)) {
            ActiveList_EraseMatching(&self->list, Pred_ab50(e, &svc));
            return svc;
        }
    }
    return 0;
}
