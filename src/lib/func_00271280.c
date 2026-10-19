typedef struct { int f0; void* f4; int f8; int fc; int f10; } P271280;
unsigned int D_0048B2C8[2] = { 0x0, 0x0 };
extern P271280 D_004FFB00;
extern char D_004FF300[];
extern void DIntr();
extern void EIntr();
extern void func_00271488(void* p);
extern void func_00271368(int a);
extern int func_0010F748(unsigned int id, void (*cb)(void*), P271280* p);
extern int func_0010F948(unsigned int id, void* p, int n, int a, int b, int c);
extern int func_0010F418(int a);
extern int func_00118200(unsigned int id, void (*cb)(int), int a);
void func_00271280(void)
{
    int* q;
    if ((*(int*)D_0048B2C8) != 0) return;
    (*(int*)D_0048B2C8) = 1;
    DIntr();
    D_004FFB00.f8 = 0x20;
    D_004FFB00.f4 = (void*)((int)D_004FF300 | 0x20000000);
    D_004FFB00.f0 = 1;
    D_004FFB00.fc = 0;
    D_004FFB00.f10 = 0;
    func_0010F748(0x80000018, func_00271488, &D_004FFB00);
    EIntr();
    q = (int*)(D_004FF300 + 0x40);
    q[4] = 1;
    q[5] = 1;
    func_0010F948(0x80000001, q, 0x18, 0, 0, 0);
    while (func_0010F418(1) == 0);
    func_00118200(0x80000014, func_00271368, 0);
}