#pragma once
#include "IExecute.h"
#include "Geometry.h"

class TextureDemo : public IExecute
{

public:
	void Init() override;
	void Update() override;
	void Render() override;


	shared_ptr<Geometry<VertexTextureData>> _geometry;
	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	Matrix _world = Matrix::Identity;

	//Shader
	shared_ptr<Shader> _shader;

	//Camera
	shared_ptr<GameObject> _camera;

	//Texture
	shared_ptr<Texture> _texture;
};