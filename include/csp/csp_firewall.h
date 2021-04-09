#pragma once

typedef struct csp_allow_list_s {
	uint16_t src;
	uint16_t src_mask;
	uint16_t dst;
	uint16_t dst_mask;
	uint8_t sport;
	uint8_t sport_mask;
	uint8_t dport;
	uint8_t dport_mask;

	struct csp_allow_list_s *next;
} csp_allow_list_t;

int csp_firewall_allow(csp_allow_list_t *entry, csp_packet_t *packet);