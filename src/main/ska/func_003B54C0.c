#include "types.h"
extern int func_002071F0(void* s);
extern char* func_002071A0(void* s);
extern void Skas_RegisterClip(int* out, int a, char* name, unsigned int* desc);

void Skas_AppendAnimation(int a, void* str, unsigned int* desc)
{
    int out;
    char buf[0x30];
    if (*desc < 4) {
        int i;
        for (i = 0; i < 0x2F; i++) {
            char c;
            if (i < func_002071F0(str)) c = func_002071A0(str)[i]; else c = 0;
            buf[i] = c;
        }
        buf[i] = 0;
        Skas_RegisterClip(&out, a, buf, desc);
    }
}