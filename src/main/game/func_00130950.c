#include "types.h"

extern char D_0053BB70[];
extern char D_0049AA00[]; /* format string */
extern void cSkeletonDataBank_Clear(void* obj);
extern void sprintf(char* buf, const char* fmt, const char* arg); /* sprintf */
extern void cHogList_Close(void* str, const char* text);

/* Formats D_0049AA00 with "GAMEDATA" into a buffer and assigns it to the string at self+0x3C. */
void cGameSystem_DestroySkeletons(char* self) {
    char buf[128];
    cSkeletonDataBank_Clear(D_0053BB70);
    sprintf(buf, D_0049AA00, "GAMEDATA");
    cHogList_Close(self + 0x3C, buf);
}
