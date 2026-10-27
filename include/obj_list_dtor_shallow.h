#ifndef OBJ_LIST_DTOR_SHALLOW_H
#define OBJ_LIST_DTOR_SHALLOW_H

/*
 * Object-list destructor variant with a single null test on self:
 * erase [first, sentinel) through std_list_deleter_voidPtr_erase_listdeleter_listdeleter, then delete when
 * deleteFlag > 0. C++ only (#pragma cplusplus on before including).
 */
#include "obj_list_dtor.h"

#define DEFINE_OBJ_LIST_DTOR_SHALLOW(name)                                    \
    extern "C" ObjList* name(ObjList* self, short deleteFlag)                 \
    {                                                                         \
        if (self) {                                                           \
            ObjListNode* result;                                              \
            ObjListNode* first;                                               \
            ObjListNode* last;                                                \
            last = (ObjListNode*)&self->sentinelPrev;                         \
            first = self->first;                                              \
            std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&result, self, &first, &last);              \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* OBJ_LIST_DTOR_SHALLOW_H */