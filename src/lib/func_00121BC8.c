#include "types.h"
extern long strtol(const char* s, char** end, int base);
/* atoi: strtol(s, NULL, 10). */
int atoi(const char* s)
{
    return (int)strtol(s, 0, 10);
}
