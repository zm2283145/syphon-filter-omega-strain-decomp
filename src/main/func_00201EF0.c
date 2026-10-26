typedef struct { float x, y, z; } Vec3;
typedef struct { float x, y, z, w; } Quat;
extern float Math_CosThunk(float);
extern float Math_SinThunk(float);

Quat* cQuaternion_ctor_cEulerAngleTR(Quat* q, Vec3* e) {
    float hx = 0.5f * e->x;
    float hy = 0.5f * e->y;
    float hz = 0.5f * e->z;
    float cx = Math_CosThunk(hx);
    float cy = Math_CosThunk(hy);
    float cz = Math_CosThunk(hz);
    float sx = Math_SinThunk(hx);
    float sy = Math_SinThunk(hy);
    float sz = Math_SinThunk(hz);
    float cycz = cy * cz;
    float sysz = sy * sz;
    float sycz = sy * cz;
    float cysz = cy * sz;
    q->w = cx * cycz - sx * sysz;
    q->x = sx * cycz - cx * sysz;
    q->y = cx * sycz + sx * cysz;
    q->z = cx * cysz + sx * sycz;
    return q;
}

