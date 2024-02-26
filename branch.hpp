//Bartosz Bugajski
#include <iostream>
class FRUIT_CLASS;
class TREE_CLASS;

class BRANCH_CLASS
{
public:
    BRANCH_CLASS();
    ~BRANCH_CLASS();
    BRANCH_CLASS(const BRANCH_CLASS&, TREE_CLASS* = NULL, BRANCH_CLASS* = NULL, BRANCH_CLASS* = NULL, unsigned int = 0);
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    unsigned int getHeight();
    unsigned int getLength();
    void growthBranch();
    void fadeBranch();
    void harvestBranch(unsigned int);
    void cutBranch(unsigned int);
    FRUIT_CLASS* getFruitPointer(unsigned int);
    TREE_CLASS* getTreePointer();

    void setNext(BRANCH_CLASS*);
    void setPrev(BRANCH_CLASS*);
    void setHeight(unsigned int h);
    void setParent(TREE_CLASS*);
    void setAmount(unsigned int);
    void setWeight(unsigned int);
    BRANCH_CLASS* getNext();
    BRANCH_CLASS* getPrev();
    void addLast(BRANCH_CLASS**, BRANCH_CLASS**);
    void removeCur(BRANCH_CLASS**, BRANCH_CLASS**);
    void display();

private:
    BRANCH_CLASS* prev;
    BRANCH_CLASS* next;
    unsigned int length;
    unsigned int height;
    TREE_CLASS* parent;

    //informacje o owocach
    FRUIT_CLASS* first;
    FRUIT_CLASS* last;
    unsigned int weight;
    unsigned int amount;
};