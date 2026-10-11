#ifndef SHORT_STRING_ASSIGN_INL_H
#define SHORT_STRING_ASSIGN_INL_H

/*
 * String assignment with the replace step inlined (String_Replace called
 * directly): two short strings copy as a block, otherwise replace the
 * whole current contents with src's characters.
 * C++ only (#pragma cplusplus on before including).
 */
#include "short_string_replace.h"

#define DEFINE_SHORT_STRING_ASSIGN_INL(name)                                  \
    extern "C" ShortStr* name(ShortStr* self, const ShortStr* src)            \
    {                                                                         \
        bool selfLong = ShortStr_IsLong(self);                                \
        if (!selfLong && !ShortStr_IsLong(src)) {                             \
            *self = *src;                                                     \
            return self;                                                      \
        }                                                                     \
        unsigned int n = selfLong ? self->u.l.length                          \
                                  : ShortStr_ShortLen(self);                  \
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
        return String_Replace(self, 0, n, data, data + len, tag);             \
    }

#endif /* SHORT_STRING_ASSIGN_INL_H */