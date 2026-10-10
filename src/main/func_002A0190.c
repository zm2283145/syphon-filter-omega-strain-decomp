#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */
extern char D_004AAF70[]; /* "GuiOnlineOfflineSelect" */

/* GuiOnlineOfflineSelect type check: true when name equals the class name "GuiOnlineOfflineSelect". */
int GuiOnlineOfflineSelect_IsType(void* self, const char* name) {
    return strcmp(D_004AAF70, name) == 0;
}
