#include "Player.h"
#include "../LuaManager/CommandManager/CommandManager.h"

Player::Player()
{
	model = new Model();
	phyObj = new PhysicsObject();

	InitializeEntity(this);

	entityId = "Player";
	tag = "Player";

	luaState = new LuaState( this);
	luaState->LoadScript("LuaScripts/Player.lua");


	CommandManager::GetInstance().BindGameObject(this);

	luaState->Execute();
}



void Player::Start()
{
}

void Player::Update(float deltaTime)
{
	/*followCurve->Update();
	followCurve->IsCommandCompleted();
	bezierPath->DrawCurve();*/
}

void Player::AddToRendererAndPhysics(Renderer* renderer, Shader* shader, PhysicsEngine* physicsEngine)
{
	this->renderer = renderer;

	model->LoadModel("Assets/Models/SpaceShip.fbx");
	model->transform.SetScale(glm::vec3(0.01f));
	renderer->AddModel(model, shader);

	phyObj->Initialize(model, SPHERE, DYNAMIC,TRIGGER,true);
	phyObj->userData = this;

	phyObj->AssignCollisionCallback([this](PhysicsObject* other)
		{
			Entity* entity = (Entity*)other->userData;
			std::string otherTag = entity->tag;

			std::unordered_map <std::string, CommandGroup*>::iterator it = listOfCollisionGroups.find(otherTag);


			if (it != listOfCollisionGroups.end())
			{
				Debugger::Print("Collided With : ", otherTag);
				it->second->conditionMet = true;
			}
		});

	physicsEngine->AddPhysicsObject(phyObj);

}

void Player::RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine)
{
}

Transform* Player::GetTransform()
{
	return &model->transform;
}

