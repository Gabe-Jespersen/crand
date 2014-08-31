/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  main file
 *
 *        Version:  1.0
 *        Created:  08/30/2014 07:43:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen (), gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "parse.h"

using namespace std;

int main(int argc, char **argv)
{
    srand(time(NULL));
    vector<long long int> range = parse(argc, argv);
    long long int result;
    // range.at(0) + (rand() % (range.at(1) - range.at(0) + 1))
    
    for(int i = 0; i < range.at(2);i++)
    {
        result = range.at(0) + (rand() % (range.at(1) - range.at(0) + 1));
        cout << result << endl;
    }
    return 0;
}
