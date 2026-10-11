#pragma cplusplus on

typedef struct NetworkPeerSamples {
    unsigned int values[20];
} NetworkPeerSamples;

extern "C" {
extern NetworkPeerSamples D_00572270[];
int func_003FB8D0(void);
}

/* Average nonzero peer samples and cap the result with the retail NaN behavior. */
extern "C" float func_0042B320(int peer)
{
    float sum = 0.0f;
    int count = 0;
    if (!func_003FB8D0())
        return sum;
    for (int index = 0; index < 20; ++index) {
        unsigned int value = D_00572270[peer].values[index];
        if (value) {
            ++count;
            sum += (float)value;
        }
    }
    float result = (sum / (float)count) / 6144.0f;
    if (!(result <= 1.0f))
        result = 1.0f;
    return result;
}
