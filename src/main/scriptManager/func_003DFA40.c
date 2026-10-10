#include "types.h"

typedef struct ScriptEvent {
    char pad00[0xC];
    int a;        /* 0x0C */
    int b;        /* 0x10 */
    int script;   /* 0x14 */
    int c;        /* 0x18 */
    int key;      /* 0x1C */
} ScriptEvent;

extern char D_00555070[];
extern char D_0055A0F0[];
extern void ScriptEvent_Replay(void* sched, int script, int a, int b, int c);
extern void func_003E2EE0(int* outIt, void* map, int* key);
extern void func_003DFAF0(int* outEnd, void* map);
extern void func_003DFAE0(int* out, int* end);
extern void func_003E3160(void* map, int* it);

/* Runs the event and removes it from the pending-event map. */
void ScriptEvent_Execute(ScriptEvent* ev) {
    int endRaw;
    int eraseIt;
    int found;
    int end;
    int it;
    ScriptEvent_Replay(D_00555070, ev->script, ev->a, ev->b, ev->c);
    func_003E2EE0(&found, D_0055A0F0, &ev->key);
    it = found;
    func_003DFAF0(&endRaw, D_0055A0F0);
    func_003DFAE0(&end, &endRaw);
    if ((it == end) ^ 1) {
        eraseIt = it;
        func_003E3160(D_0055A0F0, &eraseIt);
    }
}
