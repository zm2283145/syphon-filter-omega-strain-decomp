#ifndef FAM5_CONTAINER_ASSIGN_H
#define FAM5_CONTAINER_ASSIGN_H
/*
 * Container assign from another container through out-of-line iterator helpers:
 *   dst.reserve(src.size()); dst.clear();
 *   for (it = src.begin(), e = src.end(); it != e; ++it) dst.push_back(*it);
 * The loop is entered through its bottom test: wrap the instance in
 * #pragma opt_rotateloops off / reset.
 *   DEFINE_CONTAINER_ASSIGN(name, size, reserve, clear, begin, end, ne, deref, push, inc)
 */
#define DEFINE_CONTAINER_ASSIGN(name, size, reserve, clear, begin, end, ne, deref, push, inc) \
    extern int ne(int*, int*);                                                       \
    extern void inc(int*);                                                           \
    extern void push(int, int);                                                      \
    extern int* deref(int*);                                                         \
    extern void end(int*, int);                                                      \
    extern void begin(int*, int);                                                    \
    extern void clear(int);                                                          \
    extern void reserve(int, int);                                                   \
    extern int size(int);                                                            \
    void name(int src, int dst)                                                      \
    {                                                                                \
        int it[1];                                                                   \
        int e[1];                                                                    \
        reserve(dst, size(src));                                                     \
        clear(dst);                                                                  \
        begin(it, src);                                                              \
        end(e, src);                                                                 \
        while (ne(it, e)) {                                                          \
            push(dst, *deref(it));                                                   \
            inc(it);                                                                 \
        }                                                                            \
    }
#endif