#include "types.h"
typedef struct { int pad0; int count; } L450880;
typedef struct {
    int id; char name[0x20]; int f24; int f28; int f2C; int f30; int f34;
    char f38; char f39; char p3A[2]; int f3C; char f40[0xFC]; int f13C;
} E450880;
typedef struct { char p0[0xFC]; L450880 list; } S450880;
extern E450880* func_0044F290(L450880*, int);
extern void func_0044F470(L450880*, E450880*);
extern int func_00443E70(void);
extern void String_Copy(char*, char*);
extern void* memcpy(void*, const void*, int);
extern void* memset(void*, int, int);

static inline E450880* Find450880(L450880* list, int id)
{
    int n = list->count;
    int i;
    E450880* e;
    for (i = 0; i < n; i++) {
        e = func_0044F290(list, i);
        if (id == e->id)
            return e;
    }
    return 0;
}

void func_00450880(S450880* s, int id, char* name, int a3, unsigned char* data)
{
    E450880 tmp;
    E450880* e = Find450880(&s->list, id);
    if (data && *data != 0xB)
        data = 0;
    if (e) {
        if (e->f24 != a3) {
            e->f28 = 0;
            e->f2C = 0;
            e->f30 = 0;
        }
        if (data) {
            e->f39 = 1;
            e->f3C = func_00443E70();
            memcpy(e->f40, data, sizeof(e->f40));
        }
    } else {
        memset(&tmp, 0, sizeof(tmp));
        tmp.id = id;
        String_Copy(tmp.name, name);
        tmp.f24 = a3;
        if (data) {
            tmp.f39 = 1;
            tmp.f3C = func_00443E70();
            memcpy(tmp.f40, data, sizeof(tmp.f40));
        }
        func_0044F470(&s->list, &tmp);
    }
}
