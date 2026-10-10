#include "types.h"
typedef struct C4Node1BA { struct C4Node1BA* left; struct C4Node1BA* right; int pad[2]; char name[0x20]; } C4Node1BA;
typedef struct { int pad; C4Node1BA header; } C4Tree1BA;
extern int Name_Compare48(const char* a, const char* b, int n);
static inline int c4less(const char* a, const char* b) {
    return !(a[0] == 0 && b[0] == 0) && Name_Compare48(a, b, 0x20) < 0;
}
void func_001BADD0(C4Node1BA** out, C4Tree1BA* t, const char* key) {
    C4Node1BA* x = t->header.left;
    C4Node1BA* y = &t->header;
    while (x) {
        if (!c4less(x->name, key)) {
            y = x;
            x = x->left;
        } else {
            x = x->right;
        }
    }
    if (y == &t->header || c4less(key, y->name)) {
        *out = &t->header;
    } else {
        *out = y;
    }
}