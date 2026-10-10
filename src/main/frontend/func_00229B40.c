#include "types.h"

extern char D_0053BB70[];
extern char D_004A62F0[]; /* format string */
extern char D_0048B2F8[];
extern void func_003AA320(void* obj);
extern void sprintf(char* buf, const char* fmt, const char* arg); /* sprintf */
extern void func_003F9530(void* str, const char* text);

/* Formats D_004A62F0 with D_0048B2F8 into a buffer and assigns it to str. */
void func_00229B40(void* self, void* str) {
    char buf[128];
    func_003AA320(D_0053BB70);
    sprintf(buf, D_004A62F0, D_0048B2F8);
    func_003F9530(str, buf);
}
