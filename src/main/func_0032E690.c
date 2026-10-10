#include "types.h"

typedef struct CommendationArgs {
    int a0, a1, a2, a3, a4;
} CommendationArgs;

/* Temporary commendation record built on the stack. */
typedef struct Commendation {
    char data[0x1C];
} Commendation;

extern char D_00532A80[]; /* agent data registry */
extern int func_0032FFD0(Commendation* rec, int a0, int a1, int a2, int a3, int a4);
extern void func_00147600(void* registry, int rec);

/* Script native: cAgentData._RegisterCommendation(a0, a1, a2, a3, a4). */
int Script_cAgentData__RegisterCommendatio_2(CommendationArgs* args) {
    Commendation rec;
    int v4, v3, v2, v1, v0;
    volatile int w4, w3, w2, w1, w0;
    w4 = args->a4;
    v4 = w4;
    w3 = args->a3;
    v3 = w3;
    w2 = args->a2;
    v2 = w2;
    w1 = args->a1;
    v1 = w1;
    w0 = args->a0;
    v0 = w0;
    func_00147600(D_00532A80, func_0032FFD0(&rec, v0, v1, v2, v3, v4));
    return 0;
}
