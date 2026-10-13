typedef struct Sub29B920 { char pad[0x14]; unsigned short flags; } Sub29B920;
typedef struct Obj29B920 {
    char pad0[0x78];
    int state;
    int t;
    char pad80[0xA8 - 0x80];
    Sub29B920* sub;
    char padAC[0xB4 - 0xAC];
    int mode;
} Obj29B920;
void func_0041E3B0(Obj29B920* o, float dt);
void func_0026BC20(float f);
unsigned long func_003698B0(void);
void func_002996D0(Obj29B920* o, int a);
void func_0029AE60(Obj29B920* o);
int func_0029BDB0(void);
void func_0029B920(Obj29B920* o, float dt)
{
    func_0041E3B0(o, dt);
    func_0026BC20(dt / 30.0f);
    if (o->state == 1) {
        if (func_003698B0() - o->t > 8000) {
            func_002996D0(o, 1);
        }
    }
    if (o->mode == 3) {
        func_0029AE60(o);
    } else if (o->sub != 0 && (o->sub->flags & 4)) {
        if (func_0029BDB0() < 2) {
            o->sub->flags &= ~4;
        }
    }
}


