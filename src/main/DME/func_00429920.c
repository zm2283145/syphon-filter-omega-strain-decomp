#pragma cplusplus on
#include "types.h"
typedef struct { int kind; int id; } Pk429920;
extern "C" {
extern unsigned char D_005723C8;
extern int D_005723F0;
extern int D_005721A8;
extern unsigned char D_00572410;
extern unsigned char D_005721D8;
extern char D_005721E0[];
extern char D_004BF9D0[];
extern unsigned char D_005724B0;
extern unsigned char D_00572418[];
extern int D_00572424[];
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern void func_002EBBA0(int session, int* out);
extern int snprintf(char* buf, int n, const char* fmt, ...);
extern void func_0043B190(void* p);
extern void func_0043ACB0(void* p, int id);
}

#pragma define_section GUARD_DTOR_9920 ".dtors_drop" far_absolute RX
/* Scoped busy flag; the guard object also reserves the top stack slot retail has. */
struct Guard_9920 {
    char c;
    Guard_9920() { if (!D_005723C8) D_005723C8 = 1; }
    /* order matters: weak first, then the section (see alloc_guard.h) */
    __declspec(weak) __declspec(GUARD_DTOR_9920) ~Guard_9920() { D_005723C8 = 0; }
};
extern "C" void func_00429920(Pk429920* p)
{
    Guard_9920 g;
    int buf;
    int slot;
    unsigned char ok;
    D_005723F0--;
    func_002EBBA0(D_005721A8, &slot);
    if (p->id == slot) {
        D_00572410 = 1;
        D_005721D8 = 1;
        snprintf(D_005721E0, 0x10, D_004BF9D0);
        D_005724B0 = 7;
    }
    D_00572418[p->id] = 1;
    if (D_005721C8) ok = D_005721C0; else ok = 1;
    if (ok) {
        if (D_00572424[3] == -1) D_00572424[3] = 0;
        else if (D_00572424[2] == -1) D_00572424[2] = 0;
        else if (D_00572424[1] == -1) D_00572424[1] = 0;
    }
    func_0043B190(&buf);
    func_0043ACB0(&buf, p->id);
}



