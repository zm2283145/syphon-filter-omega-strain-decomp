#pragma cplusplus on
/* Inline all row-base cleanup layers while retaining their null checks. */
#pragma inline_depth(8)

#include "guiTextArrayWidget_types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004BF790[];
TextArrayRow** func_004264C0(TextArrayStore* store, int index);
void func_00428090(TextArrayRow* row, int flags);
void Mem_Free(int pool, void* allocation, char* file, int line);
}

static inline void destroy_storage(TextArrayRow* row)
{
    if (row)
        func_00428090(row, 0);
}

static inline void destroy_base(TextArrayRow* row)
{
    if (row)
        destroy_storage(row);
}

static inline void destroy_row(TextArrayRow* row)
{
    if (row)
        destroy_base(row);
}

/* Destroy owned rows in order, preserving the live count until the final reset. */
extern "C" void func_004263C0(guiTextArrayWidget* self)
{
    for (int index = 0; index < self->store.unk04; ++index) {
        TextArrayRow* row = *func_004264C0(&self->store, index);
        AllocGuard guard;
        destroy_row(row);
        Mem_Free(0, row, D_004BF790, 0x50);
    }
    self->store.unk04 = 0;
}
