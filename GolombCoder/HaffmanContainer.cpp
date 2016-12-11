//
//  HaffmanContainer.cpp
//  GolombCoder
//
//  Created by MacBook on 02.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#include "HaffmanContainer.hpp"

void CHaffmanContainer::setValues(std::map<int, int> mapValues)
{
    for(std::map<int, int>::iterator it = mapValues.begin(); it != mapValues.end(); ++it)
    {
        addValue(*it);
    }
}

void CHaffmanContainer::addValue(std::pair<int, int> pairValueFraq)
{
    CHaffmanElement elem;
    elem.m_iValue = pairValueFraq.first;
    elem.m_iCount = pairValueFraq.second;
    
    m_mmData.insert(std::make_pair(pairValueFraq.second, elem));
}

void CHaffmanContainer::processTree()
{
    while(m_mmData.size() != 2)
    {
        CHaffmanElement first = m_mmData.begin()->second;
        m_mmData.erase(m_mmData.begin());
                       
        CHaffmanElement second = m_mmData.begin()->second;
        m_mmData.erase(m_mmData.begin());
        
        CHaffmanElement newElement;
        newElement.m_iCount = first.m_iCount + second.m_iCount;
        
        newElement.m_pLeft.reset(new CHaffmanElement(first));
        newElement.m_pRight.reset(new CHaffmanElement(second));
        
        m_mmData.insert(std::make_pair(newElement.m_iCount, newElement));
    }
    
    m_resElement.m_pLeft.reset(new CHaffmanElement(m_mmData.begin()->second));
    
    m_resElement.m_pRight.reset(new CHaffmanElement(m_mmData.rbegin()->second));
}

void CHaffmanContainer::resMap()
{
    std::vector<int> value;
    if(m_resElement.m_pLeft)
        _parsChild(m_resElement.m_pLeft, value, 0);
    
    if(m_resElement.m_pRight)
        _parsChild(m_resElement.m_pRight, value, 1);
}

std::map<int,std::vector<int>> CHaffmanContainer::getResMap()
{
    return m_rResMap;
}

std::map<int,std::vector<int>> CHaffmanContainer::getRes()
{
    return m_rResMap;
}

void CHaffmanContainer::_parsChild(std::shared_ptr<CHaffmanElement> pCurrent, std::vector<int> prevVal, int iValue)
{
    prevVal.push_back(iValue);
    
    if(pCurrent->m_pLeft)
        _parsChild(pCurrent->m_pLeft, prevVal, 0);
    
    if(pCurrent->m_pRight)
        _parsChild(pCurrent->m_pRight, prevVal, 1);
    
    if(!pCurrent->m_pRight && !pCurrent->m_pLeft)
    {
        m_rResMap.insert(std::make_pair(pCurrent->m_iValue, prevVal));
    }
}
