#include "types.h"
typedef struct { int size; char hdr[4]; void* first; } ListC730;
extern void func_002CDEF0(void** res, ListC730* l, void** first, void** last);
extern void operator_delete(void* p);
ListC730* func_002CC730(ListC730* self, short deleteFlag)
{
    if (self) {
        if (self) {
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