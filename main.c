/* The Shortest Path Finding Program */

#include<stdio.h>
#include<string.h>
#include<limits.h>
#include"fdijkstra.h"
#include"dijkstra.h"


void userInterface (int counter, char cityCodeMatrix[][20],int neighborhoodMatrix[counter][counter]){
    char source[20], target[20];
    int shortestPath, nSource, nTarget;

    while(1){
        printf("\nEnter the source:");
        scanf("%s",&source);

        compare:
        if(compare0(counter,source,cityCodeMatrix)>22){ /// Checking if user entered valid input.
            printf("Please enter a valid city name:");
            scanf("%s",&source);
            goto compare;
        }
        else{
            nSource = compare0(counter,source,cityCodeMatrix);
        }

        printf("Enter the target:");
        scanf("%s",&target);

        compar:
        if(compare0(counter,target,cityCodeMatrix)>22){
            printf("Please enter a valid city name:");
            scanf("%s",&target);
            goto compar;
        }
        else{
            nTarget = compare0(counter,target,cityCodeMatrix);
        }

        shortestPath = shortestPathBetweenTwoCities(counter,neighborhoodMatrix,nSource,nTarget,cityCodeMatrix);
        printf("\nThe Shortest Path: %d\n",shortestPath);
        shortestPathToAllCites(counter,neighborhoodMatrix,nSource,cityCodeMatrix);
    }
}

int main()
{
    int counter = 0;

    counter = cityCounter(counter);

    char (*cityCodeMatrix)[20] = calloc(counter,sizeof (*cityCodeMatrix)); /// Allocating memory to city code matrix.
    char (*city) [20] = calloc(2,sizeof(*city)); /// Allocating memory to city matrix.
    int (*neighborhoodMatrix)[counter] = calloc(counter+5,sizeof (*neighborhoodMatrix)); /// Allocating memory to neighborhood matrix.

    addToCCM(cityCodeMatrix); /// Pulling data from the file to cityCodeMatrix.
    addToNM(counter,cityCodeMatrix,city,neighborhoodMatrix); /// Pulling data from the file to neighborhoodMatrix.

    /*for(int i=0; i<counter; i++){
        printf("%s\n",cityCodeMatrix[i]);
    } /// City Code Matrix control output

    for(int i=1; i<counter; i++){
        for(int j=1; j<counter; j++){
                printf("%d|",neighborhoodMatrix[i][j]);
        }
         printf("\n");
    }*/ /// Neighborhood Matrix control output

    userInterface(counter,cityCodeMatrix,neighborhoodMatrix);

    return 0;
}
