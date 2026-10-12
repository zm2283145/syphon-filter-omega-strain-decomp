#include "types.h"
#include "vu0_ops.h"
#include "vc_copy.h"

typedef struct ListNode235A00 {
    struct ListNode235A00* prev;
    struct ListNode235A00* next;
    struct LightRef235A00* value;
} ListNode235A00;

typedef struct LightRef235A00 {
    void* obj;
    int pad4[3];
    Vec4 pos;
} LightRef235A00;

typedef struct {
    ListNode235A00* node;
} ListIt235A00;

typedef struct {
    char pad0[0x38];
    int key;
    char pad3C[0x74 - 0x3C];
    char list[8];
} Fx235A00;

typedef struct {
    Vec4 r[4];
} Mtx235A00;

extern void func_002359F0(ListIt235A00* out, void* list);
extern void func_002359D0(ListIt235A00* out, void* list);
extern ListIt235A00* func_002359E0(ListIt235A00* dst, ListIt235A00* src);
extern void func_003A1AD0(void* obj, int key, Mtx235A00* m);

#pragma push
#pragma opt_rotateloops off
#pragma opt_loop_invariants off
void func_00235A00(Fx235A00* self) {
    ListIt235A00 it;
    ListIt235A00 first;
    ListIt235A00 last;
    ListIt235A00 tmpBegin;
    ListIt235A00 tmpEnd;
    Mtx235A00 m;

    VU0_UnitMatrix(&m);
    func_002359F0(&tmpBegin, self->list);
    func_002359E0(&first, &tmpBegin);
    it = first;
    while (func_002359D0(&tmpEnd, self->list), func_002359E0(&last, &tmpEnd), it.node != last.node) {
        LightRef235A00* v = it.node->value;
        if (v->obj != 0) {
            /* unfolded quad copy idiom */
            VCopyF(&m.r[3], &v->pos);
            func_003A1AD0(v->obj, self->key, &m);
        }
        it.node = it.node->next;
    }
}
#pragma pop




