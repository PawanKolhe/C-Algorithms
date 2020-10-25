#include "link_list.h"

/**
 * @brief Creates a new instance of a `list_t`.
 * @return a pointer to the created list.
 */
list_t*	list_create()
{
  list_t*	list;
    
  list = malloc(sizeof(*list));
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  return (list);
}

/**
 * @brief Same as `list_create` except no dynamic
 * allocation on the heap will be perform to create
 * the list.
 * @return a list_t value
 */
list_t list_create_static()
{
  return ((list_t) {
      .size = 0,
      .head = NULL,
      .tail = NULL
  });
}

/**
 * @brief Clears the list by deleting every node in it.
 * The list will still be usable after this call.
 */
void list_clear(list_t* list)
{
  node_t* node = list->head;
  
  while (!list_is_empty(list)) {
    node_t* next = node->next;
    
    list_remove_node(list, node);
    node = next;
  }
}

/**
 * @brief Destroys every element of the given `list` and
 * frees the memory allocated by the `list`. The given pointer
 * will not be usable after a call to this function.
 */
void list_destroy(list_t* list)
{
  list_clear(list);
  free(list);
}

/**
 * @brief Allows to iterate over each node held by the list by pushing
 * each of them to the given `iterator`.
 */
void list_iterate_over_nodes(const list_t* list, list_predicate_t iterator, void* data)
{
  node_t* node = list->head;
  
  for (size_t i = 0; i < list->size; ++i) {
    if (iterator(i, node, data) < 0) {
      break;
    }
    node = node->next;
  }
}

/**
 * @brief Searches the list for the given `node`.
 * @return the found node if any, NULL otherwise.
 */
node_t*	list_find_node(const list_t* list, const node_t* element)
{
  node_t* node = list->head;
  
  for (size_t i = 0; i < list->size; ++i) {
    if (node == element) {
      return (node);
    }
    node = node->next;
  }
  return (NULL);
}

/**
 * @brief Finds an element using the return value of the given `predicate`.
 * @return the node matching the given predicate.
 */
node_t*	list_find_node_if(const list_t* list, list_predicate_t iterator, void* data)
{
  node_t* node = list->head;
  
  for (size_t i = 0; i < list->size; ++i) {
    if (iterator(i, node, data)) {
      return (node);
    }
    node = node->next;
  }
  return (NULL);
}

/**
 * @return the size of the given `list`. That is, the number of nodes currently
 * held by the list.
 */
size_t list_get_size(const list_t* list)
{
  return (list->size);
}

/**
 * @return a positive value if the given `list` is
 * empty, zero otherwise.
 */
int	list_is_empty(const list_t* list)
{
  return (list_get_size(list) == 0);
}

/**
 * @brief Creates a new node instance initialized
 * with the given `element`.
 * @return a new instance of a `node_t`.
 */
node_t* node_new(void* element)
{
  node_t* node;
  
  node = malloc(sizeof(*node));
  node->element = element;
  node->next = NULL;
  node->prev = NULL;
  return (node);
}

/**
 * @brief Adds a new element to the `list`. This will cause a new `node_t`
 * to be created, holding the given `element` and pushed at the front of the
 * given `list`.
 * @return a pointer to the newly created node.
 */
node_t*	list_push_front(list_t* list, void* element)
{
  node_t* node = node_new(element);
  node_t* head = list->head;
  
  if (head) {
    // Binding the node to the list elements.
    node->next = head;
    node->prev = head->prev;
    // Binding the list elements to the node.
    head->prev->next = node;
    head->prev = node;
  } else {
    node->next = node;
    node->prev = node;
    list->tail = node;
  }
  list->head = node;
  list->size++;
  return (node);
}

/**
 * @brief Adds a new element to the `list`. This will cause a new `node_t`
 * to be created, holding the given `element` and pushed to the back of the
 * given `list`.
 * @return a pointer to the newly created node.
 */
node_t*	list_push_back(list_t* list, void* element)
{
  node_t* node = node_new(element);
  node_t* tail = list->tail;

  if (tail) {
    // Binding the node to the list elements.
    node->next = tail->next;
    node->prev = tail;
    // Binding the list elements to the node.
    tail->next->prev = node;
    tail->next = node;
  } else {
    node->next = node;
    node->prev = node;
    list->head = node;
  }
  list->tail = node;
  list->size++;
  return (node);
}

/**
 * @brief Removes the node associated with the given node pointer
 * from the list.
 * @return the pointer held by the removed node.
 */
void* list_pop_node(list_t* list, node_t* node)
{
  void* element;
  
  if (!node) {
    return (NULL);
  }
  element = node->element;
  list_remove_node(list, node);
  return (element);
}

/**
 * @brief Removes the node located at the head of the list.
 * @return the pointer held by the removed node.
 */
void* list_pop_back(list_t* list)
{
  return (list_pop_node(list, list->tail));
}

/**
 * @brief Removes the node located at the tail of the list.
 * @return the pointer held by the removed node.
 */
void* list_pop_front(list_t* list)
{
  return (list_pop_node(list, list->head));
}

/**
 * @return a new instance of an iterator. The iterator's current node
 * will be `node` if the given pointer is non-NULL, or the head of the
 * given `list` otherwise.
 */
list_iterator_t list_make_iterator(list_t* list, node_t* node)
{
  return ((list_iterator_t) {
      .current = (node != NULL ? node : list->head != NULL ?
		  list->head->prev : NULL),
      .list = list
  });
}

/**
 * @return whether it is possible to go forward in the list.
 */
int list_iterator_has_next(const list_iterator_t* it)
{
  return (it->current != NULL && it->current->next != NULL);
}

/**
 * @return whether it is possible to go backward in the list.
 */
int list_iterator_has_prev(const list_iterator_t* it)
{
  return (it->current != NULL && it->current->prev != NULL);
}

/**
 * @brief Removes the current node from the list.
 * @return a positive value if the removal succeeded,
 * zero otherwise.
 */
int list_iterator_remove(list_iterator_t* it)
{
  node_t* current = it->current;
  
  if (!current)
    return (0);
  if (current == current->next)
    it->current = NULL;
  else
    it->current = current->next;
  return (list_remove_node(it->list, current));
}

/**
 * @brief Moves the iterator's current node pointer forward. If
 * it is not possible to do so, the function will not modify the
 * iterator's current node pointer.
 * @return the current node if moving forward succeeded,
 * NULL otherwise.
 */
node_t* list_iterator_next(list_iterator_t* it)
{
  if (!list_iterator_has_next(it)) {
    return (NULL);
  }
  return (it->current = it->current->next);
}

/**
 * @brief Moves the iterator's current node pointer backward. If
 * it is not possible to do so, the function will not modify the
 * iterator's current node pointer.
 * @return the current node if moving backward succeeded,
 * NULL otherwise.
 */
node_t* list_iterator_prev(list_iterator_t* it)
{
  if (!list_iterator_has_prev(it)) {
    return (NULL);
  }
  return (it->current = it->current->prev);
}

/**
 * @brief Removes the given `node` from the `list`
 * and frees the memory allocated by the `node`.
 * @return a positive value if the given `node` has
 * been successfully removed from the `list`, a negative
 * value otherwise.
 */
int	list_remove_node(list_t* list, node_t* node)
{
  node_t* found = list_find_node(list, node);
  
  if (found != NULL) {
    found->prev->next = found->next;
    found->next->prev = found->prev;
    if (list->head == found) {
      list->head = found->next;
    }
    if (list->tail == found) {
      list->tail = found->prev;
    }
    list->size--;
    if (list->size == 0) {
      list->tail = NULL;
      list->head = NULL;
    }
    free(found);
    return (1);
  }
  return (0);
}

/**
 * @brief Conditionally removes a node from the list based on the return
 * value of the given `predicate`.
 * @return the number of removed nodes.
 */
int	list_remove_node_if(list_t* list, list_predicate_t iterator, void* data)
{
  node_t* node = list->head;
  int removed  = 0;
  
  for (size_t i = 0; i < list->size; ++i) {
    node_t* next = node->next;
    
    if (iterator(i, node, data)) {
      list_remove_node(list, node);
      removed++;
      i -= 1;
    }
    node = next;
  }
  return (removed);
}
