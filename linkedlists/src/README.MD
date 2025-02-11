# Get_Item
    Program needs to return cargo at the place specified.

    ```c++:
    T get_item(int pos) {
        if(pos > num_nodes) {pos = pos%num_nodes;}
        Node<T>* traveler = this->head;
        for(int i = 1; i < pos; i++) {
            traveler = traveler->next;
        }
        return traveler->cargo;
    }
    ```