#include "types.h"

extern char D_0053BB70[];
extern char D_0049AA00[]; /* format string */
extern void Skel_FreeAll(void* obj);
extern void sprintf(char* buf, const char* fmt, const char* arg); /* sprintf */
extern void ArchiveList_CloseNamed(void* str, const char* text);

/* Formats D_0049AA00 with "GAMEDATA" into a buffer and assigns it to the string at self+0x3C. */
void World_UnloadSkelHog(char* self) {
    char buf[128];
    Skel_FreeAll(D_0053BB70);
    sprintf(buf, D_0049AA00, "GAMEDATA");
    ArchiveList_CloseNamed(self + 0x3C, buf);
}
