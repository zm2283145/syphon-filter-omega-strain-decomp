// cNIEventFloatTrack::Update. cHermiteSpline built via default ctor + Init() member (array-ctor do-while in Init) and
// `cHermiteSpline* hp = &FloatSpline; hp->Init(...)` so the this-pointer vreg is created before the arg vregs (fixes t1/t2 coloring).
#pragma cplusplus on

struct Key { float time; float value; float inTan; float outTan; };
struct cArray { int cap; int count; Key* data; int pad; int Count() const { return count; } Key& operator[](unsigned int i) { return data[i]; } };
struct CP { float value; float tangent; CP() {} };
struct cHermiteSpline {
    CP mControlPoints[2];
    void Init(const float& p0, float m0, const float& p1, float m1) { cHermiteSpline* t = this; CP* p = t->mControlPoints; do { p++; } while (p != t->mControlPoints + 2); t->mControlPoints[0].value = p0; t->mControlPoints[0].tangent = m0; t->mControlPoints[1].value = p1; t->mControlPoints[1].tangent = m1; }
    cHermiteSpline() {}
    cHermiteSpline(const float& p0, float m0, const float& p1, float m1)
    {
        cHermiteSpline* t = this; CP* p = t->mControlPoints; do { p++; } while (p != t->mControlPoints + 2);
        t->mControlPoints[0].value = p0;
        t->mControlPoints[0].tangent = m0;
        t->mControlPoints[1].value = p1;
        t->mControlPoints[1].tangent = m1;
    }
    float Evaluate(float t)
    {
        float t2 = t * t;
        float t3 = t2 * t;
        CP* a = &mControlPoints[0];
        CP* b = &mControlPoints[1];
        float h00 = 2.0f * t3 - 3.0f * t2 + 1.0f; float h01 = -2.0f * t3 + 3.0f * t2; float h10 = t3 - 2.0f * t2 + t; float h11 = t3 - t2; return h00 * a->value + h01 * b->value + h10 * a->tangent + h11 * b->tangent;
    }
};
struct cNIEventFloatTrack {
    float mValue;
    cArray mFloatKeys;
    int mFloatORT;
    float mFloatTime;
    unsigned char mPlaying;
    Key& K(int i) { return mFloatKeys[i]; }
    cArray& Keys() { return mFloatKeys; }
};
extern "C" unsigned char cNIEventFloatTrack_Update(cNIEventFloatTrack* self, float timeStep);

unsigned char cNIEventFloatTrack_Update(cNIEventFloatTrack* self, float timeStep)
{
    int floatKey = self->mFloatKeys.Count() - 1;
    float floatScalar;
    float timeSpan;
    int i;
    if (!self->mPlaying || floatKey == 0)
        return 0;
    floatScalar = 0.0f;
    self->mFloatTime += timeStep;
    for (i = 0; i < self->mFloatKeys.Count() - 1; i++) {
        if (self->mFloatTime >= self->mFloatKeys[i].time && self->mFloatTime < self->mFloatKeys[i + 1].time) {
            floatKey = i;
            timeSpan = self->Keys()[i + 1].time - self->Keys()[i].time;
            floatScalar = (self->mFloatTime - self->Keys()[i].time) / timeSpan;
            break;
        }
    }
    if (floatKey == self->mFloatKeys.Count() - 1) {
        if (self->mFloatORT == -1) {
            self->mFloatTime = self->mFloatKeys[floatKey].time;
            self->mValue = self->mFloatKeys[floatKey].value;
            self->mPlaying = 0;
            return 1;
        }
        floatKey = self->mFloatORT;
        self->mFloatTime = self->mFloatKeys[floatKey].time;
        timeSpan = self->mFloatKeys[floatKey + 1].time - self->mFloatKeys[floatKey].time;
        floatScalar = self->mFloatTime / timeSpan;
    }
    cHermiteSpline FloatSpline;
    cHermiteSpline* hp = &FloatSpline;
    hp->Init(self->mFloatKeys[floatKey].value, timeSpan * self->mFloatKeys[floatKey].outTan,
                               self->mFloatKeys[floatKey + 1].value, timeSpan * -self->mFloatKeys[floatKey + 1].inTan);
    self->mValue = FloatSpline.Evaluate(floatScalar);
    return 1;
}
