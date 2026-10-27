/*
 * main/GuiGameOptions: range (7 files, 0029B360-0029BD70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);
char *strncpy(void *, const void *, int);

/* merge_units: begin func_0029B360 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W_0029B360 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
    char pad4[0x10 - 4]; int index; unsigned short flags; char pad16[0x88 - 0x16]; W_0029B360* link;
};
struct S_0029B360 {
    char pad0[0x80]; W_0029B360* p80; W_0029B360* p84; W_0029B360* p88; W_0029B360* tab[4]; W_0029B360* tabLabel[4];
    W_0029B360* pAC; W_0029B360* pB0; char padB4[0x401 - 0xB4]; unsigned char b401; char pad402[0x408 - 0x402];
    W_0029B360* p408; W_0029B360* p40C; W_0029B360* p410; W_0029B360* p414; W_0029B360* p418; W_0029B360* p41C;
    W_0029B360* p420; W_0029B360* p424; W_0029B360* p428; W_0029B360* p42C; W_0029B360* p430; W_0029B360* p434;
    char* t438[2]; char* t440[2]; char* t448[4]; char* t458; char* t45C; char* t460; char* t464;
};
extern "C" {
extern char* D_00506420[4];
extern char* D_00506430[4];
extern char* D_0048B8D0;
extern char* D_0048B8F8;
extern char D_004A7520[];
extern char D_004A9870[];
extern char D_004AA640[];
extern char D_004AAA80[];
void GuiWidget_onAdd(S_0029B360* self);
W_0029B360* GuiWidget_FindChild_charP(S_0029B360* self, char* name);
char* nGlobalization_GetString_charP(char* key);
}
static inline W_0029B360* FindAs_0029B360(S_0029B360* self, char* name, char* type)
{
    W_0029B360* w = GuiWidget_FindChild_charP(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
/* Looks up the child widgets and localised strings of the page. */
extern "C" void GuiGameOptions_onAdd(S_0029B360* self)
{
    char buf[32];
    int i;
    GuiWidget_onAdd(self);
    for (i = 0; i < 4; i++) {
        self->tab[i] = GuiWidget_FindChild_charP(self, D_00506420[i]);
        if (self->tab[i])
            self->tab[i]->flags &= ~4;
        self->tabLabel[i] = FindAs_0029B360(self, D_00506430[i], D_004A9870);
        if (self->tabLabel[i])
            self->tabLabel[i]->index = i;
    }
    self->pB0 = FindAs_0029B360(self, D_0048B8F8, D_004A7520);
    self->pAC = GuiWidget_FindChild_charP(self, D_0048B8D0);
    self->p80 = GuiWidget_FindChild_charP(self, "buttonsquare");
    self->p84 = GuiWidget_FindChild_charP(self, "buttonx");
    self->p88 = FindAs_0029B360(self, "label_to_map", D_004A7520);
    self->p408 = FindAs_0029B360(self, "value_manualaim", D_004A9870);
    self->p40C = FindAs_0029B360(self, "value_rumble", D_004A9870);
    self->p410 = FindAs_0029B360(self, "value_freelookx", D_004A9870);
    self->p414 = FindAs_0029B360(self, "value_freelooky", D_004A9870);
    self->p418 = FindAs_0029B360(self, "slider_sfx", D_004AAA80);
    self->p41C = FindAs_0029B360(self, "slider_voices", D_004AAA80);
    self->p420 = FindAs_0029B360(self, "slider_music", D_004AAA80);
    self->p424 = FindAs_0029B360(self, "value_mode_btn", D_004A9870);
    self->p428 = FindAs_0029B360(self, "slider_gamma", D_004AAA80);
    self->p42C = FindAs_0029B360(self, "value_videomode", D_004A9870);
    self->p430 = FindAs_0029B360(self, "player_list", D_004AA640);
    self->p434 = GuiWidget_FindChild_charP(self, "select_config_select");
    if (self->p430)
        self->p430->link = self->p434;
    { int j;
    for (j = 0; j < 2; j++) {
        sprintf(buf, "AudioMode%d", j);
        self->t438[j] = nGlobalization_GetString_charP(buf);
    } }
    { int j;
    for (j = 0; j < 2; j++) {
        sprintf(buf, "VideoMode%d", j);
        self->t440[j] = nGlobalization_GetString_charP(buf);
    } }
    { int j;
    for (j = 0; j < 4; j++) {
        sprintf(buf, "OptionsHeader%d", j);
        self->t448[j] = nGlobalization_GetString_charP(buf);
    } }
    self->t458 = nGlobalization_GetString_charP("ControlInvert");
    self->t45C = nGlobalization_GetString_charP("ControlNormal");
    self->t460 = nGlobalization_GetString_charP("MB_On");
    self->t464 = nGlobalization_GetString_charP("MB_Off");
    self->b401 = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029B360(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029B360 */

/* merge_units: begin func_0029B920 */
#pragma push /* merge_units */
typedef struct Sub29B920 { char pad[0x14]; unsigned short flags; } Sub29B920;
typedef struct Obj29B920 {
    char pad0[0x78];
    int state;
    int t;
    char pad80[0xA8 - 0x80];
    Sub29B920* sub;
    char padAC[0xB4 - 0xAC];
    int mode;
} Obj29B920;
void GuiWidget_onAdvanceTime(Obj29B920* o, float dt);
void nRumbleManager_NextFrame(float f);
unsigned long cTimer_GetMillisecondTime(void);
void GuiGameOptions_RevertProscan(Obj29B920* o, int a);
void GuiGameOptions_UpdateKickList(Obj29B920* o);
int NumClientConnections(void);
void GuiGameOptions_onAdvanceTime(Obj29B920* o, float dt)
{
    GuiWidget_onAdvanceTime(o, dt);
    nRumbleManager_NextFrame(dt / 30.0f);
    if (o->state == 1) {
        if (cTimer_GetMillisecondTime() - o->t > 8000) {
            GuiGameOptions_RevertProscan(o, 1);
        }
    }
    if (o->mode == 3) {
        GuiGameOptions_UpdateKickList(o);
    } else if (o->sub != 0 && (o->sub->flags & 4)) {
        if (NumClientConnections() < 2) {
            o->sub->flags &= ~4;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029B920(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029B920 */

/* merge_units: begin func_0029BA10 */
#pragma push /* merge_units */
#define SOUND_EVENT_NO_PROTOS
#include "sound_event.h"
typedef struct { char pad[0xC]; int id; } Voice_BA10;
typedef struct {
    void* vtbl;
    char pad4[0x48 - 4];
    int x48;
    char pad4c[0x78 - 0x4C];
    int x78;
    char pad7c[0xB4 - 0x7C];
    int xB4;
    char cfg[0x28];
    SoundRequest r1;
    SoundRequest r2;
} G_BA10;
extern char D_004E1220[];
extern char D_004DD580[];
void GuiWidget_ctor(void*);
void cGameOptions_ctor(void*);
static inline void Req_Init(SoundRequest* p, int type, __int128 name, Voice_BA10* voice, int x180) {
    int tmp; int* r;
    p->type = type;
    *(__int128*)p->name = name;
    p->voice = voice;
    if (voice) r = &voice->id; else { tmp = -1; r = &tmp; }
    p->voiceId = *r;
    p->x30 = 0; p->x34 = 0; p->x38 = 0;
    p->x184 = -1;
    p->x180 = x180;
}
G_BA10* GuiGameOptions_ctor(G_BA10* self) {
    SoundRequest* p;
    GuiWidget_ctor(self);
    self->vtbl = D_004E1220;
    self->x48 = -2;
    self->vtbl = D_004DD580;
    cGameOptions_ctor(self->cfg);
    p = &self->r1;
    p->voiceId = -2;
    p->voice = 0;
    cFileMan_ctor_void(&p->a);
    cFileMan_ctor_void(&p->b);
    Req_Init(p, -1, -1, 0, 0);
    p->x186 = 0;
    p = &self->r2;
    p->voiceId = -2;
    p->voice = 0;
    cFileMan_ctor_void(&p->a);
    cFileMan_ctor_void(&p->b);
    Req_Init(p, -1, -1, 0, 0);
    p->x186 = 0;
    self->xB4 = 0;
    self->x78 = 0;
    ((unsigned char*)self)[0x400] = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029BA10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029BA10 */

/* merge_units: begin func_0029BB40 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_0029BB40, D_004E1220, GuiWidget_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0029BB40 */

/* merge_units: begin func_0029BBA0 */
#pragma push /* merge_units */
void cDME_DoQuit(signed char arg0, char* arg1, char* arg2); /* gsynth: defined below */
int cPlayer_GetHuman(int arg0); /* gsynth: defined below */
typedef struct { void* vt; char pad[0x20]; int id; int arg; char pad2c[4]; } Msg_BBA0;
typedef struct { char pad[0x90]; } Name_BBA0;
#if 0 /* merge_units */
int cMessage_ctor_cMessageNameR(Msg_BBA0*, void*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

int cNetMsg_GetInt(int*);
#if 0 /* merge_units */
int cMessage_dtor(Msg_BBA0*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

void* cGameSystem_GetPlayer(void*);
#if 0 /* merge_units */
void* cPlayer_GetHuman(void*);
#endif /* merge_units */
#define cPlayer_GetHuman(a0) ((void *)cPlayer_GetHuman((int)(a0))) /* merge_units */

int cGOBJ_GetGobjClientIndex(void*);
#if 0 /* merge_units */
char* nGlobalization_GetString_charP(char*);
#endif /* merge_units */
#define nGlobalization_GetString_charP(a0) (nGlobalization_GetString_charP((a0))) /* merge_units */

void cGameSystem_Restart(void*, int);
#if 0 /* merge_units */
void cDME_DoQuit(int, char*, char*);
#endif /* merge_units */
#define cDME_DoQuit(a0, a1, a2) (cDME_DoQuit((signed char)(a0), (a1), (a2))) /* merge_units */

void pString_ctor(Name_BBA0*);
void Hud_FormatPlayerCalloutName(Name_BBA0*, int, int);
char* pString_CStr(Name_BBA0*);
extern char D_00506440[];
extern char D_004DD5E0[];
extern char D_004DCF10[];
extern char g_Game[];
extern char D_004AA960[];
extern char D_004AA970[];

void cNetKickMsg_NetReceive(void) {
    Msg_BBA0 m;
    Name_BBA0 nm;
    char buf[0x80];
    char* fmt;
    cMessage_ctor_cMessageNameR(&m, D_00506440);
    m.vt = D_004DD5E0;
    cNetMsg_GetInt(&m.id);
    cNetMsg_GetInt(&m.arg);
    if (cGameSystem_GetPlayer(g_Game) && cPlayer_GetHuman(cGameSystem_GetPlayer(g_Game))
        && m.arg == cGOBJ_GetGobjClientIndex(cPlayer_GetHuman(cGameSystem_GetPlayer(g_Game)))) {
        fmt = nGlobalization_GetString_charP(D_004AA960);
        if (!fmt) {
            cGameSystem_Restart(g_Game, 2);
            cDME_DoQuit(1, D_004AA970, 0);
        } else {
            pString_ctor(&nm);
            Hud_FormatPlayerCalloutName(&nm, m.id, 0);
            sprintf(buf, fmt, pString_CStr(&nm));
            cGameSystem_Restart(g_Game, 2);
            cDME_DoQuit(1, D_004AA970, buf);
        }
    }
    m.vt = D_004DCF10;
    cMessage_dtor(&m, 0);
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cPlayer_GetHuman /* merge_units */
#undef nGlobalization_GetString_charP /* merge_units */
#undef cDME_DoQuit /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029BBA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029BBA0 */

/* merge_units: begin func_0029BD00 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
extern signed char D_005721D8;
extern signed char D_005721E0;
extern signed char D_005721F0;
extern signed char D_005723B0;

void cDME_DoQuit(signed char arg0, char *arg1, char *arg2) {
    D_005723B0 = arg0;
    D_005721D8 = 1;
    strncpy(&D_005721E0, arg1, 0x10);
    if (arg2 != 0) {
        strncpy(&D_005721F0, arg2, 0x80);
        return;
    }
    D_005721F0 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029BD00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029BD00 */

/* merge_units: begin func_0029BD70 */
#pragma push /* merge_units */
extern int g_HumanActorClassKey;
#pragma push

int cPlayer_GetHuman(int arg0) {
    int v = F_(arg0, 0x30, int); return (v && F_(v, 0x4C, int) == g_HumanActorClassKey) ? v : 0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029BD70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029BD70 */
