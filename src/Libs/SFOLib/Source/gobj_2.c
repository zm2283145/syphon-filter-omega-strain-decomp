/*
 * Libs/SFOLib/Source/gobj: 3 files, 003CC510-003CC5C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CC510 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on

struct VC003CC510 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(...); virtual int v25(...); };
extern "C" {

}
extern "C" int Script_cGOBJ_Enemy(char * arg0) {
    int var_v0;
    void **temp_a0;
    void **temp_s0;
    char * temp_a1;

    temp_a1 = (char *)(F_(arg0, 0x4, int));
    temp_s0 = (void **)(F_(F_(arg0, 0x0, int), 0x58, int));
    var_v0 = -1;
    if (temp_s0 != NULL) {
        temp_a0 = (void **)(F_(temp_a1, 0x58, int));
        if (temp_a0 != NULL) {
            var_v0 = ((VC003CC510 *)(temp_a0))->v24(temp_a1);
        }
        var_v0 = ((VC003CC510 *)(temp_s0))->v25(var_v0) & 0xFF;
    }
    return var_v0 != 0;
}
static inline void merge_flush_func_003CC510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CC510 */

/* merge_units: begin func_003CC580 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;

/* Virtual-call view of TeamInfo: only the slots used here are named (vtable offset in comments). */
struct TeamInfo {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual int GetTeam(); /* +0x68 */
};

typedef struct cGOBJ { char pad[0x58]; TeamInfo* team; } cGOBJ;

/* Script native: returns the object's team, or -1 when it has no team info. */
extern "C" int Script_cGOBJ_Team(ScriptArg* args)
{
    int team = -1;
    TeamInfo* info = ((cGOBJ*)args[0].p)->team;
    if (info)
        team = info->GetTeam();
    {
        volatile int result = team; /* returned through a stack temporary */
        return result;
    }
}
static inline void merge_flush_func_003CC580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CC580 */

/* merge_units: begin func_003CC5C0 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; signed char b24; char pad25[3]; int id; int hp; } Msg_3CC5C0;
typedef struct { char pad[0xC]; int id; char pad10[0x30]; float hp; } Obj_3CC5C0;
extern unsigned char g_IsMultiplayer;
extern char D_00582750[];
extern void cMessage_getSOBJClassId();
extern void cNetSetGobjMsg_dtor();
extern void cNetSetGobjMsg_Clone();
extern void cNetSetGobjMsg_Pack();
void * const D_004E0EE0[8] = { (void*)0x0, (void*)0x0, (void*)cNetSetGobjMsg_dtor, (void*)cNetSetGobjMsg_Clone, (void*)cNetSetGobjMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
extern void cMessage_ctor_cMessageNameR(Msg_3CC5C0* m, void* type);
extern void QueueMessage_cMessageR_cSystemP_int(Msg_3CC5C0* m, void* target, int x);
extern void cMessage_dtor(Msg_3CC5C0* m, int f);

int Script_cGOBJ_SetHitpoints(int* args) {
    volatile int hp;
    int v;
    Obj_3CC5C0* o;
    hp = args[1];
    v = hp;
    o = (Obj_3CC5C0*)args[0];
    o->hp = v;
    if (g_IsMultiplayer) {
        Msg_3CC5C0 m;
        cMessage_ctor_cMessageNameR(&m, D_00582750);
        m.b24 = 0;
        m.vt = ((char*)D_004E0EE0);
        m.id = o->id;
        m.kind = 4;
        m.hp = v;
        QueueMessage_cMessageR_cSystemP_int(&m, o, 0);
        m.vt = ((char*)D_004E0EE0);
        cMessage_dtor(&m, 0);
    }
    return 0;
}
static inline void merge_flush_func_003CC5C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CC5C0 */
