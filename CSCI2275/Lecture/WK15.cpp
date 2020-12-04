/* HASH TABLES:
 * 
 * Map - stores data as key-value pairs similar to python dictionaries.
 * Hash Table - implementation of a map (may be reffered to as a hash map).
 *  - Uses a parameter of the data called a key to map the data into an array.
 *  - Two components of our hash table.
 *      - Array where the data is stored.
 *      - Hash function that generates the mapping.
 * EX: hash table to store movie data
 *  Movie:
 *      string title
 *      int ranking
 *      int year
 * 
 * Use the title as the key.
 * Convert title string into some integer that will be the array index where each movie is stored.
 *  - give title to hash function which spits out an index in the array.
 * 
 * Hash Functions:
 *  - Simplest possible is to sum up the ascii values in key and mod by array size.
 *  - hashSum(key, arraySize)
 *      sum = 0
 *      for x = 0; x < key.size(); x++
 *          sum = sum + key[x]
 *      sum = sum%arraySize
 *      return Sum
 * 
 * To Retrieve Data:
 * 1. Calculate index for search.
 * 2. Read from that index.
 * 
 * Both Readin and Storign data is consatant time (time to access an index in an array)
 * 
 * Collisions:
 *  - Two Keys hash to the same index
 *  - Two strings "Go Cat Go" and "Go Dog Go" = 724 
 *  - Formally: "For given hash function, h, a collision occurs when h(k1) = h(k2), when k1 != k2 and k1 and k2 are keys."
 * 
 * Approaches to Collision Resolution:
 * - Collisions Happen... how do we store that data anyway?
 * - 2 Common Approaches:
 *      - Chaining
 *      - Open Addressing
 * 
 * Chaining:
 * - Additional data structure at each index of the table that can store more than 1 record for that index.
 *      - LL, BST, Array, etc.
 * - Set up hash table to be an array of pointers.
 *      - Add record to table: updated to point to the head of a linked list.
 * 
 * Ex: 
 * - "The Godfather" = 1237%7 = 5
 * - "The Usual Suspects" = 1733%7 = 4
 * - "Casablanca" = 985%7 = 5
 * - "Whiplash" = 832%7 = 6
 * index 4 --> The usual suspecs
 * index 5 --> The godfather --> Casablanca
 * index 6 --> Whiplash
 * 
 * 
 * Open Addressing (Less popular than chaining):
 * - All records store directly in the array (no auxillary data structures)
 * - If there is a collision, put into first available index (simplest way is just the next open index in the table)
 * - challeneges: data can be clustered around certain indeces, and delting a record can mean an expensive data shift.