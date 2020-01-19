#include "Game.h"

Game::Game(string name): snake(&mouse), player(name)
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
         if (snake.is_at_position(col,row))
         {
			 line.push_back(SNAKEHEAD);
         }
         // is the mouse at this position?
         else if (mouse.is_at_position(col, row))
         {
            line.push_back(MOUSE);
         }
         // is the nut at this position?
         else if (nut.is_at_position(col, row))
         {
             line.push_back(NUT);
         }
         // is a tail part at this position?
         else if (snake.is_at_tail(col, row))
         {
             line.push_back(SNAKETAIL);
         }
         // is a hole at this position?
         else if (underground.is_at_hole(col, row))
         {
             line.push_back(HOLE);
         }
         // if there is nothing above at this location it must be a free cell.
         else
         {   
             line.push_back(FREECELL);
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
      
      if (mouse.can_collect_nut(nut) &&  mouse.is_at_position(nut.get_x(),nut.get_y()))
      {
              nut.disappear();
      }
   }
}

bool Game::is_running()const
{
   return mouse.is_alive() && !mouse.has_escaped();
}

string Game::get_end_reason()
{
    if (mouse.has_escaped())
    {
        player.update_score(1);
        return "You escaped underground!";
    }

    player.update_score(-1);
    return "The snake ate you!";
}

Player Game::get_player()const
{
    return player;
}