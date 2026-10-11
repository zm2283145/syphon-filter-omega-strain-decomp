
#include "types.h"
/* Script_CallHandler */
typedef struct { int type; } Pt2_ArgType;
typedef struct { char* name; char pad4[0xC]; Pt2_ArgType** argTypes; char pad14[4]; int script; int (*native)(int*, int); } Pt2_Handler;
typedef struct { char pad[0x4E68]; int cur; } Pt2_Interp;
extern char D_004BD510[];
extern void ScriptStack_Push(Pt2_Interp*, int);
extern int Script_Interpret(Pt2_Interp*, Pt2_Handler*);
extern void Script_InvalidArgNop(Pt2_Interp*, char*, int, char*);

#pragma opt_strength_reduction off
int Script_CallHandler(Pt2_Interp* in, Pt2_Handler* h, int* args, int n) {
    int i;
    int* a;
    if (h->script) {
        for (i = 0; i < n; i++) ScriptStack_Push(in, args[n - i - 1]);
        in->cur = h->script;
        return Script_Interpret(in, h);
    }
    i = 0;
    if (i < n) {
        a = args;
        do {
            if (h->argTypes[i]->type >= 100 && *a < 1000) {
                Script_InvalidArgNop(in, D_004BD510, i, h->name);
                return 0;
            }
            i++;
            a++;
        } while (i < n);
    }
    return h->native(args, n);
}
