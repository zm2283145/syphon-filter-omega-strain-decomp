/*
 * main/GuiEquipmentModify: range (2 files, 002BDED0-002BDF90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002BDED0 */
#pragma push /* merge_units */
typedef struct { char pad[0x104]; int count; int cur; short ids[1]; } S2BDED0;
extern void GuiEquipmentModify_RingTouch(S2BDED0* s, short id);
void GuiEquipmentModify_PreloadWindow(S2BDED0* s, int n)
{
    int base = s->cur - (n >> 1);
    int i;
    for (i = 0; i < n; i++) {
        int k = i + base;
        if (k < 0)
            k += s->count;
        if (k > s->count)
            k -= s->count;
        if (k >= 0 && k < s->count)
            GuiEquipmentModify_RingTouch(s, s->ids[k]);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002BDED0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002BDED0 */

/* merge_units: begin func_002BDF90 */
#pragma push /* merge_units */
#pragma cplusplus on
struct W_002BDF90 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
};
extern "C" {
extern char D_004AC370[];
extern char D_004A7520[];
extern char D_004AC388[];
void* GuiWidget_FindChildByName(void* self, char* name);
void GuiTextWidget_SetText(W_002BDF90* w, char* s, int a);
}
static inline W_002BDF90* FindAs_002BDF90(void* self, char* name, char* type)
{
    W_002BDF90* w = (W_002BDF90*)GuiWidget_FindChildByName(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
static inline void Clear_002BDF90(void* self, char* name)
{
    W_002BDF90* w = FindAs_002BDF90(self, name, D_004A7520);
    if (w)
        GuiTextWidget_SetText(w, D_004AC388, 0);
}
extern "C" void GuiEquipmentModify_Clear(void* self)
{
    Clear_002BDF90(self, D_004AC370);
    Clear_002BDF90(self, "value_firerate1");
    Clear_002BDF90(self, "value_damage1");
    Clear_002BDF90(self, "value_clip_size1");
    Clear_002BDF90(self, "value_max_rounds1");
    Clear_002BDF90(self, "value_weaponname2");
    Clear_002BDF90(self, "value_firerate2");
    Clear_002BDF90(self, "value_damage2");
    Clear_002BDF90(self, "value_clip_size2");
    Clear_002BDF90(self, "value_max_rounds2");
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002BDF90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002BDF90 */
