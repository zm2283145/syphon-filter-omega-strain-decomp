#ifndef SERIAL_HANDLE_EQUAL_H
#define SERIAL_HANDLE_EQUAL_H

/*
 * Weak handle {target, serial}: the target is valid only while its serial
 * (at +0xC) equals the handle's. Equality compares the resolved targets.
 *   DEFINE_SERIAL_HANDLE_EQUAL(name)       name(Handle* a, Handle* b)
 *   DEFINE_SERIAL_HANDLE_EQUAL_3(name)     name(void* self, Handle* a, Handle* b)
 */
typedef struct SerialTarget {
    char pad[0xC];
    int serial;
} SerialTarget;

typedef struct SerialHandle {
    SerialTarget* target;
    int serial;
} SerialHandle;

static inline SerialTarget* SerialHandle_Get(SerialHandle* h)
{
    SerialTarget* t = h->target;
    bool ok = !t || t->serial == h->serial;
    return ok ? t : 0;
}

#define DEFINE_SERIAL_HANDLE_EQUAL(name)                                      \
    extern "C" int name(SerialHandle* a, SerialHandle* b)                                \
    {                                                                         \
        return SerialHandle_Get(a) == SerialHandle_Get(b);                    \
    }

#define DEFINE_SERIAL_HANDLE_EQUAL_3(name)                                    \
    extern "C" int name(void* self, SerialHandle* a, SerialHandle* b)                    \
    {                                                                         \
        return SerialHandle_Get(a) == SerialHandle_Get(b);                    \
    }

#endif /* SERIAL_HANDLE_EQUAL_H */