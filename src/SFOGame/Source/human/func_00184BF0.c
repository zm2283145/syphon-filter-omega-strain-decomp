#include "types.h"
typedef struct { char pad[0x4C]; unsigned char ok; char pad4D[3]; } T_184BF0;
extern T_184BF0 SecondaryStateTable[];
typedef struct { char pad[0x310]; unsigned char a; unsigned char b; } P_184BF0;
typedef struct { char pad[0x3314]; P_184BF0* p; } O_184BF0;static inline T_184BF0* Get_184BF0(int i) { return &SecondaryStateTable[i]; }
int cHuman_IsAimed(O_184BF0* o) { P_184BF0* p = o->p; if (p) { return Get_184BF0(p->a)->ok != 0 && Get_184BF0(p->b)->ok != 0; } return 0; }
