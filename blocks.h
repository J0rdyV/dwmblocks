//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	/*
		$(sensors | awk '/edge/ { print $2 }' | sed s/+//g) \
	*/
	{"", "[ -f ~/.config/nvim/vimwiki/diary/$(date '+%Y-%m-%d').md ] || \
		echo 'Wiki entry not created today'", 60, 0},

	{" ", "echo $(cat /proc/loadavg | awk '{ print $1 }') \
		$(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g)", 3, 0},

	{"", "echo -n $(newsboat -x print-unread | awk '{ if($1>0) print \"N\" $1 }')", 60, 0},

	{"", "echo -n $(find \"${XDG_DATA_HOME:-$HOME/.local/share}\"/mail/*/INBOX/new/* -type f | \
		wc -l 2>/dev/null | awk '{ if($1>0) print \"M\" $1 }')", 60, 0},

	/* {"🔋", "echo -n $(cat /sys/class/power_supply/BAT0/capacity)%", 60, 0}, */
	{"", "echo -n $(if [ $(cat /sys/class/power_supply/BAT0/status) == 'Charging' ]; then echo BC; else echo B; fi)$(cat /sys/class/power_supply/BAT0/capacity)", 60, 0},

	/* {"", "curl -s 'wttr.in/Lokeren?format=%c%t' | sed 's/ +//g'", 3600, 0}, */
	/* {"", "curl -s 'wttr.in/Lokeren?format=%c' | sed 's/ //g'", 900, 0}, */

	{"", "if $(dunstctl is-paused); then echo 'MUTE'; fi", 5, 0},

	{"", "echo -n $(if [ \"$(nmcli device status | grep wifi | awk '{ print $3 }')\" == 'connected' ]; then echo Wifi; fi)", 5, 0},

	{"", "echo -n $(if [ \"$(nmcli device status | grep vpn0 | awk '{ print $3 }')\" == 'connected' ]; then echo VPN; fi)", 5, 0},

	/* {"", "echo \"$(curl 'wttr.in/Lokeren?format=%m%M')/28\"", 21600, 0}, */
	{"", "echo -n $(curl -s 'wttr.in/Lokeren?format=%M')", 21600, 0},

	/* {"", "echo ⏰$(date '+%d/%m %H:%M')", 5, 0}, */
	{"", "echo -n \"$(date '+%H:%M') \"", 5, 0},

	/* {"", "chars=🌌🦉🧙🦂 && echo -n \"${chars:RANDOM%${#chars}:1}$(whoami)\"", 3600, 0}, */

};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " ";
static unsigned int delimLen = 5;
