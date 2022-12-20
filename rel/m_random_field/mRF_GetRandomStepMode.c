#include "random_field.h"

int mRF_GetRandomStepMode(void) {
    return mRF_GetRandom(100) < 15;
}