# Get_Item
    Program needs to return cargo at the place specified.

    ```c++:
    T get_item(int pos) {
        // If the position exceeds the number of nodes, reduce it to a valid position using modulo
        if(pos > num_nodes) {return "Position is higher than number of nodes";}

        // Initialize a pointer to traverse the linked list, starting from the head node
        Node<T>* traveler = this->head;

        // Traverse the linked list until reaching the desired position (pos)
        for(int i = 1; i < pos; i++) {
            traveler = traveler->next;
        }

        // Return the cargo (data) stored at the node at the specified position
        return traveler->cargo;
    }
    ```

# int size()

    This program wants to return the number of items in the list. We can do this through either simply returning the num_nodes variable or through cycling through the entire list until we reach a nullptr. Note that this traversel wouldn't work for other types of linked lists like [circular linked list](https://www.geeksforgeeks.org/circular-linked-list/).
   ```c++:
    int size() {
        return this->num_nodes
    }

//Or we could traverse the entire list until we encounter a nullptr
//This would only works if the linked list is linear

    int size() {
        int count = 0;
        Node<T>* traveler = head;
        while (traveler != nullptr) {
            count++;
            traveler = traveler->next;
        }
        return count;
   }
    ```
