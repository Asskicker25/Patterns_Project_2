#include "BaseCar.h"

Transform* BaseCar::GetTransform()
{
    return &model->transform;
}
