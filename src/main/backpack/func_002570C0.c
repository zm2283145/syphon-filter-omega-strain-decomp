#include "types.h"
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
typedef struct BackpackEntry{char pad[0x60];unsigned char active;}BackpackEntry;
typedef struct BackpackRegistry{int capacity,count;BackpackEntry**items;}BackpackRegistry;
extern BackpackRegistry*D_004F7F30;
void func_00254770(BackpackEntry*);void func_00256D90(void);void func_00170570(void);
static inline int Identity(int n){return n;}
void func_002570C0(void){BackpackRegistry*list=D_004F7F30;int i;for(i=0;i<list->count;i++){int offset=i<<2;int base=(int)list->items;BackpackEntry*p=*(BackpackEntry**)(base+offset);if(!p->active){i--;func_00254770(p);}}func_00256D90();func_00170570();}
