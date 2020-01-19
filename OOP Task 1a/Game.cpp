#include "Game.h"

Game::Game(): snake(&mouse)
{
    
}

//void Game::set_up()
//{
//    snake.spot_mouse(&mouse);
//}

void Game::process_input(int key)
{
   mouse.scamper(key);
   snake.chase_mouse();
   apply_rules();
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
         if (snake.is_at_position(row,col))
         {
			 line.push_back(SNAKEHEAD);
         }
         // is the mouse at this position?
         else if (mouse.is_at_position(row,col))
         {
            line.push_back(MOUSE);
         }
         else if (nut.is_at_position(row,col))
         {
             line.push_back(NUT);
         }
         else
         {   
             //Is there a tail in this position?
             const bool s_tail = snake.is_at_tail(col, row);
            //Is there a hole in this position?
			const bool hole_no = underground.is_at_hole(col,row);
             
            if (s_tail)
            {
                 line.push_back(s_tail);
            }
            else
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
      
      if (mouse.can_collect_nut(nut))
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
   if (mouse.has_escaped())
      return "You escaped underground!";

   return "The snake ate you!";
}
