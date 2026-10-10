#include "types.h"
extern long func_0012AF90(const char* s, char** end, int base);
/* atoi: strtol(s, NULL, 10). */
int func_00121BC8(const char* s)
{
    return (int)func_0012AF90(s, 0, 10);
}
