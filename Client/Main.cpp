#include "pch.h"
#include "Main.h"
#include "Game.h"
#include "GlobalTestDemo.h"
#include "DepthStencilDemo.h"
#include "AmbientDemo.h"
#include "DiffuseDemo.h"
#include "SpecularDemo.h"
#include "EmissiveDemo.h"
#include "LightingDemo.h"
#include "MaterialDemo.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	GameDesc desc;
	desc.appName = L"DirectX3D";
	desc.hInstance = hInstance;
	desc.vsync = false;
	desc.hWnd = NULL;
	desc.width = 800;
	desc.height = 600;
	desc.clearColor = Color(0.f, 0.f, 0.f, 0.f);
	desc.app = make_shared<MaterialDemo>();

	GAME->Run(desc);

	return 0;
}