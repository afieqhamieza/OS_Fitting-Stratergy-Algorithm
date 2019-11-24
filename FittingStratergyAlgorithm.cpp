//
//  main.cpp
//  project 3
//
//  Created by afieqha mieza azemi on 09/11/2019.
//  Copyright © 2019 afieqha mieza azemi. All rights reserved.
//

#include <iostream>
using namespace std;

void findFit(int bSize[], int m, int pSize[], int n)
{
    int alloc[n];  //this will keep track of which block is used for each process
    
    for (int i=0; i<n; i++)
        alloc[i] = -1;  //this is to set all alloc to -1, meaning no block is allocate to any process yet
    
    for (int i=0; i<n; i++) //this will hold the index of process (to iterate each process)
    {
        int bestBlock = -1;
        for (int j=0; j<m; j++) //this will hold the index of blocks (to iterate each blocks)
        {
            if (bSize[j] >= pSize[i])   //if the size of the block is bigger than process, assign the index to bestBlock
            {
                if (bestBlock == -1)
                    bestBlock = j;
                else if (bSize[bestBlock] > bSize[j])   //comparing the previous block allocated to the other. which one is the best fit
                    bestBlock = j;
            }
        }
        
        if (bestBlock != -1)    //checking if a block is allocated to the process
        {
            alloc[i] = bestBlock;   //assigning the block allocated in the alloc array
            
            bSize[bestBlock] -= pSize[i];   //update the block size
        }
    }
    
    cout << "\nProcess\t   Block Allocated\n";
    
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t\t";
        
        if (alloc[i] == -1)
            cout << "Not Allocated";    //if the process is not allocated to any block because of lack of memory size
        else
            cout << alloc[i] + 1;
        
        cout << endl;
    }
}

int main()
{
    int x, y;
    
    cout << "Enter the number of memory blocks: ";
    cin  >> x;
    
    cout << "Enter number of files: ";
    cin  >> y;
    
    int block[x], process[y];
    
    for (int i=0; i<x; i++) {
        cout << "Enter the size for memory block " << i+1 << ": ";
        cin  >> block[i];
    }
    
    for (int i=0; i<y; i++) {
        cout << "Enter the size for process " << i+1 << ": ";
        cin  >> process[i];
    }
    
    int m = sizeof(block)/sizeof(block[0]); //num of blocks provided by user
    int n = sizeof(process)/sizeof(process[0]); // num of processes provided by user
    
    findFit(block, m, process, n);
    
    return 0 ;
}

