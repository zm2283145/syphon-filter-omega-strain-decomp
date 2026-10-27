/*
 * SFOGame/Source/GuiEquipmentSetup: 1 file, 002A2F00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A2F00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "gui_widget_vslots.h"
extern "C" void cFileMan_dtor(void* part, int flags);

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
extern char g_Game[];
extern int D_00506500;
extern int D_00506508;
extern float D_00506510;
extern unsigned char D_00506518[];
extern long long D_00506520[];
extern int D_00506578;
extern int g_AgentPartCache[][4];
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005723F8;
extern unsigned char D_00582B88;
extern int D_00582CF0;
int HeadsetSemaphore_GetOwner(int a);
void func_002A3A10(S_2A2F00* self);
void GuiTextWidget_SetDisableWrap(void* w, int a);
void func_0041C0D0(void* w, int a);
Pl_2A2F00* cNetObj_GetPlayer(int i);
int SKL_FindSex(void* a);
void cMan_AddDisguise(void* skel, int snd);
void cSndFx_ctor_int_charP_cGOBJP_int(SoundRequest* req, int kind, void* name, int a, int b);
void cPlaySoundMsg_ctor_netPlaySoundMsgR(EffectMsg* msg, SoundRequest* req, void* p);
void QueueMessage_cMessageR_cSystemP_int(EffectMsg* msg, void* target, int flags);
void cFileMan_dtor(void* part, int flags);
void cMessage_dtor(void* msg, int flags);
void cGameSystem_SendAgentData(void* a, int b, int c);
void cSKM_GOBJ_CloneMan(Skel_2A2F00* s, void* src);
Bk_2A2F00* cHuman_GetAgentData(Pl_2A2F00* p);
char* cAgentData_GetUserName(Bk_2A2F00* b);
char* AgentData_GetRankText(Bk_2A2F00* b);
void GuiTextWidget_SetText(void* w, char* s, int a);
char* nGlobalization_GetString_charP(char* key);
void GuiWidget_SendMessage(void* self, void* w, int a, int b, int c);
void cHuman_CheckForDisconnectedNetworkedPlayer(Pl_2A2F00* p);
void cHuman_CheckForChangedWeapons(Pl_2A2F00* p);
int sprintf(void*, const void*, ...);
void cDME_SendPlayGame(void);
Stack_2A2F00* Gui_Canvas(void);
void GuiWidget_onAdvanceTime(S_2A2F00* self, float dt);
}

static inline W_2A2F00* FindAs(void* self, char* n, char* t)
{
    W_2A2F00* w = (W_2A2F00*)GuiWidget_FindChild_charP(self, n);
    unsigned char ok = 0;
    if (w && w->IsA(t)) ok = 1;
    return ok ? w : 0;
}
#define FIND(n, t) FindAs(self, n, t)

extern "C" void GuiEquipmentSetup_onAdvanceTime(S_2A2F00* self, float dt)
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
    me = HeadsetSemaphore_GetOwner(D_00582CF0);
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
            GuiTextWidget_SetDisableWrap(wName, 1);
            func_0041C0D0(wName, 1);
        }
        wRank = FIND(rank, D_004A7520);
        wStatus = FIND(status, D_004A7520);
        wIcon = FIND(icon, D_004A9C40);
        p = cNetObj_GetPlayer(i);
        if (p) {
            int k = ((p->team & 0x7F000000) >> 24) - 1;
            unsigned char st;
            if (k < 0)
                k = 0;
            if (!D_00506518[k]) {
                D_00506518[k] = 1;
                if (self->cc) {
                    int snd = g_AgentPartCache[SKL_FindSex(p->appearance)][k + 0x3E];
                    if (snd)
                        cMan_AddDisguise(p->skel, snd);
                }
                if (k) {
                    cSndFx_ctor_int_charP_cGOBJP_int(&req, 4, D_0048BAA0[k], 0, 0);
                    cPlaySoundMsg_ctor_netPlaySoundMsgR(&msg, &req, p);
                    msg.flag = 1;
                    QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
                    msg.vtbl = D_004DAE10;
                    EffectMsg* m = &msg;
                    if (m->sub30) {
                        cFileMan_dtor(msg.partB, -1);
                        cFileMan_dtor(msg.partA, -1);
                    }
                    cMessage_dtor(&msg, 0);
                    cFileMan_dtor(req.partB, -1);
                    cFileMan_dtor(req.partA, -1);
                }
                cGameSystem_SendAgentData(g_Game, 0, 0);
            }
            cSKM_GOBJ_CloneMan(self->skel[k], p->skel);
            self->skel[k]->b2C71 = 1;
            if (cHuman_GetAgentData(p) && cHuman_GetAgentData(p)->bB70) {
                long long* c = &D_00506520[k];
                if (*c > 10) {
                    GuiTextWidget_SetText(wName, cAgentData_GetUserName(cHuman_GetAgentData(p)), 0);
                    GuiTextWidget_SetText(wRank, AgentData_GetRankText(cHuman_GetAgentData(p)), 0);
                } else {
                    GuiTextWidget_SetText(wName, D_004AB160, 0);
                    GuiTextWidget_SetText(wRank, D_004AB160, 0);
                }
                (*c)++;
            } else {
                GuiTextWidget_SetText(wName, D_004AB160, 0);
                GuiTextWidget_SetText(wRank, D_004AB160, 0);
            }
            st = p->GetState();
            if (st == 0) {
                t = nGlobalization_GetString_charP(D_004AB168);
                self->ready = 0;
            } else if (st == 1) {
                t = nGlobalization_GetString_charP(D_004AB168);
                if (self->ready > 1)
                    self->ready = 1;
            } else if (st == 2) {
                t = nGlobalization_GetString_charP(D_004AB178);
            } else {
                t = nGlobalization_GetString_charP(D_004AB190);
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
            GuiTextWidget_SetText(wStatus, t, 0);
            if (p->local) {
                Slot_2A2F00* s = p->slot;
                if (s)
                    s->b33 = D_00582B88;
            }
            if (p->IsActive()) {
                wIcon->flags |= 2;
                if (i == me) {
                    if (p->local)
                        GuiWidget_SendMessage(self, wIcon, 10, 1, 0);
                    else
                        GuiWidget_SendMessage(self, wIcon, 10, 2, 0);
                } else {
                    GuiWidget_SendMessage(self, wIcon, 10, 0, 0);
                }
            } else {
                wIcon->flags &= ~2;
            }
            if (p->local)
                D_00506500 = i;
            else
                cHuman_CheckForDisconnectedNetworkedPlayer(p);
            cHuman_CheckForChangedWeapons(p);
        } else {
            self->skel[i]->b2C3A = -1;
            wIcon->flags &= ~2;
            GuiTextWidget_SetText(wName, D_004AB160, 0);
            GuiTextWidget_SetText(wRank, D_004AB160, 0);
            GuiTextWidget_SetText(wStatus, D_004AB160, 0);
            D_00506518[i] = 0;
            D_00506520[i] = 0;
        }
    }
    if (g_IsMultiplayer) {
        if (D_00506508) {
            unsigned char ok;
            D_00506510 += dt;
            sprintf(buf, self->timerFmt, 10 - (int)(D_00506510 / 30.0f));
            GuiTextWidget_SetText(self->timer, buf, 0);
            if (g_IsMultiplayer)
                ok = D_005721C0;
            else
                ok = 1;
            if (ok && D_00506510 > 300.0f)
                cDME_SendPlayGame();
        } else {
            D_00506510 = 0.0f;
        }
    }
    if (g_IsMultiplayer) {
        unsigned char ok;
        if (g_IsMultiplayer)
            ok = D_005721C0;
        else
            ok = 1;
        if (ok) {
            W_2A2F00* w;
            self->readyShown = self->ready;
            if (self->ready == 0)
                t = nGlobalization_GetString_charP(D_004AB100);
            else if (self->ready >= 3)
                t = nGlobalization_GetString_charP(D_004AB100);
            else
                t = nGlobalization_GetString_charP(D_004AB1A0);
            w = FIND(D_004AB0B0, D_004A9870);
            if (t && w)
                GuiTextWidget_SetText(w, t, 0);
        }
    }
    if (!Gui_Canvas()->n28 || Gui_Canvas()->p2C->top != self) {
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
    GuiWidget_onAdvanceTime(self, dt);
}
static inline void merge_flush_func_002A2F00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A2F00 */
