/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

typedef struct Source { int unk0; int count; } Source;

struct Widget {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void SetCount(int n, int total); /* +0x5C */
    char pad04[0xC0 - 4];
    Source* source;   /* +0xC0 */
    int entries[11];  /* +0xC4 */
};

extern "C" void func_00424430(Widget* self, int a, int b);
extern "C" void func_004248C0(Widget* self, int index, int value);

/* Binds a data source (+0xC0), sets the list to 11 entries via virtual +0x5C, resets it and fills entries from the +0xC4 table (walked with a stepping base pointer). */
extern "C" void func_003503D0(Widget* self, Source* source)
{
    Widget* p;
    int i;
    self->source = source;
    self->SetCount(11, source ? source->count : 0);
    func_00424430(self, 0, 0);
    for (i = 0, p = self; i < 11; i++, p = (Widget*)((char*)p + 4))
        func_004248C0(self, i, p->entries[0]);
}
