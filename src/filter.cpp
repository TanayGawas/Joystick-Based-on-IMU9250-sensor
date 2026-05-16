#include "filter.h"

float lowPassFilter(float previous, float current, float alpha)
{
    return (alpha * current) + ((1.0f - alpha) * previous);
}