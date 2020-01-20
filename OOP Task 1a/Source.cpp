#include "raylib.h"
#include "Game.h"
using namespace std;
int main()
{
	InitWindow(900, 600, "OOP Assignment 1");
	SetTargetFPS(144);

	//I'm taking names
	string name;
	cout << "Please enter your name: ";
	cin >> name;
	//And giving them to games.

	Game game(name);
	//game.set_up();
	game.get_player().update_score(0);

	char input;
	input = getchar() | 32; //"or"ed with 32 acts like "toupper" for a char. y-->Y but Y-/->y
	bool last_move_undone = false;
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		if (game.is_running())
		{
			if (IsKeyPressed(KEY_RIGHT)) { game.process_input(KEY_RIGHT); last_move_undone = false; }
			if (IsKeyPressed(KEY_LEFT)) { game.process_input(KEY_LEFT); last_move_undone = false; }
			if (IsKeyPressed(KEY_UP)) { game.process_input(KEY_UP); last_move_undone = false; }
			if (IsKeyPressed(KEY_DOWN)) { game.process_input(KEY_DOWN); last_move_undone = false; }
			if (IsKeyPressed(CHEAT))	  game.cheat(CHEAT);
			if (IsKeyPressed(UNDO)) 
			{ 
				if (!last_move_undone)
				{ 
					game.undo_input(UNDO);
					last_move_undone = true;
				} 
				else
				{
					cout << "No more undo's this turn!\n";
				}
			};
		}
		else
		{
			DrawText(game.get_end_reason().c_str(), 610, 35, 20, LIGHTGRAY);
			DrawText("Would you like to play again? Y or N", 610, 35, 20, LIGHTGRAY);
			cout << "Would you like to play again? Y or N: ";
			input = ' ';
			cin >> input;

			if (input == 'N')
			{
				CloseWindow();
				cout << "You have exit the game";
			}

		}

		const int cellSize = (int)((float)GetScreenHeight() / (float)(SIZE));

		const auto grid = game.prepare_grid();

		for (int x = 0; x < SIZE; x++)
		{
			for (int y = 0; y < SIZE; y++)
			{
				int xPosition = x * cellSize;
				int yPosition = y * cellSize;

				switch (grid[y][x])
				{
					case HOLE:       DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK);     break;
					case MOUSE:      DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);     break;
					case FREECELL:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, DARKGREEN); break;
					case NUT:		 DrawRectangle(xPosition, yPosition, cellSize, cellSize, BROWN);	 break;
					case SNAKETAIL:	 DrawRectangle(xPosition, yPosition, cellSize, cellSize, PURPLE);	 break;
					case SNAKEHEAD:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, RED);       break;
					default:         assert(false); // if this assert triggers there's an unrecognised tile on the grid!
				}

				// draw lines around each tile, remove this if you don't like it!
				DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, DARKGRAY);
			}
		}

		//Draw texts (score, name, etc...)
		string title_1 = "Name: " + name;
		DrawText(title_1.c_str() , 610, 35, 20, LIGHTGRAY);
		DrawText("Score: " + game.get_player().get_score(), 610, 60, 20, LIGHTGRAY);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}