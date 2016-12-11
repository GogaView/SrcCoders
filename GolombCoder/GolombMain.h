//
//  GolombMain.h
//  GolombCoder
//
//  Created by MacBook on 11.12.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef GolombMain_h
#define GolombMain_h


#include "GolombGenerator.hpp"
#include "GolombCoder.hpp"
#include "GolombDecoder.hpp"


void coder(double p)
{
    CGolombGenerator golombGenerator(1000, p);
    std::vector<int> lSrcData = golombGenerator.getSourceData();
    
    GolombCoder golombcoder(1, p);
    golombcoder.coding(lSrcData);
    
    GolombDecoder golombDecoder(golombcoder.getBitstream(), 3);
}

void getM(double p)
{
    double tmp = (1.0 / (1+p));
    
    double dLog = log2(tmp) / log2(p);
    
    std:: cout << " p = " << p << "\t" << ceil(dLog) << std::endl;
}


void golomb()
{
    
        double p1 = 0.1;
        double p2 = 0.3;
        double p3 = 0.5;
    
        coder(p1);
        coder(p2);
        coder(p3);
    
        getM(p1);
        getM(p2);
        getM(p3);
    
    
    
    
        CGolombGenerator golombGenerator(10, 0.5);
        std::vector<int> lSrcData = golombGenerator.getSourceData();
    
        GolombCoder golombcoder(3);
        golombcoder.coding(lSrcData);
    
        GolombDecoder golombDecoder(golombcoder.getBitstream(), 3);
    

}


#endif /* GolombMain_h */
