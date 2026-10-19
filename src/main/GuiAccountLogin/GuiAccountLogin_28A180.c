/*
 * main/GuiAccountLogin: 12 files, 0028A180-0028B120
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0028A180 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct Str_0028A180 { char d[0x10]; };
struct Obj94_0028A180 { char pad[0x48]; Str_0028A180 name; };
struct S_0028A180 { char pad[0x94]; Obj94_0028A180* p94; };
extern "C" {
extern char D_004A9798[];
extern char D_004A97A8[];
void* Gui_GetScreenList(void);
void* GuiManager_FindOrLoad(void* a, char* b, char* c);
char* String_CStr(Str_0028A180* s);
char* GuiScreen_GetLobbyString(S_0028A180* self, int a, int b, int c, int d, int e);
void GuiKeyboard_Open(void* kb, char* title, char* text, S_0028A180* self, int a, int b, int c);
}
extern "C" void func_0028A180(S_0028A180* self)
{
    void* kb = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A9798, D_004A97A8);
    if (kb) {
        char* text = String_CStr(&self->p94->name);
        GuiKeyboard_Open(kb, GuiScreen_GetLobbyString(self, 0x28, 0, 0, 0, 0), text, self, 0xF, 0x22, 1);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0028A180 */

/* merge_units: begin func_0028A230 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Str_0028A230 { char d[0x10]; };
struct Obj8C_0028A230 { char pad[0x48]; Str_0028A230 name; };
struct S_0028A230 { char pad[0x8C]; Obj8C_0028A230* p8C; char pad90[0x14]; unsigned char bA4; };
extern "C" {
extern void* D_004FFC04;
#if 0 /* merge_units */
char* String_CStr(Str_0028A230* s);
#endif /* merge_units */
#define String_CStr(a0) (String_CStr((Str_0028A180 *)(a0))) /* merge_units */

#if 0 /* merge_units */
char* GuiScreen_GetLobbyString(S_0028A230* self, int a, int b, int c, int d, int e);
#endif /* merge_units */
#define GuiScreen_GetLobbyString(a0, a1, a2, a3, a4, a5) (GuiScreen_GetLobbyString((S_0028A180 *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
void GuiKeyboard_Open(void* kb, char* title, char* text, S_0028A230* self, int a, int b, int c);
#endif /* merge_units */
#define GuiKeyboard_Open(a0, a1, a2, a3, a4, a5, a6) (GuiKeyboard_Open((a0), (a1), (a2), (S_0028A180 *)(a3), (a4), (a5), (a6))) /* merge_units */

void String_CtorCStr_13B480(Str_0028A230* s, const char* c);
int FrontEnd_OpenPopup(void* ui, int a, char* b, char* c, S_0028A230* d, int e);
void String_Dtor(Str_0028A230* s, int flags);
}
extern "C" void func_0028A230(S_0028A230* self)
{
    if (self->bA4) {
        void* kb = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A9798, D_004A97A8);
        if (kb) {
            char* text = String_CStr(&self->p8C->name);
            GuiKeyboard_Open(kb, GuiScreen_GetLobbyString(self, 0x27, 0, 0, 0, 0), text, self, 0xF, 0x21, 1);
        }
    } else {
        Str_0028A230 a;
        Str_0028A230 b;
        String_CtorCStr_13B480(&a, GuiScreen_GetLobbyString(self, 0x29, 0, 0, 0, 0));
        String_CtorCStr_13B480(&b, GuiScreen_GetLobbyString(self, 0x2A, 0, 0, 0, 0));
        {
            char* tb = String_CStr(&b);
            FrontEnd_OpenPopup(D_004FFC04, 2, String_CStr(&a), tb, self, 0x25);
        }
        String_Dtor(&b, 0);
        String_Dtor(&a, 0);
    }
}
#undef String_CStr /* merge_units */
#undef GuiScreen_GetLobbyString /* merge_units */
#undef GuiKeyboard_Open /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028A230 */

/* merge_units: begin func_0028A380 */
#pragma push /* merge_units */
void func_0028A380(int a0, int a1) {
    int a2, v1;
    int cond;

    a2 = *(int*)((char*)a0 + 136);
    cond = a2 == 0;
    if (cond) goto L0028A3B8;
    cond = a1 == 0;
    if (cond) goto L0028A3A8;
    v1 = *(unsigned short*)((char*)a2 + 20);
    v1 = v1 | 4;
    *(short*)((char*)a2 + 20) = v1;
    goto L0028A3B8;
L0028A3A8:;
    v1 = *(unsigned short*)((char*)a2 + 20);
    v1 = v1 & 65531;
    *(short*)((char*)a2 + 20) = v1;
L0028A3B8:;
    a2 = *(int*)((char*)a0 + 144);
    cond = a2 == 0;
    if (cond) goto L0028A3F0;
    cond = a1 == 0;
    if (cond) goto L0028A3E0;
    v1 = *(unsigned short*)((char*)a2 + 20);
    v1 = v1 | 4;
    *(short*)((char*)a2 + 20) = v1;
    goto L0028A3F0;
L0028A3E0:;
    v1 = *(unsigned short*)((char*)a2 + 20);
    v1 = v1 & 65531;
    *(short*)((char*)a2 + 20) = v1;
L0028A3F0:;
    a0 = *(int*)((char*)a0 + 152);
    cond = a0 == 0;
    if (cond) goto L0028A428;
    cond = a1 == 0;
    if (cond) goto L0028A418;
    v1 = *(unsigned short*)((char*)a0 + 20);
    v1 = v1 | 4;
    *(short*)((char*)a0 + 20) = v1;
    goto L0028A428;
L0028A418:;
    v1 = *(unsigned short*)((char*)a0 + 20);
    v1 = v1 & 65531;
    *(short*)((char*)a0 + 20) = v1;
L0028A428:;
    goto ret;
ret:;
}
#pragma pop /* merge_units */
/* merge_units: end func_0028A380 */

/* merge_units: begin func_0028A430 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

#if 0 /* merge_units */
extern int D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(int*)&D_004FFC04) /* merge_units */

extern int FrontEnd_FreePolicyLists(int);

/* If the pending flag is set, call FrontEnd_FreePolicyLists on the global at D_004FFC04 and clear it. */
void func_0028A430(Unk28A430* self) {
    if (self->pending != 0) {
        FrontEnd_FreePolicyLists(D_004FFC04);
        self->pending = 0;
    }
}
#undef D_004FFC04 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028A430 */

/* merge_units: begin func_0028A470 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int FrontEnd_DownloadPolicies(int);                               
#if 0 /* merge_units */
extern int D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(int*)&D_004FFC04) /* merge_units */


#pragma opt_common_subs off
void func_0028A470(int arg0) {
    if (F_(arg0, 0x80, unsigned char) == 0) {
        FrontEnd_DownloadPolicies(D_004FFC04);
        F_(arg0, 0x80, unsigned char) = 1U;
    }
}
#undef D_004FFC04 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028A470 */

/* merge_units: begin func_0028A4B0 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; unsigned short flags; } W;
typedef struct { char pad0[0x10]; int state; char pad14[0x8C - 0x14]; W* p8C; int pad90; W* p94; int pad98; char* p9C; char padA0[4]; unsigned char bA4; } S;
extern char D_00506340[];
extern char D_00506350[];
extern unsigned char D_00506360;
char* AgentData_GetName(char* a);
void GuiScreen_Wake(S* s);
void GuiTextWidget_SetText(W* w, char* s, int a);
void func_0028A4B0(S* self)
{
    if (self->state == 1) {
        if (self->p8C) {
            self->p8C->flags &= ~4;
            GuiTextWidget_SetText(self->p8C, D_00506350, 0);
        }
        if (self->p94) {
            self->p94->flags &= ~4;
            GuiTextWidget_SetText(self->p94, D_00506340, 0);
        }
        self->bA4 = D_00506360;
        self->state = -1;
    } else {
        if (self->p8C) {
            self->p8C->flags &= ~4;
            GuiTextWidget_SetText(self->p8C, AgentData_GetName(self->p9C), 0);
        }
        if (self->p94) {
            self->p94->flags &= ~4;
            GuiTextWidget_SetText(self->p94, self->p9C + 0x8CC, 0);
        }
        self->bA4 = 0;
    }
    GuiScreen_Wake(self);
}
#pragma pop /* merge_units */
/* merge_units: end func_0028A4B0 */

/* merge_units: begin func_0028A5C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W28A5C0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* type);
    char pad[0x80];
    int f84;
};
struct Mgr_28A5C0 { char pad[0x265]; unsigned char b265; };
struct S_28A5C0 {
    char pad0[0x20]; W28A5C0* p20; char pad24[0x88 - 0x24];
    W28A5C0* p88; W28A5C0* p8C; W28A5C0* p90; W28A5C0* p94; W28A5C0* p98; int f9C; W28A5C0* pA0;
    char padA4[4]; int fA8; unsigned char bAC; unsigned char bAD;
};
extern "C" {
#if 0 /* merge_units */
extern Mgr_28A5C0* D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(Mgr_28A5C0 **)&D_004FFC04) /* merge_units */

extern char g_Game[];
extern char D_004A96F8[];
extern char D_004A9718[];
extern char D_004A9880[];
extern char D_004A9870[];
extern char D_004A7520[];
extern int D_0048B400;
extern int D_0048B408;
extern int D_0048B410;
extern int D_0048B418;
extern int D_0048B420;
extern int D_0048B428;
void GuiScreen_Init(void);
int Agent_GetSelected(void* a, int b);
W28A5C0* GuiWidget_FindChildByName(S_28A5C0* a, int b);
char* Loc_LookupText(char* key);
#if 0 /* merge_units */
void GuiTextWidget_SetText(void* w, char* s, int a);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((W *)(a0), (a1), (a2))) /* merge_units */

}
extern "C" void func_0028A5C0(S_28A5C0* self)
{
    W28A5C0* p;
    GuiScreen_Init();
    self->f9C = Agent_GetSelected(g_Game, -1);
    self->p88 = GuiWidget_FindChildByName(self, D_0048B400);
    p = GuiWidget_FindChildByName(self, D_0048B408);
    p = (p && p->IsA(D_004A9880)) ? p : 0;
    self->p8C = p;
    if (self->p8C)
        self->p8C->f84 = 15;
    self->p90 = GuiWidget_FindChildByName(self, D_0048B410);
    p = GuiWidget_FindChildByName(self, D_0048B418);
    p = (p && p->IsA(D_004A9880)) ? p : 0;
    self->p94 = p;
    if (self->p94)
        self->p94->f84 = 15;
    p = GuiWidget_FindChildByName(self, D_0048B420);
    p = (p && p->IsA(D_004A9870)) ? p : 0;
    self->p98 = p;
    p = GuiWidget_FindChildByName(self, D_0048B428);
    p = (p && p->IsA(D_004A7520)) ? p : 0;
    self->pA0 = p;
    if (self->pA0)
        GuiTextWidget_SetText(self->pA0, Loc_LookupText(D_004A96F8), 0);
    if (self->p98)
        GuiTextWidget_SetText(self->p98, Loc_LookupText(D_004A9718), 0);
    self->bAD = 0;
    if (!D_004FFC04->b265)
        self->p20 = self->p98;
    self->fA8 = -1;
}
#undef D_004FFC04 /* merge_units */
#undef GuiTextWidget_SetText /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0028A5C0 */

/* merge_units: begin func_0028A7E0 */
#pragma push /* merge_units */
typedef struct { int words[3]; } SsoString;
typedef struct { char unused; } Allocator; /* empty allocator object passed by value */
extern int strlen(const char* s); /* strlen */
extern void String_Reserve(SsoString* s, int capacity);
extern void* String_Replace(SsoString* s, int pos, int count, const char* first, const char* last, Allocator alloc);

/* String constructor from a C string. */
SsoString* String_CtorCStr(SsoString* self, const char* text)
{
    Allocator alloc;
    int len;
    self->words[0] = 0;
    self->words[1] = 0;
    self->words[2] = 0;
    len = strlen(text);
    String_Reserve(self, len);
    String_Replace(self, 0, 0, text, text + len, alloc);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0028A7E0 */

/* merge_units: begin func_0028A860 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004A97C0[] = "basic_string: out_of_range"; }
extern "C" { char D_004A97E0[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_0028A860, D_004A97C0, D_004A97E0, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_0048B430, D_0048B438, func_00125FE8, String_Assign)
#pragma pop /* merge_units */
/* merge_units: end func_0028A860 */

/* merge_units: begin func_0028AD50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_assign.h"

/* Assign one string to another. */
DEFINE_SHORT_STRING_ASSIGN(func_0028AD50)
#pragma pop /* merge_units */
/* merge_units: end func_0028AD50 */

/* merge_units: begin func_0028ADE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_reserve.h"

extern "C" { char D_004A9800[] = "basic_string::reserve length_error"; }
DEFINE_STRING_RESERVE(func_0028ADE0, D_004A9800, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_0028ADE0 */

/* merge_units: begin func_0028B120 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(func_0028B120)
#pragma pop /* merge_units */
/* merge_units: end func_0028B120 */
