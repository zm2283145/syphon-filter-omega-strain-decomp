#include "types.h"
typedef struct { int size; char hdr[4]; void* first; } ListC7B0;
extern void func_002CDEF0(void** res, ListC7B0* l, void** first, void** last);
extern void operator_delete(void* p);
ListC7B0* func_002CC7B0(ListC7B0* self, short deleteFlag)
{
    if (self) {
        {
            {
                void* res;
                void* first;
                void* last;
                last = self->hdr;
                first = self->first;
                func_002CDEF0(&res, self, &first, &last);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}