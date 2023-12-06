#include "Player.h"

Player::Player()
{
	model = new Model();
	phyObj = new PhysicsObject();

	InitializeEntity(this);

	entityId = "Player";


	luaState = new LuaState("Player", this);
	luaState->LoadScript("LuaScripts/Player.lua");
	luaState->Execute();
}

void Player::Start()
{
}

void Player::Update(float deltaTime)
{
}

void Player::AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine)
{
	model->LoadModel("Assets/Models/SpaceShip.fbx");
	model->transform.SetScale(glm::vec3(0.01f));
	renderer->AddModel(model, shader);

	phyObj->Initialize(model, SPHERE, DYNAMIC);
	physicsEngine->AddPhysicsObject(phyObj);

}

void Player::RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine)
{
}
