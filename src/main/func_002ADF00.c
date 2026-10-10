/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Widget {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual int IsA(void* type); /* +0x58 */
};

typedef struct Screen {
    char pad[0x94];
    unsigned char unk94;  /* +0x94 */
    char pad95[0x160 - 0x95];
    Widget* first;        /* +0x160 */
    Widget* second;       /* +0x164 */
} Screen;
extern int D_0048BCB8;
extern int D_0048BCC0;
extern char D_004A9870[];
extern "C" void func_0033F250(Screen* self);
extern "C" Widget* func_0041DB80(Screen* self, int id);

/* Base init (func_0033F250), then caches the D_0048BCB8 / D_0048BCC0 children (+0x160/+0x164) when they are of type D_004A9870, and clears +0x94. */
extern "C" void func_002ADF00(Screen* self)
{
    Widget* child;
    func_0033F250(self);
    child = func_0041DB80(self, D_0048BCB8);
    if (!child || !child->IsA(D_004A9870))
    child = 0;
    self->first = child;
    child = func_0041DB80(self, D_0048BCC0);
    if (!child || !child->IsA(D_004A9870))
    child = 0;
    self->second = child;
    self->unk94 = 0;
}
