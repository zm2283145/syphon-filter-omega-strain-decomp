/*
 * SFOGame/Source/netBackpackMsg: 1 file, 00281680
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin tank_281680 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
typedef struct { char pad[0x2F1]; unsigned char b2F1; unsigned char b2F2; char pad2f3[0x15]; int owner; } O_00281680;
typedef struct { void* vtable; char pad4[0x1C]; unsigned char cls; char pad21[3]; unsigned char sub; char pad25[3]; O_00281680* obj; int val; } M_00281680;
extern "C" {
extern char* D_005061D0;
extern unsigned char g_IsMultiplayer;
extern int D_005721A8;
extern int D_00494178;
extern int g_LocalPlayer;
extern int g_Hud;
extern char D_005061B0[];
extern char D_004DCEF0[];
extern char D_004DCF10[];
void cNetMsg_GetID(int* id);
O_00281680* cBackpack_NewBackpack_cHumanP_bool_cObjectIdP(void* t, unsigned char remote, int* id);
O_00281680* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
void cBackpack_Unpack(O_00281680* o);
void cBackpack_FadeOut(O_00281680* o);
int NetGetMyClientIndex(int* id, int session);
void cPlayer_BeginPickup(int a, O_00281680* o);
void cHud_Message(int a, char* s);
void cMessage_ctor_cMessageNameR(M_00281680* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(M_00281680* m, void* target, int flags);
void cNetObj_SendMessage_int_cMessageR_int_int(int id, M_00281680* m, int a, int b);
void cMessage_dtor(M_00281680* m, int flags);
}
struct C_00281680 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual bool v19(); };
typedef struct { char pad[0x58]; C_00281680* c58; char pad5c[0x3464 - 0x5C]; O_00281680* p3464; } T_00281680;
typedef struct { char pad[0x24]; unsigned char type; char pad25[3]; O_00281680* obj; int owner; } S_00281680;
static inline char R8_00281680(void) { return *D_005061D0++; }
static inline int LocalId_00281680(void) {
    int session = D_005721A8;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGetMyClientIndex(&D_00494178, session);
        return D_00494178;
    }
    return 0;
}
static inline void Init_00281680(M_00281680* m, O_00281680* o, int v, int sub) {
    cMessage_ctor_cMessageNameR(m, D_005061B0);
    m->vtable = D_004DCEF0;
    m->obj = o; m->sub = sub; m->val = v; m->cls = 4;
}
extern "C" void cNetBackpackMsg_UnpackAndProcess(S_00281680* p, T_00281680* t) {
    int id = -1;
    p->type = R8_00281680();
    p->owner = R8_00281680();
    cNetMsg_GetID(&id);
    if (p->type == 0) {
        unsigned char remote = 0;
        if (t) {
            unsigned char r = 0;
            if (t->c58 && t->c58->v19()) r = 1;
            if (!!r ^ 1) remote = 1;
        }
        p->obj = cBackpack_NewBackpack_cHumanP_bool_cObjectIdP(t, remote, &id);
        p->obj->owner = p->owner;
        cBackpack_Unpack(p->obj);
        if (t && !p->obj->b2F1) t->p3464 = p->obj;
    } else {
        p->obj = nGobjManager_LookupGOBJ_cObjectIdR(&id);
        if (!p->obj) return;
    }
    if (p->type == 3) cBackpack_Unpack(p->obj);
    { unsigned char ty = p->type; if (ty == 1) {
        cBackpack_FadeOut(p->obj);
    } else if (ty == 2) {
        int o = p->obj->owner; if (o == LocalId_00281680() && !p->obj->b2F2) {
            p->obj->owner = p->owner;
            {
                M_00281680 m1;
                M_00281680 m2;
                Init_00281680(&m1, p->obj, p->owner, 4);
                if (t) QueueMessage_cMessageR_cSystemP_int(&m1, t, 0);
                Init_00281680(&m2, p->obj, -1, 3);
                cNetObj_SendMessage_int_cMessageR_int_int(id, &m2, -1, p->owner);
                m2.vtable = D_004DCF10;
                cMessage_dtor(&m2, 0);
                m1.vtable = D_004DCF10;
                cMessage_dtor(&m1, 0);
            }
        } else {
            M_00281680 m3;
            Init_00281680(&m3, p->obj, p->obj->owner, 5);
            cNetObj_SendMessage_int_cMessageR_int_int(id, &m3, -1, p->owner);
            m3.vtable = D_004DCF10;
            cMessage_dtor(&m3, 0);
        }
    } else if (ty == 4) {
        if (p->owner != LocalId_00281680()) p->obj->owner = p->owner;
    } else if (ty == 5) {
        p->obj->owner = p->owner;
        cHud_Message(g_Hud, "Backpack already in use");
    } else if (ty == 3) {
        int o = p->obj->owner; if (o != LocalId_00281680()) {
            p->obj->owner = LocalId_00281680();
            { O_00281680* ob = p->obj; if (!ob->b2F2) ob->b2F2 = 1; }
            cPlayer_BeginPickup(g_LocalPlayer, p->obj);
        }
    } }
}
static inline void merge_flush_tank_281680(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end tank_281680 */
