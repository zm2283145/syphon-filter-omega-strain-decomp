#include "types.h"

typedef struct Obj419 {
    char base[0x10];
    int value;
    char listA[0xC];
    char listB[0xC];
    int buffer[3];
} Obj419;

extern void std_tree_pair_cString_value_compare_ctor_valuecompareR_cAllocatorR_5(Obj419* self, int* a, int* b);
extern void ScalarCollection_Init(void* list);
extern int* TextManager_Get(void);
extern void String_Reserve(void* buffer, int size);

/* Constructor: base init, two empty lists, cleared buffer sized 0x20. */
Obj419* GuiManager_ctor(Obj419* self) {
    int second, first;
    std_tree_pair_cString_value_compare_ctor_valuecompareR_cAllocatorR_5(self, &first, &second);
    ScalarCollection_Init(self->listA);
    ScalarCollection_Init(self->listB);
    self->buffer[0] = 0;
    self->buffer[1] = 0;
    self->buffer[2] = 0;
    self->value = *TextManager_Get();
    String_Reserve(self->buffer, 0x20);
    return self;
}
