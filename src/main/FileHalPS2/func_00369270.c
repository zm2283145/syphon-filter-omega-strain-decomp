#pragma inline_depth(8)
#pragma opt_propagation off
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct {
    char pad0[0x28];
    int unk28;
    int unk2C;
    char pad30[0xC];
    int unk3C;
    unsigned char unk40;
    char pad41[0x83];
    void* unkC4;
} Strm369270;
extern "C" {
void* Mem_Alloc(int, int, char*, int);
void Mem_Free(int, void*, char*, int);
int func_00368F60(Strm369270*, int);
extern char D_004BBDD0[];
}

static inline void Copy_369270(void* d0, void* s0, int n0)
{
    int n = n0;
    __int128 u;
    int t;
    void* d = d0;
    void* s = s0;
    asm {
        .set noreorder
        blez n, done
        andi t, s, 0xF
        andi u, d, 0xF
        or t, t, u
        andi u, n, 0xF
        or t, t, u
        nop
        bgtz t, bytes
    quads:
        lq u, 0(s)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu s, s, 0x10
        bgtz n, quads
        sq u, -0x10(d)
        b done
        nop
    bytes:
        lb u, 0(s)
        addiu d, d, 1
        addi n, n, -1
        addiu s, s, 1
        bgtz n, bytes
        sb u, -1(d)
        .set reorder
    done:
    }
}

static inline int RoundUp_369270(int n)
{
    if (n % 2048 == 0)
        return n;
    n = (n / 2048) * 2048 + 0x800;
    asm { .set reorder }
    return n;
}

static inline int Read_369270(Strm369270* o, void* dst, int size, int arg3)
{
    int ret = 0;
    int r;
    if (!o->unk2C)
        return ret;
    r = RoundUp_369270(size);
    if (size < r && o->unk28 != 0x8000) {
        void* p;
        o->unk3C = r;
        {
            int n = o->unk3C;
            AllocGuard g;
            p = Mem_Alloc(0, n, D_004BBDD0, 0xAA);
        }
        o->unkC4 = p;
        ret = func_00368F60(o, arg3);
        if (ret) {
            Copy_369270(dst, o->unkC4, size);
            ret = size;
        }
        {
            void* q = o->unkC4;
            AllocGuard g;
            Mem_Free(0, q, D_004BBDD0, 0xB3);
        }
        o->unk3C = 0;
    } else {
        o->unk3C = size;
        o->unkC4 = dst;
        ret = func_00368F60(o, arg3);
    }
    return ret;
}

extern "C" int func_00369270(Strm369270* o, void* dst, int size, int arg3)
{
    int ret = Read_369270(o, dst, size, arg3);
    o->unk40 = 0;
    return ret;
}
