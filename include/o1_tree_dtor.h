#ifndef O1_TREE_DTOR_H
#define O1_TREE_DTOR_H

/*
 * Optimization-level-1 deleting destructor of a tree container: clear it,
 * and when the header node is set, free the nodes through
 * freeFn(rootFn(self), *headerFn(self), *endFn(self)); then delete when
 * deleteFlag > 0. Wrap the use in #pragma optimization_level 1 / reset.
 */
extern void operator_delete(void* p);

#define DEFINE_O1_TREE_DTOR(name, clearFn, headerFn, rootFn, endFn, freeFn)   \
    extern void clearFn(void* self);                                          \
    extern void** headerFn(void* self);                                       \
    extern void* rootFn(void* self);                                          \
    extern void** endFn(void* self);                                          \
    extern void freeFn(void* a, void* b, void* c);                            \
    void* name(void* self, short deleteFlag)                                  \
    {                                                                         \
        if (self) {                                                           \
            clearFn(self);                                                    \
            if (*headerFn(self))                                              \
                freeFn(rootFn(self), *headerFn(self), *endFn(self));          \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* O1_TREE_DTOR_H */