#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { unsigned int word; unsigned int length; char* data; } Str_5310;
struct Buf_5310 { char* p; };
typedef struct { int a; char name[1]; } File_5310;
typedef struct { char pad[0x14]; char list[1]; } Self_5310;
extern "C" {
int func_0036DEF0(File_5310* f);
int FileMan_GetSize(File_5310* f);
int func_0036D990(File_5310* f, char** buf, int size);
void func_0036DEC0(File_5310* f);
void* Mem_Alloc(int a, int size, char* file, int line);
void String_CtorCStr_13B480(Str_5310* s, char* c);
void String_Dtor(Str_5310* s, int f);
void Skas_AppendAnimation(Self_5310* self, Str_5310* s, char* buf);
void func_00146000(void* list, struct Buf_5310* buf);
extern char D_004BCD70;
}
static inline void MemCopy_5310(void* dst, void* src, int n0)
{
    int n = n0;
    int t;
    int m;
    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
        nop
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}
extern "C" void func_003B5310(Self_5310* self, File_5310* f)
{
    Buf_5310 buf;
    Buf_5310 tmp;
    int size;
    int r;
    if (func_0036DEF0(f) & 0xFF) return;
    size = FileMan_GetSize(f);
    { char* p; { AllocGuard g; p = (char*)Mem_Alloc(0, size, &D_004BCD70, 0x1A3); } buf.p = p; }
    if (!buf.p) return;
    tmp = buf;
    r = func_0036D990(f, &tmp.p, size);
    func_0036DEC0(f);
    if (r & 0xFF) return;
    { char* dst; char* src = tmp.p; dst = buf.p; if (src != dst) MemCopy_5310(dst, src, size); }
    {
        Str_5310 s;
        String_CtorCStr_13B480(&s, f->name);
        Skas_AppendAnimation(self, &s, buf.p);
        String_Dtor(&s, 0);
    }
    func_00146000(self->list, &buf);
}



