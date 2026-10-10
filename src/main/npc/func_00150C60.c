#include "types.h"
#pragma bool off
typedef struct C6Obj_150C60 { int pad[3]; int serial; } C6Obj_150C60;
typedef struct C6Ref_150C60 { C6Obj_150C60* obj; int serial; } C6Ref_150C60;
static inline int C6Valid(void* p) { return p != 0; }
C6Obj_150C60* ActorRef_Copy(C6Ref_150C60* ref) {
    C6Obj_150C60* o = ref->obj;
    unsigned char ok = 1;
    if (!C6Valid(o) == 0) {
        if (o->serial != ref->serial) ok = 0;
    }
    return ok ? o : 0;
}