#include "CarFactory.h"
#include "../../EntityManager/EntityManager.h"
#include "Car.h"

CarFactory::CarFactory()
{
	CacheCarModels();
}

BaseCar* CarFactory::CreateCar(const std::string& id, int type)
{
	Car* car = new Car();

	if (type == 0)
	{
		car->CreateInstance(*yellowCar);
	}
	else if (type == 1)
	{
		car->CreateInstance(*blueCar);
	}
	else if (type == 2)
	{
		car->CreateInstance(*redCar);
	}

	car->tag = id;

	renderer->AddModel(car->model, shader);
	physicsEngine->AddPhysicsObject(car->phyObj);


	EntityManager::GetInstance().AddEntity(id, car);

	car->LoadLuaScript();
	return nullptr;
}

void CarFactory::AssignComponents(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine)
{
	this->renderer = renderer;
	this->shader = shader;
	this->physicsEngine = physicsEngine;
}

void CarFactory::CacheCarModels()
{
	yellowCar = new Model("Assets/Models/YellowCar.fbx");
	yellowCar->meshes[0]->material->AsMaterial()->SetBaseColor(glm::vec4(0.8f, 0.7f, 0.1f, 1.0f));
	yellowCar->meshes[2]->material->AsMaterial()->SetBaseColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	yellowCar->meshes[3]->material->AsMaterial()->SetBaseColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	yellowCar->meshes[5]->material->AsMaterial()->SetBaseColor(glm::vec4(0.3f, 0.3f, 0.3f, 1.0f));
	yellowCar->meshes[6]->material->AsMaterial()->SetBaseColor(glm::vec4(0.8f, 0.8f, 0.8f, 1.0f));
	
	yellowCar->transform.SetScale(glm::vec3(5.0f));
	yellowCar->transform.SetRotation(glm::vec3(-90, 90, 0));

	yellowCar->isActive = false;

	blueCar = new Model("Assets/Models/BlueCar.fbx");
	blueCar->meshes[0]->material->AsMaterial()->SetBaseColor(glm::vec4(0.3f, 0.4f, 0.6f, 1.0f));
	blueCar->meshes[1]->material->AsMaterial()->SetBaseColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	blueCar->meshes[4]->material->AsMaterial()->SetBaseColor(glm::vec4(0.3f, 0.3f, 0.3f, 1.0f));
	blueCar->meshes[5]->material->AsMaterial()->SetBaseColor(glm::vec4(0.8f, 0.8f, 0.8f, 1.0f));

	blueCar->transform.SetScale(glm::vec3(5.0f));
	blueCar->transform.SetRotation(glm::vec3(-90, 90, 0));

	blueCar->isActive = false;

	redCar = new Model("Assets/Models/WhiteCar.fbx");
	redCar->meshes[0]->material->AsMaterial()->SetBaseColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	redCar->meshes[1]->material->AsMaterial()->SetBaseColor(glm::vec4(1.0f, 0.3f, 0.3f, 1.0f));
	redCar->meshes[2]->material->AsMaterial()->SetBaseColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	redCar->meshes[3]->material->AsMaterial()->SetBaseColor(glm::vec4(0.8f, 0.8f, 0.8f, 1.0f));
	redCar->meshes[5]->material->AsMaterial()->SetBaseColor(glm::vec4(0.3f, 0.3f, 0.3f, 1.0f));

	redCar->transform.SetScale(glm::vec3(5.0f));
	redCar->transform.SetRotation(glm::vec3(-90, 90, 0));

	redCar->isActive = false;

}
