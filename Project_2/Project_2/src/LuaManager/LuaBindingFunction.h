extern "C"
{
#include <Lua/lua.h>
#include <Lua/lauxlib.h>
#include <Lua/lualib.h>
}

#include "CommandManager/CommandManager.h"
#include "Commands/MoveToPosWithTime.h"
#include "Commands/MoveWithSpeed.h"
#include "Commands/RotateWithTime.h"
#include "Commands/WaitForSeconds.h"
#include "Commands/FollowCurveWithTime.h"

static void GetEaseTable(lua_State* luaState);
static void GetCurveTable(lua_State* luaState);

static int EaseIn(lua_State* luaState)
{
	EaseCommand* command = dynamic_cast<EaseCommand*>
		(CommandManager::GetInstance().currentCommand);

	int argCount = lua_gettop(luaState);

	if (argCount >= 2)
	{
		std::string easeMode = luaL_checkstring(luaState, 1);
		float time = luaL_checknumber(luaState, 2);

		command->easeInTime = time;
		command->easeInMode = GetMode(easeMode);

		GetEaseTable(luaState);

		return 1;
	}

	return 0;
}
static int EaseOut(lua_State* luaState)
{
	EaseCommand* command = dynamic_cast<EaseCommand*>
		(CommandManager::GetInstance().currentCommand);

	int argCount = lua_gettop(luaState);

	if (argCount >= 2)
	{
		std::string easeMode = luaL_checkstring(luaState, 1);
		float time = luaL_checknumber(luaState, 2);

		command->easeOutTime = time;
		command->easeOutMode = GetMode(easeMode);

		GetEaseTable(luaState);

		return 1;
	}

	return 0;
}

static int AddPoint(lua_State* luaState)
{
	FollowCurveWithTime* command = dynamic_cast<FollowCurveWithTime*>
		(CommandManager::GetInstance().currentCommand);

	int argCount = lua_gettop(luaState);

	if (argCount >= 6)
	{
		glm::vec3 point;
		glm::vec3 controlPoint;

		point.x = luaL_checknumber(luaState, 1);
		point.y = luaL_checknumber(luaState, 2);
		point.z = luaL_checknumber(luaState, 3);

		controlPoint.x = luaL_checknumber(luaState, 4);
		controlPoint.y = luaL_checknumber(luaState, 5);
		controlPoint.z = luaL_checknumber(luaState, 6);

		command->AddPoint(point, controlPoint);

		GetCurveTable(luaState);

		return 1;
	}

	return 0;
}


void GetEaseTable(lua_State* luaState)
{
	lua_newtable(luaState);

	lua_pushcfunction(luaState, EaseIn);

	lua_setfield(luaState, -2, "EaseIn");

	lua_pushcfunction(luaState, EaseOut);

	lua_setfield(luaState, -2, "EaseOut");
}

void GetCurveTable(lua_State* luaState)
{
	lua_newtable(luaState);

	lua_pushcfunction(luaState, EaseIn);

	lua_setfield(luaState, -2, "EaseIn");

	lua_pushcfunction(luaState, EaseOut);

	lua_setfield(luaState, -2, "EaseOut");

	lua_pushcfunction(luaState, AddPoint);

	lua_setfield(luaState, -2, "AddPoint");

}