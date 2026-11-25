namespace CS270 {
// Forward list
template <typename T>
forward_list<T>::forward_list() {
        head = NULL;
}

template <typename T>
void forward_list<T>::push_front(const T& v) {
        head = new Node(v, head);
}

template <typename T>
T& forward_list<T>::front() {
        return head->data;
}

template <typename T>
void forward_list<T>::pop_front() {
        if (head != NULL) {
                Node* temp = head;
                head = head->next;
                delete temp;
        }
}
template <typename T>
bool forward_list<T>::empty() {
        return head == NULL;
}

template <typename T>
void forward_list<T>::remove(const T& val) {
        Node* current = head;
        Node* previous = NULL;

        while (current != NULL) {
                if (current->data == val) {
                        if (previous == NULL) {
                                head = current->next;
                        } else {
                                previous->next = current->next;
                        }
                        Node* temp = current;
                        current = current->next;
                        delete temp;
                } else {
                        previous = current;
                        current = current->next;
                }
        }
}

template <typename T>
forward_list<T>::~forward_list() {
        while (head != NULL) {
                pop_front();
        }
}
}  // namespace CS270