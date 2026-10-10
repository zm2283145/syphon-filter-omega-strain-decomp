#pragma cplusplus on
#include "types.h"
struct C5Zone { int id; };
struct C5Obj2473 { char pad[0x128]; C5Zone* zone; };
extern "C" bool func_002473E0(C5Obj2473* p, int id) { return p->zone != 0 && id == p->zone->id; }