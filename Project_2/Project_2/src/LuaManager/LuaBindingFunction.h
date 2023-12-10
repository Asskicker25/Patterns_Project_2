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
#include "Commands/FollowObject.h"
#include "Commands/LookAt.h"

static void GetEaseTable(lua_State* luaState);
static void GetCurveTable(lua_State* luaState);
static void GetFollowObjectTable(lua_State* luaState);
static void GetCommandGroupTable(lua_State* luaState);
static void GetLookAtTable(lua_State* luaState);

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
static int SetFollowDistance(lua_State* luaState)
{
	FollowObject* command = dynamic_cast<FollowObject*>
		( CommandManager::GetInstance().currentCommand);

	int argCount = lua_gettop(luaState);

	if (argCount >= 1)
	{
		float distance = luaL_checknumber(luaState, 1);

		command->SetFollowDistance(distance);

		GetFollowObjectTable(luaState);
		return 1;
	}
	return 0;

}
static int SetMaxSpeed(lua_State* luaState)
{
	FollowObject* command = dynamic_cast<FollowObject*>
		(CommandManager::GetInstance().currentCommand);

	int argCount = lua_gettop(luaState);

	if (argCount >= 1)
	{
		float maxSpeed = luaL_checknumber(luaState, 1);

		command->SetMaxSpeed(maxSpeed);

		GetFollowObjectTable(luaState);
		return 1;
	}
	return 0;

}
static int SetFollowOffset(lua_State* luaState)
{
	FollowObject* command = dynamic_cast<FollowObject*>
		(CommandManager::GetInstance().currentCommand);

	int argCount = lua_gettop(luaState);

	if (argCount >= 3)
	{
		glm::vec3 offset;

		offset.x = luaL_checknumber(luaState, 1);
		offset.y = luaL_checknumber(luaState, 2);
		offset.z = luaL_checknumber(luaState, 3);

		command->SetFollowOffset(offset);

		GetFollowObjectTable(luaState);
		return 1;
	}
	return 0;

}
static int SetAccelerationRange(lua_State* luaState)
{
	FollowObject* command = dynamic_cast<FollowObject*>
		(CommandManager::GetInstance().currentCommand);

	int argCount = lua_gettop(luaState);

	if (argCount >= 1)
	{
		float range = luaL_checknumber(luaState, 1);

		command->SetAccelerationRange(range);

		GetFollowObjectTable(luaState);
		return 1;
	}
	return 0;
}
static int SetDeaccelerationRange(lua_State* luaState)
{
	FollowObject* command = dynamic_cast<FollowObject*>
		(CommandManager::GetInstance().currentCommand);

	int argCount = lua_gettop(luaState);

	if (argCount >= 1)
	{
		float range = luaL_checknumber(luaState, 1);

		command->SetDeaccelerationRange(range);

		GetFollowObjectTable(luaState);
		return 1;
	}
	return 0;
}
static int SetCollisionCondition(lua_State* luaState)
{

	int argCount = lua_gettop(luaState);

	if (argCount >= 1)
	{
		std::string collisionTag = luaL_checkstring(luaState, 1);

		CommandGroup* commandGroup = CommandManager::GetInstance().currentCommandGroup;
		CommandManager::GetInstance().GetBoundGameObject()->AddCollisionGroup(collisionTag, commandGroup);
		commandGroup->conditionMet = false;

		GetCommandGroupTable(luaState);
		return 1;
	}
	return 0;
}
static int SetLookAtOffset(lua_State* luaState)
{
	LookAt* command = dynamic_cast<LookAt*>
		(CommandManager::GetInstance().currentCommand);

	int argCount = lua_gettop(luaState);

	if (argCount >= 3)
	{
		glm::vec3 offset;

		offset.x = luaL_checknumber(luaState, 1);
		offset.y = luaL_checknumber(luaState, 2);
		offset.z = luaL_checknumber(luaState, 3);

		command->SetLookAtOffset(offset);

		GetFollowObjectTable(luaState);
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
void GetFollowObjectTable(lua_State* luaState)
{
	lua_newtable(luaState);

	lua_pushcfunction(luaState, SetFollowDistance);
	lua_setfield(luaState, -2, "SetFollowDistance");

	lua_pushcfunction(luaState, SetMaxSpeed);
	lua_setfield(luaState, -2, "SetMaxSpeed");

	lua_pushcfunction(luaState, SetFollowOffset);
	lua_setfield(luaState, -2, "SetFollowOffset");

	lua_pushcfunction(luaState, SetAccelerationRange);
	lua_setfield(luaState, -2, "SetAccelerationRange");

	lua_pushcfunction(luaState, SetDeaccelerationRange);
	lua_setfield(luaState, -2, "SetDeaccelerationRange");
}
void GetCommandGroupTable(lua_State* luaState)
{
	lua_newtable(luaState);

	lua_pushcfunction(luaState, SetCollisionCondition);
	lua_setfield(luaState, -2, "SetCollisionCondition");
}

void GetLookAtTable(lua_State* luaState)
{
	lua_newtable(luaState);

	lua_pushcfunction(luaState, SetLookAtOffset);
	lua_setfield(luaState, -2, "SetLookAtOffset");
}
