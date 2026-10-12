#pragma cplusplus on
#include "types.h"
typedef struct Node_3B8550 { struct Node_3B8550* left; struct Node_3B8550* right; int pad[2]; char name[0x20]; } Node_3B8550;
typedef struct { int pad; Node_3B8550* root; } Tree_3B8550;
typedef struct { Node_3B8550* node; bool inserted; } Res_3B8550;
extern "C" {
int Name_Compare48(const char* a, const char* b, int n);
Node_3B8550* func_003B99D0(Tree_3B8550* t, Node_3B8550* y, bool comp, bool leftmost, const char* key);
static bool D_00493508 = true;
extern const bool D_00493510;
}
static inline bool Less_3B8550(const char* a, const char* b)
{
    return !(a[0] == 0 && b[0] == 0) && Name_Compare48(a, b, 0x20) < 0;
}
extern "C" void MotionRegistry_MapInsert(Res_3B8550* out, Tree_3B8550* t, const char* key)
{
    Node_3B8550* lb = 0;
    Node_3B8550* y = (Node_3B8550*)&t->root;
    Node_3B8550* x;
    bool comp = true;
    bool leftmost = comp;
    x = t->root;
    while (x != 0) {
        y = x;
        if (Less_3B8550(key, x->name)) {
            x = x->left;
            comp = true;
        } else {
            lb = x;
            x = x->right;
            comp = false;
            leftmost = false;
        }
    }
    if (lb == 0 || Less_3B8550(lb->name, key)) {
        out->node = func_003B99D0(t, y, comp, leftmost, key);
        out->inserted = D_00493508;
    } else {
        out->node = lb;
        out->inserted = D_00493510;
    }
}


