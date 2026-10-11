#ifndef OBJ_LIST_DTOR_MID_H
#define OBJ_LIST_DTOR_MID_H

/*
 * Object-list destructor variant with two null tests on self:
 * erase [first, sentinel) through ObjectList_EraseRange, then delete when
 * deleteFlag > 0. C++ only (#pragma cplusplus on before including).
 */
#include "obj_list_dtor.h"

#define DEFINE_OBJ_LIST_DTOR_MID(name)                                        \
    extern "C" ObjList* name(ObjList* self, short deleteFlag)                 \
    {                                                                         \
        if (self) {                                                           \
            if (self) {                                                       \
                ObjListNode* result;                                          \
                ObjListNode* first;                                           \
                ObjListNode* last;                                            \
                last = (ObjListNode*)&self->sentinelPrev;                     \
                first = self->first;                                          \
                ObjectList_EraseRange(&result, self, &first, &last);          \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* OBJ_LIST_DTOR_MID_H */