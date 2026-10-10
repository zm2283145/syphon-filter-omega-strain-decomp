#include "types.h"
typedef struct { void* vtable; char pad[0x20]; int value; } F6Msg;
typedef struct { int id; int target; } F6Link;
typedef struct { unsigned char active; char pad[0x17]; float weight; char pad2[0x78]; unsigned char notify; char pad3[3]; F6Link link; } F6Slot;
typedef struct { char pad[0x18]; char arr[1]; } F6Host;
extern void BlockArray_Append(void* arr, void* item);
extern F6Slot* Array_GetLast(void* arr);
extern char D_00542B68[];
extern char D_004DFBD0[];
extern void Event_Construct(F6Msg* m, void* type);
extern void Event_Send(F6Msg* m, int target, int immediate);
extern void cMessage_dtor(F6Msg* m, int flags);
static inline int F6LinkValid(F6Link* l) { return l->target != 0 && ~l->id != 0; }
void func_003AB970(float w, F6Host* h, void* req, int stop)
{
    F6Slot* s;
    BlockArray_Append(h->arr, req);
    s = Array_GetLast(h->arr);
    s->weight = w;
    s->active = 1;
    if (stop) {
        F6Slot* e = Array_GetLast(h->arr);
        if (e->notify) {
            F6Link* l = &e->link;
            if (F6LinkValid(l)) {
                int v = l->id;
                F6Msg msg;
                Event_Construct(&msg, D_00542B68);
                msg.vtable = D_004DFBD0;
                msg.value = v;
                Event_Send(&msg, l->target, 1);
                msg.vtable = D_004DFBD0;
                cMessage_dtor(&msg, 0);
            }
        }
        e->active = 0;
    }
}