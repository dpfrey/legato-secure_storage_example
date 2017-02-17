#include "legato.h"
#include "interfaces.h"

COMPONENT_INIT
{
    le_secStore_ConnectService();

    le_result_t result;
    const char l_userid[] = "myid";
    const uint8_t store_buff[] = "1234567890";
    result = le_secStore_Write(l_userid, store_buff, sizeof(store_buff));
    if (result != LE_OK)
    {
        LE_FATAL("Failed to write secure storage.  Error: %s", LE_RESULT_TXT(result));
    }

    uint8_t my_buff[sizeof(store_buff)] = {0};
    size_t my_buff_size = sizeof(my_buff);
    result = le_secStore_Read(l_userid, my_buff, &my_buff_size);
    if (result != LE_OK)
    {
        LE_FATAL("Failed to read secure storage.  Error: %s", LE_RESULT_TXT(result));
    }

    LE_INFO("The read back value of '%s' is '%s'", l_userid, my_buff);
}
