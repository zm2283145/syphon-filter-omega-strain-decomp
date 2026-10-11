#include "types.h"
typedef struct { char pad[0xC]; int serial; } Tgt40BF10;
typedef struct { Tgt40BF10* obj; int serial; } Ref40BF10;
extern Ref40BF10 D_00571770;
Tgt40BF10* func_0040BF10(void) {
    Tgt40BF10* obj = D_00571770.obj;
    unsigned char valid = 1;
    if (!((obj != 0) ^ 1)) {
        if (obj->serial != D_00571770.serial) {
            valid = 0;
        }
    }
    return valid ? obj : 0;
}