#include <bits/stdc++.h>

using namespace std;

/**************************************************************
Input data:-
    - foods[i]    : Name of the ith food,
    - cuisines[i] : Type of cuisine of ith food
    - ratings[i]  : Initial rating of the ith food
Note: rating is -ve to get the food to reverse order of rating
**************************************************************/

class FoodRatingSystem
{
    // unordered map of {food, rating}
    unordered_map<string,int> mFoodRating;
    // unordered map of {food, cuisine}
    unordered_map<string,string> mFoodFamily;
    // ordered map of {cuisine, set of {rating, food}};
    map<string,set<pair<int,string>>> mCuisineToFoods;

  public:
    FoodRatingSystem(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
    {
        for(int i=0;i<foods.size();++i)
        {
            mFoodRating[foods[i]] = -ratings[i];
            mFoodFamily[foods[i]] = cuisines[i];
            mCuisineToFoods[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }

    void changeRating(string food, int newrating)
    {
        int prevrating = mFoodRating[food];
        string cuisine = mFoodFamily[food];
        // update the food rating
        mFoodRating[food] = -newrating;
        // remove prev food rating and add the new rating
        mCuisineToFoods[cuisine].erase({prevrating,food});
        mCuisineToFoods[cuisine].insert({-newrating,food});
    }

    string highestRated(string cuisine)
    {
        string rating = "";
        if(mCuisineToFoods[cuisine].size() > 0){
            rating = mCuisineToFoods[cuisine].begin()->second;
        }
        return rating;
    }
};

int main()
{
    cout<<"Food Rating System"<<endl;

    vector<int> ratings     = {9, 12, 8, 15, 14, 7};
    vector<string> foods    = {"kimchi","miso","sushi","moussaka","ramen","bulgogi"};
    vector<string> cuisines = {"korean","japanese","japanese","greek","japanese","korean"};

    FoodRatingSystem frs(foods,cuisines,ratings);

    cout<<"\nHighest Rated Cuisine: "<<frs.highestRated("korean");
    cout<<"\nHighest Rated Cuisine: "<<frs.highestRated("japanese");
    frs.changeRating("sushi", 16);
    cout<<"\nHighest Rated Cuisine: "<<frs.highestRated("japanese");
    frs.changeRating("ramen", 16);
    cout<<"\nHighest Rated Cuisine: "<<frs.highestRated("japanese");

    return 0;
}