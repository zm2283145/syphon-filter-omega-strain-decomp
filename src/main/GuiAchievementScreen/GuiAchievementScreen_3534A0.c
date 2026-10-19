/*
 * main/GuiAchievementScreen: 14 files, 003534A0-003542F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003534A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x64]; int a; int b; char pad2[0x7C - 0x6C]; unsigned char kind; char pad3[3]; char text[4]; } O3534A0;
typedef struct { char d[12]; } Str3534A0;
extern void *Gui_GetScreenList(void);
extern O3534A0 *GuiManager_FindOrLoad(void *mgr, char *type, char *name);
extern void String_CtorCStr_13B480(Str3534A0 *s, char *c);
extern void String_AssignString(void *dst, Str3534A0 *s);
extern void String_Dtor(Str3534A0 *s, int flags);
O3534A0 *GuiPersonnel_OpenAchievement(unsigned char kind)
{
    char *name;
    char *text;
    int a = 2;
    int b = 1;
    O3534A0 *o;
    switch (kind) {
    case 0:
        name = "SARATING";
        text = "CSUBMENU";
        a = 3;
        b = 0x1A;
        break;
    case 1:
        name = "COMENDAT";
        text = "CSUBMENU";
        a = 4;
        break;
    case 2:
        name = "MEDALS";
        text = "CSUBMENU";
        break;
    default:
        return 0;
    }
    o = GuiManager_FindOrLoad(Gui_GetScreenList(), "GuiAchievementScreen", name);
    if (o == 0)
        return 0;
    o->kind = kind;
    {
        Str3534A0 s;
        String_CtorCStr_13B480(&s, text);
        String_AssignString(o->text, &s);
        String_Dtor(&s, 0);
    }
    o->a = a;
    o->b = b;
    return o;
}
#pragma pop /* merge_units */
/* merge_units: end func_003534A0 */

/* merge_units: begin func_003535D0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct {
    char pad[0x48]; int a48; char pad4C[0x18]; int a64; int a68; char pad6C[4]; int a70;
    char pad74[8]; signed char a7C; char pad7D[3]; char s80[0xC];
} S3535D0;
extern int GuiTextListWidget_GetItemId(int list);
extern char* String_CStr(void* str);
extern void* Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(void* self, void* mgr, int a, int b, int c);
extern void GuiPersonnelScreen_OpenMenu(void* self, char* s, int a, int b, int c, int d);
void GuiAchievementScreen_Select(S3535D0* o, int arg)
{
    int i = GuiTextListWidget_GetItemId(o->a48);
    if (i == -1 || i >= o->a70) {
        GuiWidget_SendEvent(o, Gui_GetScreenStack(), 0x10, 4, 0);
        return;
    }
    GuiPersonnelScreen_OpenMenu(o, String_CStr(o->s80), o->a7C, arg, o->a64, i + o->a68);
    GuiWidget_SendEvent(o, Gui_GetScreenStack(), 0x10, 0, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_003535D0 */

/* merge_units: begin func_003536A0 */
#pragma push /* merge_units */
typedef struct { int pad[3]; int aC; int pad10; } E3536A0;
typedef struct { char pad[0x48]; int a48; char pad4C[0x28]; E3536A0* a74; } S3536A0;
extern void GuiPersonnelScreen_ShowItem(S3536A0* o, int i, int v);
void GuiAchievementScreen_Show(S3536A0* o)
{
    int i = GuiTextListWidget_GetItemId(o->a48);
    if (i != -1) GuiPersonnelScreen_ShowItem(o, i, ((E3536A0*)((char*)o->a74 + i * 20))->aC);
}
#pragma pop /* merge_units */
/* merge_units: end func_003536A0 */

/* merge_units: begin func_00353700 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef enum { MODE_OFF, MODE_ON } Mode3700;

typedef struct {
    int id;
    int f4;
    bool flag;
    unsigned char pad[11];
} E3700;

typedef struct {
    unsigned char pad0[0x48];
    void* tbl;
    unsigned char pad4C[0x70 - 0x4C];
    int count;
    E3700* items;
} O3700;

extern "C" void GuiTextListWidget_AddItem(void* t, int id, int i, Mode3700 m);

/* MW folds `c ? 0 : 1` on ints into sltiu; enum constants keep the movz select. */
extern "C" void GuiAchievementScreen_Fill(O3700* self)
{
    int i;
    for (i = 0; i < self->count; i++) {
        E3700* e = &self->items[(unsigned int)i];
        GuiTextListWidget_AddItem(self->tbl, e->id, i, e->flag ? MODE_OFF : MODE_ON);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00353700 */

/* merge_units: begin func_00353790 */
#pragma push /* merge_units */
typedef struct { char b[0xC]; } String;
typedef struct { char pad[0x64]; int unk64; int unk68; char pad2[0x10]; char kind; char pad3[3]; String name; } Obj353;
#if 0 /* merge_units */
extern void String_CtorCStr_13B480(String* s, const char* text);
#endif /* merge_units */
#define String_CtorCStr_13B480(a0, a1) (String_CtorCStr_13B480((Str3534A0 *)(a0), (char *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void String_AssignString(String* dst, String* src);
#endif /* merge_units */
#define String_AssignString(a0, a1) (String_AssignString((void *)(a0), (Str3534A0 *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void String_Dtor(String* s, int flag);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str3534A0 *)(a0), (a1))) /* merge_units */


/* Sets the kind, name and two parameters of the object. */
void func_00353790(Obj353* o, char kind, const char* name, int a, int b)
{
    String tmp;
    o->kind = kind;
    String_CtorCStr_13B480(&tmp, name);
    String_AssignString(&o->name, &tmp);
    String_Dtor(&tmp, 0);
    o->unk64 = a;
    o->unk68 = b;
}
#undef String_CtorCStr_13B480 /* merge_units */
#undef String_AssignString /* merge_units */
#undef String_Dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00353790 */

/* merge_units: begin func_00353800 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiAchievementScreen virtual (vtable D_004DEF90 slot 5).
 */

#include "loose03_types.h"

extern int Agent_GetSelected(void* agents, int index);
extern char g_Game[];       /* agent list */
extern void func_00299510(void*);
extern int AgentData_GetAwardRows(int agent, int a1, void* a2);
extern void GuiPersonnelScreen_Wake(GuiAchievementScreen*);  /* GuiPersonnelScreen slot 5 */

/* GuiAchievementScreen vtable slot 5: refresh unk6C, pass it with unk7C to the selected agent, then call GuiPersonnelScreen_Wake. */
void GuiAchievementScreen_Wake(GuiAchievementScreen* self) {
    func_00299510(self->unk6C);
    AgentData_GetAwardRows(Agent_GetSelected(g_Game, -1), self->unk7C, self->unk6C);
    GuiPersonnelScreen_Wake(self);
}
#pragma pop /* merge_units */
/* merge_units: end func_00353800 */

/* merge_units: begin func_00353850 */
#pragma push /* merge_units */
typedef struct { int words[3]; } String_00353850; /* 12-byte short-string-optimized string */
typedef struct { char pad[0x64]; int unk64; int unk68; char pad6C[0x7C - 0x6C]; unsigned char unk7C; char pad7D[3]; String_00353850 name; } Obj80;
static const unsigned int dat_004BAF98[2] = { 0x0, 0x0 };
extern void GuiPersonnelScreen_Init(Obj80* self);
#if 0 /* merge_units */
extern void String_CtorCStr_13B480(String_00353850* s, const char* text);   /* String(const char*) */
#endif /* merge_units */
#define String_CtorCStr_13B480(a0, a1) (String_CtorCStr_13B480((Str3534A0 *)(a0), (char *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void String_AssignString(String_00353850* dst, String_00353850* src);       /* String::operator= */
#endif /* merge_units */
#define String_AssignString(a0, a1) (String_AssignString((void *)(a0), (Str3534A0 *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void String_Dtor(String_00353850* s, int flags);           /* ~String */
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str3534A0 *)(a0), (a1))) /* merge_units */


/* Resets the object: base reset, clears the flag, sets the name to ((char*)dat_004BAF98) and zeroes +0x64/+0x68. */
void GuiAchievementScreen_Init(Obj80* self)
{
    String_00353850 tmp;
    GuiPersonnelScreen_Init(self);
    self->unk7C = 0;
    String_CtorCStr_13B480(&tmp, ((char*)dat_004BAF98));
    String_AssignString(&self->name, &tmp);
    String_Dtor(&tmp, 0);
    self->unk64 = 0;
    self->unk68 = 0;
}
#undef String_CtorCStr_13B480 /* merge_units */
#undef String_AssignString /* merge_units */
#undef String_Dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00353850 */

/* merge_units: begin func_003538B0 */
#pragma push /* merge_units */
typedef struct { char tag; } Alloc;
typedef struct { char* begin; char* end; char* cap; } String_003538B0;

extern int strlen(const char* s); /* strlen */
extern void String_Reserve(String_003538B0* self, int n);
extern void String_Replace(String_003538B0* self, char* at, int unused, const char* first, const char* last, Alloc alloc);

/* Constructs a string from a C string; returns self. */
String_003538B0* String_CtorCStr_3538B0(String_003538B0* self, const char* s)
{
    int len;
    Alloc alloc;
    self->begin = 0;
    self->end = 0;
    self->cap = 0;
    len = strlen(s);
    String_Reserve(self, len);
    String_Replace(self, 0, 0, s, s + len, alloc);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003538B0 */

/* merge_units: begin func_00353930 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004BAFA0[] = "basic_string: out_of_range"; }
extern "C" { char D_004BAFC0[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_00353930, D_004BAFA0, D_004BAFC0, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_00492C38, D_00492C40, Libc_Memmove, String_Assign)
#pragma pop /* merge_units */
/* merge_units: end func_00353930 */

/* merge_units: begin func_00353E20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_assign.h"

/* Assign one string to another. */
DEFINE_SHORT_STRING_ASSIGN(func_00353E20)
#pragma pop /* merge_units */
/* merge_units: end func_00353E20 */

/* merge_units: begin func_00353EB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_reserve.h"

extern "C" { char D_004BAFE0[] = "basic_string::reserve length_error"; }
DEFINE_STRING_RESERVE(String_Reserve_353EB0, D_004BAFE0, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_00353EB0 */

/* merge_units: begin func_003541F0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(String_Dtor_3541F0)
#pragma pop /* merge_units */
/* merge_units: end func_003541F0 */

/* merge_units: begin func_003542E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_003542E0(char* self) {
    *(int*)(self + 4) = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003542E0 */

/* merge_units: begin func_003542F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "clear_buffer_dtor.h"

/* Clear and free a vector, optionally delete. */
DEFINE_CLEAR_BUFFER_DTOR(func_003542F0, D_004AA5B8)
#pragma pop /* merge_units */
/* merge_units: end func_003542F0 */
