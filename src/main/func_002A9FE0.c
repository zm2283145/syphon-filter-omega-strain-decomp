#pragma cplusplus on
#include "types.h"

extern "C" char D_004AB7C0[];
extern "C" char D_004AB7D8[];
extern "C" char D_004AB7F0[];
static void * const dat_0048BC00[2] = { (void*)D_004AB7C0, (void*)0x0 };
static void * const dat_0048BC08[2] = { (void*)D_004AB7D8, (void*)0x0 };
static void * const dat_0048BC10[2] = { (void*)D_004AB7F0, (void*)0x0 };

struct Obj9FE0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual int IsA(const char* type); /* +0x58 */
};
struct Sub9FE0 { char pad[0x88]; Obj9FE0* link; };

typedef struct Screen9FE0 {
    char pad[0x88];
    Obj9FE0* item0; /* +0x88 */
    Obj9FE0* item2; /* +0x8C */
    Sub9FE0* item1; /* +0x90 */
    Obj9FE0* extra; /* +0x94 */
} Screen9FE0;

extern "C" {
extern char D_004A7520[];
extern char D_004AA640[];
extern const char* D_0048BBF0;

void func_0033D3F0(Screen9FE0* self);
Obj9FE0* func_0041DB80(Screen9FE0* self, const char* name);
}

static inline Obj9FE0* AsA9FE0(Obj9FE0* obj)
{
    return (obj && obj->IsA(D_004A7520)) ? obj : 0;
}
static inline Obj9FE0* AsB9FE0(Obj9FE0* obj)
{
    return (obj && obj->IsA(D_004AA640)) ? obj : 0;
}

/* Screen init: base init, looks up the named child widgets and links the extra one to the second. */
extern "C" void func_002A9FE0(Screen9FE0* self)
{
    func_0033D3F0(self);
    self->item0 = AsA9FE0(func_0041DB80(self, *(const char**)dat_0048BC00));
    self->item1 = (Sub9FE0*)AsB9FE0(func_0041DB80(self, *(const char**)dat_0048BC08));
    self->item2 = AsA9FE0(func_0041DB80(self, D_0048BBF0));
    self->extra = func_0041DB80(self, *(const char**)dat_0048BC10);
    if (self->extra && self->item1)
        self->item1->link = self->extra;
}
