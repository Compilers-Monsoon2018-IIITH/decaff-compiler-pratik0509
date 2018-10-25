decaff.tab.c decaff.tab.h: decaff.y
	bison -vd -Wall decaff.y

lex.yy.c: decaff.l decaff.tab.h
	flex decaff.l

decaff: lex.yy.c decaff.tab.c decaff.tab.h
	gcc decaff.tab.c lex.yy.c -lfl -o decaff