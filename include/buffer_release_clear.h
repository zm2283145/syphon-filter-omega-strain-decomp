#ifndef BUFFER_RELEASE_CLEAR_H
#define BUFFER_RELEASE_CLEAR_H

/*
 * Library helper (EE-GCC 2.96): release a buffer's data through
 * func_001247E0 when present, then clear its data pointer and count.
 * Returns the release result, or 0 when there was no data. Plain C.
 */
typedef struct BufferRC { int pad; int count; void* data; } BufferRC;
extern int func_001247E0(void* ctx, BufferRC* b);

#define DEFINE_BUFFER_RELEASE_CLEAR(name)          \
    int name(void* ctx, BufferRC* b)               \
    {                                              \
        int r;                                     \
        if (b->data == 0) {                        \
            b->count = 0;                          \
            return 0;                              \
        }                                          \
        r = func_001247E0(ctx, b);                 \
        b->data = 0;                               \
        b->count = 0;                              \
        return r;                                  \
    }

#endif /* BUFFER_RELEASE_CLEAR_H */