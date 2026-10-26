#ifndef SHORT_STRING_SUBSTR_CTOR_H
#define SHORT_STRING_SUBSTR_CTOR_H

/*
 * String substring constructor string(src, pos, n) shared by identical
 * template clones: start empty, reserve min(n, size - pos) (0 when pos is
 * past the end) and replace the empty contents with src[pos, pos + n).
 * C++ only (#pragma cplusplus on before including).
 */
#include "short_string_assign.h"

extern "C" void String_Reserve(ShortStr* self, unsigned int n);
extern "C" ShortStr* std_basic_string_char_char_traits_char_replace_uint_uint_basicstringR_uint_etc(ShortStr* self, unsigned int pos1,
                                   unsigned int n1, const ShortStr* src,
                                   unsigned int pos2, unsigned int n2);

template <class T> inline const T& ShortStrSub_min(const T& a, const T& b)
{
    return (b < a) ? b : a;
}

#define DEFINE_SHORT_STRING_SUBSTR_CTOR(name)                                 \
    extern "C" ShortStr* name(ShortStr* self, const ShortStr* src,            \
                              unsigned int pos, unsigned int n)               \
    {                                                                         \
        unsigned int size;                                                    \
        self->u.l.word = 0;                                                   \
        self->u.l.length = 0;                                                 \
        self->u.l.data = 0;                                                   \
        size = ShortStr_IsLong(src) ? src->u.l.length                         \
                                    : ShortStr_ShortLen(src);                 \
        String_Reserve(self, pos <= size ? ShortStrSub_min(n, size - pos)      \
                                         : 0);                                \
        std_basic_string_char_char_traits_char_replace_uint_uint_basicstringR_uint_etc(self, 0, 0, src, pos, n);                               \
        return self;                                                          \
    }

#endif /* SHORT_STRING_SUBSTR_CTOR_H */