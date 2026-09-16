#include "Connection.h"
#include "Room.h"

Connection::Connection(Room& destinationRoom, bool locked, const std::string& requiredKey)
    : destinationRoom(&destinationRoom), locked(locked), requiredKey(requiredKey)
{
}

Room* Connection::getDestinationRoom() const
{
    return destinationRoom;
}

bool Connection::isLocked() const
{
    return locked;
}

const std::string& Connection::getRequiredKey() const
{
    return requiredKey;
}

bool Connection::tryUnlock(const std::string& keyName)
{
    if (!locked)
    {
        return true;
    }

    if (keyName == requiredKey)
    {
        locked = false;
        return true;
    }

    return false;
}