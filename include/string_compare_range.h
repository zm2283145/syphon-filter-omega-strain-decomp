#ifndef STRING_COMPARE_RANGE_H
#define STRING_COMPARE_RANGE_H

/*
 * Clones of String_Compare(self, pos, n, s, len) for the short/long
 * string: range-check pos (report msgSym through the error stream and
 * abort), clamp n and len with std::min by reference, compare the bytes,
 * then order by length. C++ only (#pragma cplusplus on before including).
 */
struct SCRLong { unsigned int word; unsigned int length; char* data; };
struct SCRShort { unsigned char isLong : 1; unsigned char len : 7; char buf[11]; };
struct SCRStr { union { SCRLong l; SCRShort s; } u; };
struct SCRErr { int pad[3]; int stream; };

extern "C" {
extern SCRErr* D_00489738;
void func_00123BE8(int stream, const char* msg);
void Libc_Abort(void);
int Name_Compare48(const char* a, const char* b, unsigned int n);
}

static inline unsigned char SCR_ShortLen(const SCRStr* s) { return s->u.s.len; }
static inline const unsigned int& SCR_Min(const unsigned int& a, const unsigned int& b)
{
    return b < a ? b : a;
}

#define DEFINE_STRING_COMPARE_RANGE(name, msgSym)                             \
    extern "C" char msgSym[];                                                 \
    extern "C" int name(const SCRStr* self, unsigned int pos, unsigned int n, \
                        const char* s, unsigned int len)                      \
    {                                                                         \
        const char* d;                                                        \
        unsigned int sz;                                                      \
        unsigned int rlen, rem;                                               \
        if (!(self->u.l.word & 1)) {                                          \
            d = self->u.s.buf;                                                \
            sz = SCR_ShortLen(self);                                          \
        } else {                                                              \
            d = self->u.l.data;                                               \
            sz = self->u.l.length;                                            \
        }                                                                     \
        if (sz < pos) {                                                       \
            func_00123BE8(D_00489738->stream, msgSym);                        \
            Libc_Abort();                                                  \
        }                                                                     \
        rem = sz - pos;                                                       \
        rlen = SCR_Min(rem, n);                                               \
        int r = Name_Compare48(d + pos, s, SCR_Min(rlen, len));               \
        if (r == 0) {                                                         \
            if (rlen < len)                                                   \
                return -1;                                                    \
            return rlen == len ? 0 : 1;                                       \
        }                                                                     \
        return r;                                                             \
    }

#endif /* STRING_COMPARE_RANGE_H */