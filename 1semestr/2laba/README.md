# 👩‍💻 Integer Arithmetic — Central Digit Transformation

**Topic:** Integer Arithmetic  
**Language:** C++  
**Environment:** Visual Studio  

---

## 📋 Project Overview

A C++ console application that performs integer manipulation based on the parity of the number's digit count. 

If the input number contains an **odd** number of digits, the program extracts the **central digit** and appends it to both the left and right sides of the original number. If the digit count is **even**, the number remains unchanged.

### Behavior Summary
*   `123` → `21232`
*   `42` → `42` (unchanged)
*   `7` → `777`

---

## 🗂️ Project Structure

```
project/
├── project.slnx              # Visual Studio Solution
├── project/
│   ├── project.cpp           # Source code
│   └── project.vcxproj       # Project file
└── README.md                 # Documentation
```

---

## ⚙️ Technical Implementation

The core logic relies on **integer arithmetic** and avoids string conversions:

1.  **Digit Counting:** A `while` loop uses integer division (`n /= 10`) to count the total number of digits (`N`).
2.  **Parity Check:** An `if (N % 2 != 0)` condition determines if the transformation is required.
3.  **Central Digit Extraction:** 
    *   The middle position is calculated as `N / 2`.
    *   The original number is divided by `10^(N/2)` using `pow()` from `<cmath>`.
    *   The modulo operator (`% 10`) isolates the exact central digit.
4.  **Reconstruction:** The new number is assembled using arithmetic shifts:
    *   `cif * 10^(N+1)` moves the central digit to the highest position.
    *   `original * 10` shifts the original number left.
    *   Adding `cif` appends it to the lowest position.

---

## 🚀 Build & Run

1. Open `project.slnx` in **Visual Studio**.
2. Build the solution (`Ctrl + Shift + B`).
3. Run the application (`F5`).

**Alternative via CLI:**
```bash
g++ -std=c++17 project.cpp -o program
./program
```

---

## 🛠️ Tech Stack

*   **Language:** C++
*   **Libraries:** `<iostream>`, `<cmath>`
*   **Build System:** MSBuild (`.slnx` / `.vcxproj`)
