#pragma once

#include <string>		
#include <assert.h>	
#include <vector>
#include <iostream>
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
    bool got_nut = false;
public:
      //Default
	  //void set_up();
	  Game(string name);
      vector<vector<char>> prepare_grid();
      void process_input(int key);
	  void cheat(int key);
      bool is_running() const;
      //int find_hole_number_at_position(int x, int y);
      string get_end_reason();
      Player get_player() const;
	  void undo_input(int key);
};