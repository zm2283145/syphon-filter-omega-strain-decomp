/*
 * main/guiTextArrayWidget: range (6 files, 00425E00-004263C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "guiTextArrayWidget_types.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00425E00 */
#pragma push /* merge_units */
/* Copy the state byte to the optional child widget. */
void GuiTextArrayWidget_SetHAlign(guiTextArrayWidget* self, unsigned char state)
{
    self->unk98 = state;
    if (self->unk90)
        self->unk90->state = state;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00425E00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00425E00 */

/* merge_units: begin func_00425E20 */
#pragma push /* merge_units */
typedef struct { char pad[0x20]; void* inst; } P425E20;
typedef struct { char pad[0x90]; P425E20* peer; void* inst; } T425E20;
extern void* Gui_GetScreenList(void);
extern void* GuiFont_Find(void* a, int b);
extern char* Font_GetLineHeight(void* i);
extern void GuiArrayWidget_RowHeight(T425E20* t, void* p);
void GuiTextArrayWidget_SetFont(T425E20* t, int a) {
    t->inst = GuiFont_Find(Gui_GetScreenList(), a);
    if (t->inst) {
        { char* p = Font_GetLineHeight(t->inst) + 4; GuiArrayWidget_RowHeight(t, p); }
        if (t->peer) t->peer->inst = t->inst;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00425E20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00425E20 */

/* merge_units: begin func_00425EA0 */
#pragma push /* merge_units */
#pragma opt_rebuildconditionals off
#pragma cplusplus on

typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;
typedef struct Child { int x, y, w, h; char f10; char pad11[0x20 - 0x11]; int f20; } Child;
typedef struct Item { char str[0xC]; int flags; char f10; char pad11[3]; int f14; char pad18[8]; char f20[0x10]; } Item;
typedef struct Self { char pad[0x90]; Child* child; int f94; char f98; char pad99[0xA0 - 0x99]; char fA0[0x10]; } Self;

extern "C" {
extern char g_Video[];
extern int D_00538C64;
extern char D_00538C68;
void GuiArrayWidget_DrawCell(Self* self, int a, int b, float* r);
Item* GuiTextArrayWidget_GetCell(Self* self, int a, int b);
void TextObj_SetColour(Child* c, void* p);
char* String_CStr(void* s);
void TextObj_SetText(Child* c, char* text);
void TextObj_Draw(Child* c);
}

static inline void SetPos(Child* c, int x, int y) { c->x = x; c->y = y; }
static inline void SetSize(Child* c, int w, int h) { c->w = w; c->h = h; }
static inline void SetF10(Child* c, char v) { c->f10 = v; }
static inline void SetF20(Child* c, int v) { c->f20 = v; }
static inline Mtx* MtxAt(int i) { return &((Render*)g_Video)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

extern "C" void GuiTextArrayWidget_DrawCell(Self* self, int a, int b, float* r)
{
    Item* it;
    GuiArrayWidget_DrawCell(self, a, b, r);
    if (self->child == 0) return;
    it = GuiTextArrayWidget_GetCell(self, a, b);
    if (it == 0) return;
    if (it->flags & 1) SetF10(self->child, it->f10);
    if (it->flags & 2) SetF20(self->child, it->f14);
    if (it->flags & 4) TextObj_SetColour(self->child, it->f20);
    { int i = D_00538C64; GQR(MtxAt(i + 1), MtxAt(i)); }
    D_00538C64++;
    UM(MtxAt(D_00538C64));
    D_00538C68 = 1;
    SetPos(self->child, (int)r[0], (int)r[1]);
    SetSize(self->child, (int)r[2], (int)r[3]);
    TextObj_SetText(self->child, String_CStr(it));
    TextObj_Draw(self->child);
    D_00538C64--;
    D_00538C68 = 1;
    if (it->flags & 1) SetF10(self->child, self->f98);
    if (it->flags & 2) SetF20(self->child, self->f94);
    if (it->flags & 4) TextObj_SetColour(self->child, self->fA0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00425EA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00425EA0 */

/* merge_units: begin func_00426100 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern char D_004BF790[];
void GuiArrayWidget_Sleep(guiTextArrayWidget* self);
void GuiArrayWidget_OnWake(guiTextArrayWidget* self);
void GuiArrayWidget_Init(guiTextArrayWidget* self);
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void String_Dtor(void* string, int flags);
TextArrayWidgetChild* TextObj_Construct(TextArrayWidgetChild* child, int x, int y,
                                  int width, int height, int resource, float* color);
void* Gui_GetScreenList(void);
#if 0 /* merge_units */
int GuiFont_Find(void* manager, const char* name);
#endif /* merge_units */
#define GuiFont_Find(a0, a1) ((int)GuiFont_Find((a0), (int)(a1))) /* merge_units */

#if 0 /* merge_units */
unsigned int Font_GetLineHeight(int resource);
#endif /* merge_units */
#define Font_GetLineHeight(a0) ((unsigned int)Font_GetLineHeight((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
void GuiArrayWidget_RowHeight(guiTextArrayWidget* self, unsigned int height);
#endif /* merge_units */
#define GuiArrayWidget_RowHeight(a0, a1) (GuiArrayWidget_RowHeight((T425E20 *)(a0), (void *)(a1))) /* merge_units */

}

static inline void destroy_string(void* string)
{
    if (string)
        String_Dtor(string, 0);
}

static inline void destroy_child(TextArrayWidgetChild* child)
{
    if (child)
        destroy_string(child->string);
}

/* Deactivate the grid base and release the optional text-rendering child. */
extern "C" void GuiTextArrayWidget_Sleep(guiTextArrayWidget* self)
{
    GuiArrayWidget_Sleep(self);
    TextArrayWidgetChild* child = self->unk90;
    if (child) {
        {
            AllocGuard guard;
            destroy_child(child);
            Mem_Free(0, child, D_004BF790, 0x7B);
        }
        self->unk90 = 0;
    }
}

/* Create a text child for the current resource and copy the array's display state. */
extern "C" void GuiTextArrayWidget_Wake(guiTextArrayWidget* self)
{
    GuiArrayWidget_OnWake(self);
    if (self->count) {
        TextArrayWidgetChild* child;
        {
            AllocGuard guard;
            child = (TextArrayWidgetChild*)Mem_Alloc(0, sizeof(TextArrayWidgetChild),
                                                    D_004BF790, 0x6C);
        }
        if (child)
            child = TextObj_Construct(child, 0, 0, 10, 10, self->count, self->color);
        self->unk90 = child;
        self->unk90->enabled = 1;
        self->unk90->state = self->unk98;
        self->unk90->active = 1;
    }
}

/* Resolve the default resource, refresh row height and update an existing child. */
extern "C" void GuiTextArrayWidget_Init(guiTextArrayWidget* self)
{
    GuiArrayWidget_Init(self);
    self->count = GuiFont_Find(Gui_GetScreenList(), "callout");
    if (self->count) {
        GuiArrayWidget_RowHeight(self, Font_GetLineHeight(self->count) + 4);
        if (self->unk90)
            self->unk90->resource = self->count;
    }
}
#undef GuiFont_Find /* merge_units */
#undef Font_GetLineHeight /* merge_units */
#undef GuiArrayWidget_RowHeight /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00426100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00426100 */

/* merge_units: begin func_00426350 */
#pragma push /* merge_units */
extern void GuiArrayWidget_SetDims(guiTextArrayWidget* self, unsigned int columns, unsigned int rows);
extern void TextArrayCell_InitDefaults(guiTextArrayWidget* self, unsigned int columns, unsigned int rows);

/* Update the base dimensions and rebuild the cells only when the shape changes. */
void GuiTextArrayWidget_SetDims(guiTextArrayWidget* self, unsigned int columns, unsigned int rows)
{
    if (columns != self->columns || rows != self->rows) {
        GuiArrayWidget_SetDims(self, columns, rows);
        TextArrayCell_InitDefaults(self, columns, rows);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00426350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00426350 */

/* merge_units: begin func_004263C0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* Inline all row-base cleanup layers while retaining their null checks. */
#pragma inline_depth(8)

extern "C" {
TextArrayRow** std_vector_cArray_tTextElementPtr_opIndex(TextArrayStore* store, int index);
void std_vector_deleter_tTextElement_dtor(TextArrayRow* row, int flags);
}

static inline void destroy_storage(TextArrayRow* row)
{
    if (row)
        std_vector_deleter_tTextElement_dtor(row, 0);
}

static inline void destroy_base(TextArrayRow* row)
{
    if (row)
        destroy_storage(row);
}

static inline void destroy_row(TextArrayRow* row)
{
    if (row)
        destroy_base(row);
}

/* Destroy owned rows in order, preserving the live count until the final reset. */
extern "C" void GuiTextArrayWidget_DestroyTextArray(guiTextArrayWidget* self)
{
    for (int index = 0; index < self->store.unk04; ++index) {
        TextArrayRow* row = *std_vector_cArray_tTextElementPtr_opIndex(&self->store, index);
        AllocGuard guard;
        destroy_row(row);
        Mem_Free(0, row, D_004BF790, 0x50);
    }
    self->store.unk04 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004263C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004263C0 */
