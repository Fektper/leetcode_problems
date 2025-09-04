class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d1 = z > x ? z-x : x-z;
        int d2 = z > y ? z-y : y-z;
        return d1>d2 ? 2 : d1 == d2 ? 0 : 1;
    }
}; 