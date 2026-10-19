/* Recursive time-scale propagation: the original's recursive inline expanded four levels,
   leaving out-of-line size()/operator[] template clones at each level. */
#pragma cplusplus on
struct Obj;
struct Vec { int cap; int n; Obj** p; };
struct Obj { char pad[0x9C]; Vec v; char padA8[0x134 - 0xA8]; float f134; };
extern "C" {
Obj*** func_00171EC0(Vec*);
int func_0023E5B0(Vec*);
int func_0023E5C0(Vec*);
int func_0023DA80(Vec*);
int func_0023DA90(Vec*);
Obj** func_0023DAB0(Vec*, int);
Obj** func_0023A550(Vec*, int);
Obj** func_0023DAA0(Vec*, int);
void cNIEventOBJ_SetSpeedRecursive(Obj* o, float t);
}
#pragma push
#pragma opt_strength_reduction off
extern "C" void cNIEventOBJ_SetSpeedRecursive(Obj* o, float t)
{
    o->f134 = t;
    for (int i = 0; i < o->v.n; i++) {
        Obj* a = (*func_00171EC0(&o->v))[i];
        a->f134 = t;
        for (int j = 0; j < func_0023E5B0(&a->v); j++) {
            Obj* b = *func_0023DAB0(&a->v, j);
            b->f134 = t;
            for (int k = 0; k < func_0023E5C0(&b->v); k++) {
                Obj* c = *func_0023A550(&b->v, k);
                c->f134 = t;
                for (int l = 0; l < func_0023DA80(&c->v); l++) {
                    Obj* d = *func_0023DAA0(&c->v, l);
                    d->f134 = t;
                    for (int m = 0; m < func_0023DA90(&d->v); m++)
                        cNIEventOBJ_SetSpeedRecursive(*func_0023DAA0(&d->v, m), t);
                }
            }
        }
    }
}

#pragma pop
