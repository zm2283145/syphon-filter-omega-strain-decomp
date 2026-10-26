#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* GuiNetMessageArray_onElementRender: GuiNetMessages list cell draw: column 0 places the type
 * icon widget, columns 1/3 draw the message text / localised type name in
 * the type colour. The helpers are the inlined GuiNetMessageArray_GetMessageDescription (type name),
 * GuiNetMessageArray_GetMessageIcon (icon widget) and GuiNetMessageArray_GetMessageColor (colour) of
 * GuiNetMessages_3488E0.c. */
#pragma opt_rebuildconditionals off

typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;
struct Icon { VPAD8(a) VPAD2(b) virtual void Show(); };
struct IconW { char pad0[0x3C]; float w; float h; Icon* icon; };
struct Text { int x, y, w, h; unsigned char f10; char pad11[0x58 - 0x11]; unsigned char f58; char pad59[2]; unsigned char f5B; };
struct Msg { int type; char pad4[8]; char text[1]; };
struct Arr { int pad0; unsigned int count; };
struct Self { char pad0[0x94]; IconW* iconDef; IconW* iconSys; IconW* iconChat; Text* text; Arr* msgs; char name[0xC]; };

extern "C" {
extern char g_Video[];
extern int D_00538C64;
extern char D_00538C68;
extern char D_004BA3B8[];
extern char D_004BA338[];
extern char D_00587BF0[];
extern char D_00587C00[];
extern char D_00587C10[];
int sprintf(void*, const void*, ...);
char* Loc_LookupText(char* key);
void GuiArrayWidget_DrawCell(Self* self, int col, unsigned int row, float* r);
Msg* LobbyArray_At(Arr* a, unsigned int i);
void GuiWidget_SetPos(IconW* w, float x, float y);
void TextObj_SetColour(Text* c, void* p);
char* String_CStr(void* s);
void TextObj_SetText(Text* c, char* text);
void TextObj_Draw(Text* c);
void GuiNetMessageArray_onElementRender(Self* self, int col, unsigned int row, float* r);
}

static inline Mtx* MtxAt(int i) { return &((Render*)g_Video)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

static inline void SetPos(Text* c, int x, int y) { c->x = x; c->y = y; }
static inline void SetSize(Text* c, int w, int h) { c->w = w; c->h = h; }
static inline void SetF58(Text* c, unsigned char v) { c->f58 = v; }
static inline void SetF10(Text* c, unsigned char v) { c->f10 = v; }
static inline void SetF5B(Text* c, unsigned char v) { c->f5B = v; }
static inline char* TypeName(Self* self, int n)
{
    char buf[16];
    char* t;
    if (n < 0 || (unsigned int)n >= 12) return 0;
    sprintf(buf, D_004BA3B8, n);
    t = Loc_LookupText(buf);
    if (!t) return D_004BA338;
    return t;
}
static inline IconW* TypeIcon(Self* o, int k)
{
    switch (k) {
    case 9:
        return o->iconSys;
    case 0:
    case 1:
        return o->iconChat;
    default:
        return o->iconDef;
    }
}
static inline char* TypeColour(Self* self, int k)
{
    switch (k) {
    case 9:
        return D_00587BF0;
    case 0:
    case 1:
        return D_00587C10;
    default:
        return D_00587C00;
    }
}

extern "C" void GuiNetMessageArray_onElementRender(Self* self, int col, unsigned int row, float* r)
{
    Msg* m;
    GuiArrayWidget_DrawCell(self, col, row, r);
    if (!self->text || !self->msgs || row >= self->msgs->count || col == 2)
        return;
    m = LobbyArray_At(self->msgs, row);
    if (!m)
        return;
    if (col == 0) {
        IconW* w = TypeIcon(self, m->type);
        if (w) {
            GuiWidget_SetPos(w, r[0] + (r[2] / 2.0f - w->w / 2.0f), r[1] - (r[3] / 2.0f - w->h / 2.0f));
            w->icon->Show();
        }
        return;
    }
    { int i = D_00538C64; GQR(MtxAt(i + 1), MtxAt(i)); }
    D_00538C64++;
    UM(MtxAt(D_00538C64));
    D_00538C68 = 1;
    SetPos(self->text, (int)r[0], (int)r[1]);
    SetSize(self->text, (int)r[2], (int)r[3]);
    SetF58(self->text, 1);
    if (col == 1) {
        if (m->type == 10)
            TextObj_SetText(self->text, String_CStr(self->name));
        else
            TextObj_SetText(self->text, m->text);
        SetF10(self->text, 2);
        SetF5B(self->text, 1);
    } else if (col == 3) {
        TextObj_SetText(self->text, TypeName(self, m->type));
        SetF10(self->text, 0);
        SetF5B(self->text, 0);
    }
    TextObj_SetColour(self->text, TypeColour(self, m->type));
    TextObj_Draw(self->text);
    D_00538C64--;
    D_00538C68 = 1;
}
