#ifndef LAST_KEY_TIME_H
#define LAST_KEY_TIME_H

/*
 * Time (first float) of the last 16-byte key in the list (count at 0x24,
 * keys at 0x28), or 0 when the list is empty. Plain C.
 */
typedef struct LastKeyF { float t; float pad[3]; } LastKeyF;
typedef struct LastKeyList { char pad[0x24]; int count; LastKeyF* keys; } LastKeyList;

#define DEFINE_LAST_KEY_TIME(name)                                    \
    float name(LastKeyList* l)                                        \
    {                                                                 \
        int n = l->count;                                             \
        unsigned int off = n * sizeof(LastKeyF);                      \
        if (n > 0)                                                    \
            return ((LastKeyF*)((char*)l->keys + off))[-1].t;         \
        return 0.0f;                                                  \
    }

#endif /* LAST_KEY_TIME_H */