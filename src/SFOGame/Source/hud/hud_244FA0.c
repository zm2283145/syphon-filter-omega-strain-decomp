/*
 * main/hud: range (3 files, 00244FA0-00245560)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);
char *strncpy(void *, const void *, int);

/* merge_units: begin func_00244FA0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Msg_244FA0 { void* vt; char pad04[0x1C]; unsigned char b20; char pad21[3]; int i24; char pad28[8]; };
struct Sub_244FA0 { int x0; virtual void v0(int t); };
struct Svc_244FA0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22(float dt);
};
struct Tgt_244FA0 { char pad[0x30]; void* x30; };
struct Obj_244FA0 {
    char pad00[0x54];
    int i54;
    char pad58[0x38];
    char hud[0x40];
    Sub_244FA0 sub;
    char padD8[0x28];
    char x100[0x5A0];
    int i6A0;
    char pad6A4[8];
    float f6AC;
    unsigned char b6B0;
    char pad6B1[3];
    float f6B4;
    char pad6B8[0xC];
    char t6C4[0x18];
    float f6DC;
    char pad6E0[8];
    int i6E8;
};
extern "C" {
extern unsigned char D_004FFBB7;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern unsigned char g_LoadoutPending;
extern unsigned char g_GameState;
extern float D_004F7DD8;
extern char g_LevelDirName[];
extern char D_004F7DB8[];
extern char D_004F7A08[];
extern char D_004DBA00[];
extern char D_004DCF10[];
extern Tgt_244FA0* g_LocalPlayer;
float cHud_GetMissionTime();
int cAgentData_GetParTime(void* p, unsigned char b);
int ObjMan_GetService();
int cObjectiveMan_GetObjectiveCount(int s);
int cObjectiveMan_GetSucceededObjectives(int s, int* buf, int n, int k);
void PlayCommanderQuip(int a, int b);
void cInfoBar_NextFrame(void* p, float dt);
void cHud_UpdateCallouts(Obj_244FA0* o, float dt);
int nGobjManager_LookupGOBJ_cObjectIdR(void* id);
void cHudTargetManager_Update(void* h, int t);
void cHud_UpdateWeapon(Obj_244FA0* o, int t);
void cInterface_NextFrame(int h, float dt);
void cMap_NextFrame(int h, float dt);
bool HudTimer_Update(void* t, float now);
float cHud_GetGlobalTime(Obj_244FA0* o);
void cMessage_ctor_cMessageNameR(Msg_244FA0* m, void* p);
void QueueMessage_cMessageR_cSystemP_int(Msg_244FA0* m, void* target, int flags);
void cMessage_dtor(Msg_244FA0* m, int flags);
int Gui_Manager();
Svc_244FA0* Gui_Canvas();
void GuiCanvas_ProcessInput_void(Svc_244FA0* s);
void GuiManager_NextFrame(int h, float dt);
}
extern "C" void cHud_NextFrame(Obj_244FA0* o, float dt)
{
    if (!D_004FFBB7) {
        o->f6DC += dt;
        unsigned char flag = g_IsMultiplayer;
        float cur = cHud_GetMissionTime();
        float max = (float)cAgentData_GetParTime(g_LevelDirName, flag);
        float q = max / 4.0f;
        float h = max / 2.0f;
        float t = 0.75f * max;
        int total = cObjectiveMan_GetObjectiveCount(ObjMan_GetService());
        int buf[20];
        if (D_004F7DD8 < q && !(cur < q)) {
            int n = cObjectiveMan_GetSucceededObjectives(ObjMan_GetService(), buf, 20, 1);
            if (flag && !n)
                PlayCommanderQuip(0x15, 2);
        } else if (D_004F7DD8 < h && !(cur < h)) {
            int n = cObjectiveMan_GetSucceededObjectives(ObjMan_GetService(), buf, 20, 1);
            if (n < total / 2)
                PlayCommanderQuip(0x15, 3);
            else if (flag)
                PlayCommanderQuip(0x15, 2);
        } else if (D_004F7DD8 < t && !(cur < t)) {
            if ((float)cObjectiveMan_GetSucceededObjectives(ObjMan_GetService(), buf, 20, 1) < 0.75f * (float)total)
                PlayCommanderQuip(0x15, 4);
        }
        D_004F7DD8 = cur;
    }
    cInfoBar_NextFrame(o->x100, dt);
    if (o->i6E8)
        cHud_UpdateCallouts(o, dt);
    int tgt = nGobjManager_LookupGOBJ_cObjectIdR(D_004F7DB8);
    o->sub.v0(tgt);
    cHudTargetManager_Update(o->hud, tgt);
    cHud_UpdateWeapon(o, tgt);
    cInterface_NextFrame(o->i54, dt);
    if (o->i6A0)
        cMap_NextFrame(o->i6A0, dt);
    if (HudTimer_Update(&o->f6AC, o->f6DC)) {
        Msg_244FA0 m;
        cMessage_ctor_cMessageNameR(&m, D_004F7A08);
        m.vt = D_004DBA00;
        m.i24 = 1;
        m.b20 = 2;
        QueueMessage_cMessageR_cSystemP_int(&m, g_LocalPlayer->x30, 0);
        m.vt = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
    int busy = o->b6B0 != 0;
    if (!busy) {
        busy = 1;
        if (o->f6B4 <= o->f6AC)
            busy = 0;
    }
    if (!busy && HudTimer_Update(o->t6C4, cHud_GetGlobalTime(o))) {
        if (!g_IsMultiplayer || (g_IsMultiplayer ? D_005721C0 : 1)) {
            Msg_244FA0 m;
            cMessage_ctor_cMessageNameR(&m, D_004F7A08);
            m.vt = D_004DBA00;
            m.i24 = 0;
            m.b20 = 1;
            QueueMessage_cMessageR_cSystemP_int(&m, g_LocalPlayer->x30, 0);
            m.vt = D_004DCF10;
            cMessage_dtor(&m, 0);
        }
    }
    if (!g_LoadoutPending || g_IsMultiplayer) {
        GuiManager_NextFrame(Gui_Manager(), dt);
        if (g_GameState != 0x13)
            GuiCanvas_ProcessInput_void(Gui_Canvas());
        Gui_Canvas()->v22(dt);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00244FA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00244FA0 */

/* merge_units: begin func_00245400 */
#pragma push /* merge_units */
#pragma cplusplus on
struct H_245400 { int v; };
struct Act_245400 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_245400 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
};
struct Msg_245400 {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
};
extern "C" {
extern char g_Game[];
extern char D_004DAE10[];
extern char D_004A72A8[];
void cFileMan_ctor_void(void* m);
void cFileMan_dtor(void* part, int flags);
#if 0 /* merge_units */
void cMessage_dtor(void* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Msg_244FA0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int flags);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((Msg_244FA0 *)(a0), (a1), (a2))) /* merge_units */

int cAgentData_GetCommander(void* o);
void cSndFx_SetSndFx(void* action, int kind, char* name, int a, int b);
void SoundMsg_WrapAction(Msg_245400* msg, void* action);
}
#pragma push
#pragma opt_propagation off
extern "C" void PlayCommanderQuip(int a, int b)
{
    Act_245400 act;
    char buf[32];
    Act_245400* p;
    char* pb;
    char* pa;
    int n;
    p = &act;
    act.h24.v = -2;
    act.w20 = 0;
    pa = act.memberA;
    cFileMan_ctor_void(pa);
    pb = act.memberB;
    cFileMan_ctor_void(pb);
    p->id = -1;
    p->mask = -1;
    p->w20 = 0;
    { H_245400 h; H_245400* hp = &h; h.v = -1; p->h24 = *hp; }
    p->w30 = 0;
    p->w34 = 0;
    p->w38 = 0;
    p->h184 = -1;
    p->w180 = 0;
    p->b186 = 0;
    n = cAgentData_GetCommander(g_LevelDirName);
    if (n > 0) {
        Msg_245400 m;
        sprintf(buf, D_004A72A8, n, a, b);
        cSndFx_SetSndFx(p, 4, buf, 0, 0);
        SoundMsg_WrapAction(&m, &act);
        m.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&m, g_Game, 1);
        m.vtbl = D_004DAE10;
        cFileMan_dtor(m.partB, -1);
        cFileMan_dtor(m.partA, -1);
        cMessage_dtor(&m, 0);
    }
    cFileMan_dtor(pb, -1);
    cFileMan_dtor(pa, -1);
}
#pragma pop
#undef cMessage_dtor /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00245400(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00245400 */

/* merge_units: begin func_00245560 */
#pragma push /* merge_units */
typedef struct {
    void* vt; char pad04[0x18]; int w1C; signed char kind; char pad21[3]; float f; char key[16];
} Msg_245560;
typedef struct {
    void* vtable;
    char pad04[0x1C];
    char b20;
    char pad21[0x57];
    char memberA[0x9C];
    char memberB[0xAC];
} EMsg_245560;
typedef struct { void* owner; } Net_245560;
extern char D_004F7DC0[];
extern char D_004DC310[];
extern char D_004DAE30[];
extern char D_004F0F90[];
#if 0 /* merge_units */
extern char* g_LocalPlayer;
#endif /* merge_units */
#define g_LocalPlayer (*(char **)&g_LocalPlayer) /* merge_units */

#if 0 /* merge_units */
extern float cHud_GetGlobalTime(char* o);
#endif /* merge_units */
#define cHud_GetGlobalTime(a0) (cHud_GetGlobalTime((void *)(a0))) /* merge_units */

extern int nGlobalization_GetString_charP(char* key);
extern void cHud_cHudTimer_ScheduleExpiration(void* t, int text, float time);
extern void EffectMsg_WrapRequest(EMsg_245560* m, void* a);
#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int a);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cFileMan_dtor(void* member, int flags);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) (cFileMan_dtor((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_245560* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(void* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


void cHud_StartGlobalTimer(char* o, char* key, float f)
{
    EMsg_245560 em;
    float t = f + cHud_GetGlobalTime(o);
    cHud_cHudTimer_ScheduleExpiration(o + 0x6C4, key ? nGlobalization_GetString_charP(key) : 0, t);
    EffectMsg_WrapRequest(&em, D_004F0F90);
    em.b20 = 1;
    QueueMessage_cMessageR_cSystemP_int(&em, g_Game, 0);
    if (g_IsMultiplayer && (g_IsMultiplayer ? D_005721C0 : 1)) {
        Msg_245560 m;
        Msg_245560* p = &m;
        cMessage_ctor_cMessageNameR(p, D_004F7DC0);
        m.vt = D_004DC310;
        m.f = t;
        m.kind = 4;
        m.w1C = 0x40;
        if (key) {
            strncpy(p->key, key, 16);
        } else {
            p->key[0] = 0;
        }
        QueueMessage_cMessageR_cSystemP_int(&m, *(void**)(g_LocalPlayer + 0x30), 0);
        m.vt = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
    em.vtable = D_004DAE30;
    cFileMan_dtor(em.memberB, -1);
    cFileMan_dtor(em.memberA, -1);
    cMessage_dtor(&em, 0);
}
#undef g_LocalPlayer /* merge_units */
#undef cHud_GetGlobalTime /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cFileMan_dtor /* merge_units */
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00245560(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00245560 */
