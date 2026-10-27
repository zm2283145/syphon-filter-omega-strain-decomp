/*
 * SFOGame/Source/GuiNetAgencyCell: 5 files, 002AF010-002AF2A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002AF010 */
#pragma push /* merge_units */
#include "types.h"

int D_004ABE00 = 0x4E697547;
extern int strcmp(void*);

/* Returns whether strcmp(&D_004ABE00) returned 0. */
int GuiNetAgencyCell_IsClass(void) {
    return strcmp(&D_004ABE00) == 0;
}
static inline void merge_flush_func_002AF010(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002AF010 */

/* merge_units: begin func_002AF040 */
#pragma push /* merge_units */
typedef struct { int w[3]; } String;
typedef struct { int f0; int count; } L_002AF040;
typedef struct { char pad0[0x1C]; L_002AF040 list; } G_002AF040;
typedef struct { int id; int f4; char pad8[0xC - 8]; String fC; char pad18[0x2C - 0x18]; String name; } E_002AF040;
typedef struct { char pad0[0x78]; unsigned char b78; char pad79[0x174 - 0x79]; String s174; } S_002AF040;
extern void* D_004FFC04;
extern char D_004ABCD0[];
extern G_002AF040* cDME_GetLobby(void);
extern E_002AF040* SFOLobbyList_GetSlot(L_002AF040* l, int i);
extern char* std_basic_string_char_char_traits_char_c_str(String* s);
extern int String_CompareNoCase(String* a, char* b);
extern int GuiLobbyScreen_GetLobbyString(S_002AF040* it, int id, String* a, String* b, int c, int d);
extern void cGameFrontEnd_PushMessageBox(void* mgr, int a, char* fmt, int v, S_002AF040* it, int b);
extern void GuiScreen_PollLobby(S_002AF040* self);
void GuiNetAgencyCell_PollLobby(S_002AF040* self)
{
    G_002AF040* g;
    int i;
    E_002AF040* e;
    L_002AF040* list;
    int n;
    if (!self->b78)
        return;
    g = cDME_GetLobby();
    if (!g)
        return;
    list = &g->list;
    n = list ? list->count : 0;
    for (i = 0; i < n; i++) {
        e = SFOLobbyList_GetSlot(list, i);
        if (e && (e->id == 2 || e->id == 6) && !e->f4) {
            e->f4 = 1;
            if (!String_CompareNoCase(&e->name, std_basic_string_char_char_traits_char_c_str(&self->s174))) {
                void* mgr;
                int k;
                self->b78 = 0;
                k = e->id == 2 ? 0x2F : 0x7F;
                mgr = D_004FFC04;
                cGameFrontEnd_PushMessageBox(mgr, 2, D_004ABCD0, GuiLobbyScreen_GetLobbyString(self, k, &e->fC, &e->name, 0, 0), self, 0x17);
                return;
            }
        }
    }
    GuiScreen_PollLobby(self);
}
static inline void merge_flush_func_002AF040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002AF040 */

/* merge_units: begin func_002AF190 */
#pragma push /* merge_units */
typedef struct { int kind; String name; } Src;
typedef struct { char pad[0x100]; int kind; String name; } Item;
extern void std_basic_string_char_char_traits_char_ctor_charP(String* dst, String* src);
extern void std_basic_string_char_char_traits_char_assign_basicstringR(String* dst, String* src);
extern void String_Dtor(String* s, int flags);
#if 0 /* merge_units */
extern int GuiLobbyScreen_GetLobbyString(Item* it, int id, String* name, int a, int b, int c);
#endif /* merge_units */
#define GuiLobbyScreen_GetLobbyString(a0, a1, a2, a3, a4, a5) (GuiLobbyScreen_GetLobbyString((S_002AF040 *)(a0), (a1), (a2), (String *)(a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void cGameFrontEnd_PushMessageBox(void* mgr, int a, char* fmt, int v, Item* it, int b);
#endif /* merge_units */
#define cGameFrontEnd_PushMessageBox(a0, a1, a2, a3, a4, a5) (cGameFrontEnd_PushMessageBox((a0), (a1), (a2), (a3), (S_002AF040 *)(a4), (a5))) /* merge_units */

/* Copies kind and name from src, then registers the item. */
void GuiNetAgencyCell_SelectAgentRemove(Item* it, Src* src)
{
    String tmp;
    void* mgr;
    it->kind = src->kind;
    std_basic_string_char_char_traits_char_ctor_charP(&tmp, &src->name);
    std_basic_string_char_char_traits_char_assign_basicstringR(&it->name, &tmp);
    String_Dtor(&tmp, 0);
    mgr = D_004FFC04;
    cGameFrontEnd_PushMessageBox(mgr, 5, D_004ABCD0, GuiLobbyScreen_GetLobbyString(it, 0x51, &src->name, 0, 0, 0), it, 0x12);
}
#undef GuiLobbyScreen_GetLobbyString /* merge_units */
#undef cGameFrontEnd_PushMessageBox /* merge_units */
static inline void merge_flush_func_002AF190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002AF190 */

/* merge_units: begin func_002AF230 */
#pragma push /* merge_units */
typedef struct { char pad[0x160]; void* target; } Obj2AF230;
#if 0 /* merge_units */
extern void* cDME_GetLobby(void);
#endif /* merge_units */
#define cDME_GetLobby() ((void *)cDME_GetLobby()) /* merge_units */

extern char* SFOLobby_CellGetMessage(void* p);
extern void GuiTextWidget_SetText(void* target, const char* text, int zero);

/* Forwards the current text (or a default) to the object's target. */
void GuiNetAgencyCell_UpdateCellMessage(Obj2AF230* o)
{
    void* p;
    p = cDME_GetLobby();
    if (p) {
        char* text = SFOLobby_CellGetMessage(p);
        if (o->target)
            GuiTextWidget_SetText(o->target, text ? text : D_004ABCD0, 0);
    }
}
#undef cDME_GetLobby /* merge_units */
static inline void merge_flush_func_002AF230(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002AF230 */

/* merge_units: begin func_002AF2A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x160]; void* target; } Obj2AF;
extern void GuiMissionLobbyScreen_onAdvanceTime(Obj2AF* o);
#if 0 /* merge_units */
extern void* cDME_GetLobby(void);
#endif /* merge_units */
#define cDME_GetLobby() ((void *)cDME_GetLobby()) /* merge_units */


/* Refreshes the object and forwards the current text (or a default) to its target. */
void GuiNetAgencyCell_onAdvanceTime(Obj2AF* o)
{
    void* p;
    GuiMissionLobbyScreen_onAdvanceTime(o);
    p = cDME_GetLobby();
    if (p) {
        char* text = SFOLobby_CellGetMessage(p);
        if (o->target)
            GuiTextWidget_SetText(o->target, text ? text : D_004ABCD0, 0);
    }
}
#undef cDME_GetLobby /* merge_units */
static inline void merge_flush_func_002AF2A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002AF2A0 */
