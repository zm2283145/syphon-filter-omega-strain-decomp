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
extern unsigned char D_005721C8;
extern PtrVec D_004EA370;
extern Tree D_004EA190;

extern void NetEvent_Send(Actor_A890* actor, int id, int size, unsigned char value, int a, int b, int c);
extern void NpcThinkList_Add(Actor_A890* actor);
extern void NpcThinkList_RemoveActor(Actor_A890* actor);
extern void ActiveList_EraseMatching(PtrVec* v, Pred_A890 p);
extern void NpcAi_AddToDeadList(PtrVec* v, cNPC_A890** self);
extern void func_0013B180(Iter* out, Tree* t);
extern Word* func_0014AB70(Word* dst, Word* src);
extern void func_0014AB80(Iter* out, Tree* t);
extern Word* func_0014ABC0(Word* dst, Word* src);
extern Word* func_0014ABD0(Word* dst, Word* src);
extern void func_0014ABE0(Iter* out, PtrVec* v);
extern Word* func_0014ABF0(Word* dst, Word* src);
extern int func_0014AC00(Iter* a, Iter* b);
extern void func_0014AC20(Iter* out, PtrVec* v);
extern Iter* func_0014AC30(Iter* it);
extern cNPC_A890** func_0014AC50(Iter* it);
extern Iter* func_0014AC60(Iter* dst, Iter* src);
extern void func_0014AC70(Iter* out, PtrVec* v);
extern Iter* func_0014AC80(Iter* self);
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
    if (D_005721C8) {
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
        func_0014AC80(&it);
        func_0014AC70(&b, &D_004EA370);
        func_0014AC60(&it, &b);
        func_0014AC20(&end, &D_004EA370);
        while (func_0014AC00(&it, &end)) {
            if (*func_0014AC50(&it) == self) {
                break;
            }
            func_0014AC30(&it);
            func_0014AC20(&end, &D_004EA370);
        }
        func_0014ABF0(&w4, (Word*)&it);
        x = w4.value;
        func_0014ABE0(&end2, &D_004EA370);
        func_0014ABD0(&w3, (Word*)&end2);
        if (x != w3.value) {
            NpcThinkList_Add(self->actor);
            ActiveList_EraseMatching(&D_004EA370, Pred_A890(e, &self));
        }
    } else {
        func_0013B180(&b2, &D_004EA190);
        func_0014ABC0(&w1, (Word*)&b2);
        n = (Node_A890*)w1.value;
        func_0014AB80(&end3, &D_004EA190);
        func_0014AB70(&w2, (Word*)&end3);
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
                NpcAi_AddToDeadList(&D_004EA370, &self);
                return;
            }
            n = n->next;
            func_0014AB80(&end3, &D_004EA190);
            func_0014AB70(&w2, (Word*)&end3);
        }
    }
}
