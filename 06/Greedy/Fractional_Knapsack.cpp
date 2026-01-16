#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
};

// Comparator: Sorts items by value-per-weight ratio (descending)
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main() {
    int capacity = 50;
    
    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    // Sort items to prioritize higher value density
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const auto& item : items) {
        
        // Case 1: Item fits completely
        if (currentWeight + item.weight <= capacity) {
            currentWeight += item.weight;
            totalValue += item.value;
        } 
        // Case 2: Item fits partially (Fractional take)
        else {
            int remaining = capacity - currentWeight;
            totalValue += item.value * ((double)remaining / item.weight);
            break; // Capacity exhausted
        }
    }

    cout << "Maximum value in Knapsack = " << totalValue << endl;

    return 0;
}
