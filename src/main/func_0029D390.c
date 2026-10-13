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
