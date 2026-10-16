/*
 * main/hotbox: range (2 files, 0016FE80-0016FF20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0016FE80 */
#pragma push /* merge_units */
#pragma cplusplus on
struct E2Who {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual int IsPlayer(); /* +0x54 */
};
struct E2Owner { char pad[0x58]; E2Who* who; };
struct E2Msg { char pad[0x30]; E2Owner* owner; };
typedef union E2Arg { int i; void* p; } E2Arg;
extern "C" int cHotboxMsg_WhoPlayer(E2Who*);
extern "C" int Script_cHotboxMsg_WhoPlayer(E2Arg* args)
{
    E2Msg* msg = (E2Msg*)args[0].p;
    bool ok = false;
    bool isPlayer = false;
    if (msg->owner->who && msg->owner->who->IsPlayer()) isPlayer = true;
    if (isPlayer && msg->owner->who) ok = true;
    return cHotboxMsg_WhoPlayer(ok ? msg->owner->who : 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016FE80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016FE80 */

/* merge_units: begin func_0016FF20 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ctl_FF20 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsPlayer(); };
struct Hum_FF20 { char pad[0x58]; Ctl_FF20* ctl; };
struct Obj_FF20 { char pad[0x30]; Hum_FF20* hum; };
extern "C" void NpcAi_GetIdentity(Ctl_FF20*);
static inline unsigned char IsPlayer_FF20(Obj_FF20* o) { unsigned char r = 0; if (o->hum->ctl && o->hum->ctl->IsPlayer()) r = 1; return r; }
static inline unsigned char IsNpc_FF20(Obj_FF20* o) { unsigned char r = 0; bool np = !IsPlayer_FF20(o); if (np && o->hum->ctl) r = 1; return r; }
static inline Ctl_FF20* Npc_FF20(Obj_FF20* o) { return IsNpc_FF20(o) ? o->hum->ctl : 0; }
/* script: hand the target's NPC controller (null for the player) to NpcAi_GetIdentity */
extern "C" void Script_cHotboxMsg_WhoNPC(Obj_FF20** args)
{
    NpcAi_GetIdentity(Npc_FF20(args[0]));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016FF20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016FF20 */
