/*
 * main/gameFrontEnd: range (7 files, 002CA0E0-002CA640)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();
char *strncpy(void *, const void *, int);

/* merge_units: begin func_002CA0E0 */
#pragma push /* merge_units */
#include "types.h"
extern char D_004AC9E0[];
static void * const dat_0048C138[2] = { (void*)D_004AC9E0, (void*)0x0 };
typedef struct { char pad[0x2AC]; char name[0x40]; } NameObjA0E0;
char* func_002CA0E0(NameObjA0E0* o)
{
    if (o->name[0])
        return o->name;
    return (*(char**)dat_0048C138);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CA0E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CA0E0 */

/* merge_units: begin func_002CA100 */
#pragma push /* merge_units */
typedef struct { char pad[0x26C]; char name[0x40]; } NameObjA100;
void func_002CA100(NameObjA100* o, const char* s)
{
    if (s == 0)
        o->name[0] = 0;
    else
        strncpy(o->name, s, 0x40);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CA100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CA100 */

/* merge_units: begin func_002CA140 */
#pragma push /* merge_units */
extern char D_004ACA00[];
static void * const dat_0048C140[2] = { (void*)D_004ACA00, (void*)0x0 };
typedef struct { char pad[0x26C]; char name[0x40]; } NameObjA140;
char* cGameFrontEnd_LobbyGetUniverseName_void_2(NameObjA140* o)
{
    if (o->name[0])
        return o->name;
    return (*(char**)dat_0048C140);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CA140(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CA140 */

/* merge_units: begin func_002CA160 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct S2CA160 { char pad[0x2EC]; unsigned char b2EC; char pad2ED[3]; void* p2F0; void* p2F4; void* p2F8; };
extern "C" {
extern char D_004ACF10[];
void* cDME_GetLobby(void);
void SFOLobby_AccountScreenExit(void* p);
void SFOLobbyList_dtor(void* p, int f);
}
static inline void Del2CA160(void* p, int line)
{
    AllocGuard g;
    SFOLobbyList_dtor(p, -1);
    cMemMan_Deallocate(0, p, D_004ACF10, line);
}
extern "C" int cGameFrontEnd_LobbyStopAccountScreen(S2CA160* s)
{
    if (!s->b2EC)
        return 0;
    if (cDME_GetLobby())
        SFOLobby_AccountScreenExit(cDME_GetLobby());
    Del2CA160(s->p2F0, 0x5F5);
    Del2CA160(s->p2F4, 0x5F6);
    Del2CA160(s->p2F8, 0x5F7);
    s->p2F0 = 0;
    s->p2F4 = 0;
    s->p2F8 = 0;
    s->b2EC = 0;
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CA160(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CA160 */

/* merge_units: begin func_002CA350 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern void* cMemMan_Allocate(int pool, int size, char* file, int line);
#if 0 /* merge_units */
extern int cDME_GetLobby(void);
#endif /* merge_units */
#define cDME_GetLobby() ((int)cDME_GetLobby()) /* merge_units */

extern void* SFOLobbyList_ctor(void* p);
extern int SFOLobby_AccountScreenStart(int a, void* fn, void* b, void* c, void* d);
extern void cGameFrontEnd_LobbyCallback(void);
}

struct ObjCA350 {
    char pad[0x2EC];
    unsigned char inited;
    char pad2[3];
    void* a;
    void* b;
    void* c;
};

extern "C" int cGameFrontEnd_LobbyStartAccountScreen(ObjCA350* self)
{
    void* p;

    if (self->inited || !cDME_GetLobby())
        return 0;
    {
        AllocGuard guard;
        p = cMemMan_Allocate(0, 0x1C, D_004ACF10, 0x5E1);
    }
    if (p)
        p = SFOLobbyList_ctor(p);
    self->a = p;
    {
        AllocGuard guard;
        p = cMemMan_Allocate(0, 0x1C, D_004ACF10, 0x5E2);
    }
    if (p)
        p = SFOLobbyList_ctor(p);
    self->b = p;
    {
        AllocGuard guard;
        p = cMemMan_Allocate(0, 0x1C, D_004ACF10, 0x5E3);
    }
    if (p)
        p = SFOLobbyList_ctor(p);
    self->c = p;
    self->inited = 1;
    return SFOLobby_AccountScreenStart(cDME_GetLobby(), (void*)cGameFrontEnd_LobbyCallback, self->a, self->b, self->c);
}
#undef cDME_GetLobby /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CA350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CA350 */

/* merge_units: begin func_002CA580 */
#pragma push /* merge_units */
typedef struct { char pad[0x264]; unsigned char b264; } S2CA640;
int cGameFrontEnd_LobbyDestroy(S2CA640* s, int a); /* gsynth: defined below */
typedef struct { char p0[0x255C]; int state; } L2CA580;
extern unsigned char g_DebugTriangle;
extern unsigned char D_005723B8;
#if 0 /* merge_units */
extern L2CA580* cDME_GetLobby(void);
#endif /* merge_units */
#define cDME_GetLobby() ((L2CA580 *)cDME_GetLobby()) /* merge_units */

extern void SFOLobby_Intel(L2CA580* l);
extern int SFOLobby_IsFatalError(L2CA580* l);
extern int Gui_Manager(void);
extern void GuiManager_NextFrame(int mgr, float t);
extern void func_002CA6F0(void* s);
#if 0 /* merge_units */
extern int cGameFrontEnd_LobbyDestroy(void* s, int v);
#endif /* merge_units */
#define cGameFrontEnd_LobbyDestroy(a0, a1) (cGameFrontEnd_LobbyDestroy((void *)(a0), (a1))) /* merge_units */

extern void SFOLobby_Reset(L2CA580* l, int v);
/* Lobby tick: when the session is ready either flags the pending state or starts the game screen. */
void cGameFrontEnd_LobbyUpdate(void* s)
{
    L2CA580* l;
    if (g_DebugTriangle) return;
    l = cDME_GetLobby();
    if (!l) return;
    SFOLobby_Intel(l);
    if (!SFOLobby_IsFatalError(l)) return;
    if (l->state == 10) {
        D_005723B8 = 1;
        return;
    }
    GuiManager_NextFrame(Gui_Manager(), 0.0f);
    func_002CA6F0(s);
    cGameFrontEnd_LobbyDestroy(s, 1);
    SFOLobby_Reset(l, 1);
}
#undef cDME_GetLobby /* merge_units */
#undef cGameFrontEnd_LobbyDestroy /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CA580(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CA580 */

/* merge_units: begin func_002CA640 */
#pragma push /* merge_units */
typedef struct { char pad[0x255C]; int mode; } G2CA640;

#if 0 /* merge_units */
extern int cGameFrontEnd_LobbyStopAccountScreen(S2CA640* s);
#endif /* merge_units */
#define cGameFrontEnd_LobbyStopAccountScreen(a0) (cGameFrontEnd_LobbyStopAccountScreen((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern G2CA640* cDME_GetLobby(void);
#endif /* merge_units */
#define cDME_GetLobby() ((G2CA640 *)cDME_GetLobby()) /* merge_units */

extern void SFOLobby_AccountLogOut(G2CA640* g);
extern void FrontEnd_FlushMessages(S2CA640* s);
#if 0 /* merge_units */
extern void SFOLobby_Reset(G2CA640* g, int a);
#endif /* merge_units */
#define SFOLobby_Reset(a0, a1) (SFOLobby_Reset((void *)(a0), (a1))) /* merge_units */

extern void cDME_ActivateLobby(int a);
int cGameFrontEnd_LobbyDestroy(S2CA640* s, int a)
{
    cGameFrontEnd_LobbyStopAccountScreen(s);
    if (cDME_GetLobby()) {
        if (s->b264 && cDME_GetLobby()->mode != 10)
            SFOLobby_AccountLogOut(cDME_GetLobby());
        s->b264 = 0;
        FrontEnd_FlushMessages(s);
        SFOLobby_Reset(cDME_GetLobby(), a);
        cDME_ActivateLobby(0);
        return 1;
    }
    return 0;
}
#undef cGameFrontEnd_LobbyStopAccountScreen /* merge_units */
#undef cDME_GetLobby /* merge_units */
#undef SFOLobby_Reset /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CA640(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CA640 */
