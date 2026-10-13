#include "types.h"
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int w24; signed char b28; char pad29[3]; int key0; int key1; char pad34[4]; } Msg_227A90;
typedef struct { char pad0[0xC]; int owner; } Obj_227A90;
extern unsigned char D_005721C8;
extern int D_005721A8;
extern int D_00494178;
extern void* D_004FFC2C;
extern char D_0051F098[];
extern char D_004DE280[];
extern void* Loc_LookupText(char* key);
extern void Hud_PostNotification(void* hud, void* text);
extern void Event_Construct(Msg_227A90* m, void* type);
extern int Loc_FindKeyThunk(char* s);
extern void Transport_Send(int a, Msg_227A90* m, int b, int c);
extern void cMessage_dtor(Msg_227A90* m, int f);
extern int Player_GetIndex(int);
extern void NetGame_InitLocalSlot(int*, int);
#define LOCALID_(X) { int ld_a = D_005721A8; if (D_005721C8) { if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, ld_a); X = D_00494178; } else X = 0; }
static inline int KeyOf_227A90(char* s) { return s ? Loc_FindKeyThunk(s) : -1; }
static inline int LocalId_227A90() { int r; LOCALID_(r); return r; }
static inline int IsMine_227A90(Obj_227A90* o) { int owner = o->owner; return Player_GetIndex(owner) == LocalId_227A90(); }
static inline int IsMine2_227A90(Obj_227A90* o) { int owner = o->owner; int me = LocalId_227A90(); return Player_GetIndex(owner) == me; }
void ObjMan_SetDisplayLabel(void* mgr, char* key, Obj_227A90* obj, int quiet)
{
    void* text = Loc_LookupText(key);
    if (D_005721C8) {
        if (obj) {
            int owner = obj->owner;
            int me;
            int pi;
            LOCALID_(me);
            pi = Player_GetIndex(owner);
            if (pi != me) goto skip;
        }
        Hud_PostNotification(D_004FFC2C, text);
    skip:
        if (!quiet) {
            Msg_227A90 m;
            Msg_227A90* p = &m;
            Event_Construct(p, D_0051F098);
            m.b28 = 0;
            m.w24 = 0;
            m.vt = D_004DE280;
            p->key0 = KeyOf_227A90(key);
            p->key1 = KeyOf_227A90(0);
            if (!obj) {
                m.kind = 4;
                Transport_Send(0, &m, -1, -1);
            } else {
                Transport_Send(0, &m, 0, Player_GetIndex(obj->owner));
            }
            m.vt = D_004DE280;
            cMessage_dtor(&m, 0);
        }
    } else {
        Hud_PostNotification(D_004FFC2C, text);
    }
}


