#include "types.h"
typedef struct { int pad[3]; int key; } Node2501;
typedef struct { Node2501* node; int key; } Ref2501;
Node2501* func_002501B0(Ref2501* r) {
    Node2501* n = r->node;
    unsigned char ok = 1;
    int z = (n != 0) ^ 1;
    if (!z && n->key != r->key) ok = 0;
    return ok ? n : 0;
}
