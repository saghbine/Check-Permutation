//
//  main.cpp
//  Check Permutation
//
//  Created by daniel saghbine on 12/8/24.
//  CTCI 1.2 Check Permutation

#include <iostream>
using namespace std;

bool Check_Permutation(string &s1, string &s2);

int main()
{
    string str1, str2;
    
    cout<<"problem\n-------\n\tGiven two strings, write a method to decide if one is a permutation of the other.\n\n";
    
    cout<<"input\n-----\n\tType: ";
    cin>>str1;
    cout<<"\tType again: ";
    cin>>str2;
    
    cout<<"\noutput\n------\n\tThe strings are"<<(Check_Permutation(str1, str2) ? "" : "n't")<<" permutations of each other.\n\n";
    
    cout<<"solution\n--------\n\tAuxiliary space complexity: O(1); time complexity: O(n log n).\n\n";
    
    return 0;
}

void char_swap(char &c1, char &c2)
{
    c1=c1+c2;
    c2=c1-c2;
    c1=c1-c2;
}

void max_heapify(string &s, int n, int i)
{
    bool swap;
    int lc, rc, gc;
    
    do
    {
        swap=false;
        lc=2*i+1;
        
        if(lc < n)
        {
            rc=lc+1;
            
            if(rc < n && s[rc] > s[lc])
                gc=rc;
            else
                gc=lc;
            
            if(s[gc] > s[i])
            {
                char_swap(s[gc], s[i]);
                
                if(gc*2+1 < n)
                {
                    swap=true;
                    i=gc;
                }
            }
        }
    }
    while(swap);
}

void build_max_heap(string &s)
{
    for(int i=int(s.size())/2-1; i >= 0; i--)
        max_heapify(s, int(s.size()), i);
}

void heapsort(string &s)
{
    int counter=int(s.size());
    
    build_max_heap(s);
    
    while(counter > 1)
    {
        char_swap(s[0], s[--counter]);
        max_heapify(s, counter, 0);
    }
}

bool Check_Permutation(string &s1, string &s2) // s1 and s2 are input strings
{
    heapsort(s1); // sort s1 with heapsort
    heapsort(s2); // sort s2 with heapsort
    
    if(s1 == s2) // check if they are equivalent
        return true; // they are permutations
    
    return false; // they aren't permutations
}
