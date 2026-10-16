#pragma cplusplus on
#include "types.h"

struct Obj47820 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual int IsA(const char* type); /* +0x58 */
};
struct List47820 { char pad[0x60]; int f60; char pad64[0x18]; Obj47820* f7C; };

struct V47820 { float x, y, z, w; } __attribute__((aligned(16)));
struct Sp47820 { char pad[0x10]; V47820 c0; V47820 c1; };
static inline void SetA47820(Sp47820* p, V47820 a) { p->c0 = a; }
static inline void SetB47820(Sp47820* p, V47820 b) { p->c1 = b; }
typedef struct Screen47820 {
    char pad[0x88];
    Obj47820* f88;
    Obj47820* f8C;
    Obj47820* f90;
    Obj47820* f94;
    char pad98[8];
    Obj47820* fA0;
    Obj47820* fA4;
} Screen47820;

extern "C" {
extern char D_004BA2A0[];
static void * const dat_00492B60[2] = { (void*)D_004BA2A0, (void*)0x0 };
extern char D_004BA2B0[];
static void * const dat_00492B68[2] = { (void*)D_004BA2B0, (void*)0x0 };
extern char D_004BA2B8[];
static void * const dat_00492B70[2] = { (void*)D_004BA2B8, (void*)0x0 };
extern char D_004BA2C0[];
static void * const dat_00492B78[2] = { (void*)D_004BA2C0, (void*)0x0 };
extern char D_004BA2C8[];
static void * const dat_00492B80[2] = { (void*)D_004BA2C8, (void*)0x0 };
extern char D_004BA540[];
extern char D_004A9870[];
extern char D_004A7520[];
extern char D_004BA3B0[];
extern V47820 D_00587B50;
extern V47820 D_00587B60;
extern const char* D_00492B98;
void GuiScreen_Init(Screen47820* self);
Obj47820* GuiWidget_FindChildByName(Screen47820* self, const char* name);
int Gui_GetScreenList(void);
Sp47820* func_00418420(int mgr, char* name);
}

static inline Obj47820* As47820(Obj47820* obj, const char* type)
{
    return (obj && obj->IsA(type)) ? obj : 0;
}

/* Screen init: base init, child widget lookups, then sets the two colours of a named sprite. */
extern "C" void func_00347820(Screen47820* self)
{
    Sp47820* sp;
    GuiScreen_Init(self);
    self->f88 = As47820(GuiWidget_FindChildByName(self, *(const char**)dat_00492B60), D_004BA540);
    self->f8C = As47820(GuiWidget_FindChildByName(self, *(const char**)dat_00492B68), D_004A9870);
    self->f90 = As47820(GuiWidget_FindChildByName(self, *(const char**)dat_00492B70), D_004A9870);
    self->f94 = As47820(GuiWidget_FindChildByName(self, *(const char**)dat_00492B78), D_004A9870);
    self->fA0 = As47820(GuiWidget_FindChildByName(self, *(const char**)dat_00492B80), D_004A7520);
    self->fA4 = GuiWidget_FindChildByName(self, D_00492B98);
    sp = func_00418420(Gui_GetScreenList(), D_004BA3B0);
    if (sp) { SetA47820(sp, D_00587B50); SetB47820(sp, D_00587B60); }
}
