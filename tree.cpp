//Bartosz Bugajski
#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"
#include <iostream>

TREE_CLASS::TREE_CLASS()
{
    prev = NULL;
    next = NULL;
    id = 0;
    height = 0;
    first = NULL;
    last = NULL;
    weight = 0;
    branchamount = 0;
    fruitamount = 0;
    parent = NULL;
}

TREE_CLASS::TREE_CLASS(const TREE_CLASS& tocopytr, GARDEN_CLASS* par, unsigned int i)
{
    prev = NULL;
    next = NULL;
    parent = par;
    id = i;
    height = tocopytr.height;
    first = NULL;
    last = NULL;
    weight = tocopytr.weight;
    branchamount = tocopytr.branchamount;
    fruitamount = tocopytr.fruitamount;

    BRANCH_CLASS* cur = tocopytr.first;
    for(unsigned int n = 0; n < branchamount; n++)
    {
        BRANCH_CLASS* newbranch = new BRANCH_CLASS(*cur, this);
        newbranch->addLast(&first, &last);
        cur = cur->getNext();
    }
    if(parent != NULL)
    {
        parent->setWeight(parent->getWeightsTotal() + weight);
        parent->setFruitAmount(parent->getFruitsTotal() + fruitamount);
        parent->setBranchAmount(parent->getBranchesTotal() + branchamount);
        parent->setTreeAmount(parent->getTreesTotal() + 1);
    }
}

TREE_CLASS::~TREE_CLASS()
{
    cutTree(0);
}

void TREE_CLASS::setParent(GARDEN_CLASS* gr)
{
    parent = gr;
}

void TREE_CLASS::setId(unsigned int i)
{
    id = i;
}

unsigned int TREE_CLASS::getBranchesTotal()
{
    return branchamount;
}

unsigned int TREE_CLASS::getFruitsTotal()
{
    return fruitamount;
}

unsigned int TREE_CLASS::getWeightsTotal()
{
    return weight;
}

unsigned int TREE_CLASS::getNumber()
{
    return id;
}

unsigned int TREE_CLASS::getHeight()
{
    return height;
}

void TREE_CLASS::growthTree()
{
    height++;
    BRANCH_CLASS* branch = first;
    while(branch != NULL)
    {
        branch->growthBranch();
        branch = branch->getNext();
    }
    if(height % 3 == 0)
    {
        BRANCH_CLASS* newbranch = new BRANCH_CLASS;
        newbranch->addLast(&first, &last);
        newbranch->setHeight(height);
        newbranch->setParent(this);
        setBranchAmount(branchamount+1);
    }
}

void TREE_CLASS::fadeTree()
{
    if(height > 0)
    {
        height--;
        BRANCH_CLASS* branch = first;
        while(branch != NULL)
        {
            branch->fadeBranch();
            branch = branch->getNext();
        }
        if(height % 3 == 2)
        {
            setBranchAmount(branchamount-1);
            last->removeCur(&first, &last);
        }
    }
}

void TREE_CLASS::harvestTree(unsigned int w)
{
    BRANCH_CLASS* branch = first;
    while(branch != NULL)
    {
        branch->harvestBranch(w);
        branch = branch->getNext();
    }
}

void TREE_CLASS::cutTree(unsigned int h)
{
    while(height > h)
    {
        height--;
        if(height % 3 == 2)
        {
            setBranchAmount(branchamount-1);
            last->removeCur(&first, &last);
        }
    }
}

void TREE_CLASS::cloneBranch(BRANCH_CLASS* newbranch)
{
    BRANCH_CLASS* branch = first;
    while(branch != NULL && branch->getLength() != 0)
    {
        branch = branch->getNext();
    }
    if(branch == NULL) return;
    BRANCH_CLASS* temp = branch;
    BRANCH_CLASS* brprev = branch->getPrev();
    BRANCH_CLASS* brnext = branch->getNext();
    branch = new BRANCH_CLASS(*newbranch, this, brprev, brnext, branch->getHeight());
    if(brprev != NULL)
    {
        brprev->setNext(branch);
    }
    if(brnext != NULL)
    {
        brnext->setPrev(branch);
    }
    if(temp == last)
    {
        last = branch;
    }
    if(temp == first)
    {
        first = branch;
    }
    delete temp;
}

GARDEN_CLASS* TREE_CLASS::getGardenPointer()
{
    return parent;
}

BRANCH_CLASS* TREE_CLASS::getBranchPointer(unsigned int h)
{
    BRANCH_CLASS* branch = first;
    while(branch != NULL)
    {
        if(branch->getHeight() == h)
        {
            return branch;
        }
        branch = branch->getNext();
    }
    return NULL;
}

void TREE_CLASS::setWeight(unsigned int w)
{
    long long diff = w - weight;
    weight = w;
    if(parent != NULL)
    {
        parent->setWeight(parent->getWeightsTotal() + diff);
    }
}

void TREE_CLASS::setFruitAmount(unsigned int a)
{
    long long diff = a - fruitamount;
    fruitamount = a;
    if(parent != NULL)
    {
        parent->setFruitAmount(parent->getFruitsTotal() + diff);
    }
}

void TREE_CLASS::setBranchAmount(unsigned int a)
{
    long long diff = a - branchamount;
    branchamount = a;
    if(parent != NULL)
    {
        parent->setBranchAmount(parent->getBranchesTotal() + diff);
    }
}

void TREE_CLASS::addLast(TREE_CLASS** f, TREE_CLASS** l)
{
    if(*f==NULL)
    {
        *f = this;
        *l = this;
    }
    else
    {
        (*l)->next = this;
        prev = (*l);
        *l = this;
    }
}

TREE_CLASS* TREE_CLASS::getNext()
{
    return next;
}

TREE_CLASS* TREE_CLASS::getPrev()
{
    return prev;
}

void TREE_CLASS::removeCur(TREE_CLASS** f, TREE_CLASS** l)
{
    if(*f!=NULL)
    {
        TREE_CLASS* toremove = this;
        if(this == *f)
        {
            *f = (*f)->next;
            if(*f != NULL)
            {
                (*f)->prev = NULL;
            }
        }
        else
        {
            prev->next = next;
        }
        if(this == *l)
        {
            *l = (*l)->prev;
            if(*l != NULL)
            {
                (*l)->next = NULL;
            }
        }
        else
        {
            next->prev = prev;
        }
        cutTree(0);
        delete toremove;
    }
}