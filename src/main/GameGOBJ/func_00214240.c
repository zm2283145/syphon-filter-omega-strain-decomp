#include "types.h"
typedef struct { char pad[0x4C]; int type; } F214Def;
typedef struct { F214Def* def; } F214Ent;
typedef struct { char pad[0xD0]; int* state; char padd4[8]; unsigned char active; } F214Obj;
typedef struct { char pad[0x68]; int kind; } F214Hdr;
typedef struct {
    char pad0[0x70];
    int count;
    char list[8];
    F214Obj** objs;
} F214Mgr;
extern F214Ent* func_00172990(void*, int);
extern int D_004F5468;
#pragma opt_strength_reduction off
unsigned char func_00214240(F214Mgr* m)
{
    unsigned char result = 1;
    int i;
    for (i = 0; i < m->count; i++) {
        F214Ent* e = func_00172990(m->list, i);
        if (e->def->type == D_004F5468) {
            F214Obj* o = m->objs[i];
            if (((F214Hdr*)o)->kind == 2) {
                if (!o->active || *o->state) {
                    result = 0;
                    break;
                }
            }
        }
    }
    return result;
}
#pragma opt_strength_reduction reset
