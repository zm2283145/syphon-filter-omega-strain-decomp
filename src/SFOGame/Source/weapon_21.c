/*
 * SFOGame/Source/weapon: 7 files, 00147910-00147A00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00147910 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern char g_WeaponDatabase[];
extern int Global_ReloadWeapons(void);
extern int cWeaponDB_Reload(int);
extern int cFileMan_ctor_void(void*);
extern int cDB_ctor(void*);

/* Constructor: base init, sub-object at +0x1C, then clear the fields. */
Unk00147910* cWeaponDB_ctor(Unk00147910* self) {
    cDB_ctor(self);
    cFileMan_ctor_void(&self->unk1C);
    self->unk14 = 0;
    self->unk18 = 0;
    self->unkD4 = 0;
    self->unk10 = 0;
    self->unkB8[0] = 0;
    self->unkB8[1] = 0;
    self->unkB8[2] = 0;
    self->unkB8[3] = 0;
    self->unkB8[4] = 0;
    self->unkB8[5] = 0;
    self->unkB8[6] = 0;
    return self;
}

int Script_ReloadWeapons(void) {
    Global_ReloadWeapons();
    return 0;
}

int Global_ReloadWeapons(void) {
    int db;

    db = *(int*)g_WeaponDatabase;
    return cWeaponDB_Reload(db);
}

void func_001479A0(void) {
}
static inline void merge_flush_func_00147910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00147910 */

/* merge_units: begin func_001479B0 */
#pragma push /* merge_units */
/* Returns 1.0f. */
float Light_GetCoronaSize(void)
{
    return 1.0f;
}
static inline void merge_flush_func_001479B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001479B0 */

/* merge_units: begin func_001479C0 */
#pragma push /* merge_units */
int Light_GetCoronaFlag(void) {
    return 1;
}
static inline void merge_flush_func_001479C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001479C0 */

/* merge_units: begin func_001479D0 */
#pragma push /* merge_units */
/* Three independent compiler-emitted wrappers/getter in the weapon.cc range. */
#pragma cplusplus on
#pragma exceptions off
struct PLB { int b0; };
struct PLC : PLB {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08();
    virtual void v09(); /* +0x2C */
    virtual void v0A(); /* +0x30 */
    int pad8[3]; float f14;
};
extern "C" void PointLightComp_Start(PLC* c);
extern "C" void func_001479E0(PLC* c);
extern "C" float func_001479F0(PLC* c);
void PointLightComp_Start(PLC* c) { c->v09(); }
void func_001479E0(PLC* c) { c->v0A(); }
float func_001479F0(PLC* c) { return c->f14; }
static inline void merge_flush_func_001479D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001479D0 */

/* merge_units: begin func_00147A00 */
#pragma push /* merge_units */
void func_00147A00(void) {
}

void func_00147A10(void) {
}
static inline void merge_flush_func_00147A00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00147A00 */

/* merge_units: begin func_00147A20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004D92A0[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cAISoundSystemMessage_Clone_void_2, 0x30, "ai.hh", 0x14C)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004D92A0;
    F(char, 0x24) = S(char, 0x24);
    F(char, 0x25) = S(char, 0x25);
    F(float, 0x28) = S(float, 0x28);
    F(float, 0x2C) = S(float, 0x2C);
MSG_CLONE_END
static inline void merge_flush_func_00147A20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00147A20 */

/* merge_units: begin func_00147B40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cAISoundSystemMessage_dtor, D_004D92A0, cMessage_dtor)
static inline void merge_flush_func_00147B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00147B40 */
