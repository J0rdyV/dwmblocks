//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/

	{"", "echo ' '", 10000, 0},

	{"", "[ -f ~/.config/nvim/vimwiki/diary/$(date '+%Y-%m-%d').wiki ] || \
		echo '📓Wiki entry not created today'", 60, 0},

	{"", "if $(dunstctl is-paused); then echo '🔕'; fi", 5, 0},

	{"", "echo -n $(if [ \"$(nmcli device status | grep wifi | awk '{ print $3 }')\" == 'connected' ]; then echo 📡; fi)", 5, 0},

	{"", "echo -n $(if [ \"$(nmcli device status | grep vpn0 | awk '{ print $3 }')\" == 'connected' ]; then echo 🔒; fi)", 5, 0},

	{"", "date '+%H:%M'", 5, 0},

	{"", "echo ' '", 10000, 0},

};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " ";
static unsigned int delimLen = 5;
