#ifndef OBJ_LIST_DTOR_H
#define OBJ_LIST_DTOR_H

/*
 * Destructor body shared by identical object-list destructor clones
 * (one per translation unit): erase [first, sentinel) through
 * ObjectList_EraseRange, then delete the object when deleteFlag > 0.
 * C++ only (#pragma cplusplus on before including).
 */
typedef struct ObjListNode ObjListNode;
typedef struct ObjList {
    int size;
    ObjListNode* sentinelPrev; /* +4: the sentinel node lives here */
    ObjListNode* first;        /* +8 */
} ObjList;

extern "C" {
void ObjectList_EraseRange(ObjListNode** result, ObjList* list,
                           ObjListNode** first, ObjListNode** last);
void operator_delete(void* allocation);
}

#define DEFINE_OBJ_LIST_DTOR(name)                                            \
    extern "C" ObjList* name(ObjList* self, short deleteFlag)                 \
    {                                                                         \
        if (self) {                                                           \
            if (self) {                                                       \
                if (self) {                                                   \
                    ObjListNode* result;                                      \
                    ObjListNode* first;                                       \
                    ObjListNode* last;                                        \
                    last = (ObjListNode*)&self->sentinelPrev;                 \
                    first = self->first;                                      \
                    ObjectList_EraseRange(&result, self, &first, &last);      \
                }                                                             \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* OBJ_LIST_DTOR_H */