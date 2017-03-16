/* The Shortest Path Finding Program */

#include<stdio.h>
#include<string.h>
#include<limits.h>
#include"fdijkstra.h"
#include"dijkstra.h"

void selectableCities (int counter, char cityCodeMatrix[][20])
{
    printf("\nSelectable Cities:\n");
    for(int i=1; i<counter; i++)
    {
        printf("%s\n",cityCodeMatrix[i]);
    }
    printf("\n");
}

void userInterface (int counter, char cityCodeMatrix[][20],int neighborhoodMatrix[counter][counter])
{
    char startingCity[20], destination[20];
    int shortestPath, nSource, nTarget;
    int mode;

    while(1)
    {

        printf("1-Shortest Path Between Two Cities\n");
        printf("2-Shortest Path to All Cities\n");
        printf("Select Mode:");
        scanf("%d",&mode);

        switch(mode)
        {

        case 1:
            selectableCities(counter,cityCodeMatrix);

            printf("\nEnter the starting city:");
            scanf("%s",&startingCity);

compare:
            if(compareFirstCity(counter,startingCity,cityCodeMatrix)==0)  /// Checking if user entered valid input.
            {
                printf("Please enter a valid city name:");
                scanf("%s",&startingCity);
                goto compare;
            }
            else
            {
                nSource = compareFirstCity(counter,startingCity,cityCodeMatrix);
            }

            printf("Enter the destination:");
            scanf("%s",&destination);

compar:
            if(compareFirstCity(counter,destination,cityCodeMatrix)==0)
            {
                printf("Please enter a valid city name:");
                scanf("%s",&destination);
                goto compar;
            }
            else
            {
                nTarget = compareFirstCity(counter,destination,cityCodeMatrix);
            }

            shortestPath = shortestPathBetweenTwoCities(counter,neighborhoodMatrix,nSource,nTarget,cityCodeMatrix);
            printf("\nThe Shortest Path: %d\n",shortestPath);
            printf("\n");

            break;
        case 2:
            selectableCities(counter,cityCodeMatrix);
            printf("\nEnter the starting city:");
            scanf("%s",&startingCity);

compa:
            if(compareFirstCity(counter,startingCity,cityCodeMatrix)==0)  /// Checking if user entered valid input.
            {
                printf("Please enter a valid city name:");
                scanf("%s",&startingCity);
                goto compa;
            }
            else
            {
                nSource = compareFirstCity(counter,startingCity,cityCodeMatrix);
            }

            shortestPathToAllCites(counter,neighborhoodMatrix,nSource,cityCodeMatrix);
            printf("\n");
            break;
        }

    }
}

int main()
{
    int counter = 0;

    counter = cityCounter(counter);

    char (*cityCodeMatrix)[20] = calloc(counter,sizeof (*cityCodeMatrix)); /// Allocating memory to city code matrix.
    char (*city) [20] = calloc(2,sizeof(*city)); /// Allocating memory to city matrix. /// city matrix corruption could happen cause of size 20.
    int (*neighborhoodMatrix)[counter] = calloc(counter+5,sizeof (*neighborhoodMatrix)); /// Allocating memory to neighborhood matrix.

    addToCCM(cityCodeMatrix); /// Pulling data from the file to cityCodeMatrix.
    addToNM(counter,cityCodeMatrix,city,neighborhoodMatrix); /// Pulling data from the file to neighborhoodMatrix.

    userInterface(counter,cityCodeMatrix,neighborhoodMatrix);

    return 0;
}
