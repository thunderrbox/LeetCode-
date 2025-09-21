class MovieRentingSystem {
public:
    // For each movie, store available shops in sorted order by {price, shop}.
    // This helps in "search" queries to quickly get the cheapest shops.
    unordered_map<int, set<pair<int, int>>> available;

    // For each movie, map shop -> price (for quick lookup).
    unordered_map<int, unordered_map<int, int>> movies;

    // Globally store all rented movies as {price, shop, movie}, 
    // sorted by price, then shop, then movie.
    // This helps in "report" queries.
    set<tuple<int, int, int>> rented;

    // Constructor: populate data structures with initial entries.
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            available[movie].insert({price, shop});
            movies[movie][shop] = price;
        }
    }

    // Return up to 5 shops offering "movie" at the lowest price.
    // If prices are equal, smaller shop ID is preferred.
    vector<int> search(int movie) {
        vector<int> result;
        if (available.count(movie)) {
            int cnt = 0;
            for (auto& [price, shop] : available[movie]) {
                result.push_back(shop);
                if (++cnt == 5) break; // only need top 5
            }
        }
        return result;
    }

    // Rent a movie from a shop:
    // 1. Remove it from available list.
    // 2. Add it to rented list.
    void rent(int shop, int movie) {
        int price = movies[movie][shop];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    // Drop (return) a rented movie:
    // 1. Add it back to available list.
    // 2. Remove it from rented list.
    void drop(int shop, int movie) {
        int price = movies[movie][shop];
        available[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    // Return up to 5 rented movies globally, 
    // sorted by {price, shop, movie}.
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int cnt = 0;
        for (auto& [price, shop, movie] : rented) {
            ans.push_back({shop, movie});
            if (++cnt == 5) break; // only need top 5
        }
        return ans;
    }
};
