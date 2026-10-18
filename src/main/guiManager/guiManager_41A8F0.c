/*
 * main/guiManager: 6 files, 0041A8F0-0041ADC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0041A8F0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } V4_A8F0;
extern V4_A8F0 D_004BF1A0;
extern V4_A8F0 D_004BF1B0;
extern float D_004BF1C0;
extern float D_00572100;
extern V4_A8F0 D_005720E0;
extern void GuiWidget_Update(void* self, float dt);
extern float Math_FMod(float x, float y);
static inline float Abs_A8F0(float x) { float r; asm { abs.s r, x } return r; }
static inline void Set(V4_A8F0* o, float x, float y, float z, float w) { o->x = x; o->y = y; o->z = z; o->w = w; }
static inline void Lerp(V4_A8F0* out, V4_A8F0* a, V4_A8F0* b, float t)
{
    float aw = a->w, az = a->z, ay = a->y, ax = a->x;
    Set(out, ax + t * (b->x - ax), ay + t * (b->y - ay), az + t * (b->z - az), aw + t * (b->w - aw));
}
void GuiTextEditWidget_Update(void* self, float dt)
{
    float t;
    float m;
    GuiWidget_Update(self, dt);
    m = Math_FMod(D_00572100 += 33.333332f * dt, D_004BF1C0);
    D_00572100 = m;
    t = Abs_A8F0(1.0f - 2.0f * m / D_004BF1C0);
    Lerp(&D_005720E0, &D_004BF1A0, &D_004BF1B0, t);
}
#pragma pop /* merge_units */
/* merge_units: end func_0041A8F0 */

/* merge_units: begin func_0041AA10 */
#pragma push /* merge_units */
#include "types.h"
typedef struct SsoString {
    union {
        struct { unsigned char isLong : 1; unsigned char shortLen : 7; } s;
        int flags;
    } h;
    int longLen;
    char* longData;
} SsoString;
typedef struct { char pad[0x48]; SsoString text; char pad2[0x24]; void* view; char pad3[4]; unsigned char active; char pad4[0xB]; int mode; } TextBox;
extern void func_0041BE50(TextBox* t);
extern void GuiTextEditWidget_MaskText(void* view, int len);
extern void GuiTextEditWidget_ClampCursor(TextBox* t, int mode);
/* Refreshes the text box, updating the view with the text length when active. */
void func_0041AA10(TextBox* t)
{
    func_0041BE50(t);
    if (t->active) {
        int len;
        if (!(t->text.h.flags & 1))
            len = (unsigned char)t->text.h.s.shortLen;
        else
            len = t->text.longLen;
        GuiTextEditWidget_MaskText(t->view, len);
    }
    GuiTextEditWidget_ClampCursor(t, t->mode);
}
#pragma pop /* merge_units */
/* merge_units: end func_0041AA10 */

/* merge_units: begin func_0041AA80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"

union Str_AA80 {
    struct { int w0; int len; char* data; } l;
    struct { unsigned char f : 1; unsigned char n : 7; } s;
    int Size() const { return (l.w0 & 1) ? l.len : (unsigned char)s.n; }
};
struct Target_AA80 {
    VPAD8(p) VPAD2(q) VPAD1(r)
    virtual void Activate();
};
struct O_AA80 {
    char pad[0x44];
    Target_AA80* target;
    Str_AA80 str;
    char pad54[0x30];
    int maxLen;
};
struct Ev_AA80 {
    unsigned short type;
    unsigned short mod;
    unsigned short pad4;
    unsigned short mod2;
    unsigned short key;
    char padA[6];
    unsigned char ch;
};
struct G_AA80 { char pad[0x52]; unsigned char alt; };
extern "C" G_AA80* Gui_GetScreenStack(void);
extern "C" int GuiTextEditWidget_Delete(O_AA80* o, bool fwd);
extern "C" int GuiTextEditWidget_Insert(O_AA80* o, char* text);

static inline bool Is3(Ev_AA80* e, unsigned short t, unsigned short m, unsigned short m2) { return e->type == t && e->mod == m && e->mod2 == m2; }
static inline bool Is4(Ev_AA80* e, unsigned short t, unsigned short m, unsigned short k, unsigned short m2) { return e->type == t && e->mod == m && e->key == k && e->mod2 == m2; }
extern "C" int GuiTextEditWidget_OnInput(O_AA80* self, Ev_AA80* e)
{
    if (Is3(e, 2, 0, 0)) {
        if ((Gui_GetScreenStack()->alt && e->key == 0x2A) || e->key == 0x4C ||
            (!Gui_GetScreenStack()->alt && e->key == 8) || e->key == 0x804C) {
            GuiTextEditWidget_Delete(self, e->key == 0x4C || e->key == 0x804C);
            return 1;
        }
        if ((Gui_GetScreenStack()->alt && e->key == 0x28) || (!Gui_GetScreenStack()->alt && e->key == 0xA)) {
            self->target->Activate();
            return 1;
        }
        if (e->ch) {
            if (self->maxLen == -1 || self->str.Size() < self->maxLen) {
                char buf[2];
                buf[0] = e->ch;
                buf[1] = 0;
                GuiTextEditWidget_Insert(self, buf);
                return 1;
            }
        }
    }
    if (Is4(e, 1, 0, 0x40, 0)) {
        self->target->Activate();
        return 1;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041AA80 */

/* merge_units: begin func_0041ACE0 */
#pragma push /* merge_units */
#include "loose04_types.h"

extern int func_0041C560(Unk41ADC0* self, char** cursor);

/* Read the widget's trailing word and flag after its base fields. */
int GuiTextEditWidget_Load(Unk41ADC0* self, char** cursor)
{
    unsigned short enabled;
    if (!func_0041C560(self, cursor))
        return 0;
    self->unk84 = *(int*)*cursor;
    *cursor += 4;
    enabled = *(unsigned short*)*cursor;
    *cursor += 2;
    self->unk80 = enabled != 0;
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041ACE0 */

/* merge_units: begin func_0041AD60 */
#pragma push /* merge_units */
typedef struct { unsigned char isLong : 1; unsigned char len : 7; } ShortHdr;
typedef struct { union { unsigned int word; ShortHdr s; } hdr; int longLen; char* longData; } SsoString_0041AD60;
typedef struct { char pad[0x48]; SsoString_0041AD60 text; char pad2[0x24]; void* label; char pad3[4]; unsigned char showLength; } Widget41A;

extern void GuiTextWidget_OnWake(Widget41A* self);
extern void GuiTextEditWidget_MaskText(void* label, int length);

/* Refreshes the widget and, if enabled, passes its text length to the label. */
void GuiTextEditWidget_OnWake(Widget41A* self)
{
    GuiTextWidget_OnWake(self);
    if (self->showLength)
        GuiTextEditWidget_MaskText(self->label, (self->text.hdr.word & 1) ? self->text.longLen : (unsigned char)self->text.hdr.s.len);
}
#pragma pop /* merge_units */
/* merge_units: end func_0041AD60 */

/* merge_units: begin func_0041ADC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern char D_004E0A40[];         /* Unk41ADC0 vtable */
extern Unk41ADC0* GuiTextWidget_ctor(Unk41ADC0*);

/* Constructor: runs the parent constructor, then sets flag bit 7. */
Unk41ADC0* func_0041ADC0(Unk41ADC0* self) {
    unsigned int flags;

    GuiTextWidget_ctor(self);
    self->vtable = D_004E0A40;
    flags = self->flags; /* zero-extended load keeps the match */
    self->flags = flags | 128;
    self->unk80 = 0;
    self->unk84 = 100;
    self->unk8C = 0;
    self->unk88 = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0041ADC0 */
