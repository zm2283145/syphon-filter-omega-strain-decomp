#ifndef INT_MAP_SUBSCRIPT_H
#define INT_MAP_SUBSCRIPT_H

/*
 * map<int, V>::operator[](key) shared by template clones: walk the tree
 * (root at +4) remembering the insert parent and side, then either return
 * the existing node's value or insert a default-initialised pair through
 * insertFn(tree, parent, left, left2, &pair).
 *
 *   DEFINE_INT_MAP_SUBSCRIPT(name, P, insertFn, INIT)
 * P is the caller's pair typedef (first member `int key`); INIT fills the
 * non-key members of the local `v`.
 */
#define DEFINE_INT_MAP_SUBSCRIPT(name, P, insertFn, INIT)                     \
    typedef struct name##_Node {                                              \
        struct name##_Node* left;                                             \
        struct name##_Node* right;                                            \
        struct name##_Node* parent;                                           \
        P kv;                                                                 \
    } name##_Node;                                                            \
    typedef struct { int m0; name##_Node* root; } name##_Tree;                \
    extern name##_Node* insertFn(name##_Tree* t, name##_Node* p,              \
                                 unsigned char left, unsigned char left2,     \
                                 P* v);                                       \
    P* name(name##_Tree* t, const int* key)                                   \
    {                                                                         \
        unsigned char left = 1;                                               \
        name##_Node* y = 0;                                                   \
        name##_Node* x = t->root;                                             \
        name##_Node* p = (name##_Node*)&t->root;                              \
        unsigned char l2 = left;                                              \
        while (x) {                                                           \
            p = x;                                                            \
            if (*key < x->kv.key) {                                           \
                x = x->left;                                                  \
                left = 1;                                                     \
            } else {                                                          \
                y = x;                                                        \
                x = x->right;                                                 \
                left = 0;                                                     \
                l2 = 0;                                                       \
            }                                                                 \
        }                                                                     \
        if (y == 0 || y->kv.key < *key) {                                     \
            P v;                                                              \
            v.key = *key;                                                     \
            INIT;                                                             \
            return &insertFn(t, p, left, l2, &v)->kv;                         \
        }                                                                     \
        return &y->kv;                                                        \
    }

#endif /* INT_MAP_SUBSCRIPT_H */