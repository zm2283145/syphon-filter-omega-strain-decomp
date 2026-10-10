#include "types.h"
#pragma cplusplus on
struct C6Slot_158800 { int handle; int id; int pad[3]; };
struct C6B1_158800 { void* vtable; char pad04[0x5C]; };
struct C6B2_158800 { char pad[0x5C]; int regs[9]; void Clear() { for (int i = 0; i < 9; i++) regs[i] = 0; } };
struct C6AiComp_158800 : C6B1_158800, C6B2_158800 {
    char padE0[0x150 - 0xE0];
    int kind;
    char pad154[0x16C - 0x154];
    C6Slot_158800 slots[3];
    int pad1A8;
    int m1AC;
    int m1B0;
    char pad1B4[0x1C8 - 0x1B4];
    int m1C8;
    int m1CC;
};
extern "C" void cAI_ctor(C6AiComp_158800*, void*, int);
extern "C" void func_00158BC0(C6AiComp_158800*, void*);
extern "C" char D_004D9380[];
extern "C" C6AiComp_158800* AiComponent_Construct(C6AiComp_158800* self, void* owner, int* kind) {
    cAI_ctor(self, owner, 0);
    C6B2_158800& b = *self;
    b.Clear();
    self->vtable = D_004D9380;
    self->kind = *kind;
    C6Slot_158800* s = self->slots;
    do { s->id = -2; s->handle = 0; s++; } while (s != self->slots + 3);
    self->m1CC = -2;
    self->m1C8 = 0;
    self->m1B0 = 0;
    self->m1AC = 0;
    func_00158BC0(self, owner);
    return self;
}