/*
Program: Command-Line Calculator
Author: Justin Bornais
Version: 3.0 (Assignment 3)
Date: December 2, 2020
*/


// Include standard libraries.
#include <stdio.h>
#include <math.h>

float a = 0;
float b = 0;
float c = 0;
float d = 0;
float e = 0;
float num1 = 0;
float num2 = 0;
const int HISTORY_LENGTH = 100;
float history[HISTORY_LENGTH];
unsigned int historyCount;

float getFloat2NoZero(); // Gets the second number but rejects the value 0 (used for division and modulu).
float getFloatNoNegatives(); // Gets a number but rejects negative values (used for square roots).
float getFloatNoNegativesOrZero(); // Gets a number but rejects negative values and the value of zero (used for logarithms).
float getFloat(); // Used for simply getting a number and validating the user's input.
void memoryOverflow(); // Used when there are more than HISTORY_LENGTH and the memory array runs out of memory.
void viewMemory(); // Used to view the memory values.
void clearMemory(); // Used to clear all memory.
char getChoice(); // Used to get the choice of operation from the user.
float getNumOrVar(); // Get number or variable for the Advanced option.

void binaryOperations(); // Used for performing binary operations.
void unaryOperations(); // Used for performing unary operations.
void advancedOperations(); // Used for performing advanced operations.
void setVar(); // Used for setting variable values.



// Main function.
int main(void) {

  // Initializing various variables.
  char input[100]; // Gets the total input, including any other accidental characters entered by the user.
  char option;
  char operation;
  char var;
  int goodOperation = 1; // Used to determine if there was valid operator input in the for loop.

  // Using C commands display welcome messages to the user
  puts("Welcome to my Command-Line Calculator (CLC)");
  puts("Developer: Justin Bornais");
  puts("Version: 3.0");
  puts("Date: December 2nd, 2020");
  puts("-----------------------------\n");

  option = getChoice();

  // So long as the user doesn't enter 'e' or 'E' to exit, the program will continue executing.
  while(option != 'E') {

    // Check which option the user picked.
    if(option == 'B') {
      binaryOperations(); // Run the binaryOperations() function.
    }

    else if(option == 'U') {
      unaryOperations(); // Run unary operations.
    }
    else if(option == 'A') {
      advancedOperations(); // Perform advanced operations.
    }
    else if(option == 'V') {
      setVar(); // Set variables.
    }
    else if(option == 'M') {
      viewMemory(); // View memory.
    }
    else if(option == 'R') {
      clearMemory(); // Clear memory.
    }

    
    option = getChoice(); // Get the user's choice.
  }

  // Say goodbye to the user!
  puts("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!");
  return 0; // The main function terminated with no errors.
}


// Function to perform basic binary operations.
void binaryOperations() {
  // Initialize necessary variables.
  char input[100];
  char operation;
  int goodOperation = 1; // Used to determine if there was valid operator input in the for loop.
  float result = 0;

  // Get the first number.
  printf("Please enter the first number:\n");
  num1 = getFloat();
  

  // Loops until valid data is entered.
  for(;;) {
    switch(operation) {
      case '+':
        printf("Please enter the second number:\n");
        num2 = getFloat();

        result = num1 + num2; // Save the results.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      
      case '-':
        printf("Please enter the second number:\n");
        num2 = getFloat();

        result = num1 - num2; // Save the results.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      
      case '*':
        printf("Please enter the second number:\n");
        num2 = getFloat();

        result = num1 * num2; // Save the results.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      
      case '/':
        num2 = getFloat2NoZero(); // Get a non-zero number.
        result = num1 / num2; // Save the results.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      
      case '%':
        num2 = getFloat2NoZero(); // Get a non-zero number.
        result = fmod(num1, num2); // fmod is modulu with floats.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      
      case 'p':
      case 'P':
        printf("Please enter the second number:\n");
        num2 = getFloat();

        result = pow(num1, num2); // Save the results.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      case 'x':
      case 'X':
        printf("Please enter the second number:\n");
        num2 = getFloat();

        // Check which number is greater.
        if(num1 >= num2) {
          result = num1; // Save num1.
        }
        else {
          result = num2; // Save num2.
        }
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      
      case 'i':
      case 'I':
        printf("Please enter the second number:\n");
        num2 = getFloat();

        // Check which number is smaller.
        if(num1 <= num2) {
          result = num1; // Save num1.
        }
        else {
          result = num2; // Save num2.
        }
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      default:
        break;
    }

    // Check if the user entered valid data. If so, terminate the loop, thus terminating the function.
    if(goodOperation == 0) {
      printf("The result is:\t%f\n", result);

      // Check if the memory ran out.
      if(historyCount == HISTORY_LENGTH) {
        memoryOverflow();
      }

      // Save the result in memory.
      history[historyCount] = result;
      historyCount++;
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

float getFloat() {
  char input[100];
  float num;
  // Check for valid input.
  for(;;) {
    // If the user entered a valid number (ignoring any extra characters entered afterwards), exit the loop and proceed with the program.
    if(scanf("%f%*c", &num)) break;
    else {
      scanf("%s", input); // Store the invalid input.
      puts("Invalid input. Please try again:"); // Display an error message.
    }
  }

  return num;
}

char getChoice() {
  
  // Initialize necessary variables.
  char input[100];
  char choice;
  // Display the list of options and show a message to the user to select an option
  puts("\nSelect one of the following items:");
  puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
  puts("U) - Unary Mathematical Operations, such as square root, and log.");
  puts("A) - Advanced Mathematical Operations, using variables, arrays.");
  puts("V) – Define variables and assign them values.");
  puts("M) - See the memory.");
  puts("R) - Clear the memory.");
  puts("E) - Exit");

  scanf("%s", input); // This input accepts a word as input (just in case the user slips and hits another key).
  choice = input[0]; // Takes the first character of the user input as the option.

  // Loop just in case there is invalid input.
  for(;;) {

    // Check if valid input was received from the user.
    switch(choice) {
      case 'b':
      case 'B':
        return 'B';
      case 'u':
      case 'U':
        return 'U';
      case 'a':
      case 'A':
        return 'A';
      case 'v':
      case 'V':
        return 'V';
      case 'm':
      case 'M':
        return 'M';
      case 'r':
      case 'R':
        return 'R';
      case 'e':
      case 'E':
        return 'E';
    }
    puts("Invalid input. Please try again.");
    scanf("%s", input); // This input accepts a word as input (just in case the user slips and hits another key).
    choice = input[0]; // Takes the first character of the user input as the option.
  }
}

void memoryOverflow() {

  // Run loop throughout the history array.
  for(int i = 1;i < HISTORY_LENGTH;i++) {
    history[i - 1] = history[i]; // Push back each value of the array by 1 index value.
  }
  
  historyCount--; // Reduce the count by 1.
}

float getNumOrVar() {

  // Initialize necessary variables.
  char input[100];
  char var = ' ';
  float num;

  // Check for valid input.
  for(;;) {
    // Check if user entered a number or a letter.
    if  (scanf("%f", &num)) return num;
    else {
      scanf( "%s" , input);
      var = input[0];
      switch(var) {
        case 'a':
        case 'A':
          return a;
          break;
        case 'b':
        case 'B':
          return b;
          break;
        case 'c':
        case 'C':
          return c;
          break;
        case 'd':
        case 'D':
          return d;
          break;
        case 'e':
        case 'E':
          return e;
          break;
      }

      puts("Invalid input. Please try again.");
    }
  }
}

void advancedOperations() {
  
  char input[100];
  char option;
  char operation;
  char var;
  int goodOperation = 1;
  float result;


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

      num1 = getNumOrVar();
      // Loop until user enters valid input.
      for(;;) {
        switch(operation) {
          case '+':
            printf("Please enter the second number or a variable name ('a' to 'e'):\n");
            num2 = getNumOrVar();
            result = num1 + num2; // Save the results.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          
          case '-':
            printf("Please enter the second number or a variable name ('a' to 'e'):\n");
            num2 = getNumOrVar();
            result = num1 - num2; // Save the results.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          
          case '*':
            printf("Please enter the second number or a variable name ('a' to 'e'):\n");
            num2 = getNumOrVar();
            result = num1 * num2; // Save the results.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          
          case '/':
            puts("Please enter the second number or a variable name ('a' to 'e') (must be non-zero):");

            for(;;) {
              num2 = getNumOrVar();

              // Check that the number is non-zero.
              if(num2 != 0) {
                break; // Terminate the loop.
              }
              else {
                if(var != ' ') // If the variable option is not empty, then the user either entered a number or a valid variable.
                  puts("The number cannot be 0. Please try again.");
              }
            }

            result = num1 / num2; // Save the results.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          
          case '%':

            puts("Please enter the second number or a variable name ('a' to 'e') (must be non-zero):");
            for(;;) {
              num2 = getNumOrVar();

              // Check that the number is non-zero.
              if(num2 != 0) {
                break;
              }
              else {
                if(var != ' ') // If the var variable is not empty, then the user entered a number or a valid variable.
                  puts("The number cannot be 0. Please try again.");
              }
            }
            result = fmod(num1, num2); // fmod is modulu with floats.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          
          case 'p':
          case 'P':
            printf("Please enter the second number or a variable name ('a' to 'e'):\n");
            num2 = getNumOrVar();
            result = pow(num1, num2); // Save the results.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          case 'x':
          case 'X':
            printf("Please enter the second number or a variable name ('a' to 'e'):\n");
            num2 = getNumOrVar();
            // Check which number is greater.
            if(num1 >= num2) {
              result = num1; // Save num1.
            }
            else {
              result = num2; // Save num2.
            }
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          
          case 'i':
          case 'I':
            printf("Please enter the second number or a variable name ('a' to 'e'):\n");
            num2 = getNumOrVar();
            // Check which number is lesser.
            if(num1 <= num2) {
              result = num1; // Result is num1.
            }
            else {
              result = num2; // Result is num2.
            }
            goodOperation = 0;// Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          default:
            break;
        }

        // If the user entered valid data, then terminate the loop.
        if(goodOperation == 0) {
          printf("The result is:\t%f\n", result); // Output the results.
          goodOperation = 1; // Reset the goodOperation variable.
          operation = ' '; // Reset the operation variable.

          // Check if the memory ran out.
          if(historyCount == HISTORY_LENGTH) {
            memoryOverflow();
          }

          // Save the result in memory.
          history[historyCount] = result;
          historyCount++;
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
              num1 = getNumOrVar();

              // Check if the number is positive.
              if(num1 >= 0) {
                break;
              }
              else {
                if(var != ' ') // If the var variable isn't empty, then the user entered a number or a valid variable.
                  puts("The number cannot be negative. Please try again.");
              }
            }

            result = sqrt(num1); // Save the results.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          case 'l':
          case 'L':
            puts("Please enter a number or a variable name ('a' to 'e') (must be a positive value greater than 0):");
            for(;;) {
              num1 = getNumOrVar();

              // Check if the number is positive and non-zero.
              if(num1 > 0) {
                break;
              }
              else {
                if(var != ' ') // If the var variable isn't negative, then the user entered either a number or a valid variable.
                  puts("The number cannot be negative or zero. Please try again.");
              }
            }

            result = log10(num1); // Save the results.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          case 'e':
          case 'E':
            puts("Please enter a number or a variable name ('a' to 'e'):");
            num1 = getNumOrVar();

            result = exp(num1); // Save the results.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          case 'c':
          case 'C':
            puts("Please enter a number or a variable name ('a' to 'e'):");
            num1 = getNumOrVar();
            result = ceil(num1); // Save the results.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
          case 'f':
          case 'F':
            puts("Please enter a number or a variable name ('a' to 'e'):");
            num1 = getNumOrVar();
            result = floor(num1); // Save the results.
            goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
            break;
        }

        // Check if the user entered valid input.
        if(goodOperation == 0) {
          printf("The result is:\t%f\n", result); // Output the results.
          goodOperation = 1; // Reset the goodOperation variable.
          operation = ' '; // Reset the operation variable.

          // Check if the memory ran out.
          if(historyCount == HISTORY_LENGTH) {
            memoryOverflow();
          }

          // Save the result in memory.
          history[historyCount] = result;
          historyCount++;
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

void unaryOperations() {

  int goodOperation = 1;
  float result;
  char operation = ' ';
  char input[100];

  // Run loop just in case the user enters invalid input. Then the program will prompt the user again.
  for(;;) {
    switch(operation) {
      case 's':
      case 'S':
        num1 = getFloatNoNegatives(); // Run the function to get a positive number.
        result = sqrt(num1); // Save the results.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      case 'l':
      case 'L':
        num1 = getFloatNoNegativesOrZero(); // Get a positive non-zero number.
        result = log10(num1); // Save the results.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      case 'e':
      case 'E':
        printf("Please enter a number:\n");
        num1 = getFloat();

        result = exp(num1); // Save the results.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      case 'c':
      case 'C':
        printf("Please enter a number:\n");
        num1 = getFloat();

        result = ceil(num1); // Save the results.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      case 'f':
      case 'F':
        printf("Please enter a number:\n");
        num1 = getFloat();

        result = floor(num1); // Save the results.
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
    }

    // Check if the user entered valid data. If they did, terminate the for loop.
    if(goodOperation == 0) {
      printf("The result is:\t%f\n", result); // Output the results.

      // Check if the memory ran out.
      if(historyCount == HISTORY_LENGTH) {
        memoryOverflow();
      }

      // Save the result in memory.
      history[historyCount] = result;
      historyCount++;
      break; // Terminate the loop.
    }
    
    // Prompt the user for input.
    printf("Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):\n");
    scanf("%s", input); // This input accepts a word as input (just in case the user slips and hits another key).
    operation = input[0]; // Sets the operation equal to the first character from the user input.
  }
}

void setVar() {

  // Initialize necessary variables.
  char var = ' ';
  char input[100];
  int goodOperation = 1;

  // Loops just in case the user enters invalid input.
  for(;;) {

    // Check which variable was selected.
    switch(var) {
      case 'a':
      case 'A':
        puts("Please enter a number:");
        a = getFloat();

        printf("Variable a is set to:\t%f\n", a);
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      case 'b':
      case 'B':
        puts("Please enter a number:");
        b = getFloat();

        printf("Variable b is set to:\t%f\n", b);
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      case 'c':
      case 'C':
        puts("Please enter a number:");
        c = getFloat();

        printf("Variable c is set to:\t%f\n", c);
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      case 'd':
      case 'D':
        puts("Please enter a number:");
        d = getFloat();

        printf("Variable d is set to:\t%f\n", d);
        goodOperation = 0; // Set goodOperation to 0 to show the program can move on and the for loop can terminate.
        break;
      case 'e':
      case 'E':
        puts("Please enter a number:");
        e = getFloat();

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

void viewMemory() {

  int index; // Used for the user to specify which value they have.

  if(historyCount == 0) {
    puts("There is nothing stored in memory.");
    return; // Break function.
  }
  else if(historyCount == 1) {
    printf("There's only one operation stored in memory. The value stored is:\t%f\n", history[0]);
    return; // Break function.
  }

  printf("There are %d operations stored in memory.\n", historyCount); // Display number of stored values.

  puts("Enter which value you'd like to see (enter 0 if you'd like to see all the values in a list):"); // Display prompt.

  index = floor(getFloat()); // Get the input and round it down (should the user feel funny).

  // Loop just in case the user enters invalid input.
  for(;;) {

    // If value is outside the acceptable range, display error message.
    if(index > historyCount || index < 0) {
      printf("That number is outside the range of accepted values 0 - %d. Please try again.\n", historyCount);
    }
    else {
      break; // Exit the loop.
    }
    index = floor(getFloat()); // Gets new input.
  }

  // Check input.
  if(index == 0) {

    // Loops through and displays all stored values.
    for(int i = 0;i < historyCount;i++) {
      printf("Value %d:\t%f\n", (i + 1), history[i]); // Displays the corresponding value.
    }

    return; // Breaks the function.
  }

  printf("Value %d:\t%f\n", index, history[index - 1]); // Displays the corresponding value.
}

void clearMemory() {

  char input[100]; // Used to get input.

  // Displays warning message.
  puts("WARNING: You are about to clear all previously stored operations. Are you sure? Press e if you wish to cancel this procedure or press any other key to proceed.");

  scanf("%s", input); // Get the input.

  // Check if the user wishes to exit.
  if(input[0] == 'e' || input[0] == 'E') {
    return; // Break the function.
  }

  puts("Erasing memory....");

  // Deletes all values.
  for(int i = 0;i < historyCount;i++) {
    history[i] = 0;
  }

  historyCount = 0; // Sets the historyCount back to 0.
  puts("Done.");
}