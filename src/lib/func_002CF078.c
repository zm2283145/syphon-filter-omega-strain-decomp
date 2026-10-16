typedef struct { char pad[0x1C]; int f1C; char f20[0x10]; int f30; int f34; } Msg_F078;
typedef struct { int f0; void* f4; char f8[0x18]; } Ctx_F078;
extern short D_0048C414;
extern int D_0048C3D8;
extern int D_0048C3DC;
extern int D_0048C384;
extern int func_002D0EB8(void *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int __attribute__((weak, section(".dtors_drop"))) func_002CEBC0(void) { return 0; }
extern int func_002CEBE0(void);
extern int func_002EA8C8(void *);
extern void func_002CEC70(void *);
extern void func_002CE8B0(void);
extern void func_002CE748(int);
extern void func_002CE908(int, void *);
extern int func_002EA960(void *, void *);
extern void func_002EB910(void *);
int func_002CF078(Msg_F078 *a, int b)
{
    Ctx_F078 s;
    char t[0x10];
    func_002D0EB8(a, 0x15);
    if (D_0048C414 != 1) return -0xC;
    D_0048C3DC = b;
    if (func_002CEBC0() == 1 || func_002CEBC0() == 2) {
        if (func_002EA8C8(&s)) return -5;
        func_002CEC70(s.f8);
        s.f4 = func_002CE8B0;
        func_002CE748(4);
        func_002CE908(0, a);
        if (func_002EA960(&s, t) == 0) return 0;
        func_002CE748(0);
        return -5;
    }
    if (func_002CEBC0() != 0 && func_002CEBC0() != 4) return -0xD;
    a->f1C = 1;
    func_002EB910(a->f20);
    a->f30 = func_002CEBE0();
    a->f34 = 0;
    return Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C384, 0x4C, a) ? -5 : 0;
}

