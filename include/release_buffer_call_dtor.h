#ifndef RELEASE_BUFFER_CALL_DTOR_H
#define RELEASE_BUFFER_CALL_DTOR_H

/*
 * Deleting destructor: preFn(self), then hand the buffer at +8 to the
 * per-unit allocator release releaseFn(ptr, 0, 0, file, 100), then delete
 * when deleteFlag > 0. C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);

typedef struct ReleaseBufferHolder {
    int first;
    int count;
    void* buffer;
} ReleaseBufferHolder;

#define DEFINE_RELEASE_BUFFER_CALL_DTOR(name, preFn, releaseFn, file)         \
    extern "C" char file[];                                                   \
    extern "C" void preFn(ReleaseBufferHolder* self);                         \
    extern "C" void releaseFn(void* p, int pool, int destroy, char* f, int l);\
    extern "C" ReleaseBufferHolder* name(ReleaseBufferHolder* self,           \
                                         short deleteFlag)                    \
    {                                                                         \
        if (self) {                                                           \
            void* p;                                                          \
            preFn(self);                                                      \
            p = self->buffer;                                                 \
            if (p) {                                                          \
                if (p)                                                        \
                    releaseFn(p, 0, 0, file, 0x64);                           \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* RELEASE_BUFFER_CALL_DTOR_H */