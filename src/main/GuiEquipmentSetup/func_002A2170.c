#pragma cplusplus on
#include "types.h"
struct W_002A2170 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
    char name[4];
};
struct St_002A2170 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26();
    virtual void SetState(int s); virtual unsigned char GetState();
};
struct Net_002A2170 { char pad[0x30]; St_002A2170* p30; };
struct G_002A2170 { char pad[0x26A0]; unsigned char b26A0; };
struct S_002A2170 { char pad0[0xC0]; int fC0; char padC4[0x14]; unsigned char bD8; };
extern "C" {
extern char D_004AB0B0[];
extern char D_004AB100[];
extern char D_004AB110[];
extern char D_004AB120[];
extern char D_004AB130[];
extern char D_004AB148[];
extern char D_004A9870[];
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern Net_002A2170* D_004FFC0C;
extern unsigned char D_004FFC29;
extern char D_0055A300[];
extern unsigned char D_005723F8;
extern unsigned char D_00572400;
extern char D_004FFB50[];
void func_002A3A10(S_002A2170* self);
char* func_001692D0(void* s);
int strcmp(const char* a, const char* b);
void func_0036A0F0(void* p);
void func_00429B30(void);
void* func_004147A0(void);
void func_00414AC0(void* ui, S_002A2170* self, void* pg);
G_002A2170* func_004294C0(void);
char* Loc_LookupText(char* key);
void func_0041BEB0(void* w, char* s, int a);
void* func_00414790(void);
void* func_00418A80(void* a, char* b, char* c);
void func_0012FA60(void* a, int b);
int func_0041EF10(S_002A2170* self, W_002A2170* w, int msg, int sub, char* text);
}
extern "C" int func_002A2170(S_002A2170* self, W_002A2170* w, int msg, int sub, char* text)
{
    unsigned short m;
    func_002A3A10(self);
    m = msg;
    if (m == 2) {
        char* n = func_001692D0(w->name);
        if (!strcmp(n, D_004AB0B0)) {
            if (D_005721C8) {
                int ok;
                w = (w && w->IsA(D_004A9870)) ? w : 0;
                if (D_005721C8)
                    ok = D_005721C0;
                else
                    ok = 1;
                if (ok) {
                    if (D_004FFC0C->p30->GetState() == 3) {
                        if (self->fC0 == 2) {
                            D_004FFC29 = 0;
                            func_0036A0F0(D_0055A300);
                            func_00429B30();
                            func_00414AC0(func_004147A0(), self, 0);
                            D_004FFC0C->p30->SetState(4);
                        }
                    } else if (self->fC0 > 0) {
                        D_004FFC0C->p30->SetState(3);
                        D_005723F8 = 1;
                        if (!self->bD8) {
                            G_002A2170* g;
                            self->bD8 = 1;
                            g = func_004294C0();
                            if (g)
                                g->b26A0 = 1;
                        }
                    }
                } else if (D_00572400) {
                    D_004FFC29 = 0;
                    func_0036A0F0(D_0055A300);
                    func_00414AC0(func_004147A0(), self, 0);
                    D_004FFC0C->p30->SetState(4);
                } else if (D_004FFC0C->p30->GetState() == 1) {
                    char* t;
                    D_004FFC0C->p30->SetState(2);
                    t = Loc_LookupText(D_004AB100);
                    if (t)
                        func_0041BEB0(w, t, 0);
                } else {
                    char* t;
                    D_004FFC0C->p30->SetState(1);
                    t = Loc_LookupText(D_004AB110);
                    if (t)
                        func_0041BEB0(w, t, 0);
                }
            } else {
                D_004FFC29 = 0;
                func_0036A0F0(D_0055A300);
                func_00414AC0(func_004147A0(), self, 0);
            }
            return 1;
        }
        if (!strcmp(n, D_004AB120)) {
            void* pg = func_00418A80(func_00414790(), D_004AB130, D_004AB148);
            D_004FFC0C->p30->SetState(1);
            func_00414AC0(func_004147A0(), self, pg);
            return 1;
        }
    }
    if (m == 0x1A && !sub) {
        func_00414AC0(func_004147A0(), self, 0);
        func_0012FA60(D_004FFB50, 3);
        return 1;
    }
    return func_0041EF10(self, w, msg, sub, text);
}