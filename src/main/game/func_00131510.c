#include "types.h"

typedef struct Pending {
    char pad[0xD4];
    int arg;
    unsigned char pending;
} Pending;

extern void ActiveList_RemoveObject(Pending*, int);

/* If the pending flag is set, clears it and calls ActiveList_RemoveObject(self, arg). */
void World_PopObject(Pending* p) {
    if (p->pending) {
        p->pending = 0;
        ActiveList_RemoveObject(p, p->arg);
    }
}
