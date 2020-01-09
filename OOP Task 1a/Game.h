#pragma once

#include <string>		
#include <assert.h>	
#include <vector>

#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "Player.h"

using namespace std;

class Game
{
private:
	Mouse mouse;
	Snake snake;
	Underground underground;
    Player player;
    void apply_rules();

public:
      //Default
	  void set_up();
	  Game();
      vector<vector<char>> prepare_grid();
      void process_input(int key);
      bool is_running();
      //int find_hole_number_at_position(int x, int y);
      string get_end_reason();
};