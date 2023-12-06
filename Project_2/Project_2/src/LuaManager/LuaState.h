#pragma once

#include "LuaManager.h"
#include <Graphics/Model.h>

class LuaState
{
public:
	LuaState(const char* name, Model* model);

	void LoadScript(const char* path );
	lua_State* GetState();
	void SetState(lua_State* luaState);
	void Execute();
	void CloseState();

private:
	
	const char* path;
	bool isLoaded = false;

	lua_State* luaState = nullptr;

	void PrintError(const char* message);
};

