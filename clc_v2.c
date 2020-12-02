/*
Program: Command-Line Calculator
Author: Justin Bornais
Version: 2.0 (Assignment 2)
Date: November 20, 2020
*/


// Include standard libraries.
#include <stdio.h>
#include <math.h>



float getFloat2NoZero(); // Gets the second number but rejects the value 0 (used for division and modulu).
float getFloatNoNegatives(); // Gets a number but rejects negative values (used for square roots).
float getFloatNoNegativesOrZero(); // Gets a number but rejects negative values and the value of zero (used for logarithms).
void binaryOperations(float num1);


// Main function.
int main(void) {

  // Initializing various variables.
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;
  float e = 0;
  float num1 = 0;
  float num2 = 0;
  char input[100]; // Gets the total input, including any other accidental characters entered by the user.
  char option;
  char operation;
  char var;
  int goodOperation = 1; // Used to determine if there was valid operator input in the for loop.

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

  scanf("%s", input); // This input accepts a word as input (just in case the user slips and hits another key).
  option = input[0]; // The first character of the user input will be accepted.

  // So long as the user doesn't enter 'e' or 'E' to exit, the program will continue executing.
  while(option != 'e' && option != 'E') {

    // Check which option the user picked.
    if(option == 'b' || option == 'B') {

      printf("Please enter the first number:\n");

      // Check for valid input.
      for(;;) {
        // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
        if(scanf("%f%*c", &num1)) break;
        else {
          scanf("%s", input);
          puts("Invalid input. Please try again:");
        }
      }
      
      binaryOperations(num1); // Run the binaryOperations(float) function.
    }

    else if(option == 'u' || option == 'U') {

      // Run loop just in case the user enters invalid input. Then the program will prompt the user again.
      for(;;) {
        switch(operation) {
          case 's':
          case 'S':
            num1 = getFloatNoNegatives(); // Run the function to get a positive number.
            printf("The result is:\t%f\n", sqrt(num1)); // Output the results.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          case 'l':
          case 'L':
            num1 = getFloatNoNegativesOrZero(); // Get a positive non-zero number.
            printf("The result is:\t%f\n", log10(num1)); // Output the results.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          case 'e':
          case 'E':
            printf("Please enter a number:\n");

            // Check for valid input.
            for(;;) {
              // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
              if(scanf("%f%*c", &num1)) break;
              else {
                scanf("%s", input); // Save the user input in the input variable so the scanf function can move on.
                puts("Invalid input. Please try again:");
              }
            }
            printf("The result is:\t%f\n", exp(num1)); // Output the results.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          case 'c':
          case 'C':
            printf("Please enter a number:\n");
            
            // Check for valid input.
            for(;;) {
              // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
              if(scanf("%f%*c", &num1)) break;
              else {
                scanf("%s", input);
                puts("Invalid input. Please try again:");
              }
            }
            printf("The result is:\t%f\n", ceil(num1)); // Output the results.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          case 'f':
          case 'F':
            printf("Please enter a number:\n");
            
            // Check for valid input.
            for(;;) {
              // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
              if(scanf("%f%*c", &num1)) break;
              else {
                scanf("%s", input);
                puts("Invalid input. Please try again:");
              }
            }
            printf("The result is:\t%f\n", floor(num1)); // Output the results.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
        }

        // Check if the user entered valid data. If they did, terminate the for loop.
        if(goodOperation == 0) {
          operation = ' '; // Reset the operation variable.
          goodOperation = 1; // Reset the goodOperation variable.
          break; // Terminate the loop.
        }
        
        // Prompt the user for input.
        printf("Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):\n");
        scanf("%s", input); // This input accepts a word as input (just in case the user slips and hits another key).
        operation = input[0]; // Sets the operation equal to the first character from the user input.
      }
    }
    else if(option == 'a' || option == 'a') {
      
      // Initial prompt for input.
      puts("Select one of the following items:");
      puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
      puts("U) - Unary Mathematical Operations, such as square root, and log.");
      puts("E) - Exit and back to the main menu");

      scanf("%s", input); // This input accepts a word as input (just in case the user slips and hits another key).
      option = input[0]; // Sets the option variable to the first character.

      // Loops until the user wants to exit (when they enter 'e' or 'E').
      while(option != 'e' && option != 'E') {

        // Check which option.
        if(option == 'b' || option == 'B') {
          printf("Please enter the first number or a variable name ('a' to 'e'):\n");

          // Check for valid input.
          for(int i = 0;i != 1;) {
            // Check if user entered a number or a letter.
            if  (scanf("%f", &num1)) i = 1;
            else {
              scanf( "%s" , input);
              var = input[0];
              switch(var) {
                case 'a':
                case 'A':
                  num1 = a;
                  i = 1; // Set i to 1 to indicate valid input.
                  break;
                case 'b':
                case 'B':
                  num1 = b;
                  i = 1; // Set i to 1 to indicate valid input.
                  break;
                case 'c':
                case 'C':
                  num1 = c;
                  i = 1; // Set i to 1 to indicate valid input.
                  break;
                case 'd':
                case 'D':
                  num1 = d; // Set i to 1 to indicate valid input.
                  i = 1;
                  break;
                case 'e':
                case 'E':
                  num1 = e; // Set i to 1 to indicate valid input.
                  i = 1;
                  break;
                default:
                  puts("Invalid input. Please try again:");
              }
            }
          }

          // Loop until user enters valid input.
          for(;;) {
            switch(operation) {
              case '+':
                printf("Please enter the second number or a variable name ('a' to 'e'):\n");
                // Check if user entered a number or a letter.
                for(int i = 0;i != 1;) {
                  if  (scanf("%f", &num2)) i = 1;
                  else {
                    scanf( "%s" , input);
                    var = input[0];
                    switch(var) {
                      case 'a':
                      case 'A':
                        num2 = a;
                        i = 1;
                        break;
                      case 'b':
                      case 'B':
                        num2 = b;
                        i = 1;
                        break;
                      case 'c':
                      case 'C':
                        num2 = c;
                        i = 1;
                        break;
                      case 'd':
                      case 'D':
                        num2 = d;
                        i = 1;
                        break;
                      case 'e':
                      case 'E':
                        num2 = e;
                        i = 1;
                        break;
                      default:
                        puts("Invalid input. Please try again:"); // Invalid input.
                    }
                  }
                }
                printf("The result is:\t%f\n", (num1 + num2)); // Output the results.
                goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
                break;
              
              case '-':
                printf("Please enter the second number or a variable name ('a' to 'e'):\n");
                // Check if user entered a number or a letter.
                for(int i = 0;i != 1;) {
                  if  (scanf("%f", &num2)) i = 1;
                  else {
                    scanf( "%s" , input);
                    var = input[0];
                    switch(var) {
                      case 'a':
                      case 'A':
                        num2 = a;
                        i = 1;
                        break;
                      case 'b':
                      case 'B':
                        num2 = b;
                        i = 1;
                        break;
                      case 'c':
                      case 'C':
                        num2 = c;
                        i = 1;
                        break;
                      case 'd':
                      case 'D':
                        num2 = d;
                        i = 1;
                        break;
                      case 'e':
                      case 'E':
                        num2 = e;
                        i = 1;
                        break;
                      default:
                        puts("Invalid input. Please try again:"); // Invalid input.
                    }
                  }
                }
                printf("The result is:\t%f\n", (num1 - num2)); // Output the results.
                goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
                break;
              
              case '*':
                printf("Please enter the second number or a variable name ('a' to 'e'):\n");

                for(int i = 0;i != 1;) {
                  // Check if user entered a number or a letter.
                  if  (scanf("%f", &num2)) i = 1;
                  else {
                    scanf( "%s" , input);
                    var = input[0];
                    switch(var) {
                      case 'a':
                      case 'A':
                        num2 = a;
                        i = 1;
                        break;
                      case 'b':
                      case 'B':
                        num2 = b;
                        i = 1;
                        break;
                      case 'c':
                      case 'C':
                        num2 = c;
                        i = 1;
                        break;
                      case 'd':
                      case 'D':
                        num2 = d;
                        i = 1;
                        break;
                      case 'e':
                      case 'E':
                        num2 = e;
                        i = 1;
                        break;
                      default:
                        puts("Invalid input. Please try again:"); // Invalid input.
                    }
                  }
                }

                printf("The result is:\t%f\n", (num1 * num2)); // Output the results.
                goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
                break;
              
              case '/':
                puts("Please enter the second number or a variable name ('a' to 'e') (must be non-zero):");

                for(;;) {
                  // Check if user entered a number or a letter.
                  if  (scanf("%f", &num2));
                  else {
                    scanf( "%s" , input);
                    var = input[0];
                    switch(var) {
                      case 'a':
                      case 'A':
                        num2 = a;
                        break;
                      case 'b':
                      case 'B':
                        num2 = b;
                        break;
                      case 'c':
                      case 'C':
                        num2 = c;
                        break;
                      case 'd':
                      case 'D':
                        num2 = d;
                        break;
                      case 'e':
                      case 'E':
                        num2 = e;
                        break;
                      default:
                        puts("Invalid input. Please try again:"); // Invalid input.
                        var = ' '; // Empty the var variable to 
                    }
                  }

                  // Check that the number is non-zero.
                  if(num2 != 0) {
                    break; // Terminate the loop.
                  }
                  else {
                    if(var != ' ') // If the variable option is not empty, then the user either entered a number or a valid variable.
                      puts("The number cannot be 0. Please try again.");
                  }
                }

                printf("The result is:\t%f\n", (num1 / num2)); // Output the results.
                goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
                break;
              
              case '%':

                puts("Please enter the second number or a variable name ('a' to 'e') (must be non-zero):");
                for(;;) {
                  // Check if user entered a number or a letter.
                  if  (scanf("%f", &num2));
                  else {
                    scanf( "%s" , input);
                    var = input[0];
                    switch(var) {
                      case 'a':
                      case 'A':
                        num2 = a;
                        break;
                      case 'b':
                      case 'B':
                        num2 = b;
                        break;
                      case 'c':
                      case 'C':
                        num2 = c;
                        break;
                      case 'd':
                      case 'D':
                        num2 = d;
                        break;
                      case 'e':
                      case 'E':
                        num2 = e;
                        break;
                      default:
                        puts("Invalid input. Please try again:");
                        var = ' ';
                    }
                  }

                  // Check that the number is non-zero.
                  if(num2 != 0) {
                    break;
                  }
                  else {
                    if(var != ' ') // If the var variable is not empty, then the user entered a number or a valid variable.
                      puts("The number cannot be 0. Please try again.");
                  }
                }
                printf("The result is:\t%f\n", fmod(num1, num2)); // fmod is modulu with floats.
                goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
                break;
              
              case 'p':
              case 'P':
                printf("Please enter the second number or a variable name ('a' to 'e'):\n");
                // Check if user entered a number or a letter.
                for(int i = 0;i != 1;) {
                  if  (scanf("%f", &num2)) i = 1;
                  else {
                    scanf( "%s" , input);
                    var = input[0];
                    switch(var) {
                      case 'a':
                      case 'A':
                        num2 = a;
                        i = 1;
                        break;
                      case 'b':
                      case 'B':
                        num2 = b;
                        i = 1;
                        break;
                      case 'c':
                      case 'C':
                        num2 = c;
                        i = 1;
                        break;
                      case 'd':
                      case 'D':
                        num2 = d;
                        i = 1;
                        break;
                      case 'e':
                      case 'E':
                        num2 = e;
                        i = 1;
                        break;
                      default:
                        puts("Invalid input. Please try again:");
                    }
                  }
                }

                printf("The result is:\t%f\n", pow(num1, num2)); // Output the results.
                goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
                break;
              case 'x':
              case 'X':
                printf("Please enter the second number or a variable name ('a' to 'e'):\n");
                // Check if user entered a number or a letter.
                for(int i = 0;i != 1;) {
                  if  (scanf("%f", &num2)) i = 1;
                  else {
                    scanf( "%s" , input);
                    var = input[0];
                    switch(var) {
                      case 'a':
                      case 'A':
                        num2 = a;
                        i = 1;
                        break;
                      case 'b':
                      case 'B':
                        num2 = b;
                        i = 1;
                        break;
                      case 'c':
                      case 'C':
                        num2 = c;
                        i = 1;
                        break;
                      case 'd':
                      case 'D':
                        num2 = d;
                        i = 1;
                        break;
                      case 'e':
                      case 'E':
                        num2 = e;
                        i = 1;
                        break;
                      default:
                        puts("Invalid input. Please try again:");
                    }
                  }
                }

                // Check which number is greater.
                if(num1 >= num2) {
                  printf("The result is:\t%f\n", num1); // Output num1.
                }
                else {
                  printf("The result is:\t%f\n", num2); // Output num2.
                }
                goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
                break;
              
              case 'i':
              case 'I':
                printf("Please enter the second number or a variable name ('a' to 'e'):\n");
                // Check if user entered a number or a letter.
                for(int i = 0;i != 1;) {
                  if  (scanf("%f", &num2)) i = 1;
                  else {
                    scanf( "%s" , input);
                    var = input[0];
                    switch(var) {
                      case 'a':
                      case 'A':
                        num2 = a;
                        i = 1;
                        break;
                      case 'b':
                      case 'B':
                        num2 = b;
                        i = 1;
                        break;
                      case 'c':
                      case 'C':
                        num2 = c;
                        i = 1;
                        break;
                      case 'd':
                      case 'D':
                        num2 = d;
                        i = 1;
                        break;
                      case 'e':
                      case 'E':
                        num2 = e;
                        i = 1;
                        break;
                      default:
                        puts("Invalid input. Please try again:");
                    }
                  }
                }

                // Check which number is lesser.
                if(num1 <= num2) {
                  printf("The result is:\t%f\n", num1); // Output num1.
                }
                else {
                  printf("The result is:\t%f\n", num2); // Output num2.
                }
                goodOperation = 0;// Set goodOperation to 0 to show the program can move on and the for loop can terminate.
                break;
              default:
                break;
            }

            // If the user entered valid data, then terminate the loop.
            if(goodOperation == 0) {
              goodOperation = 1; // Reset the goodOperation variable.
              operation = ' '; // Reset the operation variable.
              break; // Terminate the loop.
            }

            // Prompt the user for input.
            puts("Please enter the operation ( + , - , * , / , % , P (for power) , X (for maximum) ):");
            scanf("%s", input); // This input accepts a word as input (just in case the user slips and hits another key).
            operation = input[0]; // Sets the operation variable to the first character inputted.
          }
        }

        else if(option == 'u' || option == 'U') {

          // Loop until the user enters valid data.
          for(;;) {
            switch(operation) {
              case 's':
              case 'S':
                puts("Please enter a number or a variable name ('a' to 'e') (must be a positive value):");
                for(;;) {
                  // Check if user entered a number or a letter.
                  if  (scanf("%f", &num1));
                  else {
                    scanf( "%s" , input);
                    var = input[0];
                    switch(var) {
                      case 'a':
                      case 'A':
                        num1 = a;
                        break;
                      case 'b':
                      case 'B':
                        num1 = b;
                        break;
                      case 'c':
                      case 'C':
                        num1 = c;
                        break;
                      case 'd':
                      case 'D':
                        num1 = d;
                        break;
                      case 'e':
                      case 'E':
                        num1 = e;
                        break;
                      default:
                        puts("Invalid input. Please try again:");
                        var = ' ';
                    }
                  }

                  // Check if the number is positive.
                  if(num1 >= 0) {
                    break;
                  }
                  else {
                    if(var != ' ') // If the var variable isn't empty, then the user entered a number or a valid variable.
                      puts("The number cannot be negative. Please try again.");
                  }
                }

                printf("The result is:\t%f\n", sqrt(num1)); // Output the results.
                goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
                break;
              case 'l':
              case 'L':
                puts("Please enter a number or a variable name ('a' to 'e') (must be a positive value greater than 0):");
                for(;;) {
                  // Check if user entered a number or a letter.
                  if  (scanf("%f", &num1));
                  else {
                    scanf( "%s" , input);
                    var = input[0];
                    switch(var) {
                      case 'a':
                      case 'A':
                        num1 = a;
                        break;
                      case 'b':
                      case 'B':
                        num1 = b;
                        break;
                      case 'c':
                      case 'C':
                        num1 = c;
                        break;
                      case 'd':
                      case 'D':
                        num1 = d;
                        break;
                      case 'e':
                      case 'E':
                        num1 = e;
                        break;
                      default:
                        puts("Invalid input. Please try again:"); // Invalid input.
                        var = ' ';
                    }
                  }

                  // Check if the number is positive and non-zero.
                  if(num1 > 0) {
                    break;
                  }
                  else {
                    if(var != ' ') // If the var variable isn't negative, then the user entered either a number or a valid variable.
                      puts("The number cannot be negative or zero. Please try again.");
                  }
                }

                printf("The result is:\t%f\n", log10(num1)); // Output the results.
                goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
                break;
              case 'e':
              case 'E':
                puts("Please enter a number or a variable name ('a' to 'e'):");

                for(int i = 0;i != 1;) {
                  // Check if user entered a number or a letter.
                  if  (scanf("%f", &num1)) i = 1;
                  else {
                    scanf( "%s" , input);
                    var = input[0];
                    switch(var) {
                      case 'a':
                      case 'A':
                        num1 = a;
                        i = 1;
                        break;
                      case 'b':
                      case 'B':
                        num1 = b;
                        i = 1;
                        break;
                      case 'c':
                      case 'C':
                        num1 = c;
                        i = 1;
                        break;
                      case 'd':
                      case 'D':
                        num1 = d;
                        i = 1;
                        break;
                      case 'e':
                      case 'E':
                        num1 = e;
                        i = 1;
                        break;
                      default:
                        puts("Invalid input. Please try again:"); // Invalid input.
                    }
                  }
                }

                printf("The result is:\t%f\n", exp(num1)); // Output the results.
                goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
                break;
              case 'c':
              case 'C':
                puts("Please enter a number or a variable name ('a' to 'e'):");

                for(int i = 0;i != 1;) {
                  // Check if user entered a number or a letter.
                  if  (scanf("%f", &num1)) i = 1;
                  else {
                    scanf( "%s" , input);
                    var = input[0];
                    switch(var) {
                      case 'a':
                      case 'A':
                        num1 = a;
                        i = 1;
                        break;
                      case 'b':
                      case 'B':
                        num1 = b;
                        i = 1;
                        break;
                      case 'c':
                      case 'C':
                        num1 = c;
                        i = 1;
                        break;
                      case 'd':
                      case 'D':
                        num1 = d;
                        i = 1;
                        break;
                      case 'e':
                      case 'E':
                        num1 = e;
                        i = 1;
                        break;
                      default:
                        puts("Invalid input. Please try again:"); // Invalid data.
                    }
                  }
                }
                printf("The result is:\t%f\n", ceil(num1)); // Output the results.
                goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
                break;
              case 'f':
              case 'F':
                puts("Please enter a number or a variable name ('a' to 'e'):");

                for(int i = 0;i != 1;) {
                  // Check if user entered a number or a letter.
                  if  (scanf("%f", &num1)) i = 1;
                  else {
                    scanf( "%s" , input);
                    var = input[0];
                    switch(var) {
                      case 'a':
                      case 'A':
                        num1 = a;
                        i = 1;
                        break;
                      case 'b':
                      case 'B':
                        num1 = b;
                        i = 1;
                        break;
                      case 'c':
                      case 'C':
                        num1 = c;
                        i = 1;
                        break;
                      case 'd':
                      case 'D':
                        num1 = d;
                        i = 1;
                        break;
                      case 'e':
                      case 'E':
                        num1 = e;
                        i = 1;
                        break;
                      default:
                        puts("Invalid input. Please try again:"); // Invalid data.
                    }
                  }
                }
                printf("The result is:\t%f\n", floor(num1)); // Output the results.
                goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
                break;
            }

            // Check if the user entered valid input.
            if(goodOperation == 0) {
              goodOperation = 1; // Reset the goodOperation variable.
              operation = ' '; // Reset the operation variable.
              break; // Terminate the loop.
            }
            
            // Prompt user for input.
            printf("Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):\n");
            scanf("%s", input); // This input accepts a word as input (just in case the user slips and hits another key).
            operation = input[0]; // Sets the operation equal to the first character from the user input.
          }
        }

        puts("Please select your option ( B (Binary operation), U (Unary operation), E (Exit and back to the main menu)):");
        scanf("%s", input); // This input accepts a word as input (just in case the user slips and hits another key).
        option = input[0];
      }
    }
    else if(option == 'v' || option == 'v') {

      // Loops just in case the user enters invalid input.
      for(;;) {
        switch(var) {
          case 'a':
          case 'A':
            puts("Please enter a number:");

            // Check for valid input.
            for(;;) {
              // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
              if(scanf("%f%*c", &a)) break;
              else {
                scanf("%s", input);
                puts("Invalid input. Please try again:");
              }
            }

            printf("Variable a is set to:\t%f\n", a);
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          case 'b':
          case 'B':
            puts("Please enter a number:");
            
            // Check for valid input.
            for(;;) {
              // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
              if(scanf("%f%*c", &b)) break;
              else {
                scanf("%s", input);
                puts("Invalid input. Please try again:");
              }
            }

            printf("Variable b is set to:\t%f\n", b);
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          case 'c':
          case 'C':
            puts("Please enter a number:");
            
            // Check for valid input.
            for(;;) {
              // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
              if(scanf("%f%*c", &c)) break;
              else {
                scanf("%s", input);
                puts("Invalid input. Please try again:");
              }
            }

            printf("Variable c is set to:\t%f\n", c);
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          case 'd':
          case 'D':
            puts("Please enter a number:");
            
            // Check for valid input.
            for(;;) {
              // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
              if(scanf("%f%*c", &d)) break;
              else {
                scanf("%s", input);
                puts("Invalid input. Please try again:");
              }
            }

            printf("Variable d is set to:\t%f\n", d);
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          case 'e':
          case 'E':
            puts("Please enter a number:");

            // Check for valid input.
            for(;;) {
              // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
              if(scanf("%f%*c", &e)) break;
              else {
                scanf("%s", input);
                puts("Invalid input. Please try again:");
              }
            }

            printf("Variable e is set to:\t%f\n", e);
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
        }

        // Check if the user entered valid input. If so, then terminate the loop.
        if(goodOperation == 0) {
          goodOperation = 1; // Reset the goodOperation variable.
          var = ' '; // Reset the var variable.
          break; // Terminate the loop.
        }

        // Prompt the user for input.
        puts("Please enter the name of the variable ( A single character between 'a' to 'e' ):");
        scanf("%s", input); // Save the user input as a word (just in case they slip their fingers).
        var = input[0]; // Set the var option to the first character only.
      }
    }

    option = ' '; // Reset the option variable.
    
    printf("Please select your option ( B (Binary operation), U (Unary operation) , A (Advanced), V (Variables), E (Exit))\n");

    scanf("%s", input); // Accepts a word as input (just in case the user slips and hits another key).
    option = input[0]; // Saves the option as the first character.
  }

  // Say goodbye to the user!
  puts("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!");
  return 0; // The main function terminated with no errors.
}


// Function to perform basic binary operations.
void binaryOperations(float num1) {
  // Initialize necessary variables.
  char input[100];
  char operation;
  float num2;
  int goodOperation = 1; // Used to determine if there was valid operator input in the for loop.

  // Loops until valid data is entered.
  for(;;) {
    switch(operation) {
      case '+':
        printf("Please enter the second number:\n");

        // Check for valid input.
        for(;;) {
          // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
          if(scanf("%f%*c", &num2)) break;
          else {
            scanf("%s", input);
            puts("Invalid input. Please try again:");
          }
        }
        printf("The result is:\t%f\n", (num1 + num2)); // Output the results.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      
      case '-':
        printf("Please enter the second number:\n");
        
        // Check for valid input.
        for(;;) {
          // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
          if(scanf("%f%*c", &num2)) break;
          else {
            scanf("%s", input);
            puts("Invalid input. Please try again:");
          }
        }
        printf("The result is:\t%f\n", (num1 - num2)); // Output the results.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      
      case '*':
        printf("Please enter the second number:\n");
        
        // Check for valid input.
        for(;;) {
          // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
          if(scanf("%f%*c", &num2)) break;
          else {
            scanf("%s", input);
            puts("Invalid input. Please try again:");
          }
        }

        printf("The result is:\t%f\n", (num1 * num2)); // Output the results.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      
      case '/':
        num2 = getFloat2NoZero(); // Get a non-zero number.
        printf("The result is:\t%f\n", (num1 / num2)); // Output the results.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      
      case '%':
        num2 = getFloat2NoZero(); // Get a non-zero number.
        printf("The result is:\t%f\n", fmod(num1, num2)); // fmod is modulu with floats.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      
      case 'p':
      case 'P':
        printf("Please enter the second number:\n");
        
        // Check for valid input.
        for(;;) {
          // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
          if(scanf("%f%*c", &num2)) break;
          else {
            scanf("%s", input);
            puts("Invalid input. Please try again:");
          }
        }

        printf("The result is:\t%f\n", pow(num1, num2)); // Output the results.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      case 'x':
      case 'X':
        printf("Please enter the second number:\n");
        
        // Check for valid input.
        for(;;) {
          // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
          if(scanf("%f%*c", &num2)) break;
          else {
            scanf("%s", input);
            puts("Invalid input. Please try again:");
          }
        }

        // Check which number is greater.
        if(num1 >= num2) {
          printf("The result is:\t%f\n", num1); // Output num1.
        }
        else {
          printf("The result is:\t%f\n", num2); // Output num2.
        }
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      
      case 'i':
      case 'I':
        printf("Please enter the second number:\n");
        
        // Check for valid input.
        for(;;) {
          // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
          if(scanf("%f%*c", &num2)) break;
          else {
            scanf("%s", input);
            puts("Invalid input. Please try again:");
          }
        }

        // Check which number is smaller.
        if(num1 <= num2) {
          printf("The result is:\t%f\n", num1); // Output num1.
        }
        else {
          printf("The result is:\t%f\n", num2); // Output num2.
        }
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      default:
        break;
    }

    // Check if the user entered valid data. If so, terminate the loop, thus terminating the function.
    if(goodOperation == 0) {
      break;
    }

    // Prompt the user for input.
    printf("Please enter the operation ( + , - , * , / , %% , P (for power) , X (for maximum) , I (for minimum) ):\n");
    scanf("%s", input); // This input accepts a word as input (just in case the user slips and hits another key).
    operation = input[0]; // Takes the first character of the user input as the option.
  }

  operation = 0; // Reset the operation variable for future uses.
}

// Gets the second number but rejects the value 0 (used for division and modulu).
float getFloat2NoZero() {

  // Initialize necessary variables.
  float num2;
  char input[100];
  int badInput = 0;

  printf("Please enter the second number (non-zero):\n");
  
  // Check for valid input.
  for(;;) {

    badInput = 0;
    // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
    if(scanf("%f", &num2));
    else {
      scanf("%s", input);
      puts("Invalid input. Please try again:");
      badInput = 1; // Set to 1 to show the user entered invalid input.
    }

    // Checks if the number is valid or not. Ignored if the user entered invalid input (where badInput = 1)
    if(num2 == 0 && badInput == 0) {
      puts("Invalid number. Value must be greater than 0. Try again:");
    }
    // Checks if the user entered a valid number.
    else if(num2 != 0 && badInput == 0) {
      break; // The number is valid so the loop may terminate.
    }
  }

  return num2;
}

// Gets a number but rejects negative values (used for square roots).
float getFloatNoNegatives() {

  // Initialize necessary variables.
  float num;
  char input[100];
  int badInput = 0;
  printf("Please enter a positive number:\n");

  // Check for valid input.
  for(;;) {

    badInput = 0;
    // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
    if(scanf("%f", &num));
    else {
      scanf("%s", input);
      puts("Invalid input. Please try again:");
      badInput = 1; // Set to 1 to show the user entered invalid input.
    }

    // Checks if the number is valid or not. Ignored if the user entered invalid input (where badInput = 1)
    if(num < 0 && badInput == 0) {
      puts("Invalid number. Value must be positive. Try again:");
    }
    // Checks if the user entered a valid number.
    else if(num >= 0 && badInput == 0) {
      break; // The number is valid so the loop may terminate.
    }
  }

  return num;
}

// Gets a number but rejects negative values and the value of zero (used for logarithms).
float getFloatNoNegativesOrZero() {

  // Initialize necessary variables.
  float num;
  char input[100];
  int badInput = 0;
  
  printf("Please enter a positive non-zero number:\n");
  
  // Check for valid input.
  for(;;) {

    badInput = 0;
    // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
    if(scanf("%f", &num));
    else {
      scanf("%s", input);
      puts("Invalid input. Please try again:");
      badInput = 1; // Set to 1 to show the user entered invalid input.
    }

    // Checks if the number is valid or not. Ignored if the user entered invalid input (where badInput = 1)
    if(num <= 0 && badInput == 0) {
      puts("Invalid number. Value must be greater than 0. Try again:");
    }
    // Checks if the user entered a valid number.
    else if(num > 0 && badInput == 0) {
      break; // The number is valid so the loop may terminate.
    }
  }

  return num;
}