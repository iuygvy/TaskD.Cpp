//Bartosz Bugajski
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"
#include <iostream>

BRANCH_CLASS::BRANCH_CLASS()
{
    prev = NULL;
    next = NULL;
    weight = 0;
    length = 0;
    amount = 0;
    first = NULL;
    last = NULL;
    height = 0;
    parent = NULL;
}


BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS& tocopybr, TREE_CLASS* par, BRANCH_CLASS* p, BRANCH_CLASS* n, unsigned int h)
{
    length = tocopybr.length;
    weight = tocopybr.weight;
    amount = tocopybr.amount;
    parent = par;
    if(h != 0 && parent != NULL)
    {
        parent->setFruitAmount(parent->getFruitsTotal() + amount);
        parent->setWeight(parent->getWeightsTotal() + weight);
    }
    if(h == 0)
    {
        height = tocopybr.height;
        prev = NULL;
        next = NULL;
    }
    else
    {
        height = h;
        prev = p;
        next = n;
    }
    first = NULL;
    last = NULL;
    FRUIT_CLASS* cur = tocopybr.first;
    for(unsigned int k = 0; k < amount; k++)
    {
        FRUIT_CLASS* newfruit = new FRUIT_CLASS(*cur, this);
        newfruit->addLast(&first, &last);
        cur = cur->getNext();
    }
}

BRANCH_CLASS::~BRANCH_CLASS()
{
    cutBranch(0);
}

void BRANCH_CLASS::addLast(BRANCH_CLASS** f, BRANCH_CLASS** l)
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

void BRANCH_CLASS::removeCur(BRANCH_CLASS** f, BRANCH_CLASS** l)
{
    if(*f!=NULL)
    {
        BRANCH_CLASS* toremove = this;
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
        cutBranch(0);
        delete toremove;
    }
}

void BRANCH_CLASS::setHeight(unsigned int h)
{
    height = h;
}

void BRANCH_CLASS::setParent(TREE_CLASS* tree)
{
    parent = tree;
}

/////////////////////////
unsigned int BRANCH_CLASS::getFruitsTotal()
{
    return amount;
}
unsigned int BRANCH_CLASS::getWeightsTotal()
{
    return weight;
}
unsigned int BRANCH_CLASS::getHeight()
{
    return height;
}
unsigned int BRANCH_CLASS::getLength()
{
    return length;
}
void BRANCH_CLASS::growthBranch()
{
    length++;
    FRUIT_CLASS* fruit = first;
    while(fruit != NULL)
    {
        fruit->growthFruit();
        fruit = fruit->getNext();
    }
    if(length % 2 == 0)
    {
        FRUIT_CLASS* newfruit = new FRUIT_CLASS;
        newfruit->addLast(&first, &last);
        newfruit->setLength(length);
        newfruit->setParent(this);
        setAmount(amount+1);
    }
}
void BRANCH_CLASS::fadeBranch()
{
    if(length>0)
    {
        length--;
        FRUIT_CLASS* fruit = first;
        while(fruit != NULL)
        {
            fruit->fadeFruit();
            fruit = fruit->getNext();
        }
        if(length % 2 == 1)
        {
            last->pluckFruit();
            setAmount(amount-1);
            last->removeCur(&first, &last);
        }
    }
}

void BRANCH_CLASS::harvestBranch(unsigned int w)
{
    FRUIT_CLASS* fruit = first;
    while(fruit != NULL)
    {
        if(fruit->getWeight() >= w)
        {
            fruit->pluckFruit();
        }
        fruit = fruit->getNext();
    }
}

void BRANCH_CLASS::cutBranch(unsigned int l)
{
    while(length > l)
    {
        length--;
        if(length % 2 == 1)
        {
            last->pluckFruit();
            setAmount(amount-1);
            last->removeCur(&first, &last);
        }
    }
}

FRUIT_CLASS* BRANCH_CLASS::getFruitPointer(unsigned int l)
{
    FRUIT_CLASS* fruit = first;
    while(fruit != NULL && fruit->getLength() <= l)
    {
        if(fruit->getLength() == l)
        {
            return fruit;
        }
        fruit = fruit->getNext();
    }
    return NULL;
}
////////////////////////////////////

TREE_CLASS* BRANCH_CLASS::getTreePointer()
{
    return parent;
}

void BRANCH_CLASS::setWeight(unsigned int w)
{
    long long diff = w - weight;
    weight = w;
    if(parent != NULL)
    {
        parent->setWeight(parent->getWeightsTotal() + diff);
    }
}

void BRANCH_CLASS::setAmount(unsigned int a)
{
    long long diff = a - amount;
    amount = a;
    if(parent != NULL)
    {
        parent->setFruitAmount(parent->getFruitsTotal() + diff);
    }
}

BRANCH_CLASS* BRANCH_CLASS::getNext()
{
    return next;
}

BRANCH_CLASS* BRANCH_CLASS::getPrev()
{
    return prev;
}

void BRANCH_CLASS::setNext(BRANCH_CLASS* br)
{
    next = br;
}

void BRANCH_CLASS::setPrev(BRANCH_CLASS* br)
{
    prev = br;
}