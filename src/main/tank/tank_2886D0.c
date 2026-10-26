/*
 * main/tank: 8 files, 002886D0-00288B40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002886D0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_charPtr_1_dtor_void_2)
#pragma pop /* merge_units */
/* merge_units: end func_002886D0 */

/* merge_units: begin func_002887C0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_charPtr_dtor_void_2)
#pragma pop /* merge_units */
/* merge_units: end func_002887C0 */

/* merge_units: begin func_002888B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* g_Game;
extern int Game_CountAttractMovies(void*);
extern int GuiWidget_Init(Unk288A80*);

int* std_vector_charPtr_opIndex_uint_2(PtrVec* v, int i) {
    return v->data + i;
}

Rel* std_vector_charPtr_ctor_void_2(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Base update, then record whether an agent is selected. */
int GuiTitleScreen_Init(Unk288A80* self) {
    int selected;

    GuiWidget_Init(self);
    selected = Game_CountAttractMovies(&g_Game);
    self->unk48 = selected != 0;
    return selected;
}
#pragma pop /* merge_units */
/* merge_units: end func_002888B0 */

/* merge_units: begin func_00288920 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W_00288920 { char pad[0x14]; unsigned short flags; };
struct Scr_00288920 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void* GetFocus();
    char pad[0x10];
    unsigned short flags;
};
extern "C" {
extern char* D_0048B3E8;
extern char* D_0048B3F0;
extern char* D_0048B3F8;
W_00288920* GuiWidget_FindChildByName(Scr_00288920* s, char* name);
void* Gui_GetScreenStack(void);
void GuiScreen_SetFocus(void* stack, void* w);
}
extern "C" void GuiTitleScreen_EnableButtons(Scr_00288920* self, int on)
{
    char* names[3] = { D_0048B3E8, D_0048B3F0, D_0048B3F8 };
    unsigned int i;
    for (i = 0; i < 3; i++) {
        W_00288920* w = GuiWidget_FindChildByName(self, names[i]);
        if (w) {
            if (on)
                w->flags |= 4;
            else
                w->flags &= ~4;
        }
    }
    if (self->flags & 8)
        GuiScreen_SetFocus(Gui_GetScreenStack(), self->GetFocus());
}
#pragma pop /* merge_units */
/* merge_units: end func_00288920 */

/* merge_units: begin func_00288A40 */
#pragma push /* merge_units */
typedef struct TimedObj {
    char pad[0x4C];
    float seconds;
} TimedObj;

extern void* Time_GetMilliseconds(TimedObj* self);
extern float SoftFloat_U64ToFloat(void* src);

/* Caches a millisecond value from the source as seconds at +0x4C. */
void GuiTitleScreen_ResetTimer(TimedObj* self) {
    self->seconds = SoftFloat_U64ToFloat(Time_GetMilliseconds(self)) / 1000.0f;
}
#pragma pop /* merge_units */
/* merge_units: end func_00288A40 */

/* merge_units: begin func_00288A80 */
#pragma push /* merge_units */
extern void* D_004DD0A0;
extern void GuiWidget_ctor(Unk288A80*);

Unk288A80* GuiTitleScreen_ctor(Unk288A80* self) {
    GuiWidget_ctor(self);
    self->vtable = &D_004DD0A0;
    self->unk48 = 0;
    self->unk4C = 0;
    self->unk50 = -2;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00288A80 */

/* merge_units: begin func_00288AD0 */
#pragma push /* merge_units */
/* Short/long string header: bit 0 = long form, bits 1-7 = inline length. */
typedef struct StrHdr {
    unsigned isLong : 1;
    unsigned shortLen : 7;
    int longLen;
} StrHdr;

extern int strlen(const char* s); /* strlen */
extern void String_Compare(StrHdr* str, int pos, int count, const char* src, int srcLen);

/* String assign from a C string: replaces the whole contents with cstr. */
void String_AssignCStr(StrHdr* str, const char* cstr) {
    int srcLen = strlen(cstr);
    int len;
    if (*(int*)str & 1) {
        len = str->longLen;
    } else {
        len = (unsigned char)str->shortLen;
    }
    String_Compare(str, 0, len, cstr, srcLen);
}
#pragma pop /* merge_units */
/* merge_units: end func_00288AD0 */

/* merge_units: begin func_00288B40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_compare_range.h"

/* String compare of a substring against a buffer. */
extern "C" { char D_004A9630[] = "string compare: pos > len"; }
DEFINE_STRING_COMPARE_RANGE(String_Compare_288B40, D_004A9630)
#pragma pop /* merge_units */
/* merge_units: end func_00288B40 */
