#include "ParticleEmitter.h"
#include <stdlib.h>

void ParticleEmitter::SetScale(float start, float end)
{
	s_scale = start;
	e_scale = end;
}

void ParticleEmitter::SetColor(bool setRand, XMFLOAT4 start, XMFLOAT4 end)
{
	if (setRand) {
		s_color.x = (float)rand() / RAND_MAX;
		s_color.y = (float)rand() / RAND_MAX;
		s_color.z = (float)rand() / RAND_MAX;
		s_color.w = 1.0f;
		e_color.x = (float)rand() / RAND_MAX;
		e_color.y = (float)rand() / RAND_MAX;
		e_color.z = (float)rand() / RAND_MAX;
		e_color.w = 0.0f;
	}
	else {
		s_color = start;
		e_color = end;
	}
}

void ParticleEmitter::Update()
{
	const float rnd_pos = 2.0f;
	position = emitterPos;
	position.x += (float)rand() / RAND_MAX * rnd_pos - rnd_pos / 2.0f;
	position.y += (float)rand() / RAND_MAX * rnd_pos - rnd_pos / 2.0f;
	position.z += (float)rand() / RAND_MAX * rnd_pos - rnd_pos / 2.0f;

	const float rnd_vel = 0.1f;
	velocity.x = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
	velocity.y = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
	velocity.z = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;

	const float rnd_acc = 0.001f;
	accel.y = -(float)rand() / RAND_MAX * rnd_acc;

	s_color.x = (float)rand() / RAND_MAX;
	s_color.y = (float)rand() / RAND_MAX;
	s_color.z = (float)rand() / RAND_MAX;
	s_color.w = 1.0f;
	e_color.x = (float)rand() / RAND_MAX;
	e_color.y = (float)rand() / RAND_MAX;
	e_color.z = (float)rand() / RAND_MAX;
	e_color.w = 0.0f;
}
