/*
 * SFOGame/Source/game: 1 file, 00130520
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00130520 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { char pad[0x3C]; char f3c[0x24]; char pad2; unsigned char b61; char pad3[0x4E]; void* fb0; } O130;
typedef struct { int a[0x24]; } H130;
extern "C" {
extern int cSystemContainer_GetSystem(O130*, char*);
extern char D_004F2CC0[];
extern int D_004EA048;
extern char D_0049A950[];
extern char D_0049A890[];
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
extern void* cMemMan_Allocate(int, int, char*, int);
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
static inline void merge_flush_func_00130520(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00130520 */
