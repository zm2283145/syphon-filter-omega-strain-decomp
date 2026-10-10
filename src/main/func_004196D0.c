#include "types.h"

typedef struct Obj419 {
    char base[0x10];
    int value;
    char listA[0xC];
    char listB[0xC];
    int buffer[3];
} Obj419;

extern void func_00419E30(Obj419* self, int* a, int* b);
extern void ScalarCollection_Init(void* list);
extern int* func_003D1020(void);
extern void String_Reserve(void* buffer, int size);

/* Constructor: base init, two empty lists, cleared buffer sized 0x20. */
Obj419* func_004196D0(Obj419* self) {
    int second, first;
    func_00419E30(self, &first, &second);
    ScalarCollection_Init(self->listA);
    ScalarCollection_Init(self->listB);
    self->buffer[0] = 0;
    self->buffer[1] = 0;
    self->buffer[2] = 0;
    self->value = *func_003D1020();
    String_Reserve(self->buffer, 0x20);
    return self;
}
