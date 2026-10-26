#pragma cplusplus on
#include "types.h"
struct Str_0029CBB0 { int a; int b; int c; };
static inline void StrInit_0029CBB0(Str_0029CBB0* p) { int k; int* w = &p->a; for (k = 0; k < 3; k++) w[k] = 0; }
struct Name_0029CBB0 { char name[4]; };
struct Tab_0029CBB0 { char pad[0x14]; unsigned short flags; };
struct NameList_0029CBB0 { char pad[4]; int count; };
struct Ent_0029CBB0 { int id; char name[4]; };
struct Ui_0029CBB0 { char pad[0x2F0]; NameList_0029CBB0* l2F0; NameList_0029CBB0* l2F4; NameList_0029CBB0* l2F8; };
struct S_0029CBB0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual int v15();
    char pad4[0x88 - 4]; int f88; char pad8C[0xF0 - 0x8C]; void* pF0; void* pF4; char padF8[0x100 - 0xF8]; void* p100;
    char pad104[0x10C - 0x104]; Tab_0029CBB0* tabs[3]; int f118;
};
extern "C" {
extern Ui_0029CBB0* D_004FFC04;
extern char D_004AABF0[];
char* Loc_LookupText(char* key);
void GuiTextWidget_SetText(void* w, char* s, int a);
void* Gui_GetScreenStack(void);
void GuiScreen_SetFocus(void* mgr, int a);
int GuiScreen_GetLobbyString(S_0029CBB0* self, int a, int b, int c, int d, int e);
int FrontEnd_OpenPopup(void* ui, int a, char* b, int c, S_0029CBB0* d, int e);
void MLTextWidget_Clear(void* w);
void MLTextWidget_AddText(void* w, char* s);
Ent_0029CBB0* LobbyArray_At(NameList_0029CBB0* l, int i);
void LobbyArray_RemoveAt(NameList_0029CBB0* l, int i);
void LobbyArray_Clear(NameList_0029CBB0* l);
void String_CtorCStr_13B480(Str_0029CBB0* s, const char* c);
void std_basic_string_char_char_traits_char_append_basicstringR(Str_0029CBB0* d, Str_0029CBB0* s);
void func_003FD740(Str_0029CBB0* s);
char* String_CStr(Str_0029CBB0* s);
int String_Length(Str_0029CBB0* s);
void String_Dtor(Str_0029CBB0* s, int flags);
}
static inline void SetText_0029CBB0(S_0029CBB0* self, char* key)
{
    char* t = Loc_LookupText(key);
    if (self->pF0 && t)
        GuiTextWidget_SetText(self->pF0, t, 0);
}
/* Selects one of the three tabs of the page and fills its list widget. */
extern "C" void GuiOnlineConnect_ShowGroup(S_0029CBB0* self, unsigned char sel)
{
    int i;
    Str_0029CBB0 list1;
    Str_0029CBB0 list2;
    for (i = 0; i < 3; i++) {
        if (self->tabs[i])
            self->tabs[i]->flags &= ~2;
    }
    if (sel == 4) {
        self->f118 = 4;
        return;
    }
    {
        if (self->tabs[sel]) {
            self->tabs[sel]->flags |= 2;
            self->tabs[sel]->flags |= 4;
        }
        {
            void* mgr = Gui_GetScreenStack();
            GuiScreen_SetFocus(mgr, self->v15());
        }
        if (sel == 1) {
            NameList_0029CBB0* l = 0;
            if (self->f88 == 8) {
                SetText_0029CBB0(self, "PolicyTitle1");
                l = D_004FFC04->l2F0;
            } else if (self->f88 == 9) {
                SetText_0029CBB0(self, "PolicyTitle2");
                l = D_004FFC04->l2F4;
            }
            if (!l) {
                void* ui = D_004FFC04;
                FrontEnd_OpenPopup(ui, 2, D_004AABF0, GuiScreen_GetLobbyString(self, 5, 0, 0, 0, 0), self, 0);
                self->f88 = 4;
                return;
            }
            if (self->pF4) {
                MLTextWidget_Clear(self->pF4);
                Str_0029CBB0 all;
                StrInit_0029CBB0(&list1);
                for (i = 0; i < l->count; i++) {
                    Name_0029CBB0* e = (Name_0029CBB0*)LobbyArray_At(l, i);
                    if (e && e->name) {
                        Str_0029CBB0 s;
                        String_CtorCStr_13B480(&s, (char*)e);
                        std_basic_string_char_char_traits_char_append_basicstringR(&list1, &s);
                        String_Dtor(&s, 0);
                    }
                }
                func_003FD740(&list1);
                MLTextWidget_AddText(self->pF4, String_CStr(&list1));
                String_Dtor(&list1, 0);
            }
        } else if (sel == 2) {
            void* w = self->p100;
            NameList_0029CBB0* l = D_004FFC04->l2F8;
            if (w && l) {
                MLTextWidget_Clear(w);
                Str_0029CBB0 all;
                StrInit_0029CBB0(&list2);
                if (l->count != 0) {
                    int id;
                    unsigned char found = 0;
                    for (i = 0; i < l->count; i++) {
                        Ent_0029CBB0* e = LobbyArray_At(l, i);
                        if (e && e->name && e->name[0]) {
                            if (!found) {
                                id = e->id;
                                found = 1;
                            }
                            if (e->id == id) {
                                Str_0029CBB0 s;
                                String_CtorCStr_13B480(&s, e->name);
                                std_basic_string_char_char_traits_char_append_basicstringR(&list2, &s);
                                String_Dtor(&s, 0);
                            }
                        }
                    }
                    if (found) {
                        unsigned char removed;
                        do {
                            removed = 0;
                            for (i = 0; i < l->count; i++) {
                                Ent_0029CBB0* e = LobbyArray_At(l, i);
                                if (!(e && e->name && e->name[0]) || e->id == id) {
                                    LobbyArray_RemoveAt(l, i);
                                    removed = 1;
                                    break;
                                }
                            }
                        } while (removed);
                    } else {
                        LobbyArray_Clear(l);
                    }
                }
                if (String_Length(&list2)) {
                    func_003FD740(&list2);
                    MLTextWidget_AddText(self->p100, String_CStr(&list2));
                }
                String_Dtor(&list2, 0);
            }
        }
    }
    self->f118 = sel;
}