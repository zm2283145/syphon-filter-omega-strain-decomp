#include "types.h"
#include "scriptUtils_types.h"

typedef struct OmegaRec {
    int data[8];
} OmegaRec;

extern char D_00532AB0[];
extern void* func_0032FFD0(OmegaRec* out, int a, int zero, int b, int c, int zero2);
extern void func_00147600(void* list, void* rec);

/* Script native: cAgentData::RegisterOmega(a, b, c).
 * volatile mirrors the original stack temporaries. */
int Script_cAgentData__RegisterOmega(ScriptArg* args) {
    OmegaRec rec;
    volatile int slot2;
    volatile int slot1;
    volatile int slot0;
    int v;
    int c;
    int b;

    slot2 = args[2].i;
    v = args[1].i;
    c = slot2;
    slot1 = v;
    v = args[0].i;
    b = slot1;
    slot0 = v;
    func_00147600(D_00532AB0, func_0032FFD0(&rec, slot0, 0, b, c, 0));
    return 0;
}
