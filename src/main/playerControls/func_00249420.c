#include "types.h"
typedef struct { char pad[5]; char b5; } Sub49;
typedef struct { char pad[0x13C]; Sub49* p13C; void* p140; } Owner49;
typedef struct { char pad[0x3584]; char* p3584; } Ctx49;
extern void func_00249460(Owner49* self, Ctx49* ctx);
void func_00249420(Owner49* self, Ctx49* ctx, int a2, char a3) {
    if (!self->p13C) {
        char* q = ctx->p3584;
        if (q) q += 0x1C;
        self->p13C = (Sub49*)q;
    }
    if (self->p13C) self->p13C->b5 = a3;
    func_00249460(self, ctx);
}
