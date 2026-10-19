/*
 * main/tank: range (4 files, 00285410-00285690)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00285410 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct Sub285410 { char p[0x54]; unsigned char b54; };
struct Tank285410 { char p[0x6C]; Sub285410* sub; };
struct Msg285410 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; int f28; int f2C; };
extern "C" {
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
static inline int IsAuth285410(void) { return D_005721C8 ? D_005721C0 : 1; }
extern "C" void func_00285410(Tank285410* self) {
    if (self->sub) self->sub->b54 = 1;
    if (D_005721C8 && IsAuth285410()) {
        Msg285410 m;
        Event_Construct(&m, D_00506260);
        m.vtable = D_004DCF50;
        m.b24 = 4;
m.b20 = 4;
m.f1C = 0x40;
m.f2C = 0;
m.f28 = 0;
        Event_Send(&m, self, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00285410 */

/* merge_units: begin func_002854D0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Sub2854D0 { char p[0x54]; unsigned char b54; };
struct Tank2854D0 { char p[0x6C]; Sub2854D0* sub; unsigned char b70; };
struct Msg2854D0 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; int f28; int f2C; };
extern "C" {
}
static inline int IsAuth2854D0(void) { return D_005721C8 ? D_005721C0 : 1; }
extern "C" void func_002854D0(Tank2854D0* self) {
    if (self->sub) self->sub->b54 = 0;
    self->b70 = 1;
    if (D_005721C8 && IsAuth2854D0()) {
        Msg2854D0 m;
        Event_Construct(&m, D_00506260);
        m.vtable = D_004DCF50;
        m.f2C = 0;
m.b24 = 2;
m.f28 = 0;
m.b20 = 4;
m.f1C = 0x40;
        Event_Send(&m, self, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_002854D0 */

/* merge_units: begin func_00285590 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Obj285590 { char p[0xC]; int id; };
struct Sub285590 { char p[0x54]; unsigned char b54; char p55[7]; Obj285590* tgt; int tid; };
struct Tank285590 { char p[0x6C]; Sub285590* sub; unsigned char b70; };
struct Msg285590 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; Obj285590* f28; int f2C; };
extern "C" {
}
static inline int IsAuth285590(void) { return D_005721C8 ? D_005721C0 : 1; }
static inline void SetT285590(Sub285590* s, Obj285590* t) { int none; s->tgt = t; s->tid = *(t ? &t->id : (none = -1, &none)); }
extern "C" void cTank_SetEnemy(Tank285590* self, Obj285590* t) {
    if (self->sub) {
        self->sub->b54 = 0;
        SetT285590(self->sub, t);
    }
    self->b70 = 0;
    if (D_005721C8 && IsAuth285590()) {
        Msg285590 m;
        Event_Construct(&m, D_00506260);
        m.vtable = D_004DCF50;
        m.f28 = t;
m.b20 = 4;
m.b24 = 0;
m.f1C = 0x40;
m.f2C = 0;
        Event_Send(&m, self, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00285590 */

/* merge_units: begin func_00285690 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tank_reset.h"

/* cTank: reset controller and aim. */
extern "C" void func_00285690(TankResetTank* self) { TankReset_Do(self); }
#pragma pop /* merge_units */
/* merge_units: end func_00285690 */
