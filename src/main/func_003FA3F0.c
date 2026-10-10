#include "types.h"
typedef struct { char name[0x80]; float v[4]; unsigned char kind; unsigned char used; short pad; int a94; int a98; int pad2; } C4Note3FA;
extern void func_003FA280(C4Note3FA* n, unsigned char kind, int z);
extern void String_Copy(char* d, const char* s);
void Notify_Insert(C4Note3FA* n, const char* name, float* v, unsigned char kind, int flush) {
    int i;
    if (flush) func_003FA280(n, kind, 0);
    for (i = 0; i < 8; i++, n++) {
        if (!n->used) {
            String_Copy(n->name, name);
            n->v[0] = v[0];
            n->v[1] = v[1];
            n->v[2] = v[2];
            n->v[3] = v[3];
            n->kind = kind;
            n->a98 = 0;
            n->a94 = 0;
            n->used = 1;
            return;
        }
    }
}