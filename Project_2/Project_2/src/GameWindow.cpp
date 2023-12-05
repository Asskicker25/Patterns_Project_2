#include "GameWindow.h"
#include "EntityManager/EntityManager.h"
#include "LuaTest.h"

void GameWindow::SetUp()
{
	EntityManager::GetInstance().AddToRendererAndPhysics(&renderer, &defShader, &physicsEngine);

#pragma region Light

	Model* lightModel = new Model("res/Models/DefaultSphere.fbx",false);
	lightModel->transform.SetScale(glm::vec3(0.01f));
	renderer.AddModel(lightModel, &solidColorShader);

	Light* dirLight = new Light();
	dirLight->InitializeLight(lightModel, Directional);
	lightManager.AddLight(dirLight);

#pragma endregion

	LuaTest* luaTest = new LuaTest();



	EntityManager::GetInstance().Start();
}

void GameWindow::PreRender()
{
}

void GameWindow::PostRender()
{
	EntityManager::GetInstance().Update(deltaTime);
}

void GameWindow::ProcessInput(GLFWwindow* window)
{
}

void GameWindow::KeyCallBack(GLFWwindow* window, int& key, int& scancode, int& action, int& mods)
{
}

void GameWindow::MouseButtonCallback(GLFWwindow* window, int& button, int& action, int& mods)
{
}
