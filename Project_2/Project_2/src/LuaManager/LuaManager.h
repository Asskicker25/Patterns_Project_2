#pragma once

extern "C"
{
#include <Lua/lua.h>
#include <Lua/lauxlib.h>
#include <Lua/lualib.h>
}

#include <string>
#include <unordered_map>

#include <Graphics/Model.h>

class LuaManager
{
public:
	
	LuaManager();

	static LuaManager& GetInstance();

	lua_State* CreateLuaState(const std::string& name, Model* model);
	void CloseLuaState(lua_State* luaState);

private:

	void SetBindingsToState(lua_State* luaState);

};

