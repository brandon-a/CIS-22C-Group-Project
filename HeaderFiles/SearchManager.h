// Search Manager Header File for Team Project
// Ahmed Shalan

#ifndef _SEARCH_MANAGER
#define _SEARCH_MANAGER


#include <iostream>
#include <string>
using namespace std;

template<class ItemType>
class SearchManager
{
private:
    bool found;
    int key;
    string name;
    ItemType tempFoodItem;
    ItemType searchedFoodItem;
public:
    SearchManager(){found = false; key = 0; name = "";}
    void PrimaryKeySearchManager(BinarySearchTree<ItemType> * primaryTree, BinarySearchTree<ItemType> * secondaryTree);
    void SecondaryKeySearchManager(BinarySearchTree<ItemType> * primaryTree, BinarySearchTree<ItemType> * secondaryTree);
};


///////////////////////// public function definitions ///////////////////////////
template<class ItemType>
void SearchManager<ItemType>::PrimaryKeySearchManager(BinarySearchTree<ItemType> * primaryTree, BinarySearchTree<ItemType> * secondaryTree)
{
    //Have the user enter the ID number
    cout << "Please enter the USDA identification number: ";
    cin >> key;
    
    //Set the temporary Food object's ID to the entered ID
    tempFoodItem.setNDBNumber(key);
    
    //Check if the Food is in the tree
    found = primaryTree->getEntry(tempFoodItem, searchedFoodItem);
    
    //Display the item if it's found
    if(found)
        searchedFoodItem.displayFoodData();
    else
        cout << key << " was not found in the USDA Nutritional Database.\n";
}

template<class ItemType>
void SearchManager<ItemType>::SecondaryKeySearchManager(BinarySearchTree<ItemType> * primaryTree, BinarySearchTree<ItemType> * secondaryTree)
{
    //Have the user enter the name
    cout << "Please enter the name of the food as listed in the USDA database: ";
    cin >> name;
    
    //Set the temporary Food object's ID to the entered ID
    tempFoodItem.setFoodName(name);
    
    //Check if the Food is in the tree
    found = secondaryTree->getEntry(tempFoodItem, searchedFoodItem);
    
    //Display the item if it's found
    if(found)
        searchedFoodItem.displayFoodData();
    else
        cout << name << " was not found in the USDA Nutritional Database.\n";
}

#endif