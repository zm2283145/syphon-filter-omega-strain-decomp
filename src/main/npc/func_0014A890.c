#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

typedef struct HObj_A890 {
    char pad[0xC];
    int id;
} HObj_A890;

typedef struct Handle_A890 {
    HObj_A890* obj;
    int id;
} Handle_A890;

typedef struct Node_A890 {
    int unk0;
    struct Node_A890* next;
    Handle_A890* h;
} Node_A890;

class Actor_A890 {
public:
    VPAD32(p) VPAD32(q)
    virtual unsigned char GetState();
    char pad[0x3468 - 4];
    char unk3468;
};

class cNPC_A890 {
public:
    VPAD32(p) VPAD32(q) VPAD16(r) VPAD4(s) VPAD2(t)
    virtual void SetFlag(bool v);
    char pad[0x2C];
    Actor_A890* actor;
    char pad34[0x141 - 0x34];
    unsigned char b0 : 2;
    unsigned char inactive : 1;
    unsigned char b3 : 5;
};

/* Stateless comparator tag; its (uninitialised) byte is copied into the predicate. */
struct Empty_A890 { char c; };
struct Pred_A890 {
    Empty_A890 e;
    cNPC_A890** self;
    Pred_A890(const Empty_A890& c, cNPC_A890** s) : e(c), self(s) {}
};

extern "C" {
extern unsigned char g_IsMultiplayer;
extern PtrVec g_NpcDeadList;
extern Tree g_NpcThinkList;

extern void NetEvent_Send(Actor_A890* actor, int id, int size, unsigned char value, int a, int b, int c);
extern void NpcThinkList_Add(Actor_A890* actor);
extern void NpcThinkList_RemoveActor(Actor_A890* actor);
extern void ActiveList_EraseMatching(PtrVec* v, Pred_A890 p);
extern void NpcAi_AddToDeadList(PtrVec* v, cNPC_A890** self);
extern void List_Begin(Iter* out, Tree* t);
extern Word* cLListIterator_cActiveListItemPtr_ctor(Word* dst, Word* src);
extern void std_list_cActiveListItemPtr_end_void(Iter* out, Tree* t);
extern Word* std_list_cActiveListItemPtr_generic_iterator_ctor(Word* dst, Word* src);
extern Word* cLListIterator_cNPCPtr_ctor_listR(Word* dst, Word* src);
extern void std_list_cNPCPtr_end(Iter* out, PtrVec* v);
extern Word* cLListIterator_cNPCPtr_ctor_cLListIteratorR(Word* dst, Word* src);
extern int opNe_cLListIteratorR_cLListIteratorR(Iter* a, Iter* b);
extern void cLList_cNPCPtr_End(Iter* out, PtrVec* v);
extern Iter* cLListIterator_cNPCPtr_opInc(Iter* it);
extern cNPC_A890** cLListIterator_cNPCPtr_opMul(Iter* it);
extern Iter* cLListIterator_cNPCPtr_opAssign(Iter* dst, Iter* src);
extern void cLList_cNPCPtr_Begin(Iter* out, PtrVec* v);
extern Iter* cLListIterator_cNPCPtr_ctor_void(Iter* self);
}

/* Sets the NPC active flag (networked or via vtable), then adds or removes it from the AI think/dead lists. */
extern "C" void cNPC_v73(cNPC_A890* self, char on, int send)
{
    Word w4;
    Word w3;
    Word w2;
    Word w1;
    Empty_A890 e;
    Iter it;
    Node_A890* n;
    Iter b;
    Iter end;
    Iter end2;
    Iter b2;
    Iter end3;
    unsigned char ok;
    int x;
    unsigned char state;

    self->actor->unk3468 = on;
    if (g_IsMultiplayer) {
        self->inactive = !on;
        if (send) {
            NetEvent_Send(self->actor, 0x21, 4, on, 0, 0, 0);
        }
    } else {
        self->SetFlag(!on);
    }
    state = self->actor->GetState();
    ok = state == 2 || state == 3;
    if (!ok) {
        return;
    }
    if (on) {
        cLListIterator_cNPCPtr_ctor_void(&it);
        cLList_cNPCPtr_Begin(&b, &g_NpcDeadList);
        cLListIterator_cNPCPtr_opAssign(&it, &b);
        cLList_cNPCPtr_End(&end, &g_NpcDeadList);
        while (opNe_cLListIteratorR_cLListIteratorR(&it, &end)) {
            if (*cLListIterator_cNPCPtr_opMul(&it) == self) {
                break;
            }
            cLListIterator_cNPCPtr_opInc(&it);
            cLList_cNPCPtr_End(&end, &g_NpcDeadList);
        }
        cLListIterator_cNPCPtr_ctor_cLListIteratorR(&w4, (Word*)&it);
        x = w4.value;
        std_list_cNPCPtr_end(&end2, &g_NpcDeadList);
        cLListIterator_cNPCPtr_ctor_listR(&w3, (Word*)&end2);
        if (x != w3.value) {
            NpcThinkList_Add(self->actor);
            ActiveList_EraseMatching(&g_NpcDeadList, Pred_A890(e, &self));
        }
    } else {
        List_Begin(&b2, &g_NpcThinkList);
        std_list_cActiveListItemPtr_generic_iterator_ctor(&w1, (Word*)&b2);
        n = (Node_A890*)w1.value;
        std_list_cActiveListItemPtr_end_void(&end3, &g_NpcThinkList);
        cLListIterator_cActiveListItemPtr_ctor(&w2, (Word*)&end3);
        while (n != (Node_A890*)w2.value) {
            Actor_A890* actor = self->actor;
            Handle_A890* h = n->h;
            unsigned char valid;
            HObj_A890* o;
            unsigned char isnull;
            o = h->obj;
            isnull = !o;
            valid = 1;
            if (!isnull && o->id != h->id) {
                valid = 0;
            }
            if ((Actor_A890*)(valid ? o : 0) == actor) {
                NpcThinkList_RemoveActor(actor);
                NpcAi_AddToDeadList(&g_NpcDeadList, &self);
                return;
            }
            n = n->next;
            std_list_cActiveListItemPtr_end_void(&end3, &g_NpcThinkList);
            cLListIterator_cActiveListItemPtr_ctor(&w2, (Word*)&end3);
        }
    }
}
