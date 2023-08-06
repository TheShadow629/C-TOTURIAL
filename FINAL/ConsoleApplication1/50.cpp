//Here's an example implementation in C++ for each of the set operations:

#include <iostream>
#include <unordered_set>

// Insertion
void insertElement(std::unordered_set<int>&mySet, int element) {
    mySet.insert(element);
}

// Deletion
void deleteElement(std::unordered_set<int>& mySet, int element) {
    mySet.erase(element);
}

// Membership Test
bool isElementExists(const std::unordered_set<int>& mySet, int element) {
    return mySet.count(element) > 0;
}

// Union
std::unordered_set<int> setUnion(const std::unordered_set<int>& set1, const std::unordered_set<int>& set2) {
    std::unordered_set<int> result = set1;
    result.insert(set2.begin(), set2.end());
    return result;
}

// Intersection
std::unordered_set<int> setIntersection(const std::unordered_set<int>& set1, const std::unordered_set<int>& set2) {
    std::unordered_set<int> result;
    for (const auto& element : set1) {
        if (set2.count(element) > 0) {
            result.insert(element);
        }
    }
    return result;
}

// Difference
std::unordered_set<int> setDifference(const std::unordered_set<int>& set1, const std::unordered_set<int>& set2) {
    std::unordered_set<int> result = set1;
    for (const auto& element : set2) {
        result.erase(element);
    }
    return result;
}

int main() {
    std::unordered_set<int> set1 = { 1, 2, 3, 4, 5 };
    std::unordered_set<int> set2 = { 4, 5, 6, 7, 8 };

    // Insertion
    insertElement(set1, 6);
    std::cout << "Set after insertion: ";
    for (const auto& element : set1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Deletion
    deleteElement(set1, 2);
    std::cout << "Set after deletion: ";
    for (const auto& element : set1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Membership Test
    int element = 3;
    bool exists = isElementExists(set1, element);
    std::cout << "Element " << element << " exists in set: " << std::boolalpha << exists << std::endl;

    // Union
    std::unordered_set<int> unionSet = setUnion(set1, set2);
    std::cout << "Union Set: ";
    for (const auto& element : unionSet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Intersection
    std::unordered_set<int> intersectionSet = setIntersection(set1, set2);
    std::cout << "Intersection Set: ";
    for (const auto& element : intersectionSet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Difference
    std::unordered_set<int> differenceSet = setDifference(set1, set2);
    std::cout << "Difference Set: ";
    for (const auto& element : differenceSet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}

//This code demonstrates the usage of each set operation using an `unordered_set` container provided by the C++ Standard Library.
