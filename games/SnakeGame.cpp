#include <bits/stdc++.h>

using namespace std;

/*
char direction:
    U -> UP
    D -> DOWN
    L -> LEFT
    R -> RIGHT
*/

class SnakeGame{
  private:
    int width;
    int height;
    int score;

    list<pair<int,int>> food;
    list<pair<int,int>> snake;

  public:
    SnakeGame(int iWidth, int iHeight, list<pair<int,int>> iFood){
        this->score = 0;
        this->width  = iWidth;
        this->height = iHeight;
        this->food   = iFood;
        this->snake.push_back({0,0});
    }

    int move(char direction){
        int sLength = snake.size();
        if(sLength > height*width){
            return -1;
        }

        int sFood = food.size();

        pair<int,int> sFront = snake.front();
        int xSnakeHead = sFront.first;
        int ySnakeHead = sFront.second;

        if(direction == 'U'){
            xSnakeHead--;
        } else if(direction == 'D'){
            xSnakeHead++;
        } else if(direction == 'L'){
            ySnakeHead--;
        } else if(direction == 'R'){
            ySnakeHead++;
        }

        if(xSnakeHead<0 || xSnakeHead>=height || ySnakeHead<0 || ySnakeHead>= width){
            return -1;
        }

        pair<int,int> newHead{xSnakeHead, ySnakeHead};

        list<pair<int,int>>::iterator iter;
        iter = find(food.begin(), food.end(), newHead);
        if(iter != food.end()){
            score++;
            food.erase(iter);
        } else {
            snake.pop_back();
        }

        iter = find(snake.begin(), snake.end(), newHead);
        if(iter != snake.end()){
            return -1;
        }
        snake.push_front(newHead);

        return score;
    }
};

int main(){
    cout<<"Snake Game";
    return 0;
}

