/*
 * main/GuiKeyboard: 4 files, 0032C2D0-0032C9A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032C2D0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char p0[0xE4]; unsigned int flags; } O32C2D0;
typedef struct { char p0[0xA]; unsigned char flags; } I32C2D0;
/* Picks which of the item's key slots (0-3) applies for the object's current mode bits. */
int GuiKeyboard_GetModifierIndex(O32C2D0* o, I32C2D0* it)
{
    unsigned int f = o->flags;
    int r;
    if (f & 4) {
        r = 2;
        if (f & 2) {
            if (it->flags & 2) r = 3;
            if (f & 1) r = (r == 3) ? 2 : 3;
        } else {
            if (f & 1) r = 3;
        }
    } else {
        r = 0;
        if (f & 2) {
            if (it->flags & 1) r = 1;
            if (f & 1) r = (r ^ 1) != 0;
        } else {
            if (f & 1) r = 1;
        }
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032C2D0 */

/* merge_units: begin func_0032C390 */
#pragma push /* merge_units */
typedef struct { unsigned char lng : 1; unsigned char len : 7; } SS_C390;
typedef struct { union { SS_C390 s; unsigned int w; } h; int size; } Str_C390;
typedef struct { char p0[0x48]; Str_C390 name; char p50[0x3C]; int sel; } Menu_C390;
typedef struct { unsigned short from; unsigned short to; } Remap_C390;
typedef struct { unsigned short key; char p2[2]; Remap_C390* data; int count; } Entry_C390;
typedef struct { char p0[2]; unsigned short keys[4]; unsigned char flags; char pB; } Item_C390;
typedef struct { Item_C390* items; int p4; Entry_C390* data; int count; } Table_C390;
typedef struct {
    char p0[0x4C];
    Menu_C390* menu;
    int max;
    char p54[0x24];
    int* types;
    char p7C[0xC];
    int* index;
    char p8C[4];
    Table_C390* tab;
    char p94[4];
    Entry_C390* cur;
    unsigned char b9C;
    char p9D[0x44];
    unsigned char bE1;
    char pE2[2];
    unsigned int flags;
} Self_C390;
typedef struct { char p0[0x10]; int id; } Arg_C390;

extern void GuiKeyboard_Close(Self_C390* self, int v);
extern void GuiKeyboard_Relabel(Self_C390* self, unsigned int flags);
#if 0 /* merge_units */
extern int GuiKeyboard_GetModifierIndex(Self_C390* self, Item_C390* it);
#endif /* merge_units */
#define GuiKeyboard_GetModifierIndex(a0, a1) (GuiKeyboard_GetModifierIndex((O32C2D0 *)(a0), (I32C2D0 *)(a1))) /* merge_units */

extern int GuiKeyboard_IsCharAllowed(Self_C390* self, unsigned char c);
extern int CharMap_Lookup(unsigned short key);
extern void GuiTextEditWidget_ClampCursor(Menu_C390* m, int sel);
extern void GuiTextEditWidget_Delete(Menu_C390* m, int sel);
extern void GuiTextEditWidget_Insert(Menu_C390* m, char* s);
extern void GuiWidget_SendEventUp(Self_C390* self, int a, int b, int c);
extern int GuiWidget_OnEvent(Self_C390* self, Arg_C390* arg, unsigned short msg, int a3, int param);

static inline int StrSize(Str_C390* s) { return (s->h.w & 1) ? s->size : (unsigned char)s->h.s.len; }

static inline Entry_C390* Lookup(Self_C390* o, Item_C390* it)
{
    int k = GuiKeyboard_GetModifierIndex(o, it);
    if (it->flags & (4 << k)) {
        Table_C390* t = o->tab;
        int i;
        for (i = 0; i < t->count; i++) {
            if (it->keys[k] == t->data[i].key) return &t->data[i];
        }
    }
    return 0;
}

static inline unsigned char Remap(Self_C390* o, Item_C390* it)
{
    int k = GuiKeyboard_GetModifierIndex(o, it);
    unsigned short key = it->keys[k];
    Entry_C390* m = o->cur;
    if (m) {
        int i;
        for (i = 0; i < m->count; i++) {
            if (key == m->data[i].from) return CharMap_Lookup(m->data[i].to);
        }
        return 0xFF;
    }
    return CharMap_Lookup(key);
}

int GuiKeyboard_HandleEvent(Self_C390* self, Arg_C390* arg, unsigned short msg, int a3, int param)
{
    if (msg == 0x2000) {
        GuiKeyboard_Close(self, 0);
        return 1;
    }
    if (msg == 2) {
        int id = arg->id;
        unsigned char ok;
        Entry_C390* prev = self->cur;
        if (id != -1) {
            unsigned char ch = 0xFF;
            unsigned char found;
            int type;
            ok = 1;
            found = 0;
            type = self->types[id];
            switch (type) {
            case 0x3EC:
            case 0x428:
                if (self->b9C) {
                    GuiKeyboard_Relabel(self, (self->flags & 4) ? self->flags & ~4 : self->flags | 4);
                } else {
                    ok = 0;
                }
                break;
            case 0x39:
                GuiKeyboard_Relabel(self, (self->flags & 2) ? self->flags & ~2 : self->flags | 2);
                break;
            case 0x3EA:
            case 0x408:
                if (self->flags & 1) {
                    GuiKeyboard_Relabel(self, self->flags & ~1);
                    self->bE1 = 0;
                } else {
                    GuiKeyboard_Relabel(self, self->flags | 1);
                    self->bE1 = 1;
                }
                break;
            case 0x2A:
                if (self->menu) GuiTextEditWidget_Delete(self->menu, 0);
                self->cur = 0;
                break;
            case 0x28:
                GuiKeyboard_Close(self, 1);
                break;
            case 0x4F:
                GuiTextEditWidget_ClampCursor(self->menu, self->menu->sel + 1);
                self->cur = 0;
                break;
            case 0x50:
                if (self->menu->sel != 0) GuiTextEditWidget_ClampCursor(self->menu, self->menu->sel - 1);
                self->cur = 0;
                break;
            default:
                ok = 0;
                found = 1;
                {
                    int idx = self->index[id];
                    if (idx != -1) {
                        Item_C390* it = &self->tab->items[idx];
                        int slot = GuiKeyboard_GetModifierIndex(self, it);
                        if (it->flags & (4 << slot)) {
                            self->cur = Lookup(self, it);
                        } else {
                            ch = Remap(self, it);
                            self->cur = 0;
                        }
                    }
                }
                break;
            }
            if (prev != self->cur) GuiKeyboard_Relabel(self, self->flags);
            if (self->menu && found && ch != 0xFF) {
                if ((unsigned char)GuiKeyboard_IsCharAllowed(self, ch) && StrSize(&self->menu->name) < self->max) {
                    char buf[2];
                    buf[0] = ch;
                    buf[1] = 0;
                    GuiTextEditWidget_Insert(self->menu, buf);
                    ok = 1;
                } else {
                    ok = 0;
                }
                if (self->bE1) GuiKeyboard_Relabel(self, (self->flags & 1) ? self->flags & ~1 : self->flags | 1);
                self->bE1 = 0;
            }
            if (ok) {
                GuiWidget_SendEventUp(self, 0x10, 1, 0);
            } else {
                GuiWidget_SendEventUp(self, 0x10, 4, 0);
            }
            return 1;
        }
    }
    if (msg == 0x10 && a3 == 1) return 1;
    return GuiWidget_OnEvent(self, arg, msg, a3, param);
}
#undef GuiKeyboard_GetModifierIndex /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032C390 */

/* merge_units: begin func_0032C860 */
#pragma push /* merge_units */
typedef struct { char pad[0x94]; int mods; } Kb_32C860;
typedef struct {
    char p0[0x9C];
    unsigned char b9C;
    char p9D[0x44];
    unsigned char bE1;
    char pE2[2];
    unsigned int flags;
    unsigned int mods;
} Self_32C860;
extern unsigned char D_0055A701;
extern Kb_32C860 D_0055A700;
extern void GuiWidget_Update(Self_32C860* self);
#if 0 /* merge_units */
extern void GuiKeyboard_Relabel(Self_32C860* self, unsigned int flags);
#endif /* merge_units */
#define GuiKeyboard_Relabel(a0, a1) (GuiKeyboard_Relabel((Self_C390 *)(a0), (a1))) /* merge_units */

extern void GuiKeyboard_RefreshSpecialKeys(Self_32C860* self);

void GuiKeyboard_Update(Self_32C860* self)
{
    Kb_32C860* k;
    GuiWidget_Update(self);
    k = &D_0055A700;
    if (D_0055A701) {
        int m = k->mods;
        unsigned int f = 0;
        unsigned char changed;
        if (self->b9C && ((m & 4) || (m & 0x40))) f |= 4;
        if ((m & 2) || (m & 0x20)) f |= 1;
        changed = 0;
        if ((f & self->flags) != f) {
            if (f & 1) self->bE1 = 0;
            self->flags |= f;
            changed = 1;
        }
        if (self->mods != f) {
            if (!(f & 1) && (self->mods & 1)) {
                self->bE1 = 0;
                self->flags &= ~1;
                changed = 1;
            }
            if (!(f & 4) && (self->mods & 4)) {
                self->flags &= ~4;
                changed = 1;
            }
        }
        self->mods = f;
        if (changed) GuiKeyboard_Relabel(self, self->flags);
    }
    GuiKeyboard_RefreshSpecialKeys(self);
}
#undef GuiKeyboard_Relabel /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032C860 */

/* merge_units: begin func_0032C9A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x68]; unsigned int flags; } Mgr;
extern void GuiWidget_BaseSleep(void* self);
extern Mgr* Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(void* self, Mgr* mgr, int a, int b, int c);

/* Runs base setup, clears manager flag 0x40, then registers self with the manager. */
void GuiKeyboard_Sleep(void* self)
{
    GuiWidget_BaseSleep(self);
    Gui_GetScreenStack()->flags &= ~0x40;
    GuiWidget_SendEvent(self, Gui_GetScreenStack(), 0x10, 3, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_0032C9A0 */
