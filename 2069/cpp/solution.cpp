#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

class Robot {
    int current_steps;
    map<int, vector<int>> step_map;
    map<int, vector<int>> dir_map;
    int max_steps;
public:
    Robot(int width, int height) {
        this->current_steps = 0;
        this->max_steps = (width-1)*2 + (height-1)*2;

        int current_step = 0;
        this->step_map[0] = {0, 0};
        this->dir_map[0] = {1, 0};
        
        this->step_map[width - 1] = {width-1, 0};
        this->dir_map[width - 1] = {1, 0};
        this->step_map[width] = {width-1, 1};
        this->dir_map[width] = {0, 1};

        this->step_map[width - 1 + 1 + height - 2] = {width-1, height-1};
        this->dir_map[width -1 + 1 + height - 2] = {0, 1};
        this->step_map[width -1 + 1 + height - 2 + 1] = {width-2, height-1};
        this->dir_map[width -1 + 1 + height - 2 + 1] = {-1, 0};

        this->step_map[width -1 + 1 + height - 2 + 1 + width - 2] = {0, height-1};
        this->dir_map[width -1 + 1 + height - 2 + 1 + width - 2] = {-1, 0};
        this->step_map[width -1 + 1 + height - 2 + 1 + width - 2 + 1] = {0, height-2};
        this->dir_map[width -1 + 1 + height - 2 + 1 + width - 2 + 1] = {0, -1};

        this->step_map[width -1 + 1 + height - 2 + 1 + width - 2 + 1 + height - 2] = {0, 0};
        this->dir_map[width -1 + 1 + height - 2 + 1 + width - 2 + 1 + height - 2] = {0, -1};
    }
    
    void step(int num) {

        this->current_steps = (this->current_steps + num);
        while (this->current_steps > this->max_steps){
            this->current_steps -= this->max_steps;
        }
    }
    
    vector<int> getPos() {
        if (this->current_steps == 0){
            return {0, 0};
        }

        auto res_pos = this->step_map.lower_bound(this->current_steps);
        if (res_pos->first != this->current_steps){
            res_pos--;
        }
        auto pos = res_pos->second;
        auto dir = this->dir_map[res_pos->first];

        int n = current_steps - res_pos->first;
        int x = n * dir[0] + pos[0];
        int y = n*dir[1] + pos[1];
        return {x, y};
        // return {this->x, this->y};
    }
    
    string getDir() {
        if (current_steps == 0){
            return "East";
        }
        auto res_dir = this->dir_map.lower_bound(this->current_steps);
        if (res_dir->first != this->current_steps){
            res_dir--;
        }

        int dx = res_dir->second[0];
        int dy = res_dir->second[1];

        if (dy == 1){
            return "North";
        } if (dy == -1){
            return "South";
        } if (dx == 1){
            return "East";
        }
        return "West";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

int main(){
    Robot rob = Robot({6, 3});
    rob.step(2);
    rob.step(2);
    rob.step(2);
    rob.step(1);
    rob.step(4);

    std::cout << rob.getPos()[0] << ", " << rob.getPos()[1] << "\n";
    std::cout << rob.getDir() << "\n";
    // rob.step(2);
    // std::cout << rob.getPos()[0] << ", " << rob.getPos()[1] << "\n";
    // std::cout << rob.getDir() << "\n";
    // rob.step(20);
    // std::cout << rob.getPos()[0] << ", " << rob.getPos()[1] << "\n";
    // std::cout << rob.getDir() << "\n";
    // [[6,3],[2],[2],[],[],[2],[1],[4],[],[]]
    // ["Robot","step","step","getPos","getDir"
}