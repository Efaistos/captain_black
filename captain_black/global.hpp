#pragma once
#include <d3d11.h>
#include "captain.hpp"
#include "renderer.hpp"
#include "settings.hpp"

namespace global
{
	extern captain cpt;
	extern renderer menu;
	extern settings options;

	//extern engine::lua::do_string_t do_string_original;
	//extern void* __fastcall do_string_hook(std::int64_t state, const char* command, std::int64_t length);

	// LUA HOOKS
	extern engine::lua::gettop_t gettop_original;
	extern void* __fastcall gettop_hook(std::int64_t state);
	extern bool run_lua_from_disk;

	// DX HOOKS
	using present_t = HRESULT(__stdcall*)(IDXGISwapChain* swapchain_pointer, UINT sync_interval, UINT flags);
	extern present_t present_original;
	extern HRESULT __stdcall present_hook(IDXGISwapChain* swapchain_pointer, UINT sync_interval, UINT flags);

}