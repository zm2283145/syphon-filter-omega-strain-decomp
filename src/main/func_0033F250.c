#pragma cplusplus on
#include "types.h"

struct Obj3F250 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual int IsA(const char* type); /* +0x58 */
};
struct List3F250 { char pad[0x60]; int f60; char pad64[0x18]; Obj3F250* f7C; };

typedef struct Screen3F250 {
    char pad[0x88];
    Obj3F250* f88;
    List3F250* f8C;
    char pad90[8];
    Obj3F250* f98;
    Obj3F250* f9C;
    Obj3F250* fA0;
    Obj3F250* fA4;
} Screen3F250;

extern "C" {
char D_004B9CC8[] = "vscrollbar2";
char D_004B9CD8[] = "callout";
char D_004B9CE0[] = "GuiChatWindow";
char D_004B9CF0[] = "GuiMissionList";
extern char D_004AAE00[];
extern char D_004A9870[];
extern const char* D_004928B0;
extern const char* D_004928B8;
extern const char* D_004928C0;
extern const char* D_004928C8;
extern const char* D_004928D0;
extern const char* D_004928D8;
void func_0033D3F0(Screen3F250* self);
Obj3F250* func_0041DB80(Screen3F250* self, const char* name);
void MLTextWidget_SetFont(List3F250* l, char* s);
}

static inline Obj3F250* As3F250(Obj3F250* obj, const char* type)
{
    return (obj && obj->IsA(type)) ? obj : 0;
}

/* Screen init: base init, then looks up the child widgets and sets up the list. */
extern "C" void func_0033F250(Screen3F250* self)
{
    func_0033D3F0(self);
    self->f88 = As3F250(func_0041DB80(self, D_004928B0), D_004B9CF0);
    self->f8C = (List3F250*)As3F250(func_0041DB80(self, D_004928B8), D_004B9CE0);
    self->f8C->f7C = As3F250(func_0041DB80(self, D_004B9CC8), D_004AAE00);
    MLTextWidget_SetFont(self->f8C, D_004B9CD8);
    self->f8C->f60 = 0x40;
    self->f98 = As3F250(func_0041DB80(self, D_004928C0), D_004A9870);
    self->f9C = As3F250(func_0041DB80(self, D_004928C8), D_004A9870);
    self->fA0 = As3F250(func_0041DB80(self, D_004928D0), D_004A9870);
    self->fA4 = As3F250(func_0041DB80(self, D_004928D8), D_004A9870);
}
