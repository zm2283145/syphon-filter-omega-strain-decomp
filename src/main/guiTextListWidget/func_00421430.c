#include "guiTextListWidget_types.h"

extern char* String_CStr(const void* text);

/* Return the selected entry's string data, or null for an invalid index. */
char* func_00421430(TextListWidget* self, int index) {
    if (index < 0 || index >= self->entries.count) {
        return 0;
    }
    return String_CStr(&self->entries.data[index]);
}
