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
    cout << "Please enter a minimum and a maximum number for the program, to do this, use the flags as follows:\n" <<
             "\t-h: this menu\n"
             "\t-i: the minimum value, enter that number as the next argument\n"
             "\t-a: the maximum value, enter that number as the next argument\n"
             "\t\tan example of how to use -a and -i:\n"
             "\t\t  ./crand -i 10 -a 20\n"
             "\t-r: set a range, similar to minimum and maximum, use as follows:\n"
             "\t\t./crand -r 10-20\n"
             "\t-n: how many random numbers to generate, enter that number as the next argument, defaults to 1\n\n";
    return;
}
vector<long long int> parse(int argc, char **argv)
{
    if(argc<3)//if there isn't enough inputs for there to be a min/maximum
    {
        helpMenu();
        exit(1);
    }

    long long int minimum;
    long long int maximum;
    int numberOf = 1; //number of numbers to generate, defaults to one

    bool maxset = false;
    bool minset = false;

    for(int i = 1; i < argc; i++)
    {                            
        if(!strcmp(argv[i],"-h"))
        {
            helpMenu();
            exit(2);
        }

        if(!strcmp(argv[i],"-r")&&argc>(i+1))//this code will be horrible, need to find
        {                                    //need to find a better way to do this
            bool firstNegative = false;
            int dashAt;
            if(strlen(argv[i+1])<3)//if there isn't enough characters to have #-#
            {
                helpMenu();
                exit(1);
            }
            if(argv[i+1][0]=='-')//if the minimum is negative, going to check
                                 //for a dash, don't want to get confused with
            {                    //negatives
                firstNegative = true;
            }
            for(int j = firstNegative; j < strlen(argv[i+1]);j++)//going to find
            {                                                    //the first dash
                if(argv[i+1][j]=='-')
                {
                    dashAt = j;
                }
            }
            if(strlen(argv[i+1]) <= dashAt)
            {
                helpMenu();
                cout << "Error, first non-negative representative dash at end of range input\n";
                exit(1);
            }
            minimum = atoi(argv[i+1]);
            minset = true;
            maximum = atoi(argv[i+1]+(dashAt+1));
            maxset = true;
        }

        if(!strcmp(argv[i],"-i")&&argc>(i+1))
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

    if(minimum>maximum)
    {
        helpMenu();
        cout << "Error, minimum is greater than maximum\n";
        exit(1);
    }

    vector<long long int> toReturn = {minimum,maximum,numberOf};
    return(toReturn);
}
