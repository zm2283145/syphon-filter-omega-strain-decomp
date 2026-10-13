#pragma cplusplus on
#include "types.h"
struct Fl_0029E440 { char pad[0x14]; unsigned short flags; };
struct Ui_0029E440 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual void Show(void* p, int a);
};
struct Self_0029E440 {
    char pad0[0x88]; int f88; char pad8C[4]; char* f90; unsigned char b91x[1]; char pad95_[0x95 - 0x95];
};
struct S_0029E440 {
    char pad0[0x88]; int f88; char pad8C[4]; char* f90; char pad94; unsigned char b95; char pad96[0xF8 - 0x96];
    void* fF8; void* fFC; char pad100[4]; void* f104; void* p108; char pad10C[0x11C - 0x10C]; int f11C;
};
extern "C" {
extern void* D_004FFC04;
extern char D_004AAC18[];
extern char D_004AAC28[];
extern char D_004AABF0[];
extern char D_005381F0[];
extern char D_004FFB50[];
extern char D_004F2CC0[];
extern int* D_0055A830;
extern char D_004FFBA4[];
extern "C" char D_004AABC8[];
static void * const dat_0048B988[2] = { (void*)D_004AABC8, (void*)0x0 };
void* DME_GetLobby(void);
int func_00452FE0(void* g);
void func_0029CBB0(S_0029E440* self, int a);
void func_0029DAF0(S_0029E440* self, char* t);
Ui_0029E440* Gui_GetScreenStack(void);
Fl_0029E440* GuiWidget_FindChildByName(void* p, char* name);
int func_0033CE30(S_0029E440* self, int a, int b, int c, int d, int e);
int FrontEnd_OpenPopup(void* ui, int a, char* b, int c, S_0029E440* d, int e);
void FrontEnd_ClosePopup(void* ui, int id);
void func_0029D390(S_0029E440* self);
void func_0037E320(void* p);
void* Service_Lookup(void* a, void* b);
void func_001C9710(void* svc);
void func_002B4FA8(int id);
void func_002B4E50(void);
void* func_00189540(void* p);
void func_0044B970(void* a, char* b);
void func_0029DE70(S_0029E440* self, int a);
void func_0029DFC0(S_0029E440* self);
int func_0033CF90(S_0029E440* self, void* w, int msg, int sub);
}
extern "C" int func_0029E440(S_0029E440* self, void* w, int msg, int sub, char* text)
{
    unsigned short m = msg;
    if (m == 0x2002) {
        unsigned char ok = 0;
        if (DME_GetLobby()) {
            int st = func_00452FE0(DME_GetLobby());
            bool ne = st != -0x2BD && st != -0x2BF;
            if (!ne)
                ok = 1;
        }
        if (ok && sub)
            *(int*)sub = 1;
        self->b95 = 1;
        return 1;
    }
    if (self->f88 == 5 && m == 0x13) {
        self->f90 = text;
        func_0029CBB0(self, 4);
        func_0029DAF0(self, self->f90);
        return 1;
    }
    if (m == 0x2001) {
        void* p = self->p108;
        if (p) {
            Fl_0029E440* a;
            Fl_0029E440* b;
            int old;
            void* ui;
            Gui_GetScreenStack()->Show(p, 0x7D0);
            a = GuiWidget_FindChildByName(self->p108, D_004AAC18);
            if (a)
                a->flags &= ~2;
            b = GuiWidget_FindChildByName(self->p108, D_004AAC28);
            if (b)
                b->flags |= 2;
            old = self->f11C;
            ui = D_004FFC04;
            self->f11C = FrontEnd_OpenPopup(ui, 0, D_004AABF0, func_0033CE30(self, 0x82, 0, 0, 0, 0), 0, 0);
            if (old != -1)
                FrontEnd_ClosePopup(D_004FFC04, old);
        }
        return 1;
    }
    if (m == 0x1B || m == 0x1A) {
        if (sub == 0x20) {
            func_0029D390(self);
            return 1;
        }
        if (self->f88 == 3) {
            if (m == 0x1A) {
                void* svc;
                int id;
                func_0037E320(D_005381F0);
                svc = Service_Lookup(D_004FFB50, D_004F2CC0);
                if (svc)
                    func_001C9710(svc);
                id = D_0055A830 ? *D_0055A830 : -1;
                if (id != -1)
                    func_002B4FA8(id);
                func_002B4E50();
                func_0044B970(func_00189540(D_004FFBA4), (*(char**)dat_0048B988));
            } else if (sub == 0x1F) {
                self->f88 = 5;
            } else {
                func_0029DE70(self, 0);
            }
        }
        if (self->f88 == 4 && m == 0x1A)
            func_0029DE70(self, 0);
        if (sub == 0x1E && m == 0x1A)
            func_0029DE70(self, 0);
        return 1;
    }
    if (m == 2) {
        if (w == self->fF8 || w == self->fFC) {
            if (self->f88 == 1) {
                func_0029CBB0(self, 4);
                if (w == self->fF8) {
                    func_0029DAF0(self, self->f90);
                } else {
                    void* ui = D_004FFC04;
                    FrontEnd_OpenPopup(ui, 5, D_004AABF0, func_0033CE30(self, 0xE, 0, 0, 0, 0), self, 0x1E);
                }
            } else if (w == self->fF8) {
                func_0029DFC0(self);
            } else {
                void* ui = D_004FFC04;
                FrontEnd_OpenPopup(ui, 5, D_004AABF0, func_0033CE30(self, 0xE, 0, 0, 0, 0), self, 0x1E);
            }
            return 1;
        }
        if (w == self->f104) {
            func_0029DFC0(self);
            return 1;
        }
    }
    return func_0033CF90(self, w, msg, sub);
}