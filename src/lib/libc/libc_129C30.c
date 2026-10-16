/*
 * lib/libc: 2 files, 00129C30-00129C80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00129C30 */
#include "types.h"
char* strrchr(const char* s, int i)
{
    const char* last = 0;
    char c = i;
    while (*s) {
        if (*s == c)
            last = s;
        s++;
    }
    if (*s == c)
        return (char*)s;
    return (char*)last;
}
/* merge_units: end func_00129C30 */

/* merge_units: begin func_00129C80 */
char* strstr(const char* searchee, const char* lookfor)
{
    if (*searchee == 0) {
        if (*lookfor) return (char*)0;
        return (char*)searchee;
    }
    while (*searchee) {
        unsigned int i;
        i = 0;
        while (1) {
            if (lookfor[i] == 0) return (char*)searchee;
            if (lookfor[i] != searchee[i]) break;
            i++;
        }
        searchee++;
    }
    return (char*)0;
}
/* merge_units: end func_00129C80 */
