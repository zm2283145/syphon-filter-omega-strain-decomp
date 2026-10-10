#include "types.h"
typedef struct { void* name; char pad0[0x3C]; int next; } PsNode;
extern char D_004BD3C0[];
extern int func_00128E80(void* a, void* b);
extern PsNode* func_003D7590(int idx);
int func_003D6C90(PsNode* n) { do { if (func_00128E80(n->name, D_004BD3C0) == 0) return 1; if (n->next <= -1) break; } while ((n = func_003D7590(n->next)) != 0); return 0; }
