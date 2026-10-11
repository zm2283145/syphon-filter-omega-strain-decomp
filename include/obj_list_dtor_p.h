#ifndef OBJ_LIST_DTOR_P_H
#define OBJ_LIST_DTOR_P_H

/*
 * Callee-parameterised object-list destructors (see obj_list_dtor.h,
 * obj_list_dtor_mid.h, obj_list_dtor_shallow.h): erase [first, sentinel)
 * through eraseFn, then deleteFn(self) when deleteFlag > 0.
 * DEFINE_OBJ_LIST_DTOR_P: three null tests, _MID_P: two, _SHALLOW_P: one.
 * C++ only (#pragma cplusplus on before including).
 */
#include "obj_list_dtor.h"

#define OBJ_LIST_DTOR_P_DECL(eraseFn, deleteFn)                               \
    extern "C" {                                                              \
    void eraseFn(ObjListNode** result, ObjList* list, ObjListNode** first,    \
                 ObjListNode** last);                                         \
    void deleteFn(void* allocation);                                          \
    }

#define OBJ_LIST_DTOR_P_ERASE(eraseFn)                                        \
    {                                                                         \
        ObjListNode* result;                                                  \
        ObjListNode* first;                                                   \
        ObjListNode* last;                                                    \
        last = (ObjListNode*)&self->sentinelPrev;                             \
        first = self->first;                                                  \
        eraseFn(&result, self, &first, &last);                                \
    }

#define DEFINE_OBJ_LIST_DTOR_P(name, eraseFn, deleteFn)                       \
    OBJ_LIST_DTOR_P_DECL(eraseFn, deleteFn)                                   \
    extern "C" ObjList* name(ObjList* self, short deleteFlag)                 \
    {                                                                         \
        if (self) {                                                           \
            if (self) {                                                       \
                if (self) OBJ_LIST_DTOR_P_ERASE(eraseFn)                      \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                deleteFn(self);                                               \
        }                                                                     \
        return self;                                                          \
    }

#define DEFINE_OBJ_LIST_DTOR_MID_P(name, eraseFn, deleteFn)                   \
    OBJ_LIST_DTOR_P_DECL(eraseFn, deleteFn)                                   \
    extern "C" ObjList* name(ObjList* self, short deleteFlag)                 \
    {                                                                         \
        if (self) {                                                           \
            if (self) OBJ_LIST_DTOR_P_ERASE(eraseFn)                          \
            if (deleteFlag > 0)                                               \
                deleteFn(self);                                               \
        }                                                                     \
        return self;                                                          \
    }

#define DEFINE_OBJ_LIST_DTOR_SHALLOW_P(name, eraseFn, deleteFn)               \
    OBJ_LIST_DTOR_P_DECL(eraseFn, deleteFn)                                   \
    extern "C" ObjList* name(ObjList* self, short deleteFlag)                 \
    {                                                                         \
        if (self) {                                                           \
            OBJ_LIST_DTOR_P_ERASE(eraseFn)                                    \
            if (deleteFlag > 0)                                               \
                deleteFn(self);                                               \
        }                                                                     \
        return self;                                                          \
    }

#endif /* OBJ_LIST_DTOR_P_H */