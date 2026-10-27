#pragma cplusplus on
#include "types.h"

typedef struct { unsigned short from; unsigned short to; } Remap;
typedef struct { unsigned short key; char p2[2]; Remap* data; int count; } Entry;
typedef struct { char p0[2]; unsigned short keys[4]; unsigned char flags; char pB; } Item;
typedef struct { Item* items; } Table;
typedef struct Wid Wid;
struct Col { float r, g, b, a; Col(float a0, float a1, float a2, float a3) { r = a0; g = a1; b = a2; a = a3; } };
typedef struct {
    char p0[0x64];
    int nKeys;              /* +0x64 */
    Wid** keys;             /* +0x68 */
    char p6C[0x78 - 0x6C];
    int* codes;             /* +0x78 */
    char p7C[0x88 - 0x7C];
    int* index;             /* +0x88 */
    char p8C[4];
    Table* tab;             /* +0x90 */
    char p94[4];
    Entry* curEntry;        /* +0x98 */
    unsigned char caps;     /* +0x9C */
    char p9D[0xE4 - 0x9D];
    unsigned int flags;     /* +0xE4 */
} Self;

extern "C" {
int GuiKeyboard_GetModifierIndex(Self* self, Item* it);
int CharMap_Lookup(unsigned short key);
void GuiTextWidget_SetText(Wid* w, char* text, int flags);
/* the out pointer is declared int: passed as (int)&e retail keeps &e in a saved register */
int GuiWidget_SendMessage(void* a, void* b, int kind, int v, int f);
void cInterfaceElement_SetFilterColor(void* e, const Col& c);
void GuiKeyboard_Relabel(Self* self, unsigned int flags);
}

static inline unsigned char KeyCh(Self* o, Item* it)
{
    int k = GuiKeyboard_GetModifierIndex(o, it);
    unsigned short key = it->keys[k];
    Entry* m = o->curEntry;
    if (m) {
        int i;
        for (i = 0; i < m->count; i++) {
            if (key == m->data[i].from) return CharMap_Lookup(m->data[i].to);
        }
    }
    return CharMap_Lookup(key);
}

/* Relabels every key for the current modifier/remap state and tints it (grey: no
 * character, green: dead-key entry, grey/white otherwise; caps key lit when caps is on). */
extern "C" void GuiKeyboard_Relabel(Self* self, unsigned int flags)
{
    int i;
    self->flags = flags;
    for (i = 0; i < self->nKeys; i++) {
        if (*(int*)((char*)self->index + i * sizeof(int)) != -1) {
            Item* it = &self->tab->items[*(int*)((char*)self->index + i * sizeof(int))];
            unsigned char ch = KeyCh(self, it);
            char buf[2];
            void* e;
            buf[0] = ch == 0xFF ? 0 : ch;
            buf[1] = 0;
            GuiTextWidget_SetText(*(Wid**)((char*)self->keys + i * sizeof(Wid*)), buf, 0);
            e = 0;
            if (GuiWidget_SendMessage(self, *(Wid**)((char*)self->keys + i * sizeof(Wid*)), 5, (int)&e, 0) && e) {
                if (ch == 0xFF) {
                    cInterfaceElement_SetFilterColor(e, Col(0.75f, 0.75f, 0.75f, 1.0f));
                } else {
                    bool dead = false;
                    if (self->curEntry) {
                        int k = GuiKeyboard_GetModifierIndex(self, it);
                        Entry* m = self->curEntry;
                        int j;
                        dead = true;
                        for (j = 0; j < m->count; j++) {
                            if (it->keys[k] == m->data[j].from) {
                                dead = false;
                                break;
                            }
                        }
                    }
                    int k = GuiKeyboard_GetModifierIndex(self, it);
                    if (it->flags & (4 << k)) {
                        cInterfaceElement_SetFilterColor(e, dead ? Col(0.0f, 0.75f, 0.0f, 1.0f) : Col(0.0f, 1.0f, 0.0f, 1.0f));
                    } else {
                        cInterfaceElement_SetFilterColor(e, dead ? Col(0.5f, 0.5f, 0.5f, 1.0f) : Col(1.0f, 1.0f, 1.0f, 1.0f));
                    }
                }
            }
        }
        if (*(int*)((char*)self->codes + i * sizeof(int)) == 1004) {
            void* e = 0;
            if (GuiWidget_SendMessage(self, *(Wid**)((char*)self->keys + i * sizeof(Wid*)), 5, (int)&e, 0) && e) {
                if (self->caps) cInterfaceElement_SetFilterColor(e, Col(1.0f, 1.0f, 1.0f, 1.0f));
                else cInterfaceElement_SetFilterColor(e, Col(0.75f, 0.75f, 0.75f, 1.0f));
            }
        }
    }
}
