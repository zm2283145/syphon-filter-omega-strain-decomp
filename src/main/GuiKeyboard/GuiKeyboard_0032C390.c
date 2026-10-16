#include "types.h"
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

extern void func_0032B2D0(Self_C390* self, int v);
extern void func_0032B5F0(Self_C390* self, unsigned int flags);
extern int GuiKeyboard_GetModifierIndex(Self_C390* self, Item_C390* it);
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
        func_0032B2D0(self, 0);
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
                    func_0032B5F0(self, (self->flags & 4) ? self->flags & ~4 : self->flags | 4);
                } else {
                    ok = 0;
                }
                break;
            case 0x39:
                func_0032B5F0(self, (self->flags & 2) ? self->flags & ~2 : self->flags | 2);
                break;
            case 0x3EA:
            case 0x408:
                if (self->flags & 1) {
                    func_0032B5F0(self, self->flags & ~1);
                    self->bE1 = 0;
                } else {
                    func_0032B5F0(self, self->flags | 1);
                    self->bE1 = 1;
                }
                break;
            case 0x2A:
                if (self->menu) GuiTextEditWidget_Delete(self->menu, 0);
                self->cur = 0;
                break;
            case 0x28:
                func_0032B2D0(self, 1);
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
            if (prev != self->cur) func_0032B5F0(self, self->flags);
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
                if (self->bE1) func_0032B5F0(self, (self->flags & 1) ? self->flags & ~1 : self->flags | 1);
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
