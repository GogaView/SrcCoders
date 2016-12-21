//
//  ArifmeticMain.h
//  GolombCoder
//
//  Created by MacBook on 11.12.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef ArifmeticMain_h
#define ArifmeticMain_h

#include "ArifmeticCodec.hpp"
#include "MarcovGenerator.hpp"
#include "ArifmeticProbe.hpp"
#include "MatrixCulculate.h"
#include "WriteToFile.hpp"

#include <assert.h>


std::map<int, std::pair<double, double>>  _getProbe(std::vector<int> vData)
{
    std::map <int, int> mProbe;
    for(auto it = vData.begin(); it != vData.end(); ++it)
    {
        if(mProbe.find(*it) == mProbe.end())
            mProbe[*it] = 1;
        else
            mProbe[*it] += 1;
        
    }
    
    std::map<int, std::pair<double, double>> res;
    double dRes = 0;
    
    for(auto it = mProbe.begin(); it != mProbe.end(); ++it)
    {
        std::pair<double, double> pair;
        pair.first = dRes;
        
        dRes = dRes + static_cast<double>(it->second) / vData.size();
        pair.second = dRes;
        
        res.insert(std::make_pair(it->first, pair));
    }
    
    return res;
}

std::map<int, std::pair<double, double>> _getProbe(std::map<int, std::map<int, int> > matrix)
{
    CMatrixCalculate matrixCalcul(matrix);
    matrixCalcul.gauss();
    
    auto dVect = matrixCalcul.ans;
    
    std::map<int, std::pair<double, double>> res;
    double dRes = 0;
    int iVal = 0;
    
    for(auto it = dVect.begin(); it != dVect.end(); ++it)
    {
        std::pair<double, double> pair;
        pair.first = dRes;
        
        dRes = dRes + *it;
        pair.second = dRes;
        
        res.insert(std::make_pair(iVal, pair));
    }
    
    return res;
    
}


void ArifmeticDef()
{
    CMarcovGenerator marcov(3);
    marcov.getStreamData(30);
    
    СArifmeticProbe probe(3);
    
    
    std::vector<int> vect = marcov.getStreamData();
    CArifmeticCoder coder(probe.getProbe());
    coder.code(vect);
    auto vDecode = coder.decode(vect.size());
    
    assert(vDecode == vect);
    
    CWriteToFile("/Users/macbook/Documents/tmp/Arifmetic_Def_code.txt", vect);
    CWriteToFile("/Users/macbook/Documents/tmp/Arifmetic_Def_decode.txt", vDecode ,1);
}

void ArifmeticDinamic()
{
    CMarcovGenerator marcov(3);
    marcov.getStreamData(30);
    
    СArifmeticProbe probe(3);
    
    
    std::vector<int> vect = marcov.getStreamData();
    CArifmeticCoder coder(_getProbe(vect));
    coder.code(vect);
    auto vDecode = coder.decode(vect.size());
    
    assert(vDecode == vect);
    
    CWriteToFile("/Users/macbook/Documents/tmp/Arifmetic_Dinamic_code.txt", vect);
    CWriteToFile("/Users/macbook/Documents/tmp/Arifmetic_Dinamic_decode.txt", vDecode ,1);
}

void ArifmeticGaus()
{
    CMarcovGenerator marcov(3);
    marcov.getStreamData(30);
    
    СArifmeticProbe probe(3);
    
    
    std::vector<int> vect = marcov.getStreamData();
    CArifmeticCoder coder(_getProbe(marcov.getMapForHaffman()));
    coder.code(vect);
    auto vDecode = coder.decode(vect.size());
    
    assert(vDecode == vect);
    
    CWriteToFile("/Users/macbook/Documents/tmp/Arifmetic_Gaus_code.txt", vect);
    CWriteToFile("/Users/macbook/Documents/tmp/Arifmetic_Gaus_decode.txt", vDecode ,1);
}

void Arifmetic()
{
    ArifmeticDef();
    ArifmeticDinamic();
    ArifmeticGaus();
}

#endif /* ArifmeticMain_h */
