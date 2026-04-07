#include <string>
#include <vector>

using namespace std;

class Robot {
    int x;
    int y;
    int dx;
    int dy;
    int w;
    int h;
public:
    Robot(int width, int height) {
        this->h = height;
        this->w = width;
        this->x = 0;
        this->y = 0;
        this->dx = 1;
        this->dy = 0;
    }
    
    void step(int num) {
        for (int i = 0; i < num; i++){
            this->singleStep();
        }
    }
    
    vector<int> getPos() {
        return {this->x, this->y};
    }
    
    string getDir() {
        if (this->dy == 1){
            return "North";
        } if (this->dy == -1){
            return "South";
        } if (this->dx == 1){
            return "East";
        }
        return "West";
    }
private:
    void turn(){
        int a = this->dy;
        this->dy = this->dx;
        this->dx = -a;
    }

    void singleStep(){
        int nx; int ny;
        nx = this->x + this->dx;
        ny = this->y + this->dy;
        if (nx < 0 || nx >= this->w || ny < 0 || ny >= this->h){
            this->turn();
            this->singleStep();
        } else {
            this->x = nx;
            this->y = ny;
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */