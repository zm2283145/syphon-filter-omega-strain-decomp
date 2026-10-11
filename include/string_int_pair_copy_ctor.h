#ifndef STRING_INT_PAIR_COPY_CTOR_H
#define STRING_INT_PAIR_COPY_CTOR_H

/*
 * Copy constructor of a { string first; int second; } pair shared by
 * identical template clones: the string is copied like
 * DEFINE_SHORT_STRING_COPY_CTOR, then the trailing word.
 * C++ only (#pragma cplusplus on before including).
 */
#include "short_string_replace.h"

extern "C" void String_Reserve(ShortStr* self, unsigned int n);

struct ShortStrIntPair {
    ShortStr first;
    int second;
};

#define DEFINE_STRING_INT_PAIR_COPY_CTOR(name)                                \
    extern "C" ShortStrIntPair* name(ShortStrIntPair* self,                   \
                                     const ShortStrIntPair* src)              \
    {                                                                         \
        if (!ShortStr_IsLong(&src->first)) {                                  \
            self->first = src->first;                                         \
        } else {                                                              \
            self->first.u.l.word = 0;                                         \
            self->first.u.l.length = 0;                                       \
            self->first.u.l.data = 0;                                         \
            String_Reserve(&self->first, src->first.u.l.length);              \
            ShortStrIterTag tag;                                              \
            String_Replace(&self->first, 0, 0, src->first.u.l.data,           \
                           src->first.u.l.data + src->first.u.l.length, tag); \
        }                                                                     \
        self->second = src->second;                                           \
        return self;                                                          \
    }

#endif /* STRING_INT_PAIR_COPY_CTOR_H */