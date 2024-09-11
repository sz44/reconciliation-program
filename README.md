# Automated bank reconcilliation helper

## overview
Reconciliation is a common accounting task. Basically it is comparing 2 lists of numbers to see if they match. A problem that can arise is when one of the lists has aggrageted values. In such a case the task becomes more difficult as it requires to find which numbers make up each aggrageted sum. This problem is also know as the subset sums probelm, and is NP-complete. The goal of this program is to make it easy and fast to determine which numbers sum to which sums.

## usage
Prepare two .txt files (any names). One file should be of the individual sums, the second file should be of the aggregated totals. One number per line (see exemple data).

From terminal: ./bin/main numbers.txt sums.txt

## build
Build main.cpp with any c++ compiler 

If using vscode run build task

## Usage

1. Prepare two .txt files:
   - `numbers.txt`: Contains individual transaction amounts (one per line)
   - `sums.txt`: Contains aggregated totals (one per line)

2. Run the program from the terminal:
   ```
   ./bin/main numbers.txt sums.txt
   ```

### Example Data Format

numbers.txt:
```
100.50
200.75
150.25
300.00
-73.84
```

sums.txt:
```
301.25
450.25
-900.00
```

## Building the Program

### Prerequisites
- C++ compiler (e.g., g++, clang++)

### Build Instructions

1. Using a C++ compiler directly:
   ```
   g++ -o bin/main main.cpp
   ```

3. Using VSCode:
   - Open the project in VSCode
   - Run the build task (usually Ctrl+Shift+B or Cmd+Shift+B)

## Future Improvements
- Find all possible solutions
- Add support for currency symbols
- Create a graphical user interface for easier use

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is open source and available under the [MIT License](LICENSE).