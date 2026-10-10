#include "types.h"
typedef struct { char pad[0x60]; unsigned char a; unsigned char b; } BAE50Item;
typedef struct { int pad[2]; BAE50Item** items; } BAE50Tbl;
typedef struct { int i0; int i1; } BAE50Pair;
extern BAE50Tbl* D_00539248;
int func_003BAE50(BAE50Pair* p) {
    BAE50Item** arr = D_00539248->items;
    int r = (arr[p->i0]->a & arr[p->i0]->b) != 0;
    if (p->i1 != -1) {
        unsigned char res = 0;
        if (r) {
            if (arr[p->i1]->a & arr[p->i1]->b) res = 1;
        }
        r = res;
    }
    return r;
}