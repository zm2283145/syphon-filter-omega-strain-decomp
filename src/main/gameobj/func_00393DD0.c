#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_0049AF00[];
void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}
typedef struct { int a; int b; int c; void* buffer; } BufHolder393DD0;
extern "C" BufHolder393DD0* func_00393DD0(BufHolder393DD0* self, short deleteFlag)
{
    if (self) {
        if (self) {
            void* p = self->buffer;
            if (p) {
                if (p) {
                    AllocGuard guard;
                    Mem_Free(0, p, D_0049AF00, 0x64);
                }
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}