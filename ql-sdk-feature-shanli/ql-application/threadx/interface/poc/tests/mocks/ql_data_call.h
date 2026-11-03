#ifndef TEST_QL_DATA_CALL_H
#define TEST_QL_DATA_CALL_H
#include <netinet/in.h>
struct ql_data_call_info {
    int profile_idx;
    int ip_version;
    struct {
        int state;
        int reconnect;
        struct { struct in_addr ip, pri_dns, sec_dns; } addr;
    } v4;
};
int ql_get_data_call_info(int profile, int version, struct ql_data_call_info *info);
#endif
