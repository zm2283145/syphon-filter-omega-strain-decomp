#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { char* name; int count; int a, b; } N3A9;
extern "C" {
extern void func_0036DEF0(void*);
extern void func_0036D990(void*, int*, int);
extern void func_0036DEC0(void*);
extern void* Mem_Alloc(int, int, char*, int);
extern char D_004BCCF8[];
extern unsigned int strlen(const char*);
extern void String_Copy(char*, char*);
extern void func_003AA130(void*, N3A9**);
}
extern "C" void Skel_ReadFile(int* out, void* list, char* name, void* file) {
    int n[1];
    N3A9* tmp[1];
    int cnt;
    N3A9* node;
    n[0] = 0;
    func_0036DEF0(file);
    func_0036D990(file, n, 0);
    func_0036DEC0(file);
    cnt = n[0];
    {
        AllocGuard g;
        node = (N3A9*)Mem_Alloc(0, 0x10, D_004BCCF8, 0x60);
    }
    if (node) {
        int len = strlen(name) + 1;
        char* s;
        {
            AllocGuard g;
            s = (char*)Mem_Alloc(0, len, "skeleton.hh", 0x61);
        }
        node->name = s;
        node->count = cnt;
        String_Copy(node->name, name);
    }
    tmp[0] = node;
    func_003AA130(list, tmp);
    *out = cnt;
}
