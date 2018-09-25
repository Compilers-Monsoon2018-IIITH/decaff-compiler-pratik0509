
all: decaff.l decaff.y decaff.tab.h decaff.tab.c lex.yy.c
	bison -d decaff.y
	flex decaff.l
	gcc decaff.tab.c lex.yy.c -lfl -o ./decaff
