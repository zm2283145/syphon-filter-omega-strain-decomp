/*
 * SFOGame/Source/machine: 7 files, 00165630-00165E60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00165630 */
#pragma push /* merge_units */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);
int strlen(const char *);

typedef struct Game {
    char pad0[0x250];
    unsigned char videoMode;
    char pad251[3];
    int width;
    int height;
    float invFps;
    int fps;
} Game;

extern void cSFOini_Load(char* name);
extern void cGameOptions_LoadDefaults(int);
extern char* cSFOini_GetKeyValue(char* key);
extern void printf(char* fmt, ...);
extern int String_CompareNoCase(char* a, char* b);
extern int Libc_Strncmp(char* a, char* b, int n);
extern int atoi(char*);
extern void Language_FromSystem(int);
extern char* nGlobalization_GetLanguageName_eLanguage(unsigned char id);
extern void Loc_SetLanguage(unsigned char id);
extern char* nGlobalization_GetLanguageName_void(void);
extern int strstr(char* a, char* b);

extern int g_OptionsRecord;
extern char D_004FFBB5;
extern char D_004FFBB1;
extern int D_00494188;

void cMachine_InitINI(Game* g) {
    char* s;
    char* v;
    int i;
    int ukEnglish;
    int j;

    cSFOini_Load("SFO_GAME.INI");
    cGameOptions_LoadDefaults(g_OptionsRecord);
    { char* mode = cSFOini_GetKeyValue("BOOT_VIDEOMODE"); printf("videomode: %s\n", mode); }
    { int pal = String_CompareNoCase(cSFOini_GetKeyValue("BOOT_VIDEOMODE"), "PAL") == 0; if (pal) {
        g->videoMode = 2;
        g->width = 0x280;
        g->height = 0x200;
        g->fps = 0x32;
    } else { int pro = String_CompareNoCase(cSFOini_GetKeyValue("BOOT_VIDEOMODE"), "PROSCAN") == 0; if (pro) {
        g->videoMode = 4;
        g->width = 0x280;
        g->height = 0x1E0;
        g->fps = 0x1E;
    } else {
        g->videoMode = 0;
        g->width = 0x280;
        g->height = 0x1C0;
        g->fps = 0x1E;
    } }}
    D_004FFBB5 = 1;
    D_004FFBB1 = 1;
    g->invFps = 1.0f / g->fps;
    { char* net = cSFOini_GetKeyValue("NET_BUFFER_SIZE");
    if (strlen(net) != 0) {
        D_00494188 = atoi(net);
    } }
    /* retail "1" is an 8-byte, 8-aligned literal: a 4-byte wide string */
    ukEnglish = String_CompareNoCase(cSFOini_GetKeyValue("BOOT_USE_UK_ENGLISH"), (char*)L"1") == 0;
    s = cSFOini_GetKeyValue("BOOT_LANGUAGE");
    if (s && *s) {
        if (String_CompareNoCase(s, "PS2_SETTING") == 0) {
            Language_FromSystem(ukEnglish);
        } else {
            for (i = 0; i < 7; i++) {
                if (String_CompareNoCase(s, nGlobalization_GetLanguageName_eLanguage(i)) == 0) {
                    Loc_SetLanguage(i);
                    break;
                }
                if (i == 6) {
                    Language_FromSystem(ukEnglish);
                    break;
                }
            }
        }
    } else {
        Language_FromSystem(ukEnglish);
    }
    v = cSFOini_GetKeyValue("BOOT_VALID_LANGUAGES");
    if (v && *v) {
        if (strstr(v, nGlobalization_GetLanguageName_void()) == 0) {
            for (j = 0; j < 7; j++) {
                char* name = nGlobalization_GetLanguageName_eLanguage(j);
                if (Libc_Strncmp(v, name, strlen(name)) == 0) {
                    Loc_SetLanguage(j);
                    return;
                }
                if (j == 6) {
                    Loc_SetLanguage(0);
                }
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00165630(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00165630 */

/* merge_units: begin func_00165950 */
#pragma push /* merge_units */
typedef struct { char s[0x80]; } S165;
typedef struct { float f[9]; } M165;
typedef struct { float f[3]; } V165;
typedef struct { int v[3]; } I165;
typedef struct {
    S165 name;
    int i80;
    M165 m;
    int iA8;
    int iAC;
    V165 v;
    int iBC;
    unsigned char bC0;
    S165 name2;
    char pad141[3];
    int i144;
    int i148;
    signed char b14C;
    char pad14D[3];
    int i150;
    int i154;
    int i158;
    int i15C;
    int i160;
    int i164;
    unsigned char b168;
} R165;
typedef struct { char pad[0x248]; int i248; char p24C[0x280 - 0x24C]; int i280[3]; } O165;
extern R165* cHogList_Open(void*, char*, int, int);
extern void cFont_Load(int, R165*, int);
extern int* GetTextSystem(void);
extern I165 D_0048A060;
extern char D_0048B2F8[];
extern char D_0049C360[];
extern char D_004FFB8C[];
extern int D_00533868;
extern int g_InterfaceFont;
extern S165 D_0055C5D0;
extern int D_0055C650;
extern M165 D_0055C654;
extern int D_0055C678;
extern int D_0055C67C;
extern V165 D_0055C680;
extern int D_0055C68C;
extern unsigned char D_0055C690;
extern S165 D_0055C691;
extern int D_0055C714;
extern int D_0055C718;
extern signed char D_0055C71C;
extern int D_0055C720;
extern int D_0055C724;
extern int D_0055C728;
extern int D_0055C72C;
extern int D_0055C730;
extern int D_0055C734;
extern unsigned char D_0055C738;

void cMachine_InitFonts(O165* o) {
    char buf[0x50];
    I165 I165 = D_0048A060;
    R165* r;
    int i;
    int x;
    sprintf(buf, D_0049C360, D_0048B2F8);
    r = cHogList_Open(D_004FFB8C, buf, 0, 0);
    for (i = 0; i < 3; i++) {
        cFont_Load(o->i280[i], r, I165.v[i]);
    }
    x = o->i280[0];
    *GetTextSystem() = x;
    o->i248 = x;
    D_00533868 = x;
    g_InterfaceFont = o->i280[1];
    D_0055C5D0 = r->name;
    D_0055C650 = r->i80;
    D_0055C654 = r->m;
    D_0055C678 = r->iA8;
    D_0055C67C = r->iAC;
    D_0055C680 = r->v;
    D_0055C68C = r->iBC;
    D_0055C690 = r->bC0;
    D_0055C691 = r->name2;
    D_0055C714 = r->i144;
    D_0055C718 = r->i148;
    D_0055C71C = r->b14C;
    D_0055C720 = r->i150;
    D_0055C724 = r->i154;
    D_0055C728 = r->i158;
    D_0055C72C = r->i15C;
    D_0055C730 = r->i160;
    D_0055C734 = r->i164;
    D_0055C738 = r->b168;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00165950(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00165950 */

/* merge_units: begin func_00165BC0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cNetObj_NetInit();                        
int cNetObjectiveMsg_InitNet();                             
int cTeam_InitNet();                                  
int cHotboxMsg_InitNet();                                  
int cEndLevelMsg_InitNet();                                  
int cStopSoundMsg_InitNet();                                  
int cPlaySoundMsg_InitNet_void();                                  
int SoundPosRequest_NetRegister();                                  
int tGimmeTheElevatorMenu_NetRegister();                                  
int cNetLockElevatorMsg_InitNet();                                  
int cGOBJTriggerEventMsg_InitNet();                                  
int cElevatorGOBJ_InitNet();                                  
int cPathedGOBJ_InitNet();                                  
int cGeneratorDataMessage_InitNet();                                  
int cGeneratorMessageBase_InitNet();                                  
int cRespawnMsg_InitNet();                                  
int cNotifyCheckpointMsg_InitNet();                                  
int cAddCheckpointMsg_InitNet();                                  
int cNICameraMsg_InitNet();                                  
int cNIShuttle_InitNet();                                  
int cRestoreBodyMsg_InitNet();                                  
int cSwitchBodiesMsg_InitNet();                                  
int cAIUnconsciousMsg_InitNet();                                  
int cAIDisguiseTakenMsg_InitNet();                                  
int cAIBodyMovedMsg_InitNet();                                  
int cAINewAwarenessMsg_InitNet();                                  
int cAIDestinationReachedMsg_InitNet();                                  
int cAIWaypointReachedMsg_InitNet();                                  
int cAIDeadMsg_InitNet();                                  
int cAIDeactivatedMsg_InitNet();                                  
int cAIActivatedMsg_InitNet();                                  
int func_00282240();                                  
int cNetCalloutMsg_InitNet();                                  
int cNetCopyMsg_InitNet();                                  
int cNetCreateBlastMsg_InitNet();                                  
int netCreateNPC_InitNet();                                  
int netCreatePlayer_InitNet();                                  
int tNetGenerator_InitNet();                                  
int cNetGeneratorCreateMsg_InitNet();                                  
int cNetGeneratorDeleteMsg_InitNet();                                  
int cNetHuman_InitNet();                                  
int cNetLabelMsg_InitNet();                                  
int cNetNPCMsgs_InitNet();                                  
int cNetPathMsg_InitNet();                                  
int cNetScoreMsg_InitNet();                                  
int cNetShatterMsg_InitNet();                                  
int cNetWeaponMsg_InitNet();                                  
int cNetRemoveHudObjectiveMsg_InitNet();                                  
int Iop_LoadNetModules(int);                                 
int cDME_Init();                                  
extern unsigned char D_004EE530;
extern signed char D_0051EEA0;
extern unsigned char D_0051EEA8;
extern unsigned char D_005723D0;

void cMachine_InitDME(void) {
    if (D_004EE530 == 0) {
        D_004EE530 = 1;
        Iop_LoadNetModules(1);
        if (D_0051EEA8 == 0) {
            D_0051EEA0 = 1;
            cDME_Init();
        }
    }
    if (D_005723D0 == 0) {
        cNetHuman_InitNet();
        tNetGenerator_InitNet();
        cNetPathMsg_InitNet();
        cNetGeneratorCreateMsg_InitNet();
        cNetGeneratorDeleteMsg_InitNet();
        cNetObjectiveMsg_InitNet();
        cNetWeaponMsg_InitNet();
        cSwitchBodiesMsg_InitNet();
        cRestoreBodyMsg_InitNet();
        cGeneratorMessageBase_InitNet();
        cGeneratorDataMessage_InitNet();
        cAIDeadMsg_InitNet();
        cAIDeactivatedMsg_InitNet();
        cAIActivatedMsg_InitNet();
        cAIWaypointReachedMsg_InitNet();
        cAIDestinationReachedMsg_InitNet();
        cAINewAwarenessMsg_InitNet();
        cAIBodyMovedMsg_InitNet();
        cAIUnconsciousMsg_InitNet();
        cAIDisguiseTakenMsg_InitNet();
        cEndLevelMsg_InitNet();
        SoundPosRequest_NetRegister();
        cPlaySoundMsg_InitNet_void();
        cStopSoundMsg_InitNet();
        cNetCreateBlastMsg_InitNet();
        cNetCalloutMsg_InitNet();
        cNetShatterMsg_InitNet();
        cNetRemoveHudObjectiveMsg_InitNet();
        cNIShuttle_InitNet();
        cNICameraMsg_InitNet();
        cNetNPCMsgs_InitNet();
        cNetCopyMsg_InitNet();
        cRespawnMsg_InitNet();
        cNotifyCheckpointMsg_InitNet();
        cAddCheckpointMsg_InitNet();
        cNetLabelMsg_InitNet();
        cHotboxMsg_InitNet();
        cGOBJTriggerEventMsg_InitNet();
        cNetLockElevatorMsg_InitNet();
        cElevatorGOBJ_InitNet();
        cPathedGOBJ_InitNet();
        cNetScoreMsg_InitNet();
        tGimmeTheElevatorMenu_NetRegister();
        cTeam_InitNet();
        netCreateNPC_InitNet();
        netCreatePlayer_InitNet();
        func_00282240();
        cNetObj_NetInit();
        D_005723D0 = 1;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00165BC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00165BC0 */

/* merge_units: begin func_00165DC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern char D_0055A700[];
extern int cUSBKeybd_Init(void* obj);

int cMachine_InitUSB(void) {
    return cUSBKeybd_Init(D_0055A700);
}
static inline void merge_flush_func_00165DC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00165DC0 */

/* merge_units: begin func_00165DD0 */
#pragma push /* merge_units */
extern char D_0055A300[];
void cJoystick_Init(void* p);
void cJoystick_AddPad(void* p, int a, int b, int c);
#pragma opt_propagation off
void cMachine_InitJoystick(void)
{
    float f;
    int v;
    cJoystick_Init(D_0055A300);
    f = 56.0f;
    v = (int)f;
    cJoystick_AddPad(D_0055A300, 0, 0, v);
    cJoystick_AddPad(D_0055A300, 1, 0, v);
}
#pragma opt_propagation reset
static inline void merge_flush_func_00165DD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00165DD0 */

/* merge_units: begin func_00165E40 */
#pragma push /* merge_units */
extern long g_TickCounter64;
extern int g_TimerAccum;

/* Resets timer state and the EE timer 0 counter register. */
int cMachine_InitTimers(void)
{
    g_TickCounter64 = 0;
    g_TimerAccum = 0;
    *(volatile int*)0x10000800 = 0;
    return 1;
}
static inline void merge_flush_func_00165E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00165E40 */

/* merge_units: begin func_00165E60 */
#pragma push /* merge_units */
/* cMachine::ShowLoadingScreen: draws a few frames of the loading screen (the hud loading bar,
   or the screen fader plus the level name and loading text) inside a pushed full-screen
   viewport and identity view matrix. Render-state idioms as in cMachine_ChooseNetworkServer. */
#pragma opt_rotateloops off
#pragma cplusplus on

typedef struct V4_00165E60 { float x, y, z, w; } V4_00165E60;
typedef struct Mtx_00165E60 { __int128 q[4]; } Mtx_00165E60;
typedef struct Slot_00165E60 {
    char pad[0x1F0];
    float r[4];
    char pad200[0x2E0 - 0x200];
    int f2E0;
    int pad2E4;
    float f2E8;
    char pad2EC[0x2F4 - 0x2EC];
    char f2F4;
    char f2F5;
    char f2F6;
} Slot_00165E60;
typedef struct Rs_00165E60 {
    char pad[0xA80];
    Mtx_00165E60 mtx[1];
} Rs_00165E60;
struct tRGBA { float r, g, b, a; tRGBA(float x, float y, float z, float w) { r = x; g = y; b = z; a = w; } };
struct cScreenFader { char pad[0xC]; unsigned char active; void Enable(unsigned char e) { active = e; } };
struct cMachine { char pad[0x274]; void* hudLoading; char pad278[0x280 - 0x278]; void* font; };

extern "C" {
extern char g_Video[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
extern V4_00165E60 D_00539170;
extern long long D_004BC1B0;
extern long long D_005392D8;
extern int g_DrawMode;
extern cScreenFader* g_Fader;
extern char g_LevelDirName[];
extern char D_0049C378[];
extern char D_0049C380[];
extern unsigned char D_004EE4E0;
extern unsigned char D_004EE4F0;
extern int D_0048A030;
extern int D_004EE4C8;
extern int D_004EE4D0;
int strcmp(const char* a, const char* b);
void cHudLoading_SetProgress(void* hud, float f);
void XLib_NextFrame(void* p);
void cHudLoading_Render(void* hud);
#if 0 /* merge_units */
int GetTextSystem(void);
#endif /* merge_units */
#define GetTextSystem() ((int)GetTextSystem()) /* merge_units */

void cTextSystem_Render(int a);
void cScreenFader_Render(cScreenFader* f);
void cFont_Display_charP_tRGBAR_int_int_etc(float scale, void* font, const char* s, const tRGBA& c, int x, int y);
void cMachine_ShowLoadingScreen(cMachine* self, const char* strLoading, unsigned char lastMessage);
}

#define RS_00165E60 ((Rs_00165E60*)g_Video)
#define SLOT_00165E60(i) ((Slot_00165E60*)(g_Video + (i) * 0x110))

/* identity-matrix store and 64-byte quad copy: VU0/128-bit moves have no C equivalent */
static inline void UM_00165E60(void* m) { int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void QR_00165E60(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }

extern "C" void cMachine_ShowLoadingScreen(cMachine* self, const char* strLoading, unsigned char lastMessage)
{
    int i;
    {
        int cmp = strcmp(D_0049C380, strLoading ? strLoading : D_0049C378);
        D_004EE4F0 = lastMessage;
        D_004EE4E0 = cmp == 0;
    }
    if (D_0048A030 != -1)
        return;
    {
        int vpi = (int)&D_00539170;
        if (self->hudLoading)
            cHudLoading_SetProgress(self->hudLoading, (float)D_004EE4C8 / (float)D_004EE4D0);
        {
            Slot_00165E60* s = SLOT_00165E60(D_00538C60);
            V4_00165E60* vp = (V4_00165E60*)vpi;
            s->r[0] = vp->x;
            s->r[1] = vp->y;
            s->r[2] = vp->z;
            s->r[3] = vp->w;
            s->f2F5 = 1;
            s->f2F6 = 1;
        }
    }
    {
        Slot_00165E60* s = SLOT_00165E60(D_00538C60);
        s->f2E0 = 0;
        *(int*)&s->f2E8 = 0x3F800000;
        s->f2F6 = 1;
        s->f2F4 = 1;
    }
    QR_00165E60(&RS_00165E60->mtx[D_00538C64 + 1], &RS_00165E60->mtx[D_00538C64]);
    D_00538C64++;
    UM_00165E60(&RS_00165E60->mtx[D_00538C64]);
    D_00538C68 = 1;
    D_005392D8 = D_004BC1B0;
    for (i = 0; i < 3; i++) {
        XLib_NextFrame(g_Video);
        if (self->hudLoading) {
            cHudLoading_Render(self->hudLoading);
            cTextSystem_Render(GetTextSystem());
        } else {
            g_Fader->Enable(1);
            cScreenFader_Render(g_Fader);
            {
                tRGBA kStrCol(1.0f, 1.0f, 1.0f, 1.0f);
                g_DrawMode = 1;
                cFont_Display_charP_tRGBAR_int_int_etc(0.001f, self->font, g_LevelDirName, kStrCol, -280, -160);
                cFont_Display_charP_tRGBAR_int_int_etc(0.001f, self->font, strLoading, kStrCol, -280, -184);
            }
        }
    }
    D_00538C68 = 1;
    D_00538C64--;
    {
        Slot_00165E60* s = SLOT_00165E60(D_00538C60);
        s->f2F6 = 1;
        s->f2F4 = 0;
    }
    g_Fader->active = 0;
    cScreenFader_Render(g_Fader);
}
#undef GetTextSystem /* merge_units */
static inline void merge_flush_func_00165E60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00165E60 */
