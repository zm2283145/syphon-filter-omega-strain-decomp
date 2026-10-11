#ifndef SPLIT_HALF_PAIR_H
#define SPLIT_HALF_PAIR_H

/*
 * Library helper (EE-GCC 2.96): run the first pass on half of n, then
 * return the second pass on the same half. Plain C.
 */
extern void func_003227E0(void* a, void* b, int n);
extern int func_00322B40(void* a, void* b, int n);

#define DEFINE_SPLIT_HALF_PAIR(name)           \
    int name(void* a, void* b, int n)          \
    {                                          \
        int half = n / 2;                      \
        func_003227E0(a, b, half);             \
        return func_00322B40(a, b, half);      \
    }

#endif /* SPLIT_HALF_PAIR_H */