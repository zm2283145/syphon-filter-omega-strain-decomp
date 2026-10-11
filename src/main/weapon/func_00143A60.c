#include "types.h"
typedef struct { int a0; int a4; int id; int ac; } E3A60;
typedef struct { E3A60 e[8]; char pad[4]; unsigned char cur; } S3A60;
extern int func_00143BC0(S3A60* self);
extern void func_00143C50(S3A60* self);
extern void func_00142C50(S3A60* self, unsigned char slot, int a, unsigned char prev);
extern void func_00142BB0(S3A60* self, char slot, int a, unsigned char prev);
#pragma opt_rotateloops off
#pragma opt_propagation off
void func_00143A60(S3A60* self, int wrap)
{
    unsigned char cur;
    int i;
    unsigned char stop;
    int one;
    if (func_00143BC0(self)) {
        cur = self->cur;
        if (cur == 6) {
            func_00143C50(self);
            return;
        }
        i = cur + 1;
        stop = wrap ? 6 : *(char*)&self->cur;
        one = 1;
        while (i != stop && (i == one || self->e[i].id == -1 || i == 6)) {
            i++;
            if (!wrap && i >= 6)
                i = 0;
        }
        if (i != cur && i != 6) {
            func_00142C50(self, i, one, cur);
            return;
        }
        if (wrap)
            func_00142BB0(self, *(char*)&self->cur, one, cur);
    }
}
#pragma opt_rotateloops reset
#pragma opt_propagation reset
