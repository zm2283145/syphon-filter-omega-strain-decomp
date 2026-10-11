#pragma opt_propagation off
#include "types.h"

/* Look up a resource by its lower-cased short name (up to 16 chars, stops at '.'). */
typedef struct { __int128 q; } Name_3A35C0;
extern Name_3A35C0 D_0053BAB0;
extern char String_ToLower(char c);
extern void func_003A3430(void* self, char* name);

void func_003A35C0(void* self, const char* s)
{
    Name_3A35C0* name = &D_0053BAB0;
    unsigned int i;
    char* o;
    int c;
    name->q = 0;
    for (i = 0, o = (char*)name; i < 16 && (c = s[i]) != 0 && c != '.'; i++)
        *o++ = String_ToLower(c);
    func_003A3430(self, (char*)name);
}
#pragma opt_propagation reset
