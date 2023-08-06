//There are several hashing approaches used in computer science, each with its own advantages and disadvantages.Here are five commonly used hashing approaches :
//
//1. Division Hashing :
//-Approach : In this method, the key is divided by the table size, and the remainder is used as the hash value.
//- Advantages : It is a simple and straightforward approach.The structure of the key does not affect the hash value.
//- Disadvantages : This method can cause clustering issues when there is a correlation between the key values and
//the table size.It may lead to poor distribution of hash values.
//
//2. Multiplication Hashing :
//-Approach : The key is multiplied by a constant factor(typically between 0 and 1), and the fractional part is used as
//the hash value.
//- Advantages : It provides a more uniform distribution of hash values compared to division hashing.It reduces clustering
//and collisions.
//- Disadvantages : It requires careful selection of the constant factor for optimal performance.It is slower than division
//hashing due to the multiplication operation.
//
//3. Folding Hashing :
//-Approach : The key is divided into equal - sized parts, which are then added or XORed together to obtain the hash value.
//- Advantages : It helps in reducing clustering and collisions when certain patterns might cause issues with other hashing
//methods.
//- Disadvantages : Folding hashing can be slower compared to simpler hashing methods.The division of the key into equal
//parts might not always be straightforward.
//
//4. Mid - Square Hashing :
//-Approach : The key is squared, and the middle portion of the resulting value is used as the hash value.
//- Advantages : It provides a more uniform distribution of hash values.It works well for numeric keys.
//- Disadvantages : The method can be inefficient for larger key sizes.It may lead to more collisions if the key size is large.
//
//5. Cryptographic Hashing :
//-Approach : Cryptographic hash functions like MD5, SHA - 1, SHA - 256, etc., are used to generate hash values from keys.
//- Advantages : Cryptographic hash functions provide a uniform distribution of hash values and high security.
//They are resistant to tampering and have a low probability of collisions.
//- Disadvantages : Cryptographic hashing can be slower compared to other methods.The generated hash values are irreversible.
//
//When selecting a hashing approach, consider factors such as the distribution of keys, size of the hash table,
//speed requirements, security needs, and the possibility of collisions.It's important to choose an approach that
//provides a good balance between distribution, efficiency, and collision avoidance for the specific use case.
//
//计算机科学中有几种常用的哈希方法，每种方法都有其优缺点。以下是五种常见的哈希方法及其优缺点：
//
//1. 除法哈希法：
//- 方法：将键除以哈希表大小，然后使用余数作为哈希值。
//- 优点：简单直观，键的结构不会影响哈希值。
//- 缺点：当键的值与哈希表大小相关联时，可能会导致聚集问题，哈希值分布不均匀。
//
//2. 乘法哈希法：
//- 方法：将键乘以一个常数因子（通常在0到1之间），然后使用小数部分作为哈希值。
//- 优点：相比除法哈希，在分布上提供了更均匀的哈希值，减少了聚集和冲突。
//- 缺点：需要精心选择常数因子以获得最佳性能，由于乘法运算，速度比除法哈希慢一些。
//
//3. 折叠哈希法：
//- 方法：将键分为相等大小的部分，然后将这些部分相加或进行异或运算得到哈希值。
//- 优点：在某些情况下，可以减少聚集和冲突问题。
//- 缺点：相对于更简单的哈希方法，折叠哈希可能较慢。将键平均分割成等长部分可能不总是简单的。
//
//4. 中平方哈希法：
//- 方法：将键平方，然后使用结果的中间部分作为哈希值。
//- 优点：提供较为均匀的哈希值分布，对于数字键尤其有效。
//- 缺点：对于较大的键尺寸，该方法可能效率低下。如果键尺寸较大，可能会导致更多的冲突。
//
//5. 加密哈希法：
//- 方法：使用MD5、SHA - 1、SHA - 256等加密哈希函数从键生成哈希值。
//- 优点：加密哈希函数提供了均匀的哈希值分布和较高的安全性，可以防止篡改，碰撞概率较低。
//- 缺点：与其他方法相比，加密哈希可能较慢，生成的哈希值是不可逆的。
//
//在选择哈希方法时，需要考虑键的分布情况、哈希表大小、速度要求、安全性需求以及可能的冲突情况。重要的是选择一种在特定情况下在分布、效率和冲突避免方面提供良好平衡的方法。