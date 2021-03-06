/**
 * @file ksz9893_driver.h
 * @brief KSZ9893 3-port Gigabit Ethernet switch
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2019 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneTCP Open.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 1.9.4
 **/

#ifndef _KSZ9893_DRIVER_H
#define _KSZ9893_DRIVER_H

//Dependencies
#include "core/nic.h"

//KSZ9893 ports
#define KSZ9893_PORT1 1
#define KSZ9893_PORT2 2

//SPI command byte
#define KSZ9893_SPI_CMD_WRITE 0x40000000
#define KSZ9893_SPI_CMD_READ  0x60000000
#define KSZ9893_SPI_CMD_ADDR  0x001FFFE0

//KSZ9893 PHY registers
#define KSZ9893_BMCR                             0x00
#define KSZ9893_BMSR                             0x01
#define KSZ9893_PHYID1                           0x02
#define KSZ9893_PHYID2                           0x03
#define KSZ9893_ANAR                             0x04
#define KSZ9893_ANLPAR                           0x05
#define KSZ9893_ANER                             0x06
#define KSZ9893_ANNPR                            0x07
#define KSZ9893_ANLPNPR                          0x08
#define KSZ9893_GBCR                             0x09
#define KSZ9893_GBSR                             0x0A
#define KSZ9893_MMDACR                           0x0D
#define KSZ9893_MMDAADR                          0x0E
#define KSZ9893_GBESR                            0x0F
#define KSZ9893_RLB                              0x11
#define KSZ9893_LINKMD                           0x12
#define KSZ9893_DPMAPCSS                         0x13
#define KSZ9893_RXERCTR                          0x15
#define KSZ9893_ICSR                             0x1B
#define KSZ9893_AUTOMDI                          0x1C
#define KSZ9893_PHYCON                           0x1F

//KSZ9893 Switch registers
#define KSZ9893_CHIP_ID0                         0x0000
#define KSZ9893_CHIP_ID1                         0x0001
#define KSZ9893_CHIP_ID2                         0x0002
#define KSZ9893_CHIP_ID3                         0x0003
#define KSZ9893_SWITCH_OP                        0x0300
#define KSZ9893_PORT1_INT_STATUS                 0x101B
#define KSZ9893_PORT1_INT_MASK                   0x101F
#define KSZ9893_PORT1_OP_CTRL0                   0x1020
#define KSZ9893_PORT1_STATUS                     0x1030
#define KSZ9893_PORT1_MSTP_STATE                 0x1B04
#define KSZ9893_PORT2_INT_STATUS                 0x201B
#define KSZ9893_PORT2_INT_MASK                   0x201F
#define KSZ9893_PORT2_OP_CTRL0                   0x2020
#define KSZ9893_PORT2_STATUS                     0x2030
#define KSZ9893_PORT2_MSTP_STATE                 0x2B04
#define KSZ9893_PORT3_INT_STATUS                 0x301B
#define KSZ9893_PORT3_INT_MASK                   0x301F
#define KSZ9893_PORT3_OP_CTRL0                   0x3020
#define KSZ9893_PORT3_STATUS                     0x3030
#define KSZ9893_PORT3_XMII_CTRL0                 0x3300
#define KSZ9893_PORT3_XMII_CTRL1                 0x3301
#define KSZ9893_PORT3_MSTP_STATE                 0x3B04

//KSZ9893 Switch register access macros
#define KSZ9893_PORTn_INT_STATUS(port)           (0x001B + ((port) * 0x1000))
#define KSZ9893_PORTn_INT_MASK(port)             (0x001F + ((port) * 0x1000))
#define KSZ9893_PORTn_OP_CTRL0(port)             (0x0020 + ((port) * 0x1000))
#define KSZ9893_PORTn_STATUS(port)               (0x0030 + ((port) * 0x1000))
#define KSZ9893_PORTn_XMII_CTRL0(port)           (0x0300 + ((port) * 0x1000))
#define KSZ9893_PORTn_XMII_CTRL1(port)           (0x0301 + ((port) * 0x1000))
#define KSZ9893_PORTn_MSTP_STATE(port)           (0x0B04 + ((port) * 0x1000))
#define KSZ9893_PORTn_ETH_PHY_REG(port, addr)    (0x0100 + ((port) * 0x1000) + ((addr) * 2))

//PHY Basic Control register
#define KSZ9893_BMCR_RESET                       0x8000
#define KSZ9893_BMCR_LOOPBACK                    0x4000
#define KSZ9893_BMCR_SPEED_SEL_LSB               0x2000
#define KSZ9893_BMCR_AN_EN                       0x1000
#define KSZ9893_BMCR_POWER_DOWN                  0x0800
#define KSZ9893_BMCR_ISOLATE                     0x0400
#define KSZ9893_BMCR_RESTART_AN                  0x0200
#define KSZ9893_BMCR_DUPLEX_MODE                 0x0100
#define KSZ9893_BMCR_COL_TEST                    0x0080
#define KSZ9893_BMCR_SPEED_SEL_MSB               0x0040

//PHY Basic Status register
#define KSZ9893_BMSR_100BT4                      0x8000
#define KSZ9893_BMSR_100BTX_FD                   0x4000
#define KSZ9893_BMSR_100BTX_HD                   0x2000
#define KSZ9893_BMSR_10BT_FD                     0x1000
#define KSZ9893_BMSR_10BT_HD                     0x0800
#define KSZ9893_BMSR_EXTENDED_STATUS             0x0100
#define KSZ9893_BMSR_MF_PREAMBLE_SUPPR           0x0040
#define KSZ9893_BMSR_AN_COMPLETE                 0x0020
#define KSZ9893_BMSR_REMOTE_FAULT                0x0010
#define KSZ9893_BMSR_AN_CAPABLE                  0x0008
#define KSZ9893_BMSR_LINK_STATUS                 0x0004
#define KSZ9893_BMSR_JABBER_DETECT               0x0002
#define KSZ9893_BMSR_EXTENDED_CAPABLE            0x0001

//PHY ID High register
#define KSZ9893_PHYID1_DEFAULT                   0x0022

//PHY ID Low register
#define KSZ9893_PHYID2_DEFAULT                   0x1631

//PHY Auto-Negotiation Advertisement register
#define KSZ9893_ANAR_NEXT_PAGE                   0x8000
#define KSZ9893_ANAR_REMOTE_FAULT                0x2000
#define KSZ9893_ANAR_PAUSE                       0x0C00
#define KSZ9893_ANAR_100BT4                      0x0200
#define KSZ9893_ANAR_100BTX_FD                   0x0100
#define KSZ9893_ANAR_100BTX_HD                   0x0080
#define KSZ9893_ANAR_10BT_FD                     0x0040
#define KSZ9893_ANAR_10BT_HD                     0x0020
#define KSZ9893_ANAR_SELECTOR                    0x001F
#define KSZ9893_ANAR_SELECTOR_DEFAULT            0x0001

//PHY Auto-Negotiation Link Partner Ability register
#define KSZ9893_ANLPAR_NEXT_PAGE                 0x8000
#define KSZ9893_ANLPAR_ACK                       0x4000
#define KSZ9893_ANLPAR_REMOTE_FAULT              0x2000
#define KSZ9893_ANLPAR_PAUSE                     0x0C00
#define KSZ9893_ANLPAR_100BT4                    0x0200
#define KSZ9893_ANLPAR_100BTX_FD                 0x0100
#define KSZ9893_ANLPAR_100BTX_HD                 0x0080
#define KSZ9893_ANLPAR_10BT_FD                   0x0040
#define KSZ9893_ANLPAR_10BT_HD                   0x0020
#define KSZ9893_ANLPAR_SELECTOR                  0x001F
#define KSZ9893_ANLPAR_SELECTOR_DEFAULT          0x0001

//PHY Auto-Negotiation Expansion Status register
#define KSZ9893_ANER_PAR_DETECT_FAULT            0x0010
#define KSZ9893_ANER_LP_NEXT_PAGE_ABLE           0x0008
#define KSZ9893_ANER_NEXT_PAGE_ABLE              0x0004
#define KSZ9893_ANER_PAGE_RECEIVED               0x0002
#define KSZ9893_ANER_LP_AN_ABLE                  0x0001

//PHY Auto-Negotiation Next Page register
#define KSZ9893_ANNPR_NEXT_PAGE                  0x8000
#define KSZ9893_ANNPR_MSG_PAGE                   0x2000
#define KSZ9893_ANNPR_ACK2                       0x1000
#define KSZ9893_ANNPR_TOGGLE                     0x0800
#define KSZ9893_ANNPR_MESSAGE                    0x07FF

//PHY Auto-Negotiation Link Partner Next Page Ability register
#define KSZ9893_ANLPNPR_NEXT_PAGE                0x8000
#define KSZ9893_ANLPNPR_ACK                      0x4000
#define KSZ9893_ANLPNPR_MSG_PAGE                 0x2000
#define KSZ9893_ANLPNPR_ACK2                     0x1000
#define KSZ9893_ANLPNPR_TOGGLE                   0x0800
#define KSZ9893_ANLPNPR_MESSAGE                  0x07FF

//PHY 1000BASE-T Control register
#define KSZ9893_GBCR_TEST_MODE                   0xE000
#define KSZ9893_GBCR_MS_MAN_CONF_EN              0x1000
#define KSZ9893_GBCR_MS_MAN_CONF_VAL             0x0800
#define KSZ9893_GBCR_PORT_TYPE                   0x0400
#define KSZ9893_GBCR_1000BT_FD                   0x0200
#define KSZ9893_GBCR_1000BT_HD                   0x0100

//PHY 1000BASE-T Status register
#define KSZ9893_GBSR_MS_CONF_FAULT               0x8000
#define KSZ9893_GBSR_MS_CONF_RES                 0x4000
#define KSZ9893_GBSR_LOCAL_RECEIVER_STATUS       0x2000
#define KSZ9893_GBSR_REMOTE_RECEIVER_STATUS      0x1000
#define KSZ9893_GBSR_LP_1000BT_FD                0x0800
#define KSZ9893_GBSR_LP_1000BT_HD                0x0400
#define KSZ9893_GBSR_IDLE_ERR_COUNT              0x00FF

//PHY MMD Setup register
#define KSZ9893_MMDACR_FUNC                      0xC000
#define KSZ9893_MMDACR_FUNC_ADDR                 0x0000
#define KSZ9893_MMDACR_FUNC_DATA_NO_POST_INC     0x4000
#define KSZ9893_MMDACR_FUNC_DATA_POST_INC_RW     0x8000
#define KSZ9893_MMDACR_FUNC_DATA_POST_INC_W      0xC000
#define KSZ9893_MMDACR_DEVAD                     0x001F

//PHY Extended Status register
#define KSZ9893_GBESR_1000BX_FD                  0x8000
#define KSZ9893_GBESR_1000BX_HD                  0x4000
#define KSZ9893_GBESR_1000BT_FD                  0x2000
#define KSZ9893_GBESR_1000BT_HD                  0x1000

//PHY Remote Loopback register
#define KSZ9893_RLB_REMOTE_LOOPBACK              0x0100

//PHY LinkMD register
#define KSZ9893_LINKMD_TEST_EN                   0x8000
#define KSZ9893_LINKMD_PAIR                      0x3000
#define KSZ9893_LINKMD_PAIR_A                    0x0000
#define KSZ9893_LINKMD_PAIR_B                    0x1000
#define KSZ9893_LINKMD_PAIR_C                    0x2000
#define KSZ9893_LINKMD_PAIR_D                    0x3000
#define KSZ9893_LINKMD_STATUS                    0x0300
#define KSZ9893_LINKMD_STATUS_NORMAL             0x0000
#define KSZ9893_LINKMD_STATUS_OPEN               0x0100
#define KSZ9893_LINKMD_STATUS_SHORT              0x0200

//PHY Digital PMA/PCS Status register
#define KSZ9893_DPMAPCSS_1000BT_LINK_STATUS      0x0002
#define KSZ9893_DPMAPCSS_100BTX_LINK_STATUS      0x0001

//Port Interrupt Control/Status register
#define KSZ9893_ICSR_JABBER_IE                   0x8000
#define KSZ9893_ICSR_RECEIVE_ERROR_IE            0x4000
#define KSZ9893_ICSR_PAGE_RECEIVED_IE            0x2000
#define KSZ9893_ICSR_PAR_DETECT_FAULT_IE         0x1000
#define KSZ9893_ICSR_LP_ACK_IE                   0x0800
#define KSZ9893_ICSR_LINK_DOWN_IE                0x0400
#define KSZ9893_ICSR_REMOTE_FAULT_IE             0x0200
#define KSZ9893_ICSR_LINK_UP_IE                  0x0100
#define KSZ9893_ICSR_JABBER_IF                   0x0080
#define KSZ9893_ICSR_RECEIVE_ERROR_IF            0x0040
#define KSZ9893_ICSR_PAGE_RECEIVED_IF            0x0020
#define KSZ9893_ICSR_PAR_DETECT_FAULT_IF         0x0010
#define KSZ9893_ICSR_LP_ACK_IF                   0x0008
#define KSZ9893_ICSR_LINK_DOWN_IF                0x0004
#define KSZ9893_ICSR_REMOTE_FAULT_IF             0x0002
#define KSZ9893_ICSR_LINK_UP_IF                  0x0001

//PHY Auto MDI/MDI-X register
#define KSZ9893_AUTOMDI_MDI_SET                  0x0080
#define KSZ9893_AUTOMDI_SWAP_OFF                 0x0040

//PHY Control register
#define KSZ9893_PHYCON_JABBER_EN                 0x0200
#define KSZ9893_PHYCON_SPEED_1000BT              0x0040
#define KSZ9893_PHYCON_SPEED_100BTX              0x0020
#define KSZ9893_PHYCON_SPEED_10BT                0x0010
#define KSZ9893_PHYCON_DUPLEX_STATUS             0x0008
#define KSZ9893_PHYCON_1000BT_MS_STATUS          0x0004

//Global Chip ID 0 register
#define KSZ9893_CHIP_ID0_DEFAULT                 0x00

//Global Chip ID 1 register
#define KSZ9893_CHIP_ID1_DEFAULT                 0x98

//Global Chip ID 2 register
#define KSZ9893_CHIP_ID2_DEFAULT                 0x93

//Global Chip ID 3 register
#define KSZ9893_CHIP_ID3_REVISION_ID             0xF0
#define KSZ9893_CHIP_ID3_GLOBAL_SOFT_RESET       0x01

//Switch Operation register
#define KSZ9893_SWITCH_OP_DOUBLE_TAG_EN          0x80
#define KSZ9893_SWITCH_OP_SOFT_HARD_RESET        0x02
#define KSZ9893_SWITCH_OP_START_SWITCH           0x01

//Port N Interrupt Status register
#define KSZ9893_PORTn_INT_STATUS_PHY             0x02
#define KSZ9893_PORTn_INT_STATUS_ACL             0x01

//Port N Interrupt Mask register
#define KSZ9893_PORTn_INT_MASK_PHY               0x02
#define KSZ9893_PORTn_INT_MASK_ACL               0x01

//Port N Operation Control 0 register
#define KSZ9893_PORTn_OP_CTRL0_LOCAL_LOOPBACK    0x80
#define KSZ9893_PORTn_OP_CTRL0_REMOTE_LOOPBACK   0x40
#define KSZ9893_PORTn_OP_CTRL0_TAIL_TAG_EN       0x04
#define KSZ9893_PORTn_OP_CTRL0_TX_QUEUE_SPLIT_EN 0x03

//Port N Status register
#define KSZ9893_PORTn_STATUS_SPEED               0x18
#define KSZ9893_PORTn_STATUS_SPEED_10MBPS        0x00
#define KSZ9893_PORTn_STATUS_SPEED_100MBPS       0x08
#define KSZ9893_PORTn_STATUS_SPEED_1000MBPS      0x10
#define KSZ9893_PORTn_STATUS_DUPLEX              0x04
#define KSZ9893_PORTn_STATUS_TX_FLOW_CTRL_EN     0x02
#define KSZ9893_PORTn_STATUS_RX_FLOW_CTRL_EN     0x01

//XMII Port N Control 0 register
#define KSZ9893_PORTn_XMII_CTRL0_DUPLEX          0x40
#define KSZ9893_PORTn_XMII_CTRL0_TX_FLOW_CTRL_EN 0x20
#define KSZ9893_PORTn_XMII_CTRL0_SPEED_10_100    0x10
#define KSZ9893_PORTn_XMII_CTRL0_RX_FLOW_CTRL_EN 0x08

//XMII Port N Control 1 register
#define KSZ9893_PORTn_XMII_CTRL1_SPEED_1000      0x40
#define KSZ9893_PORTn_XMII_CTRL1_RGMII_ID_IG     0x10
#define KSZ9893_PORTn_XMII_CTRL1_RGMII_ID_EG     0x08
#define KSZ9893_PORTn_XMII_CTRL1_MII_RMII_MODE   0x04
#define KSZ9893_PORTn_XMII_CTRL1_IF_TYPE         0x03
#define KSZ9893_PORTn_XMII_CTRL1_IF_TYPE_MII     0x00
#define KSZ9893_PORTn_XMII_CTRL1_IF_TYPE_RMII    0x01
#define KSZ9893_PORTn_XMII_CTRL1_IF_TYPE_RGMII   0x03

//Port N MSTP State register
#define KSZ9893_PORTn_MSTP_STATE_TRANSMIT_EN     0x04
#define KSZ9893_PORTn_MSTP_STATE_RECEIVE_EN      0x02
#define KSZ9893_PORTn_MSTP_STATE_LEARNING_DIS    0x01

//Tail tag encoding
#define KSZ9893_TAIL_TAG_ENCODE(port) (0x20 | ((port) & 0x03))
//Tail tag decoding
#define KSZ9893_TAIL_TAG_DECODE(tag) (((tag) & 0x01) + 1)

//C++ guard
#ifdef __cplusplus
   extern "C" {
#endif

//KSZ9893 Ethernet switch driver
extern const PhyDriver ksz9893PhyDriver;

//KSZ9893 related functions
error_t ksz9893Init(NetInterface *interface);

bool_t ksz9893GetLinkState(NetInterface *interface, uint8_t port);

void ksz9893Tick(NetInterface *interface);

void ksz9893EnableIrq(NetInterface *interface);
void ksz9893DisableIrq(NetInterface *interface);

void ksz9893EventHandler(NetInterface *interface);

error_t ksz9893TagFrame(NetInterface *interface, NetBuffer *buffer,
   size_t *offset, uint8_t port, uint16_t *type);

error_t ksz9893UntagFrame(NetInterface *interface, uint8_t **frame,
   size_t *length, uint8_t *port);

void ksz9893WritePhyReg(NetInterface *interface, uint8_t port,
   uint8_t address, uint16_t data);

uint16_t ksz9893ReadPhyReg(NetInterface *interface, uint8_t port,
   uint8_t address);

void ksz9893DumpPhyReg(NetInterface *interface, uint8_t port);

void ksz9893WriteSwitchReg(NetInterface *interface, uint16_t address,
   uint8_t data);

uint8_t ksz9893ReadSwitchReg(NetInterface *interface, uint16_t address);

void ksz9893DumpSwitchReg(NetInterface *interface);

//C++ guard
#ifdef __cplusplus
   }
#endif

#endif
