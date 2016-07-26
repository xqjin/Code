STATUS_0=0
STATUS_1=1
STATUS_2=2

DESC=(
    [${STATUS_0}]="status_0"
    [${STATUS_1}]="status_1"
    [${STATUS_2}]="status_2"
    )

echo ${DESC[${STATUS_0}]}
echo ${DESC[${STATUS_1}]}
echo ${DESC[${STATUS_2}]}
