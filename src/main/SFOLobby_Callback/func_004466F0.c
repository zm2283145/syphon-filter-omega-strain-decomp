#include "types.h"
typedef struct { char pad[0x18]; int v; } Info18;
typedef struct { char pad[0x238]; int failed; int pad2; int empty; } Globals;
extern Globals* D_00585E60;
extern int func_004505C0(void* a, void* b, void* c, Info18* d);
/* Runs the check and records failure state in the globals. */
void func_004466F0(void* a, void* b, void* c, Info18* d)
{
    if (!func_004505C0(a, b, c, d)) {
        D_00585E60->failed = 1;
        D_00585E60->empty = d->v == 0;
    }
}
