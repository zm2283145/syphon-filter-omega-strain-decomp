#pragma opt_rebuildconditionals off
#pragma cplusplus on
#include "types.h"
/* GuiGameScreen_DrawRoundCounts: draws the ammo count ("%d" or "%d/%d")
 * under each visible weapon slot of the in-game weapon selector, with a
 * one-pixel drop shadow and the slot's fade. Render-state helpers as in
 * GuiTextArrayWidget_DrawCell (guiTextArrayWidget_425E00.c). */
typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;
struct Col_C0F0 { float r, g, b, a; Col_C0F0() {} Col_C0F0(float a0, float a1, float a2, float a3) { r = a0; g = a1; b = a2; a = a3; } };
struct Text_C0F0 { int x, y, w, h; };
struct Slot_C0F0 { char p0[0x34]; float px, py; float w, h; };
struct Wpn_C0F0 { char p0[0xF0]; signed char kind; };
struct Human_C0F0 { char p0[0x3524]; void* weapons; };
struct Player_C0F0 { char p0[0x30]; Human_C0F0* actor; };
struct Screen_C0F0 {
    char p0[0x48]; Text_C0F0* text; char p4C[0x74 - 0x4C]; int count; int* ids; char p7C[0x90 - 0x7C];
    int first; char p94[0xA8 - 0x94]; Slot_C0F0* slots[5]; float fade[8];
    int shown;
};
extern "C" {
extern char g_Video[];
extern int D_00538C64;
extern char D_00538C68;
extern Player_C0F0* g_LocalPlayer;
extern void* g_WeaponDatabase;
extern Col_C0F0 D_00587D80;
int sprintf(void*, const void*, ...);
Wpn_C0F0* WeaponDb_Get(void* db, int id);
int WeaponInv_SlotOfItem(int id);
int WeaponInv_GetSpare(void* inv, int slot);
int WeaponInv_GetClip(void* inv, int slot);
int WeaponInv_HasAmmoText(void* inv, int id);
void TextObj_SetText(Text_C0F0* c, char* text);
void TextObj_SetColour(Text_C0F0* c, Col_C0F0* p);
void TextObj_Draw(Text_C0F0* c);
void GuiGameScreen_DrawRoundCounts(Screen_C0F0* o);
}
static inline void SetPos(Text_C0F0* c, int x, int y) { c->x = x; c->y = y; }
static inline void SetSize(Text_C0F0* c, int w, int h) { c->w = w; c->h = h; }
static inline Mtx* MtxAt(int i) { return &((Render*)g_Video)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

extern "C" void GuiGameScreen_DrawRoundCounts(Screen_C0F0* o)
{
    void* inv = g_LocalPlayer->actor->weapons;
    int idx = o->first;
    int i;
    for (i = 0; i < o->shown; i++) {
        int id;
        if (i >= o->count)
            break;
        id = o->ids[idx];
        if (id != -2) {
            char buf[32];
            signed char kind;
            int slot;
            buf[0] = 0;
            kind = WeaponDb_Get(g_WeaponDatabase, id)->kind;
            slot = WeaponInv_SlotOfItem(id);
            if ((unsigned char)kind == 1 || (unsigned char)kind == 7) {
                sprintf(buf, "%d", WeaponInv_GetSpare(inv, slot));
            } else if (WeaponInv_HasAmmoText(inv, id)) {
                int clip = WeaponInv_GetClip(inv, slot);
                sprintf(buf, "%d/%d", clip, WeaponInv_GetSpare(inv, slot));
            }
            if (buf[0]) {
                Slot_C0F0* s;
                float* pos;
                Col_C0F0 col;
                TextObj_SetText(o->text, buf);
                s = o->slots[i];
                SetSize(o->text, (int)s->w, (int)s->h);
                pos = &s->px;
                col = D_00587D80;
                col.a *= 1.0f - o->fade[i];
                { int k = D_00538C64; GQR(MtxAt(k + 1), MtxAt(k)); }
                D_00538C64++;
                UM(MtxAt(D_00538C64));
                D_00538C68 = 1;
                Col_C0F0 sh(0.0f, 0.0f, 0.0f, 1.0f - o->fade[i]);
                TextObj_SetColour(o->text, &sh);
                SetPos(o->text, (int)(1.0f + pos[0]), (int)(pos[1] - 1.0f));
                TextObj_Draw(o->text);
                TextObj_SetColour(o->text, &col);
                SetPos(o->text, (int)pos[0], (int)pos[1]);
                TextObj_Draw(o->text);
                D_00538C64--;
                D_00538C68 = 1;
            }
        }
        idx++;
        if (!(idx < o->count))
            idx = 0;
    }
}
