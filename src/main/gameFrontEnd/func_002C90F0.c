#include "types.h"
typedef struct { char pad[0x24C]; int textIndex; } Ctx9070;
typedef struct { char pad[0x35]; unsigned char enabled; } Obj9070;
extern unsigned char D_005721C8;
extern Ctx9070* D_004FFC04;
extern char D_004ACBE8[];
extern char D_004ACBF8[];
extern char D_004ACC08[];
extern char D_004ACC18[];
static void * const dat_0048C1B0[20] = { (void*)0x0, (void*)0x0, (void*)0x0, (void*)D_004ACBE8, (void*)0x0, (void*)0x0, (void*)D_004ACBF8, (void*)0x0, (void*)0x0, (void*)0x0, (void*)D_004ACC08, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)D_004ACC18, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0 };
extern char* Loc_LookupText(char* key);
char* func_002C90F0(Obj9070* o)
{
    int i;
    char* key;
    if (o->enabled && !D_005721C8) {
        i = D_004FFC04->textIndex;
        if (i != -1) {
            key = ((char**)dat_0048C1B0)[i];
            if (key)
                return Loc_LookupText(key);
        }
    }
    return 0;
}