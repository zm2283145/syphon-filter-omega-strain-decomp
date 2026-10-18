/*
 * main/GuiAccountLogin: 3 files, 00289440-00289C80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00289440 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct Str_00289440 { char d[0x10]; };
struct Txt_00289440 { char pad[0x48]; char s48[4]; };
struct Ag_00289440 { char pad[0x8CC]; char name[4]; };
struct Mgr_00289440 { char pad[0x264]; unsigned char b264; unsigned char b265; };
struct S_00289440 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void Refresh(int a);
    char pad4[0x48]; unsigned char b4C; char pad4D[0x3F]; Txt_00289440* p8C; char pad90[4]; Txt_00289440* p94; char pad98[4];
    Ag_00289440* p9C; char padA0[8]; int fA8; unsigned char bAC;
};
extern "C" {
extern Mgr_00289440* D_004FFC04;
extern char D_004A9730[];
void* DME_GetLobby(void);
char* func_0033CE30(S_00289440* self, int a, int b, int c, int d, int e);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, S_00289440* d, int e);
char* String_CStr(void* s);
int func_00445A40(void* g, char* a, char* b);
int strcmp(const char* a, const char* b);
void String_Copy(char* d, const char* s);
char* AgentData_GetName(Ag_00289440* ag);
void SaveAgentWidget_Rename(S_00289440* self, char* n);
void GuiSaveAgentWidget_HandleEvent(S_00289440* self);
void String_CtorCStr_13B480(Str_00289440* s, const char* c);
void func_0013D680(Str_00289440* d, Str_00289440* s);
void String_Dtor(Str_00289440* s, int flags);
int func_00452FF0(void* g, int a);
int func_002CA070(void* ui);
void FrontEnd_ClosePopup(void* ui, int id);
}
static inline int StrNe_00289440(const char* a, const char* b) { return strcmp(a, b); }
static inline void Assign_00289440(S_00289440* self, Str_00289440* d, int id)
{
    Str_00289440 t;
    String_CtorCStr_13B480(&t, func_0033CE30(self, id, 0, 0, 0, 0));
    func_0013D680(d, &t);
    String_Dtor(&t, 0);
}
extern "C" void func_00289440(S_00289440* self)
{
    void* g = DME_GetLobby();
    unsigned char ok;
    char* pw;
    if (!g)
        return;
    {
        void* ui = D_004FFC04;
        self->fA8 = FrontEnd_OpenPopup(ui, 0, D_004A9730, func_0033CE30(self, 0x1B, 0, 0, 0, 0), 0, 0);
        pw = String_CStr(self->p94->s48);
        ok = func_00445A40(g, String_CStr(self->p8C->s48), pw);
    }
    if (ok) {
        unsigned char changed;
        char* cur;
        char* n;
        self->bAC = 0;
        changed = 0;
        cur = self->p9C->name;
        if (StrNe_00289440(String_CStr(self->p94->s48), cur)) {
            String_Copy(self->p9C->name, String_CStr(self->p94->s48));
            changed = 1;
        }
        n = String_CStr(self->p8C->s48);
        if (strcmp(n, AgentData_GetName(self->p9C))) {
            SaveAgentWidget_Rename(self, String_CStr(self->p8C->s48));
        } else {
            if (D_004FFC04->b265)
                changed = 1;
            if (changed) {
                self->b4C = 1;
                GuiSaveAgentWidget_HandleEvent(self);
            } else {
                self->Refresh(1);
            }
        }
        return;
    }
    {
        Str_00289440 a;
        Str_00289440 b;
        int kind;
        int cb;
        String_CtorCStr_13B480(&a, D_004A9730);
        String_CtorCStr_13B480(&b, D_004A9730);
        switch ((unsigned char)func_00452FF0(g, 0)) {
        case 0x3C:
            Assign_00289440(self, &a, 0x1E);
            Assign_00289440(self, &b, 0x80);
            kind = 2;
            break;
        case 0x3B:
            if (func_002CA070(D_004FFC04)) {
                Assign_00289440(self, &a, 0x1D);
                Assign_00289440(self, &b, 0x1C);
                kind = 4;
            } else {
                Assign_00289440(self, &a, 0x1D);
                Assign_00289440(self, &b, 0x8B);
                kind = 2;
            }
            break;
        case 0x3A:
            Assign_00289440(self, &a, 0x75);
            Assign_00289440(self, &b, 0x81);
            kind = 2;
            break;
        default:
            Assign_00289440(self, &a, 0x1F);
            Assign_00289440(self, &b, 0x88);
            kind = 2;
            break;
        }
        cb = kind == 4 ? 0x1F : -1;
        {
            pw = String_CStr(&b);
            FrontEnd_OpenPopup(D_004FFC04, kind, String_CStr(&a), pw, self, cb);
        }
        FrontEnd_ClosePopup(D_004FFC04, self->fA8);
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
        D_004FFC04->b264 = ok;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00289440 */

/* merge_units: begin func_00289990 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ev_00289990 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct Txt_00289990 { char pad[0x48]; char s48[4]; };
struct Ui_00289990 { char pad[0x20]; void* f20; };
struct Mgr_00289990 { char pad[0x268]; int f268; };
struct S_00289990 { char pad0[0x88]; void* p88; Txt_00289990* p8C; void* p90; Txt_00289990* p94; char pad98[0xC]; unsigned char bA4; char padA5[8]; unsigned char bAD; };
extern "C" {
#if 0 /* merge_units */
extern Mgr_00289990* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(Mgr_00289990 **)&D_004FFC04) /* merge_units */

extern char D_00506340[];
extern char D_00506350[];
extern unsigned char D_00506360;
#if 0 /* merge_units */
int func_0033CE30(S_00289990* self, int a, int b, int c, int d, int e);
#endif /* merge_units */
#define func_0033CE30(a0, a1, a2, a3, a4, a5) ((int)func_0033CE30((S_00289440 *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
int FrontEnd_OpenPopup(void* ui, int a, char* b, int c, S_00289990* d, int e);
#endif /* merge_units */
#define FrontEnd_OpenPopup(a0, a1, a2, a3, a4, a5) (FrontEnd_OpenPopup((a0), (a1), (a2), (char *)(a3), (S_00289440 *)(a4), (a5))) /* merge_units */

#if 0 /* merge_units */
void func_00289440(S_00289990* self);
#endif /* merge_units */
#define func_00289440(a0) ((void)func_00289440((S_00289440 *)(a0))) /* merge_units */

void func_00288E90(S_00289990* self);
Ui_00289990* Gui_GetScreenStack(void);
void func_0028A230(S_00289990* self);
void func_0028A180(S_00289990* self);
char* strncpy(char* d, const char* s, int n);
void func_0033C320(S_00289990* self, int a);
int GuiScreen_HandleInput(S_00289990* self, Ev_00289990* ev);
}
static inline unsigned char Down_00289990(Ev_00289990* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->f2 == 0)
        r = 1;
    return r;
}
static inline unsigned char Btn_00289990(Ev_00289990* e, unsigned int b)
{
    unsigned char r = 0;
    if (Down_00289990(e) && e->btn == b)
        r = 1;
    return r;
}
static inline unsigned char Press_00289990(Ev_00289990* e, unsigned int b)
{
    unsigned char r = 0;
    if (Btn_00289990(e, b) && e->f6 == 0)
        r = 1;
    return r;
}
extern "C" int func_00289990(S_00289990* self, Ev_00289990* ev)
{
    if (Press_00289990(ev, 0x10)) {
        void* ui = D_004FFC04;
        FrontEnd_OpenPopup(ui, 5, D_004A9730, func_0033CE30(self, 0xE, 0, 0, 0, 0), self, 0x1E);
        return 1;
    } else {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x80 && ev->f6 == 0;
        if (b) {
            if (!self->bAD)
                func_00289440(self);
            else
                func_00288E90(self);
            return 1;
        } else {
            bool c = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x2000 && ev->f6 == 0;
            if (c) {
                if (Gui_GetScreenStack()->f20 == self->p88) {
                    func_0028A230(self);
                    return 1;
                }
                if (Gui_GetScreenStack()->f20 == self->p90) {
                    func_0028A180(self);
                    return 1;
                }
            }
        }
    }
    {
        bool d = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x20 && ev->f6 == 0;
        if (d) {
            D_00506350[0] = 0;
            D_00506340[0] = 0;
            D_00506360 = self->bA4;
            if (self->p8C && self->p94) {
                strncpy(D_00506340, String_CStr(self->p94->s48), 0xF);
                strncpy(D_00506350, String_CStr(self->p8C->s48), 0xF);
            }
            D_004FFC04->f268 = 7;
            func_0033C320(self, 5);
            return 1;
        }
    }
    return GuiScreen_HandleInput(self, ev);
}
#undef D_004FFC04 /* merge_units */
#undef func_0033CE30 /* merge_units */
#undef FrontEnd_OpenPopup /* merge_units */
#undef func_00289440 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00289990 */

/* merge_units: begin func_00289C80 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Fl_00289C80 { char pad[0x14]; unsigned short flags; };
struct Txt_00289C80 { char pad[0x14]; unsigned short flags; char pad16[0x32]; char s48[4]; };
struct Ag_00289C80 { char pad[0x8CC]; char name[4]; };
struct Mgr_00289C80 { char pad[0x265]; unsigned char b265; };
struct S_00289C80 {
    char pad0[0x4C]; unsigned char b4C; char pad4D[0x3B]; Txt_00289C80* p88; Txt_00289C80* p8C; Txt_00289C80* p90; Txt_00289C80* p94; Txt_00289C80* p98;
    Ag_00289C80* p9C; void* pA0; unsigned char bA4; char padA5[7]; unsigned char bAC; unsigned char bAD;
};
extern "C" {
extern unsigned char D_00506378;
#if 0 /* merge_units */
extern Mgr_00289C80* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(Mgr_00289C80 **)&D_004FFC04) /* merge_units */

extern char D_004A96F8[];
extern char D_004A9708[];
extern char D_004A9718[];
extern char D_004A9720[];
int GuiScreen_HandleEvent(S_00289C80* self, void* w, int msg, int sub);
#if 0 /* merge_units */
void func_0028A230(S_00289C80* self);
#endif /* merge_units */
#define func_0028A230(a0) (func_0028A230((S_00289990 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void func_0028A180(S_00289C80* self);
#endif /* merge_units */
#define func_0028A180(a0) (func_0028A180((S_00289990 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void func_00289440(S_00289C80* self);
#endif /* merge_units */
#define func_00289440(a0) ((void)func_00289440((S_00289440 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void func_00288E90(S_00289C80* self);
#endif /* merge_units */
#define func_00288E90(a0) (func_00288E90((S_00289990 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void* Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((void *)Gui_GetScreenStack()) /* merge_units */

void GuiScreen_SetFocus(void* ui, void* w);
#if 0 /* merge_units */
char* AgentData_GetName(Ag_00289C80* ag);
#endif /* merge_units */
#define AgentData_GetName(a0) (AgentData_GetName((Ag_00289440 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void SaveAgentWidget_Rename(S_00289C80* self, char* n);
#endif /* merge_units */
#define SaveAgentWidget_Rename(a0, a1) (SaveAgentWidget_Rename((S_00289440 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void GuiSaveAgentWidget_HandleEvent(S_00289C80* self);
#endif /* merge_units */
#define GuiSaveAgentWidget_HandleEvent(a0) (GuiSaveAgentWidget_HandleEvent((S_00289440 *)(a0))) /* merge_units */

char* Loc_LookupText(char* key);
void GuiTextWidget_SetText(void* w, char* s, int a);
void func_002CA640(void* ui, int a);
void* Gui_GetScreenList(void);
void* GuiManager_FindOrLoad(void* a, char* b, char* c);
void GuiStack_SwapScreens(void* ui, S_00289C80* self, void* pg);
}
static inline int StrNe_00289C80(const char* a, const char* b) { return strcmp(a, b); }
extern "C" int func_00289C80(S_00289C80* self, void* w, int msg, int sub, char* text)
{
    unsigned short m;
    if (D_00506378)
        return GuiScreen_HandleEvent(self, w, msg, sub);
    m = msg;
    if (m == 2) {
        Txt_00289C80* a = self->p88;
        if (w == a && self->p8C) {
            func_0028A230(self);
        } else if (w == self->p90 && self->p94) {
            func_0028A180(self);
        } else if (w == self->p98) {
            D_00506378 = 1;
            if (!self->bAD)
                func_00289440(self);
            else
                func_00288E90(self);
            D_00506378 = 0;
        } else if (w == self->p8C) {
            if (a)
                a->flags |= 4;
            if (self->p90)
                self->p90->flags |= 4;
            if (self->p98)
                self->p98->flags |= 4;
            self->p8C->flags &= ~4;
            GuiScreen_SetFocus(Gui_GetScreenStack(), self->p88);
        } else if (w == self->p94) {
            if (a)
                a->flags |= 4;
            if (self->p90)
                self->p90->flags |= 4;
            if (self->p98)
                self->p98->flags |= 4;
            self->p94->flags &= ~4;
            GuiScreen_SetFocus(Gui_GetScreenStack(), self->p90);
        } else {
            return GuiScreen_HandleEvent(self, w, msg, sub);
        }
        return 1;
    }
    if (m == 0x1A || m == 0x1B) {
        if (m == 0x1A) {
            if (sub == 0x23 || sub == 0x24) {
                unsigned char changed;
                char* cur;
                char* n;
                self->bAC = 1;
                changed = 0;
                cur = self->p9C->name;
                if (StrNe_00289C80(String_CStr(self->p94->s48), cur)) {
                    String_Copy(self->p9C->name, String_CStr(self->p94->s48));
                    changed = 1;
                }
                n = String_CStr(self->p8C->s48);
                if (strcmp(n, AgentData_GetName(self->p9C))) {
                    SaveAgentWidget_Rename(self, String_CStr(self->p8C->s48));
                } else {
                    unsigned char* f = &D_004FFC04->b265;
                    if (*f)
                        changed = 1;
                    if (changed) {
                        *f = 0;
                        self->b4C = 1;
                        GuiSaveAgentWidget_HandleEvent(self);
                    } else {
                        if (self->pA0)
                            GuiTextWidget_SetText(self->pA0, Loc_LookupText(D_004A96F8), 0);
                        if (self->p98)
                            GuiTextWidget_SetText(self->p98, Loc_LookupText(D_004A9718), 0);
                        self->bAD = 0;
                    }
                }
                return 1;
            }
            if (sub == 0x1F) {
                if (self->pA0)
                    GuiTextWidget_SetText(self->pA0, Loc_LookupText(D_004A9708), 0);
                if (self->p98)
                    GuiTextWidget_SetText(self->p98, Loc_LookupText(D_004A9720), 0);
                self->bAD = 1;
                return 1;
            }
            if (sub == 0x1E) {
                void* pg;
                func_002CA640(D_004FFC04, 1);
                pg = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiOnlineOfflineSelect", "ONOFFSEL");
                GuiStack_SwapScreens(Gui_GetScreenStack(), self, pg);
                return 1;
            }
            if (sub == 0x21) {
                if (self->p8C) {
                    GuiTextWidget_SetText(self->p8C, text ? text : D_004A9730, 0);
                }
                return 1;
            }
            if (sub == 0x22) {
                if (self->p94) {
                    GuiTextWidget_SetText(self->p94, text ? text : D_004A9730, 0);
                }
                return 1;
            }
            if (sub == 0x25) {
                self->bA4 = 1;
                func_0028A230(self);
                return 1;
            }
        }
    }
    return GuiScreen_HandleEvent(self, w, msg, sub);
}
#undef D_004FFC04 /* merge_units */
#undef func_0028A230 /* merge_units */
#undef func_0028A180 /* merge_units */
#undef func_00289440 /* merge_units */
#undef func_00288E90 /* merge_units */
#undef Gui_GetScreenStack /* merge_units */
#undef AgentData_GetName /* merge_units */
#undef SaveAgentWidget_Rename /* merge_units */
#undef GuiSaveAgentWidget_HandleEvent /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00289C80 */
