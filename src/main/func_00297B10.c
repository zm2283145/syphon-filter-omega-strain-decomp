typedef struct V4 { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct Panel { char pad[0xB0]; V4 c0; V4 c1; V4 c2; } Panel;
typedef struct Self { char pad[0x10]; int state; char pad2[0x194 - 0x14]; Panel* panel; } Self;
extern V4 D_00587BA0, D_00587BB0, D_00587BC0;
extern void func_002982C0(Self*);
extern void func_0033D3A0(Self*);
static inline void SetV4(V4* d, V4 s) { d->x = s.x; d->y = s.y; d->z = s.z; d->w = s.w; }
void func_00297B10(Self* self)
{
    if (self->state == 1) {
        func_002982C0(self);
        self->state = -1;
    }
    if (self->panel) {
        SetV4(&self->panel->c0, D_00587BA0);
        SetV4(&self->panel->c1, D_00587BB0);
        SetV4(&self->panel->c2, D_00587BC0);
    }
    func_0033D3A0(self);
}
