typedef struct Node_7E0 {
    struct Node_7E0* left;
    struct Node_7E0* right;
    int color;
    int val;
} Node_7E0;

void* func_00430A40(void* t);
void* func_00430A20(void* t);
void func_00430A30(void* a, int* v);
void func_00430A10(void* a, Node_7E0* n, int count);
void operator_delete(void* p);
void func_004307E0(void* t, Node_7E0* n);

static inline void Leaf_7E0(void* t, Node_7E0* g)
{
    if (g->left)
        func_004307E0(t, g->left);
    if (g->right)
        func_004307E0(t, g->right);
    func_00430A30(func_00430A40(t), &g->val);
    func_00430A10(func_00430A20(t), g, 1);
}

static inline void Mid_7E0(void* t, Node_7E0* c)
{
    Node_7E0* g;
    if ((g = c->left) != 0)
        Leaf_7E0(t, g);
    if ((g = c->right) != 0)
        Leaf_7E0(t, g);
    func_00430A40(t);
    func_00430A20(t);
    operator_delete(c);
}

void func_004307E0(void* t, Node_7E0* n)
{
    Node_7E0* c;
    if ((c = n->left) != 0)
        Mid_7E0(t, c);
    if ((c = n->right) != 0)
        Mid_7E0(t, c);
    operator_delete(n);
}
