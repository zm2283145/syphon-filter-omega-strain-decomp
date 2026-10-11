#include "types.h"
typedef struct { char pad[0x10]; void* vt10; void* vt14; char pad18[8]; void* vt20; char pad24[0xC]; char arr[4]; } S_3730;
extern char D_004D9720[];
extern char D_004D9730[];
extern char D_004D9740[];
extern char D_004D9750[];
void func_00163820(void* p, int f);
void __destroy_array(void* arr, void* dtor, int size, int n);
void operator_delete(void* p);
S_3730* func_00163730(S_3730* self, short del)
{
    if (self) {
        __destroy_array(self->arr, func_00163820, 0x20, 0x20);
        if (&self->vt10) {
            self->vt10 = D_004D9750;
            if (&self->vt10) {
                self->vt10 = D_004D9740;
                if (&self->vt20) {
                    self->vt20 = D_004D9730;
                    if (&self->vt20)
                        self->vt20 = D_004D9720;
                }
                if (&self->vt14) {
                    self->vt14 = D_004D9730;
                    if (&self->vt14)
                        self->vt14 = D_004D9720;
                }
            }
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}