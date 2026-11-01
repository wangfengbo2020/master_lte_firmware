#ifndef BT_API_LE_DEMO_H
#define BT_API_LE_DEMO_H

// gap name
void gap_name_demo_register(void);

// hid
void ble_hid_demo_register(void);

// ancs
void ancs_demo_register(void);

// auto test
void auto_test_server_init(void);
void auto_test_client_init(void);
void auto_test_config(unsigned char command, unsigned char test_mode, unsigned int size);

// ams
void appbt_le_ams_register(void);
void appbt_le_ams_command_play(void);
void appbt_le_ams_command_pause(void);
void appbt_le_ams_command_next_track(void);
void appbt_le_ams_command_previous_track(void);
void appbt_le_ams_command_volume_up(void);
void appbt_le_ams_command_volume_down(void);
void appbt_le_ams_entity_player_enable(void);
void appbt_le_ams_entity_player_disable(void);
void appbt_le_ams_entity_track_enable(void);
void appbt_le_ams_entity_track_disable(void);

#endif
