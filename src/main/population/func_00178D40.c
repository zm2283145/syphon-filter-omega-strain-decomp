#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { int a[0x28]; } H178;
typedef struct { int f0; int f4; void* f8; void* fc; unsigned char b10; } P178;
extern "C" {
extern int sprintf(char*, const char*, ...);
extern void func_0036E540(H178*, char*, void*, int);
extern int func_0036DEF0(H178*);
extern void func_0036E140(H178*, char*, int, int);
extern int func_0036DE50(H178*);
extern void* Mem_Alloc(int, int, char*, int);
extern char D_0049CDA0[];
extern char D_0048B2F8[];
extern void func_0036D990(H178*, void**, int);
extern void func_0036DEC0(H178*);
extern void* func_0036DC60(H178*);
extern void func_0036E220(H178*, int);
}
extern "C" P178* Population_Load(P178* p, char* name, void* arg) {
    char buf[0x90];
    H178 h;
    sprintf(buf, "%s.pop", name);
    func_0036E540(&h, buf, arg, 0);
    if ((unsigned char)func_0036DEF0(&h)) {
        void* m;
        sprintf(buf, "%s\\%s\\DATA.POP", D_0048B2F8, name, name);
        func_0036E140(&h, buf, 0, 0);
        func_0036DEF0(&h);
        p->f4 = func_0036DE50(&h);
        p->b10 = 1;
        {
        int sz = p->f4;
        if (D_00533880) Alloc_Lock(9);
        D_00533888++;
        m = Mem_Alloc(1, sz, D_0049CDA0, 0x27);
        }
        if (D_00533880) Alloc_Unlock(9);
        D_00533888--;
        p->f8 = m;
        func_0036D990(&h, &p->f8, p->f4);
        func_0036DEC0(&h);
    } else {
        p->b10 = 0;
        p->f8 = func_0036DC60(&h);
        p->f4 = func_0036DE50(&h);
    }
    p->fc = p->f8;
    p->f0 = *(int*)p->fc;
    p->fc = (char*)p->fc + 4;
    func_0036E220(&h, -1);
    return p;
}
