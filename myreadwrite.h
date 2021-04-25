//
// Created by Adrian Antonio on 4/20/2021.
//

#ifndef HOMEWORK5_MYREADWRITE_H
#define HOMEWORK5_MYREADWRITE_H

#include <iostream>
#include <fstream>
#include<string>


template<typename T>
void myWrite(std::ofstream & fileName, T variableName){
    if(fileName.is_open()){
        fileName.write(reinterpret_cast<char *>(&variableName), sizeof(T));
    }else{
        std::cout<<"File NOT OPEN!!"<<std::endl;
    }
}
template<typename T>
void myRead(std::ifstream & fileName, T  variableName) {
    if (fileName.is_open()) {
        fileName.read(reinterpret_cast<char *>(variableName), sizeof(T)); //might need to add "&" also to variable name
    } else {
        std::cout << "File NOT open!!" << std::endl;

    }
}

#endif //HOMEWORK5_MYREADWRITE_H
