//Bartosz Bugajski
class TREE_CLASS;

class GARDEN_CLASS
{
private:
    unsigned int treeamount;
    unsigned int branchamount;
    unsigned int fruitamount;
    unsigned int weight;
    unsigned int hole;

    TREE_CLASS* first;
    TREE_CLASS* last;

public:
    void setWeight(unsigned int);
    void setFruitAmount(unsigned int);
    void setBranchAmount(unsigned int);
    void setTreeAmount(unsigned int);
    GARDEN_CLASS();
    ~GARDEN_CLASS();
    void display();
    unsigned int getMinID();

    unsigned int getTreesTotal();
    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    void plantTree();
    void extractTree(unsigned int);
    void growthGarden();
    void fadeGarden();
    void harvestGarden(unsigned int);
    TREE_CLASS* getTreePointer(unsigned int);
    void cloneTree(unsigned int);
};