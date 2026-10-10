#include "types.h"

typedef struct { long a; long b; int rel; int extra; } Req;
extern void func_003F4770(void* list, Req* req);

typedef struct { char pad[0x48]; int base; } Obj;

/* Builds a request (offset relative to +0x48) and submits it. */
void func_003F5C90(Obj* self, long a, long b, int pos, int extra)
{
    Req req;
    req.a = a;
    req.b = b;
    req.rel = pos - self->base;
    req.extra = extra;
    func_003F4770(&self->base, &req);
}
