//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"", "echo ' ' $(cat /proc/loadavg | awk '{ print $2 }') - \
		$(sensors | awk '/Core 0/ { print $3 }' | sed s/+//g) - \
		$(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g)", 5, 0},
	{"", "echo $(cat /sys/class/power_supply/BAT0/capacity)%", 60, 0},
	{"", "date '+%d/%m %H:%M'", 5, 0},
	{"", "echo \"$(whoami) \"", 100, 0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
