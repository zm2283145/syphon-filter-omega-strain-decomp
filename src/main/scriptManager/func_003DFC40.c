#pragma bool off
#include "types.h"

typedef struct ResNodeE6 {
    char pad[0x10];
    int* timer;
} ResNodeE6;

typedef struct ResIterE6 { ResNodeE6* node; } ResIterE6;

extern char D_0055A0F0[];
extern void func_003E2EE0(ResIterE6* out, void* map, int* key);
extern void func_003DFAF0(ResIterE6* out, void* map);
extern void func_003DFAE0(ResIterE6* out, ResIterE6* in);

static inline int IsZeroE6(int x) { return x == 0; }
static inline int IterE6_Ne(ResNodeE6* a, ResNodeE6* b) { return (a == b) ^ 1; }

/* Reschedules a registered script timer to fire after the given seconds. */
void Script_Reschedule_3DFC40(int id, float seconds)
{
    ResIterE6 cend;
    ResIterE6 it;
    ResIterE6 end;
    int key[1];
    ResNodeE6* node;
    key[0] = id;
    func_003E2EE0(&it, D_0055A0F0, key);
    node = it.node;
    func_003DFAF0(&end, D_0055A0F0);
    func_003DFAE0(&cend, &end);
    if (IterE6_Ne(node, cend.node)) {
        *node->timer = (int)(1000.0f * seconds);
    }
}