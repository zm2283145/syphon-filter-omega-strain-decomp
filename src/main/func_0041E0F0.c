/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of Handler: only the slots used here are named (vtable offset in comments). */
struct Handler {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C();
    virtual int Method3C(void* arg); /* +0x3C */
};

typedef struct Widget { char pad[0x44]; Handler* handler; /* +0x44 */ } Widget;

/* Passes arg to the widget's handler (virtual +0x3C); 0 without a widget. */
extern "C" int func_0041E0F0(void* arg, Widget* widget)
{
    if (widget)
        return widget->handler->Method3C(arg);
    return 0;
}
