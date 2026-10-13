#pragma cplusplus on
struct Vec { float x, y, z, w; };
struct Ctl {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void Update(); /* +0x58 */
    char pad04[0x44];
    float x48;
    char pad4C[4];
    unsigned char dirty;
};
struct Obj {
    char pad00[0x50];
    Ctl* ctl;
    Ctl* GetCtl() { Ctl* c = ctl; if (c->dirty) c->Update(); return c; }
};
struct Src {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36();
    virtual Vec GetPos(); /* +0xE4 */
};
struct cInteractGOBJ {
    char pad00[0x94];
    unsigned char x94;
    char pad95[0x13];
    Src* xA8;
    char padAC[4];
    unsigned char xB0;
    char padB1[3];
    Obj* riders[2];
};
struct Notice { char pad[0x30]; int who; };
static inline float Fabs(float x) { float r; asm { abs.s r, x } return r; }
extern "C" {
extern Obj* Object_LookupById(int* id);
extern int ObjectAction_SendKind7(Obj* obj, int action, cInteractGOBJ* target, int arg, float time);
void func_00216230(cInteractGOBJ* self, Notice* msg);
}
void func_00216230(cInteractGOBJ* self, Notice* msg)
{
    int id;
    Obj* o;
    int i;
    float d0;
    float d1;
    if (self->xB0) return;
    id = msg->who;
    o = Object_LookupById(&id);
    if (self->riders[0] == o) {
        self->riders[0] = 0;
        if (self->x94) {
            ObjectAction_SendKind7(o, 0x36, self, 0, -1.0f);
        } else {
            ObjectAction_SendKind7(o, 0x32, self, 0, -1.0f);
        }
        self->x94 = 0;
        return;
    }
    for (i = 1; i < 2; i++) {
        if (self->riders[i] == o) return;
    }
    if (self->riders[0] == 0) {
        if (self->xA8 == 0) return;
        float d;
        {
            Ctl* c = o->GetCtl();
            d = self->xA8->GetPos().z - c->x48;
        }
        self->riders[0] = o;
        if (Fabs(d) < 5.0f) {
            self->x94 = 1;
            ObjectAction_SendKind7(o, 0x35, self, 0, -1.0f);
            return;
        } else {
            ObjectAction_SendKind7(o, 0x31, self, 0, -1.0f);
            return;
        }
    }
    if (self->riders[1]) return;
    {
        Ctl* c = self->riders[0]->GetCtl();
        d0 = self->xA8->GetPos().z - c->x48;
    }
    {
        Ctl* c = o->GetCtl();
        d1 = self->xA8->GetPos().z - c->x48;
    }
    if (Fabs(d0) < 5.0f && Fabs(d1) < 5.0f) return;
    self->xB0 = 1;
    self->riders[1] = o;
    if (Fabs(d1) < 5.0f) {
        ObjectAction_SendKind7(o, 0x38, self, 0, -1.0f);
        ObjectAction_SendKind7(self->riders[0], 0x37, self, 0, -1.0f);
        return;
    }
    if (self->x94) {
        ObjectAction_SendKind7(self->riders[0], 0x38, self, 0, -1.0f);
        ObjectAction_SendKind7(o, 0x37, self, 0, -1.0f);
        self->x94 = 0;
        return;
    }
    ObjectAction_SendKind7(o, 0x34, self, 0, -1.0f);
    ObjectAction_SendKind7(self->riders[0], 0x33, self, 0, -1.0f);
}


