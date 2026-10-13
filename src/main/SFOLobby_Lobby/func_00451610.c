extern void func_00452FC0(void* self, int x);
extern void func_0044F6B0(void* p);

typedef struct Lobby {
    char pad0[0x23EC];
    void* p23EC;
    void* p23F0;
    void* p23F4;
    char pad23F8[0x255C - 0x23F8];
    int state;
} Lobby;

void func_00451610(Lobby* self)
{
    if (self->state == 9) return;
    if (self->state == 5 || self->state == 0 || self->state == 10) {
        if (self->state != 10) {
            self->state = 9;
        }
        func_00452FC0(self, 0);
        if (self->p23EC) {
            func_0044F6B0(self->p23EC);
        }
        self->p23EC = 0;
        if (self->p23F4) {
            func_0044F6B0(self->p23F4);
        }
        self->p23F4 = 0;
        if (self->p23F0) {
            func_0044F6B0(self->p23F0);
        }
        self->p23F0 = 0;
        func_0044F6B0((char*)self + 0x8C);
        func_0044F6B0((char*)self + 0xA8);
        func_0044F6B0(self);
    }
}

