#!/usr/bin/expect
#trap sigwinch spawned
trap {
    set rows [stty rows]
    set cols [stty columns]
    stty rows $rows columns $cols < $spawn_out(slave,name)
} WINCH

if { $argc != 2 } {
    send_user "Usage: user@host passwd\n"
    exit
}

set user_host [lindex $argv 0]
set passwd [lindex $argv 1]

spawn /usr/local/bin/luit -encoding gb18030 ssh baidu
expect "*ssl*" {send "ssh $user_host \r"}
expect "*password:*"
send "$passwd\r"
expect -re "$"

#fconfigure stdout -encoding ascii
#fconfigure stdout -encoding cp936
#fconfigure stdin  -translation binary
#fconfigure stdout -translation binary

#fconfigure stdin -translation binary
#fconfigure stdin -encoding cp936

#fconfigure stdin -encoding gb2312
#fconfigure stdout -encoding gb2312

#send "export LANG=en_US.UTF-8;export LC_ALL=en_US.UTF8;export LC_CTYPE=en_US.UTF8\r"
#send "export LANG=zh_CN.gbk;export LC_ALL=zh_CN.gbk;export LC_CTYPE=zh_CN.gbk\r"
#send "export LANG=zh_CN.GB18030;export LC_ALL=zh_CN.GB18030;export LC_CTYPE=zh_CN.GB18030\r"

interact
