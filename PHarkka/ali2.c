/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Konsta Keski-Mattinen
 * Opiskelijanumero: 0568752
 * Päivämäärä: 
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
//muut aliohjelmat
#include "ali2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*void printLList(readNode *pStart){
    if(pStart == NULL){
        //printf("Lista on tyhjä.\n");
        printf("\n");
        return;
    }
    //printf("Listassa on seuraavat luvut: \n");
    for(readNode *ptr = pStart;ptr != NULL; ptr=ptr->pNext){
        printf("%d ", ptr->value);
    }
    printf("\n");
}*/

readNode * addLList(readNode *pStart, struct tm *pTime, char * sTaskName, int iNameLength, int iTaskID, int iUserID){
    readNode *pNew, *ptr;

    if((pNew = (readNode*)malloc(sizeof(readNode)))== NULL){
        printf("Muistin varaus epäonnistui.\n");
        exit(1);
    }

    pNew->time=*(pTime);
    strncpy(pNew->name, sTaskName, iNameLength);
    pNew->taskID=iTaskID;
    pNew->userID=iUserID;
    pNew->pNext=NULL;

    if(pStart == NULL){
        pNew->pNext=pStart;
        pStart= pNew;
    } else {
        int i = 1;
        for(ptr = pStart;;ptr=ptr->pNext){
            if(ptr->pNext == NULL){
                ptr->pNext=pNew;
                break;
            }
            i++;
        }
    }
    return pStart;
}

readNode * freeLList(readNode *pStart){
    readNode *ptr = pStart;

    while(ptr != NULL){
        pStart = ptr->pNext;
        free(ptr);
        ptr = pStart;
    }

    return pStart;
}

void analFile(readNode *pStart, analNode * tasks, int analListSize){
    if(pStart == NULL){
        printf("Ei analysoitavaa, lue ensin palautustiedosto.\n");
        return;
    }

    int numOfReturns;
    int numOfReturnedTasks;
    int iAverage;

    for(int i = 0; i<analListSize; i++){
        strcpy(tasks[i].name, "Tyhjä");
        tasks[i].returns= 0;
    }

    for(readNode *ptr = pStart;ptr != NULL; ptr=ptr->pNext){
        strcpy(tasks[ptr->taskID-1].name, ptr->name);
        tasks[ptr->taskID-1].returns += 1;
    }

    //Analysing
    for(int i=0; i<analListSize;i++){
        if(tasks[i].returns != 0){
            numOfReturnedTasks++;
        }
        numOfReturns += tasks[i].returns;
    }
    iAverage = numOfReturns / numOfReturnedTasks;

    printf("Palautuksia oli yhteensä %d, %d eri tehtävässä, keskimäärin %d per tehtävä.", numOfReturns, numOfReturnedTasks, iAverage);
    printf("\n");
    return;
}
