/*
 * main/tank: range (2 files, 00284020-002840D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "tank_types.h"

/* merge_units: begin func_00284020 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; void* tank; int value; } cNetCreateTankMsg;

extern unsigned char* D_005061D0; /* network write cursor */
extern void func_00284750(void* tank);

static inline void write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

/* cNetCreateTankMsg virtual 4: writes the 32-bit value little-endian, then serializes the tank. */
void cNetCreateTankMsg_v04(cNetCreateTankMsg* self)
{
    int value = self->value;
    write16((unsigned short)value);
    write16(value >> 16);
    func_00284750(self->tank);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00284020(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00284020 */

/* merge_units: begin func_002840D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */


extern int Global_CreateTank(void* gobj);
extern void* cNIEventOBJ_Identity(int handle);

int Script_CreateTank(TankScriptArg* args) {
    volatile int tank = Global_CreateTank(cNIEventOBJ_Identity(args[0].i)); /* mirrors the original stack temporary */
    return tank;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002840D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002840D0 */
