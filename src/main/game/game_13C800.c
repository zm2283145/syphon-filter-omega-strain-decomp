#pragma cplusplus on

struct RbNode {
    RbNode *left;
    RbNode *right;
    RbNode *pp;

    RbNode *parent() const { return (RbNode *)((unsigned int)pp & ~1); }
    void set_parent(RbNode *p) { pp = (RbNode *)((unsigned int)p | ((unsigned int)pp & 1)); }
    bool red() const { return ((unsigned int)pp & 1) ? true : false; }
    void set_red() { pp = (RbNode *)((unsigned int)pp | 1); }
    void set_black() { pp = (RbNode *)((unsigned int)pp & ~1); }
    void set_color(bool c)
    {
        if (c)
            set_red();
        else
            set_black();
    }
};

#define RED(n) ((unsigned int)(n)->pp & 1 ? true : false)
#define PARENT(n) ((n)->parent())

extern "C" {
void std_red_black_tree_1_increment(RbNode **it);
void std_red_black_tree_1_rotate_left(RbNode *x, RbNode **root);
void std_red_black_tree_1_rotate_right(RbNode *x, RbNode **root);
void std_red_black_tree_1_balance_erase(RbNode *z, RbNode *root);
}

void std_red_black_tree_1_balance_erase(RbNode *z, RbNode *root)
{
    RbNode *y = z;
    RbNode *x;
    RbNode *x_parent;
    bool x_is_left;
    bool rebalance;

    if (z->left != 0 && z->right != 0)
        std_red_black_tree_1_increment(&y);
    {
        RbNode *t = y;
        x = t->left ? t->left : t->right;
        x_parent = t->parent();
    }
    if (x != 0)
        x->set_parent(x_parent);
    if (y == y->parent()->left) {
        y->parent()->left = x;
        x_is_left = true;
    } else {
        y->parent()->right = x;
        x_is_left = false;
    }
    rebalance = y->red() == false;
    if (y != z) {
        y->set_parent(z->parent());
        if (z == y->parent()->left)
            y->parent()->left = y;
        else
            y->parent()->right = y;
        y->left = z->left;
        if (y->left != 0)
            y->left->set_parent(y);
        else
            x_parent = y;
        y->right = z->right;
        if (y->right != 0)
            y->right->set_parent(y);
        else
            x_parent = y;
        y->set_color(z->red());
        if (root == z)
            root = y;
    } else if (x == 0 && z == root) {
        rebalance = false;
    }
    if (rebalance) {
        while (x != root && (x == 0 || !RED(x))) {
            if (x_is_left) {
                RbNode *w = x_parent->right;
                if ((bool)((unsigned int)w->pp & 1) == true) {
                    w->set_black();
                    (x_parent->set_red());
                    std_red_black_tree_1_rotate_left(x_parent, &root);
                    w = x_parent->right;
                }
                if ((w->left == 0 || !RED(w->left)) && (w->right == 0 || !RED(w->right))) {
                    (w->set_red());
                    x = x_parent;
                    x_parent = PARENT(x_parent);
                    x_is_left = x == x_parent->left;
                } else {
                    if (w->right == 0 || !RED(w->right)) {
                        (w->left->set_black());
                        (w->set_red());
                        std_red_black_tree_1_rotate_right(w, &root);
                        w = x_parent->right;
                    }
                    if (RED(x_parent)) w->set_red(); else w->set_black();
                    (x_parent->set_black());
                    (w->right->set_black());
                    std_red_black_tree_1_rotate_left(x_parent, &root);
                    x = root;
                }
            } else {
                RbNode *w = x_parent->left;
                if ((bool)((unsigned int)w->pp & 1) == true) {
                    w->set_black();
                    (x_parent->set_red());
                    std_red_black_tree_1_rotate_right(x_parent, &root);
                    w = x_parent->left;
                }
                if ((w->left == 0 || !RED(w->left)) && (w->right == 0 || !RED(w->right))) {
                    (w->set_red());
                    x = x_parent;
                    x_parent = PARENT(x_parent);
                    x_is_left = x == x_parent->left;
                } else {
                    if (w->left == 0 || !RED(w->left)) {
                        (w->right->set_black());
                        (w->set_red());
                        std_red_black_tree_1_rotate_left(w, &root);
                        w = x_parent->left;
                    }
                    if (RED(x_parent)) w->set_red(); else w->set_black();
                    (x_parent->set_black());
                    (w->left->set_black());
                    std_red_black_tree_1_rotate_right(x_parent, &root);
                    x = root;
                }
            }
        }
        if (x != 0)
            (x->set_black());
    }
}


