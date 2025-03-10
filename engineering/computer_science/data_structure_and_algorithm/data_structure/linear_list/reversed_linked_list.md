### Reverse Linked List

The core idea is to maintain **three** node as we proceeded through the linked list. Why three? Consider how we turn `A->B->C` to `A<-B<-C`. The first step is to change the `B->next` from C to A, once this has completed, the pointers' direction becomes `A<->B C`. That is, the linked list has been broken into two parts and no one knows where C is if the information is not restored preserved previously.

implementations reference:

- C++: lintcode0035
