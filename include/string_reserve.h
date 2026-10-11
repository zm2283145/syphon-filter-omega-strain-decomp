#ifndef STRING_RESERVE_H
#define STRING_RESERVE_H

/*
 * reserve(n) of the short/long string template clones (String_Reserve):
 * length-check n, round the capacity (11 = in place, else 16-byte steps),
 * move the contents into the new buffer, free the old heap buffer and
 * rewrite the flag/capacity/length words.
 * Parameters: name, length-error message, Mem_Alloc file/line,
 * Mem_Free file/line. C++ only (#pragma cplusplus on before including).
 */
#include "tstr_types.h"

#define DEFINE_STRING_RESERVE(name, errSym, allocFile, allocLine, freeFile, freeLine) \
    extern "C" char errSym[];                                                 \
    extern "C" char allocFile[];                                              \
    extern "C" char freeFile[];                                               \
    extern "C" void name(TStr* self, unsigned int n)                          \
    {                                                                         \
        if (n > 0x2FFFFFF) {                                                  \
            func_00123BE8(D_00489738->stream, errSym);                        \
            func_00121B60();                                                  \
        }                                                                     \
        unsigned int len;                                                     \
        char* newData;                                                        \
        char* oldData;                                                        \
        bool newLong;                                                         \
        bool isLong;                                                          \
        unsigned int cap;                                                     \
        isLong = self->u.l.w.b.isLong;                                        \
        if (!isLong) {                                                        \
            cap = 11;                                                         \
            len = TStr_ShortLen(self);                                        \
        } else {                                                              \
            len = self->u.l.length;                                           \
            cap = self->u.l.w.b.cap;                                          \
        }                                                                     \
        if (n < len)                                                          \
            n = len;                                                          \
        if (n + 1 < 12)                                                       \
            n = 11;                                                           \
        else                                                                  \
            n = (n + 16) & ~15;                                               \
        if (n == cap)                                                         \
            return;                                                           \
        if (n == 11) {                                                        \
            oldData = self->u.l.data;                                         \
            newData = self->u.s.buf;                                          \
            newLong = false;                                                  \
        } else {                                                              \
            if (cap < n) {                                                    \
                newData = TStr_Alloc(n, allocFile, allocLine);                \
            } else {                                                          \
                newData = TStr_Alloc(n, allocFile, allocLine);                \
                if (!newData)                                                 \
                    return;                                                   \
            }                                                                 \
            newLong = true;                                                   \
            oldData = isLong ? self->u.l.data : self->u.s.buf;               \
        }                                                                     \
        memcpy(newData, oldData, len);                                        \
        newData[len] = 0;                                                     \
        if (isLong && oldData)                                                \
            TStr_Free(oldData, freeFile, freeLine);                           \
        self->u.l.w.b.isLong = newLong;                                       \
        if (!newLong) {                                                       \
            self->u.s.len = len;                                              \
        } else {                                                              \
            self->u.l.data = newData;                                         \
            self->u.l.length = len;                                           \
            self->u.l.w.b.cap = n;                                            \
        }                                                                     \
    }

#endif /* STRING_RESERVE_H */