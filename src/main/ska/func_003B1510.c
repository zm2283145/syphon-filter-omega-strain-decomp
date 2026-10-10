#include "types.h"
typedef struct { char pad[0xC]; unsigned char flag; } S;
extern void func_003B1560(S*);
extern void func_003B7A50(S*, int);
/* Constructor: base init, sets value from *v, stores flag. */
S* func_003B1510(S* s, int* v, unsigned char flag) { func_003B1560(s); func_003B7A50(s, *v); s->flag = flag; return s; }
