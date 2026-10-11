#ifndef VECTOR_ARRAY_MEMBER_DTOR_H
#define VECTOR_ARRAY_MEMBER_DTOR_H

/*
 * Deleting destructor of an object whose subobject at +0x4C owns a vector
 * at +0x88 (func_001BE5A0) and an array of 7 8-byte elements at +0x50
 * (destroyed with __destroy_array / func_0018A210); delete when
 * deleteFlag > 0. One clone per translation unit.
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" {
void* func_001BE5A0(void* self, short flags);
void* func_0018A210(void* self, short flags);
void __destroy_array(void* array, void* dtor, unsigned int size,
                     unsigned int count);
void operator_delete(void* allocation);
}

struct VectorArrayObject {
    char head[0x4C];
};

#define DEFINE_VECTOR_ARRAY_MEMBER_DTOR(name)                                 \
    extern "C" VectorArrayObject* name(VectorArrayObject* self,               \
                                       short deleteFlag)                      \
    {                                                                         \
        if (self) {                                                           \
            char* sub = (char*)self + 0x4C;                                   \
            if (sub) {                                                        \
                char* v = (char*)self + 0x88;                                 \
                if (v) {                                                      \
                    if (v) {                                                  \
                        if (v)                                                \
                            func_001BE5A0(v, 0);                              \
                    }                                                         \
                }                                                             \
                char* arr = (char*)self + 0x50;                               \
                if (arr)                                                      \
                    __destroy_array(arr, (void*)func_0018A210, 8, 7);         \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* VECTOR_ARRAY_MEMBER_DTOR_H */