#include "types.h"
typedef struct { int id; unsigned char flags; char pad[3]; } E43AB20;
extern E43AB20 *D_00583888;
int cGenInfoObject_GetOwner(int d0, int *arg1) {
    E43AB20 *e;
    E43AB20 *t = D_00583888;
    int key = *arg1;
    if (t != 0) {
        int i = 0;
        E43AB20 *p = t;
        do {
            if (key == p->id) { e = &t[i]; goto found; }
            i++;
            p++;
        } while (i != 0x37);
    }
    e = 0;
found:
    if (e != 0) {
        int v = e->flags & 0xF;
        if (v != 0xF) {
            return v;
        }
    }
    return -1;
}