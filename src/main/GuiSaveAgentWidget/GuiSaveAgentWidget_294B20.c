/*
 * main/GuiSaveAgentWidget: 4 files, 00294B20-00294F50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00294B20 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x98]; void* a98; void* a9C; } S294B20;
extern void String_Copy(char* dst, char* src);
extern char* strchr(char* s, int c);
extern void func_0041BEB0(void* w, char* text, int f);
#pragma bool off
static inline int IsZero294B20(int c) { return (c != 0) ^ 1; }
static inline int IsSp294B20(int c) { return (char)c == ' '; }
#pragma opt_rotateloops off
void GuiCommandCenter_SplitLevelName(S294B20* s, char* str)
{
    char* p;
    char buf[0x70];
    if (!str)
        return;
    String_Copy(buf, str);
    p = strchr(buf, ':');
    if (p) {
        *p = 0;
        func_0041BEB0(s->a98, buf, 0);
        p++;
        while (!IsZero294B20(*p) && IsSp294B20(*p))
            p++;
        if (p)
            func_0041BEB0(s->a9C, p, 0);
    } else {
        func_0041BEB0(s->a98, str, 0);
    }
}
#pragma opt_rotateloops reset
#pragma bool reset
#pragma pop /* merge_units */
/* merge_units: end func_00294B20 */

/* merge_units: begin func_00294BF0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V294BF0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); };
typedef struct { char pad[0x44]; V294BF0* m44; } O294BF0;
extern "C" O294BF0* GuiWidget_FindChildByName(int a, int b);
extern "C" void func_00294BF0(int a, int b, int on)
{
    O294BF0* o = GuiWidget_FindChildByName(a, b);
    if (o) {
        if (on)
            o->m44->v3();
        else
            o->m44->v4();
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00294BF0 */

/* merge_units: begin func_00294C60 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Str_00294C60 { char d[0x10]; };
struct Str12_00294C60 { char d[0xC]; };
struct Sub_00294C60 { char pad[0x40]; char name[4]; };
struct Mgr_00294C60 { char pad[0x188]; Sub_00294C60 sub; };
struct S_00294C60 {
    char pad0[0x98]; void* p98; void* p9C; void* pA0; int fA4; int fA8; int fAC; int fB0;
    char padB4[0x178 - 0xB4]; unsigned char b178[0x78]; unsigned char b1F0[0x14]; Str12_00294C60 s204[0x11];
};
struct S2_00294C60 { char pad0[0x1CC]; int f1CC; int f1D0; };
extern "C" {
extern char D_004AA288[];
extern char* D_0048C160[];
extern char D_004FFC90[];
extern Mgr_00294C60* D_004FFC04;
extern char D_004AA200[];
#if 0 /* merge_units */
void func_0041BEB0(void* w, char* s, int a);
#endif /* merge_units */
#define func_0041BEB0(a0, a1, a2) (func_0041BEB0((a0), (a1), (a2))) /* merge_units */

char* strncpy(char* d, const char* s, int n);
char* Loc_LookupText(char* key);
void String_CtorCStr_13B480(Str_00294C60* s, const char* c);
void func_0013D680(Str12_00294C60* d, Str_00294C60* s);
void String_Dtor(Str_00294C60* s, int flags);
int String_Length(Str12_00294C60* s);
char* String_CStr(Str12_00294C60* s);
#if 0 /* merge_units */
void GuiCommandCenter_SplitLevelName(S_00294C60* self, char* t);
#endif /* merge_units */
#define GuiCommandCenter_SplitLevelName(a0, a1) (GuiCommandCenter_SplitLevelName((S294B20 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void String_Copy(char* d, const char* s);
#endif /* merge_units */
#define String_Copy(a0, a1) (String_Copy((a0), (char *)(a1))) /* merge_units */

}
extern "C" void GuiCommandCenter_SetTexts(S_00294C60* self)
{
    char* key;
    int i;
    if (!self->p98 || !self->p9C || !self->pA0)
        return;
    func_0041BEB0(self->p98, D_004AA288, 0);
    func_0041BEB0(self->p9C, D_004AA288, 0);
    func_0041BEB0(self->pA0, D_004AA288, 0);
    i = ((S2_00294C60*)self)->f1CC;
    if (i == -1)
        return;
    if (i < 0x11) {
        if (self->b178[i]) {

            unsigned char* f;
            Str12_00294C60* st;
            char* txt;
            key = D_0048C160[i];
            strncpy(D_004FFC90, key, 0x80);
            if (!self->b1F0[i]) {
                char* t = Loc_LookupText(key);
                if (t) {
                    Str_00294C60 s;
                    String_CtorCStr_13B480(&s, t);
                    func_0013D680(&self->s204[i], &s);
                    String_Dtor(&s, 0);
                }
                self->b1F0[i] = 1;
            }
            txt = (char*)&self->s204[i];
            {
                bool e = String_Length((Str12_00294C60*)txt) == 0;
                if (e) {
                    txt = 0;
                } else {
                    txt = String_CStr((Str12_00294C60*)txt);
                    asm { .set reorder } /* scheduling barrier: keeps retail's branch layout */
                }
            }
            if (txt)
                GuiCommandCenter_SplitLevelName(self, txt);
            else
                func_0041BEB0(self->p98, key, 0);
            {
                Sub_00294C60* sub = &D_004FFC04->sub;
                String_Copy(sub->name, txt ? txt : key);
            }
            return;
        } else {
            char* t = Loc_LookupText(D_004AA200);
            func_0041BEB0(self->pA0, t ? t : D_004AA288, 0);
            return;
        }
    }
    if (self->pA0) {
        int k = ((S2_00294C60*)self)->f1D0;
        if (k == self->fA8)
            func_0041BEB0(self->pA0, Loc_LookupText("Online"), 0);
        else if (k == self->fA4)
            func_0041BEB0(self->pA0, Loc_LookupText("Personnel"), 0);
        else if (k == self->fAC)
            func_0041BEB0(self->pA0, Loc_LookupText("UnlockedMedia"), 0);
        else if (k == self->fB0)
            GuiCommandCenter_SplitLevelName(self, Loc_LookupText("Training"));
    }
}
#undef func_0041BEB0 /* merge_units */
#undef GuiCommandCenter_SplitLevelName /* merge_units */
#undef String_Copy /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00294C60 */

/* merge_units: begin func_00294F50 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; unsigned short flags; } E294F50;
typedef struct { char pad[0x118]; E294F50* items[45]; int cur; } S294F50;
extern int GuiCommandCenter_GetDefaultSlot(S294F50* s);
extern void GuiCommandCenter_Select(S294F50* s, int i, int f);
extern void* Gui_GetScreenStack(void);
extern void func_0041E0F0(void* a, void* b, int c, int d, int e);
void GuiCommandCenter_MoveSelection(S294F50* s, int dir)
{
    int cur = s->cur;
    int i;
    int step;
    if (cur == -1) {
        GuiCommandCenter_Select(s, GuiCommandCenter_GetDefaultSlot(s), 1);
        return;
    }
    {
        int up = dir == 4;
        int down = dir == 8;
        if (up || down) {
            if (up)
                step = 1;
            else
                step = -1;
            for (i = cur + step; i != cur; i += step) {
                E294F50* e;
                if (i >= 24)
                    i = 0;
                if (i < 0)
                    i = 23;
                e = s->items[i];
                if (e && (e->flags & 4) && (e->flags & 2)) {
                    func_0041E0F0(s, Gui_GetScreenStack(), 0x10, 9, 0);
                    GuiCommandCenter_Select(s, i, 1);
                    return;
                }
            }
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00294F50 */
