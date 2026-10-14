typedef struct { char c[12]; } Name12;
typedef struct {
    short f0;
    Name12 name;
    char pad0E[0x28 - 0x0E];
    long f28;
    long f30;
    short f38;
    short f3A;
    short f3C;
    short f3E;
    short f40;
    char pad42[6];
    long f48;
    long f50;
    long f58;
    long f60;
    unsigned short f68;
    short f6A;
} S320570;
extern const char D_004B5E00[12];
extern float func_00121570(float x);
int func_00320570(S320570 *s)
{
    if (s == 0) return 0x181A;
    s->f0 = 4;
    __builtin_memcpy(&s->name, D_004B5E00, 12);
    s->f50 = 64;
    s->f58 = 64;
    s->f60 = 64;
    s->f28 = 100;
    s->f30 = 3000;
    s->f38 = 8000;
    s->f3A = 16;
    s->f3C = 160;
    s->f48 = 3200;
    s->f68 = (unsigned int)func_00121570(0.90625f);
    s->f3E = 1;
    s->f40 = 1;
    s->f6A = s->f68 * 160 - 0x91;
    return 0;
}




