#include "types.h"
typedef struct { int x0; int* args; char pad[0x44]; } SrvCtx;
typedef struct { char pad[0x14]; void* init; unsigned char pending; char pad19[3]; void* owner; } SrvVar;
typedef struct { int x0; int count; SrvVar** vars; } SrvScript;
extern char D_004BD4D8[];
extern char D_00555070[];
extern void func_003D5EB0(SrvCtx*, void*, SrvScript*, void*);
extern void func_003E03F0(void*, void*);
extern void Script_Interpret(void*, SrvCtx*);
extern void func_003D5DD0(SrvCtx*, int);
#pragma opt_strength_reduction off
void Script_RunVarInitializers(SrvScript* s)
{
    int n = s->count;
    int i;
    for (i = 0; i < n; i++) {
        SrvVar* v = s->vars[i];
        if (v && v->pending && v->owner == s) {
            void* init;
            init = v->init;
            v->pending = 0;
            if (init) {
                SrvCtx ctx;
                int arg[1];
                func_003D5EB0(&ctx, D_004BD4D8, s, init);
                arg[0] = 4;
                ctx.args = arg;
                func_003E03F0(D_00555070, init);
                Script_Interpret(D_00555070, &ctx);
                func_003D5DD0(&ctx, -1);
            }
        }
    }
}
#pragma opt_strength_reduction reset
