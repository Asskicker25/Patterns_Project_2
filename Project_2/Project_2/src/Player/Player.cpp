#include "Player.h"
#include "../LuaManager/CommandManager/CommandManager.h"

Player::Player()
{
	model = new Model();
	phyObj = new PhysicsObject();

	InitializeEntity(this);

	bezierPath = new CubicBezierCurve(0.01f);

	entityId = "Player";


	luaState = new LuaState( this);
	luaState->LoadScript("LuaScripts/Player.lua");

	followCurve = new FollowCurveWithTime(this,5);
	followCurve->easeInTime = 2;
	followCurve->easeOutTime = 2;


	bezierPath->AddPoint(CubicBezierPoint{ glm::vec3(-5,9,30), glm::vec3(10,9,0) });
	bezierPath->AddPoint(CubicBezierPoint{ glm::vec3(40,9,30), glm::vec3(30,9,60) });

	followCurve->SetBezierCurve(bezierPath);

	followCurve->StartCommand();

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

	phyObj->Initialize(model, SPHERE, DYNAMIC);
	physicsEngine->AddPhysicsObject(phyObj);

}

void Player::RemoveFromRendererAndPhysics(Renderer* renderer, PhysicsEngine* physicsEngine)
{
}
