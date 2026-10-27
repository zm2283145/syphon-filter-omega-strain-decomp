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
int cMemMan_Deallocate();
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

extern char g_Game[];
extern char D_004F2CC0[];
extern char D_004DAE30[];
extern char* D_0048C148[];
extern int cSystemContainer_GetSystem(void*, void*);
extern void cSndFx_ctor_int_charP_cGOBJP_int(SoundRequest* req, int kind, void* name, int a, int b);
extern void EffectMsg_WrapRequest(EffectMsg* msg, SoundRequest* req);
extern void QueueMessage_cMessageR_cSystemP_int(EffectMsg* msg, int target, int flags);
#if 0 /* merge_units */
extern void cFileMan_dtor(void* part, int flags);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) (cFileMan_dtor((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(EffectMsg* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


void cGameFrontEnd_PlayMusic(char* self, unsigned char kind) {
    EffectMsg msg;
    SoundRequest req;
    int target;

    if (*(int*)(self + 0x30C) != kind) {
        target = cSystemContainer_GetSystem(g_Game, D_004F2CC0);
        cSndFx_ctor_int_charP_cGOBJP_int(&req, 5, D_0048C148[kind], 0, 0);
        EffectMsg_WrapRequest(&msg, &req);
        cFileMan_dtor(req.partB, -1);
        cFileMan_dtor(req.partA, -1);
        msg.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&msg, target, 1);
        *(int*)(self + 0x30C) = kind;
        msg.vtbl = D_004DAE30;
        cFileMan_dtor(msg.partB, -1);
        cFileMan_dtor(msg.partA, -1);
        cMessage_dtor(&msg, 0);
    }
}
#undef cFileMan_dtor /* merge_units */
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
void cMotionManager_FlushUpdateList(void);
}
static inline void Del2C9C80(V2C9C80* o, int line)
{
    AllocGuard g;
    o->v0(-1);
    cMemMan_Deallocate(0, o, D_004ACF10, line);
}
extern "C" void cGameFrontEnd_CloseCharacter(S2C9C80* s, int flag)
{
    V2C9C80* p = s->p260;
    if (p) {
        if (flag) {
            Del2C9C80(p, 0x653);
            s->p260 = 0;
        } else {
            cMotionManager_FlushUpdateList();
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
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void* cFrontendSystem_ctor(void* p);
void cFrontendSystem_Init(void* p);
}
struct Obj9D50 { char pad[0x260]; void* timer; };
extern "C" void FrontEnd_GetCharacterData(Obj9D50* o)
{
    if (!o->timer) {
        void* p;
        {
            AllocGuard guard;
            p = cMemMan_Allocate(0, 0x3C, D_004ACF10, 0x645);
        }
        if (p)
            p = cFrontendSystem_ctor(p);
        o->timer = p;
        cFrontendSystem_Init(o->timer);
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
void cHogFile_CloseHog(void* p);
void cHogFile_dtor(void* p, short f);
}
extern "C" void cGameFrontEnd_CloseZeusHog(S2C9E20* s)
{
    if (s->p25C) {
        cHogFile_CloseHog(s->p25C);
        {
            void* p = s->p25C;
            AllocGuard g;
            cHogFile_dtor(p, -1);
            cMemMan_Deallocate(0, p, D_004ACF10, 0x639);
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
char* Loc_GetCurrentLanguageName_Thunk(void);
void* cHogFile_ctor(void* p);
#if 0 /* merge_units */
void cHogFile_dtor(void* p, int flags);
#endif /* merge_units */
#define cHogFile_dtor(a0, a1) (cHogFile_dtor((a0), (short)(a1))) /* merge_units */

int cHogFile_OpenHog(void* hog, char* path, int mode, int flags);
}
struct Obj9EE0 { char pad[0x25C]; void* hog; };
extern "C" bool cGameFrontEnd_OpenZeusHog(Obj9EE0* o)
{
    if (!o->hog) {
        char path[0x100];
        void* p;
        sprintf(path, "%s\\FRONTEND\\LANG\\%s\\ZEUS.HOG", D_0048B2F8, Loc_GetCurrentLanguageName_Thunk());
        {
            AllocGuard guard;
            p = cMemMan_Allocate(0, 0x16C, D_004ACF10, 0x628);
        }
        if (p)
            p = cHogFile_ctor(p);
        o->hog = p;
        if (cHogFile_OpenHog(o->hog, path, 2, 0)) {
            void* q = o->hog;
            {
                AllocGuard guard;
                cHogFile_dtor(q, -1);
                cMemMan_Deallocate(0, q, D_004ACF10, 0x62C);
            }
            o->hog = 0;
        }
    }
    return o->hog != 0;
}
#undef cHogFile_dtor /* merge_units */
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
char* cSFOini_GetKeyValue(char* s);
int String_CompareNoCase(char* a, char* b);
}
extern "C" bool FrontEnd_IsRegisterEnabled(void)
{
    if (!D_0051EF60) {
        bool eq = String_CompareNoCase(cSFOini_GetKeyValue("LOBBY_DISABLE_REGISTER"), "1") == 0;
        D_0051EF60 = 1;
        D_0051EF58 = !eq;
    }
    return D_0051EF58;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CA070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CA070 */
