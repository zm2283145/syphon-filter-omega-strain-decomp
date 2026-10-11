#ifndef SHORT_STRING_REPLACE_H
#define SHORT_STRING_REPLACE_H

/*
 * replace(pos, n, const string& src) shared by identical template clones:
 * take src's character range (in place for short strings, heap data for
 * long ones) and forward to String_Replace with an (empty) iterator tag.
 * C++ only (#pragma cplusplus on before including).
 */
#include "short_string_assign.h"

struct ShortStrIterTag {
    char c;
};

extern "C" ShortStr* String_Replace(ShortStr* self, unsigned int pos,
                                    unsigned int n, const char* first,
                                    const char* last, ShortStrIterTag tag);

#define DEFINE_SHORT_STRING_REPLACE(name)                                     \
    extern "C" ShortStr* name(ShortStr* self, unsigned int pos,               \
                              unsigned int n, const ShortStr* src)            \
    {                                                                         \
        const char* data;                                                     \
        unsigned int len;                                                     \
        if (!ShortStr_IsLong(src)) {                                          \
            data = src->u.s.buf;                                              \
            len = ShortStr_ShortLen(src);                                     \
        } else {                                                              \
            data = src->u.l.data;                                             \
            len = src->u.l.length;                                            \
        }                                                                     \
        ShortStrIterTag tag;                                                  \
        return String_Replace(self, pos, n, data, data + len, tag);           \
    }

#endif /* SHORT_STRING_REPLACE_H */