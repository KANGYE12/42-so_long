# 🎮 so_long

![so_long](https://img.shields.io/badge/so__long-v1.0-brightgreen.svg) ![42-school](https://img.shields.io/badge/42-school-blue.svg) ![C Language](https://img.shields.io/badge/Language-C-informational.svg)

## 🌟 Project Overview

**so_long** is a small, 2D maze navigation game developed as part of the 42 curriculum. The primary goal of this project is to get familiar with the basics of game development, including window management, event handling, and rendering graphics using the **MiniLibX** library.

The player's mission is simple: traverse a rectangular map, collect all the shiny collectibles ✨, and find the exit 🚪 without getting stuck.

---

## 🕹️ Features

-   **Window & Graphics:**
    -   Seamless window creation and management using the MiniLibX library.
    -   Renders high-quality sprites for walls, empty spaces, the player, collectibles, and the exit.
    -   Displays the number of moves the player has made in the console.

-   **Map Handling:**
    -   Robust map parsing system that reads a `.ber` file to build the game environment.
    -   Validates the map to ensure it meets all project requirements (rectangular shape, bordered by walls, etc.).
    -   Includes a backtracking algorithm to guarantee a valid path from the player to all collectibles and the exit.

-   **Game Logic:**
    -   Responsive player movement and collision detection.
    -   Dynamic game state: the exit is only accessible after all collectibles have been gathered.
    -   Handles a win condition (reaching the exit after collecting everything) and an exit condition (closing the window or pressing `ESC`).

---

## 🚀 Installation & Gameplay

### 🛠️ Prerequisites

You will need the MiniLibX library, which is typically available in the 42 school environment. If not, you may need to install it according to your system's specific instructions.

### ⚙️ Getting Started

1.  **Clone the repository to your local machine:**
    ```bash
    git clone [https://github.com/KANGYE12/42-so_long.git](https://github.com/KANGYE12/42-so_long.git)
    cd 42-so_long
    ```

2.  **Compile the project:**
    Use the provided `Makefile` to compile all the necessary source files.
    ```bash
    make
    ```

3.  **Run the game with a map:**
    The executable `so_long` requires a `.ber` map file as an argument. You can find example maps in the `maps/` directory.
    ```bash
    ./so_long maps/example.ber
    ```

### 🗺️ Map Creation

You can create your own maps! Just make sure they follow these strict rules:

-   Map must be a perfect **rectangle**.
-   Must be fully surrounded by **walls** (`1`).
-   Must contain exactly **one** player starting position (`P`).
-   Must contain exactly **one** exit (`E`).
-   Must contain at least **one** collectible (`C`).
-   All map elements must be reachable from the start.
-   Only uses the allowed characters: `1`, `0`, `P`, `E`, `C`.

---

## ⌨️ Controls

| Key           | Action             | Emoji      |
|---------------|--------------------|------------|
| `W` or `↑`    | Move player up     | 👆🏻         |
| `A` or `←`    | Move player left   | 👈🏻         |
| `S` or `↓`    | Move player down   | 👇🏻         |
| `D` or `→`    | Move player right  | 👉🏻         |
| `ESC`         | Exit the game      | 🚪         |

---

## 🧑‍💻 Author

-   **KANGYE** - [KANGYE12](https://github.com/KANGYE12)

---
