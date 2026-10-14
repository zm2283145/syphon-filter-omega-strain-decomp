#pragma cplusplus on
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
extern "C" {
int Alloc_Lock(int);
int Alloc_Unlock(int);
void* Mem_Alloc(int, int, char*, int);
int func_002728F0(void*, void*);
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_004A8EF0[];
}
struct Obj { char pad[0xC]; int id; };
static inline const int& GetId(Obj* o) { int tmp; if (o) return o->id; tmp = -1; return tmp; }
static inline int GetId2(Obj* o) { const int* p; int tmp; if (o) p = &o->id; else { tmp = -1; p = &tmp; } return *p; }
struct Flash {
    float a; float zero; float c; float d; float b; char pad14[0xC];
    V4 col; int f30; int f34;
};
extern "C" void VisionFx_RequestFlash(void* list, V4* col, float a, float b, float c, float d)
{
    Flash* f;
    Flash* q;
    Obj* const o = 0;
    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    f = (Flash*)Mem_Alloc(0, 0x40, D_004A8EF0, 0x59);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_00533888 -= 1;
    if (f != 0) {
        f->f34 = -2;
        f->f30 = 0;
        f->a = a;
        f->b = b;
        QC(&f->col, col);
        f->c = c;
        f->d = d;
        f->zero = 0.0f;
        f->f30 = 0;
{ int tmp[2]; const int* p; if (o) p = &o->id; else { tmp[1] = -1; p = &tmp[1]; } f->f34 = *p; }
    }
    q = f;
    func_002728F0(list, &q);
}
