#pragma once

extern "C"
{
#include <Lua/lua.h>
#include <Lua/lauxlib.h>
#include <Lua/lualib.h>
}


class LuaTest
{
public:
	LuaTest();

private:
	lua_State* Start();

};

