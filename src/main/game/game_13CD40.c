#include "types.h"
#pragma cplusplus on

struct N {
    N* left_;
    N* right_;
    N* parent_;
    N* parent() const { return (N*)((unsigned int)parent_ & ~1); }
    bool is_red() const { return bool((unsigned int)parent_ & 1) == true; }
    void set_red() { parent_ = (N*)((unsigned int)parent_ | 1); }
    void set_black() { parent_ = (N*)((unsigned int)parent_ & ~1); }
};

extern "C" void func_0013CF60(N* x, N** root);
extern "C" void func_0013CFF0(N* x, N** root);

extern "C" void func_0013CD40(N* x, N* root)
{
    x->set_red();
    while (x != root && x->parent()->is_red()) {
        N* xpp = x->parent()->parent();
        if (x->parent() == xpp->left_) {
            N* y = xpp->right_;
            if (y != 0 && y->is_red()) {
                x->parent()->set_black();
                y->set_black();
                x = x->parent()->parent();
                x->set_red();
            } else {
                if (x == x->parent()->right_) {
                    x = x->parent();
                    func_0013CF60(x, &root);
                }
                x->parent()->set_black();
                x->parent()->parent()->set_red();
                func_0013CFF0(x->parent()->parent(), &root);
            }
        } else {
            N* y = xpp->left_;
            if (y != 0 && y->is_red()) {
                x->parent()->set_black();
                y->set_black();
                x = x->parent()->parent();
                x->set_red();
            } else {
                if (x == x->parent()->left_) {
                    x = x->parent();
                    func_0013CFF0(x, &root);
                }
                x->parent()->set_black();
                x->parent()->parent()->set_red();
                func_0013CF60(x->parent()->parent(), &root);
            }
        }
    }
    root->set_black();
}

