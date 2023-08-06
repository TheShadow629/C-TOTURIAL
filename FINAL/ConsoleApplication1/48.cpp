//是要手动实现set的操作？
//The Set data structure is an unordered collection of unique elements.
//It represents a mathematical set and is commonly used in computer science
//to store a collection of distinct values. Sets do not allow duplicate elements,
//and the order of elements is not important.
//
//Common set operations include:
//
//1. Insertion: Adds an element to the set if it doesn't already exist.
//   - Algorithm:
//     - Check if the element exists in the set.
//     - If it doesn't, add the element to the set.
//   - Preconditions: None.
//
//2. Deletion: Removes an element from the set if it exists.
//   - Algorithm:
//     - Check if the element exists in the set.
//     - If it does, remove the element from the set.
//   - Preconditions: None.
//
//3. Membership Test: Checks if an element exists in the set.
//   - Algorithm:
//     - Check if the element exists in the set.
//     - Return true if it does, false otherwise.
//   - Preconditions: None.
//
//4. Union: Combines two sets, resulting in a new set that contains all elements from both sets.
//   - Algorithm:
//     - Create an empty set to hold the union of the two sets.
//     - Add all elements from the first set to the new set.
//     - Iterate over the second set and add only the elements that do not already exist in the new set.
//     - Return the new set.
//   - Preconditions: None.
//
//5. Intersection: Finds elements that exist in both sets, resulting in a new set.
//   - Algorithm:
//     - Create an empty set to hold the intersection of the two sets.
//     - Iterate over the elements in one set.
//     - If an element exists in the other set, add it to the new set.
//     - Return the new set.
//   - Preconditions: None.
//
//6. Difference: Finds elements in the first set that do not exist in the second set, resulting in a new set.
//   - Algorithm:
//     - Create an empty set to hold the difference of the two sets.
//     - Iterate over the elements in the first set.
//     - If an element does not exist in the second set, add it to the new set.
//     - Return the new set.
//   - Preconditions: None.
//
//Efficiency of the algorithms:
//
//- The efficiency of set operations depends on the underlying implementation of the Set data structure.
//Common implementations, such as HashSet or Red-Black Tree, offer efficient average-case time complexities
//for operations like insertion, deletion, and membership testing. These operations typically have an
//average-case time complexity of O(1) or O(log n), where n is the number of elements in the set. However,
//worst-case scenarios can occur if there are many hash collisions or unbalanced trees, resulting in a time
//complexity of O(n).
//- The efficiency of set operations also depends on the hash code or comparison function used for elements.
//For a hash-based set, a good hash function can distribute elements evenly, reducing the chance of collisions
//and providing efficient average-case behavior.
//- The efficiency of the Union, Intersection, and Difference operations is dependent on the sizes of the sets
//being operated on. In the worst case, they have a time complexity of O(n), where n is the size of the larger set.
//
//Preconditions for efficient algorithms:
//
//- To achieve efficient set operations, it is important to use an appropriate implementation of the Set
//data structure that provides efficient average-case time complexities.
//- It is crucial to ensure that the elements in the set have well-distributed hash codes or an effective
//comparison function to minimize collisions.
//- For Union, Intersection, and Difference operations, the efficiency is affected by the sizes of the sets.
//If one set is significantly larger than the other, it can impact the performance.

//集合（Set）数据结构是一种无序的、元素唯一的集合。它代表了数学中的集合概念，在计算机科学中常用于存储不重复的值。
//集合不允许重复的元素，且元素的顺序并不重要。
//
//常见的集合操作包括：
//
//1. 插入：将元素添加到集合中，如果它不存在的话。
//   - 算法：
//     - 检查集合中是否存在该元素。
//     - 如果不存在，则将元素添加到集合中。
//   - 前提条件：无。
//
//2. 删除：从集合中删除一个存在的元素。
//   - 算法：
//     - 检查集合中是否存在该元素。
//     - 如果存在，则从集合中删除该元素。
//   - 前提条件：无。
//
//3. 成员测试：检查元素是否存在于集合中。
//   - 算法：
//     - 检查集合中是否存在该元素。
//     - 如果存在，则返回 true；否则返回 false。
//   - 前提条件：无。
//
//4. 并集：合并两个集合，生成一个包含两个集合中所有元素的新集合。
//   - 算法：
//     - 创建一个空集合，用于存储两个集合的并集。
//     - 将第一个集合中的所有元素添加到新集合中。
//     - 遍历第二个集合，只添加那些在新集合中不存在的元素。
//     - 返回新集合。
//   - 前提条件：无。
//
//5. 交集：找出两个集合中共同存在的元素，生成一个新集合。
//   - 算法：
//     - 创建一个空集合，用于存储两个集合的交集。
//     - 遍历其中一个集合的元素。
//     - 如果一个元素也存在于另一个集合中，则将其添加到新集合中。
//     - 返回新集合。
//   - 前提条件：无。
//
//6. 差集：找出第一个集合中存在但第二个集合中不存在的元素，生成一个新集合。
//   - 算法：
//     - 创建一个空集合，用于存储两个集合的差集。
//     - 遍历第一个集合的元素。
//     - 如果一个元素不存在于第二个集合中，则将其添加到新集合中。
//     - 返回新集合。
//   - 前提条件：无。
//
//算法的效率：
//
//- 集合操作的效率取决于集合数据结构的实现方式。常见的实现方式，如哈希集合（HashSet）或红黑树（Red-Black Tree），
//对于插入、删除和成员测试等操作，通常具有平均时间复杂度为O(1)或O(log n)的效率，其中n是集合中的元素数量。
//然而，在存在大量哈希冲突或树不平衡的情况下，最坏情况下的时间复杂度可能为O(n)。
//- 集合操作的效率还取决于元素的哈希码或比较函数的选择。对于基于哈希的集合，良好的哈希函数可以均匀地分布元素，
//减少碰撞的机会，提供高效的平均情况行为。
//- 对于并集、交集和差集操作，其效率取决于所操作集合的大小。在最坏的情况下，它们的时间复杂度为O(n)，其中n是较大集合的大小。
//
//算法的前提条件：
//
//- 要实现高效的集合操作，需要选择适当的集合数据结构实现，以提供高效的平均时间复杂度。
//- 确保集合中的元素具有良好分布的哈希码或有效的比较函数，以最小化碰撞的发生。
//- 对于并集、交集和差集操作，其效率受到集合大小的影响。如果一个集合远大于另一个集合，可能会影响性能。