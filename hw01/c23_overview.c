#include <stdio.h>

int main(void)
{
    //stores basic information about the c23 standerds
    int release_year = 2024;
    int programing_age = 50;

    //introduces c23
    printf("C23 Overview\n");
    printf("C23 is a modern version of the programing language c.\n");
    printf("The C23 standard was published in %d.\n", release_year);
    //Explain why C is still important.
    printf("\nwhy is C still important?\n");
    printf("C is important becese it provides not only speed but efficency and direct control over hardware\n");
    printf("It is widely used in operatig systems, embeded systems, ad other performance-critical software. \n");
    //Mention some C23 features
    printf("\nSome C23 featers include improved langage syntax, new keywords, and updated library support.\n");
    printf("C23 also continues to improve the language while maintaining compadibility with much of the existing C code\n");
    //Explain the purpose of the program
    printf("\nC has been used for more than %d years and remaons relevant in modern programing.\n",
        programing_age);
    return 0;
}
