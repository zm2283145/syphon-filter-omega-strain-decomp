/*
 * main/GuiOnlineConnect: 3 files, 0029E1A0-0029E8C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0029E1A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct Str_0029E1A0 { char d[0x10]; };
struct S_0029E1A0 { char pad0[0x48]; int f48; char pad4C[0x3C]; int f88; char pad8C[0x120 - 0x8C]; int f120; };
extern "C" {
extern void* D_004FFC04;
extern unsigned char g_DebugTriangle;
extern char D_004AABF0[];
void GuiLobbyScreen_onAdvanceTime(S_0029E1A0* self);
void FrontEnd_StartSplashThread(void* ui);
void FrontEnd_StopMusic(void* ui);
void* cDME_GetLobby(void);
int cGameFrontEnd_LobbyCreate(void* ui);
char* GuiLobbyScreen_GetLobbyString(S_0029E1A0* self, int a, int b, int c, int d, int e);
void std_basic_string_char_char_traits_char_ctor_charP(Str_0029E1A0* s, const char* c);
char* std_basic_string_char_char_traits_char_c_str(Str_0029E1A0* s);
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, char* c, S_0029E1A0* d, int e);
void cGameFrontEnd_PlayMusic(void* ui, int a);
void cGameFrontEnd_PopMessageBox(void* ui, int id);
void FrontEnd_StopSplashThread(void* ui);
void String_Dtor(Str_0029E1A0* s, int flags);
void GuiOnlineConnect_ListConfigs(S_0029E1A0* self);
void GuiOnlineConnect_Back(S_0029E1A0* self, int a);
void cGameFrontEnd_LobbyStartAccountScreen(void* ui);
void SFOLobby_GetAnnouncements(void* g);
int SFOLobby_GetUsagePolicy(void* g);
void SFOLobby_GetPrivacyPolicy(void* g);
void GuiOnlineConnect_Advance(S_0029E1A0* self);
}
extern "C" void GuiOnlineConnect_Update(S_0029E1A0* self)
{
    GuiLobbyScreen_onAdvanceTime(self);
    if (g_DebugTriangle)
        return;
    if (!self->f88) {
        FrontEnd_StartSplashThread(D_004FFC04);
        self->f88 = 2;
    }
    if (self->f88 == 2) {
        FrontEnd_StopMusic(D_004FFC04);
        if (!cDME_GetLobby() && !cGameFrontEnd_LobbyCreate(D_004FFC04)) {
            Str_0029E1A0 a;
            Str_0029E1A0 b;
            self->f88 = 4;
            std_basic_string_char_char_traits_char_ctor_charP(&a, GuiLobbyScreen_GetLobbyString(self, 1, 0, 0, 0, 0));
            std_basic_string_char_char_traits_char_ctor_charP(&b, GuiLobbyScreen_GetLobbyString(self, 4, 0, 0, 0, 0));
            {
                char* tb = std_basic_string_char_char_traits_char_c_str(&b);
                cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&a), tb, self, 0);
            }
            cGameFrontEnd_PlayMusic(D_004FFC04, 0);
            cGameFrontEnd_PopMessageBox(D_004FFC04, self->f48);
            FrontEnd_StopSplashThread(D_004FFC04);
            String_Dtor(&b, 0);
            String_Dtor(&a, 0);
            return;
        }
        GuiOnlineConnect_ListConfigs(self);
        FrontEnd_StopSplashThread(D_004FFC04);
        cGameFrontEnd_PopMessageBox(D_004FFC04, self->f48);
        cGameFrontEnd_PlayMusic(D_004FFC04, 0);
    }
    if (self->f88 == 7) {
        unsigned char done;
        void* g = cDME_GetLobby();
        if (!g) {
            GuiOnlineConnect_Back(self, 1);
            done = 0;
        } else {
            void* ui = D_004FFC04;
            int h = cGameFrontEnd_PushMessageBox(ui, 0, D_004AABF0, GuiLobbyScreen_GetLobbyString(self, 0xD, 0, 0, 0, 0), 0, 0);
            if (self->f120 != -1)
                cGameFrontEnd_PopMessageBox(D_004FFC04, self->f120);
            cGameFrontEnd_LobbyStartAccountScreen(D_004FFC04);
            SFOLobby_GetAnnouncements(g);
            if (SFOLobby_GetUsagePolicy(g))
                SFOLobby_GetPrivacyPolicy(g);
            cGameFrontEnd_PopMessageBox(D_004FFC04, h);
            done = 1;
        }
        if (done)
            GuiOnlineConnect_Advance(self);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0029E1A0 */

/* merge_units: begin func_0029E440 */
#pragma push /* merge_units */
#pragma cplusplus on
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
extern char D_004AAC18[];
extern char D_004AAC28[];
extern char g_Video[];
extern char g_Game[];
extern char D_004F2CC0[];
extern int* g_MemCard;
extern char D_004FFBA4[];
extern "C" char D_004AABC8[];
static void * const dat_0048B988[2] = { (void*)D_004AABC8, (void*)0x0 };
int SFOLobby_GetDNASError(void* g);
void GuiOnlineConnect_ShowGroup(S_0029E440* self, int a);
void GuiOnlineConnect_Connect(S_0029E440* self, char* t);
Ui_0029E440* Gui_Canvas(void);
Fl_0029E440* GuiWidget_FindChild_charP(void* p, char* name);
#if 0 /* merge_units */
int GuiLobbyScreen_GetLobbyString(S_0029E440* self, int a, int b, int c, int d, int e);
#endif /* merge_units */
#define GuiLobbyScreen_GetLobbyString(a0, a1, a2, a3, a4, a5) ((int)GuiLobbyScreen_GetLobbyString((S_0029E1A0 *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, int c, S_0029E440* d, int e);
#endif /* merge_units */
#define cGameFrontEnd_PushMessageBox(a0, a1, a2, a3, a4, a5) (cGameFrontEnd_PushMessageBox((a0), (a1), (a2), (char *)(a3), (S_0029E1A0 *)(a4), (a5))) /* merge_units */

void GuiOnlineConnect_DnasRetry(S_0029E440* self);
void Renderer_Teardown(void* p);
void* cSystemContainer_GetSystem(void* a, void* b);
void cGameSound_Unload(void* svc);
void sceMc2DeleteSocket(int id);
void sceMc2End(void);
void* cString_CStr(void* p);
void SFOLobby_ConfigLaunchNetGui(void* a, char* b);
#if 0 /* merge_units */
void GuiOnlineConnect_Back(S_0029E440* self, int a);
#endif /* merge_units */
#define GuiOnlineConnect_Back(a0, a1) (GuiOnlineConnect_Back((S_0029E1A0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void GuiOnlineConnect_Advance(S_0029E440* self);
#endif /* merge_units */
#define GuiOnlineConnect_Advance(a0) (GuiOnlineConnect_Advance((S_0029E1A0 *)(a0))) /* merge_units */

int GuiLobbyScreen_onMessage(S_0029E440* self, void* w, int msg, int sub);
}
extern "C" int GuiOnlineConnect_HandleEvent(S_0029E440* self, void* w, int msg, int sub, char* text)
{
    unsigned short m = msg;
    if (m == 0x2002) {
        unsigned char ok = 0;
        if (cDME_GetLobby()) {
            int st = SFOLobby_GetDNASError(cDME_GetLobby());
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
        GuiOnlineConnect_ShowGroup(self, 4);
        GuiOnlineConnect_Connect(self, self->f90);
        return 1;
    }
    if (m == 0x2001) {
        void* p = self->p108;
        if (p) {
            Fl_0029E440* a;
            Fl_0029E440* b;
            int old;
            void* ui;
            Gui_Canvas()->Show(p, 0x7D0);
            a = GuiWidget_FindChild_charP(self->p108, D_004AAC18);
            if (a)
                a->flags &= ~2;
            b = GuiWidget_FindChild_charP(self->p108, D_004AAC28);
            if (b)
                b->flags |= 2;
            old = self->f11C;
            ui = D_004FFC04;
            self->f11C = cGameFrontEnd_PushMessageBox(ui, 0, D_004AABF0, GuiLobbyScreen_GetLobbyString(self, 0x82, 0, 0, 0, 0), 0, 0);
            if (old != -1)
                cGameFrontEnd_PopMessageBox(D_004FFC04, old);
        }
        return 1;
    }
    if (m == 0x1B || m == 0x1A) {
        if (sub == 0x20) {
            GuiOnlineConnect_DnasRetry(self);
            return 1;
        }
        if (self->f88 == 3) {
            if (m == 0x1A) {
                void* svc;
                int id;
                Renderer_Teardown(g_Video);
                svc = cSystemContainer_GetSystem(g_Game, D_004F2CC0);
                if (svc)
                    cGameSound_Unload(svc);
                id = g_MemCard ? *g_MemCard : -1;
                if (id != -1)
                    sceMc2DeleteSocket(id);
                sceMc2End();
                SFOLobby_ConfigLaunchNetGui(cString_CStr(D_004FFBA4), (*(char**)dat_0048B988));
            } else if (sub == 0x1F) {
                self->f88 = 5;
            } else {
                GuiOnlineConnect_Back(self, 0);
            }
        }
        if (self->f88 == 4 && m == 0x1A)
            GuiOnlineConnect_Back(self, 0);
        if (sub == 0x1E && m == 0x1A)
            GuiOnlineConnect_Back(self, 0);
        return 1;
    }
    if (m == 2) {
        if (w == self->fF8 || w == self->fFC) {
            if (self->f88 == 1) {
                GuiOnlineConnect_ShowGroup(self, 4);
                if (w == self->fF8) {
                    GuiOnlineConnect_Connect(self, self->f90);
                } else {
                    void* ui = D_004FFC04;
                    cGameFrontEnd_PushMessageBox(ui, 5, D_004AABF0, GuiLobbyScreen_GetLobbyString(self, 0xE, 0, 0, 0, 0), self, 0x1E);
                }
            } else if (w == self->fF8) {
                GuiOnlineConnect_Advance(self);
            } else {
                void* ui = D_004FFC04;
                cGameFrontEnd_PushMessageBox(ui, 5, D_004AABF0, GuiLobbyScreen_GetLobbyString(self, 0xE, 0, 0, 0, 0), self, 0x1E);
            }
            return 1;
        }
        if (w == self->f104) {
            GuiOnlineConnect_Advance(self);
            return 1;
        }
    }
    return GuiLobbyScreen_onMessage(self, w, msg, sub);
}
#undef GuiLobbyScreen_GetLobbyString /* merge_units */
#undef cGameFrontEnd_PushMessageBox /* merge_units */
#undef GuiOnlineConnect_Back /* merge_units */
#undef GuiOnlineConnect_Advance /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029E440 */

/* merge_units: begin func_0029E8C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ev_0029E8C0 { unsigned short type; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short btn; };
struct Str_0029E8C0 { char d[0x10]; };
struct Fl_0029E8C0 { char pad[0x14]; unsigned short flags; };
struct S_0029E8C0 {
    char pad0[0x88]; int f88; char pad8C[0xF4 - 0x8C]; void* pF4; char padF8[8]; void* p100; char pad104[0xC]; Fl_0029E8C0* p110; Fl_0029E8C0* p114;
};
extern "C" {
#if 0 /* merge_units */
void GuiOnlineConnect_Back(S_0029E8C0* self, int a);
#endif /* merge_units */
#define GuiOnlineConnect_Back(a0, a1) (GuiOnlineConnect_Back((S_0029E1A0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
char* GuiLobbyScreen_GetLobbyString(S_0029E8C0* self, int a, int b, int c, int d, int e);
#endif /* merge_units */
#define GuiLobbyScreen_GetLobbyString(a0, a1, a2, a3, a4, a5) (GuiLobbyScreen_GetLobbyString((S_0029E1A0 *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, char* c, S_0029E8C0* d, int e);
#endif /* merge_units */
#define cGameFrontEnd_PushMessageBox(a0, a1, a2, a3, a4, a5) (cGameFrontEnd_PushMessageBox((a0), (a1), (a2), (a3), (S_0029E1A0 *)(a4), (a5))) /* merge_units */

#if 0 /* merge_units */
void std_basic_string_char_char_traits_char_ctor_charP(Str_0029E8C0* s, const char* c);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) (std_basic_string_char_char_traits_char_ctor_charP((Str_0029E1A0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
char* std_basic_string_char_char_traits_char_c_str(Str_0029E8C0* s);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_c_str(a0) (std_basic_string_char_char_traits_char_c_str((Str_0029E1A0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void String_Dtor(Str_0029E8C0* s, int flags);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str_0029E1A0 *)(a0), (a1))) /* merge_units */

void GuiMLTextWidget_ScrollUp(void* p, int a);
void GuiMLTextWidget_ScrollDown(void* p, int a);
int GuiLobbyScreen_onInput(S_0029E8C0* self, Ev_0029E8C0* ev);
}
static inline unsigned char Down_0029E8C0(Ev_0029E8C0* e)
{
    unsigned char r = 0;
    if (e->type == 1 && e->f2 == 0)
        r = 1;
    return r;
}
static inline unsigned char Btn_0029E8C0(Ev_0029E8C0* e, unsigned int b)
{
    unsigned char r = 0;
    if (Down_0029E8C0(e) && e->btn == b)
        r = 1;
    return r;
}
static inline unsigned char Press_0029E8C0(Ev_0029E8C0* e, unsigned int b)
{
    unsigned char r = 0;
    if (Btn_0029E8C0(e, b) && e->f6 == 0)
        r = 1;
    return r;
}
extern "C" int GuiOnlineConnect_onInput(S_0029E8C0* self, Ev_0029E8C0* ev)
{
    if (Press_0029E8C0(ev, 0x10)) {
        if (self->f88 == 5 || self->f88 == 1) {
            GuiOnlineConnect_Back(self, 0);
        } else {
            void* ui = D_004FFC04;
            cGameFrontEnd_PushMessageBox(ui, 5, D_004AABF0, GuiLobbyScreen_GetLobbyString(self, 0xE, 0, 0, 0, 0), self, 0x1E);
        }
        return 1;
    } else {
        bool b = ev->type == 1 && ev->f2 == 0 && ev->btn == 0x20 && ev->f6 == 0;
        if (b) {
            if (self->f88 == 5) {
                Str_0029E8C0 a;
                Str_0029E8C0 c;
                self->f88 = 3;
                std_basic_string_char_char_traits_char_ctor_charP(&a, GuiLobbyScreen_GetLobbyString(self, 7, 0, 0, 0, 0));
                std_basic_string_char_char_traits_char_ctor_charP(&c, GuiLobbyScreen_GetLobbyString(self, 8, 0, 0, 0, 0));
                {
                    char* tc = std_basic_string_char_char_traits_char_c_str(&c);
                    cGameFrontEnd_PushMessageBox(D_004FFC04, 5, std_basic_string_char_char_traits_char_c_str(&a), tc, self, 0x1F);
                }
                String_Dtor(&c, 0);
                String_Dtor(&a, 0);
            }
            return 1;
        } else {
            bool d = ev->type == 1 && ev->f2 == 0 && ev->btn == 8 && ev->f6 == 0;
            if (d) {
                if (self->p110 && (self->p110->flags & 2))
                    GuiMLTextWidget_ScrollUp(self->pF4, 0);
                else if (self->p114 && (self->p114->flags & 2))
                    GuiMLTextWidget_ScrollUp(self->p100, 0);
                return 1;
            } else {
                bool e = ev->type == 1 && ev->f2 == 0 && ev->btn == 4 && ev->f6 == 0;
                if (e) {
                    if (self->p110 && (self->p110->flags & 2))
                        GuiMLTextWidget_ScrollDown(self->pF4, 0);
                    else if (self->p114 && (self->p114->flags & 2))
                        GuiMLTextWidget_ScrollDown(self->p100, 0);
                    return 1;
                }
            }
        }
    }
    return GuiLobbyScreen_onInput(self, ev);
}
#undef GuiOnlineConnect_Back /* merge_units */
#undef GuiLobbyScreen_GetLobbyString /* merge_units */
#undef cGameFrontEnd_PushMessageBox /* merge_units */
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef std_basic_string_char_char_traits_char_c_str /* merge_units */
#undef String_Dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029E8C0 */
