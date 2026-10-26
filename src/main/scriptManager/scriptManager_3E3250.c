#include "types.h"
#pragma cplusplus on
#include "tree_insert_unique_kt.h"

struct std_tree_pair_int_value_compare_insert_one_pairR_N { std_tree_pair_int_value_compare_insert_one_pairR_N* left; std_tree_pair_int_value_compare_insert_one_pairR_N* right; unsigned int parentAndColor; int key; };
struct std_tree_pair_int_value_compare_insert_one_pairR_T { unsigned int count; std_tree_pair_int_value_compare_insert_one_pairR_N* root; };
struct std_tree_pair_int_value_compare_insert_one_pairR_P { std_tree_pair_int_value_compare_insert_one_pairR_N* it; bool ok; };
extern "C" {
static const unsigned int dat_00493900[2] = { 0x1, 0x0 };
static const unsigned int dat_00493908[2] = { 0x0, 0x0 };
std_tree_pair_int_value_compare_insert_one_pairR_N* std_tree_pair_int_value_compare_insert_node_at_nodeP_bool_bool_pairR_2(std_tree_pair_int_value_compare_insert_one_pairR_T* t, std_tree_pair_int_value_compare_insert_one_pairR_N* parent, bool left, bool first,
                 const int* v);
}
extern "C" void std_tree_pair_int_value_compare_insert_one_pairR(std_tree_pair_int_value_compare_insert_one_pairR_P* ret, std_tree_pair_int_value_compare_insert_one_pairR_T* t, const int* v)
{
    bool left = true;
    bool first = left;
    std_tree_pair_int_value_compare_insert_one_pairR_N* y = 0;
    std_tree_pair_int_value_compare_insert_one_pairR_N* parent = (std_tree_pair_int_value_compare_insert_one_pairR_N*)&t->root;
    std_tree_pair_int_value_compare_insert_one_pairR_N* x = t->root;
    while (x) {
        parent = x;
        if (*v < x->key) {
            x = x->left;
            left = true;
        } else {
            y = x;
            x = x->right;
            left = false;
            first = false;
        }
    }
    if (!y || y->key < *v) {
        ret->it = std_tree_pair_int_value_compare_insert_node_at_nodeP_bool_bool_pairR_2(t, parent, left, first, v);
        ret->ok = (*(bool*)dat_00493900);
    } else {
        ret->it = y;
        ret->ok = (*(bool*)dat_00493908);
    }
}
