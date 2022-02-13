#include <queue>
#include <climits>
#include <iostream>

using namespace std;

typedef struct entry{
    int score;
    int steps;
}Entry;

int minDiceThrows(int move[], int N){
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++){
        visited[i] = false;
    }

    // BFS Queue
    queue<Entry> queue;

    Entry start={0,0};
    visited[0] = true;
    queue.push(start);

    int minSteps = INT_MAX;
    while(!queue.empty()){
        Entry front = queue.front();
        queue.pop();

        int currScore = front.score;
        if(currScore == N-1){
            minSteps = front.steps; break;
        }

        for(int j=currScore+1; j<=(currScore+6) && j<N; ++j){
            if (!visited[j]){
                Entry next;
                next.steps = front.steps+1;
                visited[j] = true;

                if (move[j] != -1){
                    next.score = move[j];
                } else {
                    next.score = j;
                }
                queue.push(next);
            }
        }
    }
    return minSteps;
}

int main(){
    int N = 30;
    int moves[N];
    for (int i = 0; i<N; i++){
        moves[i] = -1;
    }

    // Ladders
    moves[2]  = 21;
    moves[4]  = 7;
    moves[10] = 25;
    moves[19] = 28;
    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout<<"Min Dice Throws = "<<minDiceThrows(moves, N);

    return 0;
}

