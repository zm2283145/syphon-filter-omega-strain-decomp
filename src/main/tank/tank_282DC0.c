/*
 * main/tank: range (2 files, 00282DC0-00282E10)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_00282DC0 */
#pragma push /* merge_units */
typedef struct { char pad[0x68]; int weapon; int weaponId; } Ang2DC0;
typedef struct { char pad[0x6C]; Ang2DC0* angles; } Tank2DC0;
typedef union { int i; Tank2DC0* p; } Arg2DC0;
extern int D_004FFD30;
extern int WeaponDb_Get(int db, int id);
int Script_cTank_SetWeapon(Arg2DC0* args) {
    volatile int id = args[1].i;
    Ang2DC0* a = args[0].p->angles;
    int i = id;
    if (a) {
        int db = D_004FFD30;
        a->weaponId = i;
        a->weapon = WeaponDb_Get(db, i);
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00282DC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00282DC0 */

/* merge_units: begin func_00282E10 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Gun282E10 { VPAD32(a) VPAD16(b) VPAD16(c) VPAD2(d) VPAD1(e) virtual void Fire(); virtual void Arm(int on); };
struct Sub282E10 { Gun282E10* gun; };
struct Tank282E10 { char p[0x60]; Gun282E10* turret; char p64[8]; Sub282E10* sub; };
struct Msg282E10 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; int f28; float f2C; };
extern "C" {
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
void func_0023E3D0(Gun282E10*, float);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
static inline int IsAuth282E10(void) { return D_005721C8 ? D_005721C0 : 1; }
union Arg282E10 { int i; float f; void* p; };
extern "C" int Script_cTank_Move(Arg282E10* args) {
    float v;
Gun282E10* t;
Tank282E10* self;
int tmp;
    tmp = args[1].i;
    v = *(float*)&tmp;
    self = (Tank282E10*)args[0].p;
    t = self->turret;
    func_0023E3D0(t, v);
    t->Fire();
    if (self->sub) self->sub->gun->Arm(1);
    if (D_005721C8 && IsAuth282E10()) {
        Msg282E10 m;
        Event_Construct(&m, D_00506260);
        m.vtable = D_004DCF50;
        m.f28 = 0;
        m.b24 = 1;
        m.f2C = v;
        m.b20 = 4;
        m.f1C = 0x40;
        Event_Send(&m, self, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00282E10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00282E10 */
