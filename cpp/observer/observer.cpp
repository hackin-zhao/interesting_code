#include "observer.h"

namespace observer
{
    BaseObserverProtocol::BaseObserverProtocol()
    {
        setNextObserverId();
    }

    BaseObserverProtocol::BaseObserverProtocol(const BaseObserverProtocol &)
    {
        setNextObserverId();
    }

    BaseObserverProtocol::BaseObserverProtocol(BaseObserverProtocol &&)
    {
        setNextObserverId();
    }

    BaseObserverProtocol &BaseObserverProtocol::operator=(const BaseObserverProtocol &)
    {
        return *this;
    }

    BaseObserverProtocol &BaseObserverProtocol::operator=(BaseObserverProtocol &&)
    {
        return *this;
    }

    BaseObserverProtocol::~BaseObserverProtocol()
    {
        ObserverManager::unsubscribe(this);
    }

    void BaseObserverProtocol::setNextObserverId()
    {
        static id_t observersCount = 0;
        observerId = ++observersCount;
    }

    std::unordered_map<BaseObserverProtocol::id_t, void (*)(BaseObserverProtocol *)> ObserverManager::unsubscribeMap;

} // namespace observer
