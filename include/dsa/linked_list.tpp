template <typename T>
dsa::LinkedList<T>::LinkedList()
  : head_(nullptr),
    tail_(nullptr),
    size_(0) {}


template <typename T>
dsa::LinkedList<T>::LinkedList(const LinkedList<T>& other)
  : head_(nullptr), tail_(nullptr), size_(0)
{
    try
    {
        const Node* current = other.head_;
        while (current != nullptr)
        {
            push_back(current->data);
            current = current->next;
        }
    }
    catch (...)
    {
        clear();
        throw;
    }
}


template <typename T>
dsa::LinkedList<T>& dsa::LinkedList<T>::operator=(const LinkedList<T>& other)
{
    if (this != &other)
    {
        LinkedList<T> copy(other);
        swap(copy);
    }
    return *this;
}


template <typename T>
void dsa::LinkedList<T>::swap(LinkedList<T>& other) noexcept
{
    Node* head = head_;
    head_ = other.head_;
    other.head_ = head;

    Node* tail = tail_;
    tail_ = other.tail_;
    other.tail_ = tail;

    std::size_t size = size_;
    size_ = other.size_;
    other.size_ = size;
}


template <typename T>
dsa::LinkedList<T>::~LinkedList()
{
    Node* current = head_;

    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}


template <typename T>
std::size_t dsa::LinkedList<T>::size() const
{
    return size_;
}


template <typename T>
bool dsa::LinkedList<T>::empty() const
{
    return size_ == 0;
}


template <typename T>
void dsa::LinkedList<T>::push_front(const T& value)
{
    Node* new_node = new Node(value, head_);

    head_ = new_node;

    if (tail_ == nullptr) {
        tail_ = new_node;
    }

    ++size_;
}


template <typename T>
void dsa::LinkedList<T>::push_back(const T& value)
{
    Node* new_node = new Node(value, nullptr);

    if (head_ == nullptr)
    {
        head_ = new_node;
        tail_ = new_node;
    }
    else
    {
        tail_->next = new_node;
        tail_ = new_node;
    }

    ++size_;
}


template <typename T>
void dsa::LinkedList<T>::clear()
{
    Node* current = head_;

    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}


template <typename T>
void dsa::LinkedList<T>::iterate(std::ostream& out) const
{
    Node* temp = head_;

    while (temp != nullptr)
    {
        out << temp->data << "->";
        temp = temp->next;
    }
    out << "null";
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const dsa::LinkedList<T>& self)
{
    self.iterate(out);
    return out;
}


template <typename T>
T& dsa::LinkedList<T>::front()
{
    if (empty())
    {
        throw std::out_of_range("LinkedList::front(): list is empty");
    }

    return head_->data;
}


template <typename T>
const T& dsa::LinkedList<T>::front() const
{
    if (empty())
    {
        throw std::out_of_range("LinkedList::front(): list is empty");
    }

    return head_->data;
}


template <typename T>
T& dsa::LinkedList<T>::back()
{
    if (empty())
    {
        throw std::out_of_range("LinkedList::back(): list is empty");
    }

    return tail_->data;
}


template <typename T>
const T& dsa::LinkedList<T>::back() const
{
    if (empty())
    {
        throw std::out_of_range("LinkedList::back(): list is empty");
    }

    return tail_->data;
}

template <typename T>
void dsa::LinkedList<T>::pop_front()
{
    if (empty())
    {
        throw std::out_of_range("LinkedList::pop_front(): list is empty");
    }

    Node* old_head = head_;
    head_ = head_->next;
    delete old_head;

    --size_;

    if (head_ == nullptr)
    {
        tail_ = nullptr;
    }
}

template <typename T>
void dsa::LinkedList<T>::pop_back()
{
    if(empty())
    {
        throw std::out_of_range("LinkedList::pop_back(): list is empty");
    }

    if (head_ == tail_)
    {
        delete head_;
        
        tail_ = nullptr;
        head_ = nullptr;
        --size_;
        
        return;
    }
    
    Node* temp = head_;

    while (temp->next != tail_)
    {
        temp = temp->next;
    }

    delete tail_;
    
    tail_ = temp;
    tail_->next = nullptr;

    --size_;
}


// template <typename T>
// void dsa::LinkedList<T>::reverse(void)
// {

// }


template <typename T>
dsa::LinkedList<T> dsa::LinkedList<T>::deep_copy(const dsa::LinkedList<T>& other)
{
    LinkedList<T> list;
    const Node* temp = other.head_;

    while (temp)
    {
        list.push_back(temp->data);
        temp = temp->next;
    }

    return list;
}
