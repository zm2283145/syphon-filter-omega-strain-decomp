#pragma cplusplus on
#pragma opt_propagation off
#include "types.h"
#define V5(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4();
struct Ctl {
    V5(a) V5(b) V5(c) V5(d)
    virtual int IsA();
    virtual int IsB();
};
struct Tgt {
    int pad0[3]; int id; int x10; unsigned char x14; char p15[0x43]; Ctl* ctl;
};
struct Hnd { Tgt* p; int id; };
struct LNode { LNode* prev; LNode* next; Hnd h; };
struct Ev {
    char* vt; char p4[0x20]; signed char f24; char p25[0xB];
};
struct Gen {
    char pad[0xC]; int key; char p10[0x80]; int list90; LNode head;
};
extern "C" {
LNode* func_0021EDE0(LNode* n);
LNode* func_0021E000(void* l);
LNode** func_0021DFE0(LNode** it, LNode* n);
void func_0043B190(void* ctx);
int func_0043AB20(void* ctx, void* key);
int func_00439C70(void* ctx, void* key);
void func_003FB4B0(int id, int v);
int NetGame_InitLocalSlot(int*, int);
int Event_Construct(void*, char*);
int Event_Send(void*, void*, int);
int cMessage_dtor(void*, int);
extern char D_00582730[];
extern char D_004D9300[];
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C8;
}
static inline Tgt* HGet(Hnd* h) {
    unsigned char valid = 1;
    Tgt* p = h->p;
    int n = (p != 0) ^ 1;
    if (!n && p->id != h->id)
        valid = 0;
    return valid ? p : 0;
}
extern "C" void func_0021EAA0(Gen* self)
{
    char ctx[4];
    int* key;
    int id;
    func_0043B190(ctx);
    if (!func_0043AB20(ctx, &self->key))
        return;
    {
        key = &self->key;
        int a = D_005721A8;
        if (D_005721C8) {
            if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, a);
            id = D_00494178;
        } else id = 0;
    }
    int cur = func_00439C70(ctx, key);
    if (cur == id) {
        Tgt* t;
        LNode* end;
        LNode* n;
        n = func_0021EDE0(&self->head)->next;
        func_0021DFE0(&end, func_0021E000(&self->list90));
        while (n != end) {
            Hnd* h = &n->h;
            t = HGet(h);
            if (t) {
                bool ok = 0;
                if (t->ctl && t->ctl->IsB())
                    ok = 1;
                if (ok) {
                    Ev ev;
                    Event_Construct(&ev, D_00582730);
                    ev.vt = D_004D9300;
                    ev.f24 = 1;
                    Event_Send(&ev, t, 1);
                    ev.vt = D_004D9300;
                    cMessage_dtor(&ev, 0);
                    t->x14 = 1;
                    {
                        int tid = t->id;
                        func_003FB4B0(tid, func_00439C70(ctx, &self->key));
                    }
                }
            }
            n = n->next;
            func_0021DFE0(&end, func_0021E000(&self->list90));
        }
    } else {
        Tgt* t;
        LNode* end;
        LNode* n;
        n = func_0021EDE0(&self->head)->next;
        func_0021DFE0(&end, func_0021E000(&self->list90));
        while (n != end) {
            Hnd* h = &n->h;
            t = HGet(h);
            if (t) {
                bool ok = 0;
                if (t->ctl && t->ctl->IsA())
                    ok = 1;
                if (ok) {
                    Ev ev;
                    Event_Construct(&ev, D_00582730);
                    ev.vt = D_004D9300;
                    ev.f24 = 2;
                    Event_Send(&ev, t, 1);
                    ev.vt = D_004D9300;
                    cMessage_dtor(&ev, 0);
                    t->x14 = 0;
                    {
                        int tid = t->id;
                        func_003FB4B0(tid, func_00439C70(ctx, &self->key));
                    }
                }
            }
            n = n->next;
            func_0021DFE0(&end, func_0021E000(&self->list90));
        }
    }
}




