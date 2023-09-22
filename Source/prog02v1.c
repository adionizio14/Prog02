#include <stdio.h>
#include <stdbool.h>

void print_sequence(int array[], int count);

void fill_sequence(int *sequence, int count);

bool argument_check(char* argv[], int num_args);

int main(int argc, char* argv[]) {
    //check that the arguments are correct, program ends if not
    if (argument_check(argv, argc))
    {
        return 0;
    }
    else {
        //initialize f1,f2 and n
        int f1, f2, count;
        //convert string to in
        sscanf(argv[1], "%d", &f1);
        sscanf(argv[2], "%d", &f2);
        sscanf(argv[3], "%d", &count);
        //fill sequence array with count and first two values
        int sequence[count];
        sequence[0] = f1;
        sequence[1] = f2;
        //fill the sequence
        fill_sequence(sequence, count);
        //print the sequence
        print_sequence(sequence, count);
    }


    return 0;
}

void fill_sequence(int *sequence, int count){
    //method that uses fib formual and places answer in sequence array
    for(int i = 2; i < count; i++){
        sequence[i] = sequence[i-1] + sequence[i-2];

    }
}

void print_sequence(int sequence[], int count){
    //method that prints the sequence in desired format
    printf("%d terms of the Fibonacci series with F1=%d and F2=%d:\n", count, sequence[0], sequence[1]);
    for(int i = 0; i < count; i++){
        if (i == (count - 1)){
            printf("F%d=%d", (i+1), sequence[i] );
        }
        else {
            printf("F%d=%d, ", (i+1), sequence[i] );
        }
    }
    printf("\n");
}

bool argument_check(char* argv[], int num_args){
    //Method that checks argument count is correct, all numbers are strictly positive integer and
    // f1 is not greater than f2
    int f1,f2,count;
    sscanf(argv[1], "%d", &f1);
    sscanf(argv[2], "%d", &f2);
    sscanf(argv[3], "%d", &count);
    if (num_args > 4 || num_args < 3 || f1 > f2 || f1 < 0 || f2 < 0 || count < 0 ){
        printf("usage: %s F1 F2 n, with F2>F1>0 and n>0 all integers.\n", argv[0]);
        return true;
    }
    else if (f1 > f2){
        printf("error: The second argument must be strictly larger than the first\n");
        return true;
    }

    return false;
}