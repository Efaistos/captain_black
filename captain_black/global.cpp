#include "global.hpp"

#include <iostream>

bdo::cheat bdo::global::cheat = {};
//bdo::engine::lua::do_string_t bdo::global::do_string_original = nullptr;
bdo::engine::lua::gettop_t bdo::global::gettop_original = nullptr;

bool bdo::global::run_lua_from_disk = false;

//
//
//void* __fastcall bdo::global::do_string_hook(std::int64_t state, const char* command, std::int64_t length)
//{
//	if (state && command)
//	{
//		if (!dump)
//		{
//			constexpr auto dump_command = "dofile('D:/BDO/Extract_Tables_Globals.lua')";
//			auto result = bdo::global::do_string_original(state, dump_command, sizeof(dump_command));
//			printf("Dumped! - %p\n", result);
//			dump = true;
//		}
//
//		printf("[lua::do_string] %s - (%p)\n", command, reinterpret_cast<void*>(state));
//	}
//
//	return bdo::global::do_string_original(state, command, length);
//}

bool running_script = false;

void* __fastcall bdo::global::gettop_hook(std::int64_t state)
{
	if (state)
	{
		//printf("[lua::gettop] %p\n", state);
		

		if (global::run_lua_from_disk && !running_script)
		{
			running_script = true;

			constexpr auto dump_command = "dofile(\"D:/BDO/test.lua\")";
			auto result = bdo::global::cheat.lua().do_string(state, dump_command, strlen(dump_command));
			printf("Dumped! - %p\n", result);

			running_script = false;
			global::run_lua_from_disk = false;
		}

	}

	return bdo::global::gettop_original(state);
}
