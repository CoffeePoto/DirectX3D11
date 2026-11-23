#include "pch.h"
#include "AssimpTool.h"
#include "Converter.h"

void AssimpTool::Init()
{
	//{
	//	shared_ptr<Converter> converter = make_shared<Converter>();
	//	//FBX->Memory
	//	converter->ReadAssetFile(L"House/House.fbx");

	//	//Memory->Custom Data(File)
	//	converter->ExportMaterialData(L"House/House");
	//	converter->ExportModelData(L"House/House");
	//	
	//	//Custom Data(File) -> Memory
	//}

	{
		shared_ptr<Converter> converter = make_shared<Converter>();
		//FBX->Memory
		converter->ReadAssetFile(L"Tower/Tower.fbx");

		//Memory->Custom Data(File)
		converter->ExportMaterialData(L"Tower/Tower");
		converter->ExportModelData(L"Tower/Tower");

		//Custom Data(File) -> Memory
	}
}

void AssimpTool::Update()
{
}

void AssimpTool::Render()
{
}
