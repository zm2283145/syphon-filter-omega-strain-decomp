#ifndef ITER_RETURN_COPY_H
#define ITER_RETURN_COPY_H

/*
 * One-pointer iterator getters (begin()/end() of list-like containers)
 * shared by identical clones: build the iterator in a temporary, copy it
 * (4-byte struct copy, done through an FPR), store it to the result.
 *   DEFINE_ITER_END(name)    iterator(&c->header)  (address of +4)
 *   DEFINE_ITER_BEGIN(name)  iterator(c->first)    (value at +8)
 * Plain C.
 */
typedef struct IterRet {
    void* node;
} IterRet;

typedef struct IterContainer {
    int count;
    void* header;
    void* first;
} IterContainer;

#define DEFINE_ITER_END(name)                                                 \
    void name(IterRet* out, IterContainer* c)                                 \
    {                                                                         \
        IterRet a;                                                            \
        IterRet b;                                                            \
        a.node = &c->header;                                                  \
        b = a;                                                                \
        out->node = b.node;                                                   \
    }

#define DEFINE_ITER_BEGIN(name)                                               \
    void name(IterRet* out, IterContainer* c)                                 \
    {                                                                         \
        IterRet a;                                                            \
        IterRet b;                                                            \
        a.node = c->first;                                                    \
        b = a;                                                                \
        out->node = b.node;                                                   \
    }

#endif /* ITER_RETURN_COPY_H */