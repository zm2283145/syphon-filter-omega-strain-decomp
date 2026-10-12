#include "types.h"
typedef struct { char p0[0x14]; char set[1]; } Mgr32D750;
extern void* func_004147A0(void);
extern Mgr32D750* func_00414790(void);
extern void func_002A88C0(int* it, void* set, int* key);
extern void func_002A88B0(int* it, void* set);
extern int func_002A8890(int* a, int* b);
/* Returns o when it is the root widget or is registered with the manager, else 0. */
void* func_0032D750(void* o)
{
    Mgr32D750* m;
int key[1];
int it[1];
int end[1];
    if (!o) return 0;
    if (o == func_004147A0()) return o;
    key[0] = (int)o;
    m = func_00414790();
    func_002A88C0(it, m->set, key);
    func_002A88B0(end, m->set);
    return func_002A8890(it, end) ? o : 0;
}
