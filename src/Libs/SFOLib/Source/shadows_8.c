/*
 * Libs/SFOLib/Source/shadows: 2 files, 003D57A0-003D5970
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D57A0 */
#pragma push /* merge_units */
#pragma push

#include "types.h"

typedef struct { int head; int value; } ListHead;
extern void std_list_deleter_int_erase_listdeleter_listdeleter(int* out, void* list, int* value, ListHead** head);
extern void std_list_deleter_int_insert(int* out, void* list, ListHead** pos, int* value);

typedef struct { int a, b, c; char pad[0x130 - 0xC]; } SMElemA;
typedef struct { int a; char pad[0x60]; int b; char pad2[0x80 - 0x68]; } SMElemB;

typedef struct ShadowMgr {
    int f0, f4, f8, fC;
    SMElemA ea[4];
    SMElemB eb[0x200];
    int c0, c4, c8, pad;
    int d0, d4, d8, dC;
    char pad2[0x11744 - 0x104F0];
    float scale;
    char pad3[0x1175C - 0x11748];
    int list;
    ListHead head;
} ShadowMgr;

void cShadowMan_Init(ShadowMgr* self)
{
    int i;
    int result;
    int value;
    ListHead* headp;
    int j;
    ListHead* head;

    self->f0 = 6;
    self->f4 = 4;
    self->f8 = 0x20;
    self->fC = 0x50;
    for (j = 0; j < 4; j++) {
        self->ea[j].a = 0;
        self->ea[j].b = 0;
        self->ea[j].c = 0;
    }
    for (j = 0; j < 0x200; j++) {
        self->eb[j].a = 0;
        self->eb[j].b = 0;
    }
    self->c0 = 0;
    self->c4 = 0;
    self->c8 = 0;
    self->d0 = 0;
    self->d4 = 0;
    self->d8 = 0;
    self->dC = 0;
    head = &self->head;
    headp = head;
    value = head->value;
    std_list_deleter_int_erase_listdeleter_listdeleter(&result, &self->list, &value, &headp);
    i = 0;
    goto tramp;
body:
    {
        int r2;
        ListHead* pos = head;
        std_list_deleter_int_insert(&r2, &self->list, &pos, &i);
    }
    i++;
test:
    if (i < 5) goto body;
    self->scale = 0.33f;
    return;
tramp:
    asm { nop }
    goto test;
}
#pragma pop
static inline void merge_flush_func_003D57A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D57A0 */

/* merge_units: begin func_003D5970 */
#pragma push /* merge_units */
extern void std_list_int_dtor(void* self, short del);
extern void cShadowMan_tShadow_dtor(void);
extern void cShadowMan_tReceiver_dtor(void);
extern void cShadowMan_tCaster_dtor(void);
extern void __destroy_array(void* arr, void* dtor, int size, int n);
extern void operator_delete(void* p);
void* cShadowMan_dtor(void* self, short del)
{
    if (self) {
        void* m = (char*)self + 0x1175C;
        if (m)
            std_list_int_dtor(m, 0);
        __destroy_array((char*)self + 0x10540, (void*)cShadowMan_tShadow_dtor, 0xC0, 0x18);
        __destroy_array((char*)self + 0x4D0, (void*)cShadowMan_tReceiver_dtor, 0x80, 0x200);
        __destroy_array((char*)self + 0x10, (void*)cShadowMan_tCaster_dtor, 0x130, 4);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_003D5970(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D5970 */
