typedef struct { int f0; int pad[7]; int f20; } G6040;
typedef struct { int f0; int* p; int f8; } S6040;
extern G6040* D_00491474;
extern int D_0049147C;
extern void func_0010D190(int);
void func_00326040(S6040* s)
{
    *s->p = D_00491474->f20;
    s->f8 = D_00491474->f0;
    func_0010D190(D_0049147C);
}
