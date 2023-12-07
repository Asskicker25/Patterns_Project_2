#include "GameWindow.h"
#include "EntityManager/EntityManager.h"
#include "Player/Player.h"
#include "AI/Car/Car.h"
#include "LuaManager/CommandManager/CommandManager.h"
#include "City/City.h"

void GameWindow::SetUp()
{
	camera->SetCameraPosition(glm::vec3(-15, 12, 30));
	camera->SetCameraRotation(glm::vec3(-10, -5, 0));

	camera->InitializeCamera(PERSPECTIVE, windowWidth, windowHeight, 0.1f, 1000.0f, 65.0f);

	EntityManager::GetInstance().AddToRendererAndPhysics(&renderer, &defShader, &physicsEngine);

#pragma region Light

	Model* lightModel = new Model("res/Models/DefaultSphere.fbx",false);
	lightModel->transform.SetScale(glm::vec3(0.01f));
	renderer.AddModel(lightModel, &solidColorShader);

	Light* dirLight = new Light();
	dirLight->InitializeLight(lightModel, Directional);
	lightManager.AddLight(dirLight);

#pragma endregion

	City* city = new City();
	Player* player = new Player();
	Car* car = new Car();

	EntityManager::GetInstance().Start();

	LuaManager::GetInstance().ExecuteGlobalState();
}

void GameWindow::PreRender()
{
}

void GameWindow::PostRender()
{
	EntityManager::GetInstance().Update(Time::GetInstance().deltaTime);
	CommandManager::GetInstance().Update(Time::GetInstance().deltaTime);
}

void GameWindow::ProcessInput(GLFWwindow* window)
{
	std::stringstream ssTitle;
	ssTitle << "Camera Pos : "
		<< camera->cameraPos.x << " , "
		<< camera->cameraPos.y << " , "
		<< camera->cameraPos.z
		<< "  Camera Pitch : "
		<< camera->cameraPitch
		<< "  Camera Yaw : "
		<< camera->cameraYaw;

	std::string theTitle = ssTitle.str();

	glfwSetWindowTitle(window, theTitle.c_str());
}

void GameWindow::KeyCallBack(GLFWwindow* window, int& key, int& scancode, int& action, int& mods)
{
}

void GameWindow::MouseButtonCallback(GLFWwindow* window, int& button, int& action, int& mods)
{
}
