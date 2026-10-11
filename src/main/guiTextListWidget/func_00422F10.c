#pragma cplusplus on

#include "guiTextListWidget_types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004BF608[];
void func_00329930(void* destination, const void* source);
void func_00421F90(TextListEntryVec* entries);
void func_00138350(TextListEntry* entries, int flags);
void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
void func_00423080(TextListEntry* allocation, int pool, int destroy,
                   char* file, int line);
}

static inline void assign_entry(TextListEntry* destination, const TextListEntry* source)
{
    func_00329930(destination->text, source->text);
    destination->unk0C = source->unk0C;
    destination->unk10 = source->unk10;
}

/* Assign a repeated text-entry value across an existing range. */
extern "C" void func_00422F10(TextListEntry* destination, unsigned int count,
                            const TextListEntry* value)
{
    while (count) {
        assign_entry(destination, value);
        --count;
        ++destination;
    }
}

/* Copy backward so overlapping entry ranges retain their original contents. */
extern "C" TextListEntry* func_00422F80(TextListEntry* first, TextListEntry* last,
                                      TextListEntry* destinationEnd)
{
    while (first < last) {
        --last;
        --destinationEnd;
        assign_entry(destinationEnd, last);
    }
    return destinationEnd;
}

static inline void release_storage(TextListEntry* data)
{
    if (data)
        func_00423080(data, 0, 0, D_004BF608, 0x64);
}

/* Destroy live entries, release their storage, then optionally delete the vector. */
extern "C" TextListEntryVec* func_00423000(TextListEntryVec* self, short deleteFlag)
{
    if (self) {
        func_00421F90(self);
        TextListEntry* data = self->data;
        if (data)
            release_storage(data);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

/* Release an entry allocation under the allocator lock, optionally destroying it. */
extern "C" void func_00423080(TextListEntry* allocation, int pool, int destroy,
                             char* file, int line)
{
    AllocGuard guard;
    if (destroy && allocation)
        func_00138350(allocation, -1);
    Mem_Free(pool, allocation, file, line);
}
