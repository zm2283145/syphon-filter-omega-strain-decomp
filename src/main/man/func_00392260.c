#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct App92260 {
    __int128 q[0x44];
};

struct Self92260 {
    char pad[0x40];
    App92260 app;               /* 0x40 */
    char pad480[0x2C14 - 0x40 - sizeof(App92260)];
    App92260* saved;            /* 0x2C14 */
};

extern "C" {
extern char D_004BC310[];
void Mem_Free(int pool, void* p, char* file, int line);
void func_0038E030(Self92260* self);
void ActorModel_Setup(Self92260* self, int flag);
void func_0038C820(Self92260* self);
void operator_delete(void* p);
}

/* 16-byte block copy loop (lq/sq), as in func_00391210. */
static inline void QMove_392260(void* d0, void* s, int n0) {
    int n = n0; __int128 t; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}

extern "C" Self92260* func_00392260(Self92260* self, short flag)
{
    if (self) {
        App92260* s = self->saved;
        if (s) {
            QMove_392260(&self->app, s, 0x44);
            {
                App92260* p = self->saved;
                AllocGuard g;
                Mem_Free(0, p, D_004BC310, 0x11F);
            }
            self->saved = 0;
            func_0038E030(self);
            ActorModel_Setup(self, 1);
        }
        func_0038C820(self);
        if (flag > 0) operator_delete(self);
    }
    return self;
}
