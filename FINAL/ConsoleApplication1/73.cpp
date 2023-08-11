//Cyclomatic complexity is a software metric that measures the complexity of a program's control flow based
//on the number of decision points and the number of independent paths through the program. It helps identify
//the number of logical conditions and possible execution paths in a program, which in turn provides an estimate of how difficult it is to understand, test, and maintain the code.
//
//The cyclomatic complexity of a program can be calculated using the following formula :
//
//M = E - N + 2
//
//Where :
//    -M is the cyclomatic complexity
//    - E is the number of edges(control flow branches)
//    - N is the number of nodes(decision points)
//
//    The higher the cyclomatic complexity, the more complex the program's logic and the more difficult it
//    may be to understand and test. A low cyclomatic complexity indicates simpler and more manageable code.
//
//    Cyclomatic complexity can provide insights into the number of test cases needed to achieve good code
//    coverage.In general, the number of test cases required should be at least equal to the cyclomatic complexity
//    to ensure that all possible paths and decision points are covered.Each distinct path through the code should
//    be tested at least once.
//
//    Here is an example in C++ to illustrate how cyclomatic complexity relates to program logic complexity
//    and the number of test cases :
//
//```cpp
//#include <iostream>
//
//int calculate(int x, int y, int z) {
//    int result;
//
//    if (x > 0) {
//        if (y > 0) {
//            result = x + y;
//        }
//        else {
//            result = x - y;
//        }
//    }
//    else {
//        if (z > 0) {
//            result = x * z;
//        }
//        else {
//            result = x / z;
//        }
//    }
//
//    return result;
//}
//
//int main() {
//    int a = 10, b = 5, c = 2;
//    int res = calculate(a, b, c);
//
//    std::cout << "Result: " << res << std::endl;
//
//    return 0;
//}
//```
//
//In this example, the `calculate` function takes three input parameters and performs a set of nested if -
//else conditions based on the values of those parameters.The code has multiple decision points, resulting
//in different paths of execution.
//
//To calculate the cyclomatic complexity, we need to count the number of decision points(nodes) and control
//flow branches(edges).In this case, we have four decision points(`x > 0`, `y > 0`, `z > 0`, and the final
//`return` statement) and six control flow branches(two branches for each if - else condition).Therefore,
//the cyclomatic complexity is 6 - 4 + 2 = 4.
//
//Based on the cyclomatic complexity of 4, it is recommended to have a minimum of 4 test cases to cover all
//possible paths and decision points in the code.This will ensure that all branches are tested and increase
//the likelihood of finding potential bugs or issues.
//
//By having an appropriate number of test cases, we can have better code coverage and gain more confidence
//in the correctness of the program.However, it's important to note that cyclomatic complexity is just one
//aspect of measuring program complexity, and additional factors should be considered for comprehensive testing.

/*圈复杂度（Cyclomatic complexity）是一种衡量程序控制流复杂性的软件度量指标，它基于程序中的决策点数量和独立路径数量来衡量。
 *它可以帮助识别程序中的逻辑条件和可能的执行路径数量，从而提供了对代码难以理解、测试和维护程度的估计。

计算程序的圈复杂度可以使用以下公式：

M = E - N + 2

其中：
- M 是圈复杂度
- E 是边的数量（控制流分支）
- N 是节点的数量（决策点）

圈复杂度越高，程序逻辑越复杂，理解和测试起来可能越困难。低圈复杂度表示代码更简单、更易于管理。

圈复杂度可以提供关于测试用例数量的参考。一般来说，所需的测试用例数量至少应等于圈复杂度，以确保覆盖所有可能的路径和决策点。
每个不同的代码路径至少应被测试一次。

下面是一个用 C++ 示例来说明圈复杂度如何与程序逻辑复杂性和测试用例数量相关的示例：

```cpp
#include <iostream>

int calculate(int x, int y, int z) {
  int result;

  if (x > 0) {
    if (y > 0) {
      result = x + y;
    } else {
      result = x - y;
    }
  } else {
    if (z > 0) {
      result = x * z;
    } else {
      result = x / z;
    }
  }

  return result;
}

int main() {
  int a = 10, b = 5, c = 2;
  int res = calculate(a, b, c);
  
  std::cout << "Result: " << res << std::endl;

  return 0;
}
```

在这个示例中，`calculate` 函数接受三个输入参数，并根据这些参数的值执行一系列嵌套的 if-else 条件。代码中有多个决策点，
导致执行不同的路径。

要计算圈复杂度，我们需要统计决策点的数量（节点）和控制流分支的数量（边）。在这个例子中，
我们有四个决策点（`x > 0`、`y > 0`、`z > 0` 和最后的 `return` 语句），以及六个控制流分支（每个 if-else 条件两个分支）。因此，圈复杂度为 6 - 4 + 2 = 4。

根据圈复杂度为 4，建议至少有 4 个测试用例来覆盖代码中的所有可能路径和决策点。这将确保所有分支都被测试，
并增加发现潜在错误或问题的可能性。

通过使用适当数量的测试用例，我们可以提高代码覆盖率，对程序正确性更有信心。然而，需要注意的是，
圈复杂度只是衡量程序复杂性的一个方面，综合考虑其他因素进行全面测试。*/


