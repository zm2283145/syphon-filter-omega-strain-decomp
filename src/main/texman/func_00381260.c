#include "types.h"
typedef struct { char pad[0x10]; unsigned short h10; } G7S44;
typedef struct { char pad[0x44]; G7S44* p44; char pad2[0x60 - 0x48]; char b60; char b61; } G7Obj;
typedef struct { char pad[8]; G7Obj** arr; int pad2; int count; } G7Mgr;
extern void func_003812D0(G7Mgr* m);
void func_00381260(G7Mgr* m)
{
    int i;
    for (i = 0; i < m->count; i++) {
        if (m->arr[i]) {
            m->arr[i]->b60 = 0;
            if (m->arr[i]->p44->h10 > 0) {
                m->arr[i]->b61 = 0;
            }
        }
    }
    func_003812D0(m);
}