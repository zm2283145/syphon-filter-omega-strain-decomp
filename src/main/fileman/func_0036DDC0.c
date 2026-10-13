#pragma cplusplus on
#include "types.h"

struct Hdr_36DDC0 { char pad[0x10]; int f10; };
struct Arc_36DDC0 { char pad0[4]; int f4; char pad8[0x7C]; int f84; char pad88[0xC0]; Hdr_36DDC0* f148; };
struct FME_36DDC0 { int flags; char name[128]; short h84; int a88; int a8C; int a90; unsigned char b94; Arc_36DDC0* a98; };

extern "C" int func_0036D520(Arc_36DDC0*, int);

static inline int Off(Arc_36DDC0* a, int idx) { return a->f148->f10 + func_0036D520(a, idx); }

extern "C" int func_0036DDC0(FME_36DDC0* f)
{
    if (f->flags & 2) {
        int s = Off(f->a98, f->h84) / 2048;
        const int b = f->a98->f84;
        return b + s;
    }
    if (f->flags & 1) return f->a98->f4;
    return -1;
}
