/*
 * main/machine: range (3 files, 00165630-00165BC0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);
int strlen(const char *);

/* merge_units: begin func_00165630 */
#pragma push /* merge_units */
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
