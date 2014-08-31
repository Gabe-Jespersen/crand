/*
 * =====================================================================================
 *
 *       Filename:  parse.cpp
 *
 *    Description:  parsing input for minimum and maximum numbers
 *
 *        Version:  1.0
 *        Created:  08/30/2014 07:49:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen (), gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>

#include "parse.h"

using namespace std;

void helpMenu()
{
    cout << "Please enter 4 flags for the program:\n" <<
             "\t-i: the minimum value, enter that number as the next argument\n"
             "\t-a: the maximum value, enter that number as the next argument\n"
             "\t-n: how many random numbers to generate, enter that number as the next argument, defaults to 1";
    return;
}
vector<long long int> parse(int argc, char **argv)
{
    if(argc<5)//if there isn't enough inputs for there to be a start and a finish
    {
        helpMenu();
        exit(1);
    }

    long long int minimum;
    long long int maximum;
    int numberOf = 1; //number of numbers to generate, defaults to one

    bool maxset = false;
    bool minset = false;

    for(int i = 1; i < (argc-1); i++)//minus 1 so that if last flag is -i or -a
    {                                //the program won't read a value that
        if(!strcmp(argv[i],"-i")&&argc>(i+1))    //doesn't exist
        {
            minimum = atoi(argv[i+1]);
            minset = true; //setting if minimum/maximum has been set, can't do
                           //!minimum, because, if it is 0, it returns true

            i++;//won't read the next value, which is set to the minimum, also
                //done in the maximum
        }
        if(!strcmp(argv[i],"-a")&&argc>(i+1))
        {
            maximum = atoi(argv[i+1]);
            maxset = true;
            i++;
        }
        if(!strcmp(argv[i],"-n")&&argc>(i+1))
        {
            numberOf = atoi(argv[i+1]);
            i++;
        }
    }

    if(!(minset)||!(maxset))//if there isn't a value for max or min
    {
        helpMenu();
        exit(1);
    }

    vector<long long int> toReturn = {minimum,maximum,numberOf};
    return(toReturn);
}
