#include "types.h"
typedef struct { char pad[0x20]; void* inst; } P425E20;
typedef struct { char pad[0x90]; P425E20* peer; void* inst; } T425E20;
extern void* func_00414790(void);
extern void* func_00418420(void* a, int b);
extern char* func_0036A2F0(void* i);
extern void func_00424820(T425E20* t, void* p);
void func_00425E20(T425E20* t, int a) {
    t->inst = func_00418420(func_00414790(), a);
    if (t->inst) {
        { char* p = func_0036A2F0(t->inst) + 4; func_00424820(t, p); }
        if (t->peer) t->peer->inst = t->inst;
    }
}