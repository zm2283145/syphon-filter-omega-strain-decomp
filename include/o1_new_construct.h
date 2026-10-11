#ifndef O1_NEW_CONSTRUCT_H
#define O1_NEW_CONSTRUCT_H

/*
 * Optimization-level-1 helper (0x0020xxxx container code): allocate `size`
 * bytes through allocFn and, when that succeeds, construct the object with
 * ctor(p, value), where value is the third argument. Wrap the macro use in
 * #pragma optimization_level 1 / reset.
 */
#define DEFINE_O1_NEW_CONSTRUCT(name, size, allocFn, ctor)                    \
    extern void* allocFn(int bytes);                                          \
    extern void ctor(void* p, void* v);                                       \
    void name(void* a0, void* a1, void* v)                                    \
    {                                                                         \
        void* p = allocFn(size);                                              \
        if (p)                                                                \
            ctor(p, v);                                                       \
    }

#endif /* O1_NEW_CONSTRUCT_H */