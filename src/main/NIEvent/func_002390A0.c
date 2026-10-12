#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct PopReader_2390A0 { int version; int size; unsigned int base; char* cur; };
extern "C" {
extern char D_004A6FA8[];
extern char** D_004F7C70;
extern int D_004F7C78;
extern int D_004F7C80;
extern int D_0048AE28;
void* Mem_Alloc(int pool, int size, char* file, int line);
int Pop_FindTag(PopReader_2390A0* r, int tag);
int strlen(const char* s);
void String_Copy(char* d, const char* s);
}
extern "C" void func_002390A0(PopReader_2390A0* r)
{
    int mis;
    D_004F7C80 = 0;
    D_0048AE28 = -1;
    mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
    if ((unsigned char)Pop_FindTag(r, 0x3A53494E)) {
        D_004F7C78 = *(int*)r->cur;
        r->cur += 4;
        if (D_004F7C78) {
            int i;
            {
                char** p;
                {
                    int sz = D_004F7C78 * 4;
                    AllocGuard g;
                    p = (char**)Mem_Alloc(0, sz, D_004A6FA8, 0x680);
                }
                D_004F7C70 = p;
            }
            for (i = 0; i < D_004F7C78; i++) {
                char* p;
                char* s = r->cur;
                while (*r->cur++)
                    ;
                mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
                if (mis)
                    r->cur += 4 - mis;
                {
                    int len = strlen(s) + 1;
                    AllocGuard g;
                    p = (char*)Mem_Alloc(0, len, D_004A6FA8, 0x686);
                }
                D_004F7C70[i] = p;
                String_Copy(D_004F7C70[i], s);
                if (r->version >= 0x43) {
                    int v = *(int*)r->cur;
                    r->cur += 4;
                    if (D_0048AE28 == -1)
                        D_0048AE28 = v;
                    if (D_0048AE28 == v)
                        D_004F7C80++;
                }
            }
        }
    }
}


