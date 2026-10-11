#include "types.h"
extern char D_0049B210[];
extern char D_0048B2F8[];
extern char D_004FFB8C[];
extern int sprintf(char* buf, const char* fmt, ...);
typedef struct { char pad[0x10]; unsigned char loaded; char pad2[0xB]; char hog[4]; } S_HOG;
extern char D_0049B228[];
extern void* Archive_Open(char* a, char* b, int c, int d);
extern void Hog_Register(void* hog, char* name, void* arc, int z);
extern void func_00146040(S_HOG* self, void* arc);
void func_00145160(S_HOG* self)
{
    if (!self->loaded) {
        char buf[0x80];
        void* arc;
        sprintf(buf, D_0049B210, D_0048B2F8);
        arc = Archive_Open(D_004FFB8C, buf, 0, 0);
        Hog_Register(self->hog, D_0049B228, arc, 0);
        func_00146040(self, arc);
        self->loaded = 1;
    }
}