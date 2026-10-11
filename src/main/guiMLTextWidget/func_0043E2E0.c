#include "types.h"
typedef struct { char pad[0x64]; int start; int pos; int pad6C; int end; int pad74; int pad78; void* target; } O3E2E0;
extern void func_0041EFA0(O3E2E0* s, float x);
extern void func_0043BC70(void* t, int a, int pos, int b, int len);
void func_0043E2E0(O3E2E0* s, float x) {
    func_0041EFA0(s, x);
    if (s->target)
        func_0043BC70(s->target, 0, s->pos, 0, s->end - s->start);
}