//Bartosz Bugajski
#include "branch.hpp"
#include "fruit.hpp"
#include <iostream>

FRUIT_CLASS::FRUIT_CLASS()
{
    prev = NULL;
    next = NULL;
    weight = 0;
    length = 0;
    parent = NULL;
}

FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS& tocopyfr, BRANCH_CLASS* par)
{
    prev = NULL;
    next = NULL;
    weight = tocopyfr.weight;
    length = tocopyfr.length;
    parent = par;
}

void FRUIT_CLASS::setLength(unsigned int l)
{
    length = l;
}

void FRUIT_CLASS::addLast(FRUIT_CLASS** first, FRUIT_CLASS** last)
{
    if(*first==NULL)
    {
        *first = this;
        *last = this;
    }
    else
    {
        (*last)->next = this;
        prev = (*last);
        *last = this;
    }
}

void FRUIT_CLASS::removeCur(FRUIT_CLASS** first, FRUIT_CLASS** last)
{
    if(*first!=NULL)
    {
        FRUIT_CLASS* toremove = this;
        if(this == *first)
        {
            *first = (*first)->next;
            if(*first != NULL)
            {
                (*first)->prev = NULL;
            }
        }
        else
        {
            prev->next = next;
        }
        if(this == *last)
        {
            *last = (*last)->prev;
            if(*last != NULL)
            {
                (*last)->next = NULL;
            }
        }
        else
        {
            next->prev = prev;
        }
        delete toremove;
    }
}

/////////////////////////////////////////
unsigned int FRUIT_CLASS::getLength()
{
    return length;
}
unsigned int FRUIT_CLASS::getWeight()
{
    return weight;
}
void FRUIT_CLASS::growthFruit()
{
    if(parent != NULL)
    {
        parent->setWeight(parent->getWeightsTotal() + 1);
    }
    weight++;
}
void FRUIT_CLASS::fadeFruit()
{
    if(weight>0)
    {
        if(parent != NULL)
        {
            parent->setWeight(parent->getWeightsTotal() - 1);
        }
        weight--;
    }
}
void FRUIT_CLASS::pluckFruit()
{
    if(parent != NULL)
    {
        parent->setWeight(parent->getWeightsTotal() - weight);
    }
    weight = 0;
}

BRANCH_CLASS* FRUIT_CLASS::getBranchPointer()
{
    return parent;
}
//////////////////////////////////////////

FRUIT_CLASS* FRUIT_CLASS::getNext()
{
    return next;
}

void FRUIT_CLASS::setParent(BRANCH_CLASS* br)
{
    parent = br;
}
