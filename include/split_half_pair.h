#ifndef SPLIT_HALF_PAIR_H
#define SPLIT_HALF_PAIR_H

/*
 * Library helper (EE-GCC 2.96): run the first pass on half of n, then
 * return the second pass on the same half. Plain C.
 */
extern void fftCore4CFG(void* a, void* b, int n);
extern int unpack2G(void* a, void* b, int n);

#define DEFINE_SPLIT_HALF_PAIR(name)           \
    int name(void* a, void* b, int n)          \
    {                                          \
        int half = n / 2;                      \
        fftCore4CFG(a, b, half);             \
        return unpack2G(a, b, half);      \
    }

#endif /* SPLIT_HALF_PAIR_H */