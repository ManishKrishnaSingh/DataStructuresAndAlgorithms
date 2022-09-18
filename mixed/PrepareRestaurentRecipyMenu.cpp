#include <bits/stdc++.h>

using namespace std;

/******************************************************
Items:-
1. Bread:
    Raw Ingredients: Flour, Yeast
    Intermediate Ingredients: NONE
2. Sandwich:
    Raw Ingredients: Ham, Cheese, Paneer
    Intermediate Ingredients: Bread
3. Salad:
    Raw Ingredients: Cheese, Tomato, Basil, Cucumber
    Intermediate Ingredients: NONE
4. Platter:
    Raw Ingredients: NONE
    Intermediate Ingredients: Sandwich, Salad

Ingredients:-
{Flour, Yeast, Cheese, Tomato, Ham, Basil, Cucumber}

-> Menu: {___}
******************************************************/

unordered_set<string> rawIngredients {
    "Flour", "Yeast","Cheese", "Tomato", "Ham", "Basil", "Cucumber"
};

unordered_map<string, list<string>> mRecipyToIngredients {
  {"Bread",    {"Flour", "Yeast"}},
  {"Sandwich", {"Ham", "Cheese", "Paneer", "Bread"}},
  {"Salad",    {"Cheese", "Tomato", "Basil", "Cucumber"}},
  {"Platter",  {"Sandwich", "Salad"}}
};

bool IsPossibleToBuildRecipy(list<string> &iIngredients, unordered_map<string, bool>& mRecipy){
    // intermediate ingredients to check
    vector<string> intermediateIngredients;

    // check if all ingredients available
    for(string ingredient : iIngredients){
        // if ingredient is neither in raw ingredients nor in intermediate ingredients, return false
        if ((rawIngredients.find(ingredient)==rawIngredients.end()) && (mRecipyToIngredients.find(ingredient)==mRecipyToIngredients.end()))
        {
            return false;
        }

        // prepare intermediate ingredients if not available
        if((mRecipyToIngredients.find(ingredient) != mRecipyToIngredients.end())){
            if(!mRecipy[ingredient]){
                intermediateIngredients.push_back(ingredient);
		mRecipy[ingredient] = IsPossibleToBuildRecipy(mRecipyToIngredients[ingredient], mRecipy);
            }
        }
    }
    
    // check if all intermediate ingredients are available
    for(string ingredient : intermediateIngredients){
        if(!mRecipy[ingredient]){
            return false;
        }
    }

    return true;
}

void buildRestaurentMenu(){
    // item avilability recipy map
    unordered_map<string, bool> mRecipy;
    for(auto item : mRecipyToIngredients){
        mRecipy[item.first] = false;
    }
    
    // update recipy map if recipy possible
    for(auto item : mRecipyToIngredients){
        if(mRecipy[item.first] == false){
            mRecipy[item.first] = IsPossibleToBuildRecipy(item.second, mRecipy);
        }
    }

    // Publish Today's Menu
    cout<<"Today's Menu:-"<<endl;
    for(auto recipy : mRecipy){
        if(recipy.second == true){
            cout<<"- "<<recipy.first<<" in availble.\n";
        }
    }
}

int main() {
    buildRestaurentMenu();
    return 0;
}
