#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void operator_delete(void* p);
}
typedef struct { unsigned char owns; char pad[3]; int len; void* buf; } S_CC0F0;
extern "C" S_CC0F0* cDB_dtor(S_CC0F0* self, short flag)
{
    if (self) {
        if (self->owns) {
            void* b = self->buf;
            {
                AllocGuard g;
                cMemMan_Deallocate(0, b, "db.cc", 0x29);
            }
            self->buf = 0;
            self->len = 0;
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}