#include<stdio.h>
#include<string.h>
#include<limits.h>
#include"fdijkstra.h"
#include"dijkstra.h"

int shortestPathBetweenTwoCities(int counter, int neighborhoodMatrix[][counter],int source,int target, char cityCodeMatrix[counter][20]) /// returns shortest path between two given cities.
{
    int dist[counter]; /// Holds distance between source and other cities.
    int m,minimum,start,d; /// needed variables.
    int selected[counter]; /// Holds selected graphs while algortihm works.
    int prev[counter]; /// Holds previous passed cities.
    char path[counter][20];

    for(int i=1;i< counter;i++)
    {
        selected[i]=0; /// Makes all graphs unselected.
    }

    for(int i=1;i< counter;i++)
    {
        dist[i] = INT_MAX; /// Makes distance from starting city to others infinite.
        prev[i] = -1; /// Will be used in the future.
    }

    start = source;
    selected[start]=1; /// Makes source city selected.
    dist[start] = 0; /// Makes source cities distance to itself 0.

    while(selected[target] ==0) /// Until algorithm reachs the target city.
    {
        minimum = INT_MAX;
        m = 0;
        for(int i=1; i<counter;i++)
        {
            d = dist[start] + neighborhoodMatrix[start][i];
            if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(minimum>dist[i] && selected[i]==0) /// if minimum distance bigger than distance of city and city was not selected before
            {
                minimum = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }

    start = target;  /// Backtracing cities target to start.
    int j = 0;
    int passedCitiesNumber=0;
    while(start != -1)
    {
        strcpy(path[j++],cityCodeMatrix[start]);
        passedCitiesNumber++;
        start = prev[start];
    }
    strcpy(path[target],cityCodeMatrix[target]);

    printf("Passed Cities: ");

    for(int i=passedCitiesNumber-1; i>=1; i--){
        printf("%s->", path[i]);
    }

    printf("%s",path[target]);

    return dist[target]; /// Returns distance to target city.
}

void shortestPathToAllCites(int counter, int neighborhoodMatrix[][counter],int source,char cityCodeMatrix[counter][20])
{
    int dist[counter]; /// Holds distance between source and other cities.
    int m,minimum,start,d; /// needed variables.
    int selected[counter]; /// Holds selected graphs while algortihm works.
    int prev[counter]; /// Holds previous passed cities.
    char path[counter][20];

    for(int target=1; target<counter; target++)
    {

        for(int i=1; i<counter; i++)
        {
            selected[i]=0; /// Makes all graphs unselected.
        }

        for(int i=1; i<counter; i++)
        {
            dist[i] = INT_MAX; /// Makes distance from starting city to others infinite.
            prev[i] = -1; /// Will be used in the future.
        }

        start = source;
        selected[start]=1; /// Makes source city selected.
        dist[start] = 0; /// Makes source cities distance to itself 0.

        while(selected[target] ==0) /// Until algorithm reachs the target city.
        {
            minimum = INT_MAX;
            m = 0;
            for(int i=1; i<counter; i++)
            {
                d = dist[start] + neighborhoodMatrix[start][i]; /// !!!INT_MAX error probably happens because of this line!!!
                if(d< dist[i]&&selected[i]==0)
                {
                    dist[i] = d;
                    prev[i] = start;
                }
                if(minimum>dist[i] && selected[i]==0) /// if minimum distance bigger than distance of city and city was not selected before
                {
                    minimum = dist[i];
                    m = i;
                }
            }
            start = m;
            selected[start] = 1;
        }
        start = target;  /// Backtracing cities target to start.
        int j = 0;
        int passedCitiesNumber=0;
        while(start != -1)
        {
            strcpy(path[j++],cityCodeMatrix[start]);
            passedCitiesNumber++;
            start = prev[start];
        }
        strcpy(path[target],cityCodeMatrix[target]);

        printf("Passed Cities: ");

        for(int i=passedCitiesNumber-1; i>=1; i--)
        {
            printf("%s->", path[i]);
        }

        printf("%s",path[target]);
        printf(" The shortest path %d\n",dist[target]);
    }
}
