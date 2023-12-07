#include "City.h"

City::City()
{
	model = new Model();
	phyObj = new PhysicsObject();

	InitializeEntity(this);


}

void City::Start()
{
}

void City::Update(float deltaTime)
{
}

void City::AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine)
{
	model->LoadModel("Assets/Models/FullCity.fbx");
	model->transform.SetRotation(glm::vec3(-90.0f,0,0));
	model->transform.SetScale(glm::vec3(1.0f));

	renderer->AddModel(model, shader);

}

void City::RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine)
{
}
