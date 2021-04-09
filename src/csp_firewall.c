#include <csp/csp.h>
#include <sys/queue.h>

int csp_firewall_allow(csp_allow_list_t *entry, csp_packet_t *packet) {
	while (entry) {
		if ((packet->id.src & entry->src_mask) != (entry->src & entry->src_mask))
			continue;
		if ((packet->id.dst & entry->dst_mask) != (entry->dst & entry->dst_mask))
			continue;
		if ((packet->id.sport & entry->sport_mask) != (entry->sport & entry->sport_mask))
			continue;
		if ((packet->id.dport & entry->dport_mask) != (entry->dport & entry->dport_mask))
			continue;

		// Match!
		return 1;
	}

	return 0;
}
