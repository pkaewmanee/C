#include <stdio.h>
#include "search.h"

int main() {

  char big_brain_line[1000]; //a giant string to collect every single line in csv file
  char country_name[471][100]; //array to collect each countries
  int year[471]; //array to collect each year
  float annual_change[471]; //array to collect annual change

  char search[100] = ""; //array for you to search your data
  int i = 0; //i just used "i" instead of total

  char *sp;

  FILE *fp; //as you know, the file thingy

  fp = fopen("deforest.csv", "r"); //as you know, open the file thingy

  if (fp == NULL) {
    printf("Trouble reading file! \nProgram Terminating...");
    exit(0); //When have error as you know
  }

  while (fgets(big_brain_line, 1000, fp) != NULL) { //get every file into a big string call big_brain_line

    sp = strtok(big_brain_line, ","); //break a string into a token until it see ","

    /* in string Algeria,1990,-8800 it will read Algeria and stop at ,*/

    strcpy(country_name[i], sp); //collect the country name

    sp = strtok(NULL, ","); //move on from , to the next line

    year[i] = atoi(sp); //collect the year

    sp = strtok(NULL, ",");

    annual_change[i] = atof(sp); //collect the annual rate

    i++; //increase total to use it
  }

  fclose(fp);
  
  menu(country_name, year, annual_change, search, i);

  return (0);
}


