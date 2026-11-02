/*
 * SFOGame/Source/gameFrontEnd: 8 files, 002C9420-002C9A40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C9420 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x39]; char names[8][32]; char pad2[0x13C - 0x139]; int count; } Menu9420;
extern char* D_0048C1A0;
extern char g_Game[];
extern int sprintf(char* buf, const char* fmt, ...);
extern void Libc_Strcpy(char* dst, const char* src);
extern void* cGameSystem_GetAgentData(char* name, int index);
extern int cAgentData_HasZeusItem(void* agent, int a, int b, int i);
void cGameFrontEnd_BuildFinalMovie(Menu9420* m)
{
    char num[8];
    char buf[0x28];
    int n = 0;
    void* agent;
    int i;
    sprintf(buf, "%s_EOL", D_0048C1A0);
    n++;
    Libc_Strcpy(m->names[0], buf);
    agent = cGameSystem_GetAgentData(g_Game, -1);
    for (i = 0; i < 10 && n < 8; i++) {
        if (cAgentData_HasZeusItem(agent, 0, 0x63, i)) {
            sprintf(num, "%d_%d", 0x11, i + 1);
            Libc_Strcpy(m->names[n++], num);
        }
    }
    m->count = n;
}
static inline void merge_flush_func_002C9420(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C9420 */

/* merge_units: begin func_002C9510 */
#pragma push /* merge_units */
typedef struct Msg_002C9510 { void* vt; char pad4[0x2C]; } Msg_002C9510;
typedef struct PStr_002C9510 { unsigned char len; char s[0x80]; } PStr_002C9510;
typedef struct Self_002C9510 {
    char pad0[0x28]; unsigned char b28; char pad29[0xE]; unsigned char b37; unsigned char b38;
    char pad39[0x30C - 0x39]; int f30C;
} Self_002C9510;
typedef struct G_002C9510 { char pad[0x2409]; unsigned char b2409; } G_002C9510;
typedef struct W_002C9510 { char pad[0x278]; unsigned char b278; } W_002C9510;
extern char D_00571DC0[];
extern char D_0055A700[];
extern unsigned char D_0051EF68;
extern char g_LevelDirName[];
extern char D_004F2CC0[];
extern char D_004F5370[];
extern char D_004F5378[];
extern char D_004DE220[];
extern char D_004DE200[];
extern int g_WeaponDatabase;
extern char g_Video[];
void cInterfaceManager_Refresh(void* p);
#if 0 /* merge_units */
W_002C9510* GetMachine(void);
#endif /* merge_units */
char* GetMachine(void); /* merge_units */
#define GetMachine() ((W_002C9510 *)GetMachine()) /* merge_units */

void cUSBKeybd_SetKeyMode(void* p);
#if 0 /* merge_units */
G_002C9510* cDME_GetLobby(void);
#endif /* merge_units */
unsigned char* cDME_GetLobby(void); /* merge_units */
#define cDME_GetLobby() ((G_002C9510 *)cDME_GetLobby()) /* merge_units */

void cDME_StartUpdateThread(void);
int Gui_Canvas(void);
void GuiWidget_SendMessage(int a, int b, int c, int d, int e);
char* strncpy(char* d, const char* s, int n);
void* cSystemContainer_GetSystem(void* a, void* b);
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
#if 0 /* merge_units */
void cMessage_dtor(void* m, int flags);
#endif /* merge_units */
void* cMessage_dtor(void* self, short deleteFlag); /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((a0), (short)(a1))) /* merge_units */

void cGameFrontEnd_PlayMusic(Self_002C9510* self, int v);
void cDME_StopUpdateThread(void);
void cMachine_InitFonts(W_002C9510* w);
void cGameFrontEnd_OpenZeusHog(Self_002C9510* self);
void cWeaponDB_OpenWeaponsHog(int a);
void cGameFrontEnd_LobbySendShutdownMessage(int a, int b, int c);
void XLib_NextFrame(void* p);
void cGameFrontEnd_Restore(Self_002C9510* self)
{
    if (self->b37) {
        cInterfaceManager_Refresh(D_00571DC0);
        GetMachine()->b278 = 0;
        cUSBKeybd_SetKeyMode(D_0055A700);
        switch (self->b38) {
        case 0: {
            unsigned char had = 0;
            G_002C9510* g = cDME_GetLobby();
            void* svc;
            int a;
            PStr_002C9510 buf;
            Msg_002C9510 m1;
            Msg_002C9510 m2;
            if (g) {
                had = 1;
                cDME_StartUpdateThread();
                if (D_0051EF68)
                    g->b2409 = 0;
            }
            D_0051EF68 = 0;
            a = Gui_Canvas();
            GuiWidget_SendMessage(a, Gui_Canvas(), 0x10, 5, 0);
            {
                char* d = buf.s;
                const char* s = g_LevelDirName;
                int n = 0;
                while ((*d++ = *s++) != 0) {
                    if (++n >= 0x7E) {
                        n++;
                        *d = '\n';
                        d[1] = 0;
                        break;
                    }
                }
                buf.len = n;
            }
            strncpy(g_LevelDirName, "FRONTEND", 0x80);
            svc = cSystemContainer_GetSystem(g_Game, D_004F2CC0);
            cMessage_ctor_cMessageNameR(&m1, D_004F5370);
            m1.vt = D_004DE220;
            QueueMessage_cMessageR_cSystemP_int(&m1, svc, 1);
            m1.vt = D_004DE220;
            cMessage_dtor(&m1, 0);
            cMessage_ctor_cMessageNameR(&m2, D_004F5378);
            m2.vt = D_004DE200;
            QueueMessage_cMessageR_cSystemP_int(&m2, svc, 1);
            m2.vt = D_004DE200;
            cMessage_dtor(&m2, 0);
            strncpy(g_LevelDirName, buf.s, 0x80);
            {
                unsigned char o = *(unsigned char*)&self->f30C;
                self->f30C = 0xFF;
                cGameFrontEnd_PlayMusic(self, o);
            }
            if (had)
                cDME_StopUpdateThread();
            break;
        }
        case 1:
            cMachine_InitFonts(GetMachine());
            break;
        }
        cGameFrontEnd_OpenZeusHog(self);
        cWeaponDB_OpenWeaponsHog(g_WeaponDatabase);
        cGameFrontEnd_LobbySendShutdownMessage(0x2003, 0, 0);
        self->b37 = 0;
        self->b28 = 1;
        XLib_NextFrame(g_Video);
    }
}
#undef GetMachine /* merge_units */
#undef cDME_GetLobby /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_002C9510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C9510 */

/* merge_units: begin func_002C97A0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cLoadMsg_dtor, D_004DE200, cMessage_dtor)
static inline void merge_flush_func_002C97A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C97A0 */

/* merge_units: begin func_002C9800 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cInitMsg_dtor, D_004DE220, cMessage_dtor)
static inline void merge_flush_func_002C9800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C9800 */

/* merge_units: begin func_002C9860 */
#pragma push /* merge_units */
extern void* cSystemContainer_GetSystem(void* a, void* b);
extern void cWeaponDB_CloseWeaponsHog(int);
extern char* GetMachine(void);
extern void cGameSound_Unload(void*);
extern void cGameFrontEnd_CloseCharacter(void*, int);
extern void cGameFrontEnd_CloseZeusHog(void*);
extern void cUSBKeybd_SetAsciiMode(void*);
extern unsigned char* cDME_GetLobby(void);
#if 0 /* merge_units */
extern char* strncpy(char*, const char*, int);
#endif /* merge_units */
#define strncpy(a0, a1, a2) (strncpy((a0), (a1), (a2))) /* merge_units */

extern char D_004ACF48[];

typedef struct {
    char pad0[0x28];
    unsigned char f28;
    char pad29[0xE];
    unsigned char f37;
    unsigned char f38;
} Obj9860;

typedef struct {
    signed char len;
    char text[0x80];
} PStr;

static inline void Copy(PStr* buf, const char* s)
{
    char* d;
    const char* p;
    int n;
    n = 0;
    d = buf->text;
    p = s;
    while ((*d++ = *p++) != 0) {
        if (++n >= 0x7E) {
            n++;
            d[0] = '\n';
            d[1] = 0;
            break;
        }
    }
    buf->len = n;
}

void cGameFrontEnd_Suspend(Obj9860* self, unsigned char mode)
{
    if (self->f37 == 0) {
        { char* q = GetMachine(); q[0x278] = 1; }
        cUSBKeybd_SetAsciiMode(D_0055A700);
        switch (mode) {
        case 0: {
            void* svc;
            D_0051EF68 = 0;
            svc = cSystemContainer_GetSystem(g_Game, D_004F2CC0);
            if (svc) {
                PStr save;
                unsigned char* g;
                Copy(&save, g_LevelDirName);
                strncpy(g_LevelDirName, D_004ACF48, 0x80);
                cGameSound_Unload(svc);
                strncpy(g_LevelDirName, save.text, 0x80);
                g = cDME_GetLobby();
                if (g && g[0x2409] == 0) {
                    D_0051EF68 = 1;
                    g[0x2409] = 1;
                }
            }
            break;
        }
        case 1:
            break;
        }

        cGameFrontEnd_CloseZeusHog(self);
        cWeaponDB_CloseWeaponsHog(g_WeaponDatabase);
        cGameFrontEnd_CloseCharacter(self, 1);
        self->f37 = 1;
        self->f28 = 0;
        self->f38 = mode;
    }
}
#undef strncpy /* merge_units */
static inline void merge_flush_func_002C9860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C9860 */

/* merge_units: begin func_002C99F0 */
#pragma push /* merge_units */
typedef struct FlagMsg {
    void* vtbl;
    char pad04[0x1C];
    unsigned char flag;  /* 0x20 */
    char pad21[0xF];
} FlagMsg;
extern char D_004D97F0[];
extern void cPauseMusicMsg_ctor(FlagMsg* msg);
#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(FlagMsg* msg, void* target, int flags);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(FlagMsg* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */


/* Broadcasts a flagged message. */
void cGameFrontEnd_PauseMusic(void) {
    FlagMsg msg;
    cPauseMusicMsg_ctor(&msg);
    msg.flag = 1;
    QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 1);
    msg.vtbl = D_004D97F0;
    cMessage_dtor(&msg, 0);
}
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_002C99F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C99F0 */

/* merge_units: begin func_002C9A40 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#pragma pop

#pragma cplusplus on

/* Message destructor: restore vtable, run cMessage base, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_002C9A40, D_004D97F0, cMessage_dtor)
static inline void merge_flush_func_002C9A40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C9A40 */

/* merge_units: begin func_002C9AA0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* cSystemContainer_GetSystem(char* a, char* b);
#endif /* merge_units */
#define cSystemContainer_GetSystem(a0, a1) (cSystemContainer_GetSystem((void *)(a0), (void *)(a1))) /* merge_units */

extern void SoundMgr_StopMusic(void* p);
typedef struct { char pad[0x30C]; int handle; } Obj9AA0;
void FrontEnd_StopMusic(Obj9AA0* o)
{
    void* s = cSystemContainer_GetSystem(g_Game, D_004F2CC0);
    if (s)
        SoundMgr_StopMusic(s);
    o->handle = -1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C9AA0(void) {}
#undef cSystemContainer_GetSystem /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C9AA0 */
