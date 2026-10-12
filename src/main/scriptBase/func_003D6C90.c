#include "types.h"
typedef struct { void* name; char pad0[0x3C]; int next; } PsNode;
extern int String_CompareNoCase(void* a, void* b);
extern PsNode* ScriptType_GetRecord(int idx);
int ScriptType_DerivesFromName(PsNode* n) { do { if (String_CompareNoCase(n->name, "AI") == 0) return 1; if (n->next <= -1) break; } while ((n = ScriptType_GetRecord(n->next)) != 0); return 0; }
