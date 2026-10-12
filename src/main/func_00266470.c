#pragma cplusplus on
extern "C" void operator_delete(void* allocation);
struct Vec266 { int cap; int count; int* data; };
struct VObj266 { int head; virtual ~VObj266(); };
struct Obj266 {
    int f0, f4;
    char f8;
    char pad9[3];
    VObj266* fC;
    char m10[0x10];
    char m20[0x10];
};
extern "C" {
extern Vec266 D_004F8350; extern int D_004F8354; extern int* D_004F8358;
void PtrVector_Resize(Vec266* v, int n, int* fill);
void HeldItem_Release(Obj266* self);
void func_00266710(void* p);
void func_002665B0(void* p, short flag);
void func_00267270(void* p, short flag);
}
#pragma opt_strength_reduction off
extern "C" Obj266* func_00266470(Obj266* self, short deleteFlag) {
    if (self) {
        self->f8 = 0;
        HeldItem_Release(self);
        func_00266710(self->m10);
        {
            VObj266* m = self->fC;
            if (m) {
                delete m;
                self->fC = 0;
            }
        }
        {
            int i;
            int last = D_004F8354 - 1;
            int fill;
            for (i = 0; last >= i; i++) {
                int* e = &D_004F8358[i];
                if (*e == (int)self) {
                    *e = D_004F8358[last];
                    last--;
                }
            }
            fill = 0;
            PtrVector_Resize(&D_004F8350, last + 1, &fill);
        }
        {
            void* a = self->m20;
            if (a) func_002665B0(a, 0);
        }
        {
            void* b = self->m10;
            if (b) { if (b) { if (b) func_00267270(b, 0); } }
        }
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
#pragma opt_strength_reduction reset