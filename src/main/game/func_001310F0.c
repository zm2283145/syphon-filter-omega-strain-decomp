#include "types.h"
#pragma cplusplus on
#include "vslot_pad.h"
class AlObj_r {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Activate(int on);
    virtual void Deactivate(int on);
    char pad4[8];
    int id;
    char pad10[0x1C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    bool IsActive() { return b2D && b2C && !b2E; }
};
typedef struct AlNode_r { struct AlNode_r* next; struct AlNode_r* prev; AlObj_r* obj; } AlNode_r;
typedef struct { char pad[0xC4]; int list; int padC8; AlNode_r* head; } AlList_r;
struct AlEq_r { char c; };
struct AlPred_r { AlEq_r op; AlObj_r** ref; AlPred_r(const AlEq_r& e, AlObj_r** r) : op(e), ref(r) {} };
extern "C" {
extern AlObj_r* D_00583878;
extern int D_0058387C;
extern void ActiveList_EraseMatching(int* list, AlPred_r pred);
void ActiveList_RemoveObject(AlList_r* l, AlObj_r* o);
}
static inline void AlSetCurrent_r(AlObj_r* o)
{
    int def[1];
    int* p;
    D_00583878 = o;
    if (o) {
        p = &o->id;
    } else {
        def[0] = -1;
        p = def;
    }
    D_0058387C = *p;
}
void ActiveList_RemoveObject(AlList_r* l, AlObj_r* o)
{
    if (o) {
        AlEq_r eq;
        AlObj_r* next;
        ActiveList_EraseMatching(&l->list, AlPred_r(eq, &o));
        if (o->IsActive())
            o->Deactivate(1);
        next = l->head->obj;
        if (next && !next->IsActive()) {
            next->Activate(1);
            AlSetCurrent_r(next);
        } else {
            AlSetCurrent_r(0);
        }
    }
}

