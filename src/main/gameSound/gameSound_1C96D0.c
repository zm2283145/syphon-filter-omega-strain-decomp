/*
 * main/gameSound: range (5 files, 001C96D0-001C9D00)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_001C96D0 */
#pragma push /* merge_units */
extern void snd_ContinueAllSoundsInGroup(int);
extern void snd_PauseAllSoundsInGroup(int);

void SoundMgr_SetGroupsPaused(int a0, int a1) {
    int cond;

    cond = a1 == 0;
    if (cond) goto L001C96F0;
    a0 = 0 + -1;
    snd_PauseAllSoundsInGroup(a0);
    goto L001C96F8;
L001C96F0:;
    a0 = 0 + -1;
    snd_ContinueAllSoundsInGroup(a0);
L001C96F8:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C96D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C96D0 */

/* merge_units: begin func_001C9710 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
typedef struct { char pad[0x90]; void* ptr; unsigned char flag; char pad2[0x1B0 - 0x95]; } E1C9710;
extern void snd_StopAllSounds(void);
extern void snd_StopAllStreams(void);
extern void snd_CloseVAGStreaming(void);
extern void snd_UnloadBank(int);
extern int snd_FlushSoundCommands(void);
extern void cHogList_Close(void* a, char* name);
extern char D_0048B2F8[];
extern char D_004FFB8C[];
extern char g_LevelDirName[];
extern char D_0049F550[];
extern char D_0049F570[];
extern char D_0049F590[];
#pragma opt_propagation off
void cGameSound_Unload(char* arg0) {
    int i;
    snd_StopAllSounds();
    snd_StopAllStreams();
    snd_CloseVAGStreaming();
    {
        E1C9710* e;
        i = 0;
        e = (E1C9710*)arg0;
        do {
            e[0].flag = 0; e[0].ptr = 0;
            i += 8;
            e[1].flag = 0; e[1].ptr = 0;
            e[2].flag = 0; e[2].ptr = 0;
            e[3].flag = 0; e[3].ptr = 0;
            e[4].flag = 0; e[4].ptr = 0;
            e[5].flag = 0; e[5].ptr = 0;
            e[6].flag = 0; e[6].ptr = 0;
            e[7].flag = 0; e[7].ptr = 0;
            e += 8;
        } while (i < 42);
        e = &((E1C9710*)arg0)[i];
        e[0].flag = 0; e[0].ptr = 0;
        e[1].flag = 0; e[1].ptr = 0;
    }
    if (F_(arg0, 0x5494, int)) snd_UnloadBank(F_(arg0, 0x5494, int));
    if (F_(arg0, 0x5490, int)) snd_UnloadBank(F_(arg0, 0x5490, int));
    if (F_(arg0, 0x5498, int)) snd_UnloadBank(F_(arg0, 0x5498, int));
    if (F_(arg0, 0x549C, int)) snd_UnloadBank(F_(arg0, 0x549C, int));
    while (snd_FlushSoundCommands()) {
    }
    {
    char a[0x80];
    char b[0x80];
    char c[0x80];
    char* fs = D_004FFB8C;
    sprintf(a, D_0049F550, D_0048B2F8, g_LevelDirName);
    sprintf(b, D_0049F570);
    sprintf(c, D_0049F590, g_LevelDirName);
    cHogList_Close(fs, a);
    cHogList_Close(fs, b);
    cHogList_Close(fs, c);
    }
    F_(arg0, 0x54A8, int) = 0;
    F_(arg0, 0x54AC, int) = 0;
    F_(arg0, 0x54B0, int) = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C9710(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C9710 */

/* merge_units: begin func_001C98D0 */
#pragma push /* merge_units */
typedef struct Arc1C98D0 {
    char pad0[0x84];
    int f84;
    char pad88[0x148 - 0x88];
    char* f148;
    unsigned char f14C;
} Arc1C98D0;

extern Arc1C98D0* cHogList_Open(void* a, char* name, int b, int c);
extern char* Loc_GetLanguageSuffix(void);
extern int cHogFile_GetBlockIndex(Arc1C98D0* a, char* name, int c);
extern int cHogFile_GetBlockOffset(Arc1C98D0* a, int idx);
extern void snd_SetVAGStreamChannelRange(int, int, int);
extern void snd_InitVAGStreamingEx(int, int, int, int);
extern void snd_ResolveBankXREFS(void);
extern int cHogList_Get(void* a, char* name);
extern int snd_BankLoadByLoc(int loc, int size);
extern signed char D_0048A330;

int cGameSound_Load(char* arg0) {
    char snd[0x80];
    char vag[0x80];
    char vagloc[0x80];
    char music[0x80];
    char* fs = D_004FFB8C;
    Arc1C98D0* arc;

    snd_InitVAGStreamingEx(4, 0xE000, 1, 1);
    D_0048A330 = 1;
    snd_SetVAGStreamChannelRange(1, 0, 1);
    snd_SetVAGStreamChannelRange(2, 2, 2);
    snd_SetVAGStreamChannelRange(0xE, 2, 2);
    sprintf(snd, "%s\\%s\\SND.HOG", D_0048B2F8, g_LevelDirName);
    sprintf(vag, "%s\\%s\\SNDVAG.HOG%s", D_0048B2F8, g_LevelDirName, Loc_GetLanguageSuffix());
    sprintf(vagloc, "ZMEDIA\\SNDVAG%s.HOG", Loc_GetLanguageSuffix());
    sprintf(music, D_0049F590);
    arc = cHogList_Open(fs, snd, 1, 0);
    if (arc->f14C) {
        if (cHogFile_GetBlockIndex(arc, "WEPS.BNK", 0) != -1) {
            F_(arg0, 0x5494, int) = snd_BankLoadByLoc(arc->f84, F_(arc->f148, 0x10, int) + cHogFile_GetBlockOffset(arc, cHogFile_GetBlockIndex(arc, "WEPS.BNK", 0)));
        }
        if (cHogFile_GetBlockIndex(arc, "ENVIRON.BNK", 0) != -1) {
            F_(arg0, 0x5490, int) = snd_BankLoadByLoc(arc->f84, F_(arc->f148, 0x10, int) + cHogFile_GetBlockOffset(arc, cHogFile_GetBlockIndex(arc, "ENVIRON.BNK", 0)));
        }
        if (cHogFile_GetBlockIndex(arc, "VOX.BNK", 0) != -1) {
            F_(arg0, 0x5498, int) = snd_BankLoadByLoc(arc->f84, F_(arc->f148, 0x10, int) + cHogFile_GetBlockOffset(arc, cHogFile_GetBlockIndex(arc, "VOX.BNK", 0)));
        }
        if (cHogFile_GetBlockIndex(arc, "SHELL.BNK", 0) != -1) {
            F_(arg0, 0x549C, int) = snd_BankLoadByLoc(arc->f84, F_(arc->f148, 0x10, int) + cHogFile_GetBlockOffset(arc, cHogFile_GetBlockIndex(arc, "SHELL.BNK", 0)));
        }
        cHogList_Close(fs, snd);
        cHogList_Open(fs, vag, 1, 0);
        F_(arg0, 0x54A8, int) = cHogList_Get(fs, vag);
        cHogList_Open(fs, vagloc, 1, 0);
        F_(arg0, 0x54AC, int) = cHogList_Get(fs, vagloc);
        cHogList_Open(fs, music, 1, 0);
        F_(arg0, 0x54B0, int) = cHogList_Get(fs, music);
    }
    snd_ResolveBankXREFS();
    while (snd_FlushSoundCommands()) {
    }
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C98D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C98D0 */

/* merge_units: begin func_001C9BF0 */
#pragma push /* merge_units */
#define NULL 0
#pragma mpwc_relax on
int snd_SetReverbDepth(int, int, int);                        
int snd_SetReverbType(int, int);                              
int snd_SetPlaybackMode(int, int);                          
int snd_SetMasterVolumeDucker(int, int *);                          
extern char * g_OptionsRecord;

void cGameSound_Init(char * arg0) {
    struct { int f10; int f14; int f18; int f1C; int f20; int f24[3]; } sl;
    int var_a1;
    char * temp_v0;
    char * var_v1;

    var_a1 = 0;
    var_v1 = arg0;
    F_(arg0, 0x5490, int) = 0;
    F_(arg0, 0x5494, int) = 0;
    F_(arg0, 0x5498, int) = 0;
    F_(arg0, 0x549C, int) = 0;
    F_(arg0, 0x54A0, int) = 0;
    F_(arg0, 0x54A4, int) = 0;
    do {
        F_(var_v1, 0x94, signed char) = 0;
        F_(var_v1, 0x90, int) = 0;
        var_a1 += 8;
        F_(var_v1, 0x244, signed char) = 0;
        F_(var_v1, 0x240, int) = 0;
        F_(var_v1, 0x3F4, signed char) = 0;
        F_(var_v1, 0x3F0, int) = 0;
        F_(var_v1, 0x5A4, signed char) = 0;
        F_(var_v1, 0x5A0, int) = 0;
        F_(var_v1, 0x754, signed char) = 0;
        F_(var_v1, 0x750, int) = 0;
        F_(var_v1, 0x904, signed char) = 0;
        F_(var_v1, 0x900, int) = 0;
        F_(var_v1, 0xAB4, signed char) = 0;
        F_(var_v1, 0xAB0, int) = 0;
        F_(var_v1, 0xC64, signed char) = 0;
        F_(var_v1, 0xC60, int) = 0;
        var_v1 += 0xD80;
    } while (var_a1 < 0x2A);
    temp_v0 = (char *)(var_a1 * 0x1B0) + (int)(arg0);
    F_(temp_v0, 0x94, signed char) = 0;
    F_(temp_v0, 0x90, int) = 0;
    F_(temp_v0, 0x244, signed char) = 0;
    F_(temp_v0, 0x240, int) = 0;
    snd_SetPlaybackMode(F_(g_OptionsRecord, 0x14, int), var_a1);
    snd_SetReverbType(1, 4);
    snd_SetReverbDepth(1, 0xB21, 0xB21);
    sl.f10 = 2;
    sl.f24[0] = 0;
    sl.f14 = -0xD;
    sl.f1C = 0x8000;
    sl.f18 = 0x8CCC;
    sl.f20 = 0x10000;
    snd_SetMasterVolumeDucker(0, &sl.f10);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C9BF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C9BF0 */

/* merge_units: begin func_001C9D00 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
int* cMessage_Name(void* msg);
extern int D_004F5370;
extern int D_004F5378;
extern int D_005436B0;
extern int g_PlaySndMsgClass;
extern int D_004F53C8;
extern int D_004F53D8;
extern int D_004F53E8;
#if 0 /* merge_units */
void cGameSound_Init(void*);
#endif /* merge_units */
#define cGameSound_Init(a0) (cGameSound_Init((char *)(a0))) /* merge_units */

#if 0 /* merge_units */
int cGameSound_Load(void*);
#endif /* merge_units */
#define cGameSound_Load(a0) (cGameSound_Load((char *)(a0))) /* merge_units */

void cGameSound_NextFrame(void*);
void cGameSound_PlaySound(void*, void*);
void cGameSound_StopSound(void*, void*);
void cGameSound_PauseMusic(void*, unsigned char);
int cSystem_HandleMessage(void*, void*);
}
struct Msg { char pad[0x24]; unsigned char b24; char pad2[0xB]; char data[1]; };
extern "C" unsigned char cGameSound_HandleMessage(void* self, Msg* msg)
{
    unsigned char r = 1;
    int t = *cMessage_Name(msg);
    if (t == D_004F5370) {
        cGameSound_Init(self);
    } else if (t = *cMessage_Name(msg), t == D_004F5378) {
        cGameSound_Load(self);
    } else if (t = *cMessage_Name(msg), t == D_005436B0) {
        cGameSound_NextFrame(self);
    } else if (t = *cMessage_Name(msg), t == g_PlaySndMsgClass) {
        cGameSound_PlaySound(self, msg->data);
    } else if (t = *cMessage_Name(msg), t == D_004F53C8) {
        cGameSound_PlaySound(self, msg->data);
    } else if (t = *cMessage_Name(msg), t == D_004F53D8) {
        cGameSound_StopSound(self, msg->data);
    } else if (t = *cMessage_Name(msg), t == D_004F53E8) {
        cGameSound_PauseMusic(self, msg->b24);
    } else {
        r = cSystem_HandleMessage(self, msg);
    }
    return r;
}
#undef cGameSound_Init /* merge_units */
#undef cGameSound_Load /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C9D00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C9D00 */
