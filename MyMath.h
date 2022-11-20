#pragma once
#include <DirectXMath.h>

const DirectX::XMFLOAT3 operator+(const DirectX::XMFLOAT3& lhs, const DirectX::XMFLOAT3& rhs);

const DirectX::XMFLOAT4 operator+(const DirectX::XMFLOAT4& lhs, const DirectX::XMFLOAT4& rhs);

const DirectX::XMFLOAT4 operator-(const DirectX::XMFLOAT4& lhs, const DirectX::XMFLOAT4& rhs);

const DirectX::XMFLOAT4 operator*(const DirectX::XMFLOAT4& lhs, const float& rhs);
