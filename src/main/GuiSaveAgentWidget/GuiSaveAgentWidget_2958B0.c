/*
 * main/GuiSaveAgentWidget: 2 files, 002958B0-00296660
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002958B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

struct Str_2958B0 { char pad[0xC]; };
struct Msg_2958B0 { char pad0[4]; Str_2958B0 name; int f10; char pad14[8]; int f1C; };
struct Lvl_2958B0 { char pad[0xC0]; int fC0; };
struct Ui_2958B0 {
    char pad0[0x30]; unsigned char b30; char pad31; unsigned char b32; unsigned char b33; unsigned char b34; unsigned char b35;
    char pad36[3]; char text[0x13C - 0x39]; int f13C; char pad140[0x188 - 0x140]; Lvl_2958B0 lvl;
    char pad24C[0x260 - 0x24C]; int f260; char pad264[4]; int f268;
};
struct S_2958B0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v0A(); virtual void v0B(); virtual void v0C(); virtual void v0D(); virtual void v0E();
    virtual void v0F(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual int GetId();    /* +0x54 */
    Str_2958B0 name;        /* 0x04 */
    char pad10[0x1CC - 0x10];
    int f1CC;
    char pad1D0[4];
    unsigned char b1D4;
    char pad1D5[0x1DC - 0x1D5];
    int f1DC; int f1E0; int f1E4; int f1E8; int f1EC;
    char pad1F0[0x2D0 - 0x1F0];
    Msg_2958B0* p2D0[6];
    unsigned char b2E8;
    char pad2E9[0x2F8 - 0x2E9];
    int f2F8;
    char pad2FC[0x324 - 0x2FC];
    int f324;
};

extern "C" {
extern Ui_2958B0* D_004FFC04;
extern char D_004FFB50[];
extern char D_004FFC90[];
extern signed char D_004FFBA0;
extern signed char D_004FFBA1;
extern char* D_0048C160[];
extern char* D_0048B6F8;
extern char* D_0048B700;
extern char* D_0048B708;
extern char* D_0048B710;
extern char* D_0048B718;
extern char* D_0048B720;
extern char* D_0048B728;
extern char* D_0048B730;
extern char* D_0048B738;
extern char* D_0048B740;
extern char* D_0048B748;
extern char* D_0048B750;
extern char* D_0048B758;
extern char* D_0048B760;
extern char* D_0048B768;
extern char D_004AA248[], D_004AA268[], D_004AA288[], D_004AA368[], D_004AA378[], D_004AA390[], D_004AA3A0[];
extern char D_004AA3B0[], D_004AA3C0[], D_004AA3D0[], D_004AA3E0[], D_004AA3F0[], D_004AA400[], D_004AA410[];
extern char D_004AA418[], D_004AA428[], D_004AA430[], D_004AA448[], D_004AA450[], D_004AA460[], D_004AA468[];
extern char D_004AA478[], D_004AA488[], D_004AA490[], D_004AA498[], D_004AA4A0[];
void func_002C8090(Ui_2958B0* ui);
void func_002C81D0(Ui_2958B0* ui);
void func_002C82F0(Ui_2958B0* ui);
void func_002955B0(S_2958B0* self);
void func_00294300(S_2958B0* self, int a);
void func_002972E0(S_2958B0* self);
void FrontEnd_ClosePopup(Ui_2958B0* ui, int id);
int FrontEnd_OpenPopup(Ui_2958B0* ui, int kind, char* title, char* text, S_2958B0* owner, int cb);
void* Gui_GetScreenList(void);
void* Gui_GetScreenStack(void);
void* GuiManager_FindOrLoad(void* list, char* a, char* b);
void GuiStack_SwapScreens(void* stack, S_2958B0* from, void* to);
char* func_0033CE30(S_2958B0* self, int id, int a, char* s, int b, int c);
void func_0032B4F0(void* scr, char* text, char* title, S_2958B0* owner, int a, int b, int c);
int DME_GetLobby(void);
int func_0044AF60(int lobby, char* s);
int func_00452FF0(int lobby, int a);
int func_0033C320(S_2958B0* self, int a);
void String_CtorCStr_13B480(Str_2958B0* s, char* c);
char* String_CStr(Str_2958B0* s);
void String_Dtor(Str_2958B0* s, int f);
void String_Copy(char* d, char* s);
int String_AssignCStr_1C43A0(Str_2958B0* s, char* c);
void LevelSelect_SetLevel(Lvl_2958B0* l, int lvl);
char* strncpy(char* d, const char* s, unsigned int n);
int Agent_GetSelected(void* a, int b);
void func_003328D0(int agent, int a, int b, int c, int d);
void* func_003534A0(int a);
void func_00327C70(void* scr, int id, char* s, int a);
void func_00326DE0(void* scr, int a, int b, int c, int d);
int sprintf(char* d, const char* f, ...);
char* Loc_LookupText(char* s);
int func_0033CF90(S_2958B0* self, Msg_2958B0* msg, unsigned short type, int sub, char* str);
}

extern "C" int func_002958B0(S_2958B0* self, Msg_2958B0* msg, unsigned short type, int sub, char* str)
{
    Str_2958B0 title;
    Str_2958B0 text;
    char buf[0x40];

    if (type == 0x18) {
        self->b2E8 = 1;
        return 1;
    }
    if (type == 0x10 && sub == 1)
        return 1;
    if (type == 0x1B || type == 0x1A) {
        if (sub == 0x19 && type == 0x1A) {
            func_002C8090(D_004FFC04);
            func_002955B0(self);
            FrontEnd_ClosePopup(D_004FFC04, self->f2F8);
            return 1;
        }
        if (sub == 0x1A && type == 0x1A) {
            void* scr = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AA368, D_004AA378);
            if (scr)
                func_0032B4F0(scr, func_0033CE30(self, 0x5D, 0, 0, 0, 0), D_004AA288, self, 0xF, 0x1B, 0);
            return 1;
        }
        if (sub == 0x1B && type == 0x1A) {
            int lobby = DME_GetLobby();
            if (lobby && str && *str) {
                Ui_2958B0* ui = D_004FFC04;
                int popup = FrontEnd_OpenPopup(ui, 0, D_004AA288, func_0033CE30(self, 0x7E, 0, str, 0, 0), 0, 0);
                if (func_0044AF60(lobby, str)) {
                    func_0033C320(self, 3);
                } else {
                    int id;
                    switch ((unsigned char)func_00452FF0(lobby, 0)) {
                    case 0x1B: id = 0x5F; break;
                    case 0x1A: id = 0x60; break;
                    case 3: id = 0x61; break;
                    case 0x1C: id = 0x62; break;
                    default: id = 0x63; break;
                    }
                    String_CtorCStr_13B480(&title, func_0033CE30(self, 0x5E, 0, 0, 0, 0));
                    String_CtorCStr_13B480(&text, func_0033CE30(self, (unsigned char)id, 0, str, 0, 0));
                    char* t = String_CStr(&text);
                    FrontEnd_OpenPopup(D_004FFC04, 5, String_CStr(&title), t, self, 0x1C);
                    String_Dtor(&text, 0);
                    String_Dtor(&title, 0);
                }
                FrontEnd_ClosePopup(D_004FFC04, popup);
            }
            return 1;
        }
        if (sub == 0x1C && type == 0x1A) {
            void* scr = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AA368, D_004AA378);
            if (scr)
                func_0032B4F0(scr, func_0033CE30(self, 0x5D, 0, 0, 0, 0), D_004AA288, self, 0xF, 0x1B, 0);
            return 1;
        }
    }
    if (type == 2) {
        int id = msg->f1C;
        if (id == self->f1DC) {
            int lvl;
            int v;
            void* scr;
            Lvl_2958B0* ls;
            if (!String_AssignCStr_1C43A0(&msg->name, D_0048B700)) {
                func_00294300(self, 4);
                return 1;
            }
            v = self->f1CC;
            lvl = -1;
            if (v >= 0 && v < 0x11)
                lvl = v;
            else if (v == 0x17)
                lvl = 0x11;
            ls = &D_004FFC04->lvl;
            LevelSelect_SetLevel(ls, lvl);
            if (lvl == -1)
                return 1;
            strncpy(D_004FFC90, D_0048C160[lvl], 0x80);
            scr = 0;
            if (!String_AssignCStr_1C43A0(&msg->name, D_0048B6F8)) {
                Ui_2958B0* ui = D_004FFC04;
                if (ui->b30) {
                    if (ui->b32) {
                        scr = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AA390, D_004AA3A0);
                    } else {
                        if (!func_0033C320(self, 6)) {
                            Ui_2958B0* ui2 = D_004FFC04;
                            FrontEnd_OpenPopup(ui2, 2, D_004AA288, func_0033CE30(self, 0x5B, 0, 0, 0, 0), self, 0x18);
                        }
                        return 1;
                    }
                } else {
                    ui->b35 = 1;
                    D_004FFC04->b33 = 0;
                    D_004FFC04->b34 = self->f1CC == 0x17;
                    D_004FFBA1 = D_004FFBA0;
                    D_004FFBA0 = 3;
                    func_003328D0(Agent_GetSelected(D_004FFB50, -1), self->f1CC + 1, 5, 0, 1);
                    return 1;
                }
            } else if (!String_AssignCStr_1C43A0(&msg->name, D_0048B708)) {
                if (D_004FFC04->b32)
                    return 1;
                if (self->f1CC >= 0 && self->f1CC < 0x11 && ls->fC0 >= 0) {
                    if (!func_0033C320(self, 2)) {
                        Ui_2958B0* ui2 = D_004FFC04;
                        FrontEnd_OpenPopup(ui2, 2, D_004AA288, func_0033CE30(self, 0x5B, 0, 0, 0, 0), self, 0x18);
                    }
                    return 1;
                }
            }
            if (scr)
                GuiStack_SwapScreens(Gui_GetScreenStack(), self, scr);
        } else if (id == self->f1E4) {
            void* scr = 0;
            if (!String_AssignCStr_1C43A0(&msg->name, D_0048B728)) {
                unsigned char noLobby = !D_004FFC04->f260;
                int popup = -2;
                if (noLobby) {
                    func_002C82F0(D_004FFC04);
                    Ui_2958B0* ui = D_004FFC04;
                    popup = FrontEnd_OpenPopup(ui, 0, D_004AA288, Loc_LookupText(D_004AA3B0), 0, 0);
                }
                scr = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AA3C0, D_004AA3D0);
                if (noLobby) {
                    FrontEnd_ClosePopup(D_004FFC04, popup);
                    func_002C81D0(D_004FFC04);
                }
            } else if (!String_AssignCStr_1C43A0(&msg->name, D_0048B730)) {
                scr = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AA3E0, D_004AA3F0);
            } else if (!String_AssignCStr_1C43A0(&msg->name, D_0048B738)) {
                scr = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AA400, D_004AA410);
            } else if (!String_AssignCStr_1C43A0(&msg->name, D_0048B740)) {
                scr = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AA418, D_004AA428);
            } else if (!String_AssignCStr_1C43A0(&msg->name, D_0048B748)) {
                scr = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AA430, D_004AA448);
            } else if (!String_AssignCStr_1C43A0(&msg->name, D_0048B750)) {
                scr = func_003534A0(0);
            } else if (!String_AssignCStr_1C43A0(&msg->name, D_0048B758)) {
                scr = func_003534A0(1);
            } else if (!String_AssignCStr_1C43A0(&msg->name, D_0048B760)) {
                scr = func_003534A0(2);
            } else if (!String_AssignCStr_1C43A0(&msg->name, D_0048B768)) {
                scr = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AA450, D_004AA460);
            }
            if (scr)
                GuiStack_SwapScreens(Gui_GetScreenStack(), self, scr);
        } else if (id == self->f1E0) {
            LevelSelect_SetLevel(&D_004FFC04->lvl, -1);
            if (!String_AssignCStr_1C43A0(&msg->name, D_0048B710)) {
                if (!func_0033C320(self, 3)) {
                    Ui_2958B0* ui = D_004FFC04;
                    FrontEnd_OpenPopup(ui, 5, D_004AA288, func_0033CE30(self, 0x5C, 0, 0, 0, 0), self, 0x1A);
                }
                return 1;
            }
            if (!String_AssignCStr_1C43A0(&msg->name, D_0048B718)) {
                func_0033C320(self, 4);
                return 1;
            }
            if (!String_AssignCStr_1C43A0(&msg->name, D_0048B720)) {
                D_004FFC04->f268 = 1;
                func_0033C320(self, 5);
                return 1;
            }
            func_00294300(self, 0);
        } else if (id == self->f1E8) {
            void* scr;
            int v = msg->f10;
            if (v == 5) {
                func_00294300(self, 5);
                return 1;
            }
            if (v != -1) {
                scr = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004AA468, D_004AA478);
                if (scr) {
                    char* s = String_CStr(&self->name);
                    func_00327C70(scr, self->GetId(), s, 0);
                    if (self->f1CC == 0x14)
                        func_00326DE0(scr, 0x12, v, -1, 1);
                    else
                        func_00326DE0(scr, self->f1CC + 1, v, -1, 0);
                    GuiStack_SwapScreens(Gui_GetScreenStack(), self, scr);
                    return 1;
                }
            }
        } else if (id == self->f1EC) {
            int v = msg->f10;
            switch (v) {
            case 2:
                sprintf(buf, D_004AA248, D_004FFC90);
                func_003328D0(Agent_GetSelected(D_004FFB50, -1), self->f1CC + 1, 5, 0, 1);
                break;
            case 3:
                sprintf(buf, D_004AA488, self->f324);
                func_003328D0(Agent_GetSelected(D_004FFB50, -1), self->f1CC + 1, 5, 2, 1);
                break;
            case 4:
                sprintf(buf, D_004AA268, D_004FFC90);
                func_003328D0(Agent_GetSelected(D_004FFB50, -1), self->f1CC + 1, 5, 1, 1);
                break;
            case 0:
                String_Copy(buf, D_004AA490);
                break;
            case 1:
                String_Copy(buf, D_004AA498);
                func_003328D0(Agent_GetSelected(D_004FFB50, -1), 0x11, 5, 1, 1);
                break;
            default:
                if (v >= 10000) {
                    sprintf(buf, D_004AA4A0, 0x11, v - 9999);
                    func_003328D0(Agent_GetSelected(D_004FFB50, -1), 0x12, 5, v - 10000, 1);
                } else
                    return 1;
                break;
            }
            func_002972E0(self);
            D_004FFC04->f13C = 1;
            String_Copy(D_004FFC04->text, buf);
            D_004FFBA1 = D_004FFBA0;
            D_004FFBA0 = 4;
            return 1;
        }
        return 1;
    }
    if (type == 0)
        self->p2D0[self->b1D4] = msg;
    return func_0033CF90(self, msg, type, sub, str);
}
#pragma pop /* merge_units */
/* merge_units: end func_002958B0 */

/* merge_units: begin func_00296660 */
#pragma push /* merge_units */
typedef struct Col_00296660 { float r, g, b, a; } Col_00296660;
typedef struct W_00296660 { char pad[0x10]; int kind; unsigned short flags; } W_00296660;
typedef struct Ag_00296660 { char pad[0xB68]; unsigned char bB68; } Ag_00296660;
typedef struct S_00296660 {
    char pad0[0x198]; W_00296660* w198[6]; float f1B0; char pad1B4[0x1CC - 0x1B4]; int f1CC; char pad1D0[4];
    unsigned char state; char pad1D5[0x2EC - 0x1D5]; W_00296660* p2EC; W_00296660* p2F0; char pad2F4[0x2FC - 0x2F4];
    W_00296660* w2FC[10];
} S_00296660;
static const float dat_004AA1F8[2] = { 500.0f, 0.0f };
extern Col_00296660 D_00587B80;
extern Col_00296660 D_00587B90;
void func_00296A80(S_00296660* self);
void func_0033D310(S_00296660* self, float dt);
float Math_FMod(float x, float y);
void func_002986B0(float t, Col_00296660* out, Col_00296660* a, Col_00296660* b);
#if 0 /* merge_units */
Ag_00296660* Agent_GetSelected(void* a, int b);
#endif /* merge_units */
#define Agent_GetSelected(a0, a1) ((Ag_00296660 *)Agent_GetSelected((a0), (a1))) /* merge_units */

int func_00332860(Ag_00296660* ag, int a, int b);
int func_00332950(Ag_00296660* ag, int a, int b, int c);
void func_0041C070(W_00296660* w, Col_00296660* c);
/* abs.s has no C spelling in MW */
static inline float Fabs_00296660(float x) { float r; asm { abs.s r, x } return r; }

/* Per-frame update of a menu page: pulses the highlight colour of the enabled entries. */
void func_00296660(S_00296660* self, float dt)
{
    Col_00296660 col;
    Ag_00296660* ag;
int n;
int i;
    unsigned char st;
    func_00296A80(self);
    func_0033D310(self, dt);
    st = self->state;
    if (!(st == 1 || (unsigned int)(st - 3) <= 1 || st == 5))
        return;
    self->f1B0 += 33.333332f * dt;
    self->f1B0 = Math_FMod(self->f1B0, (*(float*)dat_004AA1F8));
    func_002986B0(Fabs_00296660(1.0f - 2.0f * self->f1B0 / (*(float*)dat_004AA1F8)), &col, &D_00587B90, &D_00587B80);
    ag = Agent_GetSelected(D_004FFB50, -1);
    if (self->state == 4) {
        n = -1;
        if (self->f1CC < 0x11)
            n = self->f1CC + 1;
        else if (self->f1CC == 0x14)
            n = 0x12;
        if (n != -1) {
            for (i = 0; i < 6; i++) {
                if (self->w198[i]) {
                    if (func_00332860(ag, n, i))
                        func_0041C070(self->w198[i], &col);
                    else
                        func_0041C070(self->w198[i], &D_00587B80);
                }
            }
        } else {
            int j;
            for (j = 0; j < 6; j++) {
                if (self->w198[j])
                    func_0041C070(self->w198[j], &D_00587B80);
            }
        }
    }
    if (self->state == 3 && self->p2F0) {
        if (Agent_GetSelected(D_004FFB50, -1)->bB68)
            func_0041C070(self->p2F0, &col);
        else
            func_0041C070(self->p2F0, &D_00587B80);
    }
    if (self->state == 1 && self->p2EC) {
        if (self->f1CC < 0x11) {
            if (func_00332860(ag, self->f1CC + 1, -1))
                func_0041C070(self->p2EC, &col);
            else
                func_0041C070(self->p2EC, &D_00587B80);
        } else {
            func_0041C070(self->p2EC, &D_00587B80);
        }
    }
    if (self->state == 5) {
        int k;
        for (k = 0; k < 10; k++) {
            unsigned char on;
            W_00296660* w = self->w2FC[k];
            if (w && (w->flags & 2)) {
                on = 0;
                if (w->flags & 4) {
                    if (self->f1CC == 0x14) {
                        on = !func_00332950(ag, 0x12, 5, k);
                    } else {
                        switch (w->kind) {
                        case 2:
                            on = !func_00332950(ag, self->f1CC + 1, 5, 0);
                            break;
                        case 3:
                            on = !func_00332950(ag, self->f1CC + 1, 5, 2);
                            break;
                        case 4:
                        case 1:
                            on = !func_00332950(ag, self->f1CC + 1, 5, 1);
                            break;
                        }
                    }
                }
                if (on)
                    func_0041C070(self->w2FC[k], &col);
                else
                    func_0041C070(self->w2FC[k], &D_00587B80);
            }
        }
    }
}
#undef Agent_GetSelected /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00296660 */
