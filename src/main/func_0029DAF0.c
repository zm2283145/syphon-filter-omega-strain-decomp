#pragma cplusplus on
#include "types.h"
struct Stack_DAF0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void Show(void* w, int ms); virtual void Hide(void* w); };
typedef struct { char pad[0x14]; unsigned short flags; } W_DAF0;
typedef struct { char pad[0x88]; int x88; char pad8c[0x95 - 0x8C]; unsigned char b95; char pad96[0x108 - 0x96]; void* x108; char pad10c[0x11C - 0x10C]; int x11C; } O_DAF0;
typedef struct { int a; int b; int c; int d; } Str_DAF0;
extern "C" {
extern int D_004FFC04;
extern unsigned char D_00587B38;
extern char D_004AABF0[];
extern char D_004AAC18[];
extern char D_004AAC28[];
void* DME_GetLobby(void);
void func_0029CBB0(O_DAF0*, int);
char* func_0033CE30(O_DAF0*, int, int, int, int, int);
int FrontEnd_OpenPopup(int, int, char*, char*, O_DAF0*, int);
void FrontEnd_ClosePopup(int, int);
Stack_DAF0* Gui_GetScreenStack(void);
W_DAF0* GuiWidget_FindChildByName(void*, char*);
void func_002C9AA0(int);
void func_002C9AF0(int, int);
int SFOLobby_StartNetwork(void*, void*, int);
void* func_00452FE0(void*);
int func_00452FF0(void*, char*);
void func_0029D980(O_DAF0*, void*);
void func_0029D390(O_DAF0*);
void String_CtorCStr_13B480(Str_DAF0*, char*);
void func_0013D680(Str_DAF0*, Str_DAF0*);
void String_Dtor(Str_DAF0*, int);
int func_002071F0(Str_DAF0*);
char* String_CStr(Str_DAF0*);
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
    if (func_002071F0(&msg)) {
        char* m = String_CStr(&msg);
        FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&title), m, o, 0);
    }
    FrontEnd_ClosePopup(D_004FFC04, o->x11C);
    String_Dtor(&title, 0);
    String_Dtor(&msg, 0);
}