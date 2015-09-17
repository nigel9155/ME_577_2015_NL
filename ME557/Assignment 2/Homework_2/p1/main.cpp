//
//  main.cpp
//  ME 557 Assignment2
//
//  Created by Nigel Lee & Hsiang Sing Naik on 9/16/15.
//  Copyright (c) 2015 Nigel Lee. All rights reserved.
//

#include <iostream>
using namespace std; //allows the usage of cout


double FibonacciFunction(int n) //Define function and integer n
{
    unsigned int i = 0, j = 1, t, k; for (k=0; k <= n; ++k) //initialize integer i, j, t, k
    {
        t = i + j; //Fibonacci sequence formula
        i = j;
        j = t;
    }
    return j; //j is output of the function
}


int main(int argc, char *argv[]) //initialize main program


{

int p = FibonacciFunction(10); //call function
    cout << p << endl; //output value onto console
}

//p = 144
