typedef struct Node {
    char pad0[0x34];
    int id;
} Node;
typedef struct Obj {
    char pad0[0x5C];
    int x5C;
    char pad60[4];
    int x64;
    char pad68[4];
    Node *x6C;
    int x70;
    char pad74[0x8C - 0x74];
    int x8C;
    char pad90[0xA4 - 0x90];
    int xA4;
    int xA8;
    int xAC;
    int xB0;
    int xB4;
    int xB8;
} Obj;
extern int func_002ED890(int);
extern int func_002D9E30(Obj *, int);
extern void func_002ED838(int);
extern void func_002DABD8(Obj *, int);
extern void func_002F39B8(int);
extern void func_00306F98(int);
extern void func_002D7740(int);
extern void func_002FB3C0(Obj **);
void func_002D8E40(Obj *o)
{
    if (o == 0)
        return;
    while (o->x64 != 0)
        func_002ED838(func_002D9E30(o, func_002ED890(o->x64)));
    while (o->x6C != 0)
        func_002DABD8(o, o->x6C->id);
    if (o->x5C != 0) {
        func_002F39B8(o->x5C);
        o->x5C = 0;
    }
    if (o->x8C != 0) {
        func_00306F98(o->x8C);
        o->x8C = 0;
    }
    if (o->xA4 != 0) {
        func_002D7740(o->xA4);
        o->xA4 = 0;
    }
    if (o->xA8 != 0) {
        func_002D7740(o->xA8);
        o->xA8 = 0;
    }
    if (o->xAC != 0) {
        func_002D7740(o->xAC);
        o->xAC = 0;
    }
    if (o->xB0 != 0) {
        func_002D7740(o->xB0);
        o->xB0 = 0;
    }
    if (o->xB4 != 0) {
        func_002D7740(o->xB4);
        o->xB4 = 0;
    }
    if (o->xB8 != 0) {
        func_002D7740(o->xB8);
        o->xB8 = 0;
    }
    o->x70 = 0;
    func_002FB3C0(&o);
}
