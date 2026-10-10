#include "types.h"
typedef struct C6It_3B86D0 { Q q[2]; } C6It_3B86D0;
typedef struct C6Arr_3B86D0 { int pad0; unsigned int state; int index; void** items; int result; int live; } C6Arr_3B86D0;
extern void func_00397840(C6It_3B86D0*, C6Arr_3B86D0*, int);
extern void Array_DestroyRange(C6Arr_3B86D0*, C6It_3B86D0*, C6It_3B86D0*);
extern void func_00396810(void*, int, int, char*, int);
extern void func_003B92E0(C6Arr_3B86D0*);
extern char D_004BC4D0[];
void func_003B86D0(C6Arr_3B86D0* self) {
    C6It_3B86D0 first;
    C6It_3B86D0 last;
    func_00397840(&last, self, self->live);
    func_00397840(&first, self, 0);
    Array_DestroyRange(self, &first, &last);
    self->live = 0;
    if (self->state > 1) {
        while (self->state > 2) {
            void* p = self->items[self->index];
            if (p) func_00396810(p, 0, 0, D_004BC4D0, 100);
            func_003B92E0(self);
        }
        self->result = 4;
    } else {
        self->result = 0;
    }
}