#pragma cplusplus on
extern "C" void operator_delete(void* allocation);
struct Vec25A { int cap; int count; int* data; };
struct VObj25A;

struct VObj25A { int head; virtual ~VObj25A(); };
struct GObj25A { void* vt; char pad[0xCC]; VObj25A* fD0; };
extern "C" {
extern Vec25A D_004F8040; extern int D_004F8044; extern int* D_004F8048;
extern char D_004DC5B0[];
void PtrVector_Resize(Vec25A* v, int n, int* fill);
void cGOBJ_dtor(void* self, short flag);
}
#pragma opt_strength_reduction off
extern "C" GObj25A* func_0025A1D0(GObj25A* self, short deleteFlag) {
    if (self) {
        self->vt = D_004DC5B0;
        {
            int i;
            int last = D_004F8044 - 1;
            int fill;
            for (i = 0; last >= i; i++) {
                int* e = &D_004F8048[i];
                if (*e == (int)self) {
                    *e = D_004F8048[last];
                    last--;
                }
            }
            fill = 0;
            PtrVector_Resize(&D_004F8040, last + 1, &fill);
        }
        {
            VObj25A* m = self->fD0;
            if (m) delete m;
        }
        cGOBJ_dtor(self, 0);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
#pragma opt_strength_reduction reset
