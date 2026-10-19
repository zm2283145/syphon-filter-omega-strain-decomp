#pragma cplusplus on
#include "types.h"
typedef int u128_t __attribute__((mode(TI))); struct Vec4_27BB70 { float x, y, z, w; Vec4_27BB70() {} Vec4_27BB70(const Vec4_27BB70& o) { u128_t q; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); } } __attribute__((aligned(16)));
typedef struct {
    char pad[0x24];
    unsigned char mode;
    char pad2[3];
    int target;
    int a;
    unsigned char b;
    char pad3[3];
    int c;
    char pad4[8];
    Vec4_27BB70 pos;
} cNetTaserMsg;
typedef struct { char pad[0x4C]; int kind; char pad2[0x3524 - 0x50]; int* held; } T_0027BB70;
extern signed char* D_005061D0;
extern int g_HumanActorClassKey[];
extern "C" void NetStream_ReadObject(int* out);
extern "C" float Script_ReadFloat(void);
extern "C" void HeldItem_Release(int h);
extern "C" void func_00264980(int h, int target, int a, Vec4_27BB70 v);
extern "C" void HeldItem_LaunchDart(int h, int target, unsigned char b, int c, Vec4_27BB70 v);

static inline int Key0() { int* p = g_HumanActorClassKey; return *p; }
static inline int Held(T_0027BB70* t) { int* h = t->held; return *h; }
static inline signed char ReadS8(void)
{
    signed char v = *D_005061D0;
    D_005061D0++;
    return v;
}

extern "C" void cNetTaserMsg_Apply(cNetTaserMsg* self, T_0027BB70* t);
void cNetTaserMsg_Apply(cNetTaserMsg* self, T_0027BB70* t)
{
    self->mode = ReadS8();
    if (self->mode != 2) {
        NetStream_ReadObject(&self->target);
        self->pos.x = Script_ReadFloat();
        self->pos.y = Script_ReadFloat();
        self->pos.z = Script_ReadFloat();
        self->pos.w = 1.0f;
        self->a = ReadS8();
        self->b = ReadS8() != 0;
        self->c = ReadS8();
    }
    if (t && t->kind == Key0()) {
        if (self->mode == 2) {
            HeldItem_Release(*t->held);
        } else if (self->mode == 1) {
            if (self->target == 0) {
                HeldItem_Release(*t->held);
            } else {
                func_00264980(Held(t), self->target, self->a, self->pos);
            }
        } else if (self->mode == 0) {
            HeldItem_LaunchDart(Held(t), self->target, self->b, self->c, self->pos);
        }
    }
}







