#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { char pad[0x3C]; char f3c[0x24]; char pad2; unsigned char b61; char pad3[0x4E]; void* fb0; } O130;
typedef struct { int a[0x24]; } H130;
extern "C" {
extern int Service_Lookup(O130*, char*);
extern char D_004F2CC0[];
extern int D_004EA048;
extern char D_0049A950[];
extern char D_0049A890[];
extern int func_001C94D0(int, int);
extern void SoundMgr_SetChannelVolume(int, int, int);
extern void Heap_ReleaseSlot(int);
extern void Heap_AllocSlot(int, int, int);
extern void Resource_Construct(H130*);
extern int sprintf(char*, const char*, ...);
extern int Archive_Open(char*, char*, int, int);
extern void Hog_Register(H130*, void*, int, int);
extern void func_0036E140(H130*, void*, int, int);
extern int Loc_GetLanguage(void);
extern void Subtitles_SelectTrack(int);
extern void Subtitles_SetEnabled(int);
extern void* Mem_Alloc(int, int, char*, int);
extern void* MoviePlayer_ctor(void*, H130*, unsigned char);
extern void FileMan_Release(H130*, int);
}
extern "C" void GameFlow_StartMovie(O130* o, void* name, unsigned char flag) {
    int svc;
    if (!o->b61) return;
    svc = Service_Lookup(o, D_004F2CC0);
    D_004EA048 = func_001C94D0(svc, 2);
    SoundMgr_SetChannelVolume(svc, 2, 0x400);
    if (!o->fb0) {
        H130 hog;
        int lang;
        unsigned char l;
        int sel;
        void* p;
        Heap_ReleaseSlot(1);
        Heap_AllocSlot(1, 0x700000, 0x800);
        Resource_Construct(&hog);
        if (flag == 1) {
            char buf[0x80];
            sprintf(buf, D_0049A950);
            Hog_Register(&hog, name, Archive_Open(o->f3c, buf, 1, 0), 0);
        } else {
            func_0036E140(&hog, name, 0, 0);
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
            p = Mem_Alloc(0, 0x238, D_0049A890, 0x9F3);
        }
        if (p) p = MoviePlayer_ctor(p, &hog, sel);
        o->fb0 = p;
        FileMan_Release(&hog, -1);
    }
}
