#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */
extern char D_004ABC70[]; /* "GuiChatWindow" */

/* GuiChatWindow type check: true when name equals the class name "GuiChatWindow". */
int GuiChatWindow_IsType(void* self, const char* name) {
    return strcmp(D_004ABC70, name) == 0;
}
