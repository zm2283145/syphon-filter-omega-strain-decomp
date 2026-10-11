#ifndef SHORT_STRING_ASSIGN_H
#define SHORT_STRING_ASSIGN_H

/*
 * String assignment shared by identical template clones (one per
 * translation unit). The 12-byte string is either short (in place, bit 0
 * clear, length in bits 1-7 of byte 0) or long (bit 0 set, length at +4,
 * heap data at +8). Two short strings are copied as a block; otherwise the
 * whole current contents are replaced through func_0013D710.
 * C++ only (#pragma cplusplus on before including).
 */
struct ShortStrLong {
    unsigned int word;
    unsigned int length;
    char* data;
};

struct ShortStrShort {
    unsigned char isLong : 1;
    unsigned char len : 7;
    char buf[11];
};

struct ShortStr {
    union {
        ShortStrLong l;
        ShortStrShort s;
    } u;
};

extern "C" ShortStr* func_0013D710(ShortStr* self, unsigned int pos,
                                   unsigned int n, const ShortStr* src);

static inline bool ShortStr_IsLong(const ShortStr* s)
{
    return (s->u.l.word & 1) != 0;
}

static inline unsigned char ShortStr_ShortLen(const ShortStr* s)
{
    return s->u.s.len;
}

#define DEFINE_SHORT_STRING_ASSIGN(name)                                      \
    extern "C" ShortStr* name(ShortStr* self, const ShortStr* src)            \
    {                                                                         \
        bool selfLong = ShortStr_IsLong(self);                                \
        if (!selfLong && !ShortStr_IsLong(src)) {                             \
            *self = *src;                                                     \
            return self;                                                      \
        }                                                                     \
        return func_0013D710(self, 0,                                         \
                             selfLong ? self->u.l.length                      \
                                      : ShortStr_ShortLen(self),              \
                             src);                                            \
    }

#endif /* SHORT_STRING_ASSIGN_H */