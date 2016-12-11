//
//  HaffmanMain.h
//  GolombCoder
//
//  Created by MacBook on 20.11.16.
//  Copyright © 2016 kosa. All rights reserved.
//

#ifndef HaffmanMain_h
#define HaffmanMain_h


#include "MarcovGenerator.hpp"
#include "ValueAccumulator.hpp"
#include "HaffmanContainer.hpp"

#include "HafmanCoder.hpp"
#include "HaffmanDecoder.hpp"

#include "HaffmanCoderPair.hpp"
#include "HaffmanDecoderPair.hpp"

#include "WriteToFile.hpp"
#include "ReadFromFile.hpp"
#include "MatrixCulculate.h"

int ihaffmanLen = 100000;








void haffmanNormal(CMarcovGenerator marcov)
{
    std::vector<int> vect = marcov.getStreamData();
    
    CValueAccumulator vectAccum(vect);
    std::map<int, int> mAccumValues = vectAccum.getAccumNormal();
    
    CHaffmanContainer haffCounter;
    
    haffCounter.setValues(mAccumValues);
    
    haffCounter.processTree();
    haffCounter.resMap();
    
    CHaffmanCoder coder;
    coder.setHaffmanMap( haffCounter.getResMap() );
    coder.coding(vect);
    
    CHaffmanDecoder decoder;
    decoder.setHaffmanMap(haffCounter.getResMap());
    decoder.decoding(coder.getCodingData());
    
    
    CWriteToFile("/Users/macbook/Documents/tmp/HaffmanNormal_Code.txt", coder.getCodingData());
    CWriteToFile("/Users/macbook/Documents/tmp/HaffmanNormal_Code_Origin.txt", vect,1);
}

void haffmanByPairs(CMarcovGenerator marcov)
{
    std::vector<int> vect = marcov.getStreamData();
    
    CValueAccumulator vectAccum(vect);
    std::map<int, std::map<int, int> > mAccumValues = vectAccum.getAccumNormalByPairs();
    
    
    std::map<int, std::map<int, std::vector<int> > > mHaffmanPairs;
    
    
    for(int i = 0 ; i != mAccumValues.size(); i++)
    {
        CHaffmanContainer haffCounter;
        haffCounter.setValues(mAccumValues[i]);
    
        haffCounter.processTree();
        haffCounter.resMap();
        
        mHaffmanPairs[i] = haffCounter.getRes();
    }
    
    CHaffmanCoderPair coder;
    coder.setHaffmanMap( mHaffmanPairs );
    coder.coding(vect);
    
    CHaffmanDecoderPair decoder;
    decoder.setHaffmanMap(mHaffmanPairs);
    decoder.decoding(coder.getCodingData());
    
    CWriteToFile("/Users/macbook/Documents/tmp/HaffmanByPairs_Code.txt", coder.getCodingData());
    CWriteToFile("/Users/macbook/Documents/tmp/HaffmanByPairs_Code_Origin.txt", vect,1);
}

void haffmanByOriginPairs(CMarcovGenerator marcov)
{
    std::vector<int> vect = marcov.getStreamData();
    
    std::map<int, std::map<int, int> > mAccumValues = marcov.getMapForHaffman();
    
    std::map<int, std::map<int, std::vector<int> > > mHaffmanPairs;
    for(int i = 0 ; i != mAccumValues.size(); i++)
    {
        CHaffmanContainer haffCounter;
        haffCounter.setValues(mAccumValues[i]);
        
        haffCounter.processTree();
        haffCounter.resMap();
        
        mHaffmanPairs[i] = haffCounter.getRes();
    }
    
    CHaffmanCoderPair coder;
    coder.setHaffmanMap( mHaffmanPairs );
    coder.coding(vect);
    
    CHaffmanDecoderPair decoder;
    decoder.setHaffmanMap(mHaffmanPairs);
    decoder.decoding(coder.getCodingData());
    
    CWriteToFile("/Users/macbook/Documents/tmp/HaffmanByOrigPairs_Code.txt", coder.getCodingData());
    CWriteToFile("/Users/macbook/Documents/tmp/HaffmanByOrigPairs_Code_Origin.txt", vect,1);
}


void haffman()
{
    CMarcovGenerator marcov(3);
    marcov.getStreamData(ihaffmanLen);
    
    auto matrix = marcov.getMapForHaffman();
    CMatrixCalculate matrixCalcul(matrix);
    matrixCalcul.gauss();
    
    auto dVect = matrixCalcul.ans;
    
    
    double HRes = 0;
    for(int i = 0; i != matrixCalcul.m_matOrigIn.size(); i++)
    {
        double H = 0;
        for(int j = 0; j != matrixCalcul.m_matOrigIn.size(); j++)
        {
            H += (-1)* log(matrixCalcul.m_matOrigIn[i][j]) * matrixCalcul.m_matOrigIn[i][j];
        }
        
        HRes += dVect[i] * H;
    }
    
    std::cout << "H = " << HRes << std::endl;
    
    
    haffmanNormal(marcov);
    haffmanByPairs(marcov);
    haffmanByOriginPairs(marcov);
    
}

#endif /* HaffmanMain_h */
