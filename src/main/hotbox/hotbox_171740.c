/*
 * main/hotbox: range (3 files, 00171740-00171880)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "base_dtor_chain.h"
#pragma pop

/* merge_units: begin func_00171740 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00171740, func_00135C90)
#pragma pop /* merge_units */
/* merge_units: end func_00171740 */

/* merge_units: begin func_001717A0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct TZEvt { char pad[0x24]; unsigned char kind; char pad2[0xB]; int arg; } TZEvt;
class TZ { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
 virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
 virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
 virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void f(int a); };
extern "C" int* Event_GetType(TZEvt* e);
extern "C" int D_004EE698;
extern "C" void Hotbox_Type2Receiver(TZ* self, int a);
extern "C" void Hotbox_SendLinkMessages(TZ* self, int a);
extern "C" unsigned char TriggerZone_HandleEvent(TZ* self, TZEvt* e) {
    unsigned char r;
    int t = *Event_GetType(e);
    if (t == D_004EE698) {
        switch (e->kind) {
        case 0: Hotbox_Type2Receiver(self, e->arg); break;
        case 1: break;
        case 2: Hotbox_SendLinkMessages(self, e->arg); break;
        case 3: self->f(e->arg); break;
        }
        r = 1;
    } else r = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001717A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001717A0 */

/* merge_units: begin func_00171880 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad[0x1C]; unsigned char kind; char pad21[0x1F]; } Msg_1880;
typedef struct { void* target; } Lnk_1880;
typedef struct { char pad[0x68]; Lnk_1880* link; char pad6c[0x28]; int x94; } Obj_1880;
void cGOBJTriggerEventMsg_ctor(Msg_1880* m, int type, int a, int b, Obj_1880* src);
int Event_Send(Msg_1880*, void*, int);
int cMessage_dtor(Msg_1880*, int);
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
extern char D_004DAF10[];
static inline unsigned char IsLocal_1880(void) { unsigned char v; if (g_IsMultiplayer) v = D_005721C0; else v = 1; return v; }
/* send a trigger event (type 7) to the linked target when networked */
int Hotbox_Type12BuddyClimb(Obj_1880* self, int arg)
{
    if (g_IsMultiplayer) {
        Msg_1880 m;
        cGOBJTriggerEventMsg_ctor(&m, 7, self->x94, arg, self);
        m.kind = IsLocal_1880() ? 1 : 2;
        Event_Send(&m, self->link->target, 0);
        m.vt = D_004DAF10;
        cMessage_dtor(&m, 0);
    }
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00171880(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00171880 */
