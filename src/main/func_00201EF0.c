typedef struct { float x, y, z; } Vec3;
typedef struct { float x, y, z, w; } Quat;
extern float COS(float);
extern float SIN(float);

Quat* cQuaternion_ctor_cEulerAngleTR(Quat* q, Vec3* e) {
    float hx = 0.5f * e->x;
    float hy = 0.5f * e->y;
    float hz = 0.5f * e->z;
    float cx = COS(hx);
    float cy = COS(hy);
    float cz = COS(hz);
    float sx = SIN(hx);
    float sy = SIN(hy);
    float sz = SIN(hz);
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

