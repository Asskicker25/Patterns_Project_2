#include "GameWindow.h"
#include "EntityManager/EntityManager.h"
#include "Player/Player.h"
#include "LuaManager/CommandManager/CommandManager.h"
#include "City/City.h"
#include "Utilities/RendererInstance.h"
#include "AI/Car/CarManager.h"
#include "TriggerZone/TriggerZoneManager.h"
#include "Camera/CameraObject.h"

void GameWindow::SetUp()
{
	physicsEngine.fixedStepTime = 0.01f;
	physicsEngine.gravity.y = 0;
	moveSpeed = 50;

	stopKeyCallback = true;
	stopMouseCallback = true;

	RendererInstance::GetInstance().SetRenderer(&renderer);


	camera->InitializeCamera(PERSPECTIVE, windowWidth, windowHeight, 0.1f, 1000.0f, 65.0f);

	camera->transform.SetPosition(glm::vec3(0, 0, 0));
	camera->transform.SetRotation(glm::vec3(-20, -90, 0));

	EntityManager::GetInstance().AddToRendererAndPhysics(&renderer, &defShader, &physicsEngine);

#pragma region Light

	Model* lightModel = new Model("res/Models/DefaultSphere.fbx", false);
	lightModel->transform.SetScale(glm::vec3(0.01f));
	renderer.AddModel(lightModel, &solidColorShader);

	Light* dirLight = new Light();
	dirLight->InitializeLight(lightModel, Directional);
	dirLight->intensity = 1.5f;
	lightManager.AddLight(dirLight);

#pragma endregion

	TriggerZoneManager::GetInstance().SetShader(&alphaBlendShader);

	City* city = new City();
	Player* player = new Player();
	CarManager::GetInstance().LoadLuaScript();

	CameraObject* cameraObject = new CameraObject();
	cameraObject->camera = camera;




	EntityManager::GetInstance().Start();

	LuaManager::GetInstance().ExecuteGlobalState();
}

void GameWindow::PreRender()
{
}

void GameWindow::PostRender()
{
	physicsEngine.Update(Timer::GetInstance().deltaTime);
	EntityManager::GetInstance().Update(Timer::GetInstance().deltaTime);
	CommandManager::GetInstance().Update(Timer::GetInstance().deltaTime);
}

void GameWindow::ProcessInput(GLFWwindow* window)
{
	std::stringstream ssTitle;
	ssTitle << "Camera Pos : "
		<< camera->transform.position.x << " , "
		<< camera->transform.position.y << " , "
		<< camera->transform.position.z
		<< "  Camera Pitch : "
		<< camera->transform.rotation.x
		<< "  Camera Yaw : "
		<< camera->transform.rotation.y;

	std::string theTitle = ssTitle.str();

	glfwSetWindowTitle(window, theTitle.c_str());
}

void GameWindow::KeyCallBack(GLFWwindow* window, int& key, int& scancode, int& action, int& mods)
{
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_SPACE)
		{
			CommandManager::GetInstance().TogglePaused();
			ToggleFreeCam();
		}

	}
}

void GameWindow::MouseButtonCallback(GLFWwindow* window, int& button, int& action, int& mods)
{
}

void GameWindow::ToggleFreeCam()
{
	isFreeCam = !isFreeCam;

	stopKeyCallback = !isFreeCam;
	stopMouseCallback = !isFreeCam;


	if (isFreeCam)
	{
		lastCameraPos = camera->transform.position;
		lastCameraRot = camera->transform.rotation;
	}
	else
	{
		camera->transform.SetPosition(lastCameraPos);
		camera->transform.SetRotation(lastCameraRot);
	}


}