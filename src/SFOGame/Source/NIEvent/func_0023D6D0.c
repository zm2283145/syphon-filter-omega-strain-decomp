#pragma cplusplus on
#include "types.h"
/* cNIEventBase::UpdateVis: advances the visibility track time, finds the active key
 * (wrapping to the out-of-range-type key when the track has run past its last key)
 * and reports whether the visibility flag changed. */
struct VisKey { float time; unsigned char visible; };
template <class T> struct cArray {
    int x0;
    int size;
    T* data;
    int xC;
    int Size() const { return size; }
    T& operator[](unsigned int i) { return data[i]; } /* std::vector::operator[](unsigned int) */
};
class cNIEventBase {
public:
    char pad0[0xC4];
    cArray<VisKey> mVisKeys;
    int mVisORT;
    float mVisTime;
    unsigned char mVisible;
};
extern "C" bool cNIEventBase_UpdateVis(cNIEventBase* self, float timeStep)
{
    int visKey = self->mVisKeys.Size() - 1;
    int i;
    float leftOver;
    unsigned char oldVis;
    if (visKey == 0) return false;
    self->mVisTime += timeStep;
    for (i = 0; i < self->mVisKeys.Size() - 1; i++) {
        if (self->mVisTime >= self->mVisKeys[i].time && self->mVisTime < self->mVisKeys[i + 1].time) {
            visKey = i;
            break;
        }
    }
    if (visKey == self->mVisKeys.Size() - 1) {
        if (self->mVisORT == -1) {
            self->mVisTime = self->mVisKeys[visKey].time;
            self->mVisible = self->mVisKeys[visKey].visible;
            return true;
        }
        leftOver = self->mVisTime - self->mVisKeys[visKey].time;
        visKey = self->mVisORT;
        self->mVisTime = leftOver + self->mVisKeys[visKey].time;
    }
    oldVis = self->mVisible;
    self->mVisible = self->mVisKeys[visKey].visible;
    return self->mVisible != oldVis;
}
