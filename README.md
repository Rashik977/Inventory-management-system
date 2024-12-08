# Inventory Management System

## Overview

This is a C++ Inventory Management System that allows an organization to manage products and suppliers. It includes functionalities for adding and removing products, searching for products by either their ID or name, generating an inventory report, and notifying suppliers when products need to be restocked. The system utilizes Object-Oriented Programming (OOP) principles such as **inheritance**, **composition**, **abstraction**, and **polymorphism** to provide a flexible and extensible solution.

## Features

- **Product Management**: Add and remove products from the organization’s inventory.
- **Supplier Notification**: Notify local and global suppliers when products need to be restocked.
- **Product Search**: Search products either by **ID** or **name** using method overloading.
- **Inventory Report**: Generate a report showing product names, stock levels, and restocking needs.
- **Extensible System**: The system is designed to easily accommodate additional functionality such as adding more product categories or supplier types.

## Design Choices

### **OOP Concepts Implemented**

1. **Inheritance**:  
   The `Supplier` class is inherited by both the `LocalSupplier` and `GlobalSupplier` classes, each implementing the `notifyRestock` method, which makes the system flexible in terms of extending the types of suppliers.

2. **Composition**:  
   The `Organization` class is composed of multiple `Product` objects (via a vector), representing a collection of products managed by the organization. Each product has properties like `name`, `price`, `stock level`, and `reorder threshold`.

3. **Method Overloading**:  
   The `searchProduct` method is overloaded to allow searching by either product **ID** (integer) or **name** (string). This enhances the flexibility of the code by allowing users to search for products using different parameters.

4. **Abstraction**:  
   The `Product` class abstracts the details about product attributes and methods related to stock management. The `Supplier` class abstractly defines how suppliers are notified for restocking.

5. **Forward Declarations**:  
   The `Organization` and `Supplier` classes are forward declared to prevent circular dependencies and enable proper organization of the codebase.

6. **Polymorphism**:  
   The use of the `notifyRestock` function in the `Supplier` class and its subclasses demonstrates polymorphism. This allows for dynamic binding when different types of suppliers are notified of restocking needs.

### **Additional Features Implemented**

- **Enhanced Search Functionality**: Added a search feature that finds products based on partial name matches. For example, searching for "lap" would return "Laptop", making the application more user-friendly and allowing for more flexible product lookups.

---

## How to Run the Program

### **Using Visual Studio Code (VS Code)**

1. **Prerequisites**:
   - Ensure you have **Visual Studio Code** installed.
   - Install the **C++ extension** from Microsoft in VS Code to enable syntax highlighting, IntelliSense, and debugging support.
   - Install the **g++ compiler** (part of the GNU Compiler Collection) if you haven't already. You can install it using your package manager or download it from [here](https://gcc.gnu.org/).

2. **Setting up the Task Configuration**:
   - The code uses **g++** for compiling, and the build process is automated using the `tasks.json` configuration file.
   - Open VS Code and add the following task configuration inside your project’s `.vscode` folder.

   **tasks.json**:

   ```json
   {
       "version": "2.0.0",
       "tasks": [
           {
               "label": "Build C++",
               "type": "shell",
               "command": "/usr/bin/g++",
               "args": [
                   "-g",
                   "*.cpp",
                   "-o",
                   "main"
               ],
               "group": {
                   "kind": "build",
                   "isDefault": true
               },
               "problemMatcher": ["$gcc"]
           }
       ]
   }


3. **Building the Project:**
    - To build the project in VS Code, press Ctrl + Shift + B or go to Terminal > Run Build Task. This will invoke the g++ compiler to compile all .cpp files in the project and generate the executable file named main.

4. **Running the Program:**
    - After building the project, you can run the program directly from the terminal. Open a terminal window in VS Code and type:

        ```bash
        ./main

    - This will execute the compiled program.


### **Running on Other IDEs**
If you are using a different IDE (e.g., Code::Blocks, CLion, or DevC++), follow these general steps:

Install g++ (or use your IDE's built-in C++ compiler).
Open the project in your IDE.
Build the project by pressing the Build button or following the IDE’s build process.
Run the program by executing the output file (typically named main or a.out depending on the IDE).
