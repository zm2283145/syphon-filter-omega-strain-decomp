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
void Script_ReadU32(int* id);
O_00281680* Backpack_Construct(void* t, unsigned char remote, int* id);
O_00281680* Object_LookupById(int* id);
void func_002536D0(O_00281680* o);
void func_002579E0(O_00281680* o);
int NetGame_InitLocalSlot(int* id, int session);
void Player_HandlePickupTrigger(int a, O_00281680* o);
void Hud_PostNotification(int a, char* s);
void Event_Construct(M_00281680* m, void* type);
void Event_Send(M_00281680* m, void* target, int flags);
void Transport_Send(int id, M_00281680* m, int a, int b);
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
            NetGame_InitLocalSlot(&D_00494178, session);
        return D_00494178;
    }
    return 0;
}
static inline void Init_00281680(M_00281680* m, O_00281680* o, int v, int sub) {
    Event_Construct(m, D_005061B0);
    m->vtable = D_004DCEF0;
    m->obj = o; m->sub = sub; m->val = v; m->cls = 4;
}
extern "C" void func_00281680(S_00281680* p, T_00281680* t) {
    int id = -1;
    p->type = R8_00281680();
    p->owner = R8_00281680();
    Script_ReadU32(&id);
    if (p->type == 0) {
        unsigned char remote = 0;
        if (t) {
            unsigned char r = 0;
            if (t->c58 && t->c58->v19()) r = 1;
            if (!!r ^ 1) remote = 1;
        }
        p->obj = Backpack_Construct(t, remote, &id);
        p->obj->owner = p->owner;
        func_002536D0(p->obj);
        if (t && !p->obj->b2F1) t->p3464 = p->obj;
    } else {
        p->obj = Object_LookupById(&id);
        if (!p->obj) return;
    }
    if (p->type == 3) func_002536D0(p->obj);
    { unsigned char ty = p->type; if (ty == 1) {
        func_002579E0(p->obj);
    } else if (ty == 2) {
        int o = p->obj->owner; if (o == LocalId_00281680() && !p->obj->b2F2) {
            p->obj->owner = p->owner;
            {
                M_00281680 m1;
                M_00281680 m2;
                Init_00281680(&m1, p->obj, p->owner, 4);
                if (t) Event_Send(&m1, t, 0);
                Init_00281680(&m2, p->obj, -1, 3);
                Transport_Send(id, &m2, -1, p->owner);
                m2.vtable = D_004DCF10;
                cMessage_dtor(&m2, 0);
                m1.vtable = D_004DCF10;
                cMessage_dtor(&m1, 0);
            }
        } else {
            M_00281680 m3;
            Init_00281680(&m3, p->obj, p->obj->owner, 5);
            Transport_Send(id, &m3, -1, p->owner);
            m3.vtable = D_004DCF10;
            cMessage_dtor(&m3, 0);
        }
    } else if (ty == 4) {
        if (p->owner != LocalId_00281680()) p->obj->owner = p->owner;
    } else if (ty == 5) {
        p->obj->owner = p->owner;
        Hud_PostNotification(g_Hud, "Backpack already in use");
    } else if (ty == 3) {
        int o = p->obj->owner; if (o != LocalId_00281680()) {
            p->obj->owner = LocalId_00281680();
            { O_00281680* ob = p->obj; if (!ob->b2F2) ob->b2F2 = 1; }
            Player_HandlePickupTrigger(g_LocalPlayer, p->obj);
        }
    } }
}