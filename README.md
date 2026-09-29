# Carlpp
C++ in short.

My attempt at a reimplementation of (most of) the C++ standard library from scratch, as well as some other common data structures. 

## Roadmap
### Containers
- [x] vector - implemented using three pointers (start, end, end_of_allocation) and an allocator object in the vector.
- [ ] copy-swap-buffer - buffer implemented using the copy & swap idiom
- [ ] list
- [ ] deque
- [ ] array
- [ ] queue, stack
- [ ] priority queue, heap
- [ ] map, set
- [ ] unordered_map, unordered_set
- [ ] string

### Pointers
- [ ] move, swap
- [ ] unique_ptr, make_unique
- [ ] shared_ptr, weak_ptr, make_shared

### OS 
- [ ] LRU cache
- [ ] Arena/Linear allocator
- [ ] Pool allocator

### Concurrency
- [ ] Mutex
- [ ] Semaphore
- [ ] Locks

### Others
- [ ] optional
- [ ] any
- [ ] variant
- [ ] bump/arena allocator
- [ ] SPSC Queue
- [ ] Ring Buffer
