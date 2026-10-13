#pragma cplusplus on
#include "types.h"
struct O_34D2D0;
typedef struct { int f0; char pad4[4]; unsigned char b8; char pad9[0xB]; } E_34D2D0;
struct O_34D2D0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual int v19();
    char s4[0x60];
    int f64;
    char pad68[0xD4 - 0x68];
    E_34D2D0* ents;
};
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; } Ev_34D2D0;
typedef struct { char pad[0x10]; int f10; } Sel_34D2D0;
typedef struct { char pad[0x20]; Sel_34D2D0* f20; } M_34D2D0;
typedef struct { char pad[0x25C]; int f25C; } G_34D2D0;
extern "C" {
extern G_34D2D0* D_004FFC04;
char D_004BA818[] = "GuiSlideShow"; void func_0034D770(O_34D2D0* o, int k);
M_34D2D0* Gui_GetScreenStack(void);
void* Gui_GetScreenList(void);
void func_0041E0F0(void* a, void* b, int kind, int v, int f);
void* func_00418A80(void* mgr, char* a, char* b);
void GuiStack_SwapScreens(void* mgr, void* o, void* w);
char* String_CStr(void* s);
void func_00327C70(void* w, int a, char* s, int b);
void func_00328630(void* w);
int func_00328310(void* w, int v);
int sprintf(char* buf, const char* fmt, ...);
void func_00328140(void* w, int r, char* s, int v, char* t);
int func_00356BE0(O_34D2D0* o, Ev_34D2D0* ev);
int func_0034D2D0(O_34D2D0* o, Ev_34D2D0* ev);
}
static inline unsigned char Down_34D2D0(Ev_34D2D0* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Plain_34D2D0(Ev_34D2D0* e) { unsigned char r = 0; if (Down_34D2D0(e) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_34D2D0(Ev_34D2D0* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_34D2D0(Ev_34D2D0* e, int b) { return Down2_34D2D0(e) && e->btn == b; }
static inline bool Plain2_34D2D0(Ev_34D2D0* e, int b) { return Btn2_34D2D0(e, b) && e->b6 == 0; }

int func_0034D2D0(O_34D2D0* o, Ev_34D2D0* ev)
{
    if (Plain_34D2D0(ev)) {
        switch ((unsigned int)ev->btn) {
        case 0x8000: func_0034D770(o, 0); return 1;
        case 0x2000: func_0034D770(o, 1); return 1;
        case 0x1000: func_0034D770(o, 2); return 1;
        case 0x4000: func_0034D770(o, 3); return 1;
        }
    }
    if (Plain2_34D2D0(ev, 0x40) && Gui_GetScreenStack()->f20->f10 != -1) {
        int idx = Gui_GetScreenStack()->f20->f10;
        void* w;
        E_34D2D0** ep = &o->ents;
        if (((E_34D2D0*)((char*)o->ents + idx * 20))->b8) {
            func_0041E0F0(o, Gui_GetScreenStack(), 0x10, 1, 0);
            w = func_00418A80(Gui_GetScreenList(), D_004BA818, "ZEUSHELL");
            if (w) {
                char b0[16];
                char b1[16];
                char* s = String_CStr(o->s4);
                int r;
                func_00327C70(w, o->v19(), s, idx);
                func_00328630(w);
                r = func_00328310(w, (*ep)[idx].f0);
                sprintf(b0, "0_%d_%d.tdx", o->f64, idx + 1);
                if (idx % 4 == 2) idx--;
                sprintf(b1, "0_%d_%d", o->f64, idx + 1);
                func_00328140(w, r, b0, D_004FFC04->f25C, b1);
                GuiStack_SwapScreens(Gui_GetScreenStack(), o, w);
            }
        } else {
            func_0041E0F0(o, Gui_GetScreenStack(), 0x10, 4, 0);
        }
        return 1;
    }
    return func_00356BE0(o, ev);
}