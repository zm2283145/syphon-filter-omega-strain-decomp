#include "types.h"
extern char* D_0048C160[];
extern int String_CompareNoCase(const char* a, const char* b);
extern void func_002CC820(void* o, int i);
void func_002CC8E0(void* o, const char* name)
{
    int i;
    for (i = 0; i < 0x12; i++) {
        if (String_CompareNoCase(D_0048C160[i], name) == 0) {
            func_002CC820(o, i);
            return;
        }
    }
    func_002CC820(o, -1);
}