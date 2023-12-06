#include "LuaManager.h"
#include <iostream>
#include "CommandManager/CommandManager.h"

LuaManager::LuaManager()
{
}

LuaManager& LuaManager::GetInstance()
{
	static LuaManager instance;
	return instance;
}

lua_State* LuaManager::CreateLuaState(const std::string& name, Model* model)
{
	lua_State* newState = luaL_newstate();

	if (newState == nullptr)
	{
		return nullptr;
	}

	luaL_openlibs(newState);
	SetBindingsToState(newState);

	return newState;
}

void LuaManager::CloseLuaState(lua_State* luaState)
{
	lua_close(luaState);
}


void LuaManager::SetBindingsToState(lua_State* luaState)
{
#pragma region BeginCommand

	lua_pushcfunction(luaState, [](lua_State* luaState)->int
		{
			int argCount = lua_gettop(luaState);
			if (argCount >= 3)
			{
				std::string friendlyName = luaL_checkstring(luaState, 1);
				std::string commandGroupType = luaL_checkstring(luaState, 2);
				int repeatCount = luaL_checknumber(luaState, 3);

				CommandManager::BeginCommandGroup(friendlyName, commandGroupType,repeatCount);

			}
			else if (argCount == 2)
			{
				std::string friendlyName = luaL_checkstring(luaState, 1);
				std::string commandGroupType = luaL_checkstring(luaState, 2);
				CommandManager::BeginCommandGroup(friendlyName, commandGroupType);
			}

			return 0;
		});

	lua_setglobal(luaState, "BeginCommandGroup");

#pragma endregion


}



