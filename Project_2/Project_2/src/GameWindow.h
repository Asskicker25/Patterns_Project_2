#pragma once

#include <Graphics/ApplicationWindow.h>
#include <Physics/PhysicsEngine.h>


class GameWindow : public ApplicationWindow
{

public:
	PhysicsEngine physicsEngine;

private:

	bool isFreeCam = false;

	glm::vec3 lastCameraPos = glm::vec3(0);
	glm::vec3 lastCameraRot = glm::vec3(0);

	// Inherited via ApplicationWindow
	void SetUp() override;
	void PreRender() override;
	void PostRender() override;
	void ProcessInput(GLFWwindow* window) override;
	void KeyCallBack(GLFWwindow* window, int& key, int& scancode, int& action, int& mods) override;
	void MouseButtonCallback(GLFWwindow* window, int& button, int& action, int& mods) override;

	void ToggleFreeCam();
};

