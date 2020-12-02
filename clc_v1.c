/*
Command-Line Calculator
Developer: Justin Bornais
Version: 1
Date: October 19th, 2020
*/

// Include required standard libraries.
#include <stdio.h>

// Create the main function
int main(void) {

  // Using C commands display welcome messages to the user
  printf("Welcome to my Command-Line Calculator (CLC)\n");
  printf("Developer: Justin Bornais\n");
  printf("Version: 1\n");
  printf("Date: October 19th, 2020\n");
  printf("-----------------------------\n\n");

  // Display the list of options and show a message to the user to select an option
  printf("Select one of the following items:\n");
  printf("B) - Binary Mathematical Operations, such as addition and subtraction.\n");
  printf("U) - Unary Mathematical Operations, such as square root, and log.\n");
  printf("A) - Advances Mathematical Operations, using variables, arrays.\n");
  printf("V) – Define variables and assign them values.\n");
  printf("E) - Exit\n");


  /*
  char selection;
  char operation;
  int num1;
  int num2;

  loop // Loop until the user enters E for exit.
    printf("Please select your option ( B , U , A , E , V )\n");
    read(selection);
    if selection == 'B' then
      printf("Please enter the first number:\n");
      read(num1);

      loop: // If the user makes a typo and does not enter a valid input, then the program will loop back and force the user to enter a new operation.
        printf("Please enter the operation ( + , - , * , / ):\n");
        read(operation);
        if operation == '+' then
          printf("Please enter the second number:\n");
          read(num2);
          display(num1 + num2);
          exit loop;
        else if operation == '-' then
          printf("Please enter the second number:\n");
          read(num2);
          display(num1 - num2);
          exit loop;
        else if operation == '*' then
          printf("Please enter the second number:\n");
          read(num2);
          display(num1 * num2);
          exit loop;
        else if operation == '/' then
          printf("Please enter the second number:\n");
          read(num2)
          // This loop is so the user doesn't enter 0 for division (x/0 = undefined).
          while num2 == 0:
            printf("The second number can't equal 0 for division. Please try again.");
            read(num2);
          end while
          display(num1 / num2);
          exit loop;
        else
          printf("This is not a mathematical operation. Try again.\n");
        end if
      end loop
    end if
    else if selection == 'E' then
      exit loop
    else if selection == 'U' then
      printf("The calculator is currently unable to perform said category. Please try again.\n");
    else if selection == 'A' then
      printf("The calculator is currently unable to perform said category. Please try again.\n");
    else if selection == 'V' then
      printf("The calculator is currently unable to perform said category. Please try again.\n");
    else
      printf("This is not a valid input. Please try again.\n");
    end if
  end loop
  read selection
  */
  return 0;
}