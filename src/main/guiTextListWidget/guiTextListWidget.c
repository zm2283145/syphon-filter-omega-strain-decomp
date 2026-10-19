/*
 * main/guiTextListWidget: 4 files, 00420E20-00421070
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00420E20 */
#pragma push /* merge_units */
#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiTextListWidget". */
int GuiTextListWidget_IsType(void)
{
    return strcmp("GuiTextListWidget") == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00420E20 */

/* merge_units: begin func_00420E50 */
#pragma push /* merge_units */
#include "guiTextListWidget_types.h"

extern void TextObj_SetColour(TextRenderChild* child, const TextRenderStyle* style);
extern const char* String_CStr(const void* string);
extern void TextObj_SetText(TextRenderChild* child, const char* text);
extern void TextObj_Draw(TextRenderChild* child);
extern void GuiArrayWidget_DrawCell(TextRenderWidget* self, void* context, unsigned int index,
                          const TextRenderRect* rect);

static inline TextListEntry* entry_at(TextRenderWidget* self, unsigned int index)
{
    return &self->entries.data[index];
}

static inline void set_position(TextRenderChild* child, float x, float y)
{
    int top = (int)y;
    int left = (int)x;
    child->x = left;
    child->y = top;
}

static inline void set_size(TextRenderChild* child, float width, float height)
{
    int rows = (int)height;
    int columns = (int)width;
    child->width = columns;
    child->height = rows;
}

/* Render an existing text row with its selected or per-entry style, then its base. */
void GuiTextListWidget_DrawCell(TextRenderWidget* self, void* context, unsigned int index,
                   const TextRenderRect* rect)
{
    if (self->child && index < (unsigned int)self->entries.count) {
        if (index == self->selected && self->highlighted)
            TextObj_SetColour(self->child, &self->highlight);
        else
            TextObj_SetColour(self->child,
                         &self->styles[(unsigned char)entry_at(self, index)->unk10]);
        set_position(self->child, rect->x, rect->y);
        set_size(self->child, rect->width, rect->height);
        TextObj_SetText(self->child, String_CStr(entry_at(self, index)));
        TextObj_Draw(self->child);
    }
    GuiArrayWidget_DrawCell(self, context, index, rect);
}
#pragma pop /* merge_units */
/* merge_units: end func_00420E50 */

/* merge_units: begin func_00420F90 */
#pragma push /* merge_units */
typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;
extern char g_Video[];
extern int D_00538C64;
extern char D_00538C68;
void GuiArrayWidget_Draw(void* self);
static inline Mtx* MtxAt(int i) { return &((Render*)g_Video)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

void GuiTextListWidget_Draw(void* self)
{
    { int i = D_00538C64; GQR(MtxAt(i + 1), MtxAt(i)); }
    D_00538C64++;
    UM(MtxAt(D_00538C64));
    D_00538C68 = 1;
    GuiArrayWidget_Draw(self);
    D_00538C64--;
    D_00538C68 = 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00420F90 */

/* merge_units: begin func_00421070 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Widget: only the slots used here are named (vtable offset in comments). */
struct Widget {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int flag, int value); /* +0x5C */
    char pad04[0x90 - 4];
    int sub90; /* +0x90 */
    int unk94; /* +0x94 */
};

extern "C" void func_00421F90(int* sub);
extern "C" void GuiArrayWidget_Select(Widget* self, int a, int b);

/* Resets the +0x90 sub-object, calls virtual +0x5C(1, +0x94), then GuiArrayWidget_Select(self, 0, 0). */
extern "C" void GuiTextListWidget_Clear(Widget* self)
{
    func_00421F90(&self->sub90);
    self->Method5C(1, self->unk94);
    GuiArrayWidget_Select(self, 0, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00421070 */
