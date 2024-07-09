#include <iostream>
#include <string>
#include "code/code.h"
#include <utility>
#include <memory>


int main(int argc, char *argv[])
{
    std::pair<int,int> goal;

    std::unique_ptr<rwa2group3::Maze> maze_object = std::make_unique<rwa2group3::Maze>();
    goal = maze_object->return_goal();
    char c = 'G';
    maze_object->set_cell_color(goal.first, goal.second, c);
    std::unique_ptr<rwa2group3::Robot> robot = std::make_unique<rwa2group3::Robot>();
    robot->setCurrentLocation(std::make_pair(0,0));
    std::pair<int,int> loc;
    int orientation;
    loc = robot->get_current_location();
    orientation = robot->return_orientation();
    maze_object->set_wall_color(loc.first,loc.second, 'r', orientation);
    maze_object->set_cell_color(loc.first,loc.second,'c');

    //right hand rule//

    while(robot->get_current_location() != goal)
    {
        if(robot->right_wall())
         {   
            robot->turn_right();
            robot->move_forward();
            loc = robot->get_current_location();
            orientation = robot->return_orientation();
            maze_object->set_wall_color(loc.first,loc.second, 'r', orientation);
            if(loc == goal)
            {
                continue;
            }
            else
            {
            maze_object->set_cell_color(loc.first,loc.second,'c');
            }
        }
        else if(robot->front_wall())
        {
            robot->move_forward();
            loc = robot->get_current_location();
            orientation = robot->return_orientation();
            maze_object->set_wall_color(loc.first,loc.second, 'r', orientation);
            if(loc == goal)
            {
                continue;
            }
            else
            {
            maze_object->set_cell_color(loc.first,loc.second,'c');
            }
        }
        else if(robot->left_wall())
        {
            robot->turn_left();
            robot->move_forward();
            loc = robot->get_current_location();
            orientation = robot->return_orientation();
            maze_object->set_wall_color(loc.first,loc.second, 'r', orientation);
            if(loc == goal)
            {
                continue;
            }
            else
            {
            maze_object->set_cell_color(loc.first,loc.second,'c');
            }
        }
        else 
        {
            robot->turn_around();
        }
    }


 //left hand rule//

    //     while(robot->get_current_location() != goal)
    //     {
    //     if(robot->left_wall())
    //     {
    //         robot->turn_left();
    //         robot->move_forward();
    //         loc = robot->get_current_location();
    //         orientation = robot->return_orientation();
    //         maze_object->set_wall_color(loc.first,loc.second, 'r', orientation);
    //         if(loc == goal)
    //         {
    //             continue;
    //         }
    //         else
    //         {
    //         maze_object->set_cell_color(loc.first,loc.second,'c');
    //         }
    //     }
        
    //     else if(robot->front_wall())
    //     {
    //         robot->move_forward();
    //         loc = robot->get_current_location();
    //         orientation = robot->return_orientation();
    //         maze_object->set_wall_color(loc.first,loc.second, 'r', orientation);
    //         if(loc == goal)
    //         {
    //             continue;
    //         }
    //         else
    //         {
    //         maze_object->set_cell_color(loc.first,loc.second,'c');
    //         }
    //     }
    //     else if(robot->right_wall())
    //      {   
    //         robot->turn_right();
    //         robot->move_forward();
    //         loc = robot->get_current_location();
    //         orientation = robot->return_orientation();
    //         maze_object->set_wall_color(loc.first,loc.second, 'r', orientation);
    //         if(loc == goal)
    //         {
    //             continue;
    //         }
    //         else
    //         {
    //         maze_object->set_cell_color(loc.first,loc.second,'c');
    //         }
    //     }
    //     else 
    //     {
    //         robot->turn_around();
    //     }
    // }


}

