#include "LuaManager.h"
#include <iostream>
#include "CommandManager/CommandManager.h"
#include "Commands/MoveToPosWithTime.h"

LuaManager::LuaManager()
{
}

LuaManager& LuaManager::GetInstance()
{
	static LuaManager instance;
	return instance;
}

lua_State* LuaManager::CreateLuaState(const std::string& name, GameObject* gameObject)
{
	lua_State* newState = luaL_newstate();

	if (newState == nullptr)
	{
		return nullptr;
	}

	luaL_openlibs(newState);

	gameObjectsWithState[newState] = gameObject;
	gameObjectsWithString[gameObject->entityId] = gameObject;

	SetBindingsToState(newState);

	return newState;
}

void LuaManager::CloseLuaState(lua_State* luaState)
{
	lua_close(luaState);
}

GameObject* LuaManager::GetGameObjectWithState(lua_State* state)
{
	std::unordered_map <lua_State*, GameObject*>::iterator it = gameObjectsWithState.find(state);

	if (it != gameObjectsWithState.end())
	{
		return it->second;
	}

	return nullptr;
}

GameObject* LuaManager::GetGameObjectWithID(std::string id)
{
	std::unordered_map <std::string, GameObject*>::iterator it = gameObjectsWithString.find(id);

	if (it != gameObjectsWithString.end())
	{
		return it->second;
	}
	return nullptr;
}


void LuaManager::SetBindingsToState(lua_State* luaState)
{
#pragma region BeginCommandGroup

	lua_pushcfunction(luaState, [](lua_State* luaState)->int
		{
			int argCount = lua_gettop(luaState);
			if (argCount >= 3)
			{
				std::string friendlyName = luaL_checkstring(luaState, 1);
				std::string commandGroupType = luaL_checkstring(luaState, 2);
				int repeatCount = luaL_checknumber(luaState, 3);

				CommandManager::GetInstance().
					BeginCommandGroup(friendlyName, commandGroupType, repeatCount);

			}
			else if (argCount == 2)
			{
				std::string friendlyName = luaL_checkstring(luaState, 1);
				std::string commandGroupType = luaL_checkstring(luaState, 2);
				CommandManager::GetInstance().
					BeginCommandGroup(friendlyName, commandGroupType);
			}

			return 0;
		});

	lua_setglobal(luaState, "BeginCommandGroup");

#pragma endregion

#pragma region EndCommandGroup

	lua_pushcfunction(luaState, [](lua_State* luaState)->int
		{
			CommandManager::GetInstance().EndCommandGroup();
			return 0;
		});

	lua_setglobal(luaState, "EndCommandGroup");

#pragma endregion


#pragma region MoveToPositionWithTime

	lua_pushcfunction(luaState, [](lua_State* luaState)->int
		{
			int argCount = lua_gettop(luaState);

			if (argCount >= 4)
			{
				glm::vec3 pos;
				pos.x = luaL_checknumber(luaState, 1);
				pos.y = luaL_checknumber(luaState, 2);
				pos.z = luaL_checknumber(luaState, 3);

				float time = luaL_checknumber(luaState, 4);

				BaseCommand* command = new MoveToPosWithTime(
					LuaManager::GetInstance().GetGameObjectWithState(luaState),
					pos, time);

				CommandManager::GetInstance().AddCommand(command);
			}
			return 0;
		});

	lua_setglobal(luaState, "MoveToPositionWithTime");


#pragma endregion


}



