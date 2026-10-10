#include "types.h"

extern char D_0053BB70[];
extern char D_0049AA00[]; /* format string */
extern char D_0048B2F8[];
extern void func_003AA320(void* obj);
extern void sprintf(char* buf, const char* fmt, const char* arg); /* sprintf */
extern void func_003F9530(void* str, const char* text);

/* Formats D_0049AA00 with D_0048B2F8 into a buffer and assigns it to the string at self+0x3C. */
void func_00130950(char* self) {
    char buf[128];
    func_003AA320(D_0053BB70);
    sprintf(buf, D_0049AA00, D_0048B2F8);
    func_003F9530(self + 0x3C, buf);
}
