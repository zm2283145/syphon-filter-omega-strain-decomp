#pragma cplusplus on
#pragma opt_propagation off
#include "types.h"
#include "vslot_pad.h"
struct Msg3D0 { void* vt; char pad4[0x2C]; };
struct PStr3D0 { unsigned char len; char s[0x80]; };
class Scr3D0 {
public:
    VPAD16(a) VPAD4(b) virtual int IsA(void* t);
};
class Stk3D0 {
public:
    VPAD16(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual void Push(Scr3D0* s, int f);
    char p4[0x4D];
    unsigned char b51;
    char p52[0x16];
    int x68;
};
struct Slot3D0 {
    char pad[0x1F0];
    float v[4];
    char pad200[0x2F5 - 0x200];
    char f2F5;
    char f2F6;
};
struct Self3D0 {
    char p0[0x20];
    long long x20;
    unsigned char b28;
    char p29[3];
    unsigned char b2C;
    char p2D[3];
    unsigned char b30;
    char p31;
    unsigned char b32;
    char p33[2];
    unsigned char b35;
    unsigned char b36;
    unsigned char b37;
    char p38[0x258 - 0x38];
    Scr3D0* p258;
    char p25C[0x30C - 0x25C];
    int x30C;
};
struct W3D0 { char pad[0x278]; unsigned char b278; };
extern "C" {
extern char D_004ACFE8[];
extern char D_004ACFF8[];
extern char D_004AD1F8[];
extern char D_004AD000[];
extern char D_004AD010[];
extern char D_004AD020[];
extern char D_004AD038[];
extern char D_005381F0[];
extern int D_00538C60;
extern float D_00539170[4];
extern char D_004FFC90[];
extern char D_004ACF48[];
extern char D_004FFB50[];
extern char D_004F2CC0[];
extern char D_004F5370[];
extern char D_004F5378[];
extern char D_004DE220[];
extern char D_004DE200[];
extern int D_004FFD30;
extern char D_0055A700[];
void func_002C9510(Self3D0* self);
void func_002CB8C0(Self3D0* self, unsigned char flag);
Stk3D0* Gui_GetScreenStack(void);
int Gui_GetScreenList(void);
void func_004158C0(Stk3D0* s, int x);
Scr3D0* func_004187C0(int l, char* a, char* b);
Scr3D0* func_00418A80(int l, char* a, char* b);
int DME_GetLobby(void);
void func_00453A50(int g);
void DME_StartThread(void);
long long func_003698B0(void);
void FrontEnd_SetLoadingScreen(Self3D0* self, int a, int b, int c);
char* strncpy(char* d, const char* s, int n);
void* Service_Lookup(void* a, void* b);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void func_0041E0F0(Stk3D0* a, Stk3D0* b, int c, int d, int e);
void func_002C9D50(Self3D0* self);
void func_002C9EE0(Self3D0* self);
void func_00145160(int a);
void DME_StopThread(void);
void func_002CA6F0(Self3D0* self);
void DME_SetLobbyActive(int a);
void func_002C8090(Self3D0* self);
void func_00453B00(int g, int a);
W3D0* func_001698C0(void);
void func_003D1730(void* p);
}
extern "C" void func_002CB3D0(Self3D0* self, unsigned char flag)
{
    Scr3D0* scr;
    if (self->b28) return;
    if (self->b37) {
        func_002C9510(self);
        return;
    }
    func_002CB8C0(self, flag);
    { Stk3D0* st = Gui_GetScreenStack(); st->b51 = !flag; }
    func_004158C0(Gui_GetScreenStack(), 0);
    func_004158C0(Gui_GetScreenStack(), 1);
    Gui_GetScreenStack()->x68 = 0;
    if (!flag) Gui_GetScreenStack()->x68 |= 0xF000;
    scr = func_004187C0(Gui_GetScreenList(), D_004ACFE8, D_004ACFF8);
    scr = (scr && scr->IsA(D_004AD1F8)) ? scr : 0;
    self->p258 = scr;
    if (!flag) {
        unsigned char had;
        unsigned char go;
        Scr3D0* next;
        void* svc;
        PStr3D0 buf;
        Msg3D0 m1;
        Msg3D0 m2;
        {
            Slot3D0* s = (Slot3D0*)(D_005381F0 + D_00538C60 * 0x110);
            float* v = D_00539170;
            s->v[0] = v[0];
            s->v[1] = v[1];
            s->v[2] = v[2];
            s->v[3] = v[3];
            s->f2F5 = 1;
            s->f2F6 = 1;
        }
        had = 0;
        if (DME_GetLobby()) {
            func_00453A50(DME_GetLobby());
            DME_StartThread();
            had = 1;
        }
        self->x20 = func_003698B0();
        go = 0;
        FrontEnd_SetLoadingScreen(self, 1, 0, 0);
        self->x30C = -1;
        {
            char* d = buf.s;
            const char* s = D_004FFC90;
            int n = 0;
            while ((*d++ = *s++) != 0) {
                if (++n >= 0x7E) {
                    n++;
                    *d = '\n';
                    d[1] = 0;
                    break;
                }
            }
            buf.len = n;
        }
        strncpy(D_004FFC90, D_004ACF48, 0x80);
        svc = Service_Lookup(D_004FFB50, D_004F2CC0);
        Event_Construct(&m1, D_004F5370);
        m1.vt = D_004DE220;
        Event_Send(&m1, svc, 1);
        m1.vt = D_004DE220;
        cMessage_dtor(&m1, 0);
        Event_Construct(&m2, D_004F5378);
        m2.vt = D_004DE200;
        Event_Send(&m2, svc, 1);
        m2.vt = D_004DE200;
        cMessage_dtor(&m2, 0);
        strncpy(D_004FFC90, buf.s, 0x80);
        {
            Stk3D0* a = Gui_GetScreenStack();
            func_0041E0F0(a, Gui_GetScreenStack(), 0x10, 5, 0);
        }
        if (self->b2C) {
            func_00418A80(Gui_GetScreenList(), D_004AD000, D_004AD010);
            func_00418A80(Gui_GetScreenList(), D_004AD020, D_004AD038);
            func_002C9D50(self);
        }
        if (self->b35) {
            self->b35 = 0;
            next = func_00418A80(Gui_GetScreenList(), D_004AD020, D_004AD038);
            if (self->b30 && !self->b32) go = 1;
        } else {
            next = func_00418A80(Gui_GetScreenList(), D_004AD000, D_004AD010);
        }
        func_002C9EE0(self);
        func_00145160(D_004FFD30);
        FrontEnd_SetLoadingScreen(self, 0, 0, 0);
        if (had) DME_StopThread();
        Gui_GetScreenStack()->Push(next, 0);
        if (go && !DME_GetLobby()) {
            func_002CA6F0(self);
            DME_SetLobbyActive(1);
            if (DME_GetLobby()) {
                func_002C8090(self);
                func_00453B00(DME_GetLobby(), 1);
                DME_SetLobbyActive(0);
            }
        }
    }
    func_001698C0()->b278 = flag;
    if (!flag) func_003D1730(D_0055A700);
    self->b28 = 1;
    self->b36 = flag;
}
