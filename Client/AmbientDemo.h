#pragma once
#include "IExecute.h"
#include "Geometry.h"

class AmbientDemo : public IExecute
{

	void Init() override;
	void Update() override;
	void Render() override;
	

	shared_ptr<Shader> _shader;
	//Object
	shared_ptr<GameObject> _obj;
	//Object2
	shared_ptr<GameObject> _obj2;
	//Camera
	shared_ptr<GameObject> _camera;
};