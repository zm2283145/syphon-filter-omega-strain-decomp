#pragma cplusplus on
#pragma opt_strength_reduction off
struct Obj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F();
    virtual void v40(); virtual void v41();
    virtual void Activate(int on); /* +0x110 */
    char pad[0x64];
    int x68;
};
struct Rel { int a; int b; Obj** c; Obj*& at(int i) { return c[i]; } };
struct RelFlag { Rel rel; unsigned char flag; };
struct cInteractGOBJ {
    void* vtable;
    char pad04[0x64];
    int x68;
    char pad6C[4];
    int x70;
    Rel x74;
    char pad80[0x14];
    unsigned char x94;
    char pad95[3];
    RelFlag x98;
    Obj* xA8;
    Obj* xAC;
    unsigned char xB0;
    char padB1[3];
    int xB4;
    int xB8;
    int xBC;
};
extern "C" {
extern void cGameGOBJ_ctor(cInteractGOBJ* self, void* a1, void* a2, int kind);
extern Rel* func_00215F30(Rel* r);
extern void PtrVector_Resize(Rel* v, int n, int* fill);
extern char D_004DB160[];
cInteractGOBJ* cInteractGOBJ_ctor(cInteractGOBJ* self, void* a1, void* a2);
}
cInteractGOBJ* cInteractGOBJ_ctor(cInteractGOBJ* self, void* a1, void* a2)
{
    int i;
    cGameGOBJ_ctor(self, a1, a2, 5);
    self->vtable = D_004DB160;
    {
        RelFlag* rf = &self->x98;
        func_00215F30(&rf->rel);
        rf->flag = 1;
    }
    if (self->x70) {
        {
            int fill = 0;
            PtrVector_Resize(&self->x98.rel, self->x70 - 2, &fill);
        }
        self->xA8 = self->x74.at(self->x70 - 2);
        self->xAC = self->x74.at(self->x70 - 1);
        self->x70 -= 2;
        for (i = 0; i < self->x70; i++) {
            self->x98.rel.c[i] = self->x74.c[i];
            self->x98.rel.c[i]->Activate(0);
            if (self->x98.rel.c[i]->x68 == 3) {
                self->x68 = 7;
            }
        }
        {
            int fill = 0;
            PtrVector_Resize(&self->x74, 0, &fill);
        }
        self->x70 = 0;
    }
    self->xBC = 0;
    self->xB0 = 0;
    self->x94 = 0;
    self->xB4 = 0;
    self->xB8 = 0;
    return self;
}

