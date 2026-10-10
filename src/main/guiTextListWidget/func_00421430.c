#include "guiTextListWidget_types.h"

extern char* func_001692D0(const void* text);

/* Return the selected entry's string data, or null for an invalid index. */
char* func_00421430(TextListWidget* self, int index) {
    if (index < 0 || index >= self->entries.count) {
        return 0;
    }
    return func_001692D0(&self->entries.data[index]);
}
