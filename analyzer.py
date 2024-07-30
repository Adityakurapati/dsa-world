import ast
import math

class AlgorithmComplexityAnalyzer:
    def __init__(self):
        self.complexity = "O(1)"
        self.explanations = []
        self.optimizations = []
        self.alternative_solutions = []
        self.identified_algorithms = set()

    def analyze_code(self, code):
        tree = ast.parse(code)
        self._analyze_node(tree)
        self._identify_algorithms(code)
        return self._generate_report()

    def _analyze_node(self, node):
        if isinstance(node, ast.For):
            self._analyze_loop(node)
        elif isinstance(node, ast.While):
            self._analyze_while(node)
        elif isinstance(node, ast.If):
            self._analyze_if(node)
        elif isinstance(node, ast.FunctionDef):
            self._analyze_function(node)
        elif isinstance(node, ast.Call):
            self._analyze_function_call(node)

        for child in ast.iter_child_nodes(node):
            self._analyze_node(child)

    def _analyze_loop(self, node):
        self.complexity = self._combine_complexity(self.complexity, "O(n)")
        self.explanations.append(f"Found a loop at line {node.lineno}, which contributes O(n) to the complexity.")

    def _analyze_while(self, node):
        self.complexity = self._combine_complexity(self.complexity, "O(n)")
        self.explanations.append(f"Found a while loop at line {node.lineno}, which contributes O(n) to the complexity.")

    def _analyze_if(self, node):
        pass

    def _analyze_function(self, node):
        self.explanations.append(f"Analyzing function '{node.name}' at line {node.lineno}.")

    def _analyze_function_call(self, node):
        if isinstance(node.func, ast.Name):
            self.explanations.append(f"Found a function call to '{node.func.id}' at line {node.lineno}.")

    def _combine_complexity(self, c1, c2):
        if c1 == "O(1)":
            return c2
        elif c2 == "O(1)":
            return c1
        elif c1 == c2:
            return c1
        else:
            return f"O(max({c1[2:-1]}, {c2[2:-1]}))"

    def _identify_algorithms(self, code):
        if "def bubble_sort" in code:
            self.identified_algorithms.add("bubble_sort")
        if "def selection_sort" in code:
            self.identified_algorithms.add("selection_sort")
        # Add more algorithm identifications here

    def _suggest_optimizations(self):
        if "O(n^2)" in self.complexity:
            self.optimizations.append("Consider using a more efficient data structure or algorithm to reduce nested loops.")
        if "O(n)" in self.complexity:
            self.optimizations.append("Look for opportunities to use hash tables or other O(1) lookup data structures.")

    def _suggest_alternatives(self):
        if "bubble_sort" in self.identified_algorithms:
            self.alternative_solutions.append(
                "Bubble Sort has a time complexity of O(n^2). Consider these alternatives:\n"
                "1. Quick Sort: Average case O(n log n), worst case O(n^2), but generally faster in practice.\n"
                "   def quick_sort(arr):\n"
                "       if len(arr) <= 1:\n"
                "           return arr\n"
                "       pivot = arr[len(arr) // 2]\n"
                "       left = [x for x in arr if x < pivot]\n"
                "       middle = [x for x in arr if x == pivot]\n"
                "       right = [x for x in arr if x > pivot]\n"
                "       return quick_sort(left) + middle + quick_sort(right)\n"
                "\n"
                "2. Merge Sort: Consistent O(n log n) time complexity.\n"
                "   def merge_sort(arr):\n"
                "       if len(arr) <= 1:\n"
                "           return arr\n"
                "       mid = len(arr) // 2\n"
                "       left = merge_sort(arr[:mid])\n"
                "       right = merge_sort(arr[mid:])\n"
                "       return merge(left, right)\n"
                "\n"
                "   def merge(left, right):\n"
                "       result = []\n"
                "       i, j = 0, 0\n"
                "       while i < len(left) and j < len(right):\n"
                "           if left[i] < right[j]:\n"
                "               result.append(left[i])\n"
                "               i += 1\n"
                "           else:\n"
                "               result.append(right[j])\n"
                "               j += 1\n"
                "       result.extend(left[i:])\n"
                "       result.extend(right[j:])\n"
                "       return result\n"
                "\n"
                "3. Python's built-in sort() method: Uses Timsort, a hybrid sorting algorithm derived from merge sort and insertion sort.\n"
                "   sorted_arr = sorted(arr)  # or arr.sort() for in-place sorting\n"
            )
        if "O(n)" in self.complexity and "search" in ' '.join(self.explanations).lower():
            self.alternative_solutions.append(
                "For searching in sorted arrays, consider using Binary Search which has O(log n) complexity:\n"
                "def binary_search(arr, target):\n"
                "    left, right = 0, len(arr) - 1\n"
                "    while left <= right:\n"
                "        mid = (left + right) // 2\n"
                "        if arr[mid] == target:\n"
                "            return mid\n"
                "        elif arr[mid] < target:\n"
                "            left = mid + 1\n"
                "        else:\n"
                "            right = mid - 1\n"
                "    return -1  # Target not found\n"
            )

    def _generate_report(self):
        self._suggest_optimizations()
        self._suggest_alternatives()
        return {
            "complexity": self.complexity,
            "explanations": self.explanations,
            "optimizations": self.optimizations,
            "alternative_solutions": self.alternative_solutions
        }

# Example usage
analyzer = AlgorithmComplexityAnalyzer()
code = """
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr
"""
result = analyzer.analyze_code(code)
print(result)