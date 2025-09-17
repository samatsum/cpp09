# ➕ Reverse Polish Notation (RPN) Calculator 🧮  

This exercise involves building an RPN calculator to evaluate postfix mathematical expressions.  

---  

## 📖 Problem Description  

The program will:  
1. Read postfix expressions from the user.  
2. Evaluate them using an STL stack.  
3. Handle basic operators like `+`, `-`, `*`, `/`.  

---  

## 📂 File Structure  

| File           | Description                            |  
|----------------|----------------------------------------|  
| `RPN.hpp`      | Header file with class definitions.    |  
| `RPN.cpp`      | Implementation of calculator logic.    |  
| `main.cpp`     | Entry point for the program.           |  

---  

## 🛠️ How to Build and Run  

1. Build the project using `make`:  
   ```bash  
   make  
   ```  
2. Run the program:  
   ```bash  
   ./ex01  
   ```  

---  

## 💡 Key Features  

- **Simple Evaluation**: Supports addition, subtraction, multiplication, and division.  
- **Stack-Based**: Uses STL stack for postfix evaluation.  
- **Error Handling**: Detects invalid inputs and division by zero.  

---  

## 📊 Example Usage  

### Input  
```txt  
Enter an RPN expression:  
3 4 + 2 *  
```  

### Output  
```txt  
Result: 14  
```  

---  

## 🚀 Concepts Used  

- STL Stack 🥞 for managing operations.  
- Algorithmic thinking 🤔 for parsing expressions.  

---  

## 🏆 Challenge  

Extend support to include more operators or functions (e.g., square root or power).  
