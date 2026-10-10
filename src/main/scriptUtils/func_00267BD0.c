#include "types.h"

typedef struct ScriptArgs2 {
    int a;
    int b;
} ScriptArgs2;

extern int GObj_IdentityB(int handle);
extern float Global_Distance(int a, int b);

/* Script native: Distance(a, b) - returns the float distance as its raw bits. */
int Script_Distance(ScriptArgs2* args) {
    int a = GObj_IdentityB(args->a);
    volatile float dist = Global_Distance(a, GObj_IdentityB(args->b));
    return *(int*)&dist;
}
