#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

struct MovieEntry{
    int shop;
    int movie;
    int price;

    // bool operator>(const MovieEntry& other) const{ // 
    //     if (this->price > other.price){
    //         return true;
    //     }
    //     else if (this->price < other.price){
    //         return false;
    //     }
    //     if (this->movie > other.movie)
    //     return false;
    // }

    bool operator<(const MovieEntry& other) const {
        // Sort by price asc
        if (this->price < other.price){
            return true;
        }
        else if (this->price > other.price){
            return false;
        }
        // Sort by shop asc
        if (this->shop < other.shop){
            return true;
        }
        else if (this->shop > other.shop){
            return false;
        }
        // Sort by movie asc;
        if (this->movie < other.movie){
            return true;
        }
        return false;
    }
};



class MovieRentingSystem {
public:

    unordered_map<int, set<MovieEntry, std::less<MovieEntry>>> byMovie; // Default is greatest element first, we want smallest! Therefore greater compare
    set<MovieEntry, std::less<MovieEntry>> rentals;
    unordered_map<long long int, MovieEntry> movieInfoMap;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        // shopi, moviei, price

        for (vector<int> entry: entries){
            MovieEntry this_entry = {entry[0], entry[1], entry[2]};
            
            movieInfoMap[getId(entry[0], entry[1])] = this_entry;

            if (byMovie.find(entry[1]) == byMovie.end()){
                set<MovieEntry, std::less<MovieEntry>> newSet;
                newSet.insert(this_entry);
                byMovie[entry[1]] = newSet;
            }
            else {
                byMovie[entry[1]].insert(this_entry);
            }
        }
    }
    
    vector<int> search(int movie) {
        auto& places = byMovie[movie];

        vector<int> res;
        int counter = 0;
        auto it = places.begin();
        while (counter < 5 && it != places.end()){
            res.push_back(it->shop);
            counter++;
            it = next(it);
        }

        return res;
    }
    
    void rent(int shop, int movie) {
        MovieEntry info = movieInfoMap[getId(shop, movie)];
        byMovie[movie].erase(info);
        rentals.insert(info);
    }
    
    void drop(int shop, int movie) {
        MovieEntry info = movieInfoMap[getId(shop, movie)];
        byMovie[movie].insert(info);
        rentals.erase(info);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;

        int counter = 0;
        auto it = rentals.begin();

        while (counter < 5 && it != rentals.end()){
            res.push_back({it->shop, it->movie});
            counter++;
            it = next(it);
        }

        return res;
    }

    long long int getId(int shop, int movie){
        return (((long long int) shop) << 32) + ((long long int) movie);
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */