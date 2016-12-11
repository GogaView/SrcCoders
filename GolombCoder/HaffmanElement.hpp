//
//  HaffmanElement.hpp
//  GolombCoder
//
//  Created by MacBook on 02.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef HaffmanElement_hpp
#define HaffmanElement_hpp

#include <stdio.h>


struct CHaffmanElement
{
    
    std::shared_ptr<CHaffmanElement>   m_pLeft;
    std::shared_ptr<CHaffmanElement>   m_pRight;
    
    int                                 m_iValue = -1;
    int                                 m_iCount = 0;
};

#endif /* HaffmanElement_hpp */
