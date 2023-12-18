#pragma once

class PlayerEnemyManager
{
public:

	void LoadImages();
	//敵のパターン小分け
	void BackGround1();
	void Enemy1();
	void Enemy2();
	void Enemy3();
	void Enemy4();
	void Enemy5();
	void Enemy6();
	void Boss();
	int  rang(int x);
	void Bossmove( int dist);
	//プレイヤ―
	void Player();
	//プレイヤーショット
	void Player_Shooting();
	//敵ショット
	void Enemy_Shooting();
	void Enemy_Shooting_H();
	void Enemy_Shooting_M();
	void Boss_Shooting();

	void Rotate();
	//スコア
	void Score();
	//パターン処理
	void EnemyAppearPattern();
	void Attack_area(int character_x,int character_y,int g_handle,bool visible,int life,int x,int y);
	//敵に弾が当たったら
	

};

