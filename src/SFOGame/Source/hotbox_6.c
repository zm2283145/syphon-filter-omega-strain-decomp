/*
 * SFOGame/Source/hotbox: 6 files, 0016FD90-00170080
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016FD90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cEnableMsg_dtor, D_004E0880, cMessage_dtor)
static inline void merge_flush_func_0016FD90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016FD90 */

/* merge_units: begin func_0016FDF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern int D_004EE700;   /* cHotboxMsg type id */
extern int D_004EE738;   /* cHotbox class type id */
extern int D_004EE740;   /* cHotbox script type */
extern char D_00555070[];
extern int cScriptInterpreter_CallEvent(void* filter, int a0, int a1);
extern int* cGOBJ_SOBJ_getClassId(void);
extern int cScriptBase_declareMsgUse(int type, int messageType);
extern void cScriptBase_declareParent(int type, int parentType);

/* Registers the cHotbox script type under its parent and adds cHotboxMsg to it. */
int cHotbox_SOBJ_init(void) {
    int* parent = cGOBJ_SOBJ_getClassId();

    cScriptBase_declareParent(D_004EE740, *parent);
    return cScriptBase_declareMsgUse(D_004EE740, D_004EE700);
}

void* cHotbox_SOBJ_convert(void* self) {
    return self;
}

int* cHotbox_SOBJ_getClassId(void) {
    return &D_004EE738;
}

int cHotbox_getSOBJClassId(void) {
    return D_004EE738;
}

int cHotbox_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
static inline void merge_flush_func_0016FDF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016FDF0 */

/* merge_units: begin func_0016FE80 */
#pragma push /* merge_units */
#include "vslot_pad.h"

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
extern "C" int cPlayer_SOBJ_toInt(E2Who*);
extern "C" int Script_cHotboxMsg_WhoPlayer(E2Arg* args)
{
    E2Msg* msg = (E2Msg*)args[0].p;
    bool ok = false;
    bool isPlayer = false;
    if (msg->owner->who && msg->owner->who->IsPlayer()) isPlayer = true;
    if (isPlayer && msg->owner->who) ok = true;
    return cPlayer_SOBJ_toInt(ok ? msg->owner->who : 0);
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
extern "C" void cNPC_SOBJ_toInt(Ctl_FF20*);
static inline unsigned char IsPlayer_FF20(Obj_FF20* o) { unsigned char r = 0; if (o->hum->ctl && o->hum->ctl->IsPlayer()) r = 1; return r; }
static inline unsigned char IsNpc_FF20(Obj_FF20* o) { unsigned char r = 0; bool np = !IsPlayer_FF20(o); if (np && o->hum->ctl) r = 1; return r; }
static inline Ctl_FF20* Npc_FF20(Obj_FF20* o) { return IsNpc_FF20(o) ? o->hum->ctl : 0; }
/* script: hand the target's NPC controller (null for the player) to cNPC_SOBJ_toInt */
extern "C" void Script_cHotboxMsg_WhoNPC(Obj_FF20** args)
{
    cNPC_SOBJ_toInt(Npc_FF20(args[0]));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016FF20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016FF20 */

/* merge_units: begin func_0016FFC0 */
#pragma push /* merge_units */
extern int D_004EE708;   /* cHotboxMsg script type */
extern int cGOBJ_SOBJ_toInt(void*);
extern void* cGOBJ_SOBJ_convert(int);
extern int Global_MakeGOBJInteractable(void* gobj);
extern int Global_MakeNPCInteractable(void* npc);
extern void* cNPC_SOBJ_convert(int handle);
extern int* cMessage_SOBJ_getClassId(void);

int Script_cHotboxMsg_Who(HotboxScriptArg* args) {
    return cGOBJ_SOBJ_toInt(((cHotboxMsg*)args[0].p)->who);
}

int Script_cHotboxMsg_Action(HotboxScriptArg* args) {
    return ((cHotboxMsg*)args[0].p)->action;
}

/* Registers the cHotboxMsg script type under its parent type. */
void cHotboxMsg_SOBJ_init(void) {
    int* parent = cMessage_SOBJ_getClassId();

    cScriptBase_declareParent(D_004EE708, *parent);
}

int cHotboxMsg_getSOBJClassId(void) {
    return D_004EE700;
}

/* volatile mirrors the original stack temporary. */
int Script_MakeNPCInteractable(HotboxScriptArg* args) {
    volatile int hotbox = Global_MakeNPCInteractable(cNPC_SOBJ_convert(args[0].i));
    return hotbox;
}

int Script_MakeGOBJInteractable(HotboxScriptArg* args) {
    volatile int hotbox = Global_MakeGOBJInteractable(cGOBJ_SOBJ_convert(args[0].i));
    return hotbox;
}
static inline void merge_flush_func_0016FFC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016FFC0 */

/* merge_units: begin func_00170080 */
#pragma push /* merge_units */
#include "net_register_type.h"
typedef struct { int a; int b; int c; int d; } Proto_0080;
extern char D_004EE6A0[];
extern void* cHotboxMsg_HotBoxMsgCallback(void);
NETREG_BEGIN_KEEP(cHotboxMsg_InitNet, Proto_0080)
    NETREG_FIELD(a, 4, 1)
    NETREG_FIELD(b, 4, 1)
    NETREG_FIELD(d, 4, 1)
    NETREG_FIELD(c, 4, 1)
NETREG_END(D_004EE6A0, cHotboxMsg_HotBoxMsgCallback)
static inline void merge_flush_func_00170080(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00170080 */
