default:
	@just --list

command_1:
	make clean
	make ROWS=3 COLS=3
	echo "make run" | wl-copy
	clear

command_2:
	make clean
	echo "make ROWS=4 COLS=4 run" | wl-copy
	clear

command_3:
	make clean
	echo "make ROWS=3 COLS=7 TICK_SPEED=11 TICKS_PER_TURN=30 UNICODE=OFF ASCII_ART=OFF run" | wl-copy
	clear

command_4:
	cd $HOME
	echo "docker run -it ghcr.io/softwareengineeringone/tiktaktoe:latest" | wl-copy
	clear
