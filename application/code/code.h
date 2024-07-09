#pragma once
#include<iostream>
#include "../simulator/simulator.h"
#include<vector>

namespace rwa2group3{
class Maze: public Simulator
{   
    public:
    std::pair<int,int> return_goal();
    void set_cell_color(int x, int y, char c);
    void set_wall_color(int x, int y, char r, int orientation);
};

class Algorithm: public Simulator
{
    public:
    // std::pair<int,int> goal;
    void right();
    void left();
    std::vector<std::pair<int,int>> return_tracks();

    private:
    std::vector<std::pair<int,int>> tracking;

};

class Robot: public Simulator
{
    public:
    void turn_left();
    void turn_right();
    void move_forward();
    void turn_around();

    std::pair<int,int> get_current_location();
    int return_orientation();
    void set_orientation(int orientation_new);
    void setCurrentLocation(std::pair<int,int> L);
    int front_wall();
    int right_wall();
    int left_wall();


    private:
    std::pair<int,int> current_location;
    int orientation = 0;

};


}