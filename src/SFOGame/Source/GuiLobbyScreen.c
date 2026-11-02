/*
 * SFOGame/Source/GuiLobbyScreen: 10 files, 0033C280-0033CCA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0033C280 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Rel* std_vector_imp_Record_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_0033C280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033C280 */

/* merge_units: begin func_0033C2A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "nested_null_dtor.h"

DEFINE_NESTED_NULL_DTOR2(cArray_Record_dtor, std_vector_imp_Record_dtor)
static inline void merge_flush_func_0033C2A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033C2A0 */

/* merge_units: begin func_0033C300 */
#pragma push /* merge_units */
Rel* std_vector_Record_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_0033C300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033C300 */

/* merge_units: begin func_0033C320 */
#pragma push /* merge_units */
#pragma cplusplus on
struct S33 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual void v24(); };
struct V33 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual void v23(void*, int); virtual void v24(void*); };
typedef struct { char pad[0x10]; int f10; unsigned short flags; } W33;
typedef struct { char pad[0x248]; int f248; } G33;
typedef struct { char pad[0x84]; int f84; } O33;
extern "C" {
extern G33* D_004FFC04;
extern char D_004B99D8[];
#if 0 /* merge_units */
extern char* GuiLobbyScreen_GetLobbyString(O33*, int, char*, char*, int, int);
#endif /* merge_units */
char* GuiLobbyScreen_GetLobbyString(void* self, unsigned char id, char* a, char* b, int c, int d); /* merge_units */
#define GuiLobbyScreen_GetLobbyString(a0, a1, a2, a3, a4, a5) (GuiLobbyScreen_GetLobbyString((void *)(a0), (unsigned char)(a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern int cGameFrontEnd_PushMessageBox(G33*, int, char*, char*, int, int);
#endif /* merge_units */
int cGameFrontEnd_PushMessageBox(void*, int, char*, char*, int, int); /* merge_units */
#define cGameFrontEnd_PushMessageBox(a0, a1, a2, a3, a4, a5) (cGameFrontEnd_PushMessageBox((void *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

extern void FrontEnd_StartSplashThread(G33*);
extern void FrontEnd_StopSplashThread(G33*);
#if 0 /* merge_units */
extern void cGameFrontEnd_PopMessageBox(G33*, int);
#endif /* merge_units */
void cGameFrontEnd_PopMessageBox(void*, int); /* merge_units */
#define cGameFrontEnd_PopMessageBox(a0, a1) (cGameFrontEnd_PopMessageBox((void *)(a0), (a1))) /* merge_units */

extern int Gui_Manager(void);
extern W33* GuiManager_OpenGui(int, char*, char*);
extern void GuiManager_CloseGui(int, W33*);
extern int cDME_GetLobby(void);
extern int SFOLobby_CheckMissionLobby(int, int);
extern int SFOLobby_CellIsPlayerInCell(int);
extern V33* Gui_Canvas(void);
#if 0 /* merge_units */
extern void GuiWidget_SendMessage(W33*, V33*, int, int, int);
#endif /* merge_units */
void GuiWidget_SendMessage(void*, void*, int, int, int); /* merge_units */
#define GuiWidget_SendMessage(a0, a1, a2, a3, a4) (GuiWidget_SendMessage((void *)(a0), (void *)(a1), (a2), (a3), (a4))) /* merge_units */

}
extern "C" int GuiLobbyScreen_PushLobbyScreen(O33* self, int type) {
    int c = -1;
    int h;
    W33* w;
    switch (type) {
    case 1: c = 0x78; break;
    case 3: c = 0x7A; break;
    case 4: c = 0x7B; break;
    case 9: c = 0x7C; break;
    case 2: c = 0x79; break;
    case 6: c = 0x79; break;
    }
    if (type == 1 && self->f84 == 9) c = -1;
    h = -1;
    if (c != -1) {
        G33* g = D_004FFC04;
        h = cGameFrontEnd_PushMessageBox(g, 0, D_004B99D8, GuiLobbyScreen_GetLobbyString(self, (unsigned char)c, 0, 0, 0, 0), 0, 0);
        FrontEnd_StartSplashThread(D_004FFC04);
    }
    w = 0;
    switch (type) {
    case 0: w = GuiManager_OpenGui(Gui_Manager(), "GuiOnlineConnect", "ONLINECN"); break;
    case 1: w = GuiManager_OpenGui(Gui_Manager(), "GuiCommandCenter", "CMDCENTR"); break;
    case 2: w = GuiManager_OpenGui(Gui_Manager(), "GuiNetJoinMission", "JOINMIS"); break;
    case 6: w = GuiManager_OpenGui(Gui_Manager(), "GuiMissionSetup", "MSNSETUP"); break;
    case 3: w = GuiManager_OpenGui(Gui_Manager(), "GuiNetAgencyCell", "AGENTCEL"); break;
    case 4: w = GuiManager_OpenGui(Gui_Manager(), "GuiNetContacts", "CONTACTS"); break;
    case 5: w = GuiManager_OpenGui(Gui_Manager(), "GuiOnlineOptions", "ONLIPREF"); break;
    case 9: w = GuiManager_OpenGui(Gui_Manager(), "GuiNetMessages", "NETMESS"); break;
    case 7: w = GuiManager_OpenGui(Gui_Manager(), "GuiAccountLogin", "ACNTLOGN"); break;
    }
    if (c != -1) FrontEnd_StopSplashThread(D_004FFC04);
    if (w) {
        if (type == 6 || type == 2) {
            int x = D_004FFC04->f248;
            int p = cDME_GetLobby();
            if (!p || !SFOLobby_CheckMissionLobby(p, x)) {
                if (h != -1) cGameFrontEnd_PopMessageBox(D_004FFC04, h);
                GuiManager_CloseGui(Gui_Manager(), w);
                return 0;
            }
        }
        if (type == 3) {
            int p = cDME_GetLobby();
            if (!p || !SFOLobby_CellIsPlayerInCell(p)) {
                if (h != -1) cGameFrontEnd_PopMessageBox(D_004FFC04, h);
                GuiManager_CloseGui(Gui_Manager(), w);
                return 0;
            }
        }
        if (type == 0 || type == 7) w->f10 = 1;
    }
    ((S33*)self)->v24();
    if (w) {
        V33* m;
        w->flags &= ~2;
        m = Gui_Canvas();
        m->v23(w, 0);
    }
    Gui_Canvas()->v24(self);
    if (h != -1) cGameFrontEnd_PopMessageBox(D_004FFC04, h);
    if (w) {
        w->flags |= 2;
        GuiWidget_SendMessage(w, Gui_Canvas(), 0x10, 2, 0);
    }
    return 1;
}
#undef GuiLobbyScreen_GetLobbyString /* merge_units */
#undef cGameFrontEnd_PushMessageBox /* merge_units */
#undef cGameFrontEnd_PopMessageBox /* merge_units */
#undef GuiWidget_SendMessage /* merge_units */
static inline void merge_flush_func_0033C320(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033C320 */

/* merge_units: begin func_0033C7C0 */
#pragma push /* merge_units */
typedef struct { int w[3]; } String;
#if 0 /* merge_units */
extern void* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(void **)&D_004FFC04) /* merge_units */


extern int cGameFrontEnd_PushMessageBox(void*, int, char*, char*, int, int);

extern void cGameFrontEnd_PopMessageBox(void*, int);

extern int SFOLobby_ContactInviteAgent(int, int);
extern unsigned char SFOLobby_GetErrorDetails(int, int);
extern void std_basic_string_char_char_traits_char_ctor_charP(String*, char*);
#if 0 /* merge_units */
extern char* std_basic_string_char_char_traits_char_c_str(String*);
#endif /* merge_units */
char* std_basic_string_char_char_traits_char_c_str(void*); /* merge_units */
#define std_basic_string_char_char_traits_char_c_str(a0) (std_basic_string_char_char_traits_char_c_str((void *)(a0))) /* merge_units */

extern void String_Dtor(String*, int);

void GuiLobbyScreen_ContactInviteAgent(O33* self, int buddy, char* name)
{
    int lobby;
    int h;
    lobby = cDME_GetLobby();
    if (!lobby) return;
    {
        void* g = D_004FFC04;
        h = cGameFrontEnd_PushMessageBox(g, 0, D_004B99D8, GuiLobbyScreen_GetLobbyString(self, 0x39, name, 0, 0, 0), 0, 0);
    }
    if (SFOLobby_ContactInviteAgent(lobby, buddy)) {
        void* g = D_004FFC04;
        cGameFrontEnd_PushMessageBox(g, 2, D_004B99D8, GuiLobbyScreen_GetLobbyString(self, 0x3A, name, 0, 0, 0), 0, 0);
    } else {
        int c;
        String a;
        String b;
        switch (SFOLobby_GetErrorDetails(lobby, 0)) {
        case 0x1E: c = 0x3C; break;
        case 0x25: c = 0x3D; break;
        case 0x1D: c = 0x17; break;
        case 0x2A: c = 0x3E; break;
        default: c = 0x3F; break;
        }
        std_basic_string_char_char_traits_char_ctor_charP(&a, GuiLobbyScreen_GetLobbyString(self, 0x3B, 0, 0, 0, 0));
        std_basic_string_char_char_traits_char_ctor_charP(&b, GuiLobbyScreen_GetLobbyString(self, (unsigned char)c, name, 0, 0, 0));
        {
            char* t = std_basic_string_char_char_traits_char_c_str(&b);
            cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&a), t, 0, 0);
        }
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
    }
    cGameFrontEnd_PopMessageBox(D_004FFC04, h);
}
#undef D_004FFC04 /* merge_units */
#undef std_basic_string_char_char_traits_char_c_str /* merge_units */
static inline void merge_flush_func_0033C7C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033C7C0 */

/* merge_units: begin func_0033C9E0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(void **)&D_004FFC04) /* merge_units */


extern int SFOLobby_CellInviteAgent(int, int);

void GuiLobbyScreen_CellInviteAgent(O33* self, int buddy, char* name)
{
    int lobby;
    int h;
    lobby = cDME_GetLobby();
    if (!lobby) return;
    {
        void* g = D_004FFC04;
        h = cGameFrontEnd_PushMessageBox(g, 0, D_004B99D8, GuiLobbyScreen_GetLobbyString(self, 0x4A, name, 0, 0, 0), 0, 0);
    }
    if (SFOLobby_CellInviteAgent(lobby, buddy)) {
        void* g = D_004FFC04;
        cGameFrontEnd_PushMessageBox(g, 2, D_004B99D8, GuiLobbyScreen_GetLobbyString(self, 0x4B, name, 0, 0, 0), 0, 0);
    } else {
        unsigned char r = SFOLobby_GetErrorDetails(lobby, 0);
        if (r == 0x3F) {
            String a;
            String b;
            std_basic_string_char_char_traits_char_ctor_charP(&a, GuiLobbyScreen_GetLobbyString(self, 0x4C, 0, 0, 0, 0));
            std_basic_string_char_char_traits_char_ctor_charP(&b, GuiLobbyScreen_GetLobbyString(self, 0x55, 0, 0, 0, 0));
            {
                char* t = std_basic_string_char_char_traits_char_c_str(&b);
                cGameFrontEnd_PushMessageBox(D_004FFC04, 5, std_basic_string_char_char_traits_char_c_str(&a), t, (int)self, 0x13);
            }
            String_Dtor(&b, 0);
            String_Dtor(&a, 0);
        } else {
            int c;
            String a;
            String b;
            switch (r) {
            case 0x1E: c = 0x50; break;
            case 0x1D: c = 0x17; break;
            case 0x1F: c = 0x4E; break;
            case 0x2A: c = 0x4F; break;
            default: c = 0x4D; break;
            }
            std_basic_string_char_char_traits_char_ctor_charP(&a, GuiLobbyScreen_GetLobbyString(self, 0x4C, 0, 0, 0, 0));
            std_basic_string_char_char_traits_char_ctor_charP(&b, GuiLobbyScreen_GetLobbyString(self, (unsigned char)c, name, 0, 0, 0));
            {
                char* t = std_basic_string_char_char_traits_char_c_str(&b);
                cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&a), t, 0, 0);
            }
            String_Dtor(&b, 0);
            String_Dtor(&a, 0);
        }
    }
    cGameFrontEnd_PopMessageBox(D_004FFC04, h);
}
#undef D_004FFC04 /* merge_units */
static inline void merge_flush_func_0033C9E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033C9E0 */

/* merge_units: begin func_0033CCA0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned char bc; char name[0x203]; int f210; } E33C;
typedef struct { char pad[0x20]; int f20; char pad2[0x18]; int f3c; } L33C;
typedef struct { char pad[0x10]; int f10; } W33C;
typedef struct { char pad[0x7C]; W33C* f7c; } O33C;
typedef struct { char pad[0x31]; unsigned char b31; } G33C;
#if 0 /* merge_units */
extern L33C* cDME_GetLobby(void);
#endif /* merge_units */
#define cDME_GetLobby() ((L33C *)cDME_GetLobby()) /* merge_units */

extern E33C* func_00450EF0(L33C*, int);
extern void func_00450EC0(L33C*, int);
extern unsigned char D_00532DC8;
extern char D_00532DD0[];
#if 0 /* merge_units */
extern G33C* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(G33C **)&D_004FFC04) /* merge_units */

extern char* strncpy(char*, const char*, int);
extern void func_003FD2D0(char*);
extern void cGameFrontEnd_LobbyDestroy(G33C*, int);
extern void func_002CA6F0(G33C*);
#if 0 /* merge_units */
extern void GuiWidget_SendMessage(O33C*, W33C*, int, int, int);
#endif /* merge_units */
#define GuiWidget_SendMessage(a0, a1, a2, a3, a4) (GuiWidget_SendMessage((void *)(a0), (void *)(a1), (a2), (a3), (a4))) /* merge_units */

void GuiScreen_PollLobby(O33C* o) {
    L33C* l = cDME_GetLobby();
    int i;
    E33C* e;
    int n;
    if (!l) return;
    n = l->f3c;
    for (i = 0; i < n; i++) {
        e = func_00450EF0(l, i);
        if (e->f210 == 9) {
            func_00450EC0(l, i);
            D_00532DC8 = 1;
            if (e->bc) {
                strncpy(D_00532DD0, (char*)&e->bc, 0x200);
                func_003FD2D0(D_00532DD0);
            } else {
                D_00532DD0[0] = 0;
            }
            D_004FFC04->b31 = 1;
            cGameFrontEnd_LobbyDestroy(D_004FFC04, 1);
            func_002CA6F0(D_004FFC04);
            return;
        }
    }
    if (!o->f7c) return;
    if (l->f20) {
        if (o->f7c->f10 != 1) {
            GuiWidget_SendMessage(o, o->f7c, 6, (int)"onActivate", 0);
            o->f7c->f10 = 1;
        }
    } else {
        if (o->f7c->f10) {
            GuiWidget_SendMessage(o, o->f7c, 6, (int)"onWake", 0);
            o->f7c->f10 = 0;
        }
    }
}
#undef cDME_GetLobby /* merge_units */
#undef D_004FFC04 /* merge_units */
#undef GuiWidget_SendMessage /* merge_units */
static inline void merge_flush_func_0033CCA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033CCA0 */

/* merge_units: begin GuiLobbyScreen_33CE30 */
#pragma push /* merge_units */
extern void* D_00532FE0;
extern int sprintf(char*, const char*, ...);
extern char* nGlobalization_GetString_charP(char*);
extern void FormatString(void*, char*, char*, char*, int, int);
extern char* std_basic_string_char_char_traits_char_c_str(void*);
char* GuiLobbyScreen_GetLobbyString(void* self, unsigned char id, char* a, char* b, int c, int d) {
    char buf[16];
    char* t;
    if (!D_00532FE0) return D_004B99D8;
    sprintf(buf, "LOBBY_STR%d", id);
    t = nGlobalization_GetString_charP(buf);
    if (!t) return D_004B99D8;
    FormatString(D_00532FE0, t, a, b, c, d);
    return std_basic_string_char_char_traits_char_c_str(D_00532FE0);
}
static inline void merge_flush_GuiLobbyScreen_33CE30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiLobbyScreen_33CE30 */

/* merge_units: begin func_0033CEF0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
#if 0 /* merge_units */
int GuiLobbyScreen_PushLobbyScreen(int, int);
#endif /* merge_units */
#define GuiLobbyScreen_PushLobbyScreen(a0, a1) (GuiLobbyScreen_PushLobbyScreen((O33 *)(a0), (a1))) /* merge_units */
                                 
extern int D_00532FD0;

int GuiLobbyScreen_onInput(int arg0, int arg1) {
    int var_v0;

    if (F_(arg0, 0x78, unsigned char) != 0) {
        var_v0 = F_(arg1, 0x0, unsigned short) == 1;
        var_v0 = var_v0 ? F_(arg1, 0x2, unsigned short) == 0 : var_v0;
        if (var_v0 != 0) {
            var_v0 = F_(arg1, 0x8, unsigned short) == 0x800;
        }
        var_v0 = var_v0 ? F_(arg1, 0x6, unsigned short) == 0 : var_v0;
        if (var_v0 != 0) {
            D_00532FD0 = F_(arg0, 0x84, int);
            GuiLobbyScreen_PushLobbyScreen(arg0, 9);
            return 1;
        }
        goto block_9;
    }
block_9:
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0033CEF0(void) {}
#undef GuiLobbyScreen_PushLobbyScreen /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033CEF0 */

/* merge_units: begin func_0033CF90 */
#pragma push /* merge_units */
typedef struct O O;
#if 0 /* merge_units */
extern void *D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(void **)&D_004FFC04) /* merge_units */


#if 0 /* merge_units */
extern void *cDME_GetLobby(void);
#endif /* merge_units */
#define cDME_GetLobby() ((void *)cDME_GetLobby()) /* merge_units */


extern int func_0033D0C0(O *o, void *snd, unsigned short msg, int param, int extra);
#if 0 /* merge_units */
extern char *GuiLobbyScreen_GetLobbyString(O *o, unsigned char a, char *b, char *c, int d, int e);
#endif /* merge_units */
#define GuiLobbyScreen_GetLobbyString(a0, a1, a2, a3, a4, a5) (GuiLobbyScreen_GetLobbyString((void *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */



#if 0 /* merge_units */
extern int cGameFrontEnd_PushMessageBox(void *ui, int a, char *b, char *c, void *d, int e);
#endif /* merge_units */
#define cGameFrontEnd_PushMessageBox(a0, a1, a2, a3, a4, a5) (cGameFrontEnd_PushMessageBox((a0), (a1), (a2), (a3), (int)(a4), (a5))) /* merge_units */

extern int SFOLobby_CellRevokeAllInvites(void *p);
#if 0 /* merge_units */
extern void cGameFrontEnd_PopMessageBox(void *ui, int id);
#endif /* merge_units */
#define cGameFrontEnd_PopMessageBox(a0, a1) (cGameFrontEnd_PopMessageBox((a0), (a1))) /* merge_units */

extern int GuiSaveAgentWidget_OnEvent(O *o, void *snd, unsigned short msg, int param, int extra);

int GuiLobbyScreen_onMessage(O *o, void *snd, unsigned short msg, int param, int extra)
{
    if (msg == 0x2000) {
        func_0033D0C0(o, snd, msg, param, extra);
        return 1;
    }
    if (param == 0x13) {
        void *owner = cDME_GetLobby();
        if (owner) {
            void *ui = D_004FFC04;
            int id = cGameFrontEnd_PushMessageBox(ui, 0, D_004B99D8, GuiLobbyScreen_GetLobbyString(o, 0x56, 0, 0, 0, 0), 0, 0);
            if (!SFOLobby_CellRevokeAllInvites(owner)) {
                ui = D_004FFC04;
                cGameFrontEnd_PushMessageBox(ui, 2, D_004B99D8, GuiLobbyScreen_GetLobbyString(o, 0x57, 0, 0, 0, 0), 0, 0);
            }
            cGameFrontEnd_PopMessageBox(D_004FFC04, id);
        }
        return 1;
    }
    return GuiSaveAgentWidget_OnEvent(o, snd, msg, param, extra);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0033CF90(void) {}
#undef D_004FFC04 /* merge_units */
#undef cDME_GetLobby /* merge_units */
#undef GuiLobbyScreen_GetLobbyString /* merge_units */
#undef cGameFrontEnd_PushMessageBox /* merge_units */
#undef cGameFrontEnd_PopMessageBox /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033CF90 */
