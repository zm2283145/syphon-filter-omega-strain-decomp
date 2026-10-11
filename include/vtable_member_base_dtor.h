#ifndef VTABLE_MEMBER_BASE_DTOR_H
#define VTABLE_MEMBER_BASE_DTOR_H

/*
 * Deleting destructor of a derived class with one destructible member:
 * restore the vtable, destroy the member at memberOffset through
 * memberDtor(member, -1), run baseDtor(self, 0), delete when
 * deleteFlag > 0. C++ only (#pragma cplusplus on before including).
 */
extern "C" void operator_delete(void* allocation);

struct VtableMemberObject {
    void* vtable;
};

#define DEFINE_VTABLE_MEMBER_BASE_DTOR(name, vtableSym, memberOffset,         \
                                       memberDtor, baseDtor)                  \
    extern "C" {                                                              \
    extern char vtableSym[];                                                  \
    void* memberDtor(void* self, short deleteFlag);                           \
    void* baseDtor(void* self, short deleteFlag);                             \
    }                                                                         \
    extern "C" VtableMemberObject* name(VtableMemberObject* self,             \
                                        short deleteFlag)                     \
    {                                                                         \
        if (self) {                                                           \
            self->vtable = vtableSym;                                         \
            char* member = (char*)self + (memberOffset);                      \
            if (member)                                                       \
                memberDtor(member, -1);                                       \
            baseDtor(self, 0);                                                \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* VTABLE_MEMBER_BASE_DTOR_H */