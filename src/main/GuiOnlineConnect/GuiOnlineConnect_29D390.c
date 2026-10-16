/*
 * main/GuiOnlineConnect: 3 files, 0029D390-0029DAF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0029D390 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_common_subs off
#include "types.h"
struct Stack_D390 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void Show(void* w, int ms); virtual void Hide(void* w); };
typedef struct { int a; int b; int c; int d; } Str_D390;
typedef struct { void* data; int count; char pad8[0x18]; } List_D390;
typedef struct { char pad0[0x2A]; unsigned char b2A; char pad2B[0x265 - 0x2B]; unsigned char b265; char pad266[2]; int x268; } Fe_D390;
typedef struct { char pad0[0x88]; int x88; char pad8c[0x94 - 0x8C]; unsigned char b94; char pad95[0xD0 - 0x95]; List_D390 lst; char padE8[0x108 - 0xD0 - 0x20]; void* x108; char pad10c[0x11C - 0x10C]; int x11C; int x120; } O_D390;
typedef struct { char pad0[0x8DC]; char sub[0xC4]; int key; } Agent_D390;
typedef struct { int key; char name[4]; } Ent_D390;
extern "C" {
extern Fe_D390* D_004FFC04;
extern char D_004FFB50[];
extern char D_004AABF0[];
extern char D_004AABF8[];
extern char D_004AAC08[];
int func_002CC260(void);
int DME_GetLobby(void);
void FrontEnd_ClosePopup(Fe_D390* fe, int id);
int FrontEnd_OpenPopup(Fe_D390* fe, int kind, char* title, char* text, O_D390* owner, int flags);
Stack_D390* Gui_GetScreenStack(void);
char* func_0033CE30(O_D390* o, int id, int a, int b, int c, int d);
void func_0029DE70(O_D390* o, int a);
void func_0029DFC0(O_D390* o);
void func_0033C320(O_D390* o, int a);
void SFOLobby_LeaveNetworkState(int n);
void LobbyArray_ctor(List_D390* l);
void func_0044F970(List_D390* l, int flags);
void* LobbyArray_At(List_D390* l, int i);
int func_00442F40(int n, int (*cb)(void), List_D390* l);
char* func_003CBA90(char* key);
int String_CompareNoCase(char* a, char* b);
char* func_002CA0E0(Fe_D390* fe);
void func_002CA100(Fe_D390* fe, char* s);
void func_002CA350(Fe_D390* fe);
int SFOLobby_ConnectUniverse(int n, int i);
void func_00442E90(int n);
int SFOLobby_JoinLobby(int n, int i);
int SFOLobby_AutoJoin(int n);
void func_00445570(int n);
int func_004456D0(int n);
void func_004456C0(int n);
Agent_D390* Agent_GetSelected(char* a, int b);
void String_CtorCStr_13B480(Str_D390* s, char* text);
char* String_CStr(Str_D390* s);
void String_Dtor(Str_D390* s, int flags);
}
static inline bool Start_D390(O_D390* o)
{
    int n;
    Fe_D390* fe;
    int p;
    int old;
    n = DME_GetLobby();
    if (!n) {
        func_0029DE70(o, 1);
        return false;
    }
    fe = D_004FFC04;
    p = FrontEnd_OpenPopup(fe, 0, D_004AABF0, func_0033CE30(o, 0xD, 0, 0, 0, 0), 0, 0);
    old = o->x120;
    if (old != -1) FrontEnd_ClosePopup(D_004FFC04, old);
    func_002CA350(D_004FFC04);
    func_00445570(n);
    if (func_004456D0(n)) func_004456C0(n);
    FrontEnd_ClosePopup(D_004FFC04, p);
    return true;
}
static inline char* Prof_D390(Agent_D390* a) { return a->sub; }
static inline unsigned char Find_D390(int n, List_D390* l, bool any)
{
    unsigned char ok = 0;
    if (any) {
        Agent_D390* a = Agent_GetSelected(D_004FFB50, -1);
        char* pr = Prof_D390(a);
        int key = *(int*)(pr + 0xC4);
        int j;
        char* name = pr + 0x80;
        for (j = 0; j < l->count; j++) {
            Ent_D390* e = (Ent_D390*)LobbyArray_At(l, j);
            if (e && e->key == key && String_CompareNoCase(e->name, name) == 0) {
                if (SFOLobby_JoinLobby(n, j)) ok = 1;
                break;
            }
        }
    }
    return ok;
}
extern "C" void func_0029D390(O_D390* o)
{
    Str_D390 s2;
    Str_D390 t2;
    Str_D390 s1;
    Str_D390 t1;
    List_D390 lst;
    int n;
    void* w;
    Fe_D390* fe;
    unsigned char fail;
    n = DME_GetLobby();
    if (!n) {
        FrontEnd_ClosePopup(D_004FFC04, o->x11C);
        func_0029DE70(o, 1);
        return;
    }
    w = o->x108;
    if (w) Gui_GetScreenStack()->Hide(w);
    fe = D_004FFC04;
    o->x120 = FrontEnd_OpenPopup(fe, 0, D_004AABF0, func_0033CE30(o, 0xF, 0, 0, 0, 0), 0, 0);
    FrontEnd_ClosePopup(D_004FFC04, o->x11C);
    SFOLobby_LeaveNetworkState(n);
    o->b94 = 0;
    D_004FFC04->b2A = 1;
    LobbyArray_ctor(&lst);
    fail = 0;
    if (func_00442F40(n, func_002CC260, &lst)) {
        char* cur;
        int found;
        int i;
        char* e;
        bool any;
        int ok;
        any = String_CompareNoCase(func_003CBA90(D_004AABF8), D_004AAC08) == 0;
        cur = func_002CA0E0(D_004FFC04);
        found = -1;
        for (i = 0; i < o->lst.count; i++) {
            e = (char*)LobbyArray_At(&o->lst, i);
            if (e && (String_CompareNoCase(e, cur) == 0 || any)) {
                func_002CA100(D_004FFC04, e + 0x104);
                found = i;
                break;
            }
        }
        if (found == -1) {
            char* txt;
            o->x88 = 4;
            String_CtorCStr_13B480(&s2, func_0033CE30(o, 2, 0, 0, 0, 0));
            String_CtorCStr_13B480(&t2, func_0033CE30(o, 0x84, 0, 0, 0, 0));
            txt = String_CStr(&t2);
            FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&s2), txt, o, 0);
            FrontEnd_ClosePopup(D_004FFC04, o->x120);
            String_Dtor(&t2, 0);
            String_Dtor(&s2, 0);
            func_0044F970(&lst, -1);
            return;
        }
        if (!SFOLobby_ConnectUniverse(n, found)) {
            char* txt;
            o->x88 = 4;
            String_CtorCStr_13B480(&s1, func_0033CE30(o, 3, 0, 0, 0, 0));
            String_CtorCStr_13B480(&t1, func_0033CE30(o, 0x84, 0, 0, 0, 0));
            txt = String_CStr(&t1);
            FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&s1), txt, o, 0);
            FrontEnd_ClosePopup(D_004FFC04, o->x120);
            func_00442E90(n);
            String_Dtor(&t1, 0);
            String_Dtor(&s1, 0);
            func_0044F970(&lst, -1);
            return;
        }
        ok = Find_D390(n, &lst, any);
        if (!ok && !SFOLobby_AutoJoin(n)) fail = 1;
        func_00442E90(n);
    } else {
        FrontEnd_ClosePopup(D_004FFC04, o->x120);
        func_0029DE70(o, 1);
        func_0044F970(&lst, -1);
        return;
    }
    if (D_004FFC04->b265 || fail) {
        o->x88 = 6;
        D_004FFC04->x268 = 0;
        func_0033C320(o, 5);
    } else {
        o->x88 = 7;
        if (Start_D390(o)) func_0029DFC0(o);
    }
    FrontEnd_ClosePopup(D_004FFC04, o->x120);
    func_0044F970(&lst, -1);
}
#pragma pop /* merge_units */
/* merge_units: end func_0029D390 */

/* merge_units: begin func_0029D980 */
#pragma push /* merge_units */
typedef struct { int a[4]; } Str_D980;
typedef struct { char pad[0x88]; int x88; char pad8c[0x11C - 0x8C]; int x11C; } O_D980;
#if 0 /* merge_units */
extern int D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(int*)&D_004FFC04) /* merge_units */

extern char D_004AAC10[];
extern void func_0029F340(void*, char*, char*, char*);
#if 0 /* merge_units */
extern void String_CtorCStr_13B480(Str_D980*, char*);
#endif /* merge_units */
#define String_CtorCStr_13B480(a0, a1) (String_CtorCStr_13B480((Str_D390 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern char* String_CStr(Str_D980*);
#endif /* merge_units */
#define String_CStr(a0) (String_CStr((Str_D390 *)(a0))) /* merge_units */

extern void func_00209620(Str_D980*, Str_D980*);
#if 0 /* merge_units */
extern void String_Dtor(Str_D980*, int);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str_D390 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void FrontEnd_OpenPopup(int, int, char*, char*, O_D980*, int);
#endif /* merge_units */
#define FrontEnd_OpenPopup(a0, a1, a2, a3, a4, a5) ((void)FrontEnd_OpenPopup((Fe_D390 *)(a0), (a1), (a2), (a3), (O_D390 *)(a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void FrontEnd_ClosePopup(int, int);
#endif /* merge_units */
#define FrontEnd_ClosePopup(a0, a1) (FrontEnd_ClosePopup((Fe_D390 *)(a0), (a1))) /* merge_units */


static inline void Zero(char* q, int n)
{
    if (q) {
        do {
            *q++ = 0;
        } while (--n);
    }
}

#pragma opt_propagation off
#pragma optimize_for_size on
void func_0029D980(O_D980* o, void* src) {
    Str_D980 s;
    Str_D980 t;
    Str_D980 u;
    char title[0x80];
    char body[0x100];
    char extra[0x80];
    int flags;
    Zero(title, 0x80);
    Zero(body, 0x100);
    Zero(extra, 0x80);
    func_0029F340(src, title, body, extra);
    String_CtorCStr_13B480(&s, body);
    if (extra[0]) {
        String_CtorCStr_13B480(&t, D_004AAC10);
        func_00209620(&s, &t);
        String_Dtor(&t, 0);
        String_CtorCStr_13B480(&u, extra);
        func_00209620(&s, &u);
        String_Dtor(&u, 0);
    }
    flags = 0;
    if (o->x88 != 4) flags = 0x20;
    FrontEnd_OpenPopup(D_004FFC04, 2, title, String_CStr(&s), o, flags);
    FrontEnd_ClosePopup(D_004FFC04, o->x11C);
    String_Dtor(&s, 0);
}
#undef D_004FFC04 /* merge_units */
#undef String_CtorCStr_13B480 /* merge_units */
#undef String_CStr /* merge_units */
#undef String_Dtor /* merge_units */
#undef FrontEnd_OpenPopup /* merge_units */
#undef FrontEnd_ClosePopup /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029D980 */

/* merge_units: begin func_0029DAF0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Stack_DAF0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void Show(void* w, int ms); virtual void Hide(void* w); };
typedef struct { char pad[0x14]; unsigned short flags; } W_DAF0;
typedef struct { char pad[0x88]; int x88; char pad8c[0x95 - 0x8C]; unsigned char b95; char pad96[0x108 - 0x96]; void* x108; char pad10c[0x11C - 0x10C]; int x11C; } O_DAF0;
typedef struct { int a; int b; int c; int d; } Str_DAF0;
extern "C" {
#if 0 /* merge_units */
extern int D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(int*)&D_004FFC04) /* merge_units */

extern unsigned char D_00587B38;
extern char D_004AAC18[];
extern char D_004AAC28[];
#if 0 /* merge_units */
void* DME_GetLobby(void);
#endif /* merge_units */
#define DME_GetLobby() ((void *)DME_GetLobby()) /* merge_units */

void func_0029CBB0(O_DAF0*, int);
#if 0 /* merge_units */
char* func_0033CE30(O_DAF0*, int, int, int, int, int);
#endif /* merge_units */
#define func_0033CE30(a0, a1, a2, a3, a4, a5) (func_0033CE30((O_D390 *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
int FrontEnd_OpenPopup(int, int, char*, char*, O_DAF0*, int);
#endif /* merge_units */
#define FrontEnd_OpenPopup(a0, a1, a2, a3, a4, a5) (FrontEnd_OpenPopup((Fe_D390 *)(a0), (a1), (a2), (a3), (O_D390 *)(a4), (a5))) /* merge_units */

#if 0 /* merge_units */
void FrontEnd_ClosePopup(int, int);
#endif /* merge_units */
#define FrontEnd_ClosePopup(a0, a1) (FrontEnd_ClosePopup((Fe_D390 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
Stack_DAF0* Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((Stack_DAF0 *)Gui_GetScreenStack()) /* merge_units */

W_DAF0* GuiWidget_FindChildByName(void*, char*);
void func_002C9AA0(int);
void func_002C9AF0(int, int);
int SFOLobby_StartNetwork(void*, void*, int);
void* func_00452FE0(void*);
int func_00452FF0(void*, char*);
#if 0 /* merge_units */
void func_0029D980(O_DAF0*, void*);
#endif /* merge_units */
#define func_0029D980(a0, a1) (func_0029D980((O_D980 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void func_0029D390(O_DAF0*);
#endif /* merge_units */
#define func_0029D390(a0) ((void)func_0029D390((O_D390 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void String_CtorCStr_13B480(Str_DAF0*, char*);
#endif /* merge_units */
#define String_CtorCStr_13B480(a0, a1) (String_CtorCStr_13B480((Str_D390 *)(a0), (a1))) /* merge_units */

void func_0013D680(Str_DAF0*, Str_DAF0*);
#if 0 /* merge_units */
void String_Dtor(Str_DAF0*, int);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str_D390 *)(a0), (a1))) /* merge_units */

int String_Length(Str_DAF0*);
#if 0 /* merge_units */
char* String_CStr(Str_DAF0*);
#endif /* merge_units */
#define String_CStr(a0) (String_CStr((Str_D390 *)(a0))) /* merge_units */

}

static inline void StrInit(Str_DAF0* s) { int i; int* p = &s->a; for (i = 0; i < 3; i++) *p++ = 0; }

extern "C" void func_0029DAF0(O_DAF0* o, void* arg) {
    Str_DAF0 msg;
    Str_DAF0 title;
    Str_DAF0 t1;
    Str_DAF0 t2;
    Str_DAF0 t3;
    char buf[0x100];
    void* net;
    unsigned char ok;
    void* w;
    int fe;
    net = DME_GetLobby();
    if (!net) return;
    func_0029CBB0(o, 4);
    fe = D_004FFC04;
    o->x11C = FrontEnd_OpenPopup(fe, 0, D_004AABF0, func_0033CE30(o, 9, 0, 0, 0, 0), 0, 0);
    o->b95 = 0;
    w = o->x108;
    if (w) {
        W_DAF0* p;
        Gui_GetScreenStack()->Show(w, 2000);
        p = GuiWidget_FindChildByName(o->x108, D_004AAC18);
        if (p) p->flags |= 2;
        p = GuiWidget_FindChildByName(o->x108, D_004AAC28);
        if (p) p->flags &= ~2;
    }
    D_00587B38 = 1;
    func_002C9AA0(D_004FFC04);
    ok = SFOLobby_StartNetwork(net, arg, 1);
    D_00587B38 = 0;
    func_002C9AF0(D_004FFC04, 0);
    w = o->x108;
    if (w) Gui_GetScreenStack()->Hide(w);
    if (ok) {
        if (o->b95) {
            func_0029D980(o, func_00452FE0(net));
            return;
        }
        func_0029D390(o);
        return;
    }
    o->x88 = 4;
    StrInit(&msg);
    StrInit(&title);
    switch ((unsigned char)func_00452FF0(net, buf)) {
    case 6:
        func_0029D980(o, func_00452FE0(net));
        break;
    case 0x3E:
        String_CtorCStr_13B480(&t1, func_0033CE30(o, 0xC, 0, 0, 0, 0));
        func_0013D680(&msg, &t1);
        String_Dtor(&t1, 0);
        break;
    default:
        String_CtorCStr_13B480(&t2, func_0033CE30(o, 0xB, 0, 0, 0, 0));
        func_0013D680(&title, &t2);
        String_Dtor(&t2, 0);
        String_CtorCStr_13B480(&t3, func_0033CE30(o, 0x84, 0, 0, 0, 0));
        func_0013D680(&msg, &t3);
        String_Dtor(&t3, 0);
        break;
    }
    if (String_Length(&msg)) {
        char* m = String_CStr(&msg);
        FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&title), m, o, 0);
    }
    FrontEnd_ClosePopup(D_004FFC04, o->x11C);
    String_Dtor(&title, 0);
    String_Dtor(&msg, 0);
}
#undef D_004FFC04 /* merge_units */
#undef DME_GetLobby /* merge_units */
#undef func_0033CE30 /* merge_units */
#undef FrontEnd_OpenPopup /* merge_units */
#undef FrontEnd_ClosePopup /* merge_units */
#undef Gui_GetScreenStack /* merge_units */
#undef func_0029D980 /* merge_units */
#undef func_0029D390 /* merge_units */
#undef String_CtorCStr_13B480 /* merge_units */
#undef String_Dtor /* merge_units */
#undef String_CStr /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029DAF0 */
