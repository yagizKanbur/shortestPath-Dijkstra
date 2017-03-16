#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

int shortestPathBetweenTwoCities(int counter, int neighborhoodMatrix[][counter],int source,int target, char cityCodeMatrix[counter][20]);

void shortestPathToAllCites(int counter, int neighborhoodMatrix[][counter],int source,char cityCodeMatrix[counter][20]);

void passedCities(int counter, int iter, char cityCodeMatrix[][20], int visitedCities[counter], int destination, int startingCity);

#endif // DIJKSTRA_H_INCLUDED
