#!/bin/bash

if ! [[ "${#}" -eq 1 ]];then
        echo "wrong num of args"
        exit 1
fi

if ! [[ "$(id -u)" -eq 0 ]];then
        echo "Not a root"
#       exit 2
fi

if ! [[ -n "${1}" ]];then
        echo "empty string"
        exit 3
fi

procceses="$(ps -e -o user,pid | tail -n +1)"
users=""


for line in $procceses;do

        #echo "line is : $line"
        user="$(echo "$line" | cut -d ' ' -f1)"
        ((users[$user]++))
        #echo "${users[$user]}"
        echo "$user"
done

rootP=users['root']

for user in $users;do

        echo "user is $user ${users[$user]}"
        if ((users["$user"] > rootP));then
                echo "user has more procceses"
        fi

done
