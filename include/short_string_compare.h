#ifndef SHORT_STRING_COMPARE_H
#define SHORT_STRING_COMPARE_H

/*
 * compare(a, b) for the short/long string (see short_string_assign.h)
 * shared by identical clones: tail-calls std_basic_string_char_char_traits_char_compare_uint_uint_charP_uint(a, 0, a.size(),
 * b.data(), b.size()). Plain C: C++ mode does not emit the tail call.
 */
typedef struct ShortStrCLong {
    unsigned int word;
    unsigned int length;
    char* data;
} ShortStrCLong;

typedef struct ShortStrCShort {
    unsigned char isLong : 1;
    unsigned char len : 7;
    char buf[11];
} ShortStrCShort;

typedef struct ShortStrC {
    union {
        ShortStrCLong l;
        ShortStrCShort s;
    } u;
} ShortStrC;

int std_basic_string_char_char_traits_char_compare_uint_uint_charP_uint(const ShortStrC* self, unsigned int pos, unsigned int n,
                   const char* s, unsigned int len);

static inline unsigned char ShortStrC_ShortLen(const ShortStrC* s)
{
    return s->u.s.len;
}

#define DEFINE_SHORT_STRING_COMPARE(name)                                     \
    int name(const ShortStrC* a, const ShortStrC* b)                          \
    {                                                                         \
        const char* d;                                                        \
        unsigned int n;                                                       \
        if (!(b->u.l.word & 1)) {                                             \
            d = b->u.s.buf;                                                   \
            n = ShortStrC_ShortLen(b);                                        \
        } else {                                                              \
            d = b->u.l.data;                                                  \
            n = b->u.l.length;                                                \
        }                                                                     \
        return std_basic_string_char_char_traits_char_compare_uint_uint_charP_uint(a, 0,                                           \
                              (a->u.l.word & 1) ? a->u.l.length               \
                                                : ShortStrC_ShortLen(a),      \
                              d, n);                                          \
    }

#endif /* SHORT_STRING_COMPARE_H */