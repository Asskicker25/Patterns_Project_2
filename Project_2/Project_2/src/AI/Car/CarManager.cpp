#include "CarManager.h"

CarManager& CarManager::GetInstance()
{
	static CarManager instance;
	return instance;
}

CarManager::CarManager()
{
	carFactory = new CarFactory();

	InitializeEntity(this);
}

void CarManager::SpawnCar(const std::string& carId, int type)
{
	BaseCar* car = carFactory->CreateCar(carId, type);
	//car->model->transform.SetPosition(glm::vec3(15, 9, 30));
}

void CarManager::LoadLuaScript()
{
	luaState = new LuaState(nullptr);
	luaState->LoadScript("LuaScripts/CarManager.lua");
	LuaManager::GetInstance().SetGlobalBinding(luaState->GetState());

	luaState->Execute();
}

void CarManager::Start()
{
}

void CarManager::Update(float deltaTime)
{
}

void CarManager::AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine)
{
	carFactory->AssignComponents(renderer, shader, physicsEngine);
}

void CarManager::RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine)
{
}

Transform* CarManager::GetTransform()
{
	return nullptr;
}
