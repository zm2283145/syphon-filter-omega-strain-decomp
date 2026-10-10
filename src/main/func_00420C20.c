/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of Handler: only the slots used here are named (vtable offset in comments). */
struct Handler {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A();
    virtual void Method34(); /* +0x34 */
};

typedef struct Widget { char pad[0x44]; Handler* handler; /* +0x44 */ } Widget;

extern "C" void func_0041E040(Widget* self, int a, int b, int c);
extern "C" int func_0041EF10(Widget* self, Widget* sender, unsigned short code);

/* Event handler: on event 0x16 from itself runs func_0041E040 and the handler's virtual +0x34; else defers to func_0041EF10. */
extern "C" int func_00420C20(Widget* self, Widget* sender, unsigned short code)
{
    if (code == 0x16 && sender == self) {
        func_0041E040(self, 0x10, 1, 0);
        self->handler->Method34();
        return 1;
    }
    return func_0041EF10(self, sender, code);
}
