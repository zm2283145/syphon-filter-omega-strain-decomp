#ifndef MESSAGE_PACK_H
#define MESSAGE_PACK_H

/*
 * Message serialisers ("Pack"): when the buffer holds at least `size`
 * bytes, write the common header (Event_PackHeader), then BODY(e, b)
 * copies the payload; store the type id and return `size`, else -1.
 *   DEFINE_MESSAGE_PACK(name, size, typeSym, BODY)       header gets type
 *   DEFINE_MESSAGE_PACK_NOTYPE(name, size, typeSym, BODY) header gets 0
 *   DEFINE_MESSAGE_PACK_PRE(name, size, typeSym, PRE, BODY)
 *       PRE(e) runs before the header (inside the size test)
 * MP_I/MP_S/MP_B/MP_U/MP_H access int/signed char/unsigned char/short fields
 * by offset.
 */
#define MP_I(p, off) (*(int*)((char*)(p) + (off)))
#define MP_S(p, off) (*(signed char*)((char*)(p) + (off)))
#define MP_U(p, off) (*(unsigned char*)((char*)(p) + (off)))
#define MP_H(p, off) (*(short*)((char*)(p) + (off)))
#define MP_P(p, off) (*(char**)((char*)(p) + (off)))

extern void Event_PackHeader(void* e, int a1, int* type, int a3, int a4,
                             unsigned int size, void* buf);

#define DEFINE_MESSAGE_PACK(name, size, typeSym, BODY)                        \
    extern int typeSym;                                                       \
    int name(void* e, int a1, int* type, int a3, int a4, unsigned int sz,     \
             void* buf)                                                       \
    {                                                                         \
        int r = -1;                                                           \
        if (sz >= (size) && buf) {                                            \
            char* b = (char*)buf;                                             \
            Event_PackHeader(e, a1, type, a3, a4, sz, buf);                   \
            BODY(e, b)                                                        \
            if (type) {                                                       \
                r = (size);                                                   \
                *type = typeSym;                                              \
            }                                                                 \
        }                                                                     \
        return r;                                                             \
    }

#define DEFINE_MESSAGE_PACK_NOTYPE(name, size, typeSym, BODY)                 \
    extern int typeSym;                                                       \
    int name(void* e, int a1, int* type, int a3, int a4, unsigned int sz,     \
             void* buf)                                                       \
    {                                                                         \
        int r = -1;                                                           \
        if (sz >= (size) && buf) {                                            \
            char* b = (char*)buf;                                             \
            Event_PackHeader(e, a1, 0, a3, a4, sz, buf);                      \
            BODY(e, b)                                                        \
            if (type) {                                                       \
                r = (size);                                                   \
                *type = typeSym;                                              \
            }                                                                 \
        }                                                                     \
        return r;                                                             \
    }

#define DEFINE_MESSAGE_PACK_PRE(name, size, typeSym, PRE, BODY)               \
    extern int typeSym;                                                       \
    int name(void* e, int a1, int* type, int a3, int a4, unsigned int sz,     \
             void* buf)                                                       \
    {                                                                         \
        int r = -1;                                                           \
        if (sz >= (size) && buf) {                                            \
            char* b = (char*)buf;                                             \
            PRE(e)                                                            \
            Event_PackHeader(e, a1, type, a3, a4, sz, buf);                   \
            BODY(e, b)                                                        \
            if (type) {                                                       \
                r = (size);                                                   \
                *type = typeSym;                                              \
            }                                                                 \
        }                                                                     \
        return r;                                                             \
    }


/* Inline base-class serialiser for derived Pack functions that call it. */
#define DEFINE_MESSAGE_PACK_INLINE(name, size, typeSym, BODY)                 \
    extern int typeSym;                                                       \
    static inline int name(void* e, int a1, int* type, int a3, int a4,        \
                           unsigned int sz, void* buf)                        \
    {                                                                         \
        int r = -1;                                                           \
        if (sz >= (size) && buf) {                                            \
            char* b = (char*)buf;                                             \
            Event_PackHeader(e, a1, type, a3, a4, sz, buf);                   \
            BODY(e, b)                                                        \
            if (type) {                                                       \
                r = (size);                                                   \
                *type = typeSym;                                              \
            }                                                                 \
        }                                                                     \
        return r;                                                             \
    }

/* Derived serialiser: run the inline base `baseFn`, then TAIL(e, b). */
#define DEFINE_MESSAGE_PACK_DERIVED(name, size, baseFn, TAIL)                 \
    int name(void* e, int a1, int* type, int a3, int a4, unsigned int sz,     \
             void* buf)                                                       \
    {                                                                         \
        int r = -1;                                                           \
        if (sz >= (size) && buf) {                                            \
            char* b = (char*)buf;                                             \
            r = baseFn(e, a1, type, a3, a4, sz, buf);                         \
            TAIL(e, b)                                                        \
        }                                                                     \
        return r;                                                             \
    }

#endif /* MESSAGE_PACK_H */