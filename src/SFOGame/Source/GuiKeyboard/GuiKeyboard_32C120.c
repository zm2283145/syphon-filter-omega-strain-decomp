/*
 * main/GuiKeyboard: 3 files, 0032C120-0032C290
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032C120 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { unsigned short from; unsigned short to; } E32C120;
typedef struct { char p0[4]; E32C120* data; int count; } M32C120;
typedef struct { char p0[0x98]; M32C120* map; } O32C120;
typedef struct { char p0[2]; unsigned short keys[4]; unsigned char flags; } I32C120;
extern int GuiKeyboard_GetModifierIndex(O32C120* o, I32C120* it);
extern int CharMap_Lookup(unsigned short key);
/* Maps the item's key through the object's remap table (0xFF when unmapped and strict). */
int func_0032C120(O32C120* o, I32C120* it, int strict)
{
    int k = GuiKeyboard_GetModifierIndex(o, it);
    unsigned short key = it->keys[k];
    M32C120* m = o->map;
    if (m) {
        int i;
        for (i = 0; i < m->count; i++) {
            if (key == m->data[i].from) return CharMap_Lookup(m->data[i].to);
        }
        if (strict) return 0xFF;
    }
    return CharMap_Lookup(key);
}
#pragma pop /* merge_units */
/* merge_units: end func_0032C120 */

/* merge_units: begin func_0032C1E0 */
#pragma push /* merge_units */
typedef struct { unsigned short key; char p2[10]; } E32C1E0;
typedef struct { char p0[8]; E32C1E0* data; int count; } T32C1E0;
typedef struct { char p0[0x90]; T32C1E0* tab; } O32C1E0;
typedef struct { char p0[2]; unsigned short keys[4]; unsigned char flags; } I32C1E0;
#if 0 /* merge_units */
extern int GuiKeyboard_GetModifierIndex(O32C1E0* o, I32C1E0* it);
#endif /* merge_units */
#define GuiKeyboard_GetModifierIndex(a0, a1) (GuiKeyboard_GetModifierIndex((O32C120 *)(a0), (I32C120 *)(a1))) /* merge_units */

/* Looks up the table entry for the item's key in its current mode. */
E32C1E0* func_0032C1E0(O32C1E0* o, I32C1E0* it)
{
    int k = GuiKeyboard_GetModifierIndex(o, it);
    if (it->flags & (4 << k)) {
        T32C1E0* t = o->tab;
        int i;
        for (i = 0; i < t->count; i++) {
            if (it->keys[k] == t->data[i].key) return &t->data[i];
        }
    }
    return 0;
}
#undef GuiKeyboard_GetModifierIndex /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032C1E0 */

/* merge_units: begin func_0032C290 */
#pragma push /* merge_units */
typedef struct { char pad[0xA]; unsigned char mask; } MaskObj;
#if 0 /* merge_units */
extern int GuiKeyboard_GetModifierIndex(void* self, MaskObj* obj);
#endif /* merge_units */
#define GuiKeyboard_GetModifierIndex(a0, a1) (GuiKeyboard_GetModifierIndex((O32C120 *)(a0), (I32C120 *)(a1))) /* merge_units */


/* Tests the mask bit (4 << slot) of obj, where slot comes from GuiKeyboard_GetModifierIndex. */
int func_0032C290(void* self, MaskObj* obj)
{
    int slot = GuiKeyboard_GetModifierIndex(self, obj);
    return (obj->mask & (4 << slot)) != 0;
}
#undef GuiKeyboard_GetModifierIndex /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032C290 */
