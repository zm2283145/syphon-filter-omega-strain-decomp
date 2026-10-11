#include "types.h"
typedef struct { char pad[0x40]; int value; } Node_18A670;
typedef struct { Node_18A670* n; } It_18A670;
typedef struct { char pad[0x24]; int tree; } Map_18A670;
extern void Tree_Compare(It_18A670* out, int* tree, int key);
extern void func_0018A6F0(It_18A670* out, int* tree);
extern void func_0018A6E0(It_18A670* out, It_18A670* in);
int NodeNameMap_Find(Map_18A670* m, int key)
{
    It_18A670 c;
    It_18A670 f;
    It_18A670 e;
    Node_18A670* n;
    Tree_Compare(&f, &m->tree, key);
    n = f.n;
    func_0018A6F0(&e, &m->tree);
    func_0018A6E0(&c, &e);
    if (n == c.n) return 0;
    return n->value;
}

