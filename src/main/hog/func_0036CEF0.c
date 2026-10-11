#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

typedef struct { int f0; int f4; int off8; int offC; int size; } HogHdr_36CEF0;
typedef struct {
    char name[0x80]; int stream; char pad84[0xAC - 0x84]; int size; char padB0[0x148 - 0xB0];
    HogHdr_36CEF0* hdr; unsigned char mode; char pad14D[3]; int f150; char* p154; char* buf;
    char* p15C; char* p160; int pool;
} Hog_36CEF0;
extern "C" {
extern char D_004BBF88[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
void String_Copy(char* d, char* s);
int func_003696B0(int* f, char* name, int mode);
void func_003695C0(int* f);
int func_00369270(int* f, void* buf, int size, int a3);
}
static inline void* Alloc_36CEF0(int pool, unsigned int n, int line) { AllocGuard g; return Mem_Alloc(pool, n, D_004BBF88, line); }

extern "C" int Hog_Load(Hog_36CEF0* self, char* name, int stream, int pool)
{
    int n;
    if (self->stream >= 0) return 0;
    if (!func_003696B0(&self->stream, name, 1)) return 1;
    String_Copy(self->name, name);
    n = (self->size / 0x800) * 0x800 + 0x800;
    if (!stream) {
        self->mode = 1;
        self->buf = (char*)Alloc_36CEF0(pool, n, 0xE2);
        if (!self->buf) {
            func_003695C0(&self->stream);
            return 3;
        }
        if (!func_00369270(&self->stream, self->buf, n, 0)) {
            { char* b = self->buf; AllocGuard g; Mem_Free(pool, b, D_004BBF88, 0xF2); }
            func_003695C0(&self->stream);
            return 2;
        }
        self->hdr = (HogHdr_36CEF0*)self->buf;
        self->p15C = self->buf + self->hdr->offC;
        self->p160 = self->buf + self->hdr->off8;
        func_003695C0(&self->stream);
    } else {
        HogHdr_36CEF0 h;
        self->mode = 2;
        func_00369270(&self->stream, &h, 0x14, 0);
        self->hdr = (HogHdr_36CEF0*)Alloc_36CEF0(pool, h.size, 0x104);
        func_00369270(&self->stream, self->hdr, h.size, 0);
        self->p15C = (char*)self->hdr + self->hdr->offC;
        self->p160 = (char*)self->hdr + self->hdr->off8;
    }
    self->f150 = 0;
    self->p154 = self->p15C;
    self->pool = pool;
    return 0;
}