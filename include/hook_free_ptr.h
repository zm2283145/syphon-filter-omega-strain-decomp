#ifndef HOOK_FREE_PTR_H
#define HOOK_FREE_PTR_H

/*
 * Library helpers (EE-GCC 2.96): free *pp through the installed free hook
 * D_004E1D38 when it is set, then clear it. One variant returns 0, the
 * other nothing. Plain C.
 */
extern void (*D_004E1D38)(void* p);

#define DEFINE_HOOK_FREE_PTR_RET0(name) \
    int name(void** pp)                 \
    {                                   \
        if (*pp) {                      \
            D_004E1D38(*pp);            \
            *pp = 0;                    \
        }                               \
        return 0;                       \
    }

#define DEFINE_HOOK_FREE_PTR(name)      \
    void name(void** pp)                \
    {                                   \
        if (*pp) {                      \
            D_004E1D38(*pp);            \
            *pp = 0;                    \
        }                               \
    }

#endif /* HOOK_FREE_PTR_H */