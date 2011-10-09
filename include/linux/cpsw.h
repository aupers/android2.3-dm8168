#ifndef __CPSW_H__
#define __CPSW_H__

#include <linux/if_ether.h>

struct cpsw_slave_data {
	u32		slave_reg_ofs;
	u32		sliver_reg_ofs;
	const char	*phy_id;
	int		phy_if;
	u8	mac_addr[ETH_ALEN];
};

struct cpsw_platform_data {
	u32	ss_reg_ofs;	/* Subsystem control register offset */
	int	channels;	/* number of cpdma channels (symmetric) */
	u32	cpdma_reg_ofs;	/* cpdma register offset */

	int	slaves;		/* number of slave cpgmac ports */
	struct cpsw_slave_data	*slave_data;

	u32	ale_reg_ofs;	/* address lookup engine reg offset */
	int	ale_entries;	/* ale table size */

	u32	host_port_reg_ofs; /* cpsw cpdma host port registers */

	u32	hw_stats_reg_ofs;  /* cpsw hardware statistics counters */

	u8	mac_addr[ETH_ALEN];

	int	rx_descs;

	void	(*phy_control)(bool enabled);

	u32	mac_control;

	u32	gigabit_en; /* Is gigabit capable AND enabled */
	u32	rmii_en; /* Is RMII mode capable AND enabled */
	u32	host_port_num; /* The port number for the host port */
};

#endif /* __CPSW_H__ */
