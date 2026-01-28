#ifndef OBSERVER_H
#define OBSERVER_H
template<typename T> class Observer {
    public:
    Observer() = default;
    virtual ~Observer() = default;
    virtual void handleEvent(const T& event) = 0
};
#endif //OBSERVER_H