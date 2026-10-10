#pragma cplusplus on
#pragma exceptions off
#include "types.h"
struct Channel_1BD980 { int w[15]; };
struct ChannelVector_1BD980 {
    int f0;
    unsigned int count;
    Channel_1BD980* data;
    unsigned int size() const { return count; }
    Channel_1BD980* begin() { return data; }
    Channel_1BD980* end() { return data + count; }
};
extern "C" void AnimChannelVec_Grow(ChannelVector_1BD980* v, Channel_1BD980* pos, unsigned int n, const Channel_1BD980* fill);
extern "C" void func_001BEB20(ChannelVector_1BD980* v, Channel_1BD980* first, Channel_1BD980* last);
extern "C" void ChannelVector_Resize(ChannelVector_1BD980* v, unsigned int n, const Channel_1BD980* fill) {
    if (v->size() < n)
        AnimChannelVec_Grow(v, v->end(), n - v->size(), fill);
    else if (n < v->size())
        func_001BEB20(v, v->begin() + n, v->end());
}