
#include "mac_link.h"
#include "PN532_debug.h"

int8_t MACLink::activateAsTarget(uint16_t timeout)
{
	Serial.println("MACLink::activateAsTarget-0");//LADebug
	pn532.begin();
	Serial.println("MACLink::activateAsTarget-1");//LADebug
	pn532.SAMConfig();
	Serial.println("MACLink::activateAsTarget-2");//LADebug
    return pn532.tgInitAsTarget(timeout);

}

bool MACLink::write(const uint8_t *header, uint8_t hlen, const uint8_t *body, uint8_t blen)
{
    return pn532.tgSetData(header, hlen, body, blen);
}

int16_t MACLink::read(uint8_t *buf, uint8_t len)
{
    return pn532.tgGetData(buf, len);
}
