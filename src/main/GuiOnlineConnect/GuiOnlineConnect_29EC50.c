/*
 * main/GuiOnlineConnect: 5 files, 0029EC50-0029EF90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0029EC50 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Service_Lookup(char *, char *);                       
int SoundMgr_UnloadLevel(int);                               
int func_002B4E50();                                  
int func_002B4FA8(int);                               
int func_0037E320(char *);                               
extern char D_004F2CC0;
extern char D_004FFB50;
extern char D_005381F0;
extern int *D_0055A830;


void func_0029EC50(void) {
    int temp_v0;
    int var_a0;

    func_0037E320(&D_005381F0);
    temp_v0 = Service_Lookup(&D_004FFB50, &D_004F2CC0);
    if (temp_v0 != 0) {
        SoundMgr_UnloadLevel(temp_v0);
    }
    var_a0 = D_0055A830 ? *D_0055A830 : -1;
    if (var_a0 != -1) {
        func_002B4FA8(var_a0);
    }
    func_002B4E50();
}
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
extern int FrontEnd_ClosePopup(GameMachine* machine, int arg);
extern void GuiScreen_Sleep(GuiScreen* self);
extern GuiManager* Gui_GetScreenStack(void);
extern int LobbyArray_Free(GuiSlot* slot);

/* GuiOnlineConnect vtable slot 6: base call, reset the three slots, clear manager flags 0x0C. */
int func_0029ECD0(GuiOnlineConnect* self) {
    GuiManager* mgr;

    GuiScreen_Sleep(&self->base);
    LobbyArray_Free(&self->slots[0]);
    LobbyArray_Free(&self->slots[1]);
    LobbyArray_Free(&self->slots[2]);
    D_004FFC04->unk2A = 1;
    mgr = Gui_GetScreenStack();
    mgr->flags &= ~0xC;
    return FrontEnd_ClosePopup(D_004FFC04, self->base.base.unk48);
}
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
extern char D_004FFB50[];
#endif /* merge_units */
#define D_004FFB50 ((char*)&D_004FFB50) /* merge_units */

#if 0 /* merge_units */
extern char D_0055A830[];
#endif /* merge_units */
#define D_0055A830 ((char*)&D_0055A830) /* merge_units */

void GuiScreen_Wake(void);
void func_0040D5D0(void* p);
void func_0029CBB0(S_0029ED40* self, int a);
char* func_0033CE30(S_0029ED40* self, int a, int b, int c, int d, int e);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, S_0029ED40* d, int e);
Ag_0029ED40* Agent_GetSelected(void* mgr, int idx);
void String_CtorCStr_13B480(Str_0029ED40* s, const char* c);
char* String_CStr(Str_0029ED40* s);
void String_Dtor(Str_0029ED40* s, int flags);
#if 0 /* merge_units */
G_0029ED40* Gui_GetScreenStack(void);
#endif /* merge_units */
#define Gui_GetScreenStack() ((G_0029ED40 *)Gui_GetScreenStack()) /* merge_units */

}
extern "C" void func_0029ED40(S_0029ED40* self)
{
    GuiScreen_Wake();
    D_004FFC04->b2A = 0;
    func_0040D5D0(D_0055A830);
    self->b94 = 0;
    func_0029CBB0(self, 4);
    if (self->f10 == 1)
        self->f88 = 6;
    else
        self->f88 = 0;
    if (self->f88 == 0) {
        void* ui = D_004FFC04;
        self->f48 = FrontEnd_OpenPopup(ui, 0, D_004AABF0, func_0033CE30(self, 0, 0, 0, 0, 0), 0, 0);
        self->f8C = 15.0f;
        func_0029CBB0(self, 4);
        D_004FFC04->b265 = Agent_GetSelected(D_004FFB50, -1)->f9A0 == -1;
    } else if (Agent_GetSelected(D_004FFB50, -1)->f9A0 == -1) {
        Str_0029ED40 a;
        Str_0029ED40 b;
        String_CtorCStr_13B480(&a, func_0033CE30(self, 3, 0, 0, 0, 0));
        String_CtorCStr_13B480(&b, func_0033CE30(self, 0x84, 0, 0, 0, 0));
        {
            char* tb = String_CStr(&b);
            FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&a), tb, self, 0);
        }
        self->f88 = 4;
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
    } else {
        self->f88 = 7;
    }
    Gui_GetScreenStack()->f68 |= 0xC;
}
#undef D_004FFC04 /* merge_units */
#undef D_004FFB50 /* merge_units */
#undef D_0055A830 /* merge_units */
#undef Gui_GetScreenStack /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029ED40 */

/* merge_units: begin func_0029EF30 */
#pragma push /* merge_units */
extern void* Gui_GetScreenList(void);
extern int GuiManager_UnloadRoot(void* mgr, int resource, int arg);
extern int GuiWidget_Deinit(GuiWidget* self);

/* GuiOnlineConnect vtable slot 2: base call, then release the held resource. */
void func_0029EF30(GuiOnlineConnect* self) {
    int resource;

    GuiWidget_Deinit(&self->base.base.base);
    resource = self->resource;
    if (resource != 0) {
        GuiManager_UnloadRoot(Gui_GetScreenList(), resource, 0);
        self->resource = 0;
    }
}
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
void GuiScreen_Init(Self_0029EF90* self);
void* GuiWidget_FindChildByName(Self_0029EF90* self, char* name);
void func_004235B0(W_0029EF90* w, int a, int b);
void func_00421650(W_0029EF90* w, int a);
void MLTextWidget_SetFont(W_0029EF90* w, char* s);
void* Gui_GetScreenList(void);
Page_0029EF90* GuiManager_FindOrLoad(void* a, char* b, char* c);
}
static inline W_0029EF90* FindAs_0029EF90(Self_0029EF90* self, char* name, char* type)
{
    W_0029EF90* w = (W_0029EF90*)GuiWidget_FindChildByName(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" void func_0029EF90(Self_0029EF90* self)
{
    GuiScreen_Init(self);
    self->f10C = GuiWidget_FindChildByName(self, D_0048B920);
    self->f110 = GuiWidget_FindChildByName(self, D_0048B938);
    self->f114 = GuiWidget_FindChildByName(self, D_0048B968);
    self->fEC = FindAs_0029EF90(self, D_0048B928, D_004AA640);
    if (self->fEC) {
        func_004235B0(self->fEC, 1, 10);
        self->fEC->f88 = GuiWidget_FindChildByName(self, D_0048B930);
        func_00421650(self->fEC, 1);
    }
    self->fF0 = FindAs_0029EF90(self, D_0048B940, D_004A7520);
    self->fF4 = FindAs_0029EF90(self, D_0048B948, D_004AAE20);
    self->fF8 = GuiWidget_FindChildByName(self, D_0048B950);
    self->fFC = GuiWidget_FindChildByName(self, D_0048B958);
    self->f100 = FindAs_0029EF90(self, D_0048B970, D_004AAE20);
    self->f104 = GuiWidget_FindChildByName(self, D_0048B978);
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
    self->f108 = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiWidget", "DNASLOGO");
    self->f108->flags &= ~0x20;
}
#pragma pop /* merge_units */
/* merge_units: end func_0029EF90 */
