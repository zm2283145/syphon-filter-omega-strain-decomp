#ifndef VECTOR_RELEASE_DTOR_H
#define VECTOR_RELEASE_DTOR_H

/*
 * Deleting destructor of a vector that destroys its elements with
 * destroyFn(self) and returns its buffer through the out-of-line
 * allocator release releaseFn(p, 0, 0, fileSym, 100), then deletes the
 * object when deleteFlag > 0. One clone per translation unit.
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);

struct ReleaseVector {
    int capacity;
    int count;
    void* data;
};

#define DEFINE_VECTOR_RELEASE_DTOR(name, destroyFn, releaseFn, fileSym)       \
    extern "C" {                                                              \
    extern char fileSym[];                                                    \
    void releaseFn(void* allocation, int pool, int destroy, char* file,       \
                   int line);                                                 \
    void destroyFn(void* self);                                               \
    }                                                                         \
    extern "C" ReleaseVector* name(ReleaseVector* self, short deleteFlag)     \
    {                                                                         \
        if (self) {                                                           \
            destroyFn(self);                                                  \
            void* p = self->data;                                             \
            if (p) {                                                          \
                if (p)                                                        \
                    releaseFn(p, 0, 0, fileSym, 0x64);                        \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* VECTOR_RELEASE_DTOR_H */