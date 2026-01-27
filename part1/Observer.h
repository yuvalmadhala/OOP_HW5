template<class T> class Observer {
    public:
    Observer() = default;
    virtual ~Observer() = default;
    virtual void handleEvent(const T& event) = 0
};