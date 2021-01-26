# rubber_ducky
rubber sucku usb or bad usb is a hacking device used to inject keystrokes into target device


Terminal:
[OK]Send Bytes => invoke Uartsend or printf
[OK]Receive Bytes =>getchars from uart rx interrupt

protocol definitions:
	Rx: PC -> MCU
		|_1_||_1__1_||_1_| ||_1__1_||_1_| |_1_||_1_|...| ... |_1_||_1_| ... |_1__1_|
		T_ID| size  |Status|  cmd  |argCnt|A1_S| A1_D  | ... |An_S|An_D ... | CRC / Terminator ..

	Tx: MCU -> PC
		|_1_||_1__1_||_1_| ||_1__1_||_1_| |_1_||_1_|...| ... |_1_||_1_| ... |_1__1_|
		T_ID| size  |Status| cmd   |RetCnt|R1_S| R1_D  | ... |Rn_S|Rn_D ... | CRC / Terminator ..

	
