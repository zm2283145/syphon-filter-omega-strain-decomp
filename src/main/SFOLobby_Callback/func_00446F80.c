#include "types.h"

typedef struct { char pad[0x1F8]; int failed; char pad2[0x1920]; char name[0x20]; } NetState;

extern NetState* D_00585E60;
extern int func_004505C0(int a, int b, int c);
extern void memcpy(char* dst, const char* src, int n); /* strncpy */

/* Runs func_004505C0; on failure flags the network state and records the name. */
void func_00446F80(int a, int b, int c, const char* name)
{
    if (!func_004505C0(a, b, c)) {
        D_00585E60->failed = 1;
        memcpy(D_00585E60->name, name, 0x20);
    }
}
