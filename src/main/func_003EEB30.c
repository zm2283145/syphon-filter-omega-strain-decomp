#include "types.h"
typedef struct { char pad[0x6E]; unsigned short count; char p1[0x84 - 0x70]; void** list; } T3EEB30;
extern int String_AssignCStr_1C43A0(void* s, const char* name);
void* func_003EEB30(T3EEB30* t, const char* name) {
    int i;
    for (i = 0; i < t->count; i++) {
        if (String_AssignCStr_1C43A0(t->list[i], name) == 0) return t->list[i];
    }
    return 0;
}