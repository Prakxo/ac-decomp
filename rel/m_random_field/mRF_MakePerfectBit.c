#include "random_field.h"
int mRF_MakePerfectBit(void) {
    int perfect_bit = 0;
    int i;
    for (i = 0; i < mRF_PERFECT_BIT; i++) {
        perfect_bit |= 1 << i;
    }

    return perfect_bit;
}
