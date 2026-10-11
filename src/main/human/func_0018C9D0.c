#include "types.h"
#include "canonical_key_copy.h"
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Name_18C9D0;
typedef struct { int n; } It_18C9D0;
typedef struct { char pad[0x24]; int tree; } Map_18C9D0;
typedef struct { char pad[0x2EC0]; Map_18C9D0* map; char pad2[0x34E4 - 0x2EC4]; int slot[1]; } O_18C9D0;
extern void func_0018C740(It_18C9D0* out, int* tree, Name_18C9D0* key);
extern void func_0018C730(It_18C9D0* out, int* tree);
extern int func_0018C710(It_18C9D0* a, It_18C9D0* b);
extern int* func_0018C700(It_18C9D0* a);
#pragma push
#pragma opt_common_subs off
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
void func_0018C9D0(O_18C9D0* o, char* name, unsigned char idx)
{
    It_18C9D0 it;
    It_18C9D0 end;
    Name_18C9D0 buf;
    Map_18C9D0* m = o->map;
    int v;
    CANONICAL_KEY_INIT(buf.c, name)
    func_0018C740(&it, &m->tree, (Name_18C9D0*)(int)&buf);
    func_0018C730(&end, &m->tree);
    if (func_0018C710(&it, &end)) { asm { .set reorder } v = *func_0018C700(&it); } else v = 0;
    o->slot[idx] = v;
}
#pragma pop
