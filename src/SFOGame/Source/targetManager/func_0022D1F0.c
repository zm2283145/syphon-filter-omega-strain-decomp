#pragma cplusplus on
#include "types.h"
typedef struct TargetSlot { int unk0; int unk4; int unk8; unsigned char unkC; unsigned char unkD; } TargetSlot;

struct Name_D1F0 { int id; bool operator==(const Name_D1F0& o) const { return id == o.id; } };
struct Msg_D1F0 {
    char p0[0x30];
    unsigned char hit;
    char p31[0xB4 - 0x31];
    int* pB4;
    char pB8[0xC0 - 0xB8];
    int reqId;
};
struct ReqElem_D1F0 { TargetSlot* elem; int id; int p8; int pC; };
struct Node_D1F0 { Node_D1F0* prev; Node_D1F0* next; ReqElem_D1F0 v; };
struct List_D1F0 { int size; Node_D1F0* sentPrev; Node_D1F0* first; };
struct It_D1F0 { Node_D1F0* p; };
struct EqualTo_D1F0 { };

struct Binder_D1F0 {
    EqualTo_D1F0 op;
    const ReqElem_D1F0* value;
    Binder_D1F0(const EqualTo_D1F0& x, const ReqElem_D1F0& y) : op(x), value(&y) {}
};
static inline Binder_D1F0 Bind2nd_D1F0(const EqualTo_D1F0& op, const ReqElem_D1F0& x) { return Binder_D1F0(op, x); }
static inline void SetMin_D1F0(int& a, const int& b) { if (b < a) a = b; }
struct TM_D1F0 { char p0[0x110]; List_D1F0 pending; };

extern "C" {
Name_D1F0* cMessage_Name(Msg_D1F0* m);
extern Name_D1F0 g_LosResultMsgClass;
extern int g_FrameCounter;
Node_D1F0* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_5(void* self);
Node_D1F0* std_list_deleter_LosReqElem_tail(List_D1F0* self);
It_D1F0* std_list_deleter_LosReqElem_generic_iterator_ctor(It_D1F0* self, Node_D1F0* value);
void std_list_imp_LosReqElem_remove_if(List_D1F0* self, Binder_D1F0 pred);
}

static inline Node_D1F0* End_D1F0(List_D1F0* l) { It_D1F0 e; std_list_deleter_LosReqElem_generic_iterator_ctor(&e, std_list_deleter_LosReqElem_tail(l)); return e.p; }
extern "C" unsigned char cTargetManager_HandleMessage(TM_D1F0* self, Msg_D1F0* m) {
    if (*cMessage_Name(m) == g_LosResultMsgClass) {
        Msg_D1F0* msg = m;
        int id = msg->reqId;
        Node_D1F0* n;
        for (n = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_5(&self->pending.sentPrev)->next; n != End_D1F0(&self->pending); n = n->next) {
            if (id == n->v.id) {
                int frame = g_FrameCounter;
                n->v.elem->unk0 = frame + 40;
                n->v.elem->unkC = msg->hit == 0;
                n->v.elem->unkD = 0;
                {
                    TargetSlot* s = n->v.elem;
                    s->unk8 = s->unkC ? 0 : *msg->pB4;
                }
                {
                    TargetSlot* s = n->v.elem;
                    if (s->unkC) {
                        s->unk4 = s->unk0;
                    } else {
                        SetMin_D1F0(n->v.elem->unk4, frame);
                    }
                }
                EqualTo_D1F0 eq;
                std_list_imp_LosReqElem_remove_if(&self->pending, Bind2nd_D1F0(eq, n->v));
                break;
            }
        }
    } else {
        return 0;
    }
    return 1;
}
