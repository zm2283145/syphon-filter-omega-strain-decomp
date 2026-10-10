#include "types.h"

typedef struct {
    char name[0x15];
    char label[0x13];
    int id;
    int kind;
    int value;
} Request;
typedef struct { char pad[0x2418]; char label[1]; } Obj;
extern char D_004C0F18[];
extern void* memset(void* p, int c, int n);
extern int sprintf(char* buf, const char* fmt, ...);
extern char* String_Copy(char* dst, const char* src);
extern void func_0046AC78(Request* req, void (*cb)(void));
extern void func_00446CA0(void);

/* Submits two requests (ids 4 and 7) carrying the object's label. */
void func_0044E1A0(Obj* self, int value)
{
    Request b;
    Request a;
    memset(&a, 0, sizeof(Request));
    sprintf(a.name, D_004C0F18, 4);
    String_Copy(a.label, self->label);
    a.id = 4;
    a.kind = 2;
    a.value = value;
    func_0046AC78(&a, func_00446CA0);
    memset(&b, 0, sizeof(Request));
    sprintf(b.name, D_004C0F18, 7);
    String_Copy(b.label, self->label);
    b.id = 7;
    b.kind = 2;
    b.value = 1;
    func_0046AC78(&b, func_00446CA0);
}
