#include <vector>
#include <string>

#include <set>
#include <unordered_map>
#include <tuple>

using namespace std;

class CompareFoodGreater{
public:
    bool operator() (const tuple<int, std::string> &a, const tuple<int, std::string> &b) const{
        if (get<0>(a) > get<0>(b)){
            return true;
        }
        else if (get<0>(a) < get<0>(b)){
            return false;
        }
        else {
            return get<1>(a).compare(get<1>(b)) < 0;
        }
        // Higher rating and lower lexicographic porering!
    }
};

class FoodRatings {
public:
    unordered_map<string, tuple<int, string>>       food_info_map;                       // maps food_name -> rating, cuisine
    unordered_map<string, set<tuple<int, std::string>, CompareFoodGreater>>  food_rating_map; // maps cuisine -> set of ratings and names (ordered, first element is best)
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        string current_food;
        string current_cuisine;
        int current_rating;
        for (int i = 0; i < foods.size(); i++){
            current_food = foods[i];
            current_cuisine = cuisines[i];
            current_rating = ratings[i];
            this->food_info_map.insert({current_food, {current_rating, current_cuisine}});

            if (food_rating_map.find(current_cuisine) == food_rating_map.end()){    // Create set of cuisine if it doesnt exist
                food_rating_map.insert({current_cuisine, {{current_rating, current_food}}});
            }
            else{   // Or insert if it exists
                food_rating_map.find(current_cuisine)->second.insert({current_rating, current_food});
            }
        }
    }
    
    void changeRating(string food, int newRating) {
        auto food_info_reference = this->food_info_map.find(food);
        tuple<int, string> current_food_info = food_info_reference->second;

        auto cuisine_set = food_rating_map.find(get<1>(current_food_info));
        cuisine_set->second.erase({get<0>(current_food_info), food});
        cuisine_set->second.insert({newRating, food});

        food_info_reference->second = {newRating, get<1>(current_food_info)};

    }
    
    string highestRated(string cuisine) {
        return get<1>(*(this->food_rating_map.find(cuisine)->second.begin()));
    }
};

int main(){
    vector<string> foods = {"kimchi","miso","sushi","moussaka","ramen","bulgogi"};
    vector<string> cuisines = {"korean","japanese","japanese","greek","japanese","korean"};
    vector<int> ratings = {9,12,8,15,14,7};
    FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);

}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */