#!/usr/bin/expect
set USER [lindex $argv 0]
set TARGET [lindex $argv 1]
set PASSWD [lindex $argv 2]
set ENCODING [lindex $argv 3]
trap {
	 set rows [stty rows]
	 set cols [stty columns]
	 stty rows $rows columns $cols < $spawn_out(slave,name)
} WINCH

spawn luit -encoding $ENCODING ssh -l $USER $TARGET

expect {
 "yes/no" { send "yes\r"; exp_continue }
 "password:" { send "$PASSWD\r" }
}
interact
