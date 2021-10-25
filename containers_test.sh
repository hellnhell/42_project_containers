#!/bin/bash

cyan=$'\e[0;1;36;40m'
red=$'\e[0;92;31m'
yellow=$'\e[0;92;33m'

echo 
echo " " ${red}
echo "      )     )                (       )     (   (                   (             (        "${red}
echo "     (  ( /(  ( /(  *   )   (     )\ ) ( /(     )\ ))\ )       *   )    )\ ) *   )    )    "
echo "     )\ )\()) )\()) )  /(   )\   (()/( )\())(  (()/(()/(       )  /((  (()/(  )  /((  ()    "
echo "    ((_)(_)\ ((_)\ ( )(_))(((_)(  /(_))(_)\ )\  /(_))(_))     ( )(_))\  /(_)) )(_))\  /()    " ${yellow}
echo "     \__((_)  _((_)_(_()) )\ _ )\(_))  _((_)(_)(_))(_))      (_(_())(_)(_))(_(_())(_)(_))      " ${cyan}
echo "    / __/ _ \| \| |_   _|   /_\  |_ _|| \| | __| _ \ __|     |_   _| __/ __|_   _| __| _ \   "
echo "   | (__ (_) | .  | | |    / _ \  | | | .  | _||   \__ \       | | | _|\__ \ | | | _||   /   "
echo "    \___\___/|_|\_| |_|   /_/ \_\|___||_|\_|___|_|_\___/       |_| |___|___/ |_| |___|_|_\   "
echo "                                                                                             "
echo " "

cd ./test && ./test_vector.sh && cd ..
cd ./test && ./test_map.sh && cd ..
cd ./test && ./test_stack.sh && cd ..
cd ./test && ./timming.sh && cd ..