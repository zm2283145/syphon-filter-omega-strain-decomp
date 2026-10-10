#include "types.h"

typedef struct { char pad[0x14]; unsigned short flags; } Widget;
typedef struct {
    char pad[0x8C];
    Widget* widgets[4];
    void* items[4];
    Widget* cursor;
    char pad3[4];
    int index;
} Menu299;
extern void* func_004147A0(void);
extern void func_00414B30(void* ctx, void* item);
extern void func_0041E0F0(void* item, void* ctx, int a, int b, int c);

/* Activates the current menu item: un-hides its widget, focuses it; then shows the cursor. */
void func_00299800(Menu299* m)
{
    if (m->items[m->index]) {
        m->widgets[m->index]->flags &= ~4;
        func_00414B30(func_004147A0(), m->items[m->index]);
        func_0041E0F0(m->items[m->index], func_004147A0(), 0x10, 0, 0);
    }
    if (m->cursor)
        m->cursor->flags |= 4;
}
