typedef struct { char pad0[0x14]; unsigned short flags; } W_299AA0;
typedef struct {
    char pad0[0x8C];
    W_299AA0* tabs[4];
    char* labels[4];
    char padAC[4];
    void* xB0;
    int xB4;
    char padB8[0x430 - 0xB8];
    void* x430;
    char pad434[0x448 - 0x434];
    char* names[4];
} S_299AA0;
extern char D_004AA780[];
void func_0041BEB0(void* w, char* text, int c);
void func_00424430(void* w, int a, int b);
void func_002999B0(S_299AA0* self);

void func_00299AA0(S_299AA0* self, int idx) {
    int i;
    for (i = 0; i < 4; i++) {
        if (self->tabs[i]) {
            self->tabs[i]->flags &= ~2;
        }
    }
    if (self->xB0 && self->labels[idx]) {
        func_0041BEB0(self->xB0, self->names[idx] ? self->names[idx] : D_004AA780, 0);
    }
    self->tabs[idx]->flags |= 2;
    switch (idx) {
    case 3:
        if (self->x430) {
            func_00424430(self->x430, 0, 0);
        }
        break;
    }
    self->xB4 = idx;
    func_002999B0(self);
}

