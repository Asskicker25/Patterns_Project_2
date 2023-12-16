#include "ChangeColor.h"
#include "../../Utilities/Random.h"

ChangeColor::ChangeColor(BaseMaterial* material, glm::vec3 color)
{
    this->material = material;
    this->color = color;
}

ChangeColor::ChangeColor(BaseMaterial* material)
{
    this->material = material;

  
}

void ChangeColor::StartCommand()
{
    float randomX = GetRandomFloatNumber(0, 1);
    float randomY = GetRandomFloatNumber(0, 1);
    float randomZ = GetRandomFloatNumber(0, 1);

    color = glm::vec4(randomX, randomY, randomZ, 1);
}

void ChangeColor::Update()
{
    material->AsMaterial()->SetBaseColor(glm::vec4(color, 1.0f));
    colorChanged = true;
}

void ChangeColor::EndCommand()
{
    colorChanged = false;
    inProgress = false;
}

bool ChangeColor::IsCommandCompleted()
{
    return colorChanged;
}
