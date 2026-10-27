/*
 * SFOGame/Source/GuiMissionLobbyScreen: 2 files, 0033F0C0-0033F110
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0033F0C0 */
#pragma push /* merge_units */
#include "types.h"

extern int func_002ACC80(int, int);
extern int Gui_Canvas(void);

int GuiMissionLobbyScreen_ExitLobbyScreen(int a0) {
    int a1, v0, v1;
    int cond;

    v0 = *(unsigned char*)((char*)a0 + 128);
    cond = v0 == 0;
    if (cond) goto L0033F0F0;
    *(int*)((char*)a0 + 168) = 0;
    a0 = *(int*)((char*)a0 + 136);
    cond = a0 == 0;
    a1 = 0;
    if (cond) goto L0033F0F0;
    v0 = func_002ACC80(a0, a1);
L0033F0F0:;
    v0 = Gui_Canvas();
    v1 = *(int*)((char*)v0 + 104);
    v1 = v1 | 12;
    *(int*)((char*)v0 + 104) = v1;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_0033F0C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033F0C0 */

/* merge_units: begin func_0033F110 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
};
typedef struct { char* begin; char* end; char* cap; } String;
typedef struct { char pad[0x80]; unsigned char b80; char pad81[0xB8 - 0x81]; int fB8; } UI;
typedef struct { char pad[0x68]; int flags; } Mgr;
typedef struct {
    char pad[0x78]; unsigned char b78; char pad79[0x84 - 0x79]; int f84; UI* f88;
    char pad8C[0xA8 - 0x8C]; void* fA8; char padAC[0x100 - 0xAC]; int f100; char f104[4];
} O;
extern "C" {
extern char D_004B9C60[];
extern char D_004B9C28[];
static char* D_004928E0 = D_004B9C28;
extern char D_004A7520[];
extern char g_Game[];
extern unsigned char D_00532FF0;
extern int D_00532FF8;
extern int D_00533000;
void GuiScreen_Wake(O* o);
void std_basic_string_char_char_traits_char_ctor_charP(String* s, const char* text);
void std_basic_string_char_char_traits_char_assign_basicstringR(void* list, String* s);
void String_Dtor(String* s, int flags);
void GuiMissionLobbyScreen_SetDisplayMode(O* o, unsigned char mode);
W* GuiWidget_FindChild_charP(void* o, char* name);
void* cGameSystem_GetAgentData(void* p, int i);
char* cAgentData_GetUserName(void* a);
void GuiTextWidget_SetText(W* w, char* s, int f);
#if 0 /* merge_units */
Mgr* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((Mgr *)Gui_Canvas()) /* merge_units */

void GuiMissionLobbyScreen_onWake(O* o);
}
static inline W* Cast(W* w, void* t) { return w && w->IsA(t) ? w : 0; }

void GuiMissionLobbyScreen_onWake(O* o)
{
    W* w;
    GuiScreen_Wake(o);
    o->fA8 = 0;
    o->f100 = -1;
    {
        String s;
        std_basic_string_char_char_traits_char_ctor_charP(&s, D_004B9C60);
        std_basic_string_char_char_traits_char_assign_basicstringR(o->f104, &s);
        String_Dtor(&s, 0);
    }
    if (o->f88) {
        GuiMissionLobbyScreen_SetDisplayMode(o, 1);
        o->f88->fB8 = o->f84;
        o->f88->b80 = 1;
    }
    o->b78 = 1;
    w = Cast(GuiWidget_FindChild_charP(o, D_004928E0), D_004A7520);
    if (w)
        GuiTextWidget_SetText(w, cAgentData_GetUserName(cGameSystem_GetAgentData(g_Game, -1)), 0);
    D_00532FF0 = 0;
    D_00532FF8 = 0;
    D_00533000 = 0;
    Gui_Canvas()->flags |= 0xC;
    Gui_Canvas()->flags |= 0x3;
}
#undef Gui_Canvas /* merge_units */
static inline void merge_flush_func_0033F110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033F110 */
