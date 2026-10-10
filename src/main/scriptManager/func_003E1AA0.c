#pragma cplusplus on
#include "types.h"

class FiltObjE6 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual int GetType();
};

typedef struct FiltScratchE6 { int w[16]; } FiltScratchE6;

extern "C" unsigned char D_004938D0;
extern "C" unsigned char ScriptFilter_RunPass(void* filter, int type, int arg, FiltScratchE6* scratch, int mode, int pass);

/* Runs both filter passes for an object; true if either accepted it. */
extern "C" unsigned char ScriptFilter_Dispatch(void* filter, FiltObjE6* obj, int arg)
{
    unsigned char result = 0;
    if (D_004938D0) {
        FiltScratchE6 scratch;
        result = ScriptFilter_RunPass(filter, obj->GetType(), arg, &scratch, 2, 0);
        if (ScriptFilter_RunPass(filter, obj->GetType(), arg, &scratch, 2, 1)) {
            result = 1;
        }
    }
    return result;
}