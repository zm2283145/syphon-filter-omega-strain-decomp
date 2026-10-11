#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_0041D8C0(void);
typedef struct { char pad[0x10]; int idx; char pad2[0x7C]; int tab[1]; } S456;
int func_00456A60(S456 *p) {
    int i = p->idx;
    if (i != -1) {
        int r = p->tab[i];
        p->idx = -1;
        return r;
    }
    return func_0041D8C0();
}
