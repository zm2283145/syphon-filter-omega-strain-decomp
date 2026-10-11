#ifndef PTR_COPY_LOOP_H
#define PTR_COPY_LOOP_H

/*
 * Copy every element of one pointer container into another through the
 * out-of-line container helpers (template clones, one set per type):
 *   dst.reserve(src.size()); dst.clear();
 *   for (it = src.begin(); it != src.end(); ++it) dst.push_back(*it);
 * DEFINE_PTR_COPY_LOOP(name, sizeFn, reserveFn, clearFn, beginFn, endFn,
 *                      derefFn, pushFn, incFn, neFn)
 */
typedef struct PtrCopyIter {
    void** p;
} PtrCopyIter;

#define DEFINE_PTR_COPY_LOOP(name, sizeFn, reserveFn, clearFn, beginFn,      \
                             endFn, derefFn, pushFn, incFn, neFn)             \
    extern int sizeFn(void* src);                                             \
    extern void reserveFn(void* dst, int n);                                  \
    extern void clearFn(void* dst);                                           \
    extern void beginFn(PtrCopyIter* out, void* src);                         \
    extern void endFn(PtrCopyIter* out, void* src);                           \
    extern void** derefFn(PtrCopyIter* it);                                   \
    extern void pushFn(void* dst, void* value);                               \
    extern void incFn(PtrCopyIter* it);                                       \
    extern int neFn(PtrCopyIter* a, PtrCopyIter* b);                          \
    void name(void* src, void* dst)                                           \
    {                                                                         \
        PtrCopyIter it;                                                       \
        PtrCopyIter end;                                                      \
        reserveFn(dst, sizeFn(src));                                          \
        clearFn(dst);                                                         \
        beginFn(&it, src);                                                    \
        endFn(&end, src);                                                     \
        while (neFn(&it, &end)) {                                             \
            pushFn(dst, *derefFn(&it));                                       \
            incFn(&it);                                                       \
        }                                                                     \
    }

#endif /* PTR_COPY_LOOP_H */