/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of Manager: only the slots used here are named (vtable offset in comments). */
struct Manager {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Method68(int value); /* +0x68 */
};

typedef struct Screen { char pad[0x250]; int unk250; /* +0x250 */ } Screen;

extern char D_004C2780[];
extern char D_004C2798[];
extern "C" Manager* func_004147A0(void);
extern "C" void* func_00414790(void);
extern "C" void* func_00418A80(void* root, const char* a, const char* b);
extern "C" void func_00414AC0(Manager* mgr, Screen* screen, void* item);

/* Passes +0x250 to the manager's virtual +0x68, looks up an item by the two names and hands it to func_00414AC0. */
extern "C" void func_00463310(Screen* self)
{
    void* item;
    func_004147A0()->Method68(self->unk250);
    item = func_00418A80(func_00414790(), D_004C2780, D_004C2798);
    func_00414AC0(func_004147A0(), self, item);
}
