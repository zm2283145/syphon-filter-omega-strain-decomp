#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
extern char D_0049CDA0[];
void operator_delete(void* p);
}
typedef struct { char pad[8]; void* buf; char pad2[4]; unsigned char owns; } S_8C60;
extern "C" S_8C60* func_00178C60(S_8C60* self, short flag)
{
    if (self) {
        if (self->owns) {
            void* b = self->buf;
            AllocGuard g;
            Mem_Free(1, b, D_0049CDA0, 0x43);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}