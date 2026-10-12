#pragma cplusplus on
#include "types.h"
typedef struct Node_3B83D0 { struct Node_3B83D0* left; struct Node_3B83D0* right; int pad[2]; char name[0x30]; } Node_3B83D0;
typedef struct { int pad; Node_3B83D0* root; } Tree_3B83D0;
typedef struct { Node_3B83D0* node; bool inserted; } Res_3B83D0;
extern "C" {
int Name_Compare48(const char* a, const char* b, int n);
Node_3B83D0* func_003B9840(Tree_3B83D0* t, Node_3B83D0* y, bool comp, bool leftmost, const char* key);
extern const bool D_00493518;
extern const bool D_00493520;
}
static inline bool Less_3B83D0(const char* a, const char* b)
{
    return !(a[0] == 0 && b[0] == 0) && Name_Compare48(a, b, 0x30) < 0;
}
extern "C" void func_003B83D0(Res_3B83D0* out, Tree_3B83D0* t, const char* key)
{
    Node_3B83D0* lb = 0;
    Node_3B83D0* y = (Node_3B83D0*)&t->root;
    Node_3B83D0* x;
    bool comp = true;
    bool leftmost = comp;
    x = t->root;
    while (x != 0) {
        y = x;
        if (Less_3B83D0(key, x->name)) {
            x = x->left;
            comp = true;
        } else {
            lb = x;
            x = x->right;
            comp = false;
            leftmost = false;
        }
    }
    if (lb == 0 || Less_3B83D0(lb->name, key)) {
        out->node = func_003B9840(t, y, comp, leftmost, key);
        out->inserted = D_00493518;
    } else {
        out->node = lb;
        out->inserted = D_00493520;
    }
}

