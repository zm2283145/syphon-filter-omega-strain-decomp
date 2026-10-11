#include "types.h"
typedef struct { int unk0; int size; unsigned int base; char* cur; } PopReader_1C3940;
extern char D_0048B2F8[];
extern char D_0049F030[];
extern char D_0049F200[];
extern char D_0049F220[];
extern char D_0049F250[];
extern char D_0049F270[];
extern char D_004FFC90[];
extern void func_00165E60(void* a, char* name, int x);
extern void* func_001698C0(void);
extern int sprintf(char* buf, const char* fmt, ...);
extern int Archive_Open(void* a, char* name, int b, int c);
extern void Pop_LoadTER(void* l, void* a1, PopReader_1C3940* r, void* arc);
extern void Loader_InitActivationMap(void* l, PopReader_1C3940* r);
extern void Loader_InitNodes(void* l, PopReader_1C3940* r);
extern void Loader_InitSoundGOBJs(void* l, PopReader_1C3940* r, void* arc);
extern void Pop_LoadGOB(void* l, PopReader_1C3940* r, int h);
extern void Pop_LoadNPC(void* l, PopReader_1C3940* r, void* arc);
extern void Loader_LoadParticles(void* l, PopReader_1C3940* r, void* arc);
extern void Loader_InitSkybox(void* l, void* a1, PopReader_1C3940* r, void* arc);
extern void Loader_InitNIEvents(void* l, PopReader_1C3940* r, int h);
void Pop_LoadMissionSections(void* l, void* a1, PopReader_1C3940* r, void* arc)
{
    if (r->cur) {
        char name[128];
        int h;
        int mis;
        sprintf(name, D_0049F200, D_0048B2F8, D_004FFC90, D_004FFC90);
        h = Archive_Open(arc, name, 1, 0);
        func_00165E60(func_001698C0(), D_0049F220, 0);
        Pop_LoadTER(l, a1, r, arc);
        Loader_InitActivationMap(l, r);
        Loader_InitNodes(l, r);
        Loader_InitSoundGOBJs(l, r, arc);
        Pop_LoadGOB(l, r, h);
        func_00165E60(func_001698C0(), D_0049F250, 0);
        Pop_LoadNPC(l, r, arc);
        func_00165E60(func_001698C0(), D_0049F030, 0);
        Loader_LoadParticles(l, r, arc);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        func_00165E60(func_001698C0(), D_0049F270, 0);
        Loader_InitSkybox(l, a1, r, arc);
        Loader_InitNIEvents(l, r, h);
    }
}