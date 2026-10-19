/*
 * main/gameFrontEnd: range (7 files, 002CA0E0-002CA640)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();
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
char* func_002CA140(NameObjA140* o)
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
void* DME_GetLobby(void);
void func_00445DC0(void* p);
void func_0044F970(void* p, int f);
}
static inline void Del2CA160(void* p, int line)
{
    AllocGuard g;
    func_0044F970(p, -1);
    Mem_Free(0, p, D_004ACF10, line);
}
extern "C" int FrontEnd_FreePolicyLists(S2CA160* s)
{
    if (!s->b2EC)
        return 0;
    if (DME_GetLobby())
        func_00445DC0(DME_GetLobby());
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
extern void* Mem_Alloc(int pool, int size, char* file, int line);
#if 0 /* merge_units */
extern int DME_GetLobby(void);
#endif /* merge_units */
#define DME_GetLobby() ((int)DME_GetLobby()) /* merge_units */

extern void* LobbyArray_ctor(void* p);
extern int func_00445E80(int a, void* fn, void* b, void* c, void* d);
extern void App_CardWaitPoll(void);
}

struct ObjCA350 {
    char pad[0x2EC];
    unsigned char inited;
    char pad2[3];
    void* a;
    void* b;
    void* c;
};

extern "C" int FrontEnd_DownloadPolicies(ObjCA350* self)
{
    void* p;

    if (self->inited || !DME_GetLobby())
        return 0;
    {
        AllocGuard guard;
        p = Mem_Alloc(0, 0x1C, D_004ACF10, 0x5E1);
    }
    if (p)
        p = LobbyArray_ctor(p);
    self->a = p;
    {
        AllocGuard guard;
        p = Mem_Alloc(0, 0x1C, D_004ACF10, 0x5E2);
    }
    if (p)
        p = LobbyArray_ctor(p);
    self->b = p;
    {
        AllocGuard guard;
        p = Mem_Alloc(0, 0x1C, D_004ACF10, 0x5E3);
    }
    if (p)
        p = LobbyArray_ctor(p);
    self->c = p;
    self->inited = 1;
    return func_00445E80(DME_GetLobby(), (void*)App_CardWaitPoll, self->a, self->b, self->c);
}
#undef DME_GetLobby /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CA350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CA350 */

/* merge_units: begin func_002CA580 */
#pragma push /* merge_units */
typedef struct { char pad[0x264]; unsigned char b264; } S2CA640;
int FrontEnd_LeaveOnline(S2CA640* s, int a); /* gsynth: defined below */
typedef struct { char p0[0x255C]; int state; } L2CA580;
extern unsigned char D_0051EEB0;
extern unsigned char D_005723B8;
#if 0 /* merge_units */
extern L2CA580* DME_GetLobby(void);
#endif /* merge_units */
#define DME_GetLobby() ((L2CA580 *)DME_GetLobby()) /* merge_units */

extern void SFOLobby_Update(L2CA580* l);
extern int func_00452FD0(L2CA580* l);
extern int Gui_GetScreenList(void);
extern void GuiManager_Update(int mgr, float t);
extern void func_002CA6F0(void* s);
#if 0 /* merge_units */
extern int FrontEnd_LeaveOnline(void* s, int v);
#endif /* merge_units */
#define FrontEnd_LeaveOnline(a0, a1) (FrontEnd_LeaveOnline((void *)(a0), (a1))) /* merge_units */

extern void func_00453B00(L2CA580* l, int v);
/* Lobby tick: when the session is ready either flags the pending state or starts the game screen. */
void func_002CA580(void* s)
{
    L2CA580* l;
    if (D_0051EEB0) return;
    l = DME_GetLobby();
    if (!l) return;
    SFOLobby_Update(l);
    if (!func_00452FD0(l)) return;
    if (l->state == 10) {
        D_005723B8 = 1;
        return;
    }
    GuiManager_Update(Gui_GetScreenList(), 0.0f);
    func_002CA6F0(s);
    FrontEnd_LeaveOnline(s, 1);
    func_00453B00(l, 1);
}
#undef DME_GetLobby /* merge_units */
#undef FrontEnd_LeaveOnline /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CA580(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CA580 */

/* merge_units: begin func_002CA640 */
#pragma push /* merge_units */
typedef struct { char pad[0x255C]; int mode; } G2CA640;

#if 0 /* merge_units */
extern int FrontEnd_FreePolicyLists(S2CA640* s);
#endif /* merge_units */
#define FrontEnd_FreePolicyLists(a0) (FrontEnd_FreePolicyLists((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern G2CA640* DME_GetLobby(void);
#endif /* merge_units */
#define DME_GetLobby() ((G2CA640 *)DME_GetLobby()) /* merge_units */

extern void func_00445850(G2CA640* g);
extern void FrontEnd_FlushMessages(S2CA640* s);
#if 0 /* merge_units */
extern void func_00453B00(G2CA640* g, int a);
#endif /* merge_units */
#define func_00453B00(a0, a1) (func_00453B00((void *)(a0), (a1))) /* merge_units */

extern void DME_SetLobbyActive(int a);
int FrontEnd_LeaveOnline(S2CA640* s, int a)
{
    FrontEnd_FreePolicyLists(s);
    if (DME_GetLobby()) {
        if (s->b264 && DME_GetLobby()->mode != 10)
            func_00445850(DME_GetLobby());
        s->b264 = 0;
        FrontEnd_FlushMessages(s);
        func_00453B00(DME_GetLobby(), a);
        DME_SetLobbyActive(0);
        return 1;
    }
    return 0;
}
#undef FrontEnd_FreePolicyLists /* merge_units */
#undef DME_GetLobby /* merge_units */
#undef func_00453B00 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CA640(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CA640 */
