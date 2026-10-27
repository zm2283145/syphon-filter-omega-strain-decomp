/*
 * SFOGame/Source/main: 1 file, 0013CD40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin game_13CD40 */
#pragma push /* merge_units */
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

extern "C" void std_red_black_tree_1_rotate_left(N* x, N** root);
extern "C" void std_red_black_tree_1_rotate_right(N* x, N** root);

extern "C" void std_red_black_tree_1_balance_insert(N* x, N* root)
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
                    std_red_black_tree_1_rotate_left(x, &root);
                }
                x->parent()->set_black();
                x->parent()->parent()->set_red();
                std_red_black_tree_1_rotate_right(x->parent()->parent(), &root);
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
                    std_red_black_tree_1_rotate_right(x, &root);
                }
                x->parent()->set_black();
                x->parent()->parent()->set_red();
                std_red_black_tree_1_rotate_left(x->parent()->parent(), &root);
            }
        }
    }
    root->set_black();
}
static inline void merge_flush_game_13CD40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end game_13CD40 */
