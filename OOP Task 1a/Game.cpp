#include "Game.h"

Game::Game()
{
    
}

void Game::set_up()
{
    snake.spot_mouse(&mouse);
}

void Game::process_input(int key)
{
   mouse.scamper(key);
   snake.chase_mouse();
   apply_rules();
}

void Game::undo_input(int key)
{
	if (mouse.is_at_position(SIZE / 2, SIZE / 2))
	{
		snake.undo_snake();
		"No actions to undo";

	}
	else
	{
		"Undone last action";
	}
}

void Game::cheat(int key)
{
	"Cheat mode is ON";
	mouse.scamper(key);
	apply_rules();
	player.update_score(0);

}

vector<vector<char>> Game::prepare_grid()
{
   // create the 2D grid
   vector<vector<char>> grid;

   // for each row
   for (int row = 1; row <= SIZE; ++row)
   {
      // create a row to add to the 2D grid
      vector<char> line;

      // for each column
      for (int col = 1; col <= SIZE; ++col)
      {
         // is the snake at this position?
         if (row == snake.get_x() && col == snake.get_x())
         {
			 line.push_back(SNAKEHEAD);

         }
         // is the mouse at this position?
         else if (row == mouse.get_y() && col == mouse.get_x())
         {
            line.push_back(MOUSE);
         }
         else
         if (row == nut.get_x() && col == nut.get_y())
         {
             line.push_back(NUT);
         }
         else
         {
            // is there a hole at this position?
            //const int hole_no = find_hole_number_at_position(col, row);
			const bool hole_no = underground.isAtHole(col,row);
            
			if (hole_no)
            {
               line.push_back(HOLE);
            }
            else
            {
               // none of the above, must be nothing at this position
               line.push_back(FREECELL);
            }
         }
      }

      // now that the row is full, add it to the 2D grid
      grid.push_back(line);
   }

   return grid;
}

void Game::apply_rules()
{
   if (snake.has_caught_mouse())
   {
      mouse.die();
   }
   else
   {
      if (mouse.has_reached_a_hole(underground) && nut.has_been_collected())
      {
         mouse.escape_into_hole();
      }
      
      if (!mouse.can_collect_nut(nut))
      {
              nut.disappear();
      }
   }
}

bool Game::is_running()
{
   return mouse.is_alive() && !mouse.has_escaped();
}

string Game::get_end_reason()
{
   if (mouse.has_escaped() && nut.has_been_collected() == true)
      return "You escaped underground!";

   return "The snake ate you!";
}
