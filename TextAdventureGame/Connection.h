#pragma once


#include <string>

class Room;

class Connection
{
private:

    Room* destinationRoom;
    bool locked;
    std::string requiredKey;

public:

    Connection(Room& destinationRoom, bool locked, const std::string& requiredKey);

    Room* getDestinationRoom() const;
    bool isLocked() const;
    const std::string& getRequiredKey() const;

    bool tryUnlock(const std::string& keyName);
};