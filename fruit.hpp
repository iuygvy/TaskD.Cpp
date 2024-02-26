//Bartosz Bugajski
#include <iostream>
class BRANCH_CLASS;

class FRUIT_CLASS
{
private:
    FRUIT_CLASS* prev;
    FRUIT_CLASS* next;
    unsigned int weight;
    unsigned int length;
    BRANCH_CLASS* parent;

public:
    FRUIT_CLASS();
    FRUIT_CLASS(const FRUIT_CLASS&, BRANCH_CLASS* = NULL);
    void setLength(unsigned int);
    void addLast(FRUIT_CLASS**, FRUIT_CLASS**);
    void removeCur(FRUIT_CLASS**, FRUIT_CLASS**);

    unsigned int getLength();
    unsigned int getWeight();
    void growthFruit();
    void fadeFruit();
    void pluckFruit();
    BRANCH_CLASS* getBranchPointer();

    FRUIT_CLASS* getNext();
    void setParent(BRANCH_CLASS*);
    void display();
};