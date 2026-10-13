#include "types.h"
typedef struct { char pad[0x148]; struct { int pad0; int count; }* list; } F3814D0;
typedef struct { char pad[0x98]; F3814D0* f; } A3814D0;
typedef struct { char pad[8]; char** names; int pad0C; int count; } S3814D0;
typedef struct { int pad0; char path[0x9C]; } B3814D0;
extern void func_0036E5D0(void*);
extern void func_0036E220(void*, int);
extern int func_0036D200(void*, int);
extern void func_0036DFB0(void*, int, void*);
extern void func_0036DEF0(void*);
extern int String_CompareNoCase(char*, char*);
extern int strlen(char*);
extern void Tdx_Clone(void*, void*, int);
extern char D_004BC2C8[];

void func_003814D0(S3814D0* self, A3814D0* arg1)
{
    B3814D0 buf;
    char name[0x50];
    F3814D0* f = arg1->f;
    int n;
    int i;
    func_0036E5D0(&buf);
    n = f->list->count;
    for (i = 0; i < n; i++) {
        char* path = buf.path;
        func_0036DFB0(&buf, func_0036D200(f, i), arg1);
        func_0036DEF0(&buf);
        if (String_CompareNoCase(path + strlen(path) - 3, D_004BC2C8) == 0) {
            char* s = path;
            char* end = s + strlen(s);
            char* q = end;
            char* d;
            int idx;
            int j;
            while (*q != '\\' && q != s)
                q--;
            if (*q == '\\')
                s = q + 1;
            d = name;
            while (s != end && *s != '.')
                *d++ = *s++;
            *d = 0;
            idx = -1;
            for (j = 0; j < self->count; j++) {
                if (self->names[j] && String_CompareNoCase(name, self->names[j]) == 0)
                    break;
            }
            if (j < self->count)
                idx = j;
            if (idx != -1)
                Tdx_Clone(self, &buf, idx);
        }
    }
    func_0036E220(&buf, -1);
}

