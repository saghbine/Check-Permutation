//
//  main.cpp
//  Check Permutation
//
//  Created by daniel saghbine on 12/8/24.
//
//  CTCI 1.2 Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.
//  Auxiliary space complexity: O(1). Time complexity: O(n log n).

#include <iostream>
using namespace std;

bool Check_Permutation(string &s1, string &s2);

int main()
{
    string str1, str2;
    
    cout<<"Type a string: ";
    cin>>str1;
    cout<<"Type another string: ";
    cin>>str2;
    
    cout<<"The strings are"<<(Check_Permutation(str1, str2) ? "" : "n't")<<" permutations of each other.\n";
    
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

bool Check_Permutation(string &s1, string &s2) // s1 is the first C++ string and s2 is the second
{
    heapsort(s1); // sort the first string with heapsort
    heapsort(s2); // sort the second string with heapsort
    
    if(s1 == s2) // check if the strings are the same thing
        return true; // they are permutations
    
    return false; // they are not permutations
}
