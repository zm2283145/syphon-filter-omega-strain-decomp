/*
 * SFOGame/Source/game: 2 files, 001303F0-00130520
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001303F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
char * cMemMan_Allocate(...);                      
int strncpy(...);                            
extern char D_0049A890;
extern unsigned char g_ProfileLockEnabled;
}
typedef struct { char p0[172]; int fAC; } PS0_001303F0;
#pragma push
#pragma opt_common_subs off
extern "C" void cGameSystem_QueueMovie(PS0_001303F0 *arg0, int arg1) {
    char * temp_a0;
    char * temp_s0;
    int var_a1;
    int temp_v1;
    char * var_a0;

    if (arg0->fAC == NULL) {
        {
            AllocGuard g;
        temp_s0 = (char *)(cMemMan_Allocate(0, 0x808, &D_0049A890, 0x9FD));
        }
        if (temp_s0 != NULL) {
            var_a1 = 0;
            var_a0 = temp_s0;
            do {
                F_(var_a0, 0x0, signed char) = 0;
                F_(var_a0, 0x80, signed char) = 0;
                var_a1 += 8;
                F_(var_a0, 0x100, signed char) = 0;
                F_(var_a0, 0x180, signed char) = 0;
                F_(var_a0, 0x200, signed char) = 0;
                F_(var_a0, 0x280, signed char) = 0;
                F_(var_a0, 0x300, signed char) = 0;
                F_(var_a0, 0x380, signed char) = 0;
                var_a0 += 0x400;
            } while (var_a1 < 0x10);
            F_(temp_s0, 0x804, int) = 0;
            F_(temp_s0, 0x800, int) = 0;
        }
        arg0->fAC = (int)(temp_s0);
    }
    temp_a0 = (char *)(arg0->fAC);
    temp_v1 = F_(temp_a0, 0x804, int);
    if (temp_v1 < 0x10) {
        F_(temp_a0, 0x804, int) = (int) (temp_v1 + 1);
        strncpy(temp_a0 + (temp_v1 << 7), arg1, 0x80);
    }
}
#pragma pop
static inline void merge_flush_func_001303F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001303F0 */

/* merge_units: begin func_00130520 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x3C]; char f3c[0x24]; char pad2; unsigned char b61; char pad3[0x4E]; void* fb0; } O130;
typedef struct { int a[0x24]; } H130;
extern "C" {
extern int cSystemContainer_GetSystem(O130*, char*);
extern char D_004F2CC0[];
extern int D_004EA048;
extern char D_0049A950[];
#if 0 /* merge_units */
extern char D_0049A890[];
#endif /* merge_units */
#define D_0049A890 ((char*)&D_0049A890) /* merge_units */

extern int func_001C94D0(int, int);
extern void cGameSound_SetMasterVolume(int, int, int);
extern void cMemMan_ReleaseBin(int);
extern void cMemMan_Init_int_uint_uint(int, int, int);
extern void cFileMan_ctor_void(H130*);
extern int sprintf(char*, const char*, ...);
extern int cHogList_Open(char*, char*, int, int);
extern void cFileMan_EncodeFilename_charP_cHogFileR_bool(H130*, void*, int, int);
extern void cFileMan_EncodeFilename_charP_cFileIOP_bool(H130*, void*, int, int);
extern int Loc_GetLanguage(void);
extern void Subtitles_SelectTrack(int);
extern void Subtitles_SetEnabled(int);
#if 0 /* merge_units */
extern void* cMemMan_Allocate(int, int, char*, int);
#endif /* merge_units */

extern void* cMoviePlayer_ctor(void*, H130*, unsigned char);
extern void cFileMan_dtor(H130*, int);
}
extern "C" void GameFlow_StartMovie(O130* o, void* name, unsigned char flag) {
    int svc;
    if (!o->b61) return;
    svc = cSystemContainer_GetSystem(o, D_004F2CC0);
    D_004EA048 = func_001C94D0(svc, 2);
    cGameSound_SetMasterVolume(svc, 2, 0x400);
    if (!o->fb0) {
        H130 hog;
        int lang;
        unsigned char l;
        int sel;
        void* p;
        cMemMan_ReleaseBin(1);
        cMemMan_Init_int_uint_uint(1, 0x700000, 0x800);
        cFileMan_ctor_void(&hog);
        if (flag == 1) {
            char buf[0x80];
            sprintf(buf, D_0049A950);
            cFileMan_EncodeFilename_charP_cHogFileR_bool(&hog, name, cHogList_Open(o->f3c, buf, 1, 0), 0);
        } else {
            cFileMan_EncodeFilename_charP_cFileIOP_bool(&hog, name, 0, 0);
        }
        lang = Loc_GetLanguage();
        l = lang;
        switch (l) {
        case 6: sel = 6; break;
        case 2: sel = 2; break;
        case 5: sel = 3; break;
        case 4: sel = 5; break;
        case 3: sel = 4; break;
        case 0: sel = 1; break;
        case 1: sel = 1; break;
        default: sel = 0; break;
        }
        if (l) {
            Subtitles_SelectTrack((unsigned char)lang);
            Subtitles_SetEnabled(1);
        } else {
            Subtitles_SelectTrack(-1);
            Subtitles_SetEnabled(0);
        }
        {
            AllocGuard g;
            p = cMemMan_Allocate(0, 0x238, D_0049A890, 0x9F3);
        }
        if (p) p = cMoviePlayer_ctor(p, &hog, sel);
        o->fb0 = p;
        cFileMan_dtor(&hog, -1);
    }
}
#undef D_0049A890 /* merge_units */
static inline void merge_flush_func_00130520(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00130520 */
