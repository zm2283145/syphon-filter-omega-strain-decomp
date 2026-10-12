#include "types.h"
typedef struct { void* name; char pad0[0x3C]; int next; } PsNode;
extern int String_CompareNoCase(void* a, void* b);
extern PsNode* func_003D7590(int idx);
int func_003D6C90(PsNode* n) { do { if (String_CompareNoCase(n->name, "AI") == 0) return 1; if (n->next <= -1) break; } while ((n = func_003D7590(n->next)) != 0); return 0; }
