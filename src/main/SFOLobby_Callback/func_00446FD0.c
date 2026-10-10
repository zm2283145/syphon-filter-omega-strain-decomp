#include "types.h"
typedef struct { char pad[0x1C0]; int dirty; char p2[0x9B0 - 0x1C4]; char data[0xB8]; } G;
extern G* D_00585E60;
extern int func_004505C0(void*, void*, void*, void*);
extern void memcpy(void*, void*, int);
/* If the check fails, marks the global dirty and copies 0xB8 bytes of src into it. */
void func_00446FD0(void* a, void* b, void* c, void* src) { if (!func_004505C0(a, b, c, src)) { D_00585E60->dirty = 1; memcpy(D_00585E60->data, src, 0xB8); } }
