#include <bits/stdc++.h>

using namespace std;

class MovieRentingSystem {
    int noOfShops;
    //rented set of {price, {shop,movie}}
    set<pair<int, pair<int,int>>> rented;
    //available set of {price, {shop,movie}}
    set<pair<int, pair<int,int>>> available;

    map<pair<int,int>, int> mShopMovieToPrice;
    unordered_map<int, set<pair<int,int>>> mMovieToPriceShop;

  public:
    MovieRentingSystem(int nShops, vector<vector<int>>& entries){
        this->noOfShops = nShops;
        for(int i=0; i<entries.size(); i++){
            int shop = entries[i][0];
            int movie = entries[i][1];
            int price = entries[i][2];
            // initially all movies are available
            available.insert({price, {shop, movie}});
            // store price for unique pair {shop,movie}
            mShopMovieToPrice[{shop,movie}] = price;
            // store all movies with their {price,shop}
            mMovieToPriceShop[movie].insert({price,shop});
        }
    }

    vector<int> search(int movie){
        vector<int> shops; //5 cheapest available shops
        for(auto pPriceShop : mMovieToPriceShop[movie]){
            if(shops.size() == 5) break;
            shops.push_back(pPriceShop.second);
        }
        return shops;
    }

    void rent(int shop, int movie){
        // remove the movie from the given shop
        int price = mShopMovieToPrice[{shop,movie}];
        // add this movie in rented
        rented.insert({price, {shop, movie}});
        // remove this movie from available
        available.erase({price, {shop, movie}}); 
        // also, erase this shop from the movies
        mMovieToPriceShop[movie].erase(mMovieToPriceShop[movie].find({price,shop}));
    }

    void drop(int shop, int movie) {
        int price = mShopMovieToPrice[{shop,movie}];
        // add in available as movie is back in the shop
        available.insert({price, {shop, movie}});
        mMovieToPriceShop[movie].insert({price,shop});
        // remove entry from rented movies
        rented.erase({price, {shop, movie}});
    }

    vector<vector<int>> report(){
        // 5 cheapest rented {shop, movie}
        vector<vector<int>> lisOfShopMovie;
        for(auto entry : rented)
        {
            if(lisOfShopMovie.size() == 5) break;
            int shop =  entry.second.first;
            int movie = entry.second.second;
            lisOfShopMovie.push_back({shop,movie});
        }
        return lisOfShopMovie;
    }
};

int main(){
    int movie = 2, shop = 1;
    // List of {shop, movie, price}
    vector<vector<int>> entries = {
        {0, 1, 5}, {0, 2, 6}, {0, 3, 7}, {1, 1, 4}, {1, 2, 7}, {2, 1, 5}
    };

    cout<<"Movie Renting System"<<endl;
    MovieRentingSystem mrs(3, entries);

    vector<int> shops=mrs.search(movie);

    mrs.rent(shop,movie);
    mrs.drop(shop,movie);

    vector<vector<int>> pShopMovie = mrs.report();

    return 0;
}