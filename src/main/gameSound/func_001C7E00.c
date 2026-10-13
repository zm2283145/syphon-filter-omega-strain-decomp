#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct SndEv_7E00 { int time; unsigned char b4; unsigned char b5; char pad6[2]; void* vt; unsigned char on; };
struct Slot_7E00 {
    int type; char pad4[0x3C]; int handle; unsigned char state; char pad45[0x1B0 - 0x45 - 0x50];
    bool NotFree() { return (state == 0) ^ 1; }
    bool NotStopping() { return !(state == 1 || state == 3); }
    unsigned char IsActive() {
        unsigned char r = 0;
        if (NotFree())
            if (NotStopping())
                r = 1;
        return r;
    }
};
struct Ent_7E00 { char pad0[0x50]; Slot_7E00 sub; };
struct Self_7E00 { char pad0[0x20]; unsigned char on; };
extern "C" {
extern char D_0049F4A0[];
extern char D_004D9DE0[];
extern void * const D_004DAC30[];
void* Mem_Alloc(int, int, char*, int);
void EventQueue_Admit(SndEv_7E00*);
void func_003A7EC0(int, int, int, int);
void func_003A7F80(int);
void func_003A7FB0(int);
}

extern "C" void func_001C7E00(Self_7E00* self, int on)
{
    Slot_7E00* found = 0;
    int i;
    for (i = 0; i < 50; i++) {
        Slot_7E00* s = &((Ent_7E00*)self)[i].sub;
        if (((Ent_7E00*)self)[i].sub.type == 5) {
            if (s->IsActive()) {
                found = s;
                break;
            }
        }
    }
    if (on && !self->on) {
        if (found) {
            SndEv_7E00* e;
            func_003A7EC0(found->handle, 0, 0x1F4, 2);
            {
                AllocGuard g;
                e = (SndEv_7E00*)Mem_Alloc(0, 0x10, D_0049F4A0, 0x591);
            }
            if (e) {
                e->vt = D_004D9DE0;
                e->b4 = 0;
                e->time = 0xFA0;
                e->b5 = 0;
                e->vt = (void*)D_004DAC30;
                e->on = 1;
            }
            EventQueue_Admit(e);
        } else {
            func_003A7FB0(2);
        }
        self->on = 1;
    }
    if (!on && self->on) {
        if (found) {
            SndEv_7E00* e;
            func_003A7EC0(found->handle, 0x400, 0x1F4, 2);
            {
                AllocGuard g;
                e = (SndEv_7E00*)Mem_Alloc(0, 0x10, D_0049F4A0, 0x5A2);
            }
            if (e) {
                e->vt = D_004D9DE0;
                e->b4 = 0;
                e->time = 0xFA0;
                e->b5 = 0;
                e->vt = (void*)D_004DAC30;
                e->on = 0;
            }
            EventQueue_Admit(e);
        } else {
            func_003A7F80(2);
        }
        self->on = 0;
    }
}







