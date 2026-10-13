#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct App391210 {
    __int128 q[0x44];
};

struct Self391210 {
    char pad[0x40];
    App391210 app;
    char padX[0x2C14 - 0x40 - sizeof(App391210)];
    App391210* x2C14;
};

extern "C" {
extern char D_004BC310[];
void Mem_Free(int pool, void* p, char* file, int line);
void func_0038E030(Self391210* self);
void ActorModel_Setup(Self391210* self, int flag);
}

/* 16-byte block copy loop (lq/sq). */
static inline void QMove_391210(void* d0, void* s, int n0) {
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

extern "C" void func_00391210(Self391210* self)
{
    App391210* s = self->x2C14;
    if (s) {
        QMove_391210(&self->app, s, 0x44);
        {
            App391210* p = self->x2C14;
            AllocGuard g;
            Mem_Free(0, p, D_004BC310, 0x2A8);
        }
        self->x2C14 = 0;
        func_0038E030(self);
        ActorModel_Setup(self, 1);
    }
}

