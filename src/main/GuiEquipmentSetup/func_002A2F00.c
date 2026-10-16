#pragma cplusplus on
#include "types.h"
#include "gui_widget_vslots.h"
extern "C" void FileMan_Release(void* part, int flags);

typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];
    char partB[0xAC];
} SoundRequest;
typedef struct EffectMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0xF];
    char sub30[0x48];
    char partA[0x9C];
    char partB[0xAC];
} EffectMsg;

struct W_2A2F00 : GuiWidgetV { char pad4[0x10]; unsigned short flags; };
struct Skel_2A2F00 { char pad[0x2C3A]; signed char b2C3A; char pad2C3B[0x2C71 - 0x2C3B]; unsigned char b2C71; };
struct Slot_2A2F00 { char pad[0x33]; unsigned char b33; };
struct Pl_2A2F00 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v0A(); virtual void v0B(); virtual void v0C(); virtual void v0D(); virtual void v0E();
    virtual void v0F(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19();
    virtual int IsActive();             /* +0x70 */
    virtual void SetReady(int r);       /* +0x74 */
    virtual unsigned char GetState();   /* +0x78 */
    char pad4[8];
    unsigned int team;      /* 0x0C */
    char pad10[4];
    unsigned char local;    /* 0x14 */
    char pad15[0x60 - 0x15];
    char skel[0x40];        /* 0x60 */
    char appearance[0x3584 - 0xA0]; /* 0xA0 */
    Slot_2A2F00* slot;      /* 0x3584 */
};
struct Bk_2A2F00 { char pad[0xB70]; unsigned char bB70; };
struct Scr_2A2F00 { char pad[8]; void* top; };
struct Stack_2A2F00 { char pad[0x28]; int n28; Scr_2A2F00* p2C; };
struct S_2A2F00 {
    char pad00[0x48];
    Skel_2A2F00* skel[4];   /* 0x48 */
    char pad58[0x68 - 0x58];
    float angle;            /* 0x68 */
    char pad6C[0xC0 - 0x6C];
    int ready;              /* 0xC0 */
    int readyShown;         /* 0xC4 */
    char padC8[4];
    int cc;                 /* 0xCC */
    W_2A2F00* timer;        /* 0xD0 */
    char* timerFmt;         /* 0xD4 */
    char padD8[4];
    float spin;             /* 0xDC */
};

extern "C" {
extern char D_0048BAA0[][8];
extern char D_004A7520[];
extern char D_004A9870[];
extern char D_004A9C40[];
extern char D_004AB0B0[];
extern char D_004AB100[];
extern char D_004AB160[];
extern char D_004AB168[];
extern char D_004AB178[];
extern char D_004AB190[];
extern char D_004AB1A0[];
extern char D_004DAE10[];
extern char D_004FFB50[];
extern int D_00506500;
extern int D_00506508;
extern float D_00506510;
extern unsigned char D_00506518[];
extern long long D_00506520[];
extern int D_00506578;
extern int D_0055DDA0[][4];
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
extern unsigned char D_005723F8;
extern unsigned char D_00582B88;
extern int D_00582CF0;
int func_00437600(int a);
void func_002A3A10(S_2A2F00* self);
void func_0041C0F0(void* w, int a);
void func_0041C0D0(void* w, int a);
Pl_2A2F00* PlayerSlots_Get(int i);
int Appearance_GetBodyKind(void* a);
void func_00391020(void* skel, int snd);
void SoundRequest_Ctor(SoundRequest* req, int kind, void* name, int a, int b);
void func_0020F190(EffectMsg* msg, SoundRequest* req, void* p);
void Event_Send(EffectMsg* msg, void* target, int flags);
void FileMan_Release(void* part, int flags);
void cMessage_dtor(void* msg, int flags);
void Game_NetSendPauseState(void* a, int b, int c);
void Skel_Rebind(Skel_2A2F00* s, void* src);
Bk_2A2F00* func_00185C70(Pl_2A2F00* p);
char* AgentData_GetName(Bk_2A2F00* b);
char* AgentData_GetRankText(Bk_2A2F00* b);
void func_0041BEB0(void* w, char* s, int a);
char* Loc_LookupText(char* key);
void func_0041E0F0(void* self, void* w, int a, int b, int c);
void Player_HandleLeftGame(Pl_2A2F00* p);
void func_001B2D20(Pl_2A2F00* p);
int sprintf(void*, const void*, ...);
void DME_SendPlayGameMsg(void);
Stack_2A2F00* Gui_GetScreenStack(void);
void func_0041E3B0(S_2A2F00* self, float dt);
}

static inline W_2A2F00* FindAs(void* self, char* n, char* t)
{
    W_2A2F00* w = (W_2A2F00*)GuiWidget_FindChildByName(self, n);
    unsigned char ok = 0;
    if (w && w->IsA(t)) ok = 1;
    return ok ? w : 0;
}
#define FIND(n, t) FindAs(self, n, t)

extern "C" void func_002A2F00(S_2A2F00* self, float dt)
{
    char name[17] = "1value_agentname";
    char rank[12] = "1value_rank";
    char status[14] = "1value_status";
    char icon[9] = "1headset";
    SoundRequest req;
    EffectMsg msg;
    char buf[0x40];
    int me;
    int i;
    char* t;

    D_00506578++;
    me = func_00437600(D_00582CF0);
    func_002A3A10(self);
    for (i = 0; i < 4; i++) {
        W_2A2F00* wName;
        W_2A2F00* wRank;
        W_2A2F00* wStatus;
        W_2A2F00* wIcon;
        Pl_2A2F00* p;
        {
            char c = '1' + i;
            name[0] = c;
            rank[0] = c;
            status[0] = c;
            icon[0] = c;
        }
        wName = FIND(name, D_004A7520);
        if (wName) {
            func_0041C0F0(wName, 1);
            func_0041C0D0(wName, 1);
        }
        wRank = FIND(rank, D_004A7520);
        wStatus = FIND(status, D_004A7520);
        wIcon = FIND(icon, D_004A9C40);
        p = PlayerSlots_Get(i);
        if (p) {
            int k = ((p->team & 0x7F000000) >> 24) - 1;
            unsigned char st;
            if (k < 0)
                k = 0;
            if (!D_00506518[k]) {
                D_00506518[k] = 1;
                if (self->cc) {
                    int snd = D_0055DDA0[Appearance_GetBodyKind(p->appearance)][k + 0x3E];
                    if (snd)
                        func_00391020(p->skel, snd);
                }
                if (k) {
                    SoundRequest_Ctor(&req, 4, D_0048BAA0[k], 0, 0);
                    func_0020F190(&msg, &req, p);
                    msg.flag = 1;
                    Event_Send(&msg, D_004FFB50, 0);
                    msg.vtbl = D_004DAE10;
                    EffectMsg* m = &msg;
                    if (m->sub30) {
                        FileMan_Release(msg.partB, -1);
                        FileMan_Release(msg.partA, -1);
                    }
                    cMessage_dtor(&msg, 0);
                    FileMan_Release(req.partB, -1);
                    FileMan_Release(req.partA, -1);
                }
                Game_NetSendPauseState(D_004FFB50, 0, 0);
            }
            Skel_Rebind(self->skel[k], p->skel);
            self->skel[k]->b2C71 = 1;
            if (func_00185C70(p) && func_00185C70(p)->bB70) {
                long long* c = &D_00506520[k];
                if (*c > 10) {
                    func_0041BEB0(wName, AgentData_GetName(func_00185C70(p)), 0);
                    func_0041BEB0(wRank, AgentData_GetRankText(func_00185C70(p)), 0);
                } else {
                    func_0041BEB0(wName, D_004AB160, 0);
                    func_0041BEB0(wRank, D_004AB160, 0);
                }
                (*c)++;
            } else {
                func_0041BEB0(wName, D_004AB160, 0);
                func_0041BEB0(wRank, D_004AB160, 0);
            }
            st = p->GetState();
            if (st == 0) {
                t = Loc_LookupText(D_004AB168);
                self->ready = 0;
            } else if (st == 1) {
                t = Loc_LookupText(D_004AB168);
                if (self->ready > 1)
                    self->ready = 1;
            } else if (st == 2) {
                t = Loc_LookupText(D_004AB178);
            } else {
                t = Loc_LookupText(D_004AB190);
            }
            if (st == 3) {
                if (self->ready) {
                    D_00506508++;
                    self->timer->flags |= 2;
                } else {
                    D_00506508 = 0;
                    self->ready = 0;
                    p->SetReady(1);
                    self->timer->flags &= ~2;
                    if (D_005723F8)
                        D_005723F8 = 0;
                }
            } else if (i == 0 && (self->timer->flags & 2)) {
                D_00506508 = 0;
                self->timer->flags &= ~2;
            }
            func_0041BEB0(wStatus, t, 0);
            if (p->local) {
                Slot_2A2F00* s = p->slot;
                if (s)
                    s->b33 = D_00582B88;
            }
            if (p->IsActive()) {
                wIcon->flags |= 2;
                if (i == me) {
                    if (p->local)
                        func_0041E0F0(self, wIcon, 10, 1, 0);
                    else
                        func_0041E0F0(self, wIcon, 10, 2, 0);
                } else {
                    func_0041E0F0(self, wIcon, 10, 0, 0);
                }
            } else {
                wIcon->flags &= ~2;
            }
            if (p->local)
                D_00506500 = i;
            else
                Player_HandleLeftGame(p);
            func_001B2D20(p);
        } else {
            self->skel[i]->b2C3A = -1;
            wIcon->flags &= ~2;
            func_0041BEB0(wName, D_004AB160, 0);
            func_0041BEB0(wRank, D_004AB160, 0);
            func_0041BEB0(wStatus, D_004AB160, 0);
            D_00506518[i] = 0;
            D_00506520[i] = 0;
        }
    }
    if (D_005721C8) {
        if (D_00506508) {
            unsigned char ok;
            D_00506510 += dt;
            sprintf(buf, self->timerFmt, 10 - (int)(D_00506510 / 30.0f));
            func_0041BEB0(self->timer, buf, 0);
            if (D_005721C8)
                ok = D_005721C0;
            else
                ok = 1;
            if (ok && D_00506510 > 300.0f)
                DME_SendPlayGameMsg();
        } else {
            D_00506510 = 0.0f;
        }
    }
    if (D_005721C8) {
        unsigned char ok;
        if (D_005721C8)
            ok = D_005721C0;
        else
            ok = 1;
        if (ok) {
            W_2A2F00* w;
            self->readyShown = self->ready;
            if (self->ready == 0)
                t = Loc_LookupText(D_004AB100);
            else if (self->ready >= 3)
                t = Loc_LookupText(D_004AB100);
            else
                t = Loc_LookupText(D_004AB1A0);
            w = FIND(D_004AB0B0, D_004A9870);
            if (t && w)
                func_0041BEB0(w, t, 0);
        }
    }
    if (!Gui_GetScreenStack()->n28 || Gui_GetScreenStack()->p2C->top != self) {
        self->spin = 0.0f;
    } else {
        const float pi = 3.1415927f;
        float r = pi * (dt / 30.0f);
        self->angle += r * self->spin;
        if (self->angle > pi)
            self->angle -= 6.2831855f;
        else if (self->angle < -pi)
            self->angle += 6.2831855f;
    }
    func_0041E3B0(self, dt);
}
