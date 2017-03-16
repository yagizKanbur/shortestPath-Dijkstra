#include<stdio.h>
#include<string.h>
#include<limits.h>
#include"fdijkstra.h"
#include"dijkstra.h"
#include <stdbool.h>

int shortestPathBetweenTwoCities(int counter, int neighborhoodMatrix[][counter],int startingCity,int destination, char cityCodeMatrix[counter][20])
{
    int* distance = malloc(counter * sizeof(int));
    int* visitedCities = calloc(counter,sizeof(int));
    int* reversedVisitedCities = calloc(counter,sizeof(int));
    bool* selectedCities = malloc(counter * sizeof(int));
    int iter = startingCity,minimum;
    int indiceOfNextCity, distanceToSC;

    for (int i=1; i<counter; i++)  /// Setting all distances except starting city's distance to infinity.
    {
        if (i == startingCity)
        {
            distance[startingCity] = 0;
        }
        else
        {
            distance[i]=INT_MAX;
        }
    }

    for (int i=1; i<counter; i++)
    {
        selectedCities[i] = false; /// false means unselected.
        visitedCities[i] = -1; /// -1 means unvisited.
    }

    /// selectedCities[startingCity] = true;
    distance[startingCity] = 0;

    while(selectedCities[destination] == false) /// Until destination selected
    {
        minimum = INT_MAX;

        for (int i = 1; i<counter; i++)
        {
            distanceToSC = distance[iter] + neighborhoodMatrix[iter][i]; /// Distance to starting city
            if (selectedCities[i] == false)
            {
                if (distanceToSC < distance[i])
                {
                    distance[i] = distanceToSC;
                    visitedCities[i] = iter;
                }
                if (minimum > distance[i])
                {
                    minimum = distance[i];
                    indiceOfNextCity = i;
                }
            }
            else
            {
                continue;
            }
        }
        iter = indiceOfNextCity;
        selectedCities[iter] = true;
    }
    iter = destination;
    int j=0;

    printf("Passed Cities: ");

    passedCities(counter,iter,cityCodeMatrix,visitedCities, destination,startingCity);

    return distance[destination];
}

void passedCities(int counter, int iter, char cityCodeMatrix[][20], int visitedCities[counter], int destination, int startingCity)
{
    while (iter != -1)
    {
        if(iter!=destination)
        {
            printf("<-%s",cityCodeMatrix[iter]);
        }
        else
        {
            printf("%s",cityCodeMatrix[iter]);
        }
        iter = visitedCities[iter];
    }
}

void shortestPathToAllCites(int counter, int neighborhoodMatrix[][counter],int startingCity,char cityCodeMatrix[counter][20])
{
    int* distance = malloc(counter * sizeof(int));
    int* visitedCities = calloc(counter,sizeof(int));
    int* reversedVisitedCities = calloc(counter,sizeof(int));
    bool* selectedCities = malloc(counter * sizeof(int));

    char path[counter][20];

    int iter = startingCity;
    int indiceOfNextCity, distanceToSC, minimum;

    for(int destination=1; destination<counter; destination++)
    {

        for (int i=1; i<counter; i++)  /// Setting all distances except starting city's distance to infinity.
        {
            if (i == startingCity)
            {
                distance[startingCity] = 0;
            }
            else
            {
                distance[i]=INT_MAX;
            }
        }

        for (int i=1; i<counter; i++)
        {
            selectedCities[i] = false; /// false means unselected.
            visitedCities[i] = -1; /// -1 means unvisited.
        }

        iter = startingCity;
        selectedCities[iter]= true; /// Makes source city selected.

        while(selectedCities[destination] == false) /// Until destination selected
        {
            minimum = INT_MAX;

            for (int i = 1; i<counter; i++)
            {
                distanceToSC = distance[iter] + neighborhoodMatrix[iter][i]; /// Distance to starting city
                if (selectedCities[i] == false)
                {
                    if (distanceToSC < distance[i])
                    {
                        distance[i] = distanceToSC;
                        visitedCities[i] = iter;
                    }
                    if (minimum > distance[i])
                    {
                        minimum = distance[i];
                        indiceOfNextCity = i;
                    }
                }
                else
                {
                    continue;
                }
            }
            iter = indiceOfNextCity;
            selectedCities[iter] = true;
        }

        iter = destination;
        int j=0;

        printf("Passed Cities: ");

        passedCities(counter,iter,cityCodeMatrix,visitedCities, destination,startingCity);
        printf(" The Shortest Path: %d",distance[destination]);
        printf("\n");
    }
}
