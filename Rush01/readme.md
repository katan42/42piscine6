# 🧩 rush-01 – Skyscraper Puzzle Solver

**Group project** from the 42 Piscine that challenges you to solve a 4×4 grid-based logic puzzle using **recursive backtracking** and **constraint validation**.
Inspired by ["Skyscraper" logic puzzles](https://www.puzzle-skyscrapers.com/), this project reinforces algorithmic thinking, input validation, and strict coding discipline under 42's norminette constraints.

---

## 📋 Project Description
The goal is to fill a **4×4 grid** with the numbers `1` to `4` such that:

- Each number appears **only once per row and column** (similar to Sudoku)
- Clues are given around the grid edges indicating how many “buildings” are visible from that direction
  - Taller numbers block shorter ones
  - Each clue applies to one row or column

This simulates a "skyscraper" puzzle where **logic + constraints** must be satisfied at every move.

---

## 🎯 Learning Objectives

- 🔁 Recursive backtracking
- 🧮 Manual memory management and input parsing

---

## 💡 Reflections & Lessons Learned

- ❌ We **failed the initial submission** even though the solver worked — because we forgot to handle the **empty input case** (`./rush01`) 😅  
  → The fix was embarrassingly simple and was corrected in [ex00](./ex00).

- 🧪 We attempted the **bonus** (solving for 5×5, 6×6, etc.) by statically allocating grids for sizes 5, 6, and 7 — not elegant, but functional.

- 🧵 We tried to implement **dynamic grid allocation** using `malloc`, and got it working!  
  😓 But it broke norminette due to a prototype having 5 arguments.

> _Next time: start with edge case handling, check for argument counts early, and modularize malloc logic for norm compliance and reduce runtime!

---

## 🛠️ How to Compile and Run
```bash
cc rush01.c main.c check_clues.c -o rush01

Example input:
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
