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

extern void func_003CBE90(char* name);
extern void func_0045A700(int);
extern char* GameIni_GetString(char* key);
extern void printf(char* fmt, ...);
extern int String_CompareNoCase(char* a, char* b);
extern int String_CompareN(char* a, char* b, int n);
extern int atoi(char*);
extern void Language_FromSystem(int);
extern char* Loc_GetLanguageName(unsigned char id);
extern void Loc_SetLanguage(unsigned char id);
extern char* Loc_GetCurrentLanguageName(void);
extern int strstr(char* a, char* b);

extern int D_004FFD2C;
extern char D_004FFBB5;
extern char D_004FFBB1;
extern int D_00494188;

void Game_LoadIni(Game* g) {
    char* s;
    char* v;
    int i;
    int ukEnglish;
    int j;

    func_003CBE90("SFO_GAME.INI");
    func_0045A700(D_004FFD2C);
    { char* mode = GameIni_GetString("BOOT_VIDEOMODE"); printf("videomode: %s\n", mode); }
    { int pal = String_CompareNoCase(GameIni_GetString("BOOT_VIDEOMODE"), "PAL") == 0; if (pal) {
        g->videoMode = 2;
        g->width = 0x280;
        g->height = 0x200;
        g->fps = 0x32;
    } else { int pro = String_CompareNoCase(GameIni_GetString("BOOT_VIDEOMODE"), "PROSCAN") == 0; if (pro) {
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
    { char* net = GameIni_GetString("NET_BUFFER_SIZE");
    if (strlen(net) != 0) {
        D_00494188 = atoi(net);
    } }
    /* retail "1" is an 8-byte, 8-aligned literal: a 4-byte wide string */
    ukEnglish = String_CompareNoCase(GameIni_GetString("BOOT_USE_UK_ENGLISH"), (char*)L"1") == 0;
    s = GameIni_GetString("BOOT_LANGUAGE");
    if (s && *s) {
        if (String_CompareNoCase(s, "PS2_SETTING") == 0) {
            Language_FromSystem(ukEnglish);
        } else {
            for (i = 0; i < 7; i++) {
                if (String_CompareNoCase(s, Loc_GetLanguageName(i)) == 0) {
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
    v = GameIni_GetString("BOOT_VALID_LANGUAGES");
    if (v && *v) {
        if (strstr(v, Loc_GetCurrentLanguageName()) == 0) {
            for (j = 0; j < 7; j++) {
                char* name = Loc_GetLanguageName(j);
                if (String_CompareN(v, name, strlen(name)) == 0) {
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
extern R165* Archive_Open(void*, char*, int, int);
extern void Font_LoadFnt(int, R165*, int);
extern int* TextManager_Get(void);
extern I165 D_0048A060;
extern char D_0048B2F8[];
extern char D_0049C360[];
extern char D_004FFB8C[];
extern int D_00533868;
extern int D_0055A278;
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

void Boot_LoadFonts(O165* o) {
    char buf[0x50];
    I165 I165 = D_0048A060;
    R165* r;
    int i;
    int x;
    sprintf(buf, D_0049C360, D_0048B2F8);
    r = Archive_Open(D_004FFB8C, buf, 0, 0);
    for (i = 0; i < 3; i++) {
        Font_LoadFnt(o->i280[i], r, I165.v[i]);
    }
    x = o->i280[0];
    *TextManager_Get() = x;
    o->i248 = x;
    D_00533868 = x;
    D_0055A278 = o->i280[1];
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
int NetMsgTypes_RegisterAll();                        
int ObjectiveNet_Setup();                             
int func_0016A690();                                  
int func_00170080();                                  
int func_0020E420();                                  
int func_0020E950();                                  
int func_0020EE70();                                  
int func_0020F540();                                  
int func_002107F0();                                  
int func_00211540();                                  
int func_00211820();                                  
int func_002120D0();                                  
int func_00212920();                                  
int func_0021D190();                                  
int func_0021D600();                                  
int func_0022E240();                                  
int func_0022E420();                                  
int func_0022E5E0();                                  
int func_0023F890();                                  
int func_0023FAA0();                                  
int func_0025DFF0();                                  
int func_0025E330();                                  
int cAIUnconsciousMsg_NetRegister();                                  
int cAIDisguiseTakenMsg_NetRegister();                                  
int cAIBodyMovedMsg_NetRegister();                                  
int cAINewAwarenessMsg_NetRegister();                                  
int cAIDestinationReachedMsg_NetRegister();                                  
int cAIWaypointReachedMsg_NetRegister();                                  
int cAIDeadMsg_NetRegister();                                  
int cAIDeactivatedMsg_NetRegister();                                  
int cAIActivatedMsg_NetRegister();                                  
int func_00282240();                                  
int func_002C5270();                                  
int func_002C5AC0();                                  
int func_002C64D0();                                  
int func_002C7460();                                  
int func_002C7560();                                  
int func_002C7A00();                                  
int func_002D0FE0();                                  
int func_002D16E0();                                  
int func_002D1940();                                  
int func_002D2850();                                  
int func_002D7020();                                  
int func_002D78C0();                                  
int func_00316550();                                  
int func_00316860();                                  
int func_00316BB0();                                  
int func_003240C0();                                  
int Iop_LoadNetModules(int);                                 
int func_0042AF00();                                  
extern unsigned char D_004EE530;
extern signed char D_0051EEA0;
extern unsigned char D_0051EEA8;
extern unsigned char D_005723D0;

void App_InitSystemsOnce(void) {
    if (D_004EE530 == 0) {
        D_004EE530 = 1;
        Iop_LoadNetModules(1);
        if (D_0051EEA8 == 0) {
            D_0051EEA0 = 1;
            func_0042AF00();
        }
    }
    if (D_005723D0 == 0) {
        func_002D1940();
        func_002C7A00();
        func_002D78C0();
        func_002D0FE0();
        func_002D16E0();
        ObjectiveNet_Setup();
        func_00316BB0();
        func_0025E330();
        func_0025DFF0();
        func_0021D600();
        func_0021D190();
        cAIDeadMsg_NetRegister();
        cAIDeactivatedMsg_NetRegister();
        cAIActivatedMsg_NetRegister();
        cAIWaypointReachedMsg_NetRegister();
        cAIDestinationReachedMsg_NetRegister();
        cAINewAwarenessMsg_NetRegister();
        cAIBodyMovedMsg_NetRegister();
        cAIUnconsciousMsg_NetRegister();
        cAIDisguiseTakenMsg_NetRegister();
        func_0020E420();
        func_0020F540();
        func_0020EE70();
        func_0020E950();
        func_002C64D0();
        func_002C5270();
        func_00316860();
        func_003240C0();
        func_0023FAA0();
        func_0023F890();
        func_002D7020();
        func_002C5AC0();
        func_0022E240();
        func_0022E420();
        func_0022E5E0();
        func_002D2850();
        func_00170080();
        func_00211820();
        func_00211540();
        func_002120D0();
        func_00212920();
        func_00316550();
        func_002107F0();
        func_0016A690();
        func_002C7460();
        func_002C7560();
        func_00282240();
        NetMsgTypes_RegisterAll();
        D_005723D0 = 1;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00165BC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00165BC0 */
