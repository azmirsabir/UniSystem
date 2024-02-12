//
// Created by Azmir.Sleman on 12/22/2023.
//
#include <iostream>
#include <cstdlib>
using namespace std;
class CMD{
public:
    static void clear(){
        const char *clear="cls";
//        system(clear);
        system("cls");
    }
    static void ukh(){
        cout<<"\t\t\t-----------------------------------------\n";
        cout<<"\t\t\t     University of Kurdistan-Hawler\n";
        cout<<"\t\t\t-----------------------------------------\n";
    }
};