#include "types.h"
extern int strlen(char*);
#pragma opt_rotateloops off
char* func_0032D7E0(char* s) {
    int n;
    while (!((*s != 0) ^ 1) && (unsigned char)*s <= ' ') s++;
    n = strlen(s) - 1;
    while (n >= 0 && (unsigned char)s[n] <= ' ') { s[n] = 0; n--; }
    return s;
}
#pragma opt_rotateloops reset