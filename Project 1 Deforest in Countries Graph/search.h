#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pbPlots.h"
#include "supportLib.h"

void menu(char[][100], int[], float[], char[], int);
void re_menu(char[][100], int[], float[], char[], int);
void search_con(char[][100], int[], float[], char[], int);
void search_display(char[][100], int[], float[], char[], int, int, int);
void no_coun(char[][100], int[], float[], char[100], int, int, int, int);
void plot(int[], float[], int, int);
void ask_plot(char[][100], int[], float[], int, int, char[100], int);
void array_year_annual(int[], float[], int, int, double[][2]);
float total_change(int[], float[], int, int);
float per_year_change(int[], float[], int, int, float);

void menu(char country_name[][100], int year[], float annual_change[],
          char search[100], int total) {

  char input;

  printf("+------------------------------------------------Forest------------------------------------------------+\n");
  printf("+------------------------------------------------------------------------------------------------------+\n");
  printf("|1.Search Country to see how much it forest expanded  2. End |\n");

  printf("Enter your choice: ");

  input = getchar(); // basically the scanf of char

  while (input == '\n') {
    input = getchar();
  }
  switch (input) {
  case '1':
    search_con(country_name, year, annual_change, search, total);
    break;
  case '2':
    printf("End of Program");
    exit(0);
    break;
  default:
    printf("No such Options\n");
    break;
  }
}

void search_con(char country_name[][100], int year[], float annual_change[],char search[100], int total) {
  int com; // int for comparison
  int i = 0, counter = 0;

  printf("\nWhich country are you searching for: ");
  scanf("%s", search); // string search are use for comparison

  for (i = 0; i < total; i++) {
    if (com != 0) {
      com = strcasecmp(
          country_name[i],
          search); // compare regardless of case until it find the first string
                   // with same name, the comparison is same, com will be 1.
      counter++; // counter are also use to notify our string, such as in
                 // Argentina,1990,-182600. Counter will be 5.
    } else if (com == 0) {
      break;
    }
  }

  if (com != 0 && counter == i) // if com != 0 mean there is no string(country)
                                // like that in the data and counter == i mean if
                                // there is no data until the end of file
  {
    no_coun(country_name, year, annual_change, search, total, com, i, counter);
  } else if (com == 0) {
    search_display(country_name, year, annual_change, search, i, counter,
                   total);
  }
}

void search_display(char country_name[][100], int year[], float annual_change[],
                    char search[100], int i, int counter, int total) {
  char con_dis[100] = "Country";                             // basic display
  char year_dis[100] = "Year";                               // basic display
  char annual_dis[100] = "Annual net change in forest area"; // basic display
  int com;
  int start_index_coun = counter - 1; // counter - 1 because array start at 0
  int end_index_coun = start_index_coun;

  float sum, per_year;

  printf("%20s%20s%40s", con_dis, year_dis, annual_dis);

  for (i = start_index_coun; com == 0; i++) {
    com = strcasecmp(country_name[i],
                     search); // to make sure that country that are search and
                              // county_name are same
    if (com == 0) {
      printf("\n%20s%20d%20.1f", country_name[i], year[i], annual_change[i]);
      end_index_coun++; // until the it reach the end, keep increasing then need
                        // to minus it because it's one too much
    } else {
      break;
    }
  }

  sum = total_change(year, annual_change, start_index_coun, end_index_coun);

  printf("\n\nThe total change in forest area measures forest expansion in %s "
         "is %.2f ha.\n",
         country_name[start_index_coun], sum);

  per_year = per_year_change(year, annual_change, start_index_coun,
                             end_index_coun, sum);

  if (sum > 0) {
    printf("The forest in %s has expanded %.1f ha per year since %d-%d\n",
           country_name[start_index_coun], per_year, year[start_index_coun],
           year[end_index_coun - 1]);
  } else if (sum < 0) {
    printf("The forest in %s has shrinked %.1f ha per year since %d-%d\n",
           country_name[start_index_coun], per_year, year[start_index_coun],
           year[end_index_coun - 1]);
  }

  ask_plot(country_name, year, annual_change, start_index_coun, end_index_coun,
           search, total);

  re_menu(country_name, year, annual_change, search, total);
}

void no_coun(char country_name[][100], int year[], float annual_change[],
             char search[100], int total, int com, int i, int counter) {
  printf("There are is no country in the data.\n\n");
  re_menu(country_name, year, annual_change, search, total);
}

void re_menu(char country_name[][100], int year[], float annual_change[],
             char search[100], int total) {
  printf("\n\n\nDo you want to restart the Program\n");
  printf("If you want too type 1\n");
  printf("If you want to end the program type 2\n");
  printf("If you want to search new country type 3\n");
  printf("Enter your choice: ");

  char input = getchar();
  while (input == '\n') {
    input = getchar();
  }
  switch (input) {
  case '2':
    printf("...Terminating Program");
    exit(0);
    break;
  case '1':
    printf("\nRestarting...\n\n");
    sleep(2);
    system("clear");
    menu(country_name, year, annual_change, search, total);
    break;
  case '3':
    search_con(country_name, year, annual_change, search, total);
    break;
  default:
    printf("No such Options\n");
    break;
  }
} // exactly what it said, redo menu again

void ask_plot(char country_name[][100], int year[], float annual_change[],
              int start_index_coun, int end_index_coun, char search[100],
              int total) {
  printf("\nDo you want to see the graph\n");
  printf("If you want to see type 1\n");
  printf("If you don't want to see type 2\n");
  printf("Enter your choice: ");

  char input = getchar();
  while (input == '\n') {
    input = getchar();
  }
  switch (input) {
  case '2':
    re_menu(country_name, year, annual_change, search, total);
    break;
  case '1':
    printf("\n");
    plot(year, annual_change, start_index_coun, end_index_coun);
    printf("Please open country.png file to see it.");
    break;
  default:
    printf("No such Options\n");
    break;
  }
} // exactly what it said it will do

void plot(int year[], float annual_change[], int start_index_coun,
          int end_index_coun) {
  int i;

  //  int j = start_index_coun;

  int j;

  int index = end_index_coun - start_index_coun; // total of thing

  double year_annual[4][2];

  array_year_annual(year, annual_change, start_index_coun, end_index_coun,
                    year_annual); // this is where 2d array happen

  double x[index];
  double y[index];
  _Bool success;

  for (i = 0; i < index; i++) {
    // x[i] = (double)year[j];
    // y[i] = annual_change[j];
    for (j = 0; j < index; j++) {
      if (j == 0) {
        x[i] = year_annual[i][j];
      } else if (j == 1) {
        y[i] = year_annual[i][j];
      }
    }
    // j++;
  }

  //From this point on, I just follow the creator of the code's example
  
  RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
  StringReference *errorMessage =
      (StringReference *)malloc(sizeof(StringReference));

  success =
      DrawScatterPlot(imageRef, 600, 400, x, index, y, index, errorMessage);

  if (success) {
    size_t length;
    double *pngData = ConvertToPNG(&length, imageRef->image);
    WriteToFile(pngData, length, "country.png");
    DeleteImage(imageRef->image);
  } else {
    fprintf(stderr, "Error: ");
    for (int i = 0; i < errorMessage->stringLength; i++) {
      fprintf(stderr, "%c", errorMessage->string[i]);
    }
    fprintf(stderr, "\n");
  }
  
}

void array_year_annual(int year[], float annual_change[], int start_index_coun,
                       int end_index_coun, double year_annual[][2]) {

  int i, j, index = end_index_coun - start_index_coun;

  for (i = 0; i < index; i++) {
    for (j = 0; j < 2; j++) {
      if (j == 0) {
        year_annual[i][j] = year[start_index_coun];
      } else if (j == 1) {
        year_annual[i][j] = annual_change[start_index_coun];
      }
    }
    start_index_coun++;
  }
} // I'm sure you understand that

float total_change(int year[], float annual_change[], int start_index_coun,
                   int end_index_coun) {
  double year_annual[4][2];
  int i, j, index = end_index_coun - start_index_coun;
  float sum_annual;
  array_year_annual(year, annual_change, start_index_coun, end_index_coun,
                    year_annual);

  for (i = 0; i < index; i++) {
    for (j = 1; j < 2; j++) {
      sum_annual += year_annual[i][j];
    }
  }

  return sum_annual;
}

float per_year_change(int year[], float annual_change[], int start_index_coun,
                      int end_index_coun, float sum) {
  double year_annual[4][2];
  int i, j, index = end_index_coun - start_index_coun;
  float year_passed, per_year, sum_annual = sum;
  array_year_annual(year, annual_change, start_index_coun, end_index_coun,
                    year_annual);

  year_passed = year_annual[2][0] - year_annual[0][0];

  per_year = sum / year_passed;

  if (per_year < 0) {
    return per_year * -1;
  } else {
    return per_year;
  }
}
