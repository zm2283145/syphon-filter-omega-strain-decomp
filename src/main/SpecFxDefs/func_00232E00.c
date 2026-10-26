#include "types.h"
#include "vu0_ops.h"

typedef struct ListNode232E00 {
    struct ListNode232E00* prev;
    struct ListNode232E00* next;
    struct LightRef232E00* value;
} ListNode232E00;

typedef struct LightRef232E00 {
    void* obj;
    char pad4[5];
    unsigned char enabled;
} LightRef232E00;

typedef struct {
    ListNode232E00* node;
} ListIt232E00;

typedef struct {
    char pad0[0x38];
    int key;
    char pad3C[0x74 - 0x3C];
    char list[8];
} Fx232E00;

typedef struct {
    Vec4 r[4];
} Mtx232E00;

extern void std_list_cElementPtr_begin_void(ListIt232E00* out, void* list);
extern void std_list_cElementPtr_end_void(ListIt232E00* out, void* list);
extern ListIt232E00* cLListIterator_cElementPtr_ctor_listR(ListIt232E00* dst, ListIt232E00* src);
extern void ParticleInst_Draw(void* obj, int key, Mtx232E00* m);

#pragma push
#pragma opt_rotateloops off
void SnowField_Draw(Fx232E00* self) {
    ListIt232E00 it;
    ListIt232E00 first;
    ListIt232E00 last;
    ListIt232E00 tmpBegin;
    ListIt232E00 tmpEnd;
    Mtx232E00 m;

    VU0_UnitMatrix(&m);
    std_list_cElementPtr_begin_void(&tmpBegin, self->list);
    cLListIterator_cElementPtr_ctor_listR(&first, &tmpBegin);
    it = first;
    while (std_list_cElementPtr_end_void(&tmpEnd, self->list), cLListIterator_cElementPtr_ctor_listR(&last, &tmpEnd), it.node != last.node) {
        if (it.node->value->obj != 0 && it.node->value->enabled) {
            ParticleInst_Draw(it.node->value->obj, self->key, &m);
        }
        it.node = it.node->next;
    }
}
#pragma pop

