#pragma once

extern "C"
{
#include <Lua/lua.h>
#include <Lua/lauxlib.h>
#include <Lua/lualib.h>
}

#include <string>
#include <unordered_map>

#include "../GameObject/GameObject.h"

class LuaManager
{
public:
	
	LuaManager();

	static LuaManager& GetInstance();

	lua_State* CreateLuaState(const std::string& name, GameObject* gameObject);
	void CloseLuaState(lua_State* luaState);

	GameObject* GetGameObjectWithState(lua_State* state);
	GameObject* GetGameObjectWithID(std::string id);

private:

	void SetBindingsToState(lua_State* luaState);

	std::unordered_map <lua_State*, GameObject*> gameObjectsWithState;
	std::unordered_map <std::string, GameObject*> gameObjectsWithString;
};

