//Collision resolution refers to the process of handling collisions that occur when two or more keys are mapped to the same hash value in a hash table.When collisions happen, it becomes necessary to resolve them to ensure that each key can be stored and retrieved correctly.There are several collision resolution algorithms, but two commonly used ones are :
//
//1. Separate Chaining :
//-Approach : Separate chaining handles collisions by maintaining a linked list of key - value pairs at each index of the hash table.When a collision occurs, the new key - value pair is simply appended to the linked list at the corresponding index.
//- Advantages : Simple implementation, efficient for handling a large number of collisions, and doesn't require resizing of the hash table.
//- Disadvantages : Additional memory overhead due to the linked lists, and some cache inefficiency if the linked lists become long.
//
//2. Open Addressing :
//-Approach : Open addressing resolves collisions by searching for an alternative empty slot in the hash table and placing the collided key - value pair there.There are multiple variations of open addressing, including Linear Probing, Quadratic Probing, and Double Hashing.
//- Linear Probing : After a collision, the algorithm probes the next available slot(linearly incrementing the index) until an empty slot is found.
//- Quadratic Probing : The algorithm uses a quadratic function to probe subsequent slots(incrementing the index by a quadratic sequence) until an empty slot is found.
//- Double Hashing : The algorithm uses a secondary hash function to determine the interval between probes.It probes additional slots by applying the secondary hash function until an empty slot is found.
//- Advantages : Better cache performance because all elements are stored in contiguous memory locations.It requires less memory overhead than separate chaining.
//- Disadvantages : Can have more clustering issues if the hash table becomes crowded.It requires careful selection of probing techniques and resizing of the hash table when it becomes full.
//
//Both separate chaining and open addressing provide effective ways to handle collisions, and the choice between them depends on factors such as the expected number of collisions, memory constraints, and performance requirements.It's important to select an appropriate collision resolution algorithm based on the specific characteristics of the data being hashed.

//碰撞解决是在哈希的上下文中使用时，用来处理哈希表中发生的键冲突的过程。当两个或多个键映射到哈希表中的同一哈希值时，
//必须解决冲突，以确保每个键可以正确地存储和检索。有几种碰撞解决算法，其中两种常用的是：
//
//1. 链地址法（Separate Chaining）：
//- 方法：链地址法通过在哈希表的每个索引处维护一个键值对的链表来处理冲突。当发生冲突时，
//新的键值对被追加到相应索引处的链表中。
//- 优点：实现简单，适用于处理大量冲突，不需要调整哈希表的大小。
//- 缺点：链表会造成额外的内存开销，如果链表变得很长，可能会导致一些缓存效率问题。
//
//2. 开放地址法（Open Addressing）：
//- 方法：开放地址法通过在哈希表中搜索替代的空槽来解决冲突，并将冲突的键值对放置在那里。
//开放地址法有几种变种，包括线性探测、二次探测和双重散列。
//- 线性探测：发生冲突后，算法线性地递增索引，直到找到空槽。
//- 二次探测：算法使用二次函数来递增索引，直到找到空槽。
//- 双重散列：算法使用第二个哈希函数来确定探测的间隔，直到找到空槽。
//- 优点：由于所有元素存储在连续的内存位置上，具有更好的缓存性能。比链地址法需要更少的内存开销。
//- 缺点：如果哈希表变得拥挤，可能会出现更多的聚集问题。需仔细选择探测方法，并在哈希表满时调整其大小。
//
//链地址法和开放地址法都提供了有效的碰撞解决方法，选择哪种方法取决于预期的冲突数量、内存限制和性能要求。
//根据要哈希的数据的特性，选择适当的碰撞解决算法非常重要。




















