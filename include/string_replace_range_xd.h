#ifndef STRING_REPLACE_RANGE_XD_H
#define STRING_REPLACE_RANGE_XD_H

/*
 * Same as DEFINE_STRING_REPLACE_RANGE, for the clones whose temporary
 * string is destroyed by an out-of-line destructor call dtorFn(&tmp, -1).
 * C++ only (#pragma cplusplus on before including).
 */
#include "string_replace_range.h"
#define DEFINE_STRING_REPLACE_RANGE_XD(name, oorSym, lenSym, allocFile, allocLine, freeFile, freeLine, eosGrow, eosInPlace, moveFn, assignFn, dtorFn) \
    extern "C" char oorSym[];                                                 \
    extern "C" char lenSym[];                                                 \
    extern "C" char allocFile[];                                              \
    extern "C" char freeFile[];                                               \
    extern "C" char eosGrow;                                                  \
    extern "C" char eosInPlace;                                               \
    extern "C" void* moveFn(void* d, const void* s, unsigned int n);          \
    extern "C" void* assignFn(TStr* s, const char* first, const char* last, int z); \
    extern "C" void dtorFn(TStr* s, int flags);                               \
    struct name##_Tmp {                                                       \
        TStr s;                                                               \
        name##_Tmp() { int* p = (int*)this; p[0] = 0; p[1] = 0; p[2] = 0; }  \
    };                                                                        \
    extern "C" TStr* name(TStr* self, unsigned int pos, unsigned int n,       \
                          const char* first, const char* last, TStrRangeTag tag) \
    {                                                                         \
        char* data;                                                           \
        unsigned int size;                                                    \
        unsigned int cap;                                                     \
        unsigned int rem;                                                     \
        unsigned int rlen;                                                    \
        unsigned int ins;                                                     \
        unsigned int newSize;                                                 \
        unsigned int tail;                                                    \
        char* nd;                                                             \
        bool isLong;                                                          \
        isLong = TSR_IsLong(self);                                            \
        if (!isLong) {                                                        \
            data = self->u.s.buf;                                             \
            size = TStr_ShortLen(self);                                       \
            cap = 11;                                                         \
        } else {                                                              \
            cap = TSR_Cap(self);                                              \
            data = self->u.l.data;                                            \
            size = self->u.l.length;                                          \
        }                                                                     \
        if (size < pos) {                                                     \
            Libc_Fprintf(D_00489738->stream, oorSym);                        \
            Libc_Abort();                                                  \
        }                                                                     \
        rem = size - pos;                                                     \
        rlen = TSR_Min(n, rem);                                               \
        ins = TSR_Dist(first, last);                                          \
        if (ins > 0x2FFFFFF || size - rlen > 0x2FFFFFF - ins) {               \
            Libc_Fprintf(D_00489738->stream, lenSym);                        \
            Libc_Abort();                                                  \
        }                                                                     \
        newSize = ins + (size - rlen);                                        \
        tail = size - (pos + rlen);                                           \
        if (newSize >= cap) {                                                 \
            unsigned int newCap = (cap + 15) & ~15;                           \
            while (newCap < newSize + 1)                                      \
                newCap = (newCap * 2 + 15) & ~15;                             \
            nd = TStr_Alloc(newCap, allocFile, allocLine);                    \
            if (pos)                                                          \
                memcpy(nd, data, pos);                                        \
            char* p = nd + pos;                                               \
            memcpy(p, first, last - first);                                   \
            if (tail)                                                         \
                memcpy(p + ins, data + pos + rlen, tail);                     \
            nd[newSize] = eosGrow;                                            \
            if (isLong) {                                                     \
                if (data)                                                     \
                    TStr_Free(data, freeFile, freeLine);                      \
            } else {                                                          \
                self->u.l.w.b.isLong = 1;                                     \
            }                                                                 \
            self->u.l.data = nd;                                              \
            self->u.l.length = newSize;                                       \
            self->u.l.w.b.cap = newCap;                                       \
        } else {                                                              \
            name##_Tmp tmp;                                                   \
            if (tail && data + pos + ins < last && last <= data + size) {     \
                assignFn(&tmp.s, first, last, 0);                             \
                const TStr* tp = &tmp.s;                                      \
                if ((tp->u.l.w.word & 1) == 0)                                \
                    first = tp->u.s.buf;                                      \
                else                                                          \
                    first = tp->u.l.data;                                     \
            }                                                                 \
            if (tail)                                                         \
                moveFn(data + pos + ins, data + pos + rlen, tail);            \
            moveFn(data + pos, first, ins);                                   \
            data[newSize] = eosInPlace;                                       \
            if (!isLong)                                                      \
                self->u.s.len = newSize;                                      \
            else                                                              \
                self->u.l.length = newSize;                                   \
            dtorFn(&tmp.s, -1);                                               \
        }                                                                     \
        return self;                                                          \
    }

#endif /* STRING_REPLACE_RANGE_XD_H */
