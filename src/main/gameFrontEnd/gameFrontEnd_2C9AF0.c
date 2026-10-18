/*
 * main/gameFrontEnd: range (7 files, 002C9AF0-002CA070)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "message_two_member_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();
int sprintf(void *, const void *, ...);

/* merge_units: begin func_002C9AF0 */
#pragma push /* merge_units */
typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];
    char partB[0xAC];
} SoundRequest;
typedef struct EffectMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
} EffectMsg;

extern char D_004FFB50[];
extern char D_004F2CC0[];
extern char D_004DAE30[];
extern char* D_0048C148[];
extern int Service_Lookup(void*, void*);
extern void SoundRequest_Ctor(SoundRequest* req, int kind, void* name, int a, int b);
extern void EffectMsg_WrapRequest(EffectMsg* msg, SoundRequest* req);
extern void Event_Send(EffectMsg* msg, int target, int flags);
#if 0 /* merge_units */
extern void FileMan_Release(void* part, int flags);
#endif /* merge_units */
#define FileMan_Release(a0, a1) (FileMan_Release((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(EffectMsg* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


void func_002C9AF0(char* self, unsigned char kind) {
    EffectMsg msg;
    SoundRequest req;
    int target;

    if (*(int*)(self + 0x30C) != kind) {
        target = Service_Lookup(D_004FFB50, D_004F2CC0);
        SoundRequest_Ctor(&req, 5, D_0048C148[kind], 0, 0);
        EffectMsg_WrapRequest(&msg, &req);
        FileMan_Release(req.partB, -1);
        FileMan_Release(req.partA, -1);
        msg.flag = 1;
        Event_Send(&msg, target, 1);
        *(int*)(self + 0x30C) = kind;
        msg.vtbl = D_004DAE30;
        FileMan_Release(msg.partB, -1);
        FileMan_Release(msg.partA, -1);
        cMessage_dtor(&msg, 0);
    }
}
#undef FileMan_Release /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C9AF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C9AF0 */

/* merge_units: begin func_002C9BF0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(func_002C9BF0, D_004DAE30)
#pragma pop /* merge_units */
/* merge_units: end func_002C9BF0 */

/* merge_units: begin func_002C9C80 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V2C9C80 { virtual void v0(int f); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual void v22(int f); };
struct S2C9C80 { char pad[0x260]; V2C9C80* p260; };
extern "C" {
extern char D_004ACF10[];
void World_ClearPendingIfLoaded(void);
}
static inline void Del2C9C80(V2C9C80* o, int line)
{
    AllocGuard g;
    o->v0(-1);
    Mem_Free(0, o, D_004ACF10, line);
}
extern "C" void func_002C9C80(S2C9C80* s, int flag)
{
    V2C9C80* p = s->p260;
    if (p) {
        if (flag) {
            Del2C9C80(p, 0x653);
            s->p260 = 0;
        } else {
            World_ClearPendingIfLoaded();
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C9C80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C9C80 */

/* merge_units: begin func_002C9D50 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
void* FrontEndScene_ctor(void* p);
void FrontEndScene_Init(void* p);
}
struct Obj9D50 { char pad[0x260]; void* timer; };
extern "C" void FrontEnd_GetCharacterData(Obj9D50* o)
{
    if (!o->timer) {
        void* p;
        {
            AllocGuard guard;
            p = Mem_Alloc(0, 0x3C, D_004ACF10, 0x645);
        }
        if (p)
            p = FrontEndScene_ctor(p);
        o->timer = p;
        FrontEndScene_Init(o->timer);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C9D50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C9D50 */

/* merge_units: begin func_002C9E20 */
#pragma push /* merge_units */
#pragma cplusplus on
struct S2C9E20 { char pad[0x25C]; void* p25C; };
extern "C" {
void Hog_Unload(void* p);
void func_0036D5D0(void* p, short f);
}
extern "C" void func_002C9E20(S2C9E20* s)
{
    if (s->p25C) {
        Hog_Unload(s->p25C);
        {
            void* p = s->p25C;
            AllocGuard g;
            func_0036D5D0(p, -1);
            Mem_Free(0, p, D_004ACF10, 0x639);
        }
        s->p25C = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C9E20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C9E20 */

/* merge_units: begin func_002C9EE0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_0048B2F8[];
char* func_002CCA30(void);
void* func_0036D630(void* p);
#if 0 /* merge_units */
void func_0036D5D0(void* p, int flags);
#endif /* merge_units */
#define func_0036D5D0(a0, a1) (func_0036D5D0((a0), (short)(a1))) /* merge_units */

int Hog_Load(void* hog, char* path, int mode, int flags);
}
struct Obj9EE0 { char pad[0x25C]; void* hog; };
extern "C" bool func_002C9EE0(Obj9EE0* o)
{
    if (!o->hog) {
        char path[0x100];
        void* p;
        sprintf(path, "%s\\FRONTEND\\LANG\\%s\\ZEUS.HOG", D_0048B2F8, func_002CCA30());
        {
            AllocGuard guard;
            p = Mem_Alloc(0, 0x16C, D_004ACF10, 0x628);
        }
        if (p)
            p = func_0036D630(p);
        o->hog = p;
        if (Hog_Load(o->hog, path, 2, 0)) {
            void* q = o->hog;
            {
                AllocGuard guard;
                func_0036D5D0(q, -1);
                Mem_Free(0, q, D_004ACF10, 0x62C);
            }
            o->hog = 0;
        }
    }
    return o->hog != 0;
}
#undef func_0036D5D0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C9EE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C9EE0 */

/* merge_units: begin func_002CA070 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern signed char D_0051EF60;
extern bool D_0051EF58;
char* func_003CBA90(char* s);
int String_CompareNoCase(char* a, char* b);
}
extern "C" bool func_002CA070(void)
{
    if (!D_0051EF60) {
        bool eq = String_CompareNoCase(func_003CBA90("LOBBY_DISABLE_REGISTER"), "1") == 0;
        D_0051EF60 = 1;
        D_0051EF58 = !eq;
    }
    return D_0051EF58;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CA070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CA070 */
