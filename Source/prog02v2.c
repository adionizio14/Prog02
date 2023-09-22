#include <stdio.h>
#include <stdbool.h>

void convert_args(char* arguments[], int *arg_ints, int count);

int get_total_fib_count(int *numbers, int arg_count);

void fill_total(int *total_sequence, int *arg_numbers, int count);

int remove_dupes(int *total_sequence, int count);

void print_sequence(int sequence[], int count);

void print_total(int* total_sequence, int count);

int main(int argc, char* argv[]) {
    //check that the arguments are correct, program ends if not
    int arg_numbers[argc-1];
    convert_args(argv, arg_numbers, argc-1);
    int total_fib_count = get_total_fib_count(arg_numbers, argc - 1);
    int total_sequence[total_fib_count];
    fill_total(total_sequence, arg_numbers, argc - 1);
    int new_count = remove_dupes(total_sequence, total_fib_count);
    print_total(total_sequence,new_count );

    return 0;
}

void convert_args(char* arguments[], int *arg_ints, int count){

    for(int i = 1; i < count + 1; i++){
        int num;
        sscanf(arguments[i], "%d", &num);
        arg_ints[i-1] = num;
    }

}

int get_total_fib_count(int *numbers, int arg_count){

    int total = 0;
    int diff = 1;

    for (int i = 0; i < arg_count; i++){
        if (diff == 3){
            total += numbers[i];
            diff = 0;
        }
        diff += 1;
    }

    return total;

}

void fill_total(int *total_sequence, int *arg_numbers, int count){
    int total_index = 0;
    int diff = 1;

    for (int i = 0; i < count; i++){

        if (diff == 3){

            int partial[arg_numbers[i]];
            partial[0] = arg_numbers[i-2];
            partial[1] = arg_numbers[i-1];
            for (int j = 2; j < arg_numbers[i]; j++){
                partial[j] = partial[j-1] + partial[j-2];
            }
            for (int x = 0; x < arg_numbers[i]; x++){
                total_sequence[total_index] = partial[x];
                total_index += 1;
            }
            print_sequence(partial, arg_numbers[i]);
            diff = 0;
        }
        diff += 1;
    }
}

int remove_dupes(int *total_sequence, int count){

    // javatpoint.com/remove-duplicate-elements-from-an-array-in-c
    // used this link for help with this code to remove duplicates
    for(int i = 0; i < count; i++){

        for(int j = i + 1; j < count; j++){

            if (total_sequence[i] == total_sequence[j]){

                for ( int k = j; k < count - 1; k++)
                {
                    total_sequence[k] = total_sequence [k + 1];
                }

                count -= 1;
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
/*    for (int i = 0; i < argc-1; i++){
        printf("%d, ", arg_numbers[i]);
    }
    printf("\n");*/
