/*
 * main/GenInfoObject: 4 files, 0043D730-0043D8B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043D730 */
#pragma push /* merge_units */
#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiMLTextWidget". */
int func_0043D730(void* self, const char* name)
{
    return strcmp("GuiMLTextWidget", name) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043D730 */

/* merge_units: begin func_0043D760 */
#pragma push /* merge_units */
typedef struct { char p[0x64]; int page; int pos; int f6C; int total; char p74[8]; void* sb; } L43D760;
extern void GuiScrollBarWidget_SetRange(void* sb, unsigned char b, int v, int lo, int hi);
void GuiMultiLineText_ScrollDown(L43D760* l, int big)
{
    int step = l->page;
    if (l->pos < l->total - step) {
        step = big ? step : 1;
        l->pos += step;
        if (!(l->pos < l->total - l->page)) {
            l->pos = l->total - l->page;
            if (l->pos < 0) l->pos = 0;
        }
        if (l->sb) GuiScrollBarWidget_SetRange(l->sb, 0, l->pos, 0, l->total - l->page);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0043D760 */

/* merge_units: begin func_0043D820 */
#pragma push /* merge_units */
typedef struct { char p[0x64]; int page; int pos; int f6C; int total; char p74[8]; void* sb; } L43D820;
void GuiMultiLineText_ScrollUp(L43D820* l, int big)
{
    if (l->pos) {
        int step;
        if (big) step = l->page; else step = 1;
        l->pos -= step;
        if (l->pos < 0) l->pos = 0;
        if (l->sb) GuiScrollBarWidget_SetRange(l->sb, 0, l->pos, 0, l->total - l->page);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0043D820 */

/* merge_units: begin func_0043D8B0 */
#pragma push /* merge_units */
#pragma opt_rebuildconditionals off
#pragma cplusplus on

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4(const V4& s) { __int128* pd = (__int128*)this; const __int128* ps = (const __int128*)&s; *pd = *ps; }
} __attribute__((aligned(16)));
typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;
struct Font { char pad[0x10]; float r, g, b, a; void SetColor(const V4& col) { V4 c = col; r = c.x; g = c.y; b = c.z; a = c.w; } };
struct Box { int x, y; void SetPos(int px, int py) { x = px; y = py; } };
struct Line { Line* prev; Line* next; char* text; };
struct LineList { int count; Line* last; Line* first; };
struct LineIter { Line* node; };
struct Self {
    char pad0[0x34];
    float x;
    float y;
    char pad3C[0x48 - 0x3C];
    Box* textBox;
    Font* font;
    V4 color;
    int maxLines;
    int visibleLines;
    int scrollPos;
    int colorIndex;
    LineList lines;
};

extern "C" {
extern char g_Video[];
extern int D_00538C64;
extern char D_00538C68;
void GuiWidget_Draw(Self* self);
int Font_GetLineHeight(Font* f);
LineIter List_Begin(LineList*);
LineIter func_0043DB60(LineList*);
void func_0043DB70(LineIter*, const LineIter&);
void func_0043DB50(LineIter*, const LineIter&);
void TextObj_SetText(Box* b, char* text);
void TextObj_Draw(Box* b);
}

static inline Mtx* MtxAt(int i) { return &((Render*)g_Video)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline V4 GetColor(Font* f) { return V4(f->r, f->g, f->b, f->a); }
static inline void SetColor(Font* f, V4 c) { f->r = c.x; f->g = c.y; f->b = c.z; f->a = c.w; }

extern "C" void GuiMultiLineText_Draw(Self* self)
{
    GuiWidget_Draw(self);
    if (self->textBox == 0 || self->font == 0) return;
    { int i = D_00538C64; GQR(MtxAt(i + 1), MtxAt(i)); }
    D_00538C64++;
    UM(MtxAt(D_00538C64));
    D_00538C68 = 1;
    {
        LineIter n;
        LineIter end;
        LineIter it;
        int lineH = Font_GetLineHeight(self->font);
        int y = (int)self->y;
        int i = 0;
        int cnt = 1;
        V4 saved;
        {
            Font* f = self->font;
            saved.x = f->r;
            saved.y = f->g;
            saved.z = f->b;
            saved.w = f->a;
        }
        self->font->SetColor(self->color);
        func_0043DB70(&it, List_Begin(&self->lines));
        for (n = it; func_0043DB50(&end, func_0043DB60(&self->lines)), n.node != end.node; n.node = n.node->next) {
            if (i++ < self->scrollPos) continue;
            self->textBox->SetPos((int)self->x, y);
            TextObj_SetText(self->textBox, n.node->text);
            TextObj_Draw(self->textBox);
            y -= lineH;
            if (!(cnt++ < self->visibleLines)) break;
        }
        self->font->SetColor(saved);
    }
    D_00538C68 = 1;
    D_00538C64--;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043D8B0 */
