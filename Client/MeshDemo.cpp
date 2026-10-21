#include "pch.h"
#include "MeshDemo.h"
#include "GeometryHelper.h"
#include "Camera.h"
#include "CameraScript.h"
#include "MeshRenderer.h"

void MeshDemo::Init()
{
	_shader = make_shared<Shader>(L"Normal.fx");

	//Camera
	_camera = make_shared<GameObject>();
	_camera->GetorAddTransform();
	_camera->AddComponent(make_shared<Camera>());
	_camera->AddComponent(make_shared<CameraScript>());
	_camera->GetTransform()->SetPosition(Vec3(0.f, 0.f, -3.f));

	//Object
	_obj = make_shared<GameObject>();
	_obj->GetorAddTransform();
	_obj->AddComponent(make_shared<MeshRenderer>());
	{
		auto shader = make_shared<Shader>(L"Normal.fx");
		_obj->GetMeshRenderer()->SetShader(shader);
	}

	{
		RESOURCES->Init();
		auto mesh = RESOURCES->Get<Mesh>(L"Sphere");
		_obj->GetMeshRenderer()->SetMesh(mesh);
	}

	{
		auto texture = RESOURCES->Load<Texture>(L"Ocean", L"..\\Resources\\Texture\\Ocean.jpg");
		_obj->GetMeshRenderer()->SetTexture(texture);
	}
}

void MeshDemo::Update()
{
	_camera->Update();
	_obj->Update();
}

void MeshDemo::Render()
{

}