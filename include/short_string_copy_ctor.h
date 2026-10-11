#ifndef SHORT_STRING_COPY_CTOR_H
#define SHORT_STRING_COPY_CTOR_H

/*
 * String copy constructor shared by identical template clones: a short
 * source is copied as a block; a long one starts empty, reserves the
 * length and replaces with the source characters.
 * C++ only (#pragma cplusplus on before including).
 */
#include "short_string_replace.h"

extern "C" void String_Reserve(ShortStr* self, unsigned int n);

#define DEFINE_SHORT_STRING_COPY_CTOR(name)                                   \
    extern "C" ShortStr* name(ShortStr* self, const ShortStr* src)            \
    {                                                                         \
        if (!ShortStr_IsLong(src)) {                                          \
            *self = *src;                                                     \
        } else {                                                              \
            self->u.l.word = 0;                                               \
            self->u.l.length = 0;                                             \
            self->u.l.data = 0;                                               \
            String_Reserve(self, src->u.l.length);                            \
            ShortStrIterTag tag;                                              \
            String_Replace(self, 0, 0, src->u.l.data,                         \
                           src->u.l.data + src->u.l.length, tag);             \
        }                                                                     \
        return self;                                                          \
    }

#endif /* SHORT_STRING_COPY_CTOR_H */