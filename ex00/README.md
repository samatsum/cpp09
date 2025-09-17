# 🪙 Bitcoin Exchange  

Welcome to **Bitcoin Exchange**, where you'll simulate a cryptocurrency trading system using C++!  

---  

## 📖 Problem Description  

Your task is to implement a program that:  
1. Reads a data file of Bitcoin prices.  
2. Allows the user to query the value of Bitcoin on specific dates.  
3. Calculates the exchange value based on input amounts.  

---  

## 📂 File Structure  

| File                | Description                          |  
|---------------------|--------------------------------------|  
| `BitcoinExchange.hpp` | Header file with class definitions. |  
| `BitcoinExchange.cpp` | Implementation of Bitcoin logic.    |  
| `main.cpp`          | Entry point for the program.         |  

---  

## 🛠️ How to Build and Run  

1. Build the project using `make`:  
   ```bash  
   make  
   ```  
2. Run the program:  
   ```bash  
   ./ex00  
   ```  

---  

## 💡 Key Features  

- **Efficient Lookups**: Uses STL maps for fast date-to-price lookups.  
- **User-Friendly**: Clear prompts and error handling for invalid inputs.  

---  

## 📊 Example Usage  

### Input  
```txt  
Enter a date (YYYY-MM-DD) and amount:  
2023-03-15 | 5.5  
```  

### Output  
```txt  
On 2023-03-15, 5.5 BTC is worth $200,000.  
```  

---  

## 🚀 Concepts Used  

- STL Maps 🗺️ for date-to-value mapping.  
- String parsing 🧵 to handle user input and file data.  
- File I/O 📁 for reading historical Bitcoin data.  

---  

## 🏆 Challenge  

Optimize your solution for handling large datasets!  
