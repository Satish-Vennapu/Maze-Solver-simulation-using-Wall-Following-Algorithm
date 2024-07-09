#include "code.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <utility>
#include <memory>

std::pair<int,int> rwa2group3::Maze::return_goal()
{
    std::pair<int,int> x;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 15);
    int X = distr(gen);
    int Y;
    if(X == 0 || X == 15)
    {
        std::uniform_int_distribution<> distry1(1, 14);
        Y = distry1(gen);
    }
    else
    {
        std::uniform_int_distribution<> distry(0, 1);
        Y = distry(gen);
        if(Y==1)
            {
                Y = 15;
            }
    }

    x = std::make_pair(X,Y);
    return x;
}

void rwa2group3::Maze::set_cell_color(int x,int y,char c)
{
    Simulator::setColor(x, y, c);
}

void rwa2group3::Maze::set_wall_color(int x, int y, char r, int orientation)
{
    if(orientation == 0)
    {
        if(Simulator::wallRight())
        {
            Simulator::setWall(x,y,'e');
        }
        if(Simulator::wallLeft())
        {
            Simulator::setWall(x,y,'w');
        }
        if(Simulator::wallFront())
        {
            Simulator::setWall(x,y,'n');
        }
    }
    if(orientation == 1)
    {
        if(Simulator::wallRight())
        {
            Simulator::setWall(x,y,'s');
        }
        if(Simulator::wallLeft())
        {
            Simulator::setWall(x,y,'n');
        }
        if(Simulator::wallFront())
        {
            Simulator::setWall(x,y,'e');
        }
    }
    if(orientation == 2)
    {
        if(Simulator::wallRight())
        {
            Simulator::setWall(x,y,'w');
        }
        if(Simulator::wallLeft())
        {
            Simulator::setWall(x,y,'e');
        }
        if(Simulator::wallFront())
        {
            Simulator::setWall(x,y,'s');
        }
    }
    if(orientation == 3)
    {
        if(Simulator::wallRight())
        {
            Simulator::setWall(x,y,'n');
        }
        if(Simulator::wallLeft())
        {
            Simulator::setWall(x,y,'s');
        }
        if(Simulator::wallFront())
        {
            Simulator::setWall(x,y,'w');
        }
    }
}

void rwa2group3::Robot::set_orientation(int orientation_new)
{
    orientation = orientation_new;
}
std::vector<std::pair<int,int>> rwa2group3::Algorithm::return_tracks()
{
    return tracking;
}

void rwa2group3::Robot::turn_left()
{

    Simulator::turnLeft();
    int orientation1 = return_orientation();
    if(orientation1 == 0)
    {
        set_orientation(3);
    }
    else
    {
        orientation1--;
        set_orientation(orientation1);
    }
}

void rwa2group3::Robot::turn_right()
{
    Simulator::turnRight();
    int orientation1 = return_orientation();
    if(orientation1 == 3)
    {
        set_orientation(0);
    }
    else
    {
        orientation1++;
        set_orientation(orientation1);
    }
}

void rwa2group3::Robot::move_forward()
{
    Simulator::moveForward();
    int orientation = return_orientation();
    if(orientation == 0)
    {
        std::pair<int,int> loc = get_current_location();
        int x = loc.first;
        int y = loc.second;
        y++;
        setCurrentLocation(std::make_pair(x,y));  
    }
    else if(orientation == 1)
    {
        std::pair<int,int> loc = get_current_location();
        int x = loc.first;
        int y = loc.second;
        x++;
        setCurrentLocation(std::make_pair(x,y));  
    }
    else if(orientation == 2)
    {
        std::pair<int,int> loc = get_current_location();
        int x = loc.first;
        int y = loc.second;
        y--;
        
        setCurrentLocation(std::make_pair(x,y));  
    }
    else
    {
        std::pair<int,int> loc = get_current_location();
        int x = loc.first;
        int y = loc.second;
        x--;
        setCurrentLocation(std::make_pair(x,y));
    }

    // rwa2group3::Maze maze;
    // std::pair<int,int> loc = get_current_location();
    // maze.set_cell_color(loc.first,loc.second,'R');
    

    
}

void rwa2group3::Robot::turn_around()
{
    Simulator::turnRight();
    int orientation1 = return_orientation();
    if(orientation1 == 3)
    {
        set_orientation(0);
    }
    else
    {
        orientation1++;
        set_orientation(orientation1);
    }
    Simulator::turnRight();
    orientation1 = return_orientation();
    if(orientation1 == 3)
    {
        set_orientation(0);
    }
    else
    {
        orientation1++;
        set_orientation(orientation1);
    }

}

void rwa2group3::Robot::setCurrentLocation(std::pair<int,int> L)
{
    current_location = L;
}

std::pair<int,int> rwa2group3::Robot::get_current_location()
{
    return current_location;
}

int rwa2group3::Robot::return_orientation()
{
    return orientation;
}

int rwa2group3::Robot::front_wall()
{

    if(Simulator::wallFront()==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int rwa2group3::Robot::right_wall()
{
    if(Simulator::wallRight()==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int rwa2group3::Robot::left_wall()
{


    if(Simulator::wallLeft()==0)
    {
        return 1;
    }
    else
    {

        return 0;
    }

}

