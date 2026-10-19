/*
 * main/Loader: range (5 files, 001C1470-001C1CE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_001C1470 */
#pragma push /* merge_units */
#pragma cplusplus on
struct PopReader_1C1470 { int version; int size; unsigned int base; char* cur; };
struct Vec_1C1470 { float x, y, z; };
struct Buf_1C1470 { char b[0x24]; };
struct Loc_1C1470 { Vec_1C1470 v; int pad; Buf_1C1470 buf; };
struct Col_1C1470 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void Activate(int on);
};
extern "C" {
int Pop_FindTag(PopReader_1C1470* r, int tag);
Col_1C1470* IdMgr_FindCollision(int a, int b);
void ZoneMgr_Associate(Col_1C1470* a, Col_1C1470* b, int c, Col_1C1470* d);
}
static inline void Align_1C1470(PopReader_1C1470* r)
{
    int mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
}
static inline int ReadInt_1C1470(PopReader_1C1470* r)
{
    int v = *(int*)r->cur;
    r->cur += 4;
    return v;
}
static inline float ReadFloat_1C1470(PopReader_1C1470* r)
{
    float v = *(float*)r->cur;
    r->cur += 4;
    return v;
}
static inline void Copy_1C1470(void* d0, void* s0, int n0)
{
    int n = n0; void* d = d0; void* s = s0;
    asm {
        .set noreorder
        blez n, done
        andi $a0, s, 0xF
        andi $a1, d, 0xF
        or $a0, $a0, $a1
        andi $a1, n, 0xF
        or $a0, $a0, $a1
        nop
        bgtz $a0, bytes
        nop
    quads:
        lq $a1, 0(s)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu s, s, 0x10
        bgtz n, quads
        sq $a1, -0x10(d)
        b done
        nop
    bytes:
        lb $a1, 0(s)
        addiu d, d, 1
        addi n, n, -1
        addiu s, s, 1
        bgtz n, bytes
        sb $a1, -1(d)
        .set reorder
    done:
    }
}
extern "C" void Loader_LoadPointLights(void* a0, PopReader_1C1470* r)
{
    Align_1C1470(r);
    if ((unsigned char)Pop_FindTag(r, 0x3A544E50)) {
        int n = ReadInt_1C1470(r);
        int i = 0;
        for (; i < n; i++) {
            Loc_1C1470 L;
            int a = ReadInt_1C1470(r);
            int b = ReadInt_1C1470(r);
            int c = ReadInt_1C1470(r);
            int d = ReadInt_1C1470(r);
            if (c != -1 && d != -1) {
                Col_1C1470* o1 = IdMgr_FindCollision(a, b);
                Col_1C1470* o2 = IdMgr_FindCollision(c, d);
                if (o1)
                    o1->Activate(1);
                if (o2 && o1)
                    ZoneMgr_Associate(o2, o1, 1, o2);
            }
            Copy_1C1470((void*)&L.buf, r->cur, 0x24);
            r->cur += 0x24;
            L.v.x = *(float*)r->cur; r->cur += 4;
            L.v.y = *(float*)r->cur; r->cur += 4;
            L.v.z = *(float*)r->cur; r->cur += 4;
            r->cur += 4;
            r->cur += 4;
            r->cur += 1;
            Align_1C1470(r);
            if (r->version >= 0x3B) {
                r->cur += 1;
                Align_1C1470(r);
                r->cur += 1;
                Align_1C1470(r);
            }
            r->cur += 4;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C1470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C1470 */

/* merge_units: begin func_001C1770 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct PopReader_1C1770 { int version; int size; unsigned int base; char* cur; };
struct Light_1C1770 { void* vt; char pad[0x64]; };
extern "C" {
extern char D_0049EE88[];
extern char D_004DA0B0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Object_Register(void* o);
#if 0 /* merge_units */
int Pop_FindTag(PopReader_1C1770* r, int tag);
#endif /* merge_units */
#define Pop_FindTag(a0, a1) (Pop_FindTag((PopReader_1C1470 *)(a0), (a1))) /* merge_units */

void* cGameSceneLight_ctor(void* p, PopReader_1C1770* r);
void* cGameDirectionalLight_ctor(void* p, PopReader_1C1770* r);
void cGameLight_dtor(void* p, int f);
void func_00165E60(void* a, char* name, int x);
void* App_GetInstance(void);
}
extern "C" void Loader_InitLights(void* a0, PopReader_1C1770* r)
{
    if (r->cur) {
        int mis;
        func_00165E60(App_GetInstance(), "Initializing Lights...", 0);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        if ((unsigned char)Pop_FindTag(r, 0x3A544E50)) {
            {
                int n;
                int i = 0;
                n = *(int*)r->cur;
                r->cur += 4;
                for (; i < n; i++) {
                    void* p;
                    {
                        AllocGuard g;
                        p = Mem_Alloc(0, 0x68, D_0049EE88, 0x441);
                    }
                    if (p)
                        p = cGameSceneLight_ctor(p, r);
                    Object_Register(p);
                }
            }
            mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
            if (mis)
                r->cur += 4 - mis;
            if ((unsigned char)Pop_FindTag(r, 0x3A524944)) {
                int n;
                int i = 0;
                n = *(int*)r->cur;
                r->cur += 4;
                for (; i < n; i++) {
                    if (i < 4) {
                        void* p;
                        {
                            AllocGuard g;
                            p = Mem_Alloc(0, 0x68, D_0049EE88, 0x484);
                        }
                        if (p)
                            p = cGameDirectionalLight_ctor(p, r);
                        Object_Register(p);
                    } else {
                        Light_1C1770 tmp;
                        cGameDirectionalLight_ctor(&tmp, r);
                        tmp.vt = D_004DA0B0;
                        cGameLight_dtor(&tmp, 0);
                    }
                }
            }
        }
    }
}
#undef Pop_FindTag /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C1770(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C1770 */

/* merge_units: begin func_001C1A20 */
#pragma push /* merge_units */
typedef struct G4PopReader {
    int unk0;
    int size;
    unsigned int base;
    int* cur;
} G4PopReader;
extern char g_LightMgr[];
extern void* App_GetInstance(void);
#if 0 /* merge_units */
extern void func_00165E60(void* h, void* s, int f);
#endif /* merge_units */
#define func_00165E60(a0, a1, a2) (func_00165E60((a0), (void *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int Pop_FindTag(G4PopReader* r, int tag);
#endif /* merge_units */
#define Pop_FindTag(a0, a1) (Pop_FindTag((void *)(a0), (a1))) /* merge_units */

extern void LightMgr_AllocPool(void* pool, int type, int count);
static inline void G4_Align(G4PopReader* r)
{
    int m = (unsigned long long)(unsigned int)r->cur % 4;
    if (m) {
        r->cur = (int*)((int)r->cur + (4 - m));
    }
}
void Loader_AllocateLights(void* level, G4PopReader* r)
{
    int n;
    if (r->cur == 0) {
        return;
    }
    func_00165E60(App_GetInstance(), "Allocating Lights...", 0);
    G4_Align(r);
    if (!(unsigned char)Pop_FindTag(r, 0x3A544E50)) {
        return;
    }
    n = *r->cur;
    r->cur++;
    LightMgr_AllocPool(g_LightMgr, 16, n);
    G4_Align(r);
    if (!(unsigned char)Pop_FindTag(r, 0x3A524944)) {
        return;
    }
    n = *r->cur;
    r->cur++;
    LightMgr_AllocPool(g_LightMgr, 2, n);
    LightMgr_AllocPool(g_LightMgr, 4, 0x18);
    LightMgr_AllocPool(g_LightMgr, 1, 1);
}
#undef func_00165E60 /* merge_units */
#undef Pop_FindTag /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C1A20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C1A20 */

/* merge_units: begin func_001C1B60 */
#pragma push /* merge_units */
#pragma cplusplus on
struct PopReader_1C1B60 { int unk0; int size; unsigned int base; char* cur; };
struct Sky_1C1B60 { char pad[0x90]; int count; };
extern "C" {
extern char D_0048B2F8[];
extern char g_LevelDirName[];
#if 0 /* merge_units */
int Pop_FindTag(PopReader_1C1B60* r, int tag);
#endif /* merge_units */
#define Pop_FindTag(a0, a1) (Pop_FindTag((PopReader_1C1470 *)(a0), (a1))) /* merge_units */

Sky_1C1B60* SkyboxGob_Create(void* p, void* a, int arc, PopReader_1C1B60* r, int n);
int Archive_Open(void* a, char* name, int b, int c);
}
extern "C" void Loader_InitSkybox(void* a0, void* a1, PopReader_1C1B60* r, void* arc)
{
    if ((unsigned char)Pop_FindTag(r, 0x3A594B53)) {
        char name[128];
        int h;
        int n;
        func_00165E60(App_GetInstance(), "Initializing Skybox...", 0);
        sprintf(name, "%s\\%s\\TEX.HOG", D_0048B2F8, g_LevelDirName, g_LevelDirName);
        h = Archive_Open(arc, name, 0, 0);
        n = *(int*)r->cur;
        r->cur += 4;
        while (n) {
            Sky_1C1B60* p;
            {
                AllocGuard g;
                p = (Sky_1C1B60*)Mem_Alloc(0, 0x94, D_0049EE88, 0x3F3);
            }
            if (p)
                p = SkyboxGob_Create(p, a1, h, r, n);
            Object_Register(p);
            n -= p->count;
        }
    }
}
#undef Pop_FindTag /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C1B60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C1B60 */

/* merge_units: begin func_001C1CE0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct PopReader_1C1CE0 { int unk0; int size; unsigned int base; char* cur; };
extern "C" {
#if 0 /* merge_units */
int Pop_FindTag(PopReader_1C1CE0* r, int tag);
#endif /* merge_units */
#define Pop_FindTag(a0, a1) (Pop_FindTag((PopReader_1C1470 *)(a0), (a1))) /* merge_units */

void* Loader_ReadParticleRecord(void* p, PopReader_1C1CE0* r);
}
extern "C" void Loader_LoadParticles(void* a0, PopReader_1C1CE0* r)
{
    func_00165E60(App_GetInstance(), "Loading Particles...", 0);
    if ((unsigned char)Pop_FindTag(r, 0x3A524C50)) {
        int mis;
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        {
        int n;
        int i = 0;
        n = *(int*)r->cur;
        r->cur += 4;
        for (; i < n; i++) {
            void* p;
            {
                AllocGuard g;
                p = Mem_Alloc(0, 0x74, D_0049EE88, 0x3C9);
            }
            if (p)
                p = Loader_ReadParticleRecord(p, r);
            Object_Register(p);
        }
        }
    }
}
#undef Pop_FindTag /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C1CE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C1CE0 */
