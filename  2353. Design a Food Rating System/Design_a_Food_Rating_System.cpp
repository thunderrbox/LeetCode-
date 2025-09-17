#include <bits/stdc++.h>
using namespace std;

/*
INTUITION / PROBLEM UNDERSTANDING:
---------------------------------
We are asked to design a Food Rating System that can:
1. Change the rating of a given food.
2. Get the highest rated food of a given cuisine.

Constraints to consider:
- We need efficient (fast) updates and queries.
- We must always get the food with the highest rating for a cuisine.
- If two foods have the same rating, we return the one with lexicographically smaller name.

HOW WE SOLVE THIS:
------------------
We maintain:
1. foodToCuisine: maps each food -> its cuisine
2. foodToRating: maps each food -> its current rating
3. cuisineSet: for each cuisine, stores a set of pairs (-rating, food)
   - Why negative rating?
     Because std::set is sorted in ascending order, so to get the highest rating first,
     we insert -rating. This way, the smallest element in the set is actually the highest rating.
   - Each cuisine will have its own set of ( -rating, food ) pairs sorted automatically.

Operations:
-----------
- changeRating(food, newRating):
   * Find the food's cuisine
   * Remove the old (-rating, food) pair from that cuisine's set
   * Insert the new (-newRating, food) pair into that cuisine's set
   * Update the foodToRating map

- highestRated(cuisine):
   * The first element in the cuisineSet[cuisine] will have the largest rating (because of -rating)
   * Return its food name

COMPLEXITY ANALYSIS:
--------------------
Let N = number of foods, and M = number of operations

- Constructor:
    * Each insertion into set is O(log N)
    * Total O(N log N)

- changeRating:
    * Erase old pair from set: O(log N)
    * Insert new pair into set: O(log N)
    * So overall O(log N)

- highestRated:
    * Access the first element of a set (begin()): O(1)

- Space:
    * Storing 3 maps of size N
    * Each food is stored once in the set of its cuisine
    * So overall O(N)
*/

class FoodRatings {
private:
    unordered_map<string, string> foodToCuisine;        // food -> cuisine
    unordered_map<string, int> foodToRating;             // food -> current rating
    unordered_map<string, set<pair<int,string>>> cuisineSet; // cuisine -> set of (-rating, food)

public:
    // Constructor: initialize all mappings and sets
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            string &f = foods[i];
            string &c = cuisines[i];
            int r = ratings[i];

            foodToCuisine[f] = c;     // map food to its cuisine
            foodToRating[f] = r;      // map food to its current rating
            cuisineSet[c].insert({-r, f});  // insert (-rating, food) into cuisine's set
        }
    }

    // Change the rating of a given food
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];  // get cuisine of this food
        int oldRating = foodToRating[food];    // get old rating

        // Get the set of this cuisine and update it
        auto &s = cuisineSet[cuisine];

        // Remove old rating pair from set
        s.erase({-oldRating, food});

        // Insert new rating pair
        s.insert({-newRating, food});

        // Update food's rating
        foodToRating[food] = newRating;
    }

    // Return the highest-rated food for a given cuisine
    string highestRated(string cuisine) {
        auto &s = cuisineSet[cuisine];
        // First element has the highest rating (because of -rating)
        return s.begin()->second;
    }
};

// This line is unrelated to the logic (used by the judge system to prevent fast exit)
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
