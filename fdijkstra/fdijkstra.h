#ifndef FDIJKSTRA_H_INCLUDED
#define FDIJKSTRA_H_INCLUDED

int compare0 (int counter, char cm[][20],char ccm[][20]);

int compare1 (int counter, char cm[][20],char ccm[][20]);

void addDistance (int counter,int i, int j, int nm[][counter], int distance);

int cityCounter (int counter);

void addToCCM (char cityCodeMatrix[][20]);

void addToNM (int counter, char cityCodeMatrix[][20],char city[][20],int neighborhoodMatrix[counter][counter]);
#endif // FDIJKSTRA_H_INCLUDED
