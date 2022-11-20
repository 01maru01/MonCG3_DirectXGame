#include "MyMath.h"

const DirectX::XMFLOAT3 operator+(const DirectX::XMFLOAT3& lhs, const DirectX::XMFLOAT3& rhs) {
	DirectX::XMFLOAT3 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	result.z = lhs.z + rhs.z;

	return result;
}

const DirectX::XMFLOAT4 operator+(const DirectX::XMFLOAT4& lhs, const DirectX::XMFLOAT4& rhs) {
	DirectX::XMFLOAT4 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	result.z = lhs.z + rhs.z;
	result.w = lhs.w + rhs.w;

	return result;
}

const DirectX::XMFLOAT4 operator-(const DirectX::XMFLOAT4& lhs, const DirectX::XMFLOAT4& rhs) {
	DirectX::XMFLOAT4 result;
	result.x = lhs.x - rhs.x;
	result.y = lhs.y - rhs.y;
	result.z = lhs.z - rhs.z;
	result.w = lhs.w - rhs.w;

	return result;
}

const DirectX::XMFLOAT4 operator*(const DirectX::XMFLOAT4& lhs, const float& rhs) {
	DirectX::XMFLOAT4 result;
	result.x = lhs.x * rhs;
	result.y = lhs.y * rhs;
	result.z = lhs.z * rhs;
	result.w = lhs.w * rhs;

	return result;
}