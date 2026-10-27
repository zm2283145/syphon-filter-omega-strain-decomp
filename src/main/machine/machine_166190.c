/*
 * main/machine: range (2 files, 00166190-00166430)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();
int sprintf(void *, const void *, ...);

/* merge_units: begin func_00166190 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);
int EnableIntc(int);
int cFileMan_EncodeFilename_charP_cHogFileR_bool(char *, int, char *, int);
int RemoveIntcHandler(int, int);
int DeleteThread(int);
int TerminateThread(int);
int ChangeThreadPriority(int, int);
int cHudLoading_Deactivate(int);
int cHudLoading_dtor(int, int);
int cHogFile_GetBlockName(char *, int);
int cFileMan_Open(char *);
int cFileMan_dtor(char *, int);
int cFileMan_ctor_void(char *);
int cTexMan_RemoveTextureFromFile(int, char *);
int cHogList_Close(char *, char *);
extern int D_0048A030;
extern int D_0048A038;
extern int D_0048A048;
extern int D_0048A058;
extern char D_0049C390;
extern int D_004EE4E8;
extern int D_004EE500;
extern int D_004EE508;
extern char D_004FFB8C;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern int g_TextureMgr;

typedef struct { char p0[0x148]; int *f148; unsigned char f14C; } M270_00166190;
typedef struct { char p0[624]; M270_00166190 *f270; int f274; } PS0_00166190;
void cMachine_UnloadLoadingScreen(PS0_00166190 *arg0) {
    int sp50[44];
    int n;
    int i;
    int h;

    if (arg0->f274 != 0) {
        if (D_0048A038 != -1) {
            Alloc_Lock(2);
            RemoveIntcHandler(2, D_0048A038);
            D_0048A038 = -1;
        }
        if (D_0048A030 != -1) {
            TerminateThread(D_0048A030);
            DeleteThread(D_0048A030);
            D_0048A030 = -1;
        }
        D_004EE500 = 0;
        D_004EE508 = 0;
        D_0048A058 = -1;
        h = D_004EE4E8;
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        cMemMan_Deallocate(0, h, &D_0049C390, 0x7F3);
        if (g_ProfileLockEnabled != 0) {
            EnableIntc(9);
        }
        D_004EE4E8 = 0;
        g_ProfileLockDepth -= 1;
        ChangeThreadPriority(D_0048A048, 5);
        if (arg0->f274 != 0) {
            cHudLoading_Deactivate(arg0->f274);
            h = arg0->f274;
            if (g_ProfileLockEnabled != 0) {
                Alloc_Lock(9);
            }
            g_ProfileLockDepth += 1;
            cHudLoading_dtor(h, -1);
            cMemMan_Deallocate(0, h, &D_0049C390, 0x7FD);
            if (g_ProfileLockEnabled != 0) {
                EnableIntc(9);
            }
            g_ProfileLockDepth -= 1;
            arg0->f274 = 0;
        }
        if (arg0->f270->f14C != 0) {
            cFileMan_ctor_void((char *)sp50);
            n = arg0->f270->f148[1];
            for (i = 0; i < n; i++) {
                M270_00166190 *m = arg0->f270;
                cFileMan_EncodeFilename_charP_cHogFileR_bool((char *)sp50, cHogFile_GetBlockName((char *)m, i), (char *)m, 0);
                cFileMan_Open((char *)sp50);
                cTexMan_RemoveTextureFromFile(g_TextureMgr, (char *)sp50);
            }
            cHogList_Close(&D_004FFB8C, (char *)arg0->f270);
            cFileMan_dtor((char *)sp50, -1);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00166190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00166190 */

/* merge_units: begin func_00166430 */
#pragma push /* merge_units */
#pragma mpwc_relax on
                                  
int cHogList_Open(char *, int, int, int);                     
int nGlobalization_GetString_charP(char *);                            
int cMemMan_Allocate(int, int, char *, int);                        
int atoi(signed char *);                            
int RegisterVBLANKHandler();                                  
int RegisterVBLANKThread(char *);                               
int cHudLoading_SetProgress(int, float);                            
int cHudLoading_Activate(int);                               
int cHudLoading_ctor(int, int, char *);                            
int cFileMan_ctor_charP_cFileIOP_bool(char *, int, int, int);                    
signed char *cSFOini_GetKeyValue(char *);                             
int cHogList_Get(char *, int);
extern int D_004EE4C8;
extern int D_004EE4D0;
extern signed char D_004EE4D8;
extern int D_004EE510;
extern int D_004EE518;
extern char g_LevelDirName;
extern char loadingThread;

typedef struct { char p0[624]; int f270; int f274; char p278[8]; int f280; } PS0_00166430;
void cMachine_SetLoadingScreen(PS0_00166430 *arg0, int d1, int arg2) {
    int spC0[40];
    int sp40[32];
    int var_s2;
    signed char *temp_v0;

    if (arg2 != 0) {
        cFileMan_ctor_charP_cFileIOP_bool(spC0, arg2, 0, 0);
        if (!(cFileMan_Open(spC0) & 0xFF)) {
            cHogList_Open(&D_004FFB8C, arg2, 0, 1);
            arg0->f270 = cHogList_Get(&D_004FFB8C, arg2);
            if (g_ProfileLockEnabled != 0) {
                Alloc_Lock(9);
            }
            g_ProfileLockDepth += 1;
            var_s2 = cMemMan_Allocate(0, 0x3C, &D_0049C390, 0x7A9);
            if (g_ProfileLockEnabled != 0) {
                EnableIntc(9);
            }
            g_ProfileLockDepth -= 1;
            if (var_s2 != 0) {
                var_s2 = cHudLoading_ctor(var_s2, arg0->f270, "loading_screen");
            }
            arg0->f274 = var_s2;
            cHudLoading_Activate(arg0->f274);
            cHudLoading_SetProgress(arg0->f274, 0.0f);
        }
        cFileMan_dtor(spC0, -1);
    }
    if (arg2 != 0) {
        D_004EE500 = arg0->f274;
        D_004EE508 = arg0->f280;
        D_004EE518 = nGlobalization_GetString_charP("LoadingText");
        D_004EE510 = nGlobalization_GetString_charP("Continue");
        RegisterVBLANKThread(&loadingThread);
    }
    RegisterVBLANKHandler();
    sprintf(sp40, "%s_LOADINGFRAMES", &g_LevelDirName);
    temp_v0 = cSFOini_GetKeyValue(sp40);
    if ((temp_v0 == NULL) || (*temp_v0 == 0)) {
        D_004EE4D8 = 0;
        D_004EE4D0 = 0x4B0;
    } else {
        D_004EE4D0 = atoi(temp_v0);
        D_004EE4D8 = 1;
    }
    D_004EE4C8 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00166430(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00166430 */
