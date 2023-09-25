#include <stdio.h>
#include <stdbool.h>

void convert_args(char* arguments[], int *arg_ints, int count);

int get_total_fib_count(int *numbers, int arg_count);

void fill_total(int *total_sequence, int *arg_numbers, int count);

int remove_dupes(int *total_sequence, int count);

void print_sequence(int sequence[], int count);

void print_total(int* total_sequence, int count);

bool argument_check(int* arg_numbers, int count);

int main(int argc, char* argv[]) {
    //check that the arguments are correct, program ends if not

    // initalize and convert the arguments into an iny array
    int arg_numbers[argc-1];
    convert_args(argv, arg_numbers, argc-1);

    if (argument_check(arg_numbers, argc - 1))
    {
        printf("usage: %s [F1 F2 n]+, with F2>F1>0 and n>0 all integers\n", argv[0]);
        return 0;
    }
    else {

    // get the total amount of numbers that will be produced and initialize array
    int total_fib_count = get_total_fib_count(arg_numbers, argc - 1);
    int total_sequence[total_fib_count];

    // fill the total array with every number that was produced
    fill_total(total_sequence, arg_numbers, argc - 1);

    //get the count of the array after the duplicates
    int new_count = remove_dupes(total_sequence, total_fib_count);

    //print the total array
    print_total(total_sequence,new_count );

    return 0;
    }
}

void convert_args(char* arguments[], int *arg_ints, int count){

    // method that converts the argument to int
    for(int i = 1; i < count + 1; i++){
        int num;
        sscanf(arguments[i], "%d", &num);
        arg_ints[i-1] = num;
    }

}

int get_total_fib_count(int *numbers, int arg_count){

    // method that loops through the arguments and counts how many total
    // numbers there will be
    int total = 0;
    int diff = 1;

    for (int i = 0; i < arg_count; i++){

        // since every 3rd number is the count of the two before it
        // the total would be the sum of every 3rd number
        if (diff == 3){
            total += numbers[i];
            diff = 0;
        }
        diff += 1;
    }

    return total;

}

void fill_total(int *total_sequence, int *arg_numbers, int count){

    // method that fills the total sequence array

    //initialize the index of the total sequence and every 3rd number
    int total_index = 0;
    int diff = 1;

    //loop through the total sequence array
    for (int i = 0; i < count; i++){

        //again every 3rd number is the count
        if (diff == 3){

            // create array of each partial sequence with the 3rd number
            int partial[arg_numbers[i]];

            // fill the first and second numbers with the first two
            partial[0] = arg_numbers[i-2];
            partial[1] = arg_numbers[i-1];

            // loop through the partial array calculating the fib sequence
            for (int j = 2; j < arg_numbers[i]; j++){
                partial[j] = partial[j-1] + partial[j-2];
            }

            //again loop through the same partial array but add to the
            //total sequence
            for (int x = 0; x < arg_numbers[i]; x++){
                total_sequence[total_index] = partial[x];
                total_index += 1;
            }

            //print the partial sequence array
            print_sequence(partial, arg_numbers[i]);

            //reset the variable that checks if it is the 3rd number
            diff = 0;
        }

        diff += 1;
    }
}

int remove_dupes(int *total_sequence, int count){

    // javatpoint.com/remove-duplicate-elements-from-an-array-in-c
    // used this link for help with this code to remove duplicates

    // first loop through total
    for(int i = 0; i < count; i++){

        // traverse through total array starting at whatever index
        // the first loop is on, so it does not check an index
        // that has alread been checked
        for(int j = i + 1; j < count; j++){

            // check if the numbers are the same
            if (total_sequence[i] == total_sequence[j]){

                // get rid of the element at that index
                for ( int k = j; k < count - 1; k++)
                {
                    total_sequence[k] = total_sequence [k + 1];
                }

                // shorten length of the total array
                count -= 1;

                // since the position of the indexes changed, do not increase j
                j -= 1;
            }
        }
    }

    return count;
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

void print_total(int* total_sequence, int count){

    // method that prints the total sequence list
    printf("The values encountered in the sequences are\n {");
    for (int i = 0; i < count; i++){
        if (i == (count - 1)){
            printf("%d", total_sequence[i] );
        }
        else {
            printf("%d, ", total_sequence[i] );
        }
    }
    printf("} \n");
}

bool argument_check(int* arg_numbers, int count){

    if (count % 3 != 0){
        return true;
    }

    int diff = 1;

    for (int i = 0; i < count; i++) {

        if (arg_numbers[i] < 1){
            return true;
        }
        //again every 3rd number is the count
        if (diff == 3) {
            if (arg_numbers[i-2] >= arg_numbers[i-1]){
                return true;

            }

            diff = 0;
        }
        diff += 1;
    }

    return false;

}
