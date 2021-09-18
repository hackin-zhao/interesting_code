#if !defined(_OBSERVER_H_)
#define _OBSERVER_H_

#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <memory>

namespace observer
{
    class ObserverManager;

    class BaseObserverProtocol
    {
        friend class ObserverManager;

    public:
        BaseObserverProtocol();
        BaseObserverProtocol(const BaseObserverProtocol &);
        BaseObserverProtocol(BaseObserverProtocol &&);
        BaseObserverProtocol &operator=(const BaseObserverProtocol &);
        BaseObserverProtocol &operator=(BaseObserverProtocol &&);
        virtual ~BaseObserverProtocol();

    private:
        void setNextObserverId();

    private:
        using id_t = uint64_t;
        id_t observerId;
    };

    template <typename T>
    class ObserverContainer
    {
        friend class ObserverManager;

    private:
        static std::unordered_set<T *> observers;

        static void addObserver(T *obs)
        {
            observers.insert(obs);
        }

        static void removeObserver(BaseObserverProtocol *observer)
        {
            observers.erase(static_cast<T *>(observer));
        }

        static void clear()
        {
            observers.clear();
        }
    };

    template <typename T>
    std::unordered_set<T *> ObserverContainer<T>::observers;

    class ObserverManager
    {
    public:
        template <class P, class O>
        static void subscribe(O *observer)
        {
            static_assert(std::is_base_of<BaseObserverProtocol, O>::value,
                          "All observers must inherit from BaseObserverProtocol");
            if (observer == nullptr)
                return;

            unsubscribeMap[observer->P::observerId] = &ObserverContainer<P>::removeObserver;
            ObserverContainer<P>::addObserver(observer);
        }

        template <class P, class O>
        static void subscribe(const std::shared_ptr<O> &observer)
        {
            subscribe<P>(observer.get());
        }

        template <class P, typename... MethodArgumentTypes, typename... ActualArgumentTypes>
        static void notify(void (P::*method)(MethodArgumentTypes...), ActualArgumentTypes... args)
        {
            std::vector<std::pair<P *, BaseObserverProtocol::id_t>> observers;
            for (const auto &o : ObserverContainer<P>::observers)
            {
                observers.push_back(std::make_pair(o, o->observerId));
            }

            for (const auto &p : observers)
            {
                if (unsubscribeMap.find(p.second) == std::end(unsubscribeMap))
                    continue;

                (p.first->*method)(args...);
            }
        }

        template <class P>
        static void unsubscribe(P *observer)
        {
            if (observer == nullptr)
                return;

            auto id = observer->P::observerId;
            auto it = unsubscribeMap.find(id);
            if (it == std::end(unsubscribeMap))
                return;

            auto ptr = it->second;
            if (ptr != nullptr)
                ptr(observer);

            unsubscribeMap.erase(id);
        }

        template <class P>
        static void unsubscribe(const std::shared_ptr<P> &observer)
        {
            unsubscribe<P>(observer.get());
        }

        template <class P>
        static void clear()
        {
            ObserverContainer<P>::clear();
            unsubscribeMap.clear();
        }

    private:
        static std::unordered_map<BaseObserverProtocol::id_t, void (*)(BaseObserverProtocol *)> unsubscribeMap;
    };
} // namespace observer

#endif // _OBSERVER_H_
