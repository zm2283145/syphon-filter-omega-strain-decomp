#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class Ai_9AC0 { public: VPAD16(a) VPAD4(b) virtual int IsA(); virtual int IsB(); };
typedef struct { char pad[0x58]; Ai_9AC0* ai; } Obj_9AC0;
extern "C" Obj_9AC0* GObj_IdentityB(int id);
extern "C" void func_0014A670(Ai_9AC0* ai);
static inline unsigned char TestA(Obj_9AC0* o) { unsigned char r = 0; if (o->ai && o->ai->IsA()) r = 1; return r; }
static inline unsigned char TestB(Obj_9AC0* o) { unsigned char r = 0; if (o->ai && o->ai->IsB()) r = 1; return r; }
extern "C" void Script_CastNPC(int* args)
{
    Obj_9AC0* o = GObj_IdentityB(*args);
    Ai_9AC0* ai = 0;
    if (TestA(o) || TestB(o))
        ai = o->ai;
    func_0014A670(ai);
}