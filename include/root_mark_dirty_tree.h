#ifndef ROOT_MARK_DIRTY_TREE_H
#define ROOT_MARK_DIRTY_TREE_H

/*
 * Root: set the three dirty flags at 0xA0..0xA2, then, when the node has
 * children, walk the child list (out-of-line iterator helpers) and mark
 * each child through func_001912E0. Plain C.
 */
typedef struct RootDirtyIt { void* node; } RootDirtyIt;
typedef struct RootDirtyNode {
    char pad[0xA0];
    unsigned char dirty0;
    unsigned char dirty1;
    unsigned char dirty2;
} RootDirtyNode;

extern int func_001913E0(RootDirtyNode* self);
extern void* func_001913D0(RootDirtyNode* self);
extern RootDirtyIt* func_001913C0(RootDirtyIt* it, void* list);
extern RootDirtyIt* func_001913A0(RootDirtyIt* it, void* list);
extern int func_001912A0(RootDirtyIt* a, RootDirtyIt* b);
extern RootDirtyNode** func_00191390(RootDirtyIt* it);
extern RootDirtyIt* func_001912C0(RootDirtyIt* it);
extern void func_001912E0(RootDirtyNode* self);

#define DEFINE_ROOT_MARK_DIRTY_TREE(name)                                \
    void name(RootDirtyNode* self)                                       \
    {                                                                    \
        RootDirtyIt it;                                                  \
        RootDirtyIt end;                                                 \
        self->dirty0 = 1;                                                \
        self->dirty1 = 1;                                                \
        self->dirty2 = 1;                                                \
        if (func_001913E0(self)) {                                       \
            func_001913C0(&it, func_001913D0(self));                     \
            func_001913A0(&end, func_001913D0(self));                    \
            for (; func_001912A0(&it, &end); func_001912C0(&it))         \
                func_001912E0(*func_00191390(&it));                      \
        }                                                                \
    }

#endif /* ROOT_MARK_DIRTY_TREE_H */