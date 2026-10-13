#pragma cplusplus on
#include "types.h"
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; char pad34[4]; } HudObjMsg_2750E0;
typedef struct { char pad[0xC]; int marker; } HudObjGObj_2750E0;
extern "C" {
extern unsigned char D_005721C8;
extern char D_0051F098[];
extern char D_004DE280[];
extern char D_004A8F80[];
extern char* D_004FFC2C;
extern void Event_Construct(HudObjMsg_2750E0* m, void* type);
extern void cMessage_dtor(HudObjMsg_2750E0* m, int f);
extern void Transport_Send(int, HudObjMsg_2750E0*, int, int);
extern char* Loc_LookupText(char*);
extern int Loc_FindKeyThunk(char*);
extern void printf(char*);
extern void ObjMarkerMgr_Insert(void*, int*, char*, char*);
}

extern "C" void Hud_AddObjective(HudObjGObj_2750E0* obj, char* a, char* b, int quiet)
{
    char* text = Loc_LookupText(a);
    if (!text || !*text) {
        printf(D_004A8F80);
        return;
    }
    if (!quiet && D_005721C8) {
        int marker = obj->marker;
        HudObjMsg_2750E0 m;
        HudObjMsg_2750E0* p = &m;
        Event_Construct(p, D_0051F098);
        p->vt = D_004DE280;
        p->w24 = marker;
        p->b28 = 1;
        p->key0 = a ? Loc_FindKeyThunk(a) : -1;
        p->key1 = b ? Loc_FindKeyThunk(b) : -1;
        m.kind = 4;
        Transport_Send(0, &m, -1, -1);
        m.vt = D_004DE280;
        cMessage_dtor(&m, 0);
    }
    ObjMarkerMgr_Insert(D_004FFC2C + 0x90, &obj->marker, text, b);
}


