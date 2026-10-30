/*
 * SFOGame/Source/netTaserMsg: 2 files, 0027BB00-0027BB70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027BB00 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { void* vtable; char data[0x20]; unsigned char mode; char pad[3]; int unk28; char pad2[0x24]; } Visitor;

extern char D_00504050[];
extern char D_004DCDA0[];
extern char D_004DCF10[];
extern void cMessage_ctor_cMessageNameR(Visitor* v, void* arg);
extern void cNetTaserMsg_UnpackAndProcess(void* v, void* target);
extern void cMessage_dtor(Visitor* v, int flags);

/* Constructs a temporary visitor (mode 2) on the stack, applies it to self and destroys it. */
void cNetTaserMsg_NetReceive(void* self)
{
    Visitor v;
    cMessage_ctor_cMessageNameR(&v, D_00504050);
    v.vtable = D_004DCDA0;
    v.mode = 2;
    v.unk28 = 0;
    cNetTaserMsg_UnpackAndProcess(&v, self);
    v.vtable = D_004DCF10;
    cMessage_dtor(&v, 0);
}
static inline void merge_flush_func_0027BB00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027BB00 */

/* merge_units: begin func_0027BB70 */
#pragma push /* merge_units */
#pragma cplusplus on
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
extern "C" void cNetMsg_GetGOBJ(int* out);
extern "C" float cNetMsg_GetFloat_void(void);
extern "C" void cAirTaser_Release(int h);
extern "C" void cAirTaser_BeginShocking_cHumanP_int_cVector(int h, int target, int a, Vec4_27BB70 v);
extern "C" void cAirTaser_Shoot_cGOBJP_bool_int_cVector(int h, int target, unsigned char b, int c, Vec4_27BB70 v);

static inline int Key0() { int* p = g_HumanActorClassKey; return *p; }
static inline int Held(T_0027BB70* t) { int* h = t->held; return *h; }
static inline signed char ReadS8(void)
{
    signed char v = *D_005061D0;
    D_005061D0++;
    return v;
}

extern "C" void cNetTaserMsg_UnpackAndProcess(void* message, void* target);
void cNetTaserMsg_UnpackAndProcess(void* message, void* target)
{
    cNetTaserMsg* self = (cNetTaserMsg*)message;
    T_0027BB70* t = (T_0027BB70*)target;
    self->mode = ReadS8();
    if (self->mode != 2) {
        cNetMsg_GetGOBJ(&self->target);
        self->pos.x = cNetMsg_GetFloat_void();
        self->pos.y = cNetMsg_GetFloat_void();
        self->pos.z = cNetMsg_GetFloat_void();
        self->pos.w = 1.0f;
        self->a = ReadS8();
        self->b = ReadS8() != 0;
        self->c = ReadS8();
    }
    if (t && t->kind == Key0()) {
        if (self->mode == 2) {
            cAirTaser_Release(*t->held);
        } else if (self->mode == 1) {
            if (self->target == 0) {
                cAirTaser_Release(*t->held);
            } else {
                cAirTaser_BeginShocking_cHumanP_int_cVector(Held(t), self->target, self->a, self->pos);
            }
        } else if (self->mode == 0) {
            cAirTaser_Shoot_cGOBJP_bool_int_cVector(Held(t), self->target, self->b, self->c, self->pos);
        }
    }
}
static inline void merge_flush_func_0027BB70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027BB70 */
