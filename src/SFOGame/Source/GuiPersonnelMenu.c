/*
 * SFOGame/Source/GuiPersonnelMenu: 4 files, 00354980-00354A70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00354980 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiPersonnelMenu class-name getter (vtable D_004DF020 slot 19).
 */

#include "loose03_types.h"

char D_004BB200[] = "GuiPersonnelMenu";       /* "GuiPersonnelMenu" */

/* Returns the class name string "GuiPersonnelMenu". */
const char* GuiPersonnelMenu_GetClassName(void) {
    return D_004BB200;
}
static inline void merge_flush_func_00354980(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00354980 */

/* merge_units: begin func_00354990 */
#pragma push /* merge_units */
#include "types.h"

/* "GuiPersonnelMenu" */
/* strcmp */
extern int strcmp(const char* a, const char* b);

/* GuiPersonnelMenu::IsA: returns 1 if the given class name is "GuiPersonnelMenu". */
int GuiPersonnelMenu_IsClass(void* self, const char* name)
{
    return strcmp("GuiPersonnelMenu", name) == 0;
}
static inline void merge_flush_func_00354990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00354990 */

/* merge_units: begin func_003549C0 */
#pragma push /* merge_units */
typedef struct { char pad[0x6C]; char s6C[0xC]; char s78[0xC]; signed char a84; char pad85[3]; int a88; } S3549C0;
extern int GuiAchievementScreen_Construct(int id);
extern char* std_basic_string_char_char_traits_char_c_str(void* str);
extern void* Gui_Manager(void);
extern void* Gui_Canvas(void);
extern int GuiManager_OpenGui(void* mgr, char* a, char* b);
extern void GuiWidget_SendMessage(void* self, int a, int b, int c, int d);
extern void GuiCanvas_Transition(void* mgr, void* self, int snd);
void GuiPersonnelMenu_PreviousScreen(S3549C0* o)
{
    int s = GuiAchievementScreen_Construct(o->a84);
    if (!s) {
        char* b = std_basic_string_char_char_traits_char_c_str(o->s78);
        char* a = std_basic_string_char_char_traits_char_c_str(o->s6C);
        s = GuiManager_OpenGui(Gui_Manager(), a, b);
    }
    if (s) {
        GuiWidget_SendMessage(o, s, 0x3000, o->a88, 0);
        GuiCanvas_Transition(Gui_Canvas(), o, s);
    }
}
static inline void merge_flush_func_003549C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003549C0 */

/* merge_units: begin func_00354A70 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { unsigned short a0; unsigned short a2; short pad4; unsigned short a6; unsigned short a8; } E354A70;
typedef struct { char pad[0x94]; unsigned char a94; char pad95[0x1AB]; int a240; } S354A70;
extern "C" {
void* Gui_Canvas(void);
#if 0 /* merge_units */
void GuiWidget_SendMessage(void* self, void* mgr, int a, int b, int c);
#endif /* merge_units */
#define GuiWidget_SendMessage(a0, a1, a2, a3, a4) (GuiWidget_SendMessage((a0), (int)(a1), (a2), (a3), (a4))) /* merge_units */

void GuiPersonnelMenu_SetMode(S354A70* self, int on);
bool GuiPersonnelScreen_onInput(void* self, E354A70* e);
bool GuiPersonnelMenu_onInput(S354A70* self, E354A70* e);
}
bool GuiPersonnelMenu_onInput(S354A70* self, E354A70* e)
{
    bool b = e->a0 == 1 && e->a2 == 0 && e->a8 == 0x40 && e->a6 == 0;
    if (b) {
        if (self->a94) {
            GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 2, 0);
            if (self->a240 == 0) GuiPersonnelMenu_SetMode(self, 1);
            else GuiPersonnelMenu_SetMode(self, 0);
        }
        return 1;
    }
    return GuiPersonnelScreen_onInput(self, e);
}
#undef GuiWidget_SendMessage /* merge_units */
static inline void merge_flush_func_00354A70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00354A70 */
