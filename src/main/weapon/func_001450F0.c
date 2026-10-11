#include "types.h"
extern char D_0049B210[];
extern char D_0048B2F8[];
extern char D_004FFB8C[];
extern int sprintf(char* buf, const char* fmt, ...);
typedef struct { char pad[0x10]; unsigned char loaded; char pad2[0xB]; char hog[4]; } S_HOG;
extern void func_00145200(S_HOG* self);
extern void func_003F9530(char* a, char* b);
extern void func_0036DEC0(void* p);
void func_001450F0(S_HOG* self)
{
    if (self->loaded) {
        char buf[0x80];
        func_00145200(self);
        sprintf(buf, D_0049B210, D_0048B2F8);
        func_003F9530(D_004FFB8C, buf);
        func_0036DEC0(self->hog);
        self->loaded = 0;
    }
}