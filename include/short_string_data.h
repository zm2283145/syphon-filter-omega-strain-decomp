#ifndef SHORT_STRING_DATA_H
#define SHORT_STRING_DATA_H

/*
 * String data() shared by identical clones: the heap pointer at +8 for a
 * long string (bit 0 of the first word set), else the in-place characters
 * at +1. Plain C.
 */
typedef struct ShortStrData {
    unsigned int word;
    unsigned int length;
    char* data;
} ShortStrData;

#define DEFINE_SHORT_STRING_DATA(name)      \
    char* name(ShortStrData* s)             \
    {                                       \
        if (s->word & 1)                    \
            return s->data;                 \
        return (char*)s + 1;                \
    }

#endif /* SHORT_STRING_DATA_H */