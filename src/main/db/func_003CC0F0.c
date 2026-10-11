#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
extern char D_004BD208[];
void operator_delete(void* p);
}
typedef struct { unsigned char owns; char pad[3]; int len; void* buf; } S_CC0F0;
extern "C" S_CC0F0* func_003CC0F0(S_CC0F0* self, short flag)
{
    if (self) {
        if (self->owns) {
            void* b = self->buf;
            {
                AllocGuard g;
                Mem_Free(0, b, D_004BD208, 0x29);
            }
            self->buf = 0;
            self->len = 0;
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}