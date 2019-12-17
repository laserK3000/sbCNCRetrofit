component bosch_ea;
pin out bit reset;
pin out bit clk;
pin out bit outputdata# [8];
pin in bit inputdata# [8];

pin out bit x31-# [8];
pin out bit x32-# [8];
pin out bit x33-# [8];
pin out bit x34-# [8];
pin out bit x35-# [8];
pin out bit x36-# [8];
pin out bit x37-# [8];
pin out bit x38-# [8];

pin in bit x21-# [8];
pin in bit x22-# [8];
pin in bit x23-# [8];
pin in bit x24-# [8];

## timings
resetTime = 


function _ nofp;
license "GPL"; // indicates GPL v2 or later
;;
enum states {
	START,
	RESLOW,
	CLKLOW,
	SAMPLE
} state;

state = START;
unsigned frame = 0;
while(1){
switch (state){
	case START:
	reset = 1;
	clk = 1;
	frame = 0;
	usleep(recoverTime);
	state = RESLOW;	
	break;
	
	case RESLOW;
	reset = 0;
	usleep (resetTime);
	break;

	case CLKLOW;
	clk = 0;
	usleep (clkLowTime);
	break;

	case SAMPLE;
	clk = 1;
	usleep (sampleTime);
	state = CLKLOW
	switch(frame){
		case 0:
		x31-0 = inputdata(0);
		x31-1 = inputdata(1);
		x31-2 = inputdata(2);
		x31-3 = inputdata(3);
		x31-4 = inputdata(4);
		x31-5 = inputdata(5);
		x31-6 = inputdata(6);
		x31-7 = inputdata(7);
		frame++;
		break;

		case 1:
		frame++;
		break;

		case 2:
		frame++;
		break;

		case 3:
		frame++;
		break;

		case 4:
		frame++;
		break;

		case 5:
		frame++;
		break;

		case 6:
		frame++;
		break;

		case 7:
		frame++;
		break;

		default:
		frame = 0;
		state = START;
		clk = 0;
	}
	clk = 0;
	break;
}
}
