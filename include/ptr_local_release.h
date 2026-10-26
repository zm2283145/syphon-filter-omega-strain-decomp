#ifndef PTR_LOCAL_RELEASE_H
#define PTR_LOCAL_RELEASE_H

/*
 * Library helper (EE-GCC 2.95): when p is non-null, pass the address of a
 * local copy of it to rt_memory_free. Plain C.
 */
extern void rt_memory_free(void* pp);

#define DEFINE_PTR_LOCAL_RELEASE(name)       \
    void name(void* p)                       \
    {                                        \
        void* local = p;                     \
        if (p)                               \
            rt_memory_free(&local);           \
    }

#endif /* PTR_LOCAL_RELEASE_H */