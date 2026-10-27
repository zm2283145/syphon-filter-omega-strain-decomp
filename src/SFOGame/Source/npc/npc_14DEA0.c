/*
 * main/npc: range (2 files, 0014DEA0-0014DFB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0014DEA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define AND &&
struct Act_DEA0 { char pad[0xC]; int serial; };
struct Mode_DEA0 { int prio; unsigned char active; char pad[0xF]; };
struct Npc_DEA0 { VPAD32(a) VPAD8(b) virtual int CanLeave(signed char mode); char pad4[0x160]; unsigned char mode; char pad165[0x13]; Mode_DEA0 modes[1]; char pad18c[0x8]; Act_DEA0* target; int targetSerial; float x19C; int prio; unsigned char x1A4; unsigned char x1A5; };
#pragma push



extern "C" void cNPC_RequestFacial(Npc_DEA0* self, Act_DEA0* a, int prio, float f)
{
    if (prio >= self->prio AND prio >= self->modes[self->mode].prio) {
        if (self->CanLeave(*(signed char*)&self->mode)) {
            { int off;
Mode_DEA0* m;
char* b; off = self->mode * 20; b = (char*)(off + (int)self); m = (Mode_DEA0*)(b + 0x178); if (prio >= *(int*)(b + 0x178)) { b[0x17C] = 0; m->prio = 0; } }
        }
        self->mode = 2;
        self->target = a;
        { int none; self->targetSerial = *(a ? &a->serial : (none = -1, &none)); }
        self->x1A4 = 1;
        self->x1A5 = 1;
        self->x19C = f;
        self->prio = prio;
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014DEA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014DEA0 */

/* merge_units: begin func_0014DFB0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Act_DFB0 { char pad[0xC]; int serial; };
struct Mode_DFB0 { int prio; unsigned char active; unsigned char b; char pad[0xE]; };
struct Npc_DFB0 { VPAD32(a) VPAD8(b) virtual int CanLeave(signed char mode); char pad4[0x7C]; int x80; char pad84[0xE0]; unsigned char mode; char pad165[7]; Act_DFB0* target; int serial; float f; Mode_DFB0 modes[1]; };
struct Rec_DFB0 { Act_DFB0* target; int serial; float f; int prio; unsigned char a; unsigned char b; };
#pragma push



#define R(s) ((Rec_DFB0*)((char*)(s) + 0x16C))
extern "C" void cNPC_RequestLookAt_cGOBJP_float_int(Npc_DFB0* self, Act_DFB0* a, int prio, float f)
{
    if (prio >= self->modes[0].prio) {
        if (prio >= self->modes[self->mode].prio) {
        if (self->CanLeave(*(signed char*)&self->mode)) {
            { int off;
Mode_DFB0* m;
char* b; off = self->mode * 20; b = (char*)(off + (int)self); m = (Mode_DFB0*)(b + 0x178); if (prio >= *(int*)(b + 0x178)) { b[0x17C] = 0; m->prio = 0; } }
        }
        self->mode = 0;
        self->target = a;
        { int none; self->serial = *(a ? &a->serial : (none = -1, &none)); }
        self->modes[0].active = 1;
        self->modes[0].b = 1;
        self->f = f;
        self->modes[0].prio = prio;
        }
        self->x80 = 0;
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014DFB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014DFB0 */
