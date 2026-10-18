/* GuiKeyboard_HandleInput: on-screen keyboard pad input (cancel/accept, d-pad key focus, key press
 * -> character insert, hover widget highlight); companion of GuiKeyboard_HandleEvent. */
#pragma cplusplus on
#pragma bool off
#include "types.h"

typedef struct { unsigned char lng : 1; unsigned char len : 7; } SS_BA10;
typedef struct { union { SS_BA10 s; unsigned int w; } h; int size; } Str_BA10;
typedef struct { char p0[0x48]; Str_BA10 name; char p50[0x3C]; int sel; } Menu_BA10;
typedef struct { unsigned short from; unsigned short to; } Remap_BA10;
typedef struct { unsigned short key; char p2[2]; Remap_BA10* data; int count; } Entry_BA10;
typedef struct { char p0[2]; unsigned short keys[4]; unsigned char flags; char pB; } Item_BA10;
typedef struct { Item_BA10* items; int p4; Entry_BA10* data; int count; } Table_BA10;
typedef struct Wid_BA10 Wid_BA10;
typedef struct { char p0[0x20]; Wid_BA10* hover; char p24[0x44]; unsigned int flags; } Scr_BA10;
typedef struct {
    char p0[0x20];
    Wid_BA10* hover;        /* +0x20 */
    char p24[0x4C - 0x24];
    Menu_BA10* menu;        /* +0x4C */
    int max;                /* +0x50 */
    char p54[0x5C - 0x54];
    int cur;                /* +0x5C */
    char p60[0x68 - 0x60];
    Wid_BA10** keys;        /* +0x68 */
    char p6C[0x74 - 0x6C];
    int ncodes;             /* +0x74 */
    int* codes;             /* +0x78 */
    char p7C[0x88 - 0x7C];
    int* index;             /* +0x88 */
    char p8C[4];
    Table_BA10* tab;        /* +0x90 */
    char p94[4];
    Entry_BA10* curEntry;   /* +0x98 */
    char p9C[0xA8 - 0x9C];
    int* navUp;             /* +0xA8 */
    char pAC[0xB8 - 0xAC];
    int* navDown;           /* +0xB8 */
    char pBC[0xC8 - 0xBC];
    int* navRight;          /* +0xC8 */
    char pCC[0xD8 - 0xCC];
    int* navLeft;           /* +0xD8 */
    char pDC[0xE4 - 0xDC];
    unsigned int flags;     /* +0xE4 */
} Self_BA10;
typedef struct { unsigned short type; unsigned short b2; unsigned short b4; unsigned short b6; unsigned short btn; } Ev_BA10;
struct VO_BA10 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void Enter(); virtual void Leave(); };

extern "C" {
extern void GuiKeyboard_Close(Self_BA10* self, int v);
extern void GuiKeyboard_Relabel(Self_BA10* self, unsigned int flags);
extern int GuiKeyboard_GetModifierIndex(Self_BA10* self, Item_BA10* it);
extern int GuiKeyboard_IsCharAllowed(Self_BA10* self, unsigned char c);
extern int GuiKeyboard_IsSpecialKey(Self_BA10* self, Wid_BA10* w);
extern int CharMap_Lookup(unsigned short key);
extern void GuiTextEditWidget_ClampCursor(Menu_BA10* m, int sel);
extern void GuiTextEditWidget_Delete(Menu_BA10* m, int sel);
extern void GuiTextEditWidget_Insert(Menu_BA10* m, char* s);
extern Scr_BA10* Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(void* a, void* b, int kind, int v, int f);
extern VO_BA10* func_0032C110(Wid_BA10* w);
int GuiKeyboard_HandleInput(Self_BA10* self, Ev_BA10* ev);
}

static inline int StrSize_BA10(Str_BA10* s) { return (s->h.w & 1) ? s->size : (unsigned char)s->h.s.len; }

static inline Entry_BA10* Lookup_BA10(Self_BA10* o, Item_BA10* it)
{
    int k = GuiKeyboard_GetModifierIndex(o, it);
    if (it->flags & (4 << k)) {
        Table_BA10* t = o->tab;
        int i;
        for (i = 0; i < t->count; i++) {
            if (it->keys[k] == t->data[i].key) return &t->data[i];
        }
    }
    return 0;
}

static inline unsigned char RemapCh_BA10(Self_BA10* o, Item_BA10* it)
{
    int k = GuiKeyboard_GetModifierIndex(o, it);
    unsigned short key = it->keys[k];
    Entry_BA10* m = o->curEntry;
    if (m) {
        int i;
        for (i = 0; i < m->count; i++) {
            if (key == m->data[i].from) return CharMap_Lookup(m->data[i].to);
        }
        return 0xFF;
    }
    return CharMap_Lookup(key);
}

static inline unsigned char Down_BA10(Ev_BA10* e) { unsigned char r = 0; if (e->type == 1 && !e->b2) r = 1; return r; }
static inline unsigned char Btn_BA10(Ev_BA10* e, int b) { unsigned char r = 0; if (Down_BA10(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_BA10(Ev_BA10* e, int b) { unsigned char r = 0; if (Btn_BA10(e, b) && e->b6 == 0) r = 1; return r; }


extern "C" int GuiKeyboard_HandleInput(Self_BA10* self, Ev_BA10* ev)
{
    Wid_BA10* w;
    int sel;
    int r;
    if (Plain_BA10(ev, 0x10)) {
        GuiKeyboard_Close(self, 0);
        return 1;
    }
    r = ev->type == 1 && ev->b2 == 0 && ev->btn == 0x80 && ev->b6 == 0;
    if (r) {
        GuiKeyboard_Close(self, 1);
        return 1;
    }
    sel = -1;
    switch (ev->btn) {
    case 0x8000: sel = self->navRight[self->cur]; break;
    case 0x2000: sel = self->navLeft[self->cur]; break;
    case 0x1000: sel = self->navUp[self->cur]; break;
    case 0x4000: sel = self->navDown[self->cur]; break;
    }
    w = 0;
    if (sel != -1) {
        if (ev->b6 == 0) {
            Wid_BA10** pw;
            self->cur = sel;
            pw = &self->keys[self->cur];
            w = *pw;
            GuiWidget_SendEvent(*pw, Gui_GetScreenStack(), 0x10, 6, 0);
            Gui_GetScreenStack()->flags &= ~0x40;
        } else if (ev->b6 == 1) {
            Gui_GetScreenStack()->flags |= 0x40;
        }
    }
    if (w) {
        int hi = ev->b4 == 1;
        Scr_BA10* st = Gui_GetScreenStack();
        if (hi)
            st->flags |= 0x40;
        else
            st->flags &= ~0x40;
    }
    r = ev->type == 2 && ev->b2 == 0 && ev->b6 == 0;
    if (r) {
        Menu_BA10* m = self->menu;
        Entry_BA10* prev;
        int key;
        if (!m) return 1;
        prev = self->curEntry;
        key = ev->btn;
        switch (key) {
        case 0x28:
            GuiKeyboard_Close(self, 1);
            break;
        case 0x29:
            GuiKeyboard_Close(self, 0);
            break;
        case 0x39:
            GuiKeyboard_Relabel(self, (self->flags & 2) ? self->flags & ~2 : self->flags | 2);
            break;
        case 0x4F:
            GuiTextEditWidget_ClampCursor(m, m->sel + 1);
            self->curEntry = 0;
            break;
        case 0x50:
            if (m->sel != 0) GuiTextEditWidget_ClampCursor(m, m->sel - 1);
            self->curEntry = 0;
            break;
        case 0x2A:
            if (m) GuiTextEditWidget_Delete(m, 0);
            self->curEntry = 0;
            break;
        case 0x4C:
            if (m) GuiTextEditWidget_Delete(m, 1);
            self->curEntry = 0;
            break;
        default: {
            unsigned char ok = 0;
            if (StrSize_BA10(&self->menu->name) < self->max) {
                int n;
                /* volatile read: retail reloads the code count on every pass */
                for (n = 0; n < *(volatile int*)&self->ncodes; n++) {
                    if (key == *(int*)((char*)self->codes + n * sizeof(int))) {
                        int idx = *(int*)((char*)self->index + n * sizeof(int));
                        if (idx != -1) {
                            Item_BA10* it = &self->tab->items[idx];
                            unsigned char ch = 0xFF;
                            int slot = GuiKeyboard_GetModifierIndex(self, it);
                            if (it->flags & (4 << slot)) {
                                self->curEntry = Lookup_BA10(self, it);
                            } else {
                                ch = RemapCh_BA10(self, it);
                                self->curEntry = 0;
                            }
                            if (ch != 0xFF && (unsigned char)GuiKeyboard_IsCharAllowed(self, ch)) {
                                char buf[2];
                                buf[0] = ch;
                                buf[1] = 0;
                                GuiTextEditWidget_Insert(self->menu, buf);
                                ok = 1;
                            }
                        }
                        break;
                    }
                }
            }
            if (!ok)
                GuiWidget_SendEvent(self, Gui_GetScreenStack(), 0x10, 4, 0);
            break;
        }
        }
        if (prev != self->curEntry)
            GuiKeyboard_Relabel(self, self->flags);
        return 1;
    }
    if (w) {
        Scr_BA10* st = Gui_GetScreenStack();
        if (w != st->hover) {
            if (st->hover)
                func_0032C110(st->hover)->Leave();
            st->hover = w;
            if (w && !GuiKeyboard_IsSpecialKey(self, w))
                func_0032C110(w)->Enter();
        }
        self->hover = w;
        return 1;
    }
    return 0;
}
