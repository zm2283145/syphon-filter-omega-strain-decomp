#include "types.h"
typedef struct Deq_3B87A0 { unsigned int count; int unk4; unsigned int first; void** blocks; unsigned int pos; int size; } Deq_3B87A0;
extern void func_003B86D0(Deq_3B87A0*);
extern void* func_003AC450(Deq_3B87A0*);
extern void func_00397400(void*, int);
extern void func_00396810(void*, int, int, char*, int);
extern void func_003B92E0(Deq_3B87A0*);
extern char D_004BC4D0[];
void func_003B87A0(Deq_3B87A0* self) {
    if (self->size == 1) {
        func_003B86D0(self);
    } else {
        func_00397400(func_003AC450(self), -1);
        self->size--;
        self->pos++;
        while (self->pos >= 0x10) {
            void* p = self->blocks[self->first];
            if (p) func_00396810(p, 0, 0, D_004BC4D0, 100);
            func_003B92E0(self);
            self->pos -= 8;
        }
    }
}
