#include <iostream>
#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"
using namespace std;

void GARDEN_CLASS::display() {
    TREE_CLASS* tree;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int quantity = (*this).getTreesTotal();

    printf("GARDEN:\n");
    printf("    Number of Trees: %u\n", quantity);
    printf("    Number of Branches: %u\n", (*this).getBranchesTotal());
    printf("    Number of Fruits: %u\n", (*this).getFruitsTotal());
    printf("    Total Weight: %u\n", (*this).getWeightsTotal());
    printf("    All Trees:\n");

    while (i < quantity) {
        tree = (*this).getTreePointer(j);
        if (tree != NULL) {
            (*tree).display();
            i += 1;
        }
        j += 1;
    }
    printf("    Successful Display all of %u Trees\n", quantity);
}

void TREE_CLASS::display() {
    GARDEN_CLASS* garden = (*this).getGardenPointer();
    BRANCH_CLASS* branch;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int quantity = (*this).getBranchesTotal();

    printf("    Tree number %u:\n", (*this).getNumber());
    printf("        Height of a Tree: %u\n", (*this).getHeight());
    printf("        Number of Branches: %u\n", quantity);
    printf("        Number of Fruits: %u\n", (*this).getFruitsTotal());
    printf("        Total Weight: %u\n", (*this).getWeightsTotal());
    printf("        All Branches:\n");

    while (i < quantity) {
        branch = (*this).getBranchPointer(3 * j);
        if (branch != NULL) {
            (*branch).display();
            i += 1;
        }
        j += 1;
    }
    printf("        Successful Display all of %u Branches\n", quantity);
}

void BRANCH_CLASS::display() {
    TREE_CLASS* tree = (*this).getTreePointer();
    FRUIT_CLASS* fruit;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int quantity = (*this).getFruitsTotal();

    printf("        Branch at the height of %u\n", (*this).getHeight());
    printf("            Length of a Branch: %u\n", (*this).getLength());
    printf("            Number of Fruits: %u\n", quantity);
    printf("            Total Weight: %u\n", (*this).getWeightsTotal());
    printf("            All Fruits:\n");

    while (i < quantity) {
        fruit = (*this).getFruitPointer(j << 1);
        if (fruit != NULL) {
            (*fruit).display();
            i += 1;
        }
        j += 1;
    }
    printf("            Successful Display all of %u Fruits\n", quantity);
}

void FRUIT_CLASS::display() {
    printf("            Fruit at the length of %u\n", (*this).getLength());
    printf("                Weight: %u\n", (*this).getWeight());
}

int main()
{
    GARDEN_CLASS* garden = new GARDEN_CLASS;
    garden->plantTree();
    garden->growthGarden();garden->growthGarden();garden->growthGarden();
    garden->growthGarden();garden->growthGarden();garden->growthGarden();
    garden->growthGarden();garden->growthGarden();garden->growthGarden();
    TREE_CLASS* tr = garden->getTreePointer(0);
    BRANCH_CLASS* br = tr->getBranchPointer(3);
    tr->cloneBranch(br);
    //garden->display();
    /*
    string ins;
    cin >> ins;
    while(ins != "exit")
    {
        if(ins == "plant")
        {
            garden->plantTree();
        }
        else if(ins == "extract")
        {
            unsigned int i;
            cin >> i;
            garden->extractTree(i);
        }
        else if(ins == "grow")
        {
            garden->growthGarden();
        }
        else if(ins == "fade")
        {
            garden->fadeGarden();
        }
        else if(ins == "harvest")
        {
            unsigned int w;
            cin >> w;
            garden->harvestGarden(w);
        }
        else if(ins == "clone")
        {
            unsigned int i;
            cin >> i;
            garden->cloneTree(i);
        }
        else if(ins == "display")
        {
            garden->display();
        }
        cout << garden->getTreesTotal() << ' ' << garden->getBranchesTotal()
        << ' ' << garden->getFruitsTotal() << ' ' << garden->getWeightsTotal() << '\n';
        cin >> ins;
    }
    */
}
