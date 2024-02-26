//Bartosz Bugajski
#include <iostream>
class BRANCH_CLASS;
class GARDEN_CLASS;

class TREE_CLASS
{
private:
    unsigned int id;
    unsigned int height;
    GARDEN_CLASS* parent;
    TREE_CLASS* next;
    TREE_CLASS* prev;

    BRANCH_CLASS* first;
    BRANCH_CLASS* last;
    unsigned int weight;
    unsigned int branchamount;
    unsigned int fruitamount;

public:
    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    unsigned int getNumber();
    unsigned int getHeight();
    void growthTree();
    void fadeTree();
    void harvestTree(unsigned int);
    void cutTree(unsigned int);
    void cloneBranch(BRANCH_CLASS*);
    GARDEN_CLASS* getGardenPointer();
    BRANCH_CLASS* getBranchPointer(unsigned int );

    TREE_CLASS();
    ~TREE_CLASS();
    TREE_CLASS(const TREE_CLASS&, GARDEN_CLASS* = NULL, unsigned int = 0);
    void setParent(GARDEN_CLASS*);
    void setId(unsigned int);
    TREE_CLASS* getNext();
    TREE_CLASS* getPrev();
    void setWeight(unsigned int);
    void setFruitAmount(unsigned int);
    void setBranchAmount(unsigned int);
    void addLast(TREE_CLASS**, TREE_CLASS**);
    void removeCur(TREE_CLASS**, TREE_CLASS**);
    void display();
};