#include "types.h"
typedef struct { char pad[0x80]; char m80[4]; } O36D5D0;
extern void FileHal_Dtor(void* p, int f);
extern void operator_delete(void* p);
O36D5D0* func_0036D5D0(O36D5D0* self, short del)
{
    if (self) {
        FileHal_Dtor(self->m80, -1);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}