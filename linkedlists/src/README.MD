# Get_Item
    Program needs to return cargo at the place specified.

    ```c++:
    T get_item(int pos) {
        // If the position exceeds the number of nodes, reduce it to a valid position using modulo
        if(pos > num_nodes) {pos = pos%num_nodes;}

        // Initialize a pointer to traverse the linked list, starting from the head node
        Node<T>* traveler = this->head;

        // Traverse the linked list until reaching the desired position (pos)
        for(int i = 1; i < pos; i++) {
            traveler = traveler->next;
        }
        T delivery = traveler->cargo;

        //ensure that no memory is leaked
        delete traveler;
        // Return the cargo (data) stored at the node at the specified position
        return delivery;
    }
    ```