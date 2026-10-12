#include "types.h"
typedef struct { char p[0x48]; char m48[0x30]; void* f78; } W41BE50;
extern void* func_001692D0(void* s);
extern void func_003D08B0(void* o, void* s);
extern void func_0041E040(W41BE50* w, int kind, void* s, int z);
void func_0041BE50(W41BE50* w)
{
    if (w->f78) func_003D08B0(w->f78, func_001692D0(w->m48));
    func_0041E040(w, 0x1C, func_001692D0(w->m48), 0);
}
