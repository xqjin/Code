readonly bak_path=/data12/justinxqjin/crontab_bak
bak_time=$(date +%Y_%m_%d_%H)

crontab -l > $bak_path/crontab.${bak_time}
find $bak_path -mtime +30 -name 'crontab.*' -exec rm -rf {} \;
