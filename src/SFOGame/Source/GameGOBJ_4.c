/*
 * SFOGame/Source/GameGOBJ: 3 files, 00210780-00210890
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00210780 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
extern "C" {
extern unsigned char D_005723C8;
int NetGetObject(void* out);
void* nGobjManager_LookupGOBJ_cObjectIdR(int*);
}
#pragma define_section GUARD_DTOR ".dtors_drop" far_absolute RX
struct Guard210780 {
    Guard210780() { if (!D_005723C8) D_005723C8 = 1; }
    __declspec(weak) __declspec(GUARD_DTOR) ~Guard210780() { D_005723C8 = 0; }
};
typedef struct { char pad[0x1C]; int* ids; } R210780;
extern "C" void func_00210780(void) {
    Guard210780 g;
    R210780* r;
    if (NetGetObject(&r) == 0) {
        int id = *r->ids;
        char* o = (char*)nGobjManager_LookupGOBJ_cObjectIdR(&id);
        if (o) *(int*)(o + 0x790) = 0;
    }
}
static inline void merge_flush_func_00210780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00210780 */

/* merge_units: begin func_002107F0 */
#pragma push /* merge_units */
typedef struct { int a; int b; int c; signed char d; } Desc_2107F0;
extern int NetRegisterObjectStart(void);
extern int NetObjectField(void* out, int a, int b, int c, int d, Desc_2107F0* desc);
extern int NetRegisterStructure(int* h, void* name, int n);
extern void NetRegisterRemoteObjectCallback(int h, void* a, void* b, void* c);
extern int D_0048AAE8;
extern void func_002106F0();
extern void func_00210620();
extern void func_00210780();
void tGimmeTheElevatorMenu_NetRegister(void)
{
    int out[1];
    Desc_2107F0 desc;
    desc.a = 1000;
    desc.b = 1;
    desc.d = 0x40;
    desc.c = 0;
    if (NetRegisterObjectStart() == 0 && NetObjectField(out, 0, 4, 5, 1, &desc) == 0 &&
        NetRegisterStructure(&D_0048AAE8, "tGimmeTheElevatorMenu", 8) == 0)
        NetRegisterRemoteObjectCallback(D_0048AAE8, func_002106F0, func_00210620, func_00210780);
}
static inline void merge_flush_func_002107F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002107F0 */

/* merge_units: begin func_00210890 */
#pragma push /* merge_units */
#define SOUND_EVENT_NO_PROTOS
#include "sound_event.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern int g_LocalPlayer;
extern char g_Game[];
extern char D_004DADF0[];
extern void cStopSoundMsg_ctor_cSndFxR_cGOBJP(SoundEvent* ev, void* src, void* voice);

int Script_cSoundGOBJ_KillSnd(void** arg0) {
    SoundEvent ev;
    char* o = *arg0;
    char* v;
    if (F_(o, 0x1F2, unsigned char)) v = o;
    else if (g_LocalPlayer) v = 0;
    else v = o;
    cStopSoundMsg_ctor_cSndFxR_cGOBJP(&ev, o + 0x60, v);
    QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 1);
    ev.vtable = D_004DADF0;
    cFileMan_dtor(&ev.req.b, -1);
    cFileMan_dtor(&ev.req.a, -1);
    cMessage_dtor(&ev, 0);
    F_(o, 0x1F0, unsigned char) = 0;
    return 0;
}
static inline void merge_flush_func_00210890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00210890 */
