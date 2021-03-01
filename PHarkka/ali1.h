/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Konsta Keski-Mattinen
 * Opiskelijanumero: 0568752
 * Päivämäärä: 
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include "ali2.h"

#ifndef ali1_h
#define ali1_h

readNode* readFile();
analNode* analFile(readNode *);
int printFile(analNode *, int);
void findFile(char * target);

#endif