#!/bin/sh
echo ----------------start---------
#echo -e "\e[1;45m-------------------------start------\e[1;m"
rm -f ft*.o
rm -f libftprintf.a
rm -f tst1
echo -----------git--------
if [ $HOSTNAME == "vb-devpc" ]
then
    echo PC
else
    echo REMOTE
    git stash
    git pull
    git stash drop
fi
#. ../../vwlfbrg/bin/activate
norminette ft*.c ft*.h 
#echo -e "\e[1;45m-------------------------norm-------\e[1;m"

clang -Wall -Werror -Wextra -c ft*.c
ar -cvq libftprintf.a ft*.o
ls

cc -Wall -Werror -Wextra test.c libftprintf.a -o tst1
#echo -e "\e[1;42m---------------------------val------\e[1;m"
#valgrind --leak-check=full --show-leak-kinds=all --error-limit=no ./tst1
#echo -e "\e[1;44m---------------------------exe------\e[1;m"
./tst1


rm -f ft*.o
rm -f *.a
echo -----------------finish---
ls
echo --------------------!!!!!!
hostname
