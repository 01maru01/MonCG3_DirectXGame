#pragma once
#include <DirectXMath.h>

class ParticleEmitter
{
private:
	// Microsoft::WRL::‚ğÈ—ª
	//template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::‚ğÈ—ª
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

private:
	int life;
	XMFLOAT3 position = {0.0f,0.0f,50.0f};
	XMFLOAT3 velocity = {};
	XMFLOAT3 accel = {};
	float s_scale = 1.0f;
	float e_scale = 1.0f;
	XMFLOAT4 s_color = { 1.0f,1.0f,1.0f,1.0f };
	XMFLOAT4 e_color = { 1.0f,1.0f,1.0f,0.0f };
public:
	const XMFLOAT3& GetPosition() const { return position; }

	void SetPosition(const XMFLOAT3& position) { this->position = position; }
};

