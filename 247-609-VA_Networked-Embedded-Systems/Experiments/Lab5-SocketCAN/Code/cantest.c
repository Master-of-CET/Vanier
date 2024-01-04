/*
 *  cantest.c - simple program to send and receive CAN-frames 
 *  via CAN_RAW sockets.
 *
 *	Author				Date			Version
 *	DY Fong			5  March 2020		preliminary version
 *	Leonardo Fusser		28 March 2022		added setup/init code
 *	Leonardo Fusser		4  April 2022		partially populated while(1)
 *	Leonardo Fusser		11 April 2022		completed while(1)
 *
 */


/* Includes. *///////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>
/////////////////////////////


/* Macros. */
#define	 ODD_ID   0x001


int main(int argc, char **argv)
{
	int s, i_tx = 0;		//CAN socket variable and CAN tx running counter variables.
	int nbytes;			//Read frame variable.
	struct sockaddr_can addr;	//Local struct declaration for CAN binding.
	struct ifreq ifr;		//Local struct declaration for interface index.
	struct can_frame frame_tx;	//Local struct declaration for CAN tx frame.
	struct can_frame frame_rx;	//Local struct declaration for CAN rx frame.
	struct can_filter rfilter[1];	//Local struct declaration for CAN receiving filter.


	/* Opens a CAN socket. */////////////////////////////
	if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		perror("Socket");
		return 1;
	}
	/////////////////////////////////////////////////////


	/* Retrieves the interface index for interface name. *///////
	strcpy(ifr.ifr_name, "can0" );	//CAN interface name.
	ioctl(s, SIOCGIFINDEX, &ifr);
	/////////////////////////////////////////////////////////////


	/* Binds the CAN socket to the CAN interface. *//////////////
	memset(&addr, 0, sizeof(addr));		//Clears.
	addr.can_family = AF_CAN;		//Sets type.
	addr.can_ifindex = ifr.ifr_ifindex;	//Asociates.
	
	if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("Bind");
		return 1;
	}
	/////////////////////////////////////////////////////////////


	/* Sets up CAN tx frame info and data. *////////
	frame_tx.can_id = 0x333;	//CAN ID.
	frame_tx.can_dlc = 8;		//CAN DLC.
	frame_tx.data[0] = 1;		//Student ID.
	frame_tx.data[1] = 9;		//" ".
	frame_tx.data[2] = 4;		//" ".
	frame_tx.data[3] = 6;		//" ".
	frame_tx.data[4] = 9;		//" ".
	frame_tx.data[5] = 9;		//" ".
	frame_tx.data[6] = 5;		//" ".
	////////////////////////////////////////////////


	/* Sets up CAN receive filter. */////////////////////////////////////////////////////////////////////
	//rfilter[0].can_id = 0x111;			//Forces only CAN packets from my partner through.
	//rfilter[0].can_mask = CAN_SFF_MASK;		//" ".
	rfilter[0].can_id = ODD_ID;			//Forces only odd CAN packets through.
	rfilter[0].can_mask = ODD_ID;			//" ".
	
	setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));
	/////////////////////////////////////////////////////////////////////////////////////////////////////


	/* Infinite loop. */
	while (1)
	{

		
		/* Sending and printing CAN tx frame. *////////////////////////////////////////////////////////////////////////////////////////////////////////////
		i_tx += 1;				//Increment CAN tx running counter by 1. 
		frame_tx.data[7] = i_tx;		//Offset CAN tx frame and store CAN tx running counter.
		
		/* Prints. */
		printf("Transmit CAN frame: \r\n");
		printf("0x%x [%d] %d %d %d %d %d %d %d	 <transmit count: %d>\r\n\n", frame_tx.can_id, frame_tx.can_dlc, frame_tx.data[0], frame_tx.data[1], 
															 frame_tx.data[2], frame_tx.data[3], 
															 frame_tx.data[4], frame_tx.data[5], 
															 frame_tx.data[6], frame_tx.data[7]);
		/* Alternate printing method. */
		//printf("0x%x [%d] %d %d %d %d %d %d %d  \r\n\n", frame_tx.can_id, frame_tx.can_dlc, frame_tx.data[0], frame_tx.data[1], 
												    //frame_tx.data[2], frame_tx.data[3], 
												    //frame_tx.data[4], frame_tx.data[5], 
												    //frame_tx.data[6]);


		if (write(s, &frame_tx, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
			perror("Write");
			return 1;
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		/* Reading and printing rx CAN frame. *////////////////////////////////////////////////////////////////////////////////////////////////////////////
		nbytes = read(s, &frame_rx, sizeof(struct can_frame));

		if (nbytes < 0) {
			perror("Read");
			return 1;
		}

		/* Prints. */
		printf("Receiving CAN frame: \r\n");
		//printf("0x%x [%d] %c %c %c %c %c %c %c  <receive count: %d>\r\n\n", frame_rx.can_id, frame_rx.can_dlc, frame_rx.data[0], frame_rx.data[1], 
														       //frame_rx.data[2], frame_rx.data[3], 
														       //frame_rx.data[4], frame_rx.data[5], 
														       //frame_rx.data[6], frame_rx.data[7]);
		/* Alternate printing methods. */
		printf("0x%x [%d] %d %d %d %d %d %d %d  <receive count: %d>\r\n\n", frame_rx.can_id, frame_rx.can_dlc, frame_rx.data[0], frame_rx.data[1], 
														       frame_rx.data[2], frame_rx.data[3], 
														       frame_rx.data[4], frame_rx.data[5], 
														       frame_rx.data[6], frame_rx.data[7]);

		//printf("0x%x [%d] %s  \r\n\n", frame_rx.can_id, frame_rx.can_dlc, frame_rx.data); 
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		
		usleep(500000);	//500mS sleep.


	}//End of while(1).
	

	/* Closes CAN socket. *////////
	if (close(s) < 0) {
		perror("Close");
		return 1;
	}
	///////////////////////////////


	return 0;


}//End of main().
