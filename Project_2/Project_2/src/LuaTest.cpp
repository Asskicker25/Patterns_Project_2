#include "LuaTest.h"
#include <iostream>

LuaTest::LuaTest()
{
	lua_State* L = Start();
	if (L == NULL)
	{
		std::cout << "All is lost, forever LOST!! (because Lua didn't start)" << std::endl;
		return;
	}
}

lua_State* LuaTest::Start()
{
	lua_State* L = luaL_newstate();		/* opens Lua 5.3.4 */
	if (L == NULL)
	{	// Out of memory
		return nullptr;
	}
	// No way to check if this is working or not
	luaL_openlibs(L);					/* Lua 5.3.4 */

	return L;
}
