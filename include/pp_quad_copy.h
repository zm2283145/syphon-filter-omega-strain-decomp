#ifndef PP_QUAD_COPY_H
#define PP_QUAD_COPY_H
/* Pipelined two-register 64-byte copy: lq a; lq b; sq a; lq a; sq b; lq b; sq a; sq b.
   Use inside a function compiled with #pragma peephole off (and usually
   opt_propagation off) so the source/destination pointers stay in registers. */
typedef union PPMtx { __int128 q[4]; float f[16]; } PPMtx;
#define PP_COPY4(d, s) { __int128 ppqa_, ppqb_; \
    ppqa_ = (s)->q[0]; ppqb_ = (s)->q[1]; \
    (d)->q[0] = ppqa_; ppqa_ = (s)->q[2]; \
    (d)->q[1] = ppqb_; ppqb_ = (s)->q[3]; \
    (d)->q[2] = ppqa_; \
    (d)->q[3] = ppqb_; }
/* Matrix transpose of the 3x3 part through a stack copy (cMatrix_InvertRot inlined).
   Needs peephole, opt_propagation and opt_common_subs off. */
#define PP_TRANSPOSE33_COPY(d, s) { PPMtx pptmp_; PPMtx* ppt_; PPMtx* ppp_; float ppx_; \
    ppt_ = &pptmp_; ppp_ = &pptmp_; \
    PP_COPY4(ppp_, s) \
    ppx_ = ppt_->f[1]; ppt_->f[1] = ppt_->f[4]; ppt_->f[4] = ppx_; \
    ppx_ = ppt_->f[2]; ppt_->f[2] = ppt_->f[8]; ppt_->f[8] = ppx_; \
    ppx_ = ppt_->f[6]; ppt_->f[6] = ppt_->f[9]; ppt_->f[9] = ppx_; \
    PP_COPY4(d, ppt_) }
#endif