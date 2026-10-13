#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
void Pickup_PerformAction(void* o, void* c);
void* func_00253070(void* p, void* s, void* o, void* c, int a, int b);
}
typedef struct { void* first; } L_62C0;
typedef struct { char pad[0x54]; L_62C0* list; } Game_62C0;
extern "C" Game_62C0* D_004FFC2C;
typedef struct { char pad[0x2F2]; unsigned char flag; } Obj_62C0;
typedef struct {
    char pad[0x30]; void* ctl;
    char pad2[0x178 - 0x34]; void* fx; unsigned char on;
    char pad3[0x184 - 0x17D]; int x184;
    char pad4[0x1BC - 0x188]; unsigned char reset;
} S_62C0;
extern "C" void func_001762C0(S_62C0* self, Obj_62C0* o)
{
    void* c = self->ctl;
    if (self->reset) {
        self->reset = 0;
        Pickup_PerformAction(o, c);
    }
    if (self->on && !self->fx) {
        void* p;
        void* s;
        if (!o->flag)
            o->flag = 1;
        s = D_004FFC2C->list->first;
        {
            AllocGuard g;
            p = Mem_Alloc(0, 0xB8, "player.cc", 0x27A);
        }
        if (p)
            p = func_00253070(p, s, o, c, self->x184 <= 0, 0);
        self->fx = p;
    }
}