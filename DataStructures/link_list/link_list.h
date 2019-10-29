#ifndef CIRCULAR_LINKED_LIST
#define CIRCULAR_LINKED_LIST

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

  /**
   * @brief A node holds a pointer to the user-defined
   * element required to be stored, a pointer to
   * the next element in the list, and a pointer to
   * the previous element in the list.
   */
  typedef struct node_t
  {
    void*           element;
    struct node_t*	next;
    struct node_t*	prev;
  } node_t;
  
  /**
   * @brief Definition of the circular doubly linked-list.
   * It holds informations about the current size
   * of the list, a pointer to the head node of the list,
   * and a pointer to the tail of the list.
   */
  typedef struct list_t
  {
    size_t		    size;
    struct node_t*	head;
    struct node_t*	tail;
  } list_t;
  
  /**
   * @brief The list iterator structure allows
   * to memorize a pointer to a `node_t`. It also holds
   * a pointer to the list the node belongs to.
   * The `data` pointer is reserved for future usage.
   * @see list_make_iterator
   */
  typedef struct list_iterator_t
  {
    list_t*		list;
    node_t*     current;
    void*       data;
  } list_iterator_t;
  
  /**
   * @brief A predicate type to be used when iterating over
   * each node of the list.
   * @see list_iterate_over_nodes
   */
  typedef int (*list_predicate_t)(size_t index, node_t* node, void* data);
  
  /**
   * @brief Creates a new instance of a `list_t`.
   * @return a pointer to the created list.
   */
  list_t* list_create();
  
  /**
   * @brief Same as `list_create` except no dynamic
   * allocation on the heap will be perform to create
   * the list.
   * @return a list_t value
   */
  list_t list_create_static();
  
  /**
   * @brief Clears the list by deleting every node in it.
   * The list will still be usable after this call.
   */
  void list_clear(list_t* list);
  
  /**
   * @brief Destroys every element of the given `list` and
   * frees the memory allocated by the `list`. The given pointer
   * will not be usable after a call to this function.
   */
  void list_destroy(list_t* list);
  
  /**
   * @brief Adds a new element to the `list`. This will cause a new `node_t`
   * to be created, holding the given `element` and pushed at the front of the
   * given `list`.
   * @return a pointer to the newly created node.
   */
  node_t* list_push_front(list_t* list, void* element);
  
  /**
   * @brief Adds a new element to the `list`. This will cause a new `node_t`
   * to be created, holding the given `element` and pushed to the back of the
   * given `list`.
   * @return a pointer to the newly created node.
   */
  node_t* list_push_back(list_t* list, void* element);
  
  /**
   * @brief Allows to iterate over each node held by the list by pushing
   * each of them to the given `iterator`.
   */
  void list_iterate_over_nodes(const list_t* list, list_predicate_t iterator, void* data);
  
  /**
   * @brief Searches the list for the given `node`.
   * @return the found node if any, NULL otherwise.
   */
  node_t* list_find_node(const list_t* list, const node_t* node);
  
  /**
   * @brief Finds an element using the return value of the given `predicate`.
   * @return the node matching the given predicate.
   */
  node_t* list_find_node_if(const list_t* list, list_predicate_t iterator, void* data);
  
  /**
   * @brief Removes the given `node` from the `list`
   * and frees the memory allocated by the `node`.
   * @return a positive value if the given `node` has
   * been successfully removed from the `list`, a negative
   * value otherwise.
   */
  int list_remove_node(list_t* list, node_t* node);
  
  /**
   * @brief Conditionally removes a node from the list based on the return
   * value of the given `predicate`.
   * @return the number of removed nodes.
   */
  int list_remove_node_if(list_t* list, list_predicate_t predicate, void* data);

  /**
   * @return the size of the given `list`. That is, the number of nodes currently
   * held by the list.
   */
  size_t list_get_size(const list_t* list);
  
  /**
   * @return a positive value if the given `list` is
   * empty, zero otherwise.
   */
  int list_is_empty(const list_t* list);
  
  /**
   * @brief Removes the node associated with the given node pointer
   * from the list.
   * @return the pointer held by the removed node.
   */
  void*	list_pop_node(list_t* list, node_t* node);
  
  /**
   * @brief Removes the node located at the head of the list.
   * @return the pointer held by the removed node.
   */
  void*	list_pop_back(list_t* list);
  
  /**
   * @brief Removes the node located at the tail of the list.
   * @return the pointer held by the removed node.
   */
  void*	list_pop_front(list_t* list);
  
  /**
   * @return a new instance of an iterator. The iterator's current node
   * will be `node` if the given pointer is non-NULL, or the head of the
   * given `list` otherwise.
   */
  list_iterator_t list_make_iterator(list_t* list, node_t* node);
  
  /**
   * @return whether it is possible to go forward in the list.
   */
  int list_iterator_has_next(const list_iterator_t* it);
  
  /**
   * @return whether it is possible to go backward in the list.
   */
  int list_iterator_has_prev(const list_iterator_t* it);
  
  /**
   * @brief Moves the iterator's current node pointer forward. If
   * it is not possible to do so, the function will not modify the
   * iterator's current node pointer.
   * @return the current node if moving forward succeeded,
   * NULL otherwise.
   */
  node_t* list_iterator_next(list_iterator_t* it);

  /**
   * @brief Moves the iterator's current node pointer backward. If
   * it is not possible to do so, the function will not modify the
   * iterator's current node pointer.
   * @return the current node if moving backward succeeded,
   * NULL otherwise.
   */
  node_t* list_iterator_prev(list_iterator_t* it);
  
  /**
   * @brief Removes the current node from the list.
   * @return a positive value if the removal succeeded,
   * zero otherwise.
   */
  int list_iterator_remove(list_iterator_t* it);
  
  /**
   * @brief Creates a new node instance initialized
   * with the given `element`.
   * @return a new instance of a `node_t`.
   */
  node_t* node_new(void* element);

#ifdef __cplusplus
}
#endif

#endif
