#!/bin/bash
#clear
cmd=0

while [ $cmd -ne 3 ];do

	echo "
Menu 
-------------------
1 : créer un user
2 : supp un user
3 : quitter
-------------------
"
	read -p "choisir une option : " cmd

	if [ $cmd -eq 1 ]; then
		read -p "entre le nom du new user : " newname
		adduser $newname
	fi

	if [ $cmd -eq 2 ]; then
		read -p "Entrez le nom de l'utilisateur a supprimer : " useradel
		deluser $useradel
	fi

done
echo "Au revoir"
