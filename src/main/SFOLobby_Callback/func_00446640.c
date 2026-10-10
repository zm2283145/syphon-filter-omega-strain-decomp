#include "types.h"
typedef struct { char pad[0x18]; int kind; char name[1]; } Request;
typedef struct { int type; int pad; int kind; char name[0xA0]; } Record;
extern char* D_00585E60;
extern int func_004505C0(void* a0, void* a1, void* a2);
extern void* memset(void* p, int c, int n);
extern char* String_Copy(char* dst, const char* src);
extern void func_0044F470(void* list, Record* rec);
/* If func_004505C0 succeeds, queues a type-1 record built from the request. */
void func_00446640(void* a0, void* a1, void* a2, Request* req)
{
    Record rec;
    if (func_004505C0(a0, a1, a2) == 0) {
        memset(&rec, 0, sizeof(rec));
        rec.type = 1;
        rec.kind = req->kind;
        String_Copy(rec.name, req->name);
        func_0044F470(D_00585E60 + 0x1C, &rec);
    }
}
