/* 00108440 (libmpeg, gcc29): 8 diffs with stock gcc29 build; 0 diffs (MATCH) when the gcc29 991111 cc1 output is assembled with the ee-gcc2.96 gas (asx.py). See NOTES.md 'gas finding'. */
typedef struct {
    char pad0[0xEC];
    int picStructure;
    char pad1[0x17C - 0xF0];
    int f_code[2][2];
    int picture_structure;
    int top_field_first;
    int frame_pred_frame_dct;
    int concealment_motion_vectors;
    int repeat_first_field;
    int progressive_frame;
} MpegCtx;

extern int _nextBit(void *, int);

#define IPU_CTRL ((volatile unsigned int *)0x10002010)

void _pictureCodingExtension(MpegCtx *m)
{
    int x;

    m->f_code[0][0] = _nextBit(m, 4);
    m->f_code[0][1] = _nextBit(m, 4);
    m->f_code[1][0] = _nextBit(m, 4);
    m->f_code[1][1] = _nextBit(m, 4);
    x = _nextBit(m, 2);
    *IPU_CTRL = (*IPU_CTRL & 0xFFFCFFFF) | (x << 16);
    m->picture_structure = _nextBit(m, 2);
    if (m->picStructure == 0) {
        m->picStructure = m->picture_structure;
    }
    m->top_field_first = _nextBit(m, 1);
    m->frame_pred_frame_dct = _nextBit(m, 1);
    m->concealment_motion_vectors = _nextBit(m, 1);
    x = _nextBit(m, 1);
    *IPU_CTRL = (*IPU_CTRL & 0xFFBFFFFF) | (x << 22);
    x = _nextBit(m, 1);
    *IPU_CTRL = (*IPU_CTRL & 0xFFDFFFFF) | (x << 21);
    x = _nextBit(m, 1);
    *IPU_CTRL = (*IPU_CTRL & 0xFFEFFFFF) | (x << 20);
    m->repeat_first_field = _nextBit(m, 1);
    _nextBit(m, 1);
    m->progressive_frame = _nextBit(m, 1);
    if (_nextBit(m, 1) != 0) {
        _nextBit(m, 1);
        _nextBit(m, 3);
        _nextBit(m, 1);
        _nextBit(m, 7);
        _nextBit(m, 8);
    }
}