#ifndef PTR_LOCAL_RELEASE_H
#define PTR_LOCAL_RELEASE_H

/*
 * Library helper (EE-GCC 2.95): when p is non-null, pass the address of a
 * local copy of it to func_002FB3C0. Plain C.
 */
extern void func_002FB3C0(void* pp);

#define DEFINE_PTR_LOCAL_RELEASE(name)       \
    void name(void* p)                       \
    {                                        \
        void* local = p;                     \
        if (p)                               \
            func_002FB3C0(&local);           \
    }

#endif /* PTR_LOCAL_RELEASE_H */