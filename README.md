# MasterMind (C++)

A console-based implementation of the classic Mastermind game using numbers instead of colors.

##  Description

This project is a simple C++ game for two players:

- The **first player** sets a secret 4-digit number.
- The **second player** tries to guess it in **10 attempts**.

After each guess, the game provides feedback:
-  How many digits are correct
-  How many digits are in the correct position

If the player guesses the number correctly, the game ends with a success message. Otherwise, after 10 attempts, the correct number is revealed.

---

##  Game Rules

- The secret number must be:
  - Exactly **4 digits**
  - Digits from **0–9**
  - **First digit cannot be 0**
- The second player has **10 tries**
- After each guess:
  - **Correct digits** → digits that exist in the number
  - **Correct positions** → digits in the correct place

---

##  Example
Secret number: 1234
Guess: 1243

Correct digits: 4
Correct positions: 2

## Technologies Used

- C++
- Console (CLI)

  
---

## How to Run

### Using Dev-C++
1. Open the project
2. Make sure all files are added:
   - `main.cpp`
   - `Number.cpp`
   - `Number.h`
3. Click **Compile & Run (F11)**

### Using terminal (g++)
```bash
g++ main.cpp Number.cpp -o mastermind
./mastermind
```

## Features

- Input validation
- Prevents invalid numbers
- Handles duplicate digits correctly
- Clean game loop with win/lose conditions

## Notes
- The screen clears after the first player inputs the number
- The game runs entirely in the terminal
- Designed as a beginner-friendly C++ project

  ## Author
  Eirini Markantoni


## 🧠 Example
