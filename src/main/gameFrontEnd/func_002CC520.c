#include "types.h"
typedef struct { int size; char hdr[4]; void* first; } ListC520;
extern void func_002CDEF0(void** res, ListC520* l, void** first, void** last);
extern void operator_delete(void* p);
ListC520* func_002CC520(ListC520* self, short deleteFlag)
{
    if (self) {
        if (self) {
            if (self) {
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