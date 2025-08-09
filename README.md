# Building and Running

Follow these steps to compile and run the project from your terminal.

## Prerequisites

  * A C++ compiler (like G++ or Clang)
  * **CMake** (version 3.16 or higher)

-----

## Step-by-Step Instructions

### 1\. Configure the Project (First Time Only)

First, create a `build` directory and run CMake to prepare the project for compilation. You only need to do this once.

```bash
mkdir build
cd build
cmake ..
```

### 2\. Compile the Code

Now, from within the `build` directory, you can compile the project. You'll repeat this step every time you make changes to the source code.

```bash
cmake --build .
```

This command is a platform-agnostic way to build the project and is preferred over running `make` directly.

### 3\. Run the Application

The final executable will be located in a subdirectory inside `build` that matches the source structure.

```bash
./build/SDL3Starter
```
