#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004BC200[];
extern char D_00537F80[];
void Mem_Free(int heap, void* p, char* file, int line);
void func_00375CD0(void* p);
void Video_FreeDeferredBuffers(void* p, int a);
void func_003813A0(void* p, int id, int a);
void func_00383020(void* p, int flag);
}
struct VO_0037E320 { int pad[4]; virtual void Destroy(int flag); };
struct E1_0037E320 { int id; int pad[3]; unsigned char flag; char pad11[3]; };
struct E2_0037E320 { void* a; int b; void* c; void* d; void* e; char pad[0x24]; };
struct S_0037E320 {
    int flags; char pad4[0xFB0 - 4]; E2_0037E320 e2[2]; char pad1020[0x103C - 0x1020];
    void* p103C; char pad1040[0x1058 - 0x1040]; void* p1058; VO_0037E320* p105C; char pad1060[8];
    E1_0037E320 e1[6];
};
static inline void Free_0037E320(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_004BC200, line); }
static inline void DelA_0037E320(void* p, int line) { AllocGuard g; func_00383020(p, -1); Mem_Free(0, p, D_004BC200, line); }
static inline void DelV_0037E320(VO_0037E320* p, int line) { AllocGuard g; p->Destroy(-1); Mem_Free(0, p, D_004BC200, line); }
extern "C" void func_0037E320(S_0037E320* self)
{
    int i;
    if (self->flags == -1) return;
    func_00375CD0(D_00537F80);
    if (!(self->flags & 8)) {
        for (i = 0; i < 6; i++) {
            E1_0037E320* e = &self->e1[i];
            func_003813A0(self->p1058, e->id, 0);
            if (e->flag) func_003813A0(self->p1058, e->id + 1, 0);
        }
    }
    { int j; for (j = 0; j < 2; j++) {
        E2_0037E320* e = &self->e2[j];
        Free_0037E320(e->a, 0x23E);
        Free_0037E320(e->c, 0x242);
        Free_0037E320(e->d, 0x243);
        Free_0037E320(e->e, 0x244);
        e->a = 0;
        e->b = 0;
        e->c = 0;
        e->d = 0;
        e->e = 0;
    }}
    Free_0037E320(self->p103C, 0x24C);
    self->p103C = 0;
    DelA_0037E320(self->p1058, 0x24F);
    self->p1058 = 0;
    DelV_0037E320(self->p105C, 0x251);
    self->p105C = 0;
    Video_FreeDeferredBuffers(self, 1);
    self->flags = -1;
}