#pragma cplusplus on

#include "guiTextArrayWidget_types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004BF790[];
void func_004263C0(guiTextArrayWidget* self);
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void func_004268C0(TextArrayRow* row);
void String_CtorEmpty(void* string);
void func_004268B0(Vec4* color);
Vec4* func_00426890(Vec4* color, float x, float y, float z, float w);
void SubtitleTrack_LoadCue(Vec4* destination, const Vec4* source);
void func_00428000(TextArrayRow* row, unsigned int columns, const TextArrayCell* value);
void String_Dtor(void* string, int flags);
void func_00426870(TextArrayStore* store, TextArrayRow** row);
void func_00428090(TextArrayStore* store, int flags);
void operator_delete(void* allocation);
}

/* Return an existing cell only when both row and column are in range. */
extern "C" TextArrayCell* GuiTextArrayWidget_GetCell(guiTextArrayWidget* self,
                                     unsigned int column, unsigned int row)
{
    if (row >= (unsigned int)self->store.unk04)
        return 0;
    TextArrayRow* entries = self->store.unk08[row];
    if (!entries || column >= entries->count)
        return 0;
    return &entries->data[column];
}

static inline TextArrayRow* create_row(void)
{
    TextArrayRow* allocation;
    {
        AllocGuard guard;
        allocation = (TextArrayRow*)Mem_Alloc(0, sizeof(TextArrayRow), D_004BF790, 0x2B);
    }
    if (allocation) {
        func_004268C0(allocation);
        allocation->owned = 1;
    }
    return allocation;
}

/* Rebuild the requested rows with default cells and independently owned storage. */
extern "C" void TextArrayCell_InitDefaults(guiTextArrayWidget* self, unsigned int columns, unsigned int rows)
{
    func_004263C0(self);
    if (!columns || !rows)
        return;
    for (unsigned int index = 0; index < rows; ++index) {
        TextArrayRow* row;
        TextArrayCell cell;
        Vec4 white;
        row = create_row();
        String_CtorEmpty(cell.string);
        func_004268B0(&cell.color);
        cell.flags = 0;
        cell.attribute = 0;
        cell.text = 0;
        SubtitleTrack_LoadCue(&cell.color, func_00426890(&white, 1.0f, 1.0f, 1.0f, 1.0f));
        func_00428000(row, columns, &cell);
        String_Dtor(cell.string, 0);
        func_00426870(&self->store, &row);
    }
}

static inline void destroy_string(void* string)
{
    if (string)
        String_Dtor(string, 0);
}

/* Destroy the cell's string before optional cell deletion. */
extern "C" TextArrayCell* func_004267B0(TextArrayCell* self, short deleteFlag)
{
    if (self) {
        destroy_string(self->string);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}

static inline void destroy_store(TextArrayStore* store)
{
    if (store)
        func_00428090(store, 0);
}

/* Destroy the row-pointer store before optional object deletion. */
extern "C" TextArrayStore* func_00426810(TextArrayStore* self, short deleteFlag)
{
    if (self) {
        destroy_store(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
