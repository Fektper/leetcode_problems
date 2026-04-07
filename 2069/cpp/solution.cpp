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
        int safe_steps;
        while (num > 1){
            singleStep();
            num--;
            if (this->dx == 0){
                // Dir is in y
                // y + n*dy >= 0
                // y + d*dy < this->h
                // n <= -y/dy
                safe_steps = this->dy < 0 ? -this->y / this->dy : (this->h - this->y - 1);
            }
            else {
                // x + n*dx >= 0
                // -x/dx >= n
                safe_steps = this->dx < 0 ? -this->x / this->dx : (this->w - this->x - 1);
                // Dir is in x
            }
            safe_steps = min(num, safe_steps);
            this->safeSteps(safe_steps);
            num -= safe_steps;
        }
        if (num == 1){
            singleStep();
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
    void safeSteps(int n){
        this->x = this->x + this->dx * n;
        this->y = this->y + this->dy * n;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */