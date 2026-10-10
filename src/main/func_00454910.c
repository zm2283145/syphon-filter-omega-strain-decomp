/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of Obj: only the slots used here are named (vtable offset in comments). */
struct Obj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual int IsA(const char* type); /* +0x58 */
    char pad04[0x14 - 4];
    unsigned short flags; /* +0x14 */
};

typedef struct Color { float r, g, b, a; } __attribute__((aligned(16))) Color;

typedef struct Panel {
    char pad[0x81];
    unsigned char visible; /* +0x81 */
    char pad82[0x88 - 0x82];
    Obj* label;  /* +0x88 */
    Obj* icon;   /* +0x8C */
    char pad90[0xC0 - 0x90];
    Color color; /* +0xC0 */
} Panel;

typedef struct Screen {
    char pad[0x48];
    Panel* panel; /* +0x48 */
    Obj* list;    /* +0x4C */
} Screen;

extern char D_004C19F8[];
extern char D_004C19B0[];
extern char D_004C1A10[];
extern char D_004C1A28[];
extern char D_004AA640[];
extern char D_004AAE00[];
extern char D_004C1D10[];
extern Color D_00587D40;
extern "C" void func_0041F150(Screen* self);
extern "C" Obj* func_0041DB80(Screen* self, const char* name);

static inline Obj* AsPanel(Obj* obj)
{
    if (obj == 0 || !obj->IsA(D_004AA640))
        obj = 0;
    return obj;
}

static inline Obj* AsIcon(Obj* obj)
{
    if (obj == 0 || !obj->IsA(D_004AAE00))
        obj = 0;
    return obj;
}

static inline Obj* AsList(Obj* obj)
{
    if (obj == 0 || !obj->IsA(D_004C1D10))
        obj = 0;
    return obj;
}

static inline void SetColor(Panel* panel, Color color)
{
    panel->color = color;
}

/* Screen init: binds the panel (with its icon, label and default colour) and the list child widgets. */
extern "C" void func_00454910(Screen* self)
{
    func_0041F150(self);
    self->panel = (Panel*)AsPanel(func_0041DB80(self, D_004C19F8));
    if (self->panel) {
        Obj* widget;
        self->panel->visible = 1;
        SetColor(self->panel, D_00587D40);
        self->panel->icon = AsIcon(func_0041DB80(self, D_004C19B0));
        widget = func_0041DB80(self, D_004C1A10);
        self->panel->label = widget;
        if (widget)
            widget->flags &= ~0x80;
    }
    self->list = AsList(func_0041DB80(self, D_004C1A28));
}
