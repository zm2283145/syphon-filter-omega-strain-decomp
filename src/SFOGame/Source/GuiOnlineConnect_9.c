/*
 * SFOGame/Source/GuiOnlineConnect: 8 files, 0029EC50-0029F500
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0029EC50 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cSystemContainer_GetSystem(char *, char *);                       
int cGameSound_Unload(int);                               
int sceMc2End();                                  
int sceMc2DeleteSocket(int);                               
int Renderer_Teardown(char *);                               
extern char D_004F2CC0;
extern char g_Game;
extern char g_Video;
extern int *g_MemCard;


void ShutdownForLaunchExec(void) {
    int temp_v0;
    int var_a0;

    Renderer_Teardown(&g_Video);
    temp_v0 = cSystemContainer_GetSystem(&g_Game, &D_004F2CC0);
    if (temp_v0 != 0) {
        cGameSound_Unload(temp_v0);
    }
    var_a0 = g_MemCard ? *g_MemCard : -1;
    if (var_a0 != -1) {
        sceMc2DeleteSocket(var_a0);
    }
    sceMc2End();
}
static inline void merge_flush_func_0029EC50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029EC50 */

/* merge_units: begin func_0029ECD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

extern GameMachine* D_004FFC04;
extern int cGameFrontEnd_PopMessageBox(GameMachine* machine, int arg);
extern void GuiScreen_Sleep(GuiScreen* self);
extern GuiManager* Gui_Canvas(void);
extern int SFOLobbyList_ClearAndCompactList(GuiSlot* slot);

/* GuiOnlineConnect vtable slot 6: base call, reset the three slots, clear manager flags 0x0C. */
int GuiOnlineConnect_onSleep(GuiOnlineConnect* self) {
    GuiManager* mgr;

    GuiScreen_Sleep(&self->base);
    SFOLobbyList_ClearAndCompactList(&self->slots[0]);
    SFOLobbyList_ClearAndCompactList(&self->slots[1]);
    SFOLobbyList_ClearAndCompactList(&self->slots[2]);
    D_004FFC04->unk2A = 1;
    mgr = Gui_Canvas();
    mgr->flags &= ~0xC;
    return cGameFrontEnd_PopMessageBox(D_004FFC04, self->base.base.unk48);
}
static inline void merge_flush_func_0029ECD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029ECD0 */

/* merge_units: begin func_0029ED40 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Str_0029ED40 { char d[0x10]; };
struct Ui_0029ED40 { char pad[0x2A]; unsigned char b2A; char pad2B[0x265 - 0x2B]; unsigned char b265; };
struct Ag_0029ED40 { char pad[0x9A0]; int f9A0; };
struct G_0029ED40 { char pad[0x68]; int f68; };
struct S_0029ED40 {
    char pad0[0x10]; int f10; char pad14[0x34]; int f48; char pad4C[0x3C]; int f88; float f8C; char pad90[4]; unsigned char b94;
};
extern "C" {
#if 0 /* merge_units */
extern Ui_0029ED40* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(Ui_0029ED40 **)&D_004FFC04) /* merge_units */



extern char D_004AABF0[];
#if 0 /* merge_units */
extern char g_Game[];
#endif /* merge_units */
#define g_Game ((char*)&g_Game) /* merge_units */



#if 0 /* merge_units */
extern char g_MemCard[];
#endif /* merge_units */
#define g_MemCard ((char*)&g_MemCard) /* merge_units */



void GuiScreen_Wake(void);
void cMemCard_WaitUntilNotBusy(void* p);
void GuiOnlineConnect_ShowGroup(S_0029ED40* self, int a);
char* GuiLobbyScreen_GetLobbyString(S_0029ED40* self, int a, int b, int c, int d, int e);
int cGameFrontEnd_PushMessageBox(void* ui, int a, char* b, char* c, S_0029ED40* d, int e);
Ag_0029ED40* cGameSystem_GetAgentData(void* mgr, int idx);
void std_basic_string_char_char_traits_char_ctor_charP(Str_0029ED40* s, const char* c);
char* std_basic_string_char_char_traits_char_c_str(Str_0029ED40* s);
void String_Dtor(Str_0029ED40* s, int flags);
#if 0 /* merge_units */
G_0029ED40* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((G_0029ED40 *)Gui_Canvas()) /* merge_units */



}
extern "C" void GuiOnlineConnect_onWake(S_0029ED40* self)
{
    GuiScreen_Wake();
    D_004FFC04->b2A = 0;
    cMemCard_WaitUntilNotBusy(g_MemCard);
    self->b94 = 0;
    GuiOnlineConnect_ShowGroup(self, 4);
    if (self->f10 == 1)
        self->f88 = 6;
    else
        self->f88 = 0;
    if (self->f88 == 0) {
        void* ui = D_004FFC04;
        self->f48 = cGameFrontEnd_PushMessageBox(ui, 0, D_004AABF0, GuiLobbyScreen_GetLobbyString(self, 0, 0, 0, 0, 0), 0, 0);
        self->f8C = 15.0f;
        GuiOnlineConnect_ShowGroup(self, 4);
        D_004FFC04->b265 = cGameSystem_GetAgentData(g_Game, -1)->f9A0 == -1;
    } else if (cGameSystem_GetAgentData(g_Game, -1)->f9A0 == -1) {
        Str_0029ED40 a;
        Str_0029ED40 b;
        std_basic_string_char_char_traits_char_ctor_charP(&a, GuiLobbyScreen_GetLobbyString(self, 3, 0, 0, 0, 0));
        std_basic_string_char_char_traits_char_ctor_charP(&b, GuiLobbyScreen_GetLobbyString(self, 0x84, 0, 0, 0, 0));
        {
            char* tb = std_basic_string_char_char_traits_char_c_str(&b);
            cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&a), tb, self, 0);
        }
        self->f88 = 4;
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
    } else {
        self->f88 = 7;
    }
    Gui_Canvas()->f68 |= 0xC;
}
#undef D_004FFC04 /* merge_units */
#undef g_Game /* merge_units */
#undef g_MemCard /* merge_units */
#undef Gui_Canvas /* merge_units */
static inline void merge_flush_func_0029ED40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029ED40 */

/* merge_units: begin func_0029EF30 */
#pragma push /* merge_units */
extern void* Gui_Manager(void);
extern int GuiManager_DestroyWidget(void* mgr, int resource, int arg);
extern int GuiWidget_onRemove(GuiWidget* self);

/* GuiOnlineConnect vtable slot 2: base call, then release the held resource. */
void GuiOnlineConnect_onRemove(GuiOnlineConnect* self) {
    int resource;

    GuiWidget_onRemove(&self->base.base.base);
    resource = self->resource;
    if (resource != 0) {
        GuiManager_DestroyWidget(Gui_Manager(), resource, 0);
        self->resource = 0;
    }
}
static inline void merge_flush_func_0029EF30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029EF30 */

/* merge_units: begin func_0029EF90 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W_0029EF90 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
    char pad4[0x5C]; int f60; char pad64[0x18]; W_0029EF90* f7C; char pad80[8]; void* f88;
};
struct Page_0029EF90 { char pad[0x14]; unsigned short flags; };
struct Self_0029EF90 {
    char pad0[0xEC]; W_0029EF90* fEC; W_0029EF90* fF0; W_0029EF90* fF4; void* fF8; void* fFC; W_0029EF90* f100; void* f104;
    Page_0029EF90* f108; void* f10C; void* f110; void* f114;
};
extern "C" {
extern char* D_0048B920;
extern char* D_0048B928;
extern char* D_0048B930;
extern char* D_0048B938;
extern char* D_0048B940;
extern char* D_0048B948;
extern char* D_0048B950;
extern char* D_0048B958;
extern char* D_0048B960;
extern char* D_0048B968;
extern char* D_0048B970;
extern char* D_0048B978;
extern char* D_0048B980;
extern char D_004AA640[];
extern char D_004A7520[];
extern char D_004AAE20[];
extern char D_004AAE00[];
void GuiLobbyScreen_onAdd(Self_0029EF90* self);
void* GuiWidget_FindChild_charP(Self_0029EF90* self, char* name);
void GuiArrayWidget_SetVisibleSize(W_0029EF90* w, int a, int b);
void GuiTextListWidget_SetF1(W_0029EF90* w, int a);
void MLTextWidget_SetFont(W_0029EF90* w, char* s);
void* Gui_Manager(void);
Page_0029EF90* GuiManager_OpenGui(void* a, char* b, char* c);
}
static inline W_0029EF90* FindAs_0029EF90(Self_0029EF90* self, char* name, char* type)
{
    W_0029EF90* w = (W_0029EF90*)GuiWidget_FindChild_charP(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" void GuiOnlineConnect_onAdd(Self_0029EF90* self)
{
    GuiLobbyScreen_onAdd(self);
    self->f10C = GuiWidget_FindChild_charP(self, D_0048B920);
    self->f110 = GuiWidget_FindChild_charP(self, D_0048B938);
    self->f114 = GuiWidget_FindChild_charP(self, D_0048B968);
    self->fEC = FindAs_0029EF90(self, D_0048B928, D_004AA640);
    if (self->fEC) {
        GuiArrayWidget_SetVisibleSize(self->fEC, 1, 10);
        self->fEC->f88 = GuiWidget_FindChild_charP(self, D_0048B930);
        GuiTextListWidget_SetF1(self->fEC, 1);
    }
    self->fF0 = FindAs_0029EF90(self, D_0048B940, D_004A7520);
    self->fF4 = FindAs_0029EF90(self, D_0048B948, D_004AAE20);
    self->fF8 = GuiWidget_FindChild_charP(self, D_0048B950);
    self->fFC = GuiWidget_FindChild_charP(self, D_0048B958);
    self->f100 = FindAs_0029EF90(self, D_0048B970, D_004AAE20);
    self->f104 = GuiWidget_FindChild_charP(self, D_0048B978);
    if (self->fF4) {
        self->fF4->f7C = FindAs_0029EF90(self, D_0048B960, D_004AAE00);
        MLTextWidget_SetFont(self->fF4, "callout");
        self->fF4->f60 = 0;
    }
    if (self->f100) {
        self->f100->f7C = FindAs_0029EF90(self, D_0048B980, D_004AAE00);
        MLTextWidget_SetFont(self->f100, "callout");
        self->f100->f60 = 0;
    }
    self->f108 = GuiManager_OpenGui(Gui_Manager(), "GuiWidget", "DNASLOGO");
    self->f108->flags &= ~0x20;
}
static inline void merge_flush_func_0029EF90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029EF90 */

/* merge_units: begin GuiOnlineConnect_29F2A0 */
#pragma push /* merge_units */
extern char GuiOnlineConnect_vtable[];   /* GuiOnlineConnect vtable */
extern GuiScreen* GuiLobbyScreen_ctor(GuiScreen* self);
extern GuiSlot* SFOLobbyList_ctor(GuiSlot* slot);

/* GuiOnlineConnect constructor. */
GuiOnlineConnect* GuiOnlineConnect_ctor(GuiOnlineConnect* self) {
    GuiLobbyScreen_ctor(&self->base);
    self->base.base.base.vtable = GuiOnlineConnect_vtable;
    SFOLobbyList_ctor(&self->slots[0]);
    SFOLobbyList_ctor(&self->slots[1]);
    SFOLobbyList_ctor(&self->slots[2]);
    self->base.screenId = 0;
    self->unk94 = 0;
    self->unk88 = 0;
    self->unk8C = 0;
    self->unk90 = 0;
    self->unkEC = 0;
    self->unkF4 = 0;
    self->unkF8 = 0;
    self->unkFC = 0;
    self->unk100 = 0;
    self->unk104 = 0;
    self->unk10C = 0;
    self->unk110 = 0;
    self->unk114 = 0;
    self->unk118 = 4;
    self->unk11C = -2;
    self->unk120 = -2;
    return self;
}
static inline void merge_flush_GuiOnlineConnect_29F2A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiOnlineConnect_29F2A0 */

/* merge_units: begin func_0029F340 */
#pragma push /* merge_units */
extern short g_DnasErrorTable[];
extern signed char D_0048B992[];
extern signed char D_0048B993[];
extern char D_004AACB8[];
extern char D_004AACC8[];
extern char D_004AACD8[];
extern char D_004AACE8[];
extern char* nGlobalization_GetString_charP(char* key);
extern void Libc_Strcpy(char* d, char* s);
extern int sprintf(char* d, const char* f, ...);
void GetDNASErrorStrings(int err, char* title, char* body, char* extra)
{
    char buf[16];
    int code = 0;
    unsigned int i;
    int a = 0;
    int b = 0;
    char* t;
    for (i = 0; i < 0x22; i++) {
        if (-err == *(short*)((char*)g_DnasErrorTable + i * 4)) {
            code = *(short*)((char*)g_DnasErrorTable + i * 4);
            a = *(signed char*)((char*)D_0048B992 + i * 4);
            b = *(signed char*)((char*)D_0048B993 + i * 4);
            break;
        }
    }
    if (code != -1) {
        t = (err != -701 && err != -703) ? nGlobalization_GetString_charP(D_004AACB8) : nGlobalization_GetString_charP(D_004AACC8);
        if (t) Libc_Strcpy(title, t);
    }
    if (a != -1) {
        if (a == 0 && !(err < -699) && err < -600) a = 15;
        sprintf(buf, D_004AACD8, a);
        t = nGlobalization_GetString_charP(buf);
        if (t) sprintf(body, t, err);
    }
    if (b != -1) {
        sprintf(buf, D_004AACE8, b);
        t = nGlobalization_GetString_charP(buf);
        if (t) Libc_Strcpy(extra, t);
    }
}
static inline void merge_flush_func_0029F340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029F340 */

/* merge_units: begin func_0029F500 */
#pragma push /* merge_units */
/* True unless code is -701 or -703. */
int func_0029F500(int code) {
    return code != -701 && code != -703;
}
static inline void merge_flush_func_0029F500(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029F500 */
