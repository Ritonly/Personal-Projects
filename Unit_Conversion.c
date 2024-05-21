
void convert_lengths(void);
void convert_weights(void);
void length_to_metric(void);
void length_to_us(void);
void weight_to_metric(void);
void weight_to_us(void);
void get_length_to_metric(int *pFeet, double *pInches);
void calculate_length_to_metric(int feet, double inches, int *pMeters, double *pCm);
void output_to_length_to_metric(int feet, double inches, int meters, double cm);
void get_length_to_us(int *pMeters, double *pCm);
void calculate_length_to_us(int meters, double cm, int *pFeet, double *pInches);
void output_to_length_to_us(int meters, double cm, int feet, double inches);
void get_weight_to_metric(int *pPounds, double *pOunces);
void calculate_weight_to_metric(int pounds, double ounces, int *pKg,double *pGrams);
void ouput_to_weight_to_metric(int pounds, double ounces, int kg, double grams);
void get_weight_to_us(int *pKg, double *pGrams);
void calculate_weight_to_us(int kg, double grams, int *pPounds,double *pOunces);
void output_weight_to_us(int kg, double grams, int pounds, double ounces);
void clear_keyboard_buffer(void);
const double INCHES_TO_FEET = 1 / 12.0;
const double FEET_TO_METERS = 0.3048;
const double METERS_TO_CM = 100.0;
const double CM_TO_METERS = 1 / 100.0;
const double METERS_TO_FEET = 1 / 0.3048;
const double FEET_TO_INCHES = 12.0;
const double OUNCES_TO_POUNDS = 1 / 1000;
const double POUNDS_TO_KG = 1 / 2.2046;
const double KG_TO_GRAMS = 1000.0;
const double GRAMS_TO_KG = 1 / 100.0;
const double KG_TO_POUNDS = 2.2046;
const double POUNDS_TO_OUNCES = 16;
#include <math.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int noc;
    char choice;
    printf("Please choose from the following options.\n");
    printf("1) Convert lengths.\n");
    printf("2) Convert weights.\n");
    printf("0) QUIT\n");
    noc = scanf(" %c", &choice);
    clear_keyboard_buffer();
    while (choice != '1' && choice != '2' && choice != '0')
    {
        printf("Enter either 1,2,0\n");
        noc = scanf("  %c", &choice);
        clear_keyboard_buffer();
        if (choice == 0)
        {
            return 0;
        }
    }
    do
    {
        switch (choice)
        {
        case '1':
            convert_lengths();
            break;
        case '2':
            convert_weights();
            break;
        case '0':
            return 0;
        default:
            printf("Enter either 1,2,0: \n");
            noc = scanf("  %c", &choice);
            clear_keyboard_buffer();
            break;
        }
        printf("Please choose from the following options.\n");
        printf("1) Convert lengths.\n");
        printf("2) Convert weights.\n");
        printf("0) QUIT\n");
        noc = scanf("  %c", &choice);
        clear_keyboard_buffer();
    } while (choice != 0);

    return 0;
}
void convert_lengths(void)
{
    int noc;
    char choice;
    printf("You choosed to convert lengths\n");
    printf(" 1) Do you want to convert lengths from feet/inches to meters/centimeters\n");
    printf(" 2) Do you want to convert lengths from meters/centimeters to feet/inches\n");
    printf("0) I no longer want to convert lengths\n");
    noc = scanf("  %c", &choice);
    clear_keyboard_buffer();
    do
    {
        switch (choice)
        {
        case '1':
            length_to_metric();
            printf(" 1) Do you want to convert lengths from feet/inches to meters/centimeters\n");
            printf(" 2) Do you want to convert lengths from meters/centimeters to feet/inches\n");
            printf("0) I no longer want to convert lengths\n");
            noc = scanf("  %c", &choice);
            clear_keyboard_buffer();
            break;
        case '2':
            length_to_us();
            printf( " 1) Do you want to convert lengths from feet/inches to  meters/centimeters\n");
            printf( " 2) Do you want to convert lengths from meters/centimeters to  feet/inches\n");
            printf("0) I no longer want to convert lengths\n");
            noc = scanf("  %c", &choice);
            clear_keyboard_buffer();
            break;
        case '0':
            return;
            break;
        default:
            printf("Enter either 1,2,0: \n");
            noc = scanf("  %c", &choice);
            clear_keyboard_buffer();
            break;
        }
    } while (choice != 0);
}

void convert_weights(void)
{
    int noc;
    char choice;
    printf("You choosed to convert weights\n");
    printf(" 1) Do you want to convert weights from pounds/ounces to kilograms/grams\n");
    printf(" 2) Do you want to convert weights kilograms/grams to pounds/ounces\n");
    printf("0) I no longer want to convert weights\n");
    noc = scanf("  %c", &choice);
    clear_keyboard_buffer();
    do
    {
        switch (choice)
        {
        case '1':
            weight_to_metric();
            printf( " 1) Do you want to convert weights from pounds/ounces to kilograms/grams\n");
            printf(" 2) Do you want to convert weights from kilograms/grams to pounds/ounces\n");
            printf("0) I no longer want to convert weights\n");
            noc = scanf("  %c", &choice);
            clear_keyboard_buffer();
            break;
        case '2':
            weight_to_us();
            printf(" 1) Do you want to convert weights from pounds/ounces to kilograms/grams\n");
            printf(" 2) Do you want to convert weights from kilograms/grams to pounds/ounces\n");
            printf("0) I no longer want to convert weights\n");
            noc = scanf("  %c", &choice);
            clear_keyboard_buffer();
            break;
        case '0':
            return;
            break;
        default:
            printf("Enter either 1,2,0: \n");
            noc = scanf("  %c", &choice);
            clear_keyboard_buffer();
            break;
        }
    } while (choice != 0);
}
void length_to_metric(void)
{
    int feet;
    double inches;
    int meters;
    double cm;
    get_length_to_metric(&feet, &inches);
    calculate_length_to_metric(feet, inches, &meters, &cm);
    output_to_length_to_metric(feet, inches, meters, cm);
}
void get_length_to_metric(int *pFeet, double *pInches)
{
    int noc;
    printf("You chose to convert feet & inches to meters & cm\n");
    printf("Enter the lengths in feet and inches you want converted:\n");
    noc = scanf("%d  %lf", pFeet, pInches);
    while (noc != 2 || *pFeet < 0 || *pInches < 0)
    {
        printf("Enter valid numbers for feet and inches: ");
        noc = scanf("%d  %lf ", pFeet, pInches);
        clear_keyboard_buffer();
    }
}
void calculate_length_to_metric(int feet, double inches, int *pMeters,double *pCm)
{
    double total_feet = feet + inches * INCHES_TO_FEET;
    double total_meters = total_feet * FEET_TO_METERS;
    *pMeters = floor(total_meters);
    *pCm = (total_meters - *pMeters) * METERS_TO_CM;
}
void output_to_length_to_metric(int feet, double inches, int meters, double cm)
{
    printf("%d feet and %lf inches converts to %d meters and %lf cm\n ", feet,inches, meters, cm);
}

void length_to_us(void)
{
    int meters;
    double cm;
    int feet;
    double inches;
    get_length_to_us(&meters, &cm);
    calculate_length_to_us(meters, cm, &feet, &inches);
    output_to_length_to_us(meters, cm, feet, inches);
}
void get_length_to_us(int *pMeters, double *pCm)
{
    int noc;
    printf("You choose to convert feet and inches to meters and cm\n");
    printf("Please enter the meters and cm you want converted:\n");
    noc = scanf("%d %lf", pMeters, pCm);
    while (noc != 2 || *pMeters < 0 || *pCm < 0)
    {
        printf("Enter valid number for meters and cm");
        noc = scanf("%d %lf", pMeters, pCm);
        clear_keyboard_buffer();
    }
}
void calculate_length_to_us(int meters, double cm, int *pFeet,double *pInches)
{
    double total_meters = meters + cm * CM_TO_METERS;
    double total_feet = total_meters * METERS_TO_FEET;
    *pFeet = floor(total_feet);
    *pInches = (total_feet - *pFeet) * FEET_TO_INCHES;
}
void output_to_length_to_us(int meters, double cm, int feet, double inches)
{
    printf("%d meters and %lf cm converts to %d feet and %lf inches\n ", meters,cm, feet, inches);
}
void weight_to_metric(void)
{
    int kg;
    double grams;
    int pounds;
    double ounces;
    get_weight_to_metric(&pounds, &ounces);
    calculate_weight_to_metric(pounds, ounces, &kg, &grams);
    ouput_to_weight_to_metric(pounds, ounces, kg, grams);
}
void get_weight_to_metric(int *pPounds, double *pOunces)
{
    int noc;
    printf("You choose to convert pounds and ounces to kg and grams\n");
    printf("Please enter the pounds and ounces you want converted:\n");
    noc = scanf("%d %lf", pPounds, pOunces);
    while (noc != 2 || *pPounds < 0 || *pOunces < 0)
    {
        printf("Enter valid number for pounds and ounces");
        noc = scanf("%d %lf", pPounds, pOunces);
        clear_keyboard_buffer();
    }
}
void calculate_weight_to_metric(int pounds, double ounces, int *pKg, double *pGrams)
{
    double total_pounds = pounds + ounces * OUNCES_TO_POUNDS;
    double total_kg = total_pounds * POUNDS_TO_KG;
    *pKg = floor(total_kg);
    *pGrams = (total_kg - *pKg) * KG_TO_GRAMS;
}
void ouput_to_weight_to_metric(int pounds, double ounces, int kg,double grams)
{
    printf("%d pounds and %lf ounces convert to %d kg and %lf grams\n", pounds,ounces, kg, grams);
}
void weight_to_us(void)
{
    int kg;
    double grams;
    int pounds;
    double ounces;
    get_weight_to_us(&kg, &grams);
    calculate_weight_to_us(kg, grams, &pounds, &ounces);
    output_weight_to_us(kg, grams, pounds, ounces);
}
void get_weight_to_us(int *pKg, double *pGrams)
{
    int noc;
    printf("You choose to convert kg and grams to pounds and ounces\n");
    printf("Please enter the kg and grams you want converted:\n");
    noc = scanf("%d %lf", pKg, pGrams);
    while (noc != 2 || *pKg < 0 || *pGrams < 0)
    {
        printf("Enter valid numbers for kg and grams ");
        noc = scanf("%d %lf", pKg, pGrams);
        clear_keyboard_buffer();
    }
}
void calculate_weight_to_us(int kg, double grams, int *pPounds, double *pOunces)
{
    double total_kg = kg + grams * GRAMS_TO_KG;
    double total_pounds = total_kg * KG_TO_POUNDS;
    *pPounds = floor(total_pounds);
    *pOunces = (total_pounds - *pPounds) * POUNDS_TO_OUNCES;
}
void output_weight_to_us(int kg, double grams, int pounds, double ounces)
{
    printf("%d kg and %lf grams convert to %d pounds and %lf ounces\n", kg, grams,pounds, ounces);
}
void clear_keyboard_buffer(void)
{
    char c;
    scanf("%c", &c);
    while (c != '\n')
    {
        scanf("%c", &c);
    }
}
