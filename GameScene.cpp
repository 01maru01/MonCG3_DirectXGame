#include "GameScene.h"
#include <cassert>

using namespace DirectX;

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	delete spriteBG;
	delete object3d;
	delete billboard3d;
	delete particleMan;
	delete sprite1;
	delete sprite2;
}

void GameScene::Initialize(DirectXCommon* dxCommon, Input* input)
{
	// nullptrチェック
	assert(dxCommon);
	assert(input);

	this->dxCommon = dxCommon;
	this->input = input;

	// デバッグテキスト用テクスチャ読み込み
	Sprite::LoadTexture(debugTextTexNumber, L"Resources/debugfont.png");
	// デバッグテキスト初期化
	debugText.Initialize(debugTextTexNumber);

	// テクスチャ読み込み
	Sprite::LoadTexture(1, L"Resources/background.png");

	// 背景スプライト生成
	spriteBG = Sprite::Create(1, { 0.0f,0.0f });
	// 3Dオブジェクト生成
	object3d = Object3d::Create();
	object3d->SetPosition({ 2.0f,0.0f,0.0f });
	object3d->Update();
	billboard3d = Object3d::Create();
	billboard3d->SetPosition({ -2.0f,0.0f,0.0f });
	billboard3d->Update();
	particleMan = ParticleManager::Create();
	particleMan->Update();
	Sprite::LoadTexture(2, L"Resources/texture.png");
	sprite1 = Sprite::Create(2, { 0,0 });
	sprite2 = Sprite::Create(2, { 500,500 }, { 1,0,0,1 }, { 0,0 }, false, true);

	//for (int i = 0; i < 100; i++)
	//{
	//	const float rnd_pos = 10.0f;
	//	XMFLOAT3 pos{};
	//	pos.x = (float)rand() / RAND_MAX * rnd_pos - rnd_pos / 2.0f;
	//	pos.y = (float)rand() / RAND_MAX * rnd_pos - rnd_pos / 2.0f;
	//	pos.z = (float)rand() / RAND_MAX * rnd_pos - rnd_pos / 2.0f;

	//	const float rnd_vel = 0.1f;
	//	XMFLOAT3 vel{};
	//	vel.x = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
	//	vel.y = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
	//	vel.z = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;

	//	const float rnd_acc = 0.001f;
	//	XMFLOAT3 acc{};
	//	acc.y = -(float)rand() / RAND_MAX * rnd_acc;

	//	particleMan->Add(60, pos, vel, acc, 1.0f, 0.0f);
	//}
}

void GameScene::Update()
{
	if (input->PushKey(DIK_1)) {
		mord = Billboard;
	}
	else if (input->PushKey(DIK_2)) {
		mord = ChangeScaleParticle;
	}
	else if (input->PushKey(DIK_3)) {
		mord = EmitterMord;
	}



	// カメラ移動
	if (input->PushKey(DIK_W) || input->PushKey(DIK_S) || input->PushKey(DIK_D) || input->PushKey(DIK_A))
	{
		if (input->PushKey(DIK_W)) { ParticleManager::CameraMoveVector({ 0.0f,+1.0f,0.0f }); }
		else if (input->PushKey(DIK_S)) { ParticleManager::CameraMoveVector({ 0.0f,-1.0f,0.0f }); }
		if (input->PushKey(DIK_D)) { ParticleManager::CameraMoveVector({ +1.0f,0.0f,0.0f }); }
		else if (input->PushKey(DIK_A)) { ParticleManager::CameraMoveVector({ -1.0f,0.0f,0.0f }); }
	}
	if (input->PushKey(DIK_W) || input->PushKey(DIK_S) || input->PushKey(DIK_D) || input->PushKey(DIK_A))
	{
		if (input->PushKey(DIK_W)) { Object3d::CameraMoveVector({ 0.0f,+1.0f,0.0f }); }
		else if (input->PushKey(DIK_S)) { Object3d::CameraMoveVector({ 0.0f,-1.0f,0.0f }); }
		if (input->PushKey(DIK_D)) { Object3d::CameraMoveVector({ +1.0f,0.0f,0.0f }); }
		else if (input->PushKey(DIK_A)) { Object3d::CameraMoveVector({ -1.0f,0.0f,0.0f }); }
	}
	if (input->TriggerKey(DIK_R)) {
		Object3d::ResetCamera();
		ParticleManager::ResetCamera();
	}

	if (input->PushKey(DIK_SPACE)) {
		XMFLOAT2 position = sprite1->GetPosition();
		position.x += 1.0f;
		sprite1->SetPosition(position);
	}

	switch (mord)
	{
	case Billboard:
		billboard3d->Update(true);
		object3d->Update();
		break;
	case ChangeScaleParticle:
		for (int i = 0; i < 5; i++)
		{
			const float rnd_pos = 10.0f;
			XMFLOAT3 pos{};
			pos.x = (float)rand() / RAND_MAX * rnd_pos - rnd_pos / 2.0f;
			pos.y = (float)rand() / RAND_MAX * rnd_pos - rnd_pos / 2.0f;
			pos.z = (float)rand() / RAND_MAX * rnd_pos - rnd_pos / 2.0f;

			const float rnd_vel = 0.1f;
			XMFLOAT3 vel{};
			vel.x = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
			vel.y = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
			vel.z = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;

			const float rnd_acc = 0.001f;
			XMFLOAT3 acc{};
			acc.y = -(float)rand() / RAND_MAX * rnd_acc;

			XMFLOAT4 s_color{};
			s_color.x = (float)rand() / RAND_MAX;
			s_color.y = (float)rand() / RAND_MAX;
			s_color.z = (float)rand() / RAND_MAX;
			s_color.w = 1.0f;
			XMFLOAT4 e_color{};
			e_color.x = (float)rand() / RAND_MAX;
			e_color.y = (float)rand() / RAND_MAX;
			e_color.z = (float)rand() / RAND_MAX;
			e_color.w = 0.0f;

			particleMan->Add(60, pos, vel, acc, 1.0f, 0.0f, s_color, e_color);
		}
		break;
	case EmitterMord:
		// オブジェクト移動
		if (input->PushKey(DIK_UP) || input->PushKey(DIK_DOWN) || input->PushKey(DIK_RIGHT) || input->PushKey(DIK_LEFT))
		{
			// 現在の座標を取得
			XMFLOAT3 position = afterEffect.GetPosition();

			float spd = 0.5f;
			// 移動後の座標を計算
			if (input->PushKey(DIK_UP)) { position.y += spd; }
			else if (input->PushKey(DIK_DOWN)) { position.y -= spd; }
			if (input->PushKey(DIK_RIGHT)) { position.x += spd; }
			else if (input->PushKey(DIK_LEFT)) { position.x -= spd; }

			// 座標の変更を反映
			afterEffect.SetPosition(position);
		}

		for (int i = 0; i < 5; i++)
		{
			const float rnd_pos = 2.0f;
			XMFLOAT3 pos = afterEffect.GetPosition();
			pos.x += (float)rand() / RAND_MAX * rnd_pos - rnd_pos / 2.0f;
			pos.y += (float)rand() / RAND_MAX * rnd_pos - rnd_pos / 2.0f;
			pos.z += (float)rand() / RAND_MAX * rnd_pos - rnd_pos / 2.0f;

			const float rnd_vel = 0.1f;
			XMFLOAT3 vel{};
			vel.x = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
			vel.y = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;
			vel.z = (float)rand() / RAND_MAX * rnd_vel - rnd_vel / 2.0f;

			const float rnd_acc = 0.001f;
			XMFLOAT3 acc{};
			acc.y = -(float)rand() / RAND_MAX * rnd_acc;

			XMFLOAT4 s_color{};
			s_color.x = (float)rand() / RAND_MAX;
			s_color.y = (float)rand() / RAND_MAX;
			s_color.z = (float)rand() / RAND_MAX;
			s_color.w = 1.0f;
			XMFLOAT4 e_color{};
			e_color.x = (float)rand() / RAND_MAX;
			e_color.y = (float)rand() / RAND_MAX;
			e_color.z = (float)rand() / RAND_MAX;
			e_color.w = 0.0f;

			particleMan->Add(120, pos, vel, acc, 1.0f, 0.0f, s_color, e_color);
		}
		break;
	default:
		break;
	}
	particleMan->Update();
}

void GameScene::Draw()
{
	// コマンドリストの取得
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(cmdList);
	// 背景スプライト描画
	spriteBG->Draw();

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Object3d::PreDraw(cmdList);

	// 3Dオブクジェクトの描画

	switch (mord)
	{
	case Billboard:
		billboard3d->Draw();
		object3d->Draw();
		break;
	case ChangeScaleParticle:
		break;
	default:
		break;
	}

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	Object3d::PostDraw();

	ParticleManager::PreDraw(cmdList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	
	// 3Dオブジェクト描画後処理
	
	particleMan->Draw();

	// 3Dオブジェクト描画後処理
	ParticleManager::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(cmdList);

	//sprite1->Draw();
	//sprite2->Draw();
	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// デバッグテキストの描画
	debugText.DrawAll(cmdList);

	// スプライト描画後処理
	Sprite::PostDraw();
#pragma endregion
}
