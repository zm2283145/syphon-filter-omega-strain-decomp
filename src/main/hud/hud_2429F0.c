/*
 * main/hud: range (3 files, 002429F0-00242B40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "vslot_pad.h"
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_002429F0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Obj2426 { char pad[0x6A4]; void* snd; unsigned char b6A8; unsigned char b6A9; unsigned char b6AA; };
class Mgr2427 {
public:
    VPAD16(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual void s23(void* x, int y);
};
extern "C" {
void* Gui_GetScreenList(void);
Mgr2427* Gui_GetScreenStack(void);
void* GuiManager_FindOrLoad(void* a, void* b, void* c);
void Game_SetPaused(void* p, int v);
void Hud_CloseMapScreen(Obj2426* s);
int Hud_IsGuiFocused(Obj2426* s);
void Pad_ResetHeldMask(void* p);
void GuiGameScreen_ToggleWeaponSelect(void* p, int v);
void func_00437950(int v);
extern char D_004FFB50[];
extern char D_0055A300[];
extern char D_004A7260[];
extern char D_004A7248[];
}
extern "C" void Hud_OpenPauseMenu(Obj2426* s) {
    if (s->b6A8) return;
    Game_SetPaused(D_004FFB50, 1);
    if (s->b6A9) Hud_CloseMapScreen(s);
    if (!Hud_IsGuiFocused(s)) Pad_ResetHeldMask(D_0055A300);
    {
        void* x = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A7260, "GAMEBACK");
        Gui_GetScreenStack()->s23(x, -1);
    }
    {
        void* x = GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A7248, "INGAMENU");
        Gui_GetScreenStack()->s23(x, 0);
    }
    GuiGameScreen_ToggleWeaponSelect(s->snd, 0);
    func_00437950(0);
    s->b6A8 = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002429F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002429F0 */

/* merge_units: begin func_00242B00 */
#pragma push /* merge_units */
typedef struct { char p0[0x100]; char list[0x6E4 - 0x100]; int owner; } C1Hud_242B;
extern void Notify_Insert(void* list, void* item, int owner, int a, int b);
void Hud_PostNotification(C1Hud_242B* h, void* item)
{
    if (item)
        Notify_Insert(h->list, item, h->owner, 1, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00242B00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00242B00 */

/* merge_units: begin func_00242B40 */
#pragma push /* merge_units */
extern unsigned char D_00533880;
extern int D_00533888;
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
typedef struct { void* vtable; char pad[0x18]; int x1C; unsigned char x20; char pad21[3]; unsigned char x24; char pad25[3]; int key; char pad2C[0x18]; int id; unsigned char flag; unsigned char x49; } Msg_242B40;
typedef struct { int key; int x4; int id; int c; int d; } Ent_242B40;
typedef struct Node_242B40 { struct Node_242B40* prev; struct Node_242B40* next; Ent_242B40* ent; } Node_242B40;
typedef struct { Node_242B40* n; } It_242B40;

extern unsigned char D_005721C8;
extern char D_0051EE48[];
extern char D_004DE0F0[];
extern char D_004A7210[];
void Event_Construct(Msg_242B40* m, void* type);
void Transport_Send(int a, Msg_242B40* m, int b, int c);
void cMessage_dtor(Msg_242B40* m, int flags);
void func_00242E30(It_242B40* out, char* l);
void CalloutList_End(It_242B40* out, char* l);
void func_002426A0(It_242B40* out, It_242B40* in);
void func_0015AF40(It_242B40* out, It_242B40* in);
void List_Erase(It_242B40* out, char* l, It_242B40* pos);
void IeElement_EvaluateAt(int a, float f);
void IeElement_SetShown(int a, int b);
void IeElement_SetText(int a, int b);
void HudTracker_Kill(int a);

static inline void BeginI_(It_242B40* out, char* l) { It_242B40 t; func_00242E30(&t, l); func_002426A0(out, &t); }
static inline void Begin_(It_242B40* out, char* l) { BeginI_(out, l); }
static inline void EndI_(It_242B40* out, char* l) { It_242B40 t; CalloutList_End(&t, l); func_002426A0(out, &t); }
static inline void End_(It_242B40* out, char* l) { EndI_(out, l); }
static inline void EraseI_(char* l, Node_242B40* n) { It_242B40 ac; It_242B40 a8; It_242B40 a4; ac.n = n; func_0015AF40(&a4, &ac); List_Erase(&a8, l, &a4); }

#pragma opt_dead_assignments off
int Hud_ClearCallout(char* o, int* key, int id, signed char flag, int send)
{
    Msg_242B40 m;
    It_242B40 it;
    It_242B40 b8;
    It_242B40 b4;
    int gap;
    if (D_005721C8 && send) {
        Event_Construct(&m, D_0051EE48);
        m.vtable = D_004DE0F0;
        m.x24 = 1;
        m.key = *key;
        m.x1C = 0x40;
        m.x20 = 4;
        m.id = id;
        m.flag = flag;
        m.x49 = 0;
        Transport_Send(0, &m, -1, -1);
        m.vtable = D_004DE0F0;
        cMessage_dtor(&m, 0);
    }
    { int* p = &gap; }
    Begin_(&b8, o + 0x6E8);
    for (it = b8; End_(&b4, o + 0x6E8), it.n != b4.n; it.n = it.n->next) {
        if (it.n->ent->key == *key && id == it.n->ent->id) {
            Ent_242B40* e;
            if (flag) {
                IeElement_EvaluateAt(it.n->ent->c, 0.0f);
                IeElement_SetShown(it.n->ent->c, 0);
            }
            e = it.n->ent;
            {
                if (D_00533880) Alloc_Lock(9);
                D_00533888++;
                if (e) {
                    if (e->c)
                        IeElement_SetText(e->c, 0);
                    if (e->d)
                        HudTracker_Kill(e->d);
                }
                Mem_Free(0, e, D_004A7210, 0x55F);
                if (D_00533880) Alloc_Unlock(9);
                D_00533888--;
            }
            EraseI_(o + 0x6E8, it.n);
            return 1;
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00242B40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00242B40 */
