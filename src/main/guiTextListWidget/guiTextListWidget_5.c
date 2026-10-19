/*
 * main/guiTextListWidget: 3 files, 00422ED0-00423160
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00422ED0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiTextListWidget.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00422ED0(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00422ED0 */

/* merge_units: begin func_00422F10 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "guiTextListWidget_types.h"
#include "alloc_guard.h"

extern "C" {
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
        func_00423080(data, 0, 0, "allocator.hh", 0x64);
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
#pragma pop /* merge_units */
/* merge_units: end func_00422F10 */

/* merge_units: begin guiTextListWidget_423160 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef union TextStringValue {
    struct {
        unsigned int word;
        unsigned int length;
        char* data;
    } longString;
    struct {
        unsigned int isLong : 1;
        unsigned int length : 7;
    } shortString;
    char inlineData[12];
} TextStringValue;

typedef struct TextStringAllocator {
    char unused;
} TextStringAllocator;

extern "C" {
void String_Reserve(TextStringValue* string, unsigned int capacity);
TextStringValue* String_Replace(TextStringValue* string, unsigned int position,
                                unsigned int count, const char* first,
                                const char* last, TextStringAllocator allocator);
}

/* Copy inline string bytes directly and allocate owned storage for long strings. */
extern "C" TextStringValue* func_00423160(TextStringValue* self, const TextStringValue* source)
{
    TextStringAllocator allocator;
    if (!(source->longString.word & 1)) {
        *self = *source;
    } else {
        self->longString.word = 0;
        self->longString.length = 0;
        self->longString.data = 0;
        String_Reserve(self, source->longString.length);
        String_Replace(self, 0, 0, source->longString.data,
                       source->longString.data + source->longString.length, allocator);
    }
    return self;
}

/* Replace a substring with the complete inline or heap-backed source string. */
extern "C" TextStringValue* func_004231F0(TextStringValue* self, unsigned int position,
                                       unsigned int count, const TextStringValue* source)
{
    TextStringAllocator allocator;
    const char* data;
    unsigned int length;
    if (!(source->longString.word & 1)) {
        data = (const char*)source + 1;
        length = (unsigned char)source->shortString.length;
    } else {
        data = source->longString.data;
        length = source->longString.length;
    }
    return String_Replace(self, position, count, data, data + length, allocator);
}
#pragma pop /* merge_units */
/* merge_units: end guiTextListWidget_423160 */
