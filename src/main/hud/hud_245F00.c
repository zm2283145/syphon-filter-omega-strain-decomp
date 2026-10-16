/*
 * main/hud: range (2 files, 00245F00-002464B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

/* merge_units: begin func_00245F00 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Stack_245F00 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void Draw(); virtual void Update(float dt);
    virtual void Show(void* p, int a); virtual void Hide(void* p);
};
struct Widget_245F00 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(void* type);
};
struct Elem_245F00 { char pad[0x10]; unsigned char b10; char pad11[0x58 - 0x11]; unsigned char b58; };
struct Model_245F00 { char pad[0x74]; Elem_245F00* f74; };
struct Node_245F00 { char pad[0x62]; unsigned char b62; };
struct Link_245F00 { void* owner; };
struct Snd_245F00 { char pad[0x280]; int f280[1]; };
struct Sub7C_245F00 { char pad[0xC]; unsigned char bC; };
struct Hud_245F00 {
    char pad0[0xC];
    unsigned char bC;
    char padD[0x50 - 0xD];
    int f50;
    void** f54;
    void* f58;
    void* f5C;
    void* f60;
    int f64;
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    Sub7C_245F00 m7C;
    char pad8C_[0x8C - 0x7C - sizeof(Sub7C_245F00)];
    int f8C;
    char m90[0xD0 - 0x90];
    Link_245F00 mD0;
    char padD4[0xEC - 0xD4];
    int fEC;
    int fF0;
    char padF4[0x100 - 0xF4];
    char m100[0x630 - 0x100];
    void* f630;
    char m634[0x69C - 0x634];
    Model_245F00* f69C;
    Link_245F00* f6A0;
    void* f6A4;
    unsigned char b6A8;
    unsigned char b6A9;
    unsigned char b6AA;
    int f6AC;
    unsigned char b6B0;
    int f6B4;
    char pad6B8[0x6BC - 0x6B8];
    Widget_245F00* f6BC;
    Widget_245F00* f6C0;
    int f6C4;
    unsigned char b6C8;
    int f6CC;
    char pad6D0[0x6D4 - 0x6D0];
    Widget_245F00* f6D4;
    Widget_245F00* f6D8;
    int f6DC;
    float f6E0;
    char pad6E4[0x6E8 - 0x6E4];
    char m6E8[0xC];
};
extern "C" {
extern char D_004A7210[];
extern char D_004A7248[];
extern char D_004A7260[];
extern char D_004A7278[];
extern char D_004A7288[];
extern char D_004A72B8[];
extern char D_004A72C8[];
extern char D_004A72E0[];
extern char D_004A72F8[];
extern char D_004A7308[];
extern char D_004A7310[];
extern char D_004A7328[];
extern char D_004A7338[];
extern char D_004A7348[];
extern char D_004A7360[];
extern char D_004A7378[];
extern char D_004A7388[];
extern char D_004A7398[];
extern char D_004A73B0[];
extern char D_004A73C0[];
extern char D_004A73D0[];
extern char D_004A73E8[];
extern char D_004A73F8[];
extern char D_004A7400[];
extern char D_004A7410[];
extern char D_004A7420[];
extern char D_004A7438[];
extern char D_004A7520[];
extern signed char D_004F7D40;
extern Node_245F00* D_004F7D90;
extern Node_245F00* D_004F7DA0;
extern Node_245F00* D_004F7DA4;
extern Node_245F00* D_004F7DA8;
extern Node_245F00* D_004F7DAC;
extern Node_245F00* D_004F7DB0;
extern void* D_004FFC04;
void* Gui_GetScreenList(void);
Stack_245F00* Gui_GetScreenStack(void);
void Hud_SetGoggles(Hud_245F00* h, int on);
void* Mem_Alloc(int pool, int size, char* file, int line);
void ObjMarkerMgr_ctor(void* p);
void ScalarCollection_Init(void* p);
Snd_245F00* App_GetInstance(void);
void** func_00241C70(int a, int b);
void Hud_SelectTextColorTable(Hud_245F00* h, int a);
void Hud_InitCalloutRects(Hud_245F00* h);
void func_00246540(void* mgr, Link_245F00** l);
void func_00246570(void* p);
void func_00246590(Hud_245F00* h);
void WeaponPreview_ctor(void* p);
int Hud_FindOrCreateElement(void* a, char* name);
void HudRadar_ctor(void* a, void* b);
Link_245F00* HudMap_ctor(void* p, int a, int b);
void FrontEnd_StartGui(void* a, int b);
void func_003E7EB0(void* a, void* b);
void func_003E8DE0(int a, int b);
void func_003EE830(void* a, int b);
void* func_003EEB30(void* a, char* name);
void func_003EEBE0(void* a, int b, int c);
void* func_003EF010(void* a);
void func_003FA1B0(void* a, int b);
void func_003FA500(void* a, int b, int c);
void* func_004187C0(void* list, char* a, char* b);
void GuiManager_FindOrLoad(void* list, char* a, char* b);
Widget_245F00* GuiWidget_FindChildByName(void* a, char* name);
}

#pragma inline_depth(10)
static inline void* Alloc_245F00(int n, int line) { AllocGuard g; return Mem_Alloc(0, n, D_004A7210, line); }
static inline void Reg_245F00(void* mgr, Link_245F00* l) { l->owner = mgr; func_00246540(mgr, &l); }
static inline Widget_245F00* Cast_245F00(Widget_245F00* w, void* t) { return w && w->IsA(t) ? w : 0; }
extern "C" Hud_245F00* HudObject_ctor(Hud_245F00* h, int a1, int a2, int a3)
{
    void* root;
    void* grp;
    Widget_245F00* wa;
    Widget_245F00* wb;
    func_00246590(h);
    h->bC = 1;
    h->f50 = a1;
    h->f54 = func_00241C70(a2, a1);
    h->f58 = func_003EEB30(*h->f54, D_004A72B8);
    h->f5C = func_003EEB30(*h->f54, D_004A72C8);
    h->f60 = func_003EEB30(*h->f54, D_004A72E0);
    h->f64 = 0;
    h->f68 = 0;
    {
        Sub7C_245F00* s = &h->m7C;
        func_00246570(s);
        s->bC = 1;
    }
    ObjMarkerMgr_ctor(h->m90);
    HudRadar_ctor(&h->mD0, func_003EEB30(*h->f54, D_004A72F8));
    h->fEC = 0;
    {
        signed char c = D_004F7D40;
        int v = *(int*)((unsigned char)c * 4 + (char*)App_GetInstance()->f280);
        func_003FA500(h->m100, Hud_FindOrCreateElement(*h->f54, D_004A7308), v);
    }
    WeaponPreview_ctor(h->m634);
    {
        Link_245F00* p;
        p = (Link_245F00*)Alloc_245F00(0xA0, 0xE0);
        if (p) p = HudMap_ctor(p, h->f50, a3);
        h->f6A0 = p;
    }
    h->f6A4 = 0;
    h->b6A8 = 0;
    h->b6A9 = 0;
    h->b6AA = 0;
    h->f6BC = 0;
    h->f6C0 = 0;
    h->f6AC = 0;
    h->b6B0 = 0;
    h->f6B4 = 0;
    h->f6D4 = 0;
    h->f6D8 = 0;
    h->f6C4 = 0;
    h->b6C8 = 0;
    h->f6CC = 0;
    ScalarCollection_Init(h->m6E8);
    Reg_245F00(h->m90, h->f6A0);
    Reg_245F00(h->m90, &h->mD0);
    root = *h->f54;
    func_003EE830(h->f5C, 1);
    func_003EE830(h->f60, 1);
    grp = func_003EEB30(root, D_004A7310);
    func_003EEBE0(grp, 1, 1);
    h->f6C = Hud_FindOrCreateElement(grp, D_004A7328);
    h->f70 = Hud_FindOrCreateElement(grp, D_004A7338);
    h->f74 = Hud_FindOrCreateElement(root, D_004A7348);
    Hud_SetGoggles(h, 0);
    h->f8C = -1;
    func_003FA1B0(h->m100, 0);
    grp = func_003EEB30(root, D_004A7360);
    h->f630 = func_003EF010(grp);
    func_003E7EB0(h->f630, h->m634);
    h->f69C = (Model_245F00*)func_003EF010(func_003EEB30(grp, D_004A7378));
    {
        Elem_245F00* e = h->f69C->f74;
        if (e) {
            e->b58 = 1;
            e->b10 = 2;
        }
    }
    D_004F7D90 = (Node_245F00*)func_003EEB30(root, D_004A7388);
    D_004F7D90->b62 = 1;
    D_004F7DA0 = (Node_245F00*)func_003EEB30(root, D_004A7398);
    D_004F7DA4 = (Node_245F00*)func_003EEB30(root, D_004A73B0);
    D_004F7DA8 = (Node_245F00*)func_003EEB30(root, D_004A73C0);
    D_004F7DAC = (Node_245F00*)func_003EEB30(root, D_004A73D0);
    D_004F7DA0->b62 = 1;
    D_004F7DA4->b62 = 1;
    D_004F7DA8->b62 = 1;
    D_004F7DAC->b62 = 1;
    Hud_InitCalloutRects(h);
    D_004F7DB0 = (Node_245F00*)func_003EEB30(root, D_004A73E8);
    D_004F7DB0->b62 = 1;
    func_003EEBE0(D_004F7DB0, 0, 1);
    h->f78 = Hud_FindOrCreateElement(root, D_004A73F8);
    func_003E8DE0(h->f78, 0);
    Hud_SelectTextColorTable(h, 0);
    h->fF0 = 0;
    h->f6DC = 0;
    h->f6E0 = -1.0f;
    FrontEnd_StartGui(D_004FFC04, 1);
    h->f6A4 = func_004187C0(Gui_GetScreenList(), D_004A7400, D_004A7410);
    Gui_GetScreenStack()->Show(h->f6A4, 0);
    wa = Cast_245F00(GuiWidget_FindChildByName(h->f6A4, D_004A7420), D_004A7520);
    wb = Cast_245F00(GuiWidget_FindChildByName(h->f6A4, D_004A7438), D_004A7520);
    h->f6D4 = wa;
    h->f6D8 = wb;
    h->f6BC = wa;
    h->f6C0 = wb;
    GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A7260, D_004A7278);
    GuiManager_FindOrLoad(Gui_GetScreenList(), D_004A7248, D_004A7288);
    return h;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00245F00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00245F00 */

/* merge_units: begin func_002464B0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(func_002464B0, D_004DC4A0, cGOBJ_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_002464B0 */
