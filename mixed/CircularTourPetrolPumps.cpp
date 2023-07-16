#include <iostream>

using namespace std;

typedef struct PretrolPump {
    int pretrol;
    int distance;
    PretrolPump(int p, int d){
        pretrol = p;
        distance = d;
    }
}PretrolPump;

int findStartCircularTour(PretrolPump pp[], int n){
    int start = 0, finish = 1;
    int currPetrol = pp[start].pretrol - pp[start].distance;

    while(start!=finish || currPetrol<0){
        while(start!=finish && currPetrol<0){
            currPetrol -= (pp[start].pretrol - pp[start].distance);
            start = (start+1)%n;
            if(start==0){
                return -1;
            }
        }

        currPetrol += (pp[finish].pretrol - pp[finish].distance);
        finish = (finish+1)%n;
    }

    return start;
}

int main(){
    PretrolPump pp[] = {{6, 4}, {3, 6}, {7, 3}};
    int npp = sizeof(pp)/sizeof(PretrolPump);

    int idx = findStartCircularTour(pp, npp);
    cout<<"Start of Circular Tour = "<<idx<<endl;

    return 0;
}

