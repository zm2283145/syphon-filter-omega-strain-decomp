#include "hdr.h"
static inline cQuaternion GetInverse0(const cQuaternion& s) { cQuaternion r(s); r.Invert(); return r; }
static inline cQuaternion GetInverse(const cQuaternion& s) { return GetInverse0(s); }
static inline cVector CrossW(const cVector& a, const cVector& b) { return Cross(a, b); }
static inline unsigned char AJL_I(cQuaternion& o, const cQuaternion& i, const cJointLimits& l) { return ApplyJointLimits(o, i, l); }
static inline unsigned char AJL_I_I(cQuaternion& o, const cQuaternion& i, const cJointLimits& l) { return AJL_I(o, i, l); }
static inline unsigned char AJL_I_I_I(cQuaternion& o, const cQuaternion& i, const cJointLimits& l) { return AJL_I_I(o, i, l); }
#define ACJL(rot, limits, c) { rot.Rotate(GetInverse(c)); AJL_I_I_I(rot, rot, limits); rot.Rotate(c); }
extern "C" void nIk_TwoLimbIK(cQuaternion& new_pivotARot_parentRel, cQuaternion& new_pivotBRot_parentRel,
    const cVector& targetPos, const cVector& pivotAPos, const cQuaternion& pivotARot_parentRel_input,
    const cJointLimits& pivotA_oneOverLimitSinHalfAngleSquared, const cQuaternion& pivotA_centeringTransform,
    const cVector& pivotBPos, const cQuaternion& pivotBRot_parentRel_input,
    const cJointLimits& pivotB_oneOverLimitSinHalfAngleSquared, const cQuaternion& pivotB_centeringTransform,
    const cQuaternion& parentRot, const cVector& endPointPos)
{
    cQuaternion pivotARot_parentRel(pivotARot_parentRel_input);
    cQuaternion pivotBRot_parentRel(pivotBRot_parentRel_input);
    NegateIfWNegative(pivotARot_parentRel);
    NegateIfWNegative(pivotBRot_parentRel);
    cQuaternion pivotARot(pivotARot_parentRel.GetRotated(parentRot));
    cQuaternion pivotBRot(pivotBRot_parentRel.GetRotated(pivotARot));
    cVector neg_pivotAPos(-pivotAPos);
    cQuaternion pivotADeltaRot;
    cQuaternion pivotBDeltaRot;
    cQuaternion new_pivotARot;
    cQuaternion new_pivotBRot;
    cVector new_pivotBPos;
    cVector new_endPointPos;

    float distToTarget;
    cVector pivotAToTargetDir((targetPos - pivotAPos).Normalize(distToTarget));
    float limbBLength = (endPointPos - pivotBPos).Length();
    cVector pivotAToEndPointDir((endPointPos - pivotAPos).Normalize());
    pivotADeltaRot.SetRotationArc(pivotAToEndPointDir, pivotAToTargetDir);
    new_pivotBPos = (pivotBPos + neg_pivotAPos).Rotate(pivotADeltaRot) += pivotAPos;
    float limbALength;
    cVector pivotAToNewPivotBDir((new_pivotBPos - pivotAPos).Normalize(limbALength));
    float cosTargetAngle = CLAMP4_I((SQUARE_I(limbALength) + SQUARE_I(distToTarget) - SQUARE_I(limbBLength)) / (2.0f * limbALength * distToTarget), -1.0f, 1.0f);
    cVector axis(CrossW(pivotAToTargetDir, pivotAToNewPivotBDir));
    if (!axis.IsZeroXYZ()) {
        axis.Normalize();
        float sinTargetAngle = SQRT_I(1.0f - SQUARE_I(cosTargetAngle));
        float cosCurrAngle = Dot(pivotAToTargetDir, pivotAToNewPivotBDir);
        float sinCurrAngleSquaredClamped = CLAMP_LOW_I(1.0f - SQUARE_I(cosCurrAngle), 0.0f);
        float sinCurrAngle = SQRT_I(sinCurrAngleSquaredClamped);
        float cosDeltaAngle = cosTargetAngle * cosCurrAngle + sinTargetAngle * sinCurrAngle;
        float half_cosDeltaAngle = CLAMP4_I(0.5f * cosDeltaAngle, -0.5f, 0.5f);
        float cosHalfDeltaAngle = SQRT_I(0.5f + half_cosDeltaAngle);
        float sinHalfDeltaAngle = SQRT_I(0.5f - half_cosDeltaAngle);
        if (cosTargetAngle > cosCurrAngle) {
            sinHalfDeltaAngle = -sinHalfDeltaAngle;
        }
        cVector axis_X_sinHalfDeltaAngle(axis * sinHalfDeltaAngle);
        cQuaternion deltaRot(axis_X_sinHalfDeltaAngle, cosHalfDeltaAngle);
        pivotADeltaRot.Rotate(deltaRot);
        new_pivotARot = pivotARot.GetRotated(pivotADeltaRot);
        new_pivotARot_parentRel = new_pivotARot.GetRotated(cQuaternion_GetConjugate(&parentRot));
        ACJL(new_pivotARot_parentRel, pivotA_oneOverLimitSinHalfAngleSquared, pivotA_centeringTransform);
        new_pivotARot = new_pivotARot_parentRel.GetRotated(parentRot);
        pivotADeltaRot = GetInverse(pivotARot).Rotate(new_pivotARot);
        new_pivotBPos = (pivotBPos + neg_pivotAPos).Rotate(pivotADeltaRot) += pivotAPos;
        new_endPointPos = (endPointPos + neg_pivotAPos).Rotate(pivotADeltaRot) += pivotAPos;
    } else {
        new_pivotARot = pivotARot;
        new_pivotARot_parentRel = pivotARot_parentRel;
        new_pivotBPos = pivotBPos;
        new_endPointPos = endPointPos;
    }
    cVector newPivotBToTargetDir((targetPos - new_pivotBPos).Normalize());
    cVector newPivotBToNewEndPointDir((new_endPointPos - new_pivotBPos).Normalize());
    pivotBDeltaRot.SetRotationArc(newPivotBToNewEndPointDir, newPivotBToTargetDir);
    new_pivotBRot = pivotBRot.GetRotated(pivotADeltaRot).Rotate(pivotBDeltaRot);
    new_pivotBRot_parentRel = new_pivotBRot.GetRotated(cQuaternion_GetConjugate(&new_pivotARot));
    ACJL(new_pivotBRot_parentRel, pivotB_oneOverLimitSinHalfAngleSquared, pivotB_centeringTransform);
}
