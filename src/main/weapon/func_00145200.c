#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct G_00145200 { char c; };
extern "C" {
extern char D_0049B1D0[];
void Mem_Free(int heap, void* p, char* file, int line);
void func_00136DA0(G_00145200* g);
void func_0012F530(G_00145200* g, int flag);
void func_001454E0(void* p, int flag);
void func_0038CC70(void* p);
}
struct E_00145200 { char pad[0xD8]; int xD8; char padDC[0x11C - 0xDC]; void* p11C; char pad120[0x134 - 0x120]; int x134; unsigned char x138; char p139[3]; void* p13C; };
struct I_00145200 { int a; int n; };
struct S_00145200 { int x0; I_00145200* info; char pad8[0xC]; E_00145200* arr; unsigned char x18; char pad1c[0xB8 - 0x1C]; void* pB8[7]; void* pD4; };
static inline void Free_00145200(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_0049B1D0, line); }
static inline void DelD4_00145200(void* p, int line) { G_00145200 g; func_00136DA0(&g); func_001454E0(p, -1); Mem_Free(0, p, D_0049B1D0, line); func_0012F530(&g, -1); }
extern "C" void func_00145200(S_00145200* self)
{
    int i;
    for (i = 0; i < self->info->n; i++) {
        if (self->arr[i].p13C) {
            func_0038CC70(self->arr[i].p13C);
            Free_00145200(self->arr[i].p13C, 0x3FD);
            self->arr[i].p13C = 0;
            self->arr[i].x138 = 0;
        }
        if (self->arr[i].p11C) {
            func_0038CC70(self->arr[i].p11C);
            Free_00145200(self->arr[i].p11C, 0x406);
            self->arr[i].p11C = 0;
        }
        self->arr[i].x134 = -1;
        self->arr[i].xD8 = -1;
    }
    { int j; for (j = 0; j < 7; j++) {
        if (self->pB8[j]) {
            func_0038CC70(self->pB8[j]);
            Free_00145200(self->pB8[j], 0x413);
            self->pB8[j] = 0;
        }
    } }
    {
        void* p = self->pD4;
        if (p) {
            DelD4_00145200(p, 0x419);
            self->pD4 = 0;
        }
    }
    self->x18 = 0;
}