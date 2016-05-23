#include "PureDirectoryDevice.h"

PureDirectoryDevice::PureDirectoryDevice(PureManager * pm,
                                         ros::NodeHandle * nh,
                                         std::string server,
                                         const std::string& topic_name):
PureDevice(pm, nh, server, 0, topic_name)
{
}

bool PureDirectoryDevice::connect()
{
  //get directory entries
  rxSize = 0;
  int res = request(ActionCode.GET, device, rxBuff, rxSize);
  if (res != 0)
  {
    request_error(res, ActionCode.GET);
    return false;
  }

  /*
  std::cerr << "received: " <<std::endl;
  for (unsigned int i =0; i< rxSize; ++i)
      std::cerr << std::hex << (int)rxBuff[i] << ":";
  std::cerr << std::endl;
*/
  unsigned int n = rxSize/sizeof(PureDirectoryEntry);
  ROS_INFO("There are %u services in server %s:", n, server.c_str());

  std::memset(rxBuff, 0, rxSize);
  for (unsigned int i = 0; i< n; ++i)
  {
    PureDirectoryQueryRequest qreq;
    qreq.instance = i;
    rxSize = sizeof(qreq);
    memcpy(rxBuff, &qreq,rxSize);
    int res = request(ActionCode.QUERY, device, rxBuff, rxSize);
    if (res != 0)
    {
      request_error(res, ActionCode.QUERY);
      return false;
    }

    /*
    std::cerr << "received: " <<std::endl;
    for (unsigned int j =0; j< rxSize; ++j)
        std::cerr << std::hex << (int)rxBuff[j] << ":";
    std::cerr << std::endl;
    */
    PureDirectoryQueryResponse * qres = reinterpret_cast<PureDirectoryQueryResponse *>( rxBuff);

    ROS_INFO("Instance %d: %s", i, qres->name);
    std::memset(rxBuff, 0, rxSize);
  }

  return true;
}

void PureDirectoryDevice::createTopics()
{}
