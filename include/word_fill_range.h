#ifndef WORD_FILL_RANGE_H
#define WORD_FILL_RANGE_H

/*
 * Fill arr[first..last] (inclusive) with *value. Plain C.
 */
#define DEFINE_WORD_FILL_RANGE(name)                                          \
    void name(int* arr, int first, int last, const int* value)                \
    {                                                                         \
        int i;                                                                \
        for (i = first; i <= last; i++)                                       \
            arr[i] = *value;                                                  \
    }

#endif /* WORD_FILL_RANGE_H */