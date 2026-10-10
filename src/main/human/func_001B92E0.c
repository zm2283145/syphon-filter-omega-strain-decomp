#include "types.h"
typedef struct { float t; float v; } Endpoint;
typedef struct { Endpoint ep[2]; float scale; } AnimChannel;
/* Sets an endpoint's time and scaled value. */
void AnimChannel_UpdateEndpoint(AnimChannel* c, int i, float* t, float* v)
{
    float value = *v * c->scale;
    Endpoint* ep = &c->ep[i];
    ep->t = *t;
    ep->v = value;
}
