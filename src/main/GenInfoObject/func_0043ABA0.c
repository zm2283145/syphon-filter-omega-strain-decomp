#include "types.h"
#include "net_local_id.h"
typedef struct { int id; unsigned char lo : 4; unsigned char hi : 4; char pad[3]; } Ent_ABA0;
extern Ent_ABA0* D_00583888;
static inline Ent_ABA0* Find_ABA0(int k)
{
    Ent_ABA0* t = D_00583888;
    if (t) {
        int i;
        for (i = 0; i != 0x37; i++)
            if (k == t[i].id) return &t[i];
    }
    return 0;
}
#pragma inline_depth(10)
static inline int Resolve_ABA0(int i)
{
    if (i == -1) return NetLocalId();
    return i;
}
int func_0043ABA0(void* self, int* key, int idx)
{
    Ent_ABA0* e;
    if (idx > 4) return 0;
    e = Find_ABA0(*key);
    if (e) {
        idx = Resolve_ABA0(idx);
        return (e->hi & (1 << idx)) != 0;
    }
    return 0;
}
