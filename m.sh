#!/bin/sh
echo -e "\e[1;45m-------------------------start------\e[1;m"
rm -f ft*.o
rm -f libftprintf.a
rm -f tst1
echo -----------git--------

if [ $HOSTNAME == "vb-devpc" ]
then
    echo PC;
else
    echo REMOTE;
    git stash;
    git pull;
    git stash drop;
fi

if [ $1 == "push"  ] && [ $HOSTNAME == "vb-devpc" ]
then
    echo "PUSH";
    tmp=$(date +"%s");
    git add .;
    git commit -m "${tmp}-autocom";
    git push;
else
    echo "NO PUSH"
fi
#. ../../vwlfbrg/bin/activate
#norminette ft*.c ft*.h 
echo -e "\e[1;45m-------------------------norm-------\e[1;m"

make re
ls

cc -Wall -Werror -Wextra test.c libftprintf.a -o tst1
echo -e "\e[1;42m---------------------------val------\e[1;m"
valgrind --leak-check=full --show-leak-kinds=all --error-limit=no ./tst1
echo -e "\e[1;44m---------------------------exe------\e[1;m"
./tst1
echo -e "\e[1;44m--------------------finish-exe------\e[1;m"

rm -f ft*.o
rm -f *.a
echo -----------------finish---
ls
