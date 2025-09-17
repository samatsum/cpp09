# 🔄 PmergeMe - Optimized Sorting with Performance Comparison  

In **PmergeMe**, you'll implement a hybrid sorting algorithm while measuring and comparing performance differences between `std::vector` and `std::deque`.  

---  

## 📖 Problem Description  

Your task is to:  
1. Implement a sorting algorithm combining merge and insertion sort.  
2. Use STL containers like vectors and deques for sorting.  
3. Measure the performance of sorting using both containers.  

---  

## 📂 File Structure  

| File           | Description                            |  
|----------------|----------------------------------------|  
| `PmergeMe.hpp` | Header file with class definitions.    |  
| `PmergeMe.cpp` | Implementation of hybrid sort logic.   |  
| `main.cpp`     | Entry point for the program.           |  

---  

## 🛠️ How to Build and Run  

1. Build the project using `make`:  
   ```bash  
   make  
   ```  
2. Run the program:  
   ```bash  
   ./ex02  
   ```  

---  

## 💡 Key Features  

- **Hybrid Sorting**: Combines merge and insertion sort for efficiency.  
- **Performance Measurement**: Compares execution time for `std::vector` and `std::deque`.  
- **Flexible Input**: Handles input of integers from files or standard input.  

---  

## ⏱️ Performance Comparison  

The program includes two key methods to measure sorting time:  

- `double PmergeMe::vec_duration()`: Sorts using `std::vector` and returns the execution time.  
- `double PmergeMe::deque_duration()`: Sorts using `std::deque` and returns the execution time.  

### Example Output  
```txt  
Sorted List (Vector): 3 4 6 8 10  
Time (Vector): 0.000123 seconds  

Sorted List (Deque): 3 4 6 8 10  
Time (Deque): 0.000145 seconds  
```  

---  

## 📊 Example Usage  

### Input  
```txt  
./PmergeMe 10 4 6 8 3  
```  

### Output  
```txt  
Before: 10 4 6 8 3
After: 3 4 6 8 10
Time to process a range of 5 elements with std::this->vector : 0.000005s
Time to process a range of 5 elements with std::this->deque : 0.000002s
```  

---  

## 🚀 Concepts Used  

- STL Vectors and Deques 📊 for container flexibility.  
- Hybrid algorithms 🚀 for optimized sorting.  
- Clock timing ⏱️ to measure execution performance.  

---  

## 🏆 Challenge  

Experiment with different dataset sizes to observe performance trends between `std::vector` and `std::deque`.  

---  

Happy coding! 💻  
