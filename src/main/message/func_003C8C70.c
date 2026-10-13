#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
int Mem_Free(int, void*, char*, int);
extern char D_004BD118[];
extern int D_005435C0;
}
struct C8Obj { virtual void v0(int); int m4; int m8; };
typedef struct C8Node { struct C8Node* prev; struct C8Node* next; int key; C8Obj* data; } C8Node;
extern "C" {
extern struct C8Node D_005435C4;
extern C8Node* D_005435C8;
void func_003C9EA0(int* out, int* self, int* first, int* last);
}
extern "C" void MsgQueue_ClearPending(void)
{
    C8Obj* obj;
    int i;
    int n = D_005435C0;
    for (i = 0; i < n; i++) {
        int k = i;
        C8Node* p = D_005435C8;
        if (k >= 0) {
            while (k > 0) { p = p->next; k--; }
        } else {
            while (k < 0) { p = p->prev; k++; }
        }
        obj = p->data;
        obj->m8 = 0;
        {
            AllocGuard g;
            obj->v0(-1);
            Mem_Free(0, obj, D_004BD118, 0x1C2);
        }
    }
    {
        int r;
        int first;
        int last;
        last = (int)&D_005435C4;
        first = (int)D_005435C8;
        func_003C9EA0(&r, &D_005435C0, &first, &last);
    }
}


