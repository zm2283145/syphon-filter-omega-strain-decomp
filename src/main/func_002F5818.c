#include "types.h"
typedef struct { int f0; int f4; int f8; int fC; } Obj5818;
int func_002F5818(Obj5818* obj, int* out) {
    int result = 2;
    if (obj != 0 && out != 0) {
        *out = obj->fC;
        result = 0;
    }
    return result;
}
