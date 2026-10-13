typedef struct Cam {
    char pad0[0xCF0];
    int cf0;
    int cf4;
    int cf8;
    char padCFC[8];
    int d04;
    int d08;
    char padD0C[4];
    float d10;
} Cam;
extern int func_0017A610(void);
extern void cGameCamera_v10(Cam *c, float dt);
#pragma opt_propagation off
#pragma opt_common_subs off
void PlayerCamera_PreUpdate(Cam *c, float dt)
{
    float d;
    float k;
    float z;
    c->cf0 = c->cf4;
    c->cf4 = c->cf8;
    k = func_0017A610() ? 0.125f : -1.0f;
    if (k < 0.0f) {
        c->d10 -= dt;
    } else {
        c->d10 = k;
    }
    z = 0.0f;
    d = c->d10;
    if (d <= z) {
        int tmp;
        int *pt;
        c->d04 = 0;
        tmp = -1;
        pt = &tmp;
        c->d08 = *pt;
        c->d10 = z;
    }
    cGameCamera_v10(c, dt);
}


