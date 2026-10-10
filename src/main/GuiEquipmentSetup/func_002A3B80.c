#include "types.h"
typedef struct { char pad[0x32]; unsigned char unk32; } Sub002A3B80;
typedef struct { char pad[0x3584]; Sub002A3B80* sub; } Obj002A3B80;
/* Return byte 0x32 of the sub-object, or 0 if none. */
int func_002A3B80(Obj002A3B80* obj)
{
    Sub002A3B80* sub = obj->sub;
    if (sub) {
        return sub->unk32;
    }
    return 0;
}
