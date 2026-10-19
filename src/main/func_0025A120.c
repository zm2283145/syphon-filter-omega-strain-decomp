#include "types.h"
typedef struct { char pad[0xD4]; unsigned char done; } O_A120;
O_A120 **func_0025A1C0(void *, int);
int Object_DeleteLater(O_A120 *, float);
int Object_Unregister(O_A120 *);
extern char D_004F8040;
extern int D_004F8044;
void AreaEffect_FinishAll(void) {
    int i;
    for (i = 0; i < D_004F8044; i++) {
        O_A120* o = *func_0025A1C0(&D_004F8040, i);
        if (!o->done) {
            o->done = 1;
            Object_Unregister(o);
            Object_DeleteLater(o, 0.1f);
        }
    }
}