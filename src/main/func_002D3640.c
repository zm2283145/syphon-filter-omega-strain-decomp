#include "types.h"

typedef struct Linked208 {
    char pad000[0x1E8];
    void* resolved;              /* 0x1E8 */
    char pad1EC[0x1C];
    int handle;                  /* 0x208 */
    char pad20C[8];
    unsigned char flag0 : 1;     /* 0x214 */
    unsigned char flag1 : 1;
    unsigned char linked : 1;
    unsigned char rest : 5;
} Linked208;

extern void* func_0015DDB0(int handle);

/* Stores the handle, resolves it and marks the object linked. */
void func_002D3640(Linked208* obj, int handle) {
    obj->handle = handle;
    obj->resolved = func_0015DDB0(handle);
    obj->linked = 1;
}
