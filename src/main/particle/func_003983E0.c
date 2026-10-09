/*
 * Matched functions (byte-identical with the retail executable).
 * ParticleRelFlag constructor.
 */

#include "types.h"
#include "particle_types.h"

extern Rel* func_00398410(Rel* r);

ParticleRelFlag* func_003983E0(ParticleRelFlag* self) {
    func_00398410(&self->rel);
    self->flag = 1;
    return self;
}
