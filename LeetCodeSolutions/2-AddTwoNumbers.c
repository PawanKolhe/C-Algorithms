void append(int new_val, struct ListNode ** tail) {

  ( * tail) - > next = malloc(sizeof(struct ListNode));

  ( * tail) = ( * tail) - > next;
  ( * tail) - > val = new_val;
  ( * tail) - > next = NULL;
}

struct ListNode * addTwoNumbers(struct ListNode * l1, struct ListNode * l2) {
  int carry = 0;
  int new_val = 0;
  struct ListNode * l3 = malloc(sizeof(struct ListNode));
  struct ListNode * head = NULL;
  struct ListNode * tail = NULL;

  while (l1 != NULL || l2 != NULL) {
    if (l1 == NULL) {
      new_val = l2 - > val + carry;
      l2 = l2 - > next;
      if (new_val - 10 >= 0) {
        carry = 1;
        new_val = new_val - 10;
      } else carry = 0;
    } else if (l2 == NULL) {
      new_val = l1 - > val + carry;
      l1 = l1 - > next;
      if (new_val - 10 >= 0) {
        carry = 1;
        new_val = new_val - 10;
      } else carry = 0;
    } else {
      new_val = l1 - > val + l2 - > val + carry;

      if (new_val - 10 >= 0) {
        carry = 1;
        new_val = new_val - 10;
      } else carry = 0;
      l1 = l1 - > next;
      l2 = l2 - > next;
    }
    if (head == NULL) {
      l3 - > val = new_val;
      l3 - > next = NULL;
      head = l3;
      tail = head;
    } else {
      append(new_val, & tail);
    }
  }
  if (carry) {
    append(carry, & tail);

  }

  return head;
}
