/*
 * SFOGame/Source/GuiGameScreen: 3 files, 0045BF80-0045C0F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045BF80 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Widget {
    char pad[0x14];
    unsigned short flags;
} Widget;

typedef struct ObjF0 {
    char pad[0xE0];
    Widget* widget;
    char padE4[4];
    int handle;     /* 0xE8 */
    void* target;   /* 0xEC */
    void* owner;    /* 0xF0 */
} ObjF0;

/* Notification message built on the stack. */
typedef struct NotifyMsg {
    void* vtable;
    char pad04[0x20];
    void* owner;    /* 0x24 */
    int code;       /* 0x28 */
    char pad2C[4];
} NotifyMsg;

extern int D_004F7E48;
extern int D_004DC330;
extern void GuiTextListWidget_Clear(int);
extern void cMessage_ctor_cMessageNameR(NotifyMsg*, void*);
extern void QueueMessage_cMessageR_cSystemP_int(NotifyMsg*, void*, int);
extern void cMessage_dtor(NotifyMsg*, int);
extern void GuiGameScreen_ReleaseInput(ObjF0*);

/* Closes the attached widget, notifies the owner (code -255) and detaches. */
void GuiGameScreen_CloseChooseMenu(ObjF0* o) {
    void* owner;
    NotifyMsg msg;
    if (o->widget == 0) return;
    o->widget->flags &= ~2;
    GuiTextListWidget_Clear(o->handle);
    owner = o->owner;
    if (owner != 0) {
        cMessage_ctor_cMessageNameR(&msg, &D_004F7E48);
        msg.owner = owner;
        msg.vtable = &D_004DC330;
        msg.code = -0xFF;
        QueueMessage_cMessageR_cSystemP_int(&msg, o->target, 0);
        msg.vtable = &D_004DC330;
        cMessage_dtor(&msg, 0);
    }
    o->target = 0;
    o->owner = 0;
    GuiGameScreen_ReleaseInput(o);
}
static inline void merge_flush_func_0045BF80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045BF80 */

/* merge_units: begin func_0045C030 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; unsigned short flags; } W45C;
typedef struct { char pad[0x94]; int f94; } M45C;
typedef struct { char pad[0xE0]; W45C* fe0; int fe4; M45C* fe8; int fec; int ff0; char pad2[0x1C]; unsigned char b110; } P45C;
extern void* Gui_Canvas(void);
extern void GuiCanvas_SetFocus(void*, M45C*);
extern char* nGlobalization_GetString_charP(char*);
extern void GuiTextListWidget_AddItem(M45C*, char*, int, int);
extern void GuiWidget_SendMessage(W45C*, void*, int, int, int);
#if 0 /* merge_units */
extern void GuiGameScreen_CloseChooseMenu(P45C*);
#endif /* merge_units */
#define GuiGameScreen_CloseChooseMenu(a0) (GuiGameScreen_CloseChooseMenu((ObjF0 *)(a0))) /* merge_units */

void GuiGameScreen_BeginChooseMenu(P45C* p, int arg) {
    if (p->fe0) {
        if (p->fe8->f94) {
            p->fe0->flags |= 2;
            GuiCanvas_SetFocus(Gui_Canvas(), p->fe8);
            GuiTextListWidget_AddItem(p->fe8, nGlobalization_GetString_charP("Cancel"), -1, 0);
            p->ff0 = arg;
            p->b110 = 0;
            GuiWidget_SendMessage(p->fe0, Gui_Canvas(), 0x10, 2, 0);
        } else {
            GuiGameScreen_CloseChooseMenu(p);
        }
    }
}
#undef GuiGameScreen_CloseChooseMenu /* merge_units */
static inline void merge_flush_func_0045C030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045C030 */

/* merge_units: begin func_0045C0F0 */
#pragma push /* merge_units */
#pragma opt_rebuildconditionals off
#pragma cplusplus on
/* GuiGameScreen_DrawWeaponPanelText: draws the ammo count ("%d" or "%d/%d")
 * under each visible weapon slot of the in-game weapon selector, with a
 * one-pixel drop shadow and the slot's fade. Render-state helpers as in
 * GuiTextArrayWidget_onElementRender (guiTextArrayWidget_425E00.c). */
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
Wpn_C0F0* cWeaponDB_GetEntry(void* db, int id);
int cWeapon_GetWeaponSlot(int id);
int cWeapon_GetAmmo(void* inv, int slot);
int cWeapon_GetClipAmmo(void* inv, int slot);
int cWeapon_HasAmmoCount(void* inv, int id);
void cTextArea_SetText(Text_C0F0* c, char* text);
void cTextArea_SetColor(Text_C0F0* c, Col_C0F0* p);
void TextObj_Draw(Text_C0F0* c);
void GuiGameScreen_DrawWeaponPanelText(Screen_C0F0* o);
}
static inline void SetPos(Text_C0F0* c, int x, int y) { c->x = x; c->y = y; }
static inline void SetSize(Text_C0F0* c, int w, int h) { c->w = w; c->h = h; }
static inline Mtx* MtxAt(int i) { return &((Render*)g_Video)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

extern "C" void GuiGameScreen_DrawWeaponPanelText(Screen_C0F0* o)
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
            kind = cWeaponDB_GetEntry(g_WeaponDatabase, id)->kind;
            slot = cWeapon_GetWeaponSlot(id);
            if ((unsigned char)kind == 1 || (unsigned char)kind == 7) {
                sprintf(buf, "%d", cWeapon_GetAmmo(inv, slot));
            } else if (cWeapon_HasAmmoCount(inv, id)) {
                int clip = cWeapon_GetClipAmmo(inv, slot);
                sprintf(buf, "%d/%d", clip, cWeapon_GetAmmo(inv, slot));
            }
            if (buf[0]) {
                Slot_C0F0* s;
                float* pos;
                Col_C0F0 col;
                cTextArea_SetText(o->text, buf);
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
                cTextArea_SetColor(o->text, &sh);
                SetPos(o->text, (int)(1.0f + pos[0]), (int)(pos[1] - 1.0f));
                TextObj_Draw(o->text);
                cTextArea_SetColor(o->text, &col);
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
static inline void merge_flush_func_0045C0F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045C0F0 */
