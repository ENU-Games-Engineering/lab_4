#include "game_parameters.hpp"
#include "game_system.hpp"
#include "scenes.hpp"

using param = Parameters;

int main(){
  Scenes::maze = std::make_shared<MazeScene>();
  Scenes::end = std::make_shared<EndScene>();
  std::static_pointer_cast<MazeScene>(Scenes::maze)->set_file_path(param::maze_1);
  GameSystem::set_active_scene(Scenes::maze);
  GameSystem::start(param::game_width,param::game_height,"tile_maze");
  return 0;
}
