#include<limits.h>
#include<stdio.h>
#include<string.h>
#include "fdijkstra.h"

int compare0 (int counter, char cm[][20],char ccm[][20]){ /// finds the city number for given city and returns it.
    for(int i=1; i<counter; i++){
        if(!strcmp(cm[0],ccm[i])){ /// compares two strings given. ccm stands for cityCodeMatrix. cm stands for city
            return i; /// returns city code number
        }
    }
    return counter+1; /// returning a non-valid number.
}

int compare1 (int counter, char cm[][20],char ccm[][20]){ /// finds the city number for given city and returns it.
    for(int i=1; i<counter; i++){
        if(!strcmp(cm[1],ccm[i])){ /// compares two strings given. ccm stands for cityCodeMatrix. cm stands for city.
            return i; /// returns city code number
        }
    }
    return counter+1; /// returning a non-valid number.
}

void addDistance (int counter,int i, int j, int nm[][counter], int distance){ /// adds distance to neighborhood matrix. nm stands for neighborhood matrix.
    nm[i][j] = distance;
    nm[j][i] = distance;
}

int cityCounter (int counter){ /// Finds out how many cities text file contains.
    int ch;
    FILE *fp;

    fp = fopen("sehir kod.txt","r"); /// opens file in read mode.

    while((ch=fgetc(fp))!= EOF) /// Until pointer reaches EOF
    {
        if (ch == '\n')
        {
            counter++;
        }
    }
    return counter;
    fclose(fp);
    /// Returns the number of cities.
}

void addToCCM (char cityCodeMatrix[][20]){ /// adds cities to city code matrix
    int ch;
    FILE *fp;

    fp = fopen("sehir kod.txt","r"); /// opens file in read mode.

    int x=0,y=0;

    while((ch=fgetc(fp))!= EOF)
    {
        if (ch == '\n')
        {
            x++;
            y = 0;
            continue;
        }
        else if(ch == '-')
        {
            continue;
        }
        else if (ch>='0' && ch<='9')
        {
            continue;
        }
        else
        {
            cityCodeMatrix[x][y] = ch;
            y++;
        }
    }

    fclose(fp); /// Closing file.

    /*for(int i=1; i<counter; i++){
        printf("%s\n",cityCodeMatrix[i]);
    }*/ /// City Code Matrix control output */
}

void addToNM (int counter, char cityCodeMatrix[][20],char city[][20],int neighborhoodMatrix[counter][counter]) /// adds distances to neighborhood matrix
{
    int ch;
    FILE *fp;
    fp = fopen("sehir mesafe.txt","r");

    for(int i=0; i<counter; i++){
        for(int j=0; j<counter; j++){
                neighborhoodMatrix[i][j] = INT_MAX-1000;
        }
    } /// Neighborhood Matrix maxing distances.

    char number[4];

    int z = 0, x = 0, y = 0;

    while((ch=fgetc(fp))!= EOF)
    {
        if (ch == '-')
        {
            if(x==1)
            {
                continue;
            }
            else
            {
                x++;
            }
            y = 0;
            continue;
        }
        else if (ch>='0' && ch<='9')
        {
            number[z]=ch; /// adding numbers to number matrix
            z++;
            continue;
        }
        else if (ch == '\n')
        {
            addDistance(counter,compare0(counter,city,cityCodeMatrix),compare1(counter,city,cityCodeMatrix),neighborhoodMatrix,atoi(number));

            /*for(int i=0; i<counter; i++){
                printf("%s\n",cityCodeMatrix[i]);
            }*/ /// City Code Matrix control output.

            /// printf("%s-%s-%s\n",city[0],city[1],number); /// City Matrix control output.

            ///printf("%s\n",number); /// Number array control output.
            for(int i=0; i<2; i++)
            {
                for(int j=0; j<20; j++)
                {
                    city[i][j] = '\0';
                }
            }
            for(int i=0; i<4; i++)
            {
                number[i]= '\0';
            }
            x = 0;
            y = 0;
            z = 0;
            continue;
        }
        else
        {
            city[x][y] = ch;
            y++;
        }
    }
    addDistance(counter,compare0(counter,city,cityCodeMatrix),compare1(counter,city,cityCodeMatrix),neighborhoodMatrix,atoi(number)); /// Last one couldn't added in loop cause of EOF.

    ///printf("%s-%s-%s\n",city[0],city[1],number); /// City Matrix control output.

    fclose(fp);

    /*for(int i=1; i<counter; i++){
        for(int j=1; j<counter; j++){
                printf("%d|",neighborhoodMatrix[i][j]);
        }
         printf("\n");
    }*/ /// Neighborhood Matrix control output

    /* for(int i=0; i<counter; i++){
        printf("%s\n",cityCodeMatrix[i]);
    }*/ /// City Code Matrix control output
}
