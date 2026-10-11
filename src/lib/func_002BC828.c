typedef struct { int f0; int f4; int pad[7]; int f24; } SC828;
extern SC828 D_0051ECC0;
extern void* memset(void* s, int c, unsigned int n);
void func_002BC828(void)
{
    SC828* s = &D_0051ECC0;
    memset(s, 0, 0x28);
    s->f24 = 0;
    s->f4 = -1;
}
