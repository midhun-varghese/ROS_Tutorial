xterm -e "roscore" &
sleep 2
xterm -e "rosrun beginner_tutorials talker" &
sleep 2
xterm -e "rosrun beginner_tutorials listener" &
sleep 2