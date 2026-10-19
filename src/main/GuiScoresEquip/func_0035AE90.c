#include "types.h"
extern int strcmp(const char*, const char*);
/* Returns whether the string equals the table name. */
int GuiScoresEquip_IsType(void* a0, const char* s) { return strcmp("GuiScoresEquip", s) == 0; }
