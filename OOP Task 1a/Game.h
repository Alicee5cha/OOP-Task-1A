#pragma once

#include <string>		
#include <assert.h>	
#include <vector>

#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "Player.h"
#include "Nut.h"
#include "Hole.h"

using namespace std;

class Game
{
private:
	Mouse mouse;
	Snake snake;
    Nut nut;
	Underground underground;
    Player player;
    void apply_rules();
    bool got_nut;
public:
      //Default
	  void set_up();
	  Game();
      vector<vector<char>> prepare_grid();
      void process_input(int key);
	  void undo_input(int key);
	  void cheat(int key);
      bool is_running();
      //int find_hole_number_at_position(int x, int y);
      string get_end_reason();
      bool can_collect_nut() const;
};