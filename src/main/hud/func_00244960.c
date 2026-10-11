#include "types.h"
typedef struct { char pad[0x68]; void* obj; } O4960;
extern void func_00260D90(void* tmp);
extern void func_003E7EE0(void* obj, void* tmp);
void func_00244960(O4960* self) {
    if (self->obj) {
        char tmp[16];
        func_00260D90(tmp);
        func_003E7EE0(self->obj, tmp);
    }
}
