#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// printAndSavePrices function goes here
void printAndSavePrices(const char* datain, const char* report) {
  char name[41];
  int sku;
  double price;
  // create two file pointers for input and output
  FILE* fprices;
  FILE* freport;

  // open files received through argument list (data in for read and reprot for write) 

  fprices = fopen(datain, "r");
  freport = fopen(report, "w");

  // check to see if both files are opened successfully 
  // if they are not, print following error message:
  // "could not open either input or output file!\n"

  if (fprices == NULL || freport == NULL) {
    printf("could not open either input or output file!\n");
  }


  // if they are opened successfully
  else {
    // print the title on the screen and save it in the report file
    printf("sku    |    Name                                  |Price\n");
    printf("-------+------------------------------------------+-------\n");

    fprintf(freport, "sku    |    Name                                  |Price\n"); // sku    |    Name                                  |Price
    fprintf(freport, "-------+------------------------------------------+-------\n"); // -------+------------------------------------------+-------

    // read from the data file as follows:
    // skuNumber,ProductName(upto 40 Chars),price<NEWLINE>
    // while the read is successfull, 
    while (fscanf(fprices, "%d,%[^,],%lf\n", &sku, name, &price) == 3){
    // print on screen and save in file as follows:
    // 6 spaces sku
    // " | "
    // product name 40 chars left justified
    // " | "
    // price 6spaces, 2 digits after decimal point
    // newline
    printf("%6d | %-40s | %6.2lf\n", sku, name, price);
    fprintf(freport, "%6d | %-40s | %6.2lf\n", sku, name, price);
    }

  }
    
  // after all is done
  // close both files only if they have been opened successlfy

  fclose(fprices);
  fclose(freport);

}

/*
screen output and report file sample:


sku    |    Name                                  |Price
-------+------------------------------------------+-------
125228 | 7up 12 pack                              |   6.49
127913 | Banana                                   |   0.44
123456 | Beefsteak Pie                            |   5.29
126458 | Blueberries                              |   3.99
124567 | Butter                                   |   4.56
123815 | Chicken Alfredo                          |   4.49
123512 | Coke 12 Pack                             |   6.69
122564 | Curry Checken                            |   4.79
125656 | Honey                                    |  12.99
123695 | Honeydew Melon                           |   5.99

How to submit:
~fardad.soleimanloo/submit 144_ws6<ENTER>

*/