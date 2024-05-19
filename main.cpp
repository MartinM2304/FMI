#include <iostream>
#include <string>

struct IPHeader
{
	uint8_t version:4;
	uint8_t len:4;
	uint8_t serviceType=0;
	uint16_t totalLength;
	uint16_t Identification;
	uint8_t res:1;
	uint8_t dontFragment:1;
	uint8_t moreFragment:1;
	uint16_t fragmentOffset:13;
	uint8_t ttl =128; //time to live
	uint8_t protocol=6;
    uint16_t checkSum;
    uint32_t sourceIP;
    uint32_t destinationIp;

    
    IPHeader():version(4),len(5){}
};

struct EthernetHeader
{
	uint8_t destination[6];
	uint8_t source[6];
	uint16_t etherType;
};

struct HTTPHeader
{
    std::string method;
    std::string path;
    std::string version;

    HTTPHeader():method("GET"),path("/"),version("HTTP/1.1"){}

    HTTPHeader(std::string sMethod,std::string sPath, std::string sVersion): method(sMethod), path (sPath), version (sVersion){}

	std::string packedData()const {
		std::string result = method + " " + path + " " + version + "\r\n" + "\r\n";
		return result;
	}

};

struct TCPHeader
{
	uint16_t sourcePort;
	uint16_t destinationPort;
	uint32_t sequenceNumber;
	uint32_t acknowedgementNumber;
	uint8_t length:4;
	uint8_t reserved:6;
	uint8_t codeBits:6;
	uint16_t windowSize;
	uint16_t checksum;
	uint16_t urgent;
	
};
