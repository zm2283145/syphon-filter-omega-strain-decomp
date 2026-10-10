#include "types.h"

typedef struct { char flag; char name[16]; char value[16]; } Entry21; /* size 0x21 */
typedef struct { int unk0; int count; Entry21* data; } EntryVec;
extern char* String_Copy(char* dst, const char* src); /* String_Copy */
extern void* func_004147A0(void);
extern void func_0041E0F0(void* a, void* b, int a2, int a3, int a4);
extern void func_002469F0(EntryVec* v, Entry21* pos, int n, Entry21* value);

/* Appends a (name, value) entry to the vector after notifying the UI. */
void func_00241DA0(EntryVec* self, const char* value, const char* name)
{
    Entry21 e;
    void* ui;
    String_Copy(e.value, value);
    String_Copy(e.name, name);
    e.flag = 0;
    ui = func_004147A0();
    func_0041E0F0(ui, func_004147A0(), 0x10, 5, 0);
    func_002469F0(self, self->data + self->count, 1, &e);
}
