#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
char * ObjRegistry_Find();                           

char * IdMgr_IsOccupied(int arg0) {
    char *var_v1;
    char * temp_v0;

    temp_v0 = (char *)(ObjRegistry_Find());
    if (temp_v0 != NULL) {
        var_v1 = (char *)(F_(temp_v0, 0x1C, int));
        if (var_v1 != NULL) {
loop_2:
            if ((int)var_v1 == (int)arg0) {
                return temp_v0;
            }
            var_v1 = *(char **)var_v1;
            if (var_v1 == NULL) {
                goto block_6;
            }
            goto loop_2;
        }
    }
block_6:
    return NULL;
}
