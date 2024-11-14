# Interactive Grading System with Themed Storyline

## Overview

This C++ program implements a themed, interactive grading system where the user, playing as a professor, is tasked with inputting, searching, and managing student grades. The program introduces an immersive storyline, where the user must handle the grading tasks while avoiding an antagonist called "The Grue". The professor's only source of light is a flickering flashlight, and the user must complete tasks while keeping the flashlight on to avoid being "caught" by The Grue.

## Features

- **Interactive Menu**: The user can input grades, search for existing grade entries, or print all student grades.
- **Search Functionality**: The program allows searching by student name, assignment name, grade type, and grade range.
- **Game Element**: While performing tasks, the user must keep the flashlight on by pressing the correct button to prevent The Grue from attacking. If the flashlight turns off, the user loses the game, and all grades are reset to 0%.
- **Data Persistence**: The program loads grades from an external file (`inventory.txt`), which contains student names, assignment names, types, and grades.
- **Recursive Average Calculation**: The program computes the average grade for each student using recursion.

## Setup

1. **Install a C++ Compiler**: Ensure you have a working C++ compiler (such as `g++`).
2. **Compile the Code**: 
   ```bash
   g++ -o grading_system grading_system.cpp
   ```
3. **Run the Program**:
   ```bash
   ./grading_system
   ```
4. **Inventory File**: Ensure that an `inventory.txt` file is available with the following format:
   - Student Name
   - Assignment Name
   - Type (e.g., Midterm, Homework)
   - Grade (e.g., 85)
   
   Each entry should be separated by a newline.

## Gameplay

- **Main Menu Options**:
  1. **Input a New Grade Slot**: Allows you to input a new student's grade information.
  2. **Search Existing Grade Slot**: Search for grades by student name, assignment name, type, or grade range.
  3. **Print All Grades**: Displays all grades currently stored in the system.
  4. **Run for Your Life!**: Initiates a game mechanic where you must keep the flashlight on by pressing the correct button. If you fail, The Grue will attack, and the game ends.

- **Flashing Light Mechanic**: In the search and input sections, the user must press the correct button to simulate keeping the flashlight on. If the user fails three times, the program ends and grades are reset.

## Functions

- `inputFunction()`: Takes user input for student name, assignment, type, and grade.
- `print_all()`: Displays all grades stored in the grade book.
- `searchFunction()`: Allows the user to search grades by various categories.
- `light()`: Simulates the flashlight mechanic with button presses to avoid The Grue.
- `loadItems()`: Loads grade data from the `inventory.txt` file into the system.
- `average()`: Calculates the average grade of a student recursively.

## Example

When you run the program, you’ll see the following:

```bash
                   Menu                   
__________________________________________
1: To input another grade slot
2: To search existing grade slot
3: To print all of the grade book
4: To run for your life!
__________________________________________

What do you wish to do? [1/2/3/4]:
```

If you choose option 4, the flashlight mechanic begins:

```bash
_______________________
chance 1
switch 1 is: ~~
switch 2: [Your Input Here]
_______________________
```

Keep the flashlight on by making the correct choices to avoid The Grue!

## Notes

- **Color Output**: The program uses color to highlight text in the console, providing a visual cue for various options and errors.
- **Error Handling**: The program handles invalid input gracefully, asking the user to try again if incorrect input is entered.
