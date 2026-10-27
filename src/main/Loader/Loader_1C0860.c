/*
 * main/Loader: range (5 files, 001C0860-001C0EE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_001C0860 */
#pragma push /* merge_units */
#pragma opt_common_subs off
typedef struct { char* n[3]; } SkNames_c7;
extern SkNames_c7 D_0048A310;
extern char D_0048B2F8[];
extern char D_0053BB70[];
extern int cHogList_OpenProtected(void* a, char* path, int b);
extern int cSkeletonDataBank_AddSkeletonData_charP_cHogFileR(int* out, void* skel, char* name, int hog);
void cLoader_LoadSkeletons(void* self, void* fs) {
    char path[128];
    SkNames_c7 names;
    int out;
    int hog;
    char** p;
    names = D_0048A310;
    sprintf(path, "%s\\COMMON\\SKEL.HOG", D_0048B2F8);
    hog = cHogList_OpenProtected(fs, path, 0);
    for (p = names.n; **p != 0; p++) {
        cSkeletonDataBank_AddSkeletonData_charP_cHogFileR(&out, D_0053BB70, *p, hog);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C0860(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C0860 */

/* merge_units: begin func_001C0920 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct PopReader_1C0920 { int unk0; int size; unsigned int base; char* cur; };
extern "C" {
extern char D_0049EE88[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void nGobjManager_AddGOBJ(void* o);
int cPopulation_SeekBlock(PopReader_1C0920* r, int tag);
void* Camera_ConstructStream(void* p, PopReader_1C0920* r);
void cMachine_ShowLoadingScreen(void* a, char* name, int x);
void* GetMachine(void);
}
extern "C" void cLoader_LoadCameras(void* a0, PopReader_1C0920* r)
{
    if (r->cur) {
        int mis;
        cMachine_ShowLoadingScreen(GetMachine(), "Initializing Populated Cameras...", 0);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        if ((unsigned char)cPopulation_SeekBlock(r, 0x3A4D4143)) {
            int n;
            int i = 0;
            n = *(int*)r->cur;
            r->cur += 4;
            for (; i < n; i++) {
                void* p;
                {
                    AllocGuard g;
                    p = cMemMan_Allocate(0, 0xCF0, D_0049EE88, 0x5C5);
                }
                if (p)
                    p = Camera_ConstructStream(p, r);
                nGobjManager_AddGOBJ(p);
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C0920(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C0920 */

/* merge_units: begin func_001C0A90 */
#pragma push /* merge_units */
#pragma cplusplus on
struct PopReader_1C0A90 { int unk0; int size; unsigned int base; char* cur; };
extern "C" {
#if 0 /* merge_units */
int cPopulation_SeekBlock(PopReader_1C0A90* r, int tag);
#endif /* merge_units */
#define cPopulation_SeekBlock(a0, a1) (cPopulation_SeekBlock((PopReader_1C0920 *)(a0), (a1))) /* merge_units */

void* cFireObj_ctor_cPopulationR(void* p, PopReader_1C0A90* r);
}
extern "C" void cLoader_LoadFireObjs(void* a0, PopReader_1C0A90* r)
{
    if (r->cur) {
        int mis;
        cMachine_ShowLoadingScreen(GetMachine(), "Initializing Fire Objects...", 0);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        if ((unsigned char)cPopulation_SeekBlock(r, 0x3A524946)) {
            int n;
            int i = 0;
            n = *(int*)r->cur;
            r->cur += 4;
            for (; i < n; i++) {
                void* p;
                {
                    AllocGuard g;
                    p = cMemMan_Allocate(0, 0xA0, D_0049EE88, 0x5A2);
                }
                if (p)
                    p = cFireObj_ctor_cPopulationR(p, r);
                nGobjManager_AddGOBJ(p);
            }
        }
    }
}
#undef cPopulation_SeekBlock /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C0A90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C0A90 */

/* merge_units: begin func_001C0C00 */
#pragma push /* merge_units */
typedef struct Pop_001C0C00 { int version; int size; unsigned int base; char* cur; } Pop_001C0C00;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char g_HotboxList[];
void Alloc_Lock(int id);
void EnableIntc(int id);
#if 0 /* merge_units */
void* cMemMan_Allocate(int heap, int size, char* file, int line);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
int GetMachine(void);
#endif /* merge_units */
#define GetMachine() ((int)GetMachine()) /* merge_units */

#if 0 /* merge_units */
void cMachine_ShowLoadingScreen(int a, char* b, int c);
#endif /* merge_units */
#define cMachine_ShowLoadingScreen(a0, a1, a2) (cMachine_ShowLoadingScreen((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
int cPopulation_SeekBlock(Pop_001C0C00* r, int tag);
#endif /* merge_units */
#define cPopulation_SeekBlock(a0, a1) (cPopulation_SeekBlock((void *)(a0), (a1))) /* merge_units */

void* cBuddyHotbox_ctor(void* p, Pop_001C0C00* r);
void* cHotbox_ctor_cPopulationR_int(void* p, Pop_001C0C00* r, int type);
void cLList_cHotboxPtr_PushBackActual(void* vec, void** val);
#if 0 /* merge_units */
void nGobjManager_AddGOBJ(void* p);
#endif /* merge_units */
#define nGobjManager_AddGOBJ(a0) (nGobjManager_AddGOBJ((a0))) /* merge_units */

static inline void Align_001C0C00(Pop_001C0C00* r)
{
    int mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
}
static inline int ReadInt_001C0C00(Pop_001C0C00* r)
{
    int v = *(int*)r->cur;
    r->cur += 4;
    return v;
}
static inline void* Alloc_001C0C00(int size, int line)
{
    void* p;
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    p = cMemMan_Allocate(0, size, D_0049EE88, line);
    if (g_ProfileLockEnabled) EnableIntc(9);
    g_ProfileLockDepth--;
    return p;
}
void cLoader_LoadHotboxes(void* self, Pop_001C0C00* r)
{
    if (r->cur) {
        cMachine_ShowLoadingScreen(GetMachine(), "Initializing Hotboxes...", 0);
        Align_001C0C00(r);
        if ((unsigned char)cPopulation_SeekBlock(r, 0x3A584F42)) {
            int n = ReadInt_001C0C00(r);
            void* p;
            int i;
            for (i = 0; i < n; i++) {
                void* tmp[4];
                if (r->version > 0x35) {
                    int type = ReadInt_001C0C00(r);
                    switch (type) {
                    case 0xC:
                        {
                            void* t = Alloc_001C0C00(0xB0, 0x576);
                            if (t)
                                t = cBuddyHotbox_ctor(t, r);
                            p = t;
                        }
                        break;
                    default:
                        {
                            void* t = Alloc_001C0C00(0xB0, 0x57A);
                            if (t)
                                t = cHotbox_ctor_cPopulationR_int(t, r, type);
                            p = t;
                        }
                        break;
                    }
                } else {
                    {
                        void* t = Alloc_001C0C00(0xB0, 0x57F);
                        if (t)
                            t = cHotbox_ctor_cPopulationR_int(t, r, -1);
                        p = t;
                    }
                }
                tmp[0] = p;
                cLList_cHotboxPtr_PushBackActual(g_HotboxList, tmp);
                nGobjManager_AddGOBJ(p);
            }
        }
    }
}
#undef cMemMan_Allocate /* merge_units */
#undef GetMachine /* merge_units */
#undef cMachine_ShowLoadingScreen /* merge_units */
#undef cPopulation_SeekBlock /* merge_units */
#undef nGobjManager_AddGOBJ /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C0C00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C0C00 */

/* merge_units: begin func_001C0EE0 */
#pragma push /* merge_units */
typedef struct { int unk0; int size; unsigned int base; char* cur; } PopReader_1C0EE0;
typedef struct { int a, b, c; char f; } Inner_1C0EE0;
typedef struct { int cap; int count; char* data; } VV_1C0EE0;
extern int D_004FFBE4;
extern VV_1C0EE0* D_004FFBE8;
#if 0 /* merge_units */
extern int cPopulation_SeekBlock(PopReader_1C0EE0* r, int tag);
#endif /* merge_units */
#define cPopulation_SeekBlock(a0, a1) (cPopulation_SeekBlock((void *)(a0), (a1))) /* merge_units */

extern void cMachine_ShowLoadingScreen(void* a, char* name, int x);
extern void* GetMachine(void);
extern void std_vector_int_ctor_void(Inner_1C0EE0* t);
extern void std_vector_imp_cArray_int_resize(VV_1C0EE0* v, int n, Inner_1C0EE0* fill);
extern void func_0013A040(Inner_1C0EE0* t, int flags);
extern void std_vector_pod_int_reserve(void* v, int n);
extern void std_vector_int_push_back(void* v, int* x);
#pragma opt_strength_reduction off
void cLoader_LoadNodeGroups(void* a0, PopReader_1C0EE0* r)
{
    D_004FFBE4 = 0;
    if (r->cur) {
        int mis;
        cMachine_ShowLoadingScreen(GetMachine(), "Initializing Node Groups...", 0);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        if ((unsigned char)cPopulation_SeekBlock(r, 0x3A505247)) {
            int n;
            n = *(int*)r->cur;
            r->cur += 4;
            if (n) {
                VV_1C0EE0* vv;
                Inner_1C0EE0 tmp;
                int m;
                int i;
                D_004FFBE4 = n;
                vv = D_004FFBE8;
                std_vector_int_ctor_void(&tmp);
                tmp.f = 1;
                std_vector_imp_cArray_int_resize(vv, n, &tmp);
                func_0013A040(&tmp, -1);
                for (i = 0; i < n; i++) {
                    int j;
                    int off = i * 16;
                    m = *(int*)r->cur;
                    r->cur += 4;
                    std_vector_pod_int_reserve(vv->data + off, m);
                    for (j = 0; j < m; j++) {
                        int v[1];
                        v[0] = *(int*)r->cur;
                        r->cur += 4;
                        std_vector_int_push_back(vv->data + off, v);
                    }
                }
            }
        }
    }
}
#pragma opt_strength_reduction reset
#undef cPopulation_SeekBlock /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C0EE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C0EE0 */
