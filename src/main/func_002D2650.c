#pragma cplusplus on
#include "types.h"
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; char pad34[4]; } Msg_2D2650;
typedef struct { char pad0[8]; signed char b8; char pad9[3]; int wC; int k10; int k14; } Pkt_2D2650;
extern "C" {
extern unsigned char D_005723C8;
extern unsigned char D_005721D0;
extern char D_0051F098[];
extern char D_004DE280[];
extern void Event_Construct(Msg_2D2650* m, void* type);
extern void cMessage_dtor(Msg_2D2650* m, int f);
extern char* Loc_GetStoredKey(int);
extern void* ObjMan_GetService(void);
extern void ObjMan_SetDisplayLabel(void* mgr, char* key, void* obj, int quiet);
extern void* Object_LookupById(int* id);
extern void Hud_AddObjective(void* obj, char* a, char* b, int c);
extern void func_001C6200(char* name, char* text0, int silent);
}
/* scoped re-entrancy flag; the out-of-line dtor copy is dropped like AllocGuard's (see alloc_guard.h) */
#pragma define_section GUARD_2D2650_DTOR ".dtors_drop" far_absolute RX
struct Guard_2D2650 {
    Guard_2D2650() { if (!D_005723C8) D_005723C8 = 1; }
    __declspec(weak) __declspec(GUARD_2D2650_DTOR) ~Guard_2D2650() { D_005723C8 = 0; }
};
static inline char* Name_2D2650(int id) { return id != -1 ? Loc_GetStoredKey(id) : 0; }

extern "C" int func_002D2650(void* a0, void* a1, void* a2, void* data)
{
    Guard_2D2650 g;
    if (D_005721D0) {
        Pkt_2D2650* pkt = (Pkt_2D2650*)data;
        Msg_2D2650 m;
        Event_Construct(&m, D_0051F098);
        m.vt = D_004DE280;
        m.w24 = pkt->wC;
        m.b28 = pkt->b8;
        m.key0 = pkt->k10;
        m.key1 = pkt->k14;
        switch ((unsigned char)m.b28) {
        case 0:
            ObjMan_SetDisplayLabel(ObjMan_GetService(), Name_2D2650(m.key0), 0, 1);
            break;
        case 1: {
            int id = m.w24;
            void* obj = Object_LookupById(&id);
            if (obj) {
                Hud_AddObjective(obj, Name_2D2650(m.key0), Name_2D2650(m.key1), 1);
            }
            break;
        }
        case 2:
            func_001C6200(Name_2D2650(m.key0), Name_2D2650(m.key1), 1);
            break;
        }
        m.vt = D_004DE280;
        cMessage_dtor(&m, 0);
    }
    return 0x18;
}