/*
 * main/GuiAccountLogin: 3 files, 00288DE0-002891D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00288DE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
typedef struct { char pad[0x98]; void* w98; char pad9C[4]; void* wA0; char padA4[9]; char flagAD; } SelfDE0;
extern "C" char* nGlobalization_GetString_charP(const char*);
extern "C" void GuiTextWidget_SetText(void*, char*, int);
extern "C" void GuiAccountLogin_SetMode(SelfDE0* self, char flag)
{
    if (self->wA0)
        GuiTextWidget_SetText(self->wA0, nGlobalization_GetString_charP((unsigned char)flag == 0 ? "LoginAccount" : "CreateAccount"), 0);
    if (self->w98)
        GuiTextWidget_SetText(self->w98, nGlobalization_GetString_charP((unsigned char)flag == 0 ? "Login" : "Register"), 0);
    self->flagAD = flag;
}
#pragma pop /* merge_units */
/* merge_units: end func_00288DE0 */

/* merge_units: begin func_00288E90 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Str_00288E90 { char d[0x10]; };
struct Txt_00288E90 { char pad[0x48]; char s48[4]; };
struct S_00288E90 { char pad0[0x8C]; Txt_00288E90* p8C; char pad90[4]; Txt_00288E90* p94; char pad98[0x10]; int fA8; };
extern "C" {
extern void* D_004FFC04;
const unsigned int D_004A9730[4] = { 0x0, 0x0, 0x0, 0x0 };
void* cDME_GetLobby(void);
char* std_basic_string_char_char_traits_char_c_str(void* s);
int strlen(const char* s);
char* GuiLobbyScreen_GetLobbyString(S_00288E90* self, unsigned char a, char* b, int c, int d, int e);
void std_basic_string_char_char_traits_char_ctor_charP(Str_00288E90* s, const char* c);
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, char* c, S_00288E90* d, int e);
void String_Dtor(Str_00288E90* s, int flags);
int SFOLobby_AccountCreate(void* g, char* a, char* b);
unsigned char SFOLobby_GetErrorDetails(void* g, int a);
int func_004459D0(void* g, char* a, char* b);
void cGameFrontEnd_PopMessageBox(void* ui, int id);
}
extern "C" void GuiAccountLogin_RegisterAccount(S_00288E90* self)
{
    void* g = cDME_GetLobby();
    char* pw;
    if (!std_basic_string_char_char_traits_char_c_str(self->p94->s48) || !strlen(std_basic_string_char_char_traits_char_c_str(self->p94->s48))) {
        Str_00288E90 a;
        Str_00288E90 b;
        std_basic_string_char_char_traits_char_ctor_charP(&a, GuiLobbyScreen_GetLobbyString(self, 0x20, 0, 0, 0, 0));
        std_basic_string_char_char_traits_char_ctor_charP(&b, GuiLobbyScreen_GetLobbyString(self, 0x8C, 0, 0, 0, 0));
        {
            char* tb = std_basic_string_char_char_traits_char_c_str(&b);
            cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&a), tb, 0, 0);
        }
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
        return;
    }
    {
        void* ui = D_004FFC04;
        self->fA8 = cGameFrontEnd_PushMessageBox(ui, 0, ((char*)D_004A9730), GuiLobbyScreen_GetLobbyString(self, 0x26, 0, 0, 0, 0), 0, 0);
    }
    pw = std_basic_string_char_char_traits_char_c_str(self->p94->s48);
    if ((unsigned char)SFOLobby_AccountCreate(g, std_basic_string_char_char_traits_char_c_str(self->p8C->s48), pw)) {
        void* ui = D_004FFC04;
        cGameFrontEnd_PushMessageBox(ui, 2, ((char*)D_004A9730), GuiLobbyScreen_GetLobbyString(self, 0x25, 0, 0, 0, 0), self, 0x23);
    } else {
        int cb;
        int code;
        unsigned char r = SFOLobby_GetErrorDetails(g, 0);
        cb = -1;
        if (r == 0x3D) {
            char* pw2 = std_basic_string_char_char_traits_char_c_str(self->p94->s48);
            if (func_004459D0(g, std_basic_string_char_char_traits_char_c_str(self->p8C->s48), pw2)) {
                code = 0x24;
                cb = code;
            } else {
                code = 0x23;
            }
        } else if (r == 3) {
            code = 0x21;
        } else {
            code = 0x22;
        }
        if (code != -1) {
            Str_00288E90 c;
            Str_00288E90 d;
            S_00288E90* tgt;
            std_basic_string_char_char_traits_char_ctor_charP(&c, GuiLobbyScreen_GetLobbyString(self, 0x20, 0, 0, 0, 0));
            std_basic_string_char_char_traits_char_ctor_charP(&d, GuiLobbyScreen_GetLobbyString(self, code, std_basic_string_char_char_traits_char_c_str(self->p8C->s48), 0, 0, 0));
            tgt = cb == -1 ? 0 : self;
            {
                pw = std_basic_string_char_char_traits_char_c_str(&d);
                cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&c), pw, tgt, cb);
            }
            String_Dtor(&d, 0);
            String_Dtor(&c, 0);
        }
    }
    cGameFrontEnd_PopMessageBox(D_004FFC04, self->fA8);
}
#pragma pop /* merge_units */
/* merge_units: end func_00288E90 */

/* merge_units: begin func_002891D0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Str_002891D0 { char d[0x10]; };
struct Pg_002891D0 { char pad[0x10]; int f10; unsigned short flags; };
struct Ui_002891D0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual void Show(void* p, int a); virtual void Hide(void* p);
};
struct Mgr_002891D0 { char pad[0x264]; unsigned char b264; };
struct S_002891D0 { char pad0[0x98]; void* p98; char pad9C[4]; void* pA0; char padA4[4]; int fA8; unsigned char bAC; unsigned char bAD; };
extern "C" {
#if 0 /* merge_units */
extern Mgr_002891D0* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(Mgr_002891D0 **)&D_004FFC04) /* merge_units */

extern char D_004A96F8[];
extern char D_004A9718[];
#if 0 /* merge_units */
char* nGlobalization_GetString_charP(char* key);
#endif /* merge_units */
#define nGlobalization_GetString_charP(a0) ((char *)nGlobalization_GetString_charP((const char *)(a0))) /* merge_units */

#if 0 /* merge_units */
void GuiTextWidget_SetText(void* w, char* s, int a);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) ((void)GuiTextWidget_SetText((a0), (a1), (a2))) /* merge_units */

void cGameFrontEnd_LobbyStopAccountScreen(void* ui);
void cGameFrontEnd_LobbyCallback(void);
int func_00442750(void* g, void* cb);
#if 0 /* merge_units */
char* GuiLobbyScreen_GetLobbyString(S_002891D0* self, int a, int b, int c, int d, int e);
#endif /* merge_units */
#define GuiLobbyScreen_GetLobbyString(a0, a1, a2, a3, a4, a5) (GuiLobbyScreen_GetLobbyString((S_00288E90 *)(a0), (unsigned char)(a1), (char *)(a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
void std_basic_string_char_char_traits_char_ctor_charP(Str_002891D0* s, const char* c);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) (std_basic_string_char_char_traits_char_ctor_charP((Str_00288E90 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
char* std_basic_string_char_char_traits_char_c_str(Str_002891D0* s);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_c_str(a0) (std_basic_string_char_char_traits_char_c_str((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, char* c, S_002891D0* d, int e);
#endif /* merge_units */
#define cGameFrontEnd_PushMessageBox(a0, a1, a2, a3, a4, a5) (cGameFrontEnd_PushMessageBox((a0), (a1), (a2), (a3), (S_00288E90 *)(a4), (a5))) /* merge_units */

#if 0 /* merge_units */
void String_Dtor(Str_002891D0* s, int flags);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str_00288E90 *)(a0), (a1))) /* merge_units */

void* Gui_Manager(void);
Pg_002891D0* GuiManager_OpenGui(void* a, char* b, char* c);
Pg_002891D0* GuiManager_FindOpenGui(void* a, char* b);
Ui_002891D0* Gui_Canvas(void);
void GuiWidget_SendMessage(void* a, void* b, int c, int d, int e);
}
extern "C" void func_002891D0(S_002891D0* self)
{
    void* g;
    unsigned char ok;
    if (self->bAC) {
        if (self->pA0)
            GuiTextWidget_SetText(self->pA0, nGlobalization_GetString_charP(D_004A96F8), 0);
        if (self->p98)
            GuiTextWidget_SetText(self->p98, nGlobalization_GetString_charP(D_004A9718), 0);
        self->bAD = 0;
        return;
    }
    g = cDME_GetLobby();
    if (!g)
        return;
    ok = 1;
    cGameFrontEnd_LobbyStopAccountScreen(D_004FFC04);
    if (!func_00442750(g, (void*)cGameFrontEnd_LobbyCallback)) {
        Str_002891D0 a;
        Str_002891D0 b;
        std_basic_string_char_char_traits_char_ctor_charP(&a, GuiLobbyScreen_GetLobbyString(self, 0x1F, 0, 0, 0, 0));
        std_basic_string_char_char_traits_char_ctor_charP(&b, GuiLobbyScreen_GetLobbyString(self, 0x88, 0, 0, 0, 0));
        {
            char* tb = std_basic_string_char_char_traits_char_c_str(&b);
            cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&a), tb, self, 0x1E);
        }
        cGameFrontEnd_PopMessageBox(D_004FFC04, self->fA8);
        ok = 0;
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
    } else {
        Pg_002891D0* p = GuiManager_OpenGui(Gui_Manager(), "GuiCommandCenter", "CMDCENTR");
        if (p) {
            p->f10 = 1;
            p->flags &= ~2;
            Gui_Canvas()->Show(p, 0);
        }
        cGameFrontEnd_PopMessageBox(D_004FFC04, self->fA8);
    }
    D_004FFC04->b264 = ok;
    if (ok) {
        Pg_002891D0* q;
        Gui_Canvas()->Hide(self);
        q = GuiManager_FindOpenGui(Gui_Manager(), "GuiCommandCenter");
        if (q) {
            q->flags |= 2;
            GuiWidget_SendMessage(q, Gui_Canvas(), 0x10, 2, 0);
        }
    }
}
#undef D_004FFC04 /* merge_units */
#undef nGlobalization_GetString_charP /* merge_units */
#undef GuiTextWidget_SetText /* merge_units */
#undef GuiLobbyScreen_GetLobbyString /* merge_units */
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef std_basic_string_char_char_traits_char_c_str /* merge_units */
#undef cGameFrontEnd_PushMessageBox /* merge_units */
#undef String_Dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002891D0 */
