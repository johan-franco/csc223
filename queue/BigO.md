# Questions

## Prove $2n^2 + 5n - 8$ is $O(n^2)$
If we do it the quick way then we would ignore all the lower order terms. This would leave the highest order term $2n^2$ and then we would proceed to ignore the constant 2. Therefore the Big O value of this expression is $O(n^2)$. However, this is not the method to do so.






## If you know that the element you are looking for is somewhere in the unordered array you are searching through, then the probability is you will find it after looking through about half the elements in the array. Explain why $\frac{n}{2}$ is $n^2$


# Notes;

## BIg O Definition 
"Given two functions $f(n)$ and $g(n)$, we say that $f(n)$ is $O(g(n))$ if there exist constants $c > 0$ and $n_0 >= 0$ such that $f(n) <= c*g(n)$ for all $n >= n0$."

- Used to find upper bound on time taken by an algorithm or data structure
- Can be used to predict behavior of algorithms and data structures as input increases
- Used to analyze efficiency
- Describes how the runtime or space requirements of an algorithm grow as the input size increases
    - "the upper bound of the complexity in the worst-case scenario"
- Look at the highest order term ignoring lower order and constant

## Proofs for Big O
- We only consider positive inputs and outputs
- Ignore multiplicative constants & small inputs
 - Therefore $3x^2$ and $ .003x^2$ are seen as growing at the same rate

- a function is bigger than another if they grow faster than the other with large inputs
- $1 ≺ \log n ≺ n ≺ n \log n ≺ n^2$
- The constant c in the equation models how we don’t care about multiplicative constants in comparing function.
- The restriction that the equation only holds for $x ≥ k$ models the fact that we don’t care about the behavior of the functions on small input values.
- Suitable values for c and k are needed to show a big-O relationship holds.
- 

### Examples on how to find Big O(grabbed directly from GeeksForGeeks)
$f(n) = 3n^2 + 2n + 1000\log(n) +  5000$
After ignoring lower order terms, we get the highest order term as $3n^2$
After ignoring the constant 3, we get $n^2$
Therefore the Big O value of this expression is$ O(n^2)$


## Time Complexities (grabbed directly from GeeksForGeeks)

### 1. Linear Time Complexity: $( O(n)) $
The running time grows linearly with the input size.

```cpp
bool findElement(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return true;
        }
    }
    return false;
}
```

### 2. Logarithmic Time Complexity: $( O(\log n))$
The running time is proportional to the logarithm of the input size.

```cpp
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
```

### 3. Quadratic Time Complexity: $( O(n^2))$
The running time is proportional to the square of the input size.

```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
```

### 4. Cubic Time Complexity: $( O(n^3))$
The running time is proportional to the cube of the input size.

```cpp
void multiply(int mat1[][N], int mat2[][N], int res[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = 0;
            for (int k = 0; k < N; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}
```

### 5. Polynomial Time Complexity: $( O(n^k) )$
A polynomial function of input size $( n )$. Examples include $( O(n) ), ( O(n^2) ), V( O(n^3)) $.

### 6. Exponential Time Complexity: $ O(2^n) $
The running time doubles with each addition to the input size.

```cpp
void generateSubsets(int arr[], int n) {
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}
```

### 7. Factorial Time Complexity: $ O(n!) $
The running time grows factorially with the input size.

```cpp
void permute(int* a, int l, int r) {
    if (l == r) {
        for (int i = 0; i <= r; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(a[l], a[i]);
            permute(a, l + 1, r);
            swap(a[l], a[i]); // backtrack
        }
    }
}
```

## Mathematical Examples of Runtime Analysis

| $ n $ | $ \log(n) $ | $ n $ | $ n \log(n) $ | $ n^2 $ | $ 2^n $ | $ n! $ |
|---|---|---|---|---|---|---|
| 10 | 1 | 10 | 10 | 100 | 1024 | 3,628,800 |
| 20 | 2.996 | 20 | 59.9 | 400 | 1,048,576 | 2.432902e+18 |

## Algorithmic Examples of Runtime Analysis

| Type | Notation | Example Algorithms |
|---|---|---|
| Logarithmic | $ O(\log n) $ | Binary Search |
| Linear | $ O(n) $ | Linear Search |
| Superlinear | $ O(n \log n) $ | Heap Sort, Merge Sort |
| Polynomial | $ O(n^c) $ | Strassen’s Matrix Multiplication, Bubble Sort |
| Exponential | $ O(c^n) $ | Tower of Hanoi |
| Factorial | $ O(n!) $ | Traveling Salesman Problem (Brute Force) |

## Big-O, Big-Ω, and Big-Θ Notations

| Notation | Definition | Explanation |
|---|---|---|
| Big O ($ O $) | $ f(n) \leq C \cdot g(n) $ for all $ n \geq n_0 $ | Upper bound of running time |
| Omega $(( \Omega ))$ | $ f(n) \geq C \cdot g(n) $ for all $ n \geq n_0 $ | Lower bound of running time |
| Theta ($ \Theta $) | $ C_1 \cdot g(n) \leq f(n) \leq C_2 \cdot g(n) $ for $ n \geq n_0 $ | Both upper and lower bounds |

Where:
- $ f(n) $ is the function being analyzed (time complexity of an algorithm).
- $ g(n) $ is a specific function bounding $ f(n) $.
- $ C, C_1, C_2 $ are constants.
- $ n_0 $ is the minimum input size for which the inequality holds.

These notations help analyze algorithms in terms of worst-case (Big-O), best-case ($ \Omega $), and average-case ($ \Theta $).
