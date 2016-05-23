#ifndef PUREDIRECTORYDEVICE_H
#define PUREDIRECTORYDEVICE_H

#include "PureDevice.h"


class PureDirectoryDevice : public PureDevice
{

public:
  PureDirectoryDevice(PureManager * pm, ros::NodeHandle * nh, std::string server, const std::string& topic_name);
    virtual bool connect();
    virtual void createTopics();

private:
    struct PureDirectoryEntry
    {
      unsigned short type;
      unsigned short instance;
    }__attribute__ ((__packed__));

    struct PureDirectoryServiceResponse
    {
      //unsigned int number_of_entries;
      PureDirectoryEntry entries[0];
    }__attribute__ ((__packed__));

    struct PureDirectoryQueryRequest {
      unsigned short instance;
    }__attribute__ ((__packed__));

    struct PureDirectoryQueryResponse {
      char name[0];
    }__attribute__ ((__packed__));
};

#endif // PUREDIRECTORYDEVICE_H
