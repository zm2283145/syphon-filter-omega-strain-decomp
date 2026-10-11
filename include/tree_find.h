#ifndef TREE_FIND_H
#define TREE_FIND_H

/*
 * Red-black tree find(key) shared by identical template clones (one per
 * translation unit): lower-bound walk from the root (+4) with the key
 * compare function (key at node +0xC), then return end (the header at
 * tree +4) unless the found node's key equals the search key.
 * The iterator is returned by value (hidden result pointer).
 * C++ only (#pragma cplusplus on before including).
 */
struct TreeFindNode {
    TreeFindNode* left;
    TreeFindNode* right;
    int parentAndColor;
    int key;
};

struct TreeFindTree {
    int count;
    TreeFindNode* root;
};

struct TreeFindIter {
    TreeFindNode* node;
    TreeFindIter(TreeFindNode* n) : node(n) {}
};

#define DEFINE_TREE_FIND(name, compareFn)                                     \
    extern "C" int compareFn(const void* a, const void* b);                   \
    static inline bool name##_less(const void* a, const void* b)              \
    {                                                                         \
        bool r = compareFn(a, b) < 0;                                         \
        return r;                                                             \
    }                                                                         \
    extern "C" TreeFindIter name(TreeFindTree* tree, const void* key)         \
    {                                                                         \
        TreeFindNode* x = tree->root;                                         \
        TreeFindNode* y = (TreeFindNode*)&tree->root;                         \
        while (x) {                                                           \
            bool lt = compareFn(&x->key, key) < 0;                            \
            if (!lt) {                                                        \
                y = x;                                                        \
                x = x->left;                                                  \
            } else                                                            \
                x = x->right;                                                 \
        }                                                                     \
        if (y == (TreeFindNode*)&tree->root || name##_less(key, &y->key))     \
            return TreeFindIter((TreeFindNode*)&tree->root);                  \
        return TreeFindIter(y);                                               \
    }

#endif /* TREE_FIND_H */