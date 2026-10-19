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
extern int func_003F96B0(void* a, char* path, int b);
extern int Skel_Load(int* out, void* skel, char* name, int hog);
void Skel_LoadCommonModels(void* self, void* fs) {
    char path[128];
    SkNames_c7 names;
    int out;
    int hog;
    char** p;
    names = D_0048A310;
    sprintf(path, "%s\\COMMON\\SKEL.HOG", D_0048B2F8);
    hog = func_003F96B0(fs, path, 0);
    for (p = names.n; **p != 0; p++) {
        Skel_Load(&out, D_0053BB70, *p, hog);
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
void* Mem_Alloc(int pool, int size, char* file, int line);
void Object_Register(void* o);
int Pop_FindTag(PopReader_1C0920* r, int tag);
void* Camera_ConstructStream(void* p, PopReader_1C0920* r);
void Loader_UpdateLoadingScreen(void* a, char* name, int x);
void* App_GetInstance(void);
}
extern "C" void Loader_InitPopulatedCameras(void* a0, PopReader_1C0920* r)
{
    if (r->cur) {
        int mis;
        Loader_UpdateLoadingScreen(App_GetInstance(), "Initializing Populated Cameras...", 0);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        if ((unsigned char)Pop_FindTag(r, 0x3A4D4143)) {
            int n;
            int i = 0;
            n = *(int*)r->cur;
            r->cur += 4;
            for (; i < n; i++) {
                void* p;
                {
                    AllocGuard g;
                    p = Mem_Alloc(0, 0xCF0, D_0049EE88, 0x5C5);
                }
                if (p)
                    p = Camera_ConstructStream(p, r);
                Object_Register(p);
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
int Pop_FindTag(PopReader_1C0A90* r, int tag);
#endif /* merge_units */
#define Pop_FindTag(a0, a1) (Pop_FindTag((PopReader_1C0920 *)(a0), (a1))) /* merge_units */

void* cFireObj_ctor2(void* p, PopReader_1C0A90* r);
}
extern "C" void Loader_InitFireObjects(void* a0, PopReader_1C0A90* r)
{
    if (r->cur) {
        int mis;
        Loader_UpdateLoadingScreen(App_GetInstance(), "Initializing Fire Objects...", 0);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        if ((unsigned char)Pop_FindTag(r, 0x3A524946)) {
            int n;
            int i = 0;
            n = *(int*)r->cur;
            r->cur += 4;
            for (; i < n; i++) {
                void* p;
                {
                    AllocGuard g;
                    p = Mem_Alloc(0, 0xA0, D_0049EE88, 0x5A2);
                }
                if (p)
                    p = cFireObj_ctor2(p, r);
                Object_Register(p);
            }
        }
    }
}
#undef Pop_FindTag /* merge_units */
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
void Alloc_Unlock(int id);
#if 0 /* merge_units */
void* Mem_Alloc(int heap, int size, char* file, int line);
#endif /* merge_units */
#define Mem_Alloc(a0, a1, a2, a3) (Mem_Alloc((a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
int App_GetInstance(void);
#endif /* merge_units */
#define App_GetInstance() ((int)App_GetInstance()) /* merge_units */

#if 0 /* merge_units */
void Loader_UpdateLoadingScreen(int a, char* b, int c);
#endif /* merge_units */
#define Loader_UpdateLoadingScreen(a0, a1, a2) (Loader_UpdateLoadingScreen((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
int Pop_FindTag(Pop_001C0C00* r, int tag);
#endif /* merge_units */
#define Pop_FindTag(a0, a1) (Pop_FindTag((void *)(a0), (a1))) /* merge_units */

void* TriggerZone_ctor(void* p, Pop_001C0C00* r);
void* cHotbox_ctor(void* p, Pop_001C0C00* r, int type);
void Hotbox_AddToGlobalList(void* vec, void** val);
#if 0 /* merge_units */
void Object_Register(void* p);
#endif /* merge_units */
#define Object_Register(a0) (Object_Register((a0))) /* merge_units */

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
    p = Mem_Alloc(0, size, D_0049EE88, line);
    if (g_ProfileLockEnabled) Alloc_Unlock(9);
    g_ProfileLockDepth--;
    return p;
}
void Loader_InitHotboxes(void* self, Pop_001C0C00* r)
{
    if (r->cur) {
        Loader_UpdateLoadingScreen(App_GetInstance(), "Initializing Hotboxes...", 0);
        Align_001C0C00(r);
        if ((unsigned char)Pop_FindTag(r, 0x3A584F42)) {
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
                                t = TriggerZone_ctor(t, r);
                            p = t;
                        }
                        break;
                    default:
                        {
                            void* t = Alloc_001C0C00(0xB0, 0x57A);
                            if (t)
                                t = cHotbox_ctor(t, r, type);
                            p = t;
                        }
                        break;
                    }
                } else {
                    {
                        void* t = Alloc_001C0C00(0xB0, 0x57F);
                        if (t)
                            t = cHotbox_ctor(t, r, -1);
                        p = t;
                    }
                }
                tmp[0] = p;
                Hotbox_AddToGlobalList(g_HotboxList, tmp);
                Object_Register(p);
            }
        }
    }
}
#undef Mem_Alloc /* merge_units */
#undef App_GetInstance /* merge_units */
#undef Loader_UpdateLoadingScreen /* merge_units */
#undef Pop_FindTag /* merge_units */
#undef Object_Register /* merge_units */
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
extern int Pop_FindTag(PopReader_1C0EE0* r, int tag);
#endif /* merge_units */
#define Pop_FindTag(a0, a1) (Pop_FindTag((void *)(a0), (a1))) /* merge_units */

extern void Loader_UpdateLoadingScreen(void* a, char* name, int x);
extern void* App_GetInstance(void);
extern void func_001C10A0(Inner_1C0EE0* t);
extern void func_001C4410(VV_1C0EE0* v, int n, Inner_1C0EE0* fill);
extern void func_0013A040(Inner_1C0EE0* t, int flags);
extern void PtrVec_Reserve(void* v, int n);
extern void PtrVec_PushBack_1C1080(void* v, int* x);
#pragma opt_strength_reduction off
void Loader_InitNodeGroups(void* a0, PopReader_1C0EE0* r)
{
    D_004FFBE4 = 0;
    if (r->cur) {
        int mis;
        Loader_UpdateLoadingScreen(App_GetInstance(), "Initializing Node Groups...", 0);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        if ((unsigned char)Pop_FindTag(r, 0x3A505247)) {
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
                func_001C10A0(&tmp);
                tmp.f = 1;
                func_001C4410(vv, n, &tmp);
                func_0013A040(&tmp, -1);
                for (i = 0; i < n; i++) {
                    int j;
                    int off = i * 16;
                    m = *(int*)r->cur;
                    r->cur += 4;
                    PtrVec_Reserve(vv->data + off, m);
                    for (j = 0; j < m; j++) {
                        int v[1];
                        v[0] = *(int*)r->cur;
                        r->cur += 4;
                        PtrVec_PushBack_1C1080(vv->data + off, v);
                    }
                }
            }
        }
    }
}
#pragma opt_strength_reduction reset
#undef Pop_FindTag /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C0EE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C0EE0 */
