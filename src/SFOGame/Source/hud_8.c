/*
 * main/hud: range (3 files, 002429F0-00242B40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "vslot_pad.h"
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* merge_units: begin func_002429F0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Obj2426 { char pad[0x6A4]; void* snd; unsigned char b6A8; unsigned char b6A9; unsigned char b6AA; };
class Mgr2427 {
public:
    VPAD16(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual void s23(void* x, int y);
};
extern "C" {
void* Gui_Manager(void);
Mgr2427* Gui_Canvas(void);
void* GuiManager_OpenGui(void* a, void* b, void* c);
void cGameSystem_PauseGame(void* p, int v);
void cHud_DeactivateMap(Obj2426* s);
int Hud_IsGuiFocused(Obj2426* s);
void cJoystick_Debounce(void* p);
void GuiGameScreen_ActivateWeaponSelect(void* p, int v);
void func_00437950(int v);
extern char g_Game[];
extern char D_0055A300[];
extern char D_004A7260[];
extern char D_004A7248[];
}
extern "C" void cHud_ActivateObjectiveMenu(Obj2426* s) {
    if (s->b6A8) return;
    cGameSystem_PauseGame(g_Game, 1);
    if (s->b6A9) cHud_DeactivateMap(s);
    if (!Hud_IsGuiFocused(s)) cJoystick_Debounce(D_0055A300);
    {
        void* x = GuiManager_OpenGui(Gui_Manager(), D_004A7260, "GAMEBACK");
        Gui_Canvas()->s23(x, -1);
    }
    {
        void* x = GuiManager_OpenGui(Gui_Manager(), D_004A7248, "INGAMENU");
        Gui_Canvas()->s23(x, 0);
    }
    GuiGameScreen_ActivateWeaponSelect(s->snd, 0);
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
extern void cInfoBar_AddMessage(void* list, void* item, int owner, int a, int b);
void cHud_Message(C1Hud_242B* h, void* item)
{
    if (item)
        cInfoBar_AddMessage(h->list, item, h->owner, 1, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00242B00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00242B00 */

/* merge_units: begin func_00242B40 */
#pragma push /* merge_units */
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void Alloc_Lock(int id);
void EnableIntc(int id);
typedef struct { void* vtable; char pad[0x18]; int x1C; unsigned char x20; char pad21[3]; unsigned char x24; char pad25[3]; int key; char pad2C[0x18]; int id; unsigned char flag; unsigned char x49; } Msg_242B40;
typedef struct { int key; int x4; int id; int c; int d; } Ent_242B40;
typedef struct Node_242B40 { struct Node_242B40* prev; struct Node_242B40* next; Ent_242B40* ent; } Node_242B40;
typedef struct { Node_242B40* n; } It_242B40;

extern unsigned char g_IsMultiplayer;
extern char D_0051EE48[];
extern char D_004DE0F0[];
extern char D_004A7210[];
void cMessage_ctor_cMessageNameR(Msg_242B40* m, void* type);
void cNetObj_SendMessage_int_cMessageR_int_int(int a, Msg_242B40* m, int b, int c);
void cMessage_dtor(Msg_242B40* m, int flags);
void std_list_tCalloutPtr_begin(It_242B40* out, char* l);
void std_list_tCalloutPtr_end_void(It_242B40* out, char* l);
void cLListIterator_tCalloutPtr_ctor(It_242B40* out, It_242B40* in);
void std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(It_242B40* out, It_242B40* in);
void std_list_deleter_voidPtr_erase_listdeleter(It_242B40* out, char* l, It_242B40* pos);
void cAnimator_SetFrame(int a, float f);
void cInterfaceElement_Activate(int a, int b);
void cInterfaceElement_SetText(int a, int b);
void cIE_GOBJ_AnimateOff(int a);

static inline void BeginI_(It_242B40* out, char* l) { It_242B40 t; std_list_tCalloutPtr_begin(&t, l); cLListIterator_tCalloutPtr_ctor(out, &t); }
static inline void Begin_(It_242B40* out, char* l) { BeginI_(out, l); }
static inline void EndI_(It_242B40* out, char* l) { It_242B40 t; std_list_tCalloutPtr_end_void(&t, l); cLListIterator_tCalloutPtr_ctor(out, &t); }
static inline void End_(It_242B40* out, char* l) { EndI_(out, l); }
static inline void EraseI_(char* l, Node_242B40* n) { It_242B40 ac; It_242B40 a8; It_242B40 a4; ac.n = n; std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&a4, &ac); std_list_deleter_voidPtr_erase_listdeleter(&a8, l, &a4); }

#pragma opt_dead_assignments off
int cHud_ClearCallout(char* o, int* key, int id, signed char flag, int send)
{
    Msg_242B40 m;
    It_242B40 it;
    It_242B40 b8;
    It_242B40 b4;
    int gap;
    if (g_IsMultiplayer && send) {
        cMessage_ctor_cMessageNameR(&m, D_0051EE48);
        m.vtable = D_004DE0F0;
        m.x24 = 1;
        m.key = *key;
        m.x1C = 0x40;
        m.x20 = 4;
        m.id = id;
        m.flag = flag;
        m.x49 = 0;
        cNetObj_SendMessage_int_cMessageR_int_int(0, &m, -1, -1);
        m.vtable = D_004DE0F0;
        cMessage_dtor(&m, 0);
    }
    { int* p = &gap; }
    Begin_(&b8, o + 0x6E8);
    for (it = b8; End_(&b4, o + 0x6E8), it.n != b4.n; it.n = it.n->next) {
        if (it.n->ent->key == *key && id == it.n->ent->id) {
            Ent_242B40* e;
            if (flag) {
                cAnimator_SetFrame(it.n->ent->c, 0.0f);
                cInterfaceElement_Activate(it.n->ent->c, 0);
            }
            e = it.n->ent;
            {
                if (g_ProfileLockEnabled) Alloc_Lock(9);
                g_ProfileLockDepth++;
                if (e) {
                    if (e->c)
                        cInterfaceElement_SetText(e->c, 0);
                    if (e->d)
                        cIE_GOBJ_AnimateOff(e->d);
                }
                cMemMan_Deallocate(0, e, D_004A7210, 0x55F);
                if (g_ProfileLockEnabled) EnableIntc(9);
                g_ProfileLockDepth--;
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
