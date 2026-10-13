#include "types.h"
typedef struct { char pad[0x14C]; unsigned char on; char p1[3]; unsigned int idx; char* cur; char p2[4]; char* base; } SL36D2;
#pragma opt_rotateloops off
char* Archive_GetMemberName(SL36D2* p, int n) {
    int i;
    char* s;
    char* r;
    if (!p->on) return 0;
    s = p->base;
    i = 0;
    if (!(n < p->idx)) { s = p->cur; i = p->idx; }
    while (i < n) { while (*s++) ; i++; }
    p->idx = i;
    r = s;
    while (*s++) ;
    p->cur = r;
    return p->cur;
}
#pragma opt_rotateloops reset