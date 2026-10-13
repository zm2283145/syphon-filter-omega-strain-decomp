#include "types.h"
extern char* D_0048C160[];
extern int String_CompareNoCase(const char* a, const char* b);
extern void LevelSelect_SetLevel(void* o, int i);
void LevelSelect_FindByName(void* o, const char* name)
{
    int i;
    for (i = 0; i < 0x12; i++) {
        if (String_CompareNoCase(D_0048C160[i], name) == 0) {
            LevelSelect_SetLevel(o, i);
            return;
        }
    }
    LevelSelect_SetLevel(o, -1);
}