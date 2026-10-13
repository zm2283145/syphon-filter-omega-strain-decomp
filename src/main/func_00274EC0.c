#pragma opt_propagation off
#pragma cplusplus on
#include "types.h"
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; char pad34[4]; } HudObjMsg_274EC0;
typedef struct { char pad[0xC]; int marker; } HudObjGObj_274EC0;
union HudObjArg_274EC0 { int i; char* p; };
extern "C" {
extern unsigned char D_005721C8;
extern char D_0051F098[];
extern char D_004DE280[];
extern char D_004A8F80[];
extern char* D_004FFC2C;
extern void Event_Construct(HudObjMsg_274EC0* m, void* type);
extern void cMessage_dtor(HudObjMsg_274EC0* m, int f);
extern void Transport_Send(int, HudObjMsg_274EC0*, int, int);
extern char* Loc_LookupText(char*);
extern int Loc_FindKeyThunk(char*);
extern void func_00127358(char*);
extern HudObjGObj_274EC0* GObj_IdentityB(int);
extern void ObjMarkerMgr_Insert(void*, int*, char*, char*);
}
/* the script args are read through unions; with propagation off they stay in stack slots and are reloaded once into saved registers */
extern "C" int Game_AddHudObjective2(int* args)
{
    HudObjArg_274EC0 ua; ua.i = args[1];
    HudObjGObj_274EC0* obj;
    char* text;
    HudObjMsg_274EC0* p;
    int marker;
    char* const b = 0;
    char* a;
    a = ua.p;
    obj = GObj_IdentityB(args[0]);
    text = Loc_LookupText(a);
    if (!text || !*text) {
        func_00127358(D_004A8F80);
    } else {
        if (D_005721C8) {
            HudObjMsg_274EC0 m;
            marker = obj->marker;
            p = &m;
            Event_Construct(p, D_0051F098);
            m.vt = D_004DE280;
            m.w24 = marker;
            m.b28 = 1;
            p->key0 = a ? Loc_FindKeyThunk(a) : -1;
            p->key1 = b ? Loc_FindKeyThunk(b) : -1;
            m.kind = 4;
            Transport_Send(0, &m, -1, -1);
            m.vt = D_004DE280;
            cMessage_dtor(&m, 0);
        }
        ObjMarkerMgr_Insert(D_004FFC2C + 0x90, &obj->marker, text, b);
    }
    return 0;
}



