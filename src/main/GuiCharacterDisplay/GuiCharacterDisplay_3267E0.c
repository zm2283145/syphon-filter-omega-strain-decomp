#include "types.h"
extern int strcmp(const char*, const char*);
/* Returns whether the string equals the table name. */
int GuiCharacterDisplay_IsType(void* a0, const char* s) { return strcmp("GuiCharacterDisplay", s) == 0; }
