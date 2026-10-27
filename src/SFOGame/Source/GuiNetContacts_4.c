/*
 * SFOGame/Source/GuiNetContacts: 1 file, 002ADA10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiMissionList_2ADA10 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char b[0xC]; } String;
typedef struct { int id; char name[1]; } NameRec;
typedef struct { char pad[0x100]; int id; String name; } Obj2AD;
extern void* D_004FFC04;
const unsigned int D_004ABB08[2] = { 0x0, 0x0 };
extern void std_basic_string_char_char_traits_char_ctor_charP(String* s, const char* text);
extern void std_basic_string_char_char_traits_char_assign_basicstringR(String* dst, String* src);
extern void String_Dtor(String* s, int flag);
extern int std_basic_string_char_char_traits_char_c_str(String* s);
extern int GuiLobbyScreen_GetLobbyString(Obj2AD* o, int type, int a, int b, int c, int d);
extern void cGameFrontEnd_PushMessageBox(void* mgr, int a, const char* text, int b, Obj2AD* o, int c);

/* Sets the id and name from rec, then registers the object (event 0x35) with the manager. */
void GuiNetContacts_SelectAgentRemove(Obj2AD* o, NameRec* rec)
{
    void* mgr;
    String tmp;
    int h;
    o->id = rec->id;
    std_basic_string_char_char_traits_char_ctor_charP(&tmp, rec->name);
    std_basic_string_char_char_traits_char_assign_basicstringR(&o->name, &tmp);
    String_Dtor(&tmp, 0);
    h = std_basic_string_char_char_traits_char_c_str(&o->name);
    mgr = D_004FFC04;
    cGameFrontEnd_PushMessageBox(mgr, 5, ((char*)D_004ABB08), GuiLobbyScreen_GetLobbyString(o, 0x35, h, 0, 0, 0), o, 0xD);
}
static inline void merge_flush_GuiMissionList_2ADA10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiMissionList_2ADA10 */
