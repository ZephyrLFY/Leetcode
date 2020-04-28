#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Coordinate {
    int x;
    int y;
    Coordinate(int x, int y) : x(x), y(y) {}
};

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        int level = 0, size = 0;
        queue<Coordinate> stack;
        stack.push(Coordinate(r,c));
        double res = 1;
        while (!stack.empty()) {
            size = stack.size();
            
            if (level == K) return res;
            level++;
            for (int i = 0; i < size; i++) {
                Coordinate temp = stack.front();
                stack.pop();
                for (int j = -2; j <= 2; j += 4) {
                    for (int k = -1; k <= 1; k += 2) {
                        int x1 = temp.x + j;
                        int y1 = temp.y + k;
                        if (x1 >= 0 && x1 < N && y1 >= 0 && y1 < N) stack.push(Coordinate(x1, y1));
                    }
                }
                for (int j = -1; j <= 1; j += 2) {
                    for (int k = -2; k <= 2; k += 4) {
                        int x2 = temp.x + j;
                        int y2 = temp.y + k;
                        if (x2 >= 0 && x2 < N && y2 >= 0 && y2 < N) stack.push(Coordinate(x2, y2));
                    }
                }
            }
            res *= (double(stack.size()) / (size * 8));
        }
        return 0;
    }
};