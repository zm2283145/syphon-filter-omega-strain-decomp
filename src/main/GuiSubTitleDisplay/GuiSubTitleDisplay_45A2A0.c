#pragma cplusplus on
struct Msg {
    int a;
    unsigned char b0, b1, b2, b3;
    float x, y, z;
    int d;
    unsigned char e0, e1;
    float f;
    int g;
    Msg() {}
};
struct Obj { char pad[0x59D]; unsigned char ready; };
struct Net { Obj* obj; unsigned char busy; };
extern "C" {
extern Net D_0055A830;
extern int D_004979A0;
extern int MemCardWrap_Write(Net*, int, void*, int, int);
int GameOptions_WriteConfigFile(Msg* src);
}
int GameOptions_WriteConfigFile(Msg* src)
{
    Net* n = &D_0055A830;
    if (((n->busy != 0) ^ 1) && n->obj->ready) {
        Msg m(*src);
        int saved = m.g;
        int r;
        m.g = 0;
        r = MemCardWrap_Write(n, D_004979A0, &m, sizeof(Msg), 1);
        m.g = saved;
        return r != 0;
    }
    return 0;
}

