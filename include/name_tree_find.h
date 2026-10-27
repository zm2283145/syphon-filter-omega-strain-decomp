#ifndef NAME_TREE_FIND_H
#define NAME_TREE_FIND_H

/*
 * Red-black tree find(key) for a 48-byte name key (at node +0x10) with a
 * less-than that treats two empty names as equal and otherwise uses
 * Libc_Memcmp. Identical template clones; the iterator is returned
 * through the hidden result pointer, end() is the header at tree +4.
 * C++ only (#pragma cplusplus on before including).
 */
struct NameTreeNode {
    NameTreeNode* left;
    NameTreeNode* right;
    int parentAndColor;
    int pad;
    char key[0x30];
};

struct NameTree {
    int count;
    NameTreeNode* root;
};

struct NameTreeIter {
    NameTreeNode* node;
    NameTreeIter(NameTreeNode* n) : node(n) {}
};

extern "C" int Libc_Memcmp(const char* a, const char* b, int n);

static inline bool NameTree_Empty(const char* s)
{
    return s[0] == 0;
}

static inline bool NameTree_Less(const char* a, const char* b)
{
    bool r = !(NameTree_Empty(a) && NameTree_Empty(b)) &&
             Libc_Memcmp(a, b, 0x30) < 0;
    return r;
}

#define DEFINE_NAME_TREE_FIND(name)                                           \
    extern "C" NameTreeIter name(NameTree* tree, const char* key)             \
    {                                                                         \
        NameTreeNode* x = tree->root;                                         \
        NameTreeNode* y = (NameTreeNode*)&tree->root;                         \
        while (x) {                                                           \
            bool lt = NameTree_Less(x->key, key);                             \
            if (!lt) {                                                        \
                y = x;                                                        \
                x = x->left;                                                  \
            } else                                                            \
                x = x->right;                                                 \
        }                                                                     \
        if (y == (NameTreeNode*)&tree->root || NameTree_Less(key, y->key))    \
            return NameTreeIter((NameTreeNode*)&tree->root);                  \
        return NameTreeIter(y);                                               \
    }

#endif /* NAME_TREE_FIND_H */