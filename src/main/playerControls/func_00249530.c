#include "types.h"
typedef struct { unsigned short count; } Sub49b;
typedef struct { char pad[0x13C]; Sub49b* p13C; void* p140; } Owner49b;
typedef struct { char pad[0x3584]; char* p3584; } Ctx49b;
void func_00249530(Owner49b* self, Ctx49b* ctx) {
    if (!self->p13C) {
        char* q = ctx->p3584;
        if (q) q += 0x1C;
        self->p13C = (Sub49b*)q;
    }
    if (self->p13C) self->p13C->count++;
}