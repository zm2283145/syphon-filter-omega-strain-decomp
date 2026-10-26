/* Recursive time-scale propagation: the original's recursive inline expanded four levels,
   leaving out-of-line size()/operator[] template clones at each level. */
#pragma cplusplus on
struct Obj;
struct Vec { int cap; int n; Obj** p; };
struct Obj { char pad[0x9C]; Vec v; char padA8[0x134 - 0xA8]; float f134; };
extern "C" {
Obj*** std_vector_pod_int_data(Vec*);
int std_vector_pod_int_size(Vec*);
int std_vector_imp_cNIEventBasePtr_1_size(Vec*);
int std_vector_cNIEventBasePtr_size(Vec*);
int cArray_cNIEventBasePtr_Size(Vec*);
Obj** std_vector_imp_cNIEventBasePtr_1_opIndex(Vec*, int);
Obj** std_vector_cNIEventBasePtr_opIndex(Vec*, int);
Obj** cArray_cNIEventBasePtr_opIndex(Vec*, int);
void cNIEventOBJ_SetSpeedRecursive(Obj* o, float t);
}
#pragma push
#pragma opt_strength_reduction off
extern "C" void cNIEventOBJ_SetSpeedRecursive(Obj* o, float t)
{
    o->f134 = t;
    for (int i = 0; i < o->v.n; i++) {
        Obj* a = (*std_vector_pod_int_data(&o->v))[i];
        a->f134 = t;
        for (int j = 0; j < std_vector_pod_int_size(&a->v); j++) {
            Obj* b = *std_vector_imp_cNIEventBasePtr_1_opIndex(&a->v, j);
            b->f134 = t;
            for (int k = 0; k < std_vector_imp_cNIEventBasePtr_1_size(&b->v); k++) {
                Obj* c = *std_vector_cNIEventBasePtr_opIndex(&b->v, k);
                c->f134 = t;
                for (int l = 0; l < std_vector_cNIEventBasePtr_size(&c->v); l++) {
                    Obj* d = *cArray_cNIEventBasePtr_opIndex(&c->v, l);
                    d->f134 = t;
                    for (int m = 0; m < cArray_cNIEventBasePtr_Size(&d->v); m++)
                        cNIEventOBJ_SetSpeedRecursive(*cArray_cNIEventBasePtr_opIndex(&d->v, m), t);
                }
            }
        }
    }
}

#pragma pop
