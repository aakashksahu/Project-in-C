#Makefile for Slash
#by
#Veerendra Rajkumar
#Aakash Sahu
#Naga Teja

compile: ./source/admin.c ./source/chat_func.c ./source/cnvrt.c ./source/cpswd.c ./source/daysold.c ./source/func.c ./source/h_calc.h ./source/history.c ./source/mail.c ./source/chat.h ./source/quotes.c ./source/Slash.c ./source/slash.h ./source/slash_chat.c ./source/susers.c ./source/volume.c ./source/wit.c
	gcc -o admin ./source/admin.c ./source/func.c
	gcc -o smail ./source/mail.c ./source/func.c
	gcc -o flashmail ./source/mail.c ./source/func.c
	gcc -o susers ./source/susers.c ./source/func.c
	gcc -o volume ./source/volume.c
	gcc -o wit ./source/wit.c ./source/func.c
	gcc -o quote ./source/quotes.c ./source/func.c
	gcc -o chatter -lreadline ./source/slash_chat.c ./source/chat_func.c
	gcc -o cnvrt ./source/cnvrt.c
	gcc -o password ./source/cpswd.c ./source/func.c
	gcc -o myage ./source/daysold.c ./source/func.c
	gcc -o shist ./source/history.c ./source/func.c
	gcc -o Slash ./source/Slash.c ./source/func.c

