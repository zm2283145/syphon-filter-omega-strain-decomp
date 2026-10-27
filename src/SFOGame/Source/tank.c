/*
 * SFOGame/Source/tank: 5 files, 00282990-00282BB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00282990 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"

/* Clone a network message. */
extern "C" { char D_004A9540[] = "tank.hh"; }
DEFINE_NET_MSG_CLONE(cNetUpdateTankMsg_Clone, 0x30, D_004A9540, 0xCD, D_004DCF50,
                     NMC_B(0x24); NMC_W(0x28); (*(float*)((char*)p + (0x2C)) = *(float*)((char*)self + (0x2C))))
static inline void merge_flush_func_00282990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00282990 */

/* merge_units: begin func_00282AB0 */
#pragma push /* merge_units */
#include "tank_types.h"

typedef struct TankBody {
    char pad[0x40];
    float hitpoints;
} TankBody;

typedef struct Tank {
    char pad[0x60];
    TankBody* body;
} Tank;

typedef struct TankArgs {
    Tank* obj;
} TankArgs;

/* Script native: cTank.GetHitpoints - returns the body's hitpoints truncated to int. */
int Script_cTank_GetHitpoints(TankArgs* args) {
    volatile int hp = args->obj->body->hitpoints;
    return hp;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00282AB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00282AB0 */

/* merge_units: begin func_00282AE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */


extern int cGOBJ_SOBJ_toInt(void*);

int Script_cTank_GetGobj(TankScriptArg* args) {
    return cGOBJ_SOBJ_toInt(((cTank*)args[0].p)->gobj);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00282AE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00282AE0 */

/* merge_units: begin func_00282AF0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Sub282AF0 { char p[0x54]; unsigned char b54; };
struct Tank282AF0 { char p[0x6C]; Sub282AF0* sub; };
struct Msg282AF0 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; int f28; int f2C; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
static inline int IsAuth282AF0(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
extern "C" int Script_cTank_StopFiring(Tank282AF0** args) {
    Tank282AF0* self = args[0];
    if (self->sub) self->sub->b54 = 1;
    if (g_IsMultiplayer && IsAuth282AF0()) {
        Msg282AF0 m;
        cMessage_ctor_cMessageNameR(&m, D_00506260);
        m.vtable = D_004DCF50;
        m.b24 = 4;
m.b20 = 4;
m.f1C = 0x40;
m.f2C = 0;
m.f28 = 0;
        QueueMessage_cMessageR_cSystemP_int(&m, self, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
    return 0;
}
static inline void merge_flush_func_00282AF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00282AF0 */

/* merge_units: begin func_00282BB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tank_reset.h"

/* Script binding: reset the tank in the first argument. */
extern "C" int Script_cTank_Reset(TankResetTank** args) { TankReset_Do(*args); return 0; }
static inline void merge_flush_func_00282BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00282BB0 */
