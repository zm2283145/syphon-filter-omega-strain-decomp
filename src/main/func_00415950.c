#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct LNode_415950 { LNode_415950* prev; LNode_415950* next; struct W_415950* value; };
struct LIt_415950 { LNode_415950* node; };
struct List_415950 { int size; LNode_415950* a; LNode_415950* head; };
struct W_415950 {
    VPAD16(p) VPAD4(q) VPAD2(r) VPAD1(s)
    virtual void Detach(int h, int x);
    virtual void Release(int h);
    char pad4[0x10];
    unsigned short flags;
    char pad16[0x12];
    char children[0xC];
    char pad34[0x14];
    int h48;
    int h4C;
    unsigned char b50;
    char pad51[3];
    List_415950 queue;
    unsigned char busy;
    char pad61[3];
    float dt;
};
struct U_415950 {
    VPAD8(p) VPAD4(q)
    virtual void Update(float dt);
};
extern "C" {
void List_Begin(LIt_415950* out, void* list);
void func_0028C0B0(LIt_415950* out, LIt_415950* in);
void func_0028C0A0(LIt_415950* out, void* list);
void func_0028C090(LIt_415950* out, LIt_415950* in);
void func_002CCE50(List_415950* list, W_415950** v);
void List_Erase(LIt_415950* out, List_415950* list, LIt_415950* pos);
W_415950** func_00415B20(List_415950* list);
}

extern "C" void func_00415950(W_415950* o, float dt)
{
    if (o->flags & 4) {
        LIt_415950 last;
        LIt_415950 it;
        LIt_415950 res1;
        LIt_415950 pos1;
        LIt_415950 res2;
        LIt_415950 pos2;
        LIt_415950 beginTmp;
        LIt_415950 endTmp;
        LNode_415950* n;
        o->dt = dt;
        dt *= 30.0f;
        if (o->b50) {
            o->Release(o->h48);
            o->h48 = 0;
            if (o->h4C) {
                o->Detach(o->h4C, 0);
                o->h4C = 0;
            }
            o->b50 = 0;
        }
        List_Begin(&beginTmp, o->children);
        func_0028C0B0(&it, &beginTmp);
        n = it.node;
        func_0028C0A0(&endTmp, o->children);
        func_0028C090(&last, &endTmp);
        if (n != last.node) {
            do {
                func_002CCE50(&o->queue, &n->value);
                n = n->next;
                func_0028C0A0(&endTmp, o->children);
                func_0028C090(&last, &endTmp);
            } while (n != last.node);
        }
        o->busy = 1;
        while (o->queue.size) {
            if ((*func_00415B20(&o->queue))->flags & 4) {
                W_415950* w = o->queue.head->value;
                ((U_415950*)w)->Update(dt);
                if (o->queue.size && w == o->queue.head->value) {
                    pos1.node = o->queue.head;
                    List_Erase(&res1, &o->queue, &pos1);
                }
            } else {
                pos2.node = o->queue.head;
                List_Erase(&res2, &o->queue, &pos2);
            }
        }
        o->busy = 0;
    }
}

