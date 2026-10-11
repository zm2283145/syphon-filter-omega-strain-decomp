#include "types.h"
typedef struct { char pad[0x24C]; int textIndex; } Ctx9070;
typedef struct { char pad[0x35]; unsigned char enabled; } Obj9070;
extern unsigned char D_005721C8;
extern Ctx9070* D_004FFC04;
extern char* D_0048C1B0[];
extern char* Loc_LookupText(char* key);
char* func_002C90F0(Obj9070* o)
{
    int i;
    char* key;
    if (o->enabled && !D_005721C8) {
        i = D_004FFC04->textIndex;
        if (i != -1) {
            key = D_0048C1B0[i];
            if (key)
                return Loc_LookupText(key);
        }
    }
    return 0;
}