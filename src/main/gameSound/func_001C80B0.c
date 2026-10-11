#include "types.h"
typedef struct { char pad[0xC]; unsigned char on; } S1C80B0;
extern void func_003A7FB0(int);
extern void func_003A7F80(int);
void func_001C80B0(S1C80B0* s) { if (s->on) func_003A7FB0(2); else func_003A7F80(2); }