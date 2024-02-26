//Bartosz Bugajski
#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"
#include <iostream>

GARDEN_CLASS::GARDEN_CLASS()
{
    treeamount = 0;
    branchamount = 0;
    fruitamount = 0;
    weight = 0;
    first = NULL;
    last = NULL;
    hole = 0;
}

GARDEN_CLASS::~GARDEN_CLASS()
{
    TREE_CLASS* cur = first;
    while(cur != NULL)
    {
        TREE_CLASS* n = cur->getNext();
        cur->cutTree(0);
        cur->removeCur(&first, &last);
        cur = n;
    }
}

void GARDEN_CLASS::setWeight(unsigned int w)
{
    weight = w;
}

void GARDEN_CLASS::setFruitAmount(unsigned int a)
{
    fruitamount = a;
}

void GARDEN_CLASS::setBranchAmount(unsigned int a)
{
    branchamount = a;
}

void GARDEN_CLASS::setTreeAmount(unsigned int a)
{
    treeamount = a;
}

unsigned int GARDEN_CLASS::getTreesTotal()
{
    return treeamount;
}

unsigned int GARDEN_CLASS::getBranchesTotal()
{
    return branchamount;
}

unsigned int GARDEN_CLASS::getFruitsTotal()
{
    return fruitamount;
}

unsigned int GARDEN_CLASS::getWeightsTotal()
{
    return weight;
}

void GARDEN_CLASS::plantTree()
{
    TREE_CLASS* newtree = new TREE_CLASS;
    unsigned int minid = getMinID();
    newtree->addLast(&first, &last);
    newtree->setId(minid);
    newtree->setParent(this);
    treeamount++;
}

unsigned int GARDEN_CLASS::getMinID()
{

    if(hole != 0)
    {
        unsigned int minid = 0;
        while(true)
        {
            bool isok = true;
            TREE_CLASS* cur = first;
            while(cur != NULL)
            {
                if(cur->getNumber() == minid)
                {
                    isok = false;
                    break;
                }
                cur = cur->getNext();
            }
            if(isok)
            {
                break;
            }
            minid++;
        }
        hole--;
        return minid;
    }
    return treeamount;
}

void GARDEN_CLASS::extractTree(unsigned int i)
{
    TREE_CLASS* cur = last;
    while(cur != NULL && cur->getNumber() != i)
    {
        cur = cur->getPrev();
    }
    if(cur == NULL) return;
    if(cur != last)
    {
        hole++;
    }
    treeamount--;
    cur->removeCur(&first, &last);
}

void GARDEN_CLASS::growthGarden()
{
    TREE_CLASS* cur = first;
    while(cur != NULL)
    {
        cur->growthTree();
        cur = cur->getNext();
    }
}

void GARDEN_CLASS::fadeGarden()
{
    TREE_CLASS* cur = first;
    while(cur != NULL)
    {
        cur->fadeTree();
        cur = cur->getNext();
    }
}

void GARDEN_CLASS::harvestGarden(unsigned int w)
{
    TREE_CLASS* cur = first;
    while(cur != NULL)
    {
        cur->harvestTree(w);
        cur = cur->getNext();
    }
}

TREE_CLASS* GARDEN_CLASS::getTreePointer(unsigned int i)
{
    TREE_CLASS* cur = first;
    while(cur != NULL)
    {
        if(cur->getNumber() == i)
        {
            return cur;
        }
        cur = cur->getNext();
    }
    return NULL;
}

void GARDEN_CLASS::cloneTree(unsigned int i)
{
    TREE_CLASS* cur = first;
    while(cur != NULL && cur->getNumber() != i)
    {
        cur = cur->getNext();
    }
    if(cur == NULL) return;
    TREE_CLASS* newtree = new TREE_CLASS(*cur, this, getMinID());
    newtree->addLast(&first, &last);
}