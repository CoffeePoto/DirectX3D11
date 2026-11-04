#include "pch.h"
#include "AmbientDemo.h"
#include "GeometryHelper.h"
#include "Camera.h"
#include "CameraScript.h"
#include "MeshRenderer.h"

void AmbientDemo::Init()
{
	RESOURCES->Init();
	_shader = make_shared<Shader>(L"Lighting_Ambient.fx");

	//Camera
	_camera = make_shared<GameObject>();
	_camera->GetorAddTransform();
	_camera->AddComponent(make_shared<Camera>());
	_camera->AddComponent(make_shared<CameraScript>());
	_camera->GetTransform()->SetPosition(Vec3(0.f, 0.f, -10.f));

	//Object
	_obj = make_shared<GameObject>();
	_obj->GetorAddTransform();
	_obj->AddComponent(make_shared<MeshRenderer>());
	{
		_obj->GetMeshRenderer()->SetShader(_shader);
	}

	{
		auto mesh = RESOURCES->Get<Mesh>(L"Sphere");
		_obj->GetMeshRenderer()->SetMesh(mesh);
	}

	{
		auto texture = RESOURCES->Load<Texture>(L"Ocean", L"..\\Resources\\Texture\\Ocean.jpg");
		_obj->GetMeshRenderer()->SetTexture(texture);
	}

	//Object2
	_obj2 = make_shared<GameObject>();
	_obj2->GetorAddTransform()->SetPosition(Vec3(0.5f, 0.0f, 2.0f));
	_obj2->AddComponent(make_shared<MeshRenderer>());
	{
		_obj2->GetMeshRenderer()->SetShader(_shader);
	}

	{
		auto mesh = RESOURCES->Get<Mesh>(L"Cube");
		_obj2->GetMeshRenderer()->SetMesh(mesh);
	}

	{
		auto texture = RESOURCES->Load<Texture>(L"Zoro", L"..\\Resources\\Texture\\Zoro.png");
		_obj2->GetMeshRenderer()->SetTexture(texture);
	}


	RENDER->Init(_shader);
}

void AmbientDemo::Update()
{
	_camera->Update();

	RENDER->Update();

	//
	Vec4 lightAmbient(0.1f, 0.5f, 1.f, 1.f);
	_shader->GetVector("LightAmbient")->SetFloatVector((float*)&lightAmbient);

	{
		Vec4 materialAmbient(1.f);
		_shader->GetVector("MaterialAmbient")->SetFloatVector((float*)&materialAmbient);
		_obj->Update();
	}
	{
		Vec4 materialAmbient(0.5f, 0.3f, 0.1f, 1.f);
		_shader->GetVector("MaterialAmbient")->SetFloatVector((float*)&materialAmbient);
		_obj2->Update();
	}
}

void AmbientDemo::Render()
{

}