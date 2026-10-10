#include "types.h"
typedef struct { int unk0; char inl[0x5C]; void* coll; } LosProvider;
/* Returns the external collection if set, else the inline one at +4. */
void* LosProvider_GetCollection(LosProvider* p) { if (p->coll) return p->coll; return p->inl; }
