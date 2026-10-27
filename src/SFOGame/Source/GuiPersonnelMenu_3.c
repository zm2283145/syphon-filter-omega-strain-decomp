/*
 * SFOGame/Source/GuiPersonnelMenu: 5 files, 00354CF0-00354E40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00354CF0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "member_dtor_chain.h"

/* Deleting destructor that runs the member destructor. */
DEFINE_MEMBER_DTOR_CHAIN(func_00354CF0, std_vector_deleter_tRequirementInfo_dtor)
static inline void merge_flush_func_00354CF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00354CF0 */

/* merge_units: begin func_00354D60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00354D60, std_vector_deleter_tRequirementInfo_dtor)
static inline void merge_flush_func_00354D60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00354D60 */

/* merge_units: begin func_00354DC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* func_00354DC0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00354DC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00354DC0 */

/* merge_units: begin func_00354DE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_DIRECT_BASE_DTOR(func_00354DE0, std_vector_deleter_tRequirementInfo_dtor)
static inline void merge_flush_func_00354DE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00354DE0 */

/* merge_units: begin message_354E40 */
#pragma push /* merge_units */
#pragma cplusplus on

struct W4E40 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* t);
};
typedef struct { char* begin; char* end; char* cap; int pad; } Str4E40;
typedef struct { int id; char pad4[4]; unsigned char flag; char pad9[0x14 - 9]; } E4E40;
struct L4E40 {
    int a0;
    int count;
    E4E40* data;
    unsigned char aC;
    int size() const { return count; }
};
typedef struct { char pad[0x14]; unsigned short flags; } P4E40;
typedef struct {
    char pad0[0x6C]; char s6C[0xC]; char s78[0xC];
    unsigned char kind; char pad85[3]; int arg; int f8C; int f90; bool on;
    char pad95[0xA4 - 0x95]; P4E40* fA4;
} O4E40;

extern "C" {
extern char D_004BB088[];
static char* D_00492C48 = D_004BB088;
extern char D_004A7520[];
extern char g_Game[];
extern const char* D_0048C160[];
void std_basic_string_char_char_traits_char_ctor_charP(Str4E40* s, const char* text);
void std_basic_string_char_char_traits_char_assign_basicstringR(void* dst, Str4E40* s);
void String_Dtor(Str4E40* s, int flags);
W4E40* GuiWidget_FindChild_charP(void* o, char* name);
void* cGameSystem_GetAgentData(void* p, int i);
void func_00296FA0(L4E40* l);
void func_00299360(L4E40* l, int flags);
void cAgentData_GetAchievements(void* ag, unsigned char kind, L4E40* l);
void GuiTextWidget_SetDisableWrap(W4E40* w, int v);
void GuiTextWidget_SetText(W4E40* w, int text, int f);
int nGlobalization_GetString_charP(const char* key);
enum E4E40on { ON0, ON1 };
void GuiPersonnelMenu_SetMode(O4E40* o, unsigned char on);
void GuiPersonnelMenu_SetInfo(O4E40* self, const char* a, const char* b, unsigned char kind, int arg, int c, int d);
}

/* The &l.data local and the re-derived element pointer reproduce retail register allocation; the enum ternary keeps the movz/andi argument. */
static inline W4E40* Cast(W4E40* w, void* t) { return w && w->IsA(t) ? w : 0; }

void GuiPersonnelMenu_SetInfo(O4E40* self, const char* a, const char* b, unsigned char kind, int arg, int c, int d)
{
    W4E40* w;
    {
        Str4E40 s;
        std_basic_string_char_char_traits_char_ctor_charP(&s, a);
        std_basic_string_char_char_traits_char_assign_basicstringR(self->s6C, &s);
        String_Dtor(&s, 0);
    }
    {
        Str4E40 s;
        std_basic_string_char_char_traits_char_ctor_charP(&s, b);
        std_basic_string_char_char_traits_char_assign_basicstringR(self->s78, &s);
        String_Dtor(&s, 0);
    }
    self->kind = kind;
    self->arg = arg;
    self->f8C = c;
    self->f90 = d;
    w = Cast(GuiWidget_FindChild_charP(self, D_00492C48), D_004A7520);
    if (w) {
        void* ag = cGameSystem_GetAgentData(g_Game, -1);
        if (self->kind != 6) {
            L4E40 l;
            func_00296FA0(&l);
            l.aC = 1;
            cAgentData_GetAchievements(ag, kind, &l);
            if (arg < l.size()) {
                GuiTextWidget_SetDisableWrap(w, 1);
                E4E40** pd = &l.data;
                E4E40* e = *pd + arg;
                GuiTextWidget_SetText(w, e->id, 0);
                e = *pd + arg;
                self->on = e->flag != 0;
                GuiPersonnelMenu_SetMode(self, self->on ? ON1 : ON0);
            }
            func_00299360(&l, 0);
        } else {
            const char* name = 0;
            if (self->arg >= 0 && self->arg < 17)
                name = D_0048C160[self->arg];
            if (name) {
                GuiTextWidget_SetText(w, nGlobalization_GetString_charP(name), 0);
                GuiTextWidget_SetDisableWrap(w, 1);
            }
            self->on = false;
            GuiPersonnelMenu_SetMode(self, ON0);
        }
    }
    if (self->fA4) {
        if (self->on)
            self->fA4->flags |= 2;
        else
            self->fA4->flags &= ~2;
    }
}
static inline void merge_flush_message_354E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end message_354E40 */
