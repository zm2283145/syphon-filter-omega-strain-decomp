#include "types.h"
typedef struct {
    char p00[0x3C];
    int flags;
} PlayerInput_24A660;
typedef struct {
    char p00[0x4C];
    int type;
} Obj_24A660;
extern int D_0049D010;
extern unsigned char func_0024A7A0(PlayerInput_24A660* p, Obj_24A660* o);
unsigned char func_0024A660(PlayerInput_24A660* p, Obj_24A660* o) {
    if ((p->flags >> 4) & 1) {
        o = (o && o->type == D_0049D010) ? o : 0;
        if (o)
            return func_0024A7A0(p, o);
        return 0;
    }
    return 0;
}