//
// Created by Adrian Antonio on 4/20/2021.
//

#ifndef HOMEWORK5_MYREADWRITE_H
#define HOMEWORK5_MYREADWRITE_H

#include <iostream>
#include <fstream>
#include<string>


template<typename T>
void myWrite(std::ofstream & file,T & variableName){

}
template<typename T>
void myRead(std::ifstream & fileName, T & variableName) {
    if (!fileName.is_open()) {
        std::cout << "File NOT open!!" << std::endl;
    } else {
        fileName.read(reinterpret_cast<char *>(variableName), sizeof(T)); //might need to add "&" also to variable name
    }
}

#endif //HOMEWORK5_MYREADWRITE_H
