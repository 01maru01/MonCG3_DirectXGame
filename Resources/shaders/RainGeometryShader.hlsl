#include "Particle.hlsli"

static const uint vnum = 2;

static const float4 offset_array[vnum] = {
	float4(-0.0f, -0.5f, 0, 0),
	float4(-0.0f, +0.5f, 0, 0),
};

static const float2 uv_array[vnum] = {
	float2(0.5f, 0.5f),
	float2(0.5f, 0.5f),
};

[maxvertexcount(vnum)]
void main(
	point VSOutput input[1] : SV_POSITION,
	inout LineStream< GSOutput > output
)
{
	GSOutput element;
	for (uint i = 0; i < vnum; i++) {
		float4 offset = offset_array[i] * input[0].scale;
		element.color = input[0].color;
		offset = mul(matBillboard, offset);
		element.svpos = input[0].svpos + offset_array[i];
		element.svpos = mul(mat, element.svpos);
		element.uv = uv_array[i];
		output.Append(element);
	}
}
