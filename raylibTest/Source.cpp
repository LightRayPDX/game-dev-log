// Skeleton — the minimum viable game loop
#include "raylib.h"

int main() {
	InitWindow(800, 600, "Something Moves");
	SetTargetFPS(60);
	// your variables go here (position, velocity, etc.)
	float playerWidth = 100;
	float playerHeight = 20;
	float playerX = 400;
	float playerY = 550;
	float spawnTimer = 0;
	float speed = 15;
	float spawnTimer = 10;
	float spawnInterval = 30;
	while (!WindowShouldClose()) {
		float dt = GetFrameTime(); // seconds since last frame
		// UPDATE: move things, check collisions
		spawnTimer += dt;
		if (spawnTimer >= spawnInterval)
		{
			spawnTimer = 0.0f;
		}
		if (playerX < 0)
		{
			playerX = 0;
		}
		if (playerX + playerWidth > GetScreenWidth())
		{
			playerX = GetScreenWidth() - playerWidth;
		}
		if (playerX > 0)
		{
			if (IsKeyDown(KEY_LEFT))
			{
				playerX -= speed;
			}
		}
		if (playerX + playerWidth < GetScreenWidth())
		{
			if (IsKeyDown(KEY_RIGHT))
			{
				playerX += speed;
			}
		}
		BeginDrawing();

		ClearBackground(BLACK);
		// DRAW: put things on screen here
		DrawRectangle((int)playerX, (int)playerY, (int)playerWidth, (int)playerHeight, RED);
		struct FallingObject
		{
			float objX, objY;
			float width = 30;
			float height = 30;
			float objSpeed = 15;
		};
		EndDrawing();
	}
	CloseWindow();
	return 0;
}